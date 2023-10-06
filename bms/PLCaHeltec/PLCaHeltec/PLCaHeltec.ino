#include "recolectarDatosBateria.h"
#include "LoRaSender.h"

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial1.begin(9600);
  senderStart();
}

void loop() {
  int i = 0;
  //Se llama a la función pedidoUtil para recolectar los datos de la batería
  byte DatosUtiles[13];
  pedidoUtil(DatosUtiles);
  //Se imprimen los datos obtenidos
  Serial.print("Datos en el loop para transmisión: ");
  for(i=0; i<sizeof(DatosUtiles); i++){
      if(DatosUtiles[i] < 16) Serial.print("0");
      Serial.print(DatosUtiles[i],HEX);
      Serial.print(" ");
    }
  Serial.println(" ");
  //Se envía la cadena de datos por LoRa
  send(DatosUtiles, 13);
  //Se esperan 5 segundos antes de repetir
  delay(5000);
}
