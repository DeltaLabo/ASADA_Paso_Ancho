/*
   Copyright (c) 2020 Boot&Work Corp., S.L. All rights reserved

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <LoRa.h>

uint32_t counter = 0UL;

////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600L);

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

////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  // Send counter as packet payload
  LoRa.send((uint8_t*) &counter, sizeof(counter));
  Serial.println("Sending counter...");

  // Wait packet to be sent
  LoRa.waitPacketSent();
  Serial.println("Counter sent!");

  // The packet is sent, increment the counter and wait to send the next one
  ++counter;
  delay(5000);
}
