// the setup routine runs once when you press reset:
byte status[] = {0xDD, 0xA5, 0x03, 0x00, 0xFF, 0xFD, 0x77};
byte recep[50] = {0x00};
int i = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial1.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0:
  // int sensorValue = analogRead(A0);
  // // print out the value you read:
  // Serial.println(sensorValue);
  Serial1.write(status, sizeof(status));
  //Serial.write(status, sizeof(status));
  if(Serial1.available() > 0){
    Serial1.readBytesUntil(0x77, recep, 50);
    Serial.print("Datos en serial: ");
    for(i=0; i<sizeof(recep); i++){
      if(recep[i] < 16) Serial.print("0");
      Serial.print(recep[i],HEX);
    }
    Serial.println(" ");
  }
  




  delay(1000);  // delay in between reads for stability
}
