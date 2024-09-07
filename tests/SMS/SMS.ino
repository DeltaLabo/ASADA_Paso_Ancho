#include "SIM7600Wrapper/SIM7600Wrapper.h"
#include <HardwareSerial.h>

#define LTE_TX_PIN D4
#define LTE_RX_PIN D5

HardwareSerial simSerial(0);
SIM7600Wrapper sim(simSerial);

uint8_t lastSIMOperationResult = 0;

void setup() {
  delay(5000);

  simSerial.begin(115200, SERIAL_8N1, LTE_RX_PIN, LTE_TX_PIN);
  Serial.begin(9600); // For logging

  sim.begin();

  lastSIMOperationResult = sim.checkPower();
  Serial.print("Power check: ");
  Serial.println(sim.errorCodeToName[lastSIMOperationResult]);

  lastSIMOperationResult = sim.checkSignal();
  Serial.print("Signal check: ");
  Serial.println(sim.errorCodeToName[lastSIMOperationResult]);
}

void loop() {
  float remainingData;

  lastSIMOperationResult = sim.checkRemainingData(&remainingData, nullptr);
  Serial.print("Remaining data: ");
  Serial.print(sim.errorCodeToName[lastSIMOperationResult]);
  Serial.print(", ");
  Serial.println(remainingData);
}