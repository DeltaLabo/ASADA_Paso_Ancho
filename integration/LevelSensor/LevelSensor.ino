#include <HardwareSerial.h>
#include <SPI.h>
#include <SdFat.h>
#define TINY_GSM_MODEM_SIM7600
#include <TinyGsmClient.h>




#include "src/OctaveModbusWrapper/ESP32/OctaveModbusWrapper.h"
#include "frequencies.h"
#include "pins.h"

#define MODBUS_BAUDRATE 2400
#define SIM_BAUDRATE 115200
#define BMS_BAUDRATE 9600

// Connect the SD module's CS pin to D5 (GPIO6).
const uint32_t SD_RETRY_INTERVAL_MS = 30000UL;
const char *CSV_PATH = "datos.csv";
const char *CSV_HEADER = "uptime_ms,signed_current_flow,net_signed_volume,water_height_m,flow_samples,volume_samples,height_samples";
SdFat sd;
bool sdReady = false;
uint32_t lastSdRetryMs = 0UL;

// RS485 uses UART1, so the SIM7600 must use the independent UART2.
HardwareSerial LTE(2);
TinyGsm modem(LTE);
TinyGsmClient lteClient(modem);
const char *LTE_APN = "internet.ideasclaro";
const uint32_t LTE_RETRY_INTERVAL_MS = 30000UL;
const uint32_t LTE_PROBE_INTERVAL_MS = 60000UL;
uint32_t lastLteAttemptMs = 0UL;
uint32_t lastLteProbeMs = 0UL;
bool lteConnected = false;

bool connectLTE() {
  if (!modem.testAT(1000L)) {
    Serial.println("LTE: no AT response from SIM7600.");
    return false;
  }
  if (!modem.init()) {
    Serial.println("LTE: modem initialization failed; check SIM/PIN.");
    return false;
  }
  if (!modem.waitForNetwork(10000L)) {
    Serial.println("LTE: mobile network registration failed.");
    return false;
  }
  Serial.print("LTE: operator = ");
  Serial.println(modem.getOperator());
  Serial.print("LTE: signal quality (CSQ) = ");
  Serial.println(modem.getSignalQuality());
  if (!modem.gprsConnect(LTE_APN, "", "")) {
    Serial.println("LTE: mobile data activation failed; check Claro APN.");
    return false;
  }
  Serial.print("LTE: mobile data active, IP = ");
  Serial.println(modem.localIP());
  return true;
}

// A plain HTTP request confirms that packets can leave through the SIM.
// No sensor readings or credentials are sent to the test host.
void probeLTE() {
  const char *host = "example.com";
  if (!lteClient.connect(host, 80, 10)) {
    Serial.println("LTE: HTTP test connection failed.");
    lteConnected = false;
    return;
  }
  lteClient.print("GET / HTTP/1.1\r\nHost: example.com\r\nConnection: close\r\n\r\n");
  lteClient.setTimeout(5000);
  String status = lteClient.readStringUntil('\n');
  status.trim();
  lteClient.stop(1000L);
  Serial.print("LTE: HTTP test response = ");
  Serial.println(status.length() ? status : "(no response)");
  if (!status.startsWith("HTTP/1.1 200") && !status.startsWith("HTTP/1.0 200")) {
    lteConnected = false;
  }
}

void serviceLTE(uint32_t now) {
  if (lteConnected && now - lastLteProbeMs < LTE_PROBE_INTERVAL_MS) return;
  if (!lteConnected && now - lastLteAttemptMs < LTE_RETRY_INTERVAL_MS) return;

  if (!lteConnected || !modem.isGprsConnected()) {
    lastLteAttemptMs = millis();
    lteConnected = connectLTE();
    if (!lteConnected) return;
  }
  lastLteProbeMs = millis();
  probeLTE();
}

