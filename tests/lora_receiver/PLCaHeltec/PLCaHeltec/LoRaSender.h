#include <Arduino.h>
#include <LoRa.h>

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

void send(byte* DatosUtiles, int longitud) {
  int i = 0;

  // Send the data as packet payload
  LoRa.send(DatosUtiles, longitud);
  Serial.println("Enviando información por LoRa...");

  for(i=0; i < longitud; i++){
      if(DatosUtiles[i] < 16) Serial.print("0");
      Serial.print(DatosUtiles[i],HEX);
      Serial.print(" ");
    }
  Serial.println(" ");

  // Wait for the packet to be sent
  LoRa.waitPacketSent();
  Serial.println("¡Información enviada!");
}


