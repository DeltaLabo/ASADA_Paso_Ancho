#include "recolectarDatosBateria.h"
#include "LoRaSender.h"

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial1.begin(9600);
  senderStart();
}

void loop() {
  byte* datosUtiles = pedidoUtil();
  delay(5000);
}