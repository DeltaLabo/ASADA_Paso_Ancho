// Frequency for sending Modbus requests to the slave
#define POLLING_FREQ_MS 1000 // ms

#include "RS485.h"
#include "OctaveModbusWrapper.h"

// Define the OctaveModbusWrapper object, using the RS-485 port for Modbus and Serial0 for logging
OctaveModbusWrapper octave(RS485, Serial);

// Control variable for the Modbus polling frequency
uint32_t lastSentTime = 0UL;

// Control variable to execute Modbus requests only on first loop iteration
bool isFirstLoopIteration = true;


void setup() {
  // Set indicator LED pin as output
  // This LED toggles with the same frequency as the Modbus polling, for verification purposes
  pinMode(40, OUTPUT);
  // Initialize the indicator LED's state
  digitalWrite(40, LOW);

  // Use Serial0 port for debugging and logging the slave readings
  Serial.begin(9600);

  // Start the Modbus serial port
  // SERIAL_8N1: 8 bits, no parity, 1 stop bit
  RS485.begin(octave.modbusBaudrate, HALFDUPLEX, SERIAL_8N1);

  // Start the Octave Modbus object
  octave.begin();

  // Wait 500ms for Modbus startup
  delay(500);
}


void loop() {
  // Send the selected Modbus requests only on the first loop iteration
  if (isFirstLoopIteration == true){
    // Update the control variable so the requests don't get sent again
    isFirstLoopIteration = false;

    /****** Add Modbus requests to send once ******/
  }

  // Send requests at a certain frequency
  else if (millis() - lastSentTime >= POLLING_FREQ_MS) {
    // Update the control variable
    lastSentTime = millis();
    // Toggle the indicator LED at the Modbus polling frequency, for verification purposes 
    digitalWrite(40, !digitalRead(40));

    /****** Add Modbus requests to send at the polling frequency ******/
    octave.ForwardVolume(64);
    octave.SignedCurrentFlow(32);
    octave.ReadAlarms();
    octave.TemperatureValue();
    octave.TemperatureUnit();
    octave.SerialNumber();
  }
}