//Librerias para LoRa
#include "heltec.h"
#include <SPI.h>

//Debemos definir los pines que se utilizaran por el modulo LoRa
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

//Aqui­ definimos una frecuencia de operacion segun nuestra ubicacion. 433E6 para Asia, 866E6 para Europa, 915E6 para America
const long BAND = 868E6;

String DatoLoRa;//Cadena de texto para recibir datos del otro LoRa.

void setup() { 
  //initialize Serial Monitor
  Serial.begin(115200);

  Serial.println("Prueba de recepcion LoRa");
  
  SPI.begin(SCK, MISO, MOSI, SS);  //Definimos pines SPI
  LoRa.setPins(SS, RST, DIO0); //Configuramos el LoRa para enviar
  
  if (!LoRa.begin(BAND, false)) {//Intenta transmitir en la banda elegida
    Serial.println("Error iniciando LoRa");//Si no puede transmitir, marca error
    while (1);
  }
  Serial.println("Inicio exitoso de LoRa!");//Mensaje de todo bien en puerto serial
  delay(2000);//Esperamos un par de segundos
}

void loop() {

  int i=0;
  byte DatosRecibidos[100];
  String DatosComoString = "";

  int tamanoPaquete = LoRa.parsePacket();  //analizamos paquete
  if (tamanoPaquete) {//Si nos llega paquete de datos
    Serial.print("Paquete recibido ");//Muestra confirmacion

    while (LoRa.available()) {
      LoRa.readBytes(DatosRecibidos, 100);
      for (int i = 0; i < 100; i++) {
        DatosComoString += String(DatosRecibidos[i], HEX);
        DatosComoString += " ";
      }
      Serial.println(DatosComoString);
    }

    int rssi = LoRa.packetRssi();//Esto nos imprime la intensidad de senal recibida
    Serial.print(" con RSSI ");    
    Serial.println(rssi);
  }
}