#include <HardwareSerial.h>

#include "src/OctaveModbusWrapper/ESP32/OctaveModbusWrapper.h"
//#include "src/SIM7600Wrapper/SIM7600Wrapper.h"
#include "frequencies.h"
#include "pins.h"
#include "src/metrics.h"

#define MODBUS_BAUDRATE 2400
#define SIM_BAUDRATE 115200
#define BMS_BAUDRATE 9600

// Define the HardwareSerial used as an RS-485 port
HardwareSerial RS485(1);

// Define the OctaveModbusWrapper object, using the RS-485 port for Modbus
OctaveModbusWrapper octave(RS485);

// Variable to store the last error code
uint8_t modbusErrorCode;

// Control variable for the Modbus polling frequency
uint32_t modbusTimeCounter = 0UL;

// Control variable for the height sensor polling frequency
uint32_t heightTimeCounter = 0UL;

// Control variable for the LoRa sender loop
uint32_t loggingTimeCounter = 0UL;

MetricsManager_int16 signedCurrentFlowMetrics;
MetricsManager_int32 netSignedVolumeMetrics;
MetricsManager_int16 waterHeightMetrics;

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

  // Start the Octave Modbus object
  octave.begin(MODBUS_BAUDRATE);

  pinMode(HEIGHT_SENSOR_PIN, INPUT);

  signedCurrentFlowMetrics.addMetric(new AverageMetric_int16(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS));
  signedCurrentFlowMetrics.addMetric(new MaxMetric_int16());
  signedCurrentFlowMetrics.addMetric(new MinMetric_int16());

  netSignedVolumeMetrics.addMetric(new AverageMetric_int32(MODBUS_POLLING_FREQ_MS, LOGGING_FREQ_MS));
  netSignedVolumeMetrics.addMetric(new MaxMetric_int32());
  netSignedVolumeMetrics.addMetric(new MaxMetric_int32());

  waterHeightMetrics.addMetric(new AverageMetric_int16(HEIGHT_POLLING_FREQ_MS, LOGGING_FREQ_MS));
  waterHeightMetrics.addMetric(new MaxMetric_int16());
  waterHeightMetrics.addMetric(new MinMetric_int16());

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
        signedCurrentFlowMetrics.append(truncatedSignedCurrentFlow);

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
        waterHeightMetrics.append(truncatedWaterHeight);

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
        if (signedCurrentFlowMetrics.hasOverflowed(0)) {
            Serial.print(" (overflow)");
          }
        Serial.print(", hex: ");
        Serial.println(signedCurrentFlowMetrics.getResult(0), HEX);
        Serial.print("Caudal max (x100): ");
        Serial.print(signedCurrentFlowMetrics.getResult(1));
        Serial.print(", hex: ");
        Serial.println(signedCurrentFlowMetrics.getResult(1), HEX);
        Serial.print("Caudal min (x100): ");
        Serial.print(signedCurrentFlowMetrics.getResult(2));
        Serial.print(", hex: ");
        Serial.println(signedCurrentFlowMetrics.getResult(2), HEX);

        Serial.print("Volumen promedio (x100): ");
        Serial.print(netSignedVolumeMetrics.getResult(0));
        if (netSignedVolumeMetrics.hasOverflowed(0)) {
            Serial.print(" (overflow)");
          }
        Serial.print(", hex: ");
        Serial.println(netSignedVolumeMetrics.getResult(0), HEX);
        Serial.print("Volumen max (x100): ");
        Serial.print(netSignedVolumeMetrics.getResult(1));
        Serial.print(", hex: ");
        Serial.println(netSignedVolumeMetrics.getResult(1), HEX);
        Serial.print("Volumen min (x100): ");
        Serial.print(netSignedVolumeMetrics.getResult(2));
        Serial.print(", hex: ");
        Serial.println(netSignedVolumeMetrics.getResult(2), HEX);
    
        Serial.print("Altura promedio (x100): ");
        Serial.print(waterHeightMetrics.getResult(0));
        if (waterHeightMetrics.hasOverflowed(0)) {
            Serial.print(" (overflow)");
          }
        Serial.print(", hex: ");
        Serial.println(waterHeightMetrics.getResult(0), HEX);
        Serial.print("Altura max (x100): ");
        Serial.print(waterHeightMetrics.getResult(1));
        Serial.print(", hex: ");
        Serial.println(waterHeightMetrics.getResult(1), HEX);
        Serial.print("Altura min (x100): ");
        Serial.print(waterHeightMetrics.getResult(2));
        Serial.print(", hex: ");
        Serial.println(waterHeightMetrics.getResult(2), HEX);
        // Restart time counter
        loggingTimeCounter = currentMillis;
    }
}