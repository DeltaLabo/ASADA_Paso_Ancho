#include "RS485.h"
#include "OctaveModbusWrapper.h"
#include "frequencies.h"
#include "recolectarDatosBateria.h"
#include "LoRaSender.h"


class AverageCalculator {
  public:
    int counter;
    int length;
    int dataSize;
    int16_t* int16array = NULL;
    int32_t* int32array = NULL;
    int16_t int16avg;
    int32_t int32avg;

    AverageCalculator(int sampleFreq, int avgFreq, int dataSizeinBits) {
      length = sampleFreq / avgFreq;
      counter = 0;
      dataSize = dataSizeinBits;

      if (dataSize == 16) int16array = (int16_t*)malloc(length * sizeof(int16_t));
      else if (dataSize == 32) int32array = (int32_t*)malloc(length * sizeof(int32_t));
    }

    void append(int16_t value) {
      int16array[counter] = value;
      counter = counter + 1;
    }

    void append(int32_t value) {
      int32array[counter] = value;
      counter = counter + 1;
    }

    void calculateAverage() {
      if (dataSize == 16) {
        int16_t sum = 0;
        for (int i = 0; i < counter; i++) {
          sum = sum + int16array[i];
        }

        counter = 0;
        int16avg = sum / (counter * 1.0);
      }
      else if (dataSize == 32) {
        int32_t sum = 0;
        for (int i = 0; i < counter; i++) {
          sum = sum + int32array[i];
        }

        counter = 0;
        int32avg = sum / (counter * 1.0);
      }
    }
};

// Define the OctaveModbusWrapper object, using the RS-485 port for Modbus and Serial0 for logging
OctaveModbusWrapper octave(RS485);

// Variable to store the last error code
uint8_t modbusErrorCode;

// Control variable for the Modbus polling frequency
uint32_t modbusTimeCounter = 0UL;

// Control variable for the height sensor polling frequency
uint32_t heightTimeCounter = 0UL;

// Control variable for the LoRa sender loop
uint32_t LoRaTimeCounter = 0UL;

// Signed current flow reading from Octave meter truncated to 16 bits
AverageCalculator SignedCurrentFlowArr(MODBUS_POLLING_FREQ_MS, LORA_SENDER_FREQ_MS, 16);
int16_t avgSignedCurrentFlow;

// Net signed volume reading from Octave meter truncated to 32 bits
AverageCalculator NetSignedVolumeArr(MODBUS_POLLING_FREQ_MS, LORA_SENDER_FREQ_MS, 32);
int32_t avgNetSignedVolume;

const int heightSensorPin = A0;

// Water level height, in meters
float waterHeight = 0.0;
// Water level height, in meters, truncated to 16 bits
AverageCalculator WaterHeightArr(HEIGHT_POLLING_FREQ_MS, LORA_SENDER_FREQ_MS, 16);
int16_t avgWaterHeight;

void setup() {
  // Set indicator LED pin as output
  // This LED toggles with the same frequency as the Modbus polling, for verification purposes
  pinMode(40, OUTPUT);
  // Initialize the indicator LED's state
  digitalWrite(40, LOW);

  // Use Serial0 port for debugging and logging
  Serial.begin(9600);

  // Use Serial1 port for LoRa communication
  Serial1.begin(9600);
  senderStart();

  // Start the Modbus serial port
  // SERIAL_8N1: 8 bits, no parity, 1 stop bit
  RS485.begin(octave.modbusBaudrate, HALFDUPLEX, SERIAL_8N1);

  // Start the Octave Modbus object
  octave.begin();

  // Wait 500ms for Modbus startup
  delay(500);
}


