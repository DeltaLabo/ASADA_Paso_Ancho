//Librerias para LoRa
//#include <LoRa.h>
#include "heltec.h"
#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

//Definición de pines para LoRa
//#define SCK 5
//#define MISO 19
//#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

// Se define la frecuencia de operación
const long BAND = 868E6;

// Se definen las variables para el uso de WiFi y things speak
#define WIFI_SSID "LaboratorioDelta"
#define WIFI_PASSWORD "labdelta21!"

#define THINGSPEAK_CHANNEL_ID 2447129
#define THINGSPEAK_API_KEY "R42USYBGS6QQDP6E"

String DatoLoRa;//Cadena de texto para recibir datos del otro LoRa.

void setup() { 
  //initialize Serial Monitor
  Serial.begin(115200);
  
  Serial.println("Prueba de recepcion LoRa");
  
  //SPI.begin(SCK, MISO, MOSI, SS);  //Definimos pines SPI
  LoRa.setPins(SS, RST, DIO0); //Configuramos el LoRa para enviar
  
  if (!LoRa.begin(BAND, true)) {//Intenta transmitir en la banda elegida
    Serial.println("Error iniciando LoRa");//Si no puede transmitir, marca error
    while (1);
  }
  Serial.println("Inicio exitoso de LoRa!");//Mensaje de todo bien en puerto serial
  delay(2000);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando al WiFi...");
  }
  Serial.println("Inicio exitoso de WiFi!");

  WiFiClient client;
  ThingSpeak.begin(client);
  
}

void loop() {

  int tamanoPaquete = LoRa.parsePacket();  //analizamos paquete
  if (tamanoPaquete) {//Si nos llega paquete de datos
    Serial.print("Paquete recibido ");//Muestra confirmaciÃ³n

    while (LoRa.available()) {//Leemos el paquete
      DatoLoRa = LoRa.readString();//Guardamos cadena en variable
      Serial.print(DatoLoRa);//Lo imprimimos en monitor serial
    }

    int rssi = LoRa.packetRssi();//Esto nos imprime la intensidad de seÃ±al recibida
    Serial.print(" con RSSI ");    
    Serial.println(rssi); 

    ThingSpeak.writeField(THINGSPEAK_CHANNEL_ID, 1, 10, THINGSPEAK_API_KEY);
  }
}