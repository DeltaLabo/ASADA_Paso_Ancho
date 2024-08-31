#include <WiFi.h>
#include <ThingSpeak.h>
#include <Arduino.h>

#define WIFI_SSID "LaboratorioDelta"
#define WIFI_PASSWORD "labdelta21!"
#define WRITE_API_KEY "FNYT1J1ZNBLGLXRC"
#define CHANNEL_NUMBER 2353416

WiFiClient  client;

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 15000;

// Variable to hold temperature readings
float valueA;
float valueB;

int thingSpeakErrorCode;

void setup() {
  Serial.begin(115200);  //Initialize serial
  
  WiFi.mode(WIFI_STA);   
  
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect");
      while(WiFi.status() != WL_CONNECTED){
        WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
        delay(5000);     
      } 
      Serial.println("\nConnected.");
    }

    valueA = random(1.0, 10.0) + random(1.0, 10.0)/10.0;
    valueA = random(1.0, 10.0) + random(1.0, 10.0)/10.0;

    ThingSpeak.setField(1, valueA);
    ThingSpeak.setField(2, valueB);
    
    // Write to ThingSpeak.
    // Params: Channel ID, Write API key
    thingSpeakErrorCode = ThingSpeak.writeFields(CHANNEL_NUMBER, WRITE_API_KEY);

    if(thingSpeakErrorCode == 200){
      Serial.println("Channel update successful.");
    }
    else{
      Serial.println("Problem updating channel. HTTP error code " + String(thingSpeakErrorCode));
    }
    lastTime = millis();
  }
}