bool initSD() {
  SPI.begin(7, 8, 9, SD_CS_PIN);
  if (!sd.begin(SdSpiConfig(SD_CS_PIN, SHARED_SPI, SD_SCK_MHZ(25)))) {
    Serial.println("SD initialization failed at 25 MHz; retrying at 4 MHz.");
    sd.printSdError(&Serial);
    sd.end();
    if (!sd.begin(SdSpiConfig(SD_CS_PIN, SHARED_SPI, SD_SCK_MHZ(4)))) {
      Serial.println("SD initialization failed; measurements will continue.");
      sd.printSdError(&Serial);
      sd.end();
      return false;
    }
  }

  SdFile csv;
  if (!csv.open(CSV_PATH, O_CREAT | O_WRITE | O_APPEND)) {
    Serial.println("Could not open datos.csv.");
    sd.printSdError(&Serial);
    sd.end();
    return false;
  }
  if (csv.fileSize() == 0) {
    csv.println(CSV_HEADER);
    if (csv.getWriteError() || !csv.sync()) {
      Serial.println("Could not write the CSV header.");
      csv.close();
      sd.printSdError(&Serial);
      sd.end();
      return false;
    }
  }
  if (!csv.close()) {
    Serial.println("Could not close datos.csv.");
    sd.printSdError(&Serial);
    sd.end();
    return false;
  }
  Serial.println("SD ready: /datos.csv");
  return true;
}

bool appendCSV(uint32_t timestampMs,
               bool flowValid, int16_t flowX100, int flowSamples,
               bool volumeValid, int32_t volumeX100, int volumeSamples,
               bool heightValid, int16_t heightCm, int heightSamples) {
  SdFile csv;
  if (!csv.open(CSV_PATH, O_CREAT | O_WRITE | O_APPEND)) {
    Serial.println("Could not append to datos.csv.");
    sd.printSdError(&Serial);
    return false;
  }

  csv.print(timestampMs);
  csv.print(',');
  if (flowValid) csv.print(flowX100 / 100.0, 2);
  csv.print(',');
  if (volumeValid) csv.print(volumeX100 / 100.0, 2);
  csv.print(',');
  if (heightValid) csv.print(heightCm / 100.0, 2);
  csv.print(',');
  csv.print(flowSamples);
  csv.print(',');
  csv.print(volumeSamples);
  csv.print(',');
  csv.println(heightSamples);

  bool ok = !csv.getWriteError() && csv.sync();
  ok = csv.close() && ok;
  if (!ok) {
    Serial.println("SD write failed.");
    sd.printSdError(&Serial);
  }
  return ok;
}

// Calculates the averages of an array updated in real time
class AverageCalculator {
  public:
    // Amount of data points in the array
    int counter;
    // Maximum size of the array
    int length;
    // Array data size in bits
    int dataSize;
    int16_t* int16array = NULL;
    int32_t* int32array = NULL;
    int16_t int16avg;
    int32_t int32avg;

    // Constructor
    AverageCalculator(int sampleFreq, int avgFreq, int dataSizeinBits) {
      // Store as many samples as possible during one average period
      length = (avgFreq / sampleFreq) + 5;
      // Reset the data point counter
      counter = 0;
      dataSize = dataSizeinBits;

      // Allocate memory for data arrays
      if (dataSize == 16) int16array = (int16_t*)malloc(length * sizeof(int16_t));
      else if (dataSize == 32) int32array = (int32_t*)malloc(length * sizeof(int32_t));
    }

    // Append an int16 value to the array
    void append(int16_t value) {
      // Bounds checking
      if (counter < length) {
        int16array[counter] = value;
        counter = counter + 1;
      }
    }

    // Append an int32 value to the array
    void append(int32_t value) {
      // Bounds checking
      if (counter < length) {
        int32array[counter] = value;
        counter = counter + 1;
      }
    }

