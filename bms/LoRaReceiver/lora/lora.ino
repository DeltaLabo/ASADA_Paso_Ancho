/*  RECEPTOR DE PAQUETES LORA CON PANTALLA OLED 
 *  DOMANDO INGENIERÃA
 *  Visita www.domandoingenieria.com para mÃ¡s cÃ³digos, tutoriales y recomendaciones de proyectos de 
 *  ingenierÃ­a.  SÃ­guenos en Youtube: https://www.youtube.com/channel/UC4l_rsWoPPi8weKHFPqRaQg?sub_confirmation=1 
 */

//LibrerÃ­as para LoRa
#include <LoRa.h>
#include <SPI.h>

//Libraries para comunicar con y dibujar en la pantalla OLED integrada
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Debemos definir los pines que se utilizarÃ¡n por el mÃ³dulo LoRa
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

//AquÃ­ definimos una frecuencia de operaciÃ³n segÃºn nuestra ubicaciÃ³n. 433E6 para Asia, 866E6 para Europa, 915E6 para AmÃ©rica
#define BAND 868E6

//Definimos los pines necesarios para conectar con pantalla OLED
#define ANCHOPANTALLA 128 // El ancho de la pantalla en pixeles es de 128px
#define ALTOPANTALLA 64 // El ancho de la pantalla en pixeles es de 64px
#define OLED_SDA 4
#define OLED_SCL 15 
#define OLED_RST 16

Adafruit_SSD1306 display(ANCHOPANTALLA, ALTOPANTALLA, &Wire, OLED_RST);

String DatoLoRa;//Cadena de texto para recibir datos del otro LoRa.

void setup() { 
  //initialize Serial Monitor
  Serial.begin(115200);
  
  pinMode(OLED_RST, OUTPUT);//reseteamos la pantalla OLED para comenzar
  digitalWrite(OLED_RST, LOW);
  delay(20);
  digitalWrite(OLED_RST, HIGH);
  
  Wire.begin(OLED_SDA, OLED_SCL); //inicia OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // 0x3C representa 128x32
    Serial.println(F("Fallo iniciando SSD1306"));
    for(;;); // Si detecta el fallo anterior, detiene el cÃ³digo aquÃ­ hasta que se reinicie
  }

  display.clearDisplay();//Borramos pantalla
  display.setTextColor(WHITE);//Definimos texto color blanco
  display.setTextSize(1);//TamaÃ±o de fuente a 1 punto
  display.setCursor(0,10);//Comenzamos a graficar desde coordenadas 0,0
  display.print("RECEPTOR LORA ");
  display.display();

  Serial.println("Prueba de recepciÃ³n LoRa");
  
  SPI.begin(SCK, MISO, MOSI, SS);  //Definimos pines SPI
  LoRa.setPins(SS, RST, DIO0); //Configuramos el LoRa para enviar
  
  if (!LoRa.begin(BAND)) {//Intenta transmitir en la banda elegida
    Serial.println("Error iniciando LoRa");//Si no puede transmitir, marca error
    while (1);
  }
  Serial.println("Inicio exitoso de LoRa!");//Mensaje de todo bien en puerto serial
  display.setCursor(0,30);
  display.print("Inicio exitoso de LoRa!");//Mensaje de todo bien en pantalla OLED
  display.display();
  delay(2000);//Esperamos un par de segundos
}

void loop() {

  int i=0;
  byte DatosRecibidos[13];
  String DatosComoString = "";

  int tamanoPaquete = LoRa.parsePacket();  //analizamos paquete
  if (tamanoPaquete) {//Si nos llega paquete de datos
    Serial.print("Paquete recibido ");//Muestra confirmaciÃ³n

    while (LoRa.available()) {
      LoRa.readBytes(DatosRecibidos, 13);
      for (int i = 0; i < 13; i++) {
        DatosComoString += String(DatosRecibidos[i], HEX);
        DatosComoString += " ";
      }
      Serial.println(DatosComoString);
    }

    int rssi = LoRa.packetRssi();//Esto nos imprime la intensidad de seÃ±al recibida
    Serial.print(" con RSSI ");    
    Serial.println(rssi);

    // Mostramos informaciÃ³n captada
    display.clearDisplay();
    display.setCursor(0,0);
    display.print("Receptor LoRa");//Mensaje
    display.setCursor(0,20);
    display.print("Paquete recibido:");//Imprime datos recibidos
    display.setCursor(0,30);
    display.print(DatosComoString);
    display.setCursor(0,50);
    display.print("RSSI:");//Imprime intensidad de seÃ±al
    display.setCursor(30,50);
    display.print(rssi);
    display.display();   
  }
}