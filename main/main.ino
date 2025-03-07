#include <HardwareSerial.h>

#include "src/OctaveModbusWrapper/ESP32/OctaveModbusWrapper.h"
//#include "src/SIM7600Wrapper/SIM7600Wrapper.h"
#include "frequencies.h"
#include "pins.h"

#define MODBUS_BAUDRATE 2400
#define SIM_BAUDRATE 115200
#define BMS_BAUDRATE 9600

// Calculates the averages of an array updated in real time
class AverageCalculator_int16 {
  public:
    // Amount of data points in the array
    int counter;
    // Maximum size of the array
    int length;
    int16_t* array = NULL;
    int16_t average;

    // Constructor
    AverageCalculator_int16(int sampleFreq, int avgFreq) {
      // Store as many samples as possible during one average period
      length = (avgFreq / sampleFreq) + 5;
      // Reset the data point counter
      counter = 0;

      // Allocate memory for data arrays
      array = (int16_t*)malloc(length * sizeof(int16_t));
    }

    // Append an int16 value to the array
    void append(int16_t value) {
      // Bounds checking
      if (counter < length) {
        array[counter] = value;
        counter = counter + 1;
      }
    }

    uint8_t calculateAverage() {
      uint8_t status = 0;

      // Calculate the sum of all data points in the array
      int64_t sum = 0;
      for (int i = 0; i < counter; i++) {
        sum = sum + array[i];
      }

      // Take the average, ensuring we don't overflow int16_t
      float avgFloat = (float)sum / (float)counter;
      
      // Check if result will fit in int16_t
      if (avgFloat > INT16_MAX) {
        average = INT16_MAX; // Clamp to max value
        // Error code 1: Overflow
        status = 1;
      } else if (avgFloat < -(INT16_MAX+1)) {
        average = -(INT16_MAX+1); // Clamp to min value
        // Error code 2: Underflow
        status = 2;
      } else {
        average = (int16_t)avgFloat;
      }

      // Reset the counter
      counter = 0;

      return status;
    }
};

// Calculates the averages of an array updated in real time
class AverageCalculator_int32 {
  public:
    // Amount of data points in the array
    int counter;
    // Maximum size of the array
    int length;
    int32_t* array = NULL;
    int32_t average;

    // Constructor
    AverageCalculator_int32(int sampleFreq, int avgFreq) {
      // Store as many samples as possible during one average period
      length = (avgFreq / sampleFreq) + 5;
      // Reset the data point counter
      counter = 0;

      array = (int32_t*)malloc(length * sizeof(int32_t));
    }

    // Append an int32 value to the array
    void append(int32_t value) {
      // Bounds checking
      if (counter < length) {
        array[counter] = value;
        counter = counter + 1;
      }
    }

    uint8_t calculateAverage() {
      uint8_t status = 0;

      // Calculate the sum of all data points in the array
      int64_t sum = 0;
      for (int i = 0; i < counter; i++) {
        sum = sum + array[i];
      }

      // Take the average, ensuring we don't overflow int32_t
      float avgFloat = (float)sum / (float)counter;
      
      // Check if result will fit in int32_t
      if (avgFloat > INT32_MAX) {
        average = INT32_MAX; // Clamp to max value
        status = 1;
      } else if (avgFloat < -(INT32_MAX+1)) {
        average = -(INT32_MAX+1); // Clamp to min value
        status = 1;
      } else {
        average = (int32_t)avgFloat;
      }

      // Reset the counter
      counter = 0;
      return status;
    }
};

// Define the HardwareSerial used as an RS-485 port
HardwareSerial RS485(1);

// Define the OctaveModbusWrapper object, using the RS-485 port for Modbus
OctaveModbusWrapper octave(RS485);

// Control variable for the Modbus polling frequency
uint32_t modbusTimeCounter = 0UL;

// Control variable for the height sensor polling frequency
uint32_t heightTimeCounter = 0UL;

// Control variable for the LoRa sender loop
uint32_t loggingTimeCounter = 0UL;

// Signed current flow reading from Octave meter truncated to 16 bits
AverageCalculator_int16 SignedCurrentFlowArr(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS);
int16_t avgSignedCurrentFlow;

