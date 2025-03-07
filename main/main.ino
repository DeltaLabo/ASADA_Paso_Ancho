#include <HardwareSerial.h>

#include "src/OctaveModbusWrapper/ESP32/OctaveModbusWrapper.h"
//#include "src/SIM7600Wrapper/SIM7600Wrapper.h"
#include "frequencies.h"
#include "pins.h"
#include "src/metrics.h"

#define MODBUS_BAUDRATE 2400
#define SIM_BAUDRATE 115200
#define BMS_BAUDRATE 9600

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
// Define the HardwareSerial used for SIM7600 module
HardwareSerial SIM(2);

// Define the OctaveModbusWrapper object, using the RS-485 port for Modbus
OctaveModbusWrapper octave(RS485);

// Define the SIM7600Wrapper object for cellular communication
SIM7600Wrapper sim(SIM);

// Define the DataLogger object using the SIM7600Wrapper
DataLogger dataLogger(sim);

// Control variable for the Modbus polling frequency
uint32_t modbusTimeCounter = 0UL;

// Control variable for the height sensor polling frequency
uint32_t heightTimeCounter = 0UL;

// Control variable for the LoRa sender loop
uint32_t loggingTimeCounter = 0UL;

// Control variable for the Data Logging frequency
uint32_t dataLoggingTimeCounter = 0UL;

// Net signed volume reading from Octave meter truncated to 32 bits
AverageCalculator NetSignedVolumeArr(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS, 32);
int32_t avgNetSignedVolume;

// Water level height, in meters, truncated to 16 bits
AverageCalculator WaterHeightArr(HEIGHT_POLLING_FREQ_MS, LOGGING_FREQ_MS, 16);
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

  // Start the SIM7600 serial port
  SIM.begin(SIM_BAUDRATE, SERIAL_8N1, SIM_RX_PIN, SIM_TX_PIN);
  
  // Initialize the Octave Modbus object
  octave.begin(MODBUS_BAUDRATE);
  
  // Initialize the SIM7600 module
  sim.begin();
  
  // Configure the DataLogger
  dataLogger.setHTTPEndpoint("https://your-server.com/api/data");
  dataLogger.setMQTTBroker("mqtt.your-broker.com", 1883, "asada-device-1", "username", "password");
  dataLogger.setMQTTTopic("asada/pasoAncho/metrics");

  pinMode(HEIGHT_SENSOR_PIN, INPUT);

  signedCurrentFlowMetrics.addMetric(new AverageMetric_int16(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS));
  signedCurrentFlowMetrics.addMetric(new MaxMetric_int16());
  signedCurrentFlowMetrics.addMetric(new MinMetric_int16());

  netSignedVolumeMetrics.addMetric(new AverageMetric_int32(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS));
  netSignedVolumeMetrics.addMetric(new MaxMetric_int32());
  netSignedVolumeMetrics.addMetric(new MinMetric_int32());

  waterHeightMetrics.addMetric(new AverageMetric_int16(HEIGHT_POLLING_FREQ_MS, LOGGING_FREQ_MS));
  waterHeightMetrics.addMetric(new MaxMetric_int16());
  waterHeightMetrics.addMetric(new MinMetric_int16());

  // Initialize SIM7600 module
  uint8_t simStatus = sim.initialCheck();
  if (simStatus != 0) {
    Serial.print("SIM module initialization failed: ");
    sim.PrintError(simStatus, Serial);
  } else {
    // Check signal strength
    simStatus = sim.checkSignal();
    if (simStatus != 0) {
      Serial.print("SIM signal check failed: ");
      sim.PrintError(simStatus, Serial);
    }
  }

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
        netSignedVolumeMetrics.append(truncatedNetSignedVolume);

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
        signedCurrentFlowMetrics.calculate();
        netSignedVolumeMetrics.calculate();
        waterHeightMetrics.calculate();

        Serial.print("\nCaudal promedio (x100): ");
        Serial.print(signedCurrentFlowMetrics.getResult(0));
        Serial.print("\nCaudal max (x100): ");
        Serial.print(signedCurrentFlowMetrics.getResult(1));
        Serial.print("\nCaudal min (x100): ");
        Serial.print(signedCurrentFlowMetrics.getResult(2));
        
        Serial.print("\nVolumen acum. (x100): ");
        Serial.print(netSignedVolumeMetrics.getResult(0));
        
        Serial.print("\nAltura promedio (x100): ");
        Serial.print(waterHeightMetrics.getResult(0));
        Serial.print("\nAltura max (x100): ");
        Serial.print(waterHeightMetrics.getResult(1));
        Serial.print("\nAltura min (x100): ");
        Serial.print(waterHeightMetrics.getResult(2));
        
        // Restart time counter
        loggingTimeCounter = currentMillis;
    }
    
    // Send data to remote server at the logging interval
    if (currentMillis - dataLoggingTimeCounter >= DATA_LOGGING_FREQ_MS) {
        Serial.println("Sending data to remote servers...");
        
        // First, clear any previous variables
        dataLogger.clearVariables();
        
        // Add our metrics to the DataLogger
        // Add flow average, max, min
        dataLogger.addVariable("flow_avg", (float)signedCurrentFlowMetrics.getResult(0)/100.0, "m3/h");
        dataLogger.addVariable("flow_max", (float)signedCurrentFlowMetrics.getResult(1)/100.0, "m3/h");
        dataLogger.addVariable("flow_min", (float)signedCurrentFlowMetrics.getResult(2)/100.0, "m3/h");
        
        // Add volume
        dataLogger.addVariable("volume", (float)netSignedVolumeMetrics.getResult(0)/100.0, "m3");
        
        // Add water height average, max, min
        dataLogger.addVariable("height_avg", (float)waterHeightMetrics.getResult(0)/100.0, "m");
        dataLogger.addVariable("height_max", (float)waterHeightMetrics.getResult(1)/100.0, "m");
        dataLogger.addVariable("height_min", (float)waterHeightMetrics.getResult(2)/100.0, "m");
        
        // Try to send data via HTTP
        Serial.println("Sending data via HTTP...");
        uint8_t httpResult = dataLogger.logToHTTP();
        if (httpResult != 0) {
            Serial.print("HTTP logging failed: ");
            sim.PrintError(httpResult, Serial);
        } else {
            Serial.println("HTTP logging successful");
        }
        
        // Try to send data via MQTT
        Serial.println("Sending data via MQTT...");
        uint8_t mqttResult = dataLogger.logToMQTT();
        if (mqttResult != 0) {
            Serial.print("MQTT logging failed: ");
            sim.PrintError(mqttResult, Serial);
        } else {
            Serial.println("MQTT logging successful");
        }
        
        // Restart time counter
        dataLoggingTimeCounter = currentMillis;
    }
}