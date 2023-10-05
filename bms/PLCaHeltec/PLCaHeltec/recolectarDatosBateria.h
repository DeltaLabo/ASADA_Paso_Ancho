#ifndef recolectarDatosBateria
#define recolectarDatosBateria

#include <Arduino.h>

byte* pedidoUtil();

#endif

byte* pedidoUtil()  {
int i=0;
  byte DatosUtiles[13];
  byte DatosGeneral[36];//32
  byte DatosCeldas[15];//10
  byte PedidoGeneral[7] = {0xDD, 0xA5, 0x03, 0x00, 0xFF, 0xFD, 0x77};
  byte PedidoCeldas[7] = {0xDD, 0xA5, 0x04, 0x00, 0xFF, 0xFC, 0x77};

  Serial.println("#### LECTURA DE DATOS ÚTILES ####");

  delay(100); // Add a small delay to allow the data to be sent
  Serial1.flush(); // Clear the buffer to ensure we read only the response
  Serial1.write(PedidoGeneral, sizeof(PedidoGeneral));
  delay(100); // Add a small delay to allow the data to be sent
  Serial1.flush(); // Clear the buffer to ensure we read only the response

  //Serial.write(PedidoGeneral, sizeof(PedidoGeneral));
  if(Serial1.available() > 0){
    Serial1.readBytesUntil(0xFF, DatosGeneral, 36);
    Serial.print("Datos Generales: ");
    for(i=0; i<sizeof(DatosGeneral); i++){
      if(DatosGeneral[i] < 16) Serial.print("0");
      Serial.print(DatosGeneral[i],HEX);
      Serial.print(" ");
    }
    Serial.println(" ");
  }

  delay(100); // Add a small delay to allow the data to be sent
  Serial1.flush(); // Clear the buffer to ensure we read only the response
  Serial1.write(PedidoCeldas, sizeof(PedidoCeldas));
  delay(100); // Add a small delay to allow the data to be sent
  Serial1.flush(); // Clear the buffer to ensure we read only the response

  //Serial.write(PedidoCeldas, sizeof(PedidoCeldas));
  if(Serial1.available() > 0){
    Serial1.readBytesUntil(0xFF, DatosCeldas, 15);
    Serial.print("Datos de Celda: ");
    for(i=0; i<sizeof(DatosCeldas); i++){
      if(DatosCeldas[i] < 16) Serial.print("0");
      Serial.print(DatosCeldas[i],HEX);
      Serial.print(" ");
    }
    Serial.println(" ");
  }


  Serial.print("Datos seleccionados para transmisión: ");
  //Voltaje Actual
  DatosUtiles[0]=DatosGeneral[4];
  DatosUtiles[1]=DatosGeneral[5];
  //Corriente Actual
  DatosUtiles[2]=DatosGeneral[6];
  DatosUtiles[3]=DatosGeneral[7];
  //Porcentaje Restante
  DatosUtiles[4]=DatosGeneral[23];
  //Voltaje Celda 1
  DatosUtiles[5]=DatosCeldas[4];
  DatosUtiles[6]=DatosCeldas[5];
  //Voltaje Celda 2
  DatosUtiles[7]=DatosCeldas[6];
  DatosUtiles[8]=DatosCeldas[7];
  //Voltaje Celda 3
  DatosUtiles[9]=DatosCeldas[8];
  DatosUtiles[10]=DatosCeldas[9];
  //Voltaje Celda 4
  DatosUtiles[11]=DatosCeldas[10];
  DatosUtiles[12]=DatosCeldas[11];

  for(i=0; i<sizeof(DatosUtiles); i++){
      if(DatosUtiles[i] < 16) Serial.print("0");
      Serial.print(DatosUtiles[i],HEX);
      Serial.print(" ");
    }
  Serial.println(" ");
  return DatosUtiles;
}