void loop() {
    uint32_t currentMillis = millis();  // Get the current time

    // Send Modbus requests to the Octave meter at the polling frequency
    if (currentMillis - modbusTimeCounter >= MODBUS_POLLING_FREQ_MS) {
        // Read Signed Current Flow from Octave meter via Modbus
        octave.SignedCurrentFlow(64);
        // Multiply by 100 to preserve two decimal places, then truncate to 16 bits
        int16_t truncatedSignedCurrentFlow = octave.doubleBuffer * 100;
        SignedCurrentFlowArr.append(truncatedSignedCurrentFlow);

        // Read Signed Current Flow from Octave meter via Modbus
        octave.NetSignedVolume(64);
        // Multiply by 100 to preserve two decimal places, then truncate to 32 bits
        int32_t truncatedNetSignedVolume = octave.doubleBuffer * 100;
        NetSignedVolumeArr.append(truncatedNetSignedVolume);

        // Restart time counter
        modbusTimeCounter = currentMillis;
    }

    // Read height sensor value at the polling frequency
    if (currentMillis - heightTimeCounter >= HEIGHT_POLLING_FREQ_MS) {
        // Read water level height from analog input and scale it between 0-5.0 meters
        waterHeight = (analogRead(heightSensorPin)/1023.0)*5.0;
        // Multiply by 100 to preserve two decimal places, then truncate to 16 bits
        int16_t truncatedWaterHeight = waterHeight * 100;
        WaterHeightArr.append(truncatedWaterHeight);

        // Restart time counter
        heightTimeCounter = currentMillis;
    }

    // Send collected data via LoRa at the specified interval
    if (currentMillis - LoRaTimeCounter >= LORA_SENDER_FREQ_MS) {
        // Calculate averages
        SignedCurrentFlowArr.calculateAverage();
        avgSignedCurrentFlow = SignedCurrentFlowArr.int16array;

        NetSignedVolumeArr.calculateAverage();
        avgNetSignedVolume = NetSignedVolumeArr.int32array;

        WaterHeightArr.calculateAverage();
        avgWaterHeight = WaterHeightArr.int16array;

        LoRaSend();

        // Restart time counter
        LoRaTimeCounter = currentMillis;
    }
}

void LoRaSend() {
int i = 0;
  //Se llama a la función pedidoUtil para recolectar los datos de la batería
  byte DatosUtilesBateria[13];
  pedidoUtil(DatosUtilesBateria);

  // Se define el header y el tail
  byte header[2] = {0xAA, 0xDD};
  byte tail[2] = {0xFF, 0x77};

  // Crea un nuevo array para los datos extendidos
  byte DatosExtendidos[100]; // 2 (header) + 13 (datos bateria) + 6 (datos Octave) + 2 (datos altura) + 75 (reserved) + 2 (tail) = 100 bytes

  // Copia el encabezado al principio
  for (i = 0; i < 2; i++) {
    DatosExtendidos[i] = header[i];
  }

  // Copia los datos de la batería después del encabezado
  for (i = 0; i < 13; i++) {
    DatosExtendidos[i + 2] = DatosUtilesBateria[i];
  }

  // Copia el caudal, separado en bytes con el orden AB
  DatosExtendidos[2 + 13 - 1] = (byte)(avgSignedCurrentFlow >> 8);
  DatosExtendidos[2 + 13 + 1 - 1] = (byte)(avgSignedCurrentFlow);

  // Copia el volumen, separado en bytes con el orden ABCD
  DatosExtendidos[2 + 13 + 2 - 1] = (byte)(avgNetSignedVolume >> 32);
  DatosExtendidos[2 + 13 + 3 - 1] = (byte)(avgNetSignedVolume >> 16);
  DatosExtendidos[2 + 13 + 4 - 1] = (byte)(avgNetSignedVolume >> 8);
  DatosExtendidos[2 + 13 + 5- 1] = (byte)(avgNetSignedVolume);

  // Copia la altura, separada en bytes con el orden AB
  DatosExtendidos[2 + 13 + 6 - 1] = (byte)(avgWaterHeight >> 8);
  DatosExtendidos[2 + 13 + 7 - 1] = (byte)(avgWaterHeight);

  // Se agregan los espacios reserved
  for (i = 0; i < 75; i++) {
    DatosExtendidos[i + 15] = (i & 0xFF);
  }

  // Copia el pie al final
  for (i = 0; i < 2; i++) {
    DatosExtendidos[i + 98] = tail[i];
  }

  //Se imprimen los datos obtenidos que son de utilidad
  Serial.print("Datos en el loop para transmisión: ");
  for(i=0; i<sizeof(DatosUtilesBateria); i++){
      if(DatosUtilesBateria[i] < 16) Serial.print("0");
      Serial.print(DatosUtilesBateria[i],HEX);
      Serial.print(" ");
    }
  Serial.println(" ");

  //Se envía la cadena de datos por LoRa
  send(DatosExtendidos, 100);
}