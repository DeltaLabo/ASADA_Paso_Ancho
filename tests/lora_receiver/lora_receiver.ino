/*  RECEPTOR DE PAQUETES LORA CON PANTALLA OLED 
 *  DOMANDO INGENIERÃA
 *  Visita www.domandoingenieria.com para mÃ¡s cÃ³digos, tutoriales y recomendaciones de proyectos de 
 *  ingenierÃ­a.  SÃ­guenos en Youtube: https://www.youtube.com/channel/UC4l_rsWoPPi8weKHFPqRaQg?sub_confirmation=1 
 */

//LibrerÃ­as para LoRa
#include <LoRa.h>
#include <SPI.h>

//Debemos definir los pines que se utilizarÃ¡n por el mÃ³dulo LoRa
#define SCK 14
#define MISO 16
#define MOSI 15
#define SS 13
#define RST 17
#define DIO0 19


//AquÃ­ definimos una frecuencia de operaciÃ³n segÃºn nuestra ubicaciÃ³n. 433E6 para Asia, 866E6 para Europa, 915E6 para AmÃ©rica
#define BAND 868E6

String DatoLoRa;//Cadena de texto para recibir datos del otro LoRa.

void setup() { 
  //initialize Serial Monitor
  Serial.begin(115200);

  Serial.println("Prueba de recepciÃ³n LoRa");
  
  SPI.begin(SCK, MISO, MOSI, SS);  //Definimos pines SPI
  LoRa.setPins(SS, RST, DIO0); //Configuramos el LoRa para enviar
  
  if (!LoRa.begin(BAND)) {//Intenta transmitir en la banda elegida
    Serial.println("Error iniciando LoRa");//Si no puede transmitir, marca error
    while (1);
  }
  Serial.println("Inicio exitoso de LoRa!");//Mensaje de todo bien en puerto serial
  delay(2000);//Esperamos un par de segundos
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
  }
}