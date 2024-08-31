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

  // Se define el header y el tail
  byte header[2] = {0xAA, 0xDD};
  byte tail[2] = {0xFF, 0x77};

  // Crea un nuevo array para los datos extendidos
  byte DatosExtendidos[100]; // 2 (header) + 13 (datos originales) + 83 (reserved) + 2 (tail) = 100 bytes

  // Copia el encabezado al principio
  for (i = 0; i < 2; i++) {
    DatosExtendidos[i] = header[i];
  }

  // Copia los datos originales después del encabezado
  for (i = 0; i < 13; i++) {
    DatosExtendidos[i + 2] = DatosUtiles[i];
  }

  // Se agregan los espacios reserved
  for (i = 0; i < 83; i++) {
    DatosExtendidos[i + 15] = (i & 0xFF);
  }

  // Copia el pie al final
  for (i = 0; i < 2; i++) {
    DatosExtendidos[i + 98] = tail[i];
  }

  //Se imprimen los datos obtenidos que son de utilidad
  Serial.print("Datos en el loop para transmisión: ");
  for(i=0; i<sizeof(DatosUtiles); i++){
      if(DatosUtiles[i] < 16) Serial.print("0");
      Serial.print(DatosUtiles[i],HEX);
      Serial.print(" ");
    }
  Serial.println(" ");

  //Se envía la cadena de datos por LoRa
  send(DatosExtendidos, 100);
  //Se esperan 5 segundos antes de repetir
  delay(10000);
}