// Net signed volume reading from Octave meter truncated to 32 bits
AverageCalculator_int32 NetSignedVolumeArr(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS);
int32_t avgNetSignedVolume;

// Water level height, in meters, truncated to 16 bits
AverageCalculator_int16 WaterHeightArr(HEIGHT_POLLING_FREQ_MS, LOGGING_FREQ_MS);
int16_t avgWaterHeight;

void setup() {
  // Use Serial0 port for debugging and logging
  Serial.begin(9600);

  // Start the Modbus serial port
  RS485.begin(MODBUS_BAUDRATE, SERIAL_8N1, RS485_RX_PIN, RS485_TX_PIN);
  // Set RTS pin
  RS485.setPins(RS485_RX_PIN, RS485_TX_PIN, -1, RS485_RTS_PIN);
  // Disable hardware flow control, as required by the documentation,
  // and set the TX buffer size threshold to 128 bytes (maximum value)
  RS485.setHwFlowCtrlMode(UART_HW_FLOWCTRL_DISABLE, 128);
  // Enable half-duplex flow control
  RS485.setMode(UART_MODE_RS485_HALF_DUPLEX);

  // Initialize the Octave Modbus object
  octave.begin(MODBUS_BAUDRATE);

  pinMode(HEIGHT_SENSOR_PIN, INPUT);

  // Wait 500ms for Modbus startup
  delay(500);
}

void loop() {
    uint32_t currentMillis = millis();  // Get the current time

    // Send Modbus requests to the Octave meter at the polling frequency
    if (currentMillis - modbusTimeCounter >= MODBUS_POLLING_FREQ_MS) {
      // Read Signed Current Flow from Octave meter via Modbus
      double signedCurrentFlow;
      octave.SignedCurrentFlow_double(&signedCurrentFlow);
      // Multiply by 100 to preserve two decimal places, then truncate to 16 bits
      int16_t truncatedSignedCurrentFlow = signedCurrentFlow * 100.0;
      SignedCurrentFlowArr.append(truncatedSignedCurrentFlow);

      // Read Net Signed Volume from Octave meter via Modbus
      double netSignedVolume;
      octave.NetSignedVolume_double(&netSignedVolume);
      // Multiply by 100 to preserve two decimal places, then truncate to 32 bits
      int32_t truncatedNetSignedVolume = netSignedVolume * 100;
      NetSignedVolumeArr.append(truncatedNetSignedVolume);

      // Restart time counter
      modbusTimeCounter = currentMillis;
    }

    // Read height sensor value at the polling frequency
    if (currentMillis - heightTimeCounter >= HEIGHT_POLLING_FREQ_MS) {
        // Read water level height from analog input and scale it between 0-5.0 meters`
        int sensorValue = analogRead(HEIGHT_SENSOR_PIN);
        float waterHeight = (sensorValue/1023.0)*5.0;
        // Multiply by 100 to preserve two decimal places, then truncate to 16 bits
        int16_t truncatedWaterHeight = waterHeight * 100;
        WaterHeightArr.append(truncatedWaterHeight);

        // Restart time counter
        heightTimeCounter = currentMillis;
    }

    // Log collected data at the specified interval
    if (currentMillis - loggingTimeCounter >= LOGGING_FREQ_MS) {
        // Calculate averages
        SignedCurrentFlowArr.calculateAverage();
        avgSignedCurrentFlow = SignedCurrentFlowArr.average;

        NetSignedVolumeArr.calculateAverage();
        avgNetSignedVolume = NetSignedVolumeArr.average;

        WaterHeightArr.calculateAverage();
        avgWaterHeight = WaterHeightArr.average;

        Serial.print("\nCaudal promedio (x100): ");
        Serial.print(avgSignedCurrentFlow);
        Serial.print(", hex: ");
        Serial.println(avgSignedCurrentFlow, HEX);
        Serial.print("Volumen promedio (x100): ");
        Serial.print(avgNetSignedVolume);
        Serial.print(", hex: ");
        Serial.println(avgNetSignedVolume, HEX);
        Serial.print("Altura promedio (x100): ");
        Serial.print(avgWaterHeight);
        Serial.print(", hex: ");
        Serial.println(avgWaterHeight, HEX);
        
        // Restart time counter
        loggingTimeCounter = currentMillis;
    }
}