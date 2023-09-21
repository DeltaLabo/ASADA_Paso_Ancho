// the setup routine runs once when you press reset:
uint8_t status[] = {0xAA, 0xA5, 0x03, 0x00, 0xFF, 0xFD, 0x77};
uint8_t buffer[20] = {};
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
  Serial1.readBytesUntil(0x77, buffer, 20);
  for(i=0; i<sizeof(buffer); i++){
      Serial.print(buffer[i],HEX);
  }


  delay(1000);  // delay in between reads for stability
}