    void calculateAverage() {
      if (dataSize == 16) {
        // Calculate the sum of all data points in the array
        int64_t sum = 0;
        for (int i = 0; i < counter; i++) {
          sum = sum + int16array[i];
        }

        // Take the average, ensuring we don't overflow int16_t
        float avgFloat = (float)sum / (float)counter;
        
        // Check if result will fit in int16_t
        if (avgFloat > INT16_MAX) {
          int16avg = INT16_MAX; // Clamp to max value
        } else if (avgFloat < -(INT16_MAX+1)) {
          int16avg = -(INT16_MAX+1); // Clamp to min value
        } else {
          int16avg = (int16_t)avgFloat;
        }

        // Reset the counter
        counter = 0;
      }
      else if (dataSize == 32) {
        // Calculate the sum of all data points in the array
        int64_t sum = 0;
        for (int i = 0; i < counter; i++) {
          sum = sum + int32array[i];
        }

        // Take the average, ensuring we don't overflow int32_t
        float avgFloat = (float)sum / (float)counter;
        
        // Check if result will fit in int32_t
        if (avgFloat > INT32_MAX) {
          int32avg = INT32_MAX; // Clamp to max value
        } else if (avgFloat < -(INT32_MAX+1)) {
          int32avg = -(INT32_MAX+1); // Clamp to min value
        } else {
          int32avg = (int32_t)avgFloat;
        }

        // Reset the counter
        counter = 0;
      }
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
AverageCalculator SignedCurrentFlowArr(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS, 16);
int16_t avgSignedCurrentFlow;

// Net signed volume reading from Octave meter truncated to 32 bits
AverageCalculator NetSignedVolumeArr(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS, 32);
int32_t avgNetSignedVolume;

// Water level height, in meters, truncated to 16 bits
AverageCalculator WaterHeightArr(HEIGHT_POLLING_FREQ_MS, LOGGING_FREQ_MS, 16);
int16_t avgWaterHeight;

// Divider wiring:
// S-LL-01 output -- 24.5 kOhm -- A0 -- 47 kOhm -- GND.
// Therefore V_A0 / V_SENSOR = 47 / (24.5 + 47) = 0.65734.
// The sensor's 0.5-4.5 V output becomes 0.329-2.958 V at A0.
const float R_SENSOR_TO_A0_KOHM = 24.5f;
const float R_A0_TO_GND_KOHM = 47.0f;
const float DIVIDER_RATIO = R_A0_TO_GND_KOHM /
                            (R_SENSOR_TO_A0_KOHM + R_A0_TO_GND_KOHM);

const float SENSOR_VMIN = 0.5f;
const float SENSOR_VMAX = 4.5f;
const float SENSOR_RANGE_M = 5.0f;

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
  analogReadResolution(12);  // Set ADC resolution to 12 bits
  analogSetPinAttenuation(HEIGHT_SENSOR_PIN, ADC_11db); 

  sdReady = initSD();
  lastSdRetryMs = millis();

  LTE.begin(SIM_BAUDRATE, SERIAL_8N1, LTE_RX_PIN, LTE_TX_PIN);
  Serial.println("LTE: SIM7600 UART2 started; first network test in 30 seconds.");
  lastLteAttemptMs = millis();

  // Wait 500ms for Modbus startup
  delay(500);
}

void loop() {
    uint32_t currentMillis = millis();  // Get the current time

    if (!sdReady && currentMillis - lastSdRetryMs >= SD_RETRY_INTERVAL_MS) {
      lastSdRetryMs = currentMillis;
      sdReady = initSD();
    }

    // Send Modbus requests to the Octave meter at the polling frequency
    if (currentMillis - modbusTimeCounter >= MODBUS_POLLING_FREQ_MS) {
      // Read Signed Current Flow from Octave meter via Modbus
      double signedCurrentFlow = NAN;
      if (octave.SignedCurrentFlow_double(&signedCurrentFlow) == 0 &&
          isfinite(signedCurrentFlow) &&
          signedCurrentFlow >= INT16_MIN / 100.0 &&
          signedCurrentFlow <= INT16_MAX / 100.0) {
        // Scale successful readings by 100 to preserve two decimal places.
        SignedCurrentFlowArr.append((int16_t)(signedCurrentFlow * 100.0));
      } else {
        Serial.println("Flow Modbus read failed or exceeded the logging range.");
      }

      // Read Net Signed Volume from Octave meter via Modbus
      double netSignedVolume = NAN;
      if (octave.NetSignedVolume_double(&netSignedVolume) == 0 &&
          isfinite(netSignedVolume) &&
          netSignedVolume >= INT32_MIN / 100.0 &&
          netSignedVolume <= INT32_MAX / 100.0) {
        NetSignedVolumeArr.append((int32_t)(netSignedVolume * 100.0));
      } else {
        Serial.println("Volume Modbus read failed or exceeded the logging range.");
      }

      // Restart time counter
      modbusTimeCounter = currentMillis;
    }

    // Read height sensor value at the polling frequency
    if (currentMillis - heightTimeCounter >= HEIGHT_POLLING_FREQ_MS) {
        // The calibrated voltage is measured at A0.  Restore the sensor voltage
        // before applying the S-LL-01 transfer function: 0.5 V = 0 m,
        // 4.5 V = 5 m.
        uint32_t sensorValue = analogReadMilliVolts(HEIGHT_SENSOR_PIN);
        float vAdc = sensorValue / 1000.0f;
        float vSensor = vAdc / DIVIDER_RATIO;
        float waterHeight = ((vSensor - SENSOR_VMIN) /
                             (SENSOR_VMAX - SENSOR_VMIN)) * SENSOR_RANGE_M;
        waterHeight = constrain(waterHeight, 0.0f, SENSOR_RANGE_M);

        Serial.print("DEBUG raw="); Serial.print(sensorValue);
        Serial.print(" vAdc="); Serial.print(vAdc, 3);
        Serial.print(" vSensor="); Serial.print(vSensor, 3);
        Serial.print(" height="); Serial.println(waterHeight, 3);

        // Store centimetres, rounded rather than systematically truncated.
        int16_t truncatedWaterHeight = (int16_t)(waterHeight * 100.0f + 0.5f);
        WaterHeightArr.append(truncatedWaterHeight);

        // Restart time counter
        heightTimeCounter = currentMillis;
    }

    // Log collected data at the specified interval
    if (currentMillis - loggingTimeCounter >= LOGGING_FREQ_MS) {
        int flowSamples = SignedCurrentFlowArr.counter;
        int volumeSamples = NetSignedVolumeArr.counter;
        int heightSamples = WaterHeightArr.counter;
        bool flowValid = flowSamples > 0;
        bool volumeValid = volumeSamples > 0;
        bool heightValid = heightSamples > 0;

        // Calculate averages
        if (flowValid) {
          SignedCurrentFlowArr.calculateAverage();
          avgSignedCurrentFlow = SignedCurrentFlowArr.int16avg;
        }

        if (volumeValid) {
          NetSignedVolumeArr.calculateAverage();
          avgNetSignedVolume = NetSignedVolumeArr.int32avg;
        }

        if (heightValid) {
          WaterHeightArr.calculateAverage();
          avgWaterHeight = WaterHeightArr.int16avg;
        }


        Serial.print("\nCaudal promedio (x100): ");
        if (flowValid) Serial.print(avgSignedCurrentFlow);
        else Serial.print("N/A");
        Serial.print(", hex: ");
        if (flowValid) Serial.println(avgSignedCurrentFlow, HEX);
        else Serial.println("N/A");
        Serial.print("Volumen promedio (x100): ");
        if (volumeValid) Serial.print(avgNetSignedVolume);
        else Serial.print("N/A");
        Serial.print(", hex: ");
        if (volumeValid) Serial.println(avgNetSignedVolume, HEX);
        else Serial.println("N/A");
        Serial.print("Altura promedio (x100): ");
        if (heightValid) Serial.print(avgWaterHeight);
        else Serial.print("N/A");
        Serial.print(", hex: ");
        if (heightValid) Serial.println(avgWaterHeight, HEX);
        else Serial.println("N/A");

        if (sdReady) {
          sdReady = appendCSV(currentMillis,
                              flowValid, avgSignedCurrentFlow, flowSamples,
                              volumeValid, avgNetSignedVolume, volumeSamples,
                              heightValid, avgWaterHeight, heightSamples);
          if (!sdReady) sd.end();
        }
        
        // Restart time counter
        loggingTimeCounter = currentMillis;
    }

    // Keep the cellular test independent of the sensor and SD paths.
    serviceLTE(millis());
}
