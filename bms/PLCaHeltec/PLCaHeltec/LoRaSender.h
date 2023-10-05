#ifndef LoRaSender
#define LoRaSender

#include <Arduino.h>

void senderStart();
void send();

#endif

#include <LoRa.h>

uint32_t counter = 0UL;

void senderStart() {
  
  // Begin LoRa hardware
  if (!LoRa.begin()) {
    Serial.println("LoRa begin error: is LoRa module connected?");
    while (true);
  }

  // Default LoRa values after begin:
  // Frequency: 434.0MHz
  // Modulation GFSK_Rb250Fd250
  // TX power: +13dBm

  // Set LoRa working frequency
  if (!LoRa.setFrequency(868.0)) {
    Serial.println("LoRa set frequency error");
    while (true);
  }

  Serial.println("Send started");
}


void send() {
  // Send counter as packet payload
  LoRa.send((uint8_t*) &counter, sizeof(counter));
  Serial.println("Sending counter...");

  // Wait packet to be sent
  LoRa.waitPacketSent();
  Serial.println("Counter sent!");

  // The packet is sent, increment the counter and wait to send the next one
  ++counter;
}
