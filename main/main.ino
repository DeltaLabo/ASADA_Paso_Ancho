// the setup routine runs once when you press reset:
#include <RTC.h>
const int YEAR = 2018;
const int MONTH = 3;
const int DAY = 28;
const int HOUR = 13;
const int MINUTE = 24;
const int SECOND = 25;

byte status[] = {0xDD, 0xA5, 0x03, 0x00, 0xFF, 0xFD, 0x77};
byte recep[50] = {0x00};
bool one_flag = 0;
int i = 0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("Configuring RTC: ");
  Serial.println();
  RTC.setYear(YEAR);                      //sets year
  RTC.setMonth(MONTH);                   //sets month
  RTC.setMonthDay(DAY);                   //sets day
  RTC.setHour(HOUR);                      //sets hour
  RTC.setMinute(MINUTE);                  //sets minute
  RTC.setSecond(SECOND);                  //sets second
  //RTC.setTime(TIME);                   //sets UNIX timestamp
  if(!RTC.write()){                       //RTC.write writes in the RTC memory all that has been set
    Serial.println("Write date error: Are the switches well placed?");
  }
  cli();//stop interrupts

  //set timer4 interrupt at 1Hz
  TCCR4A = 0;// set entire TCCR1A register to 0
  TCCR4B = 0;// same for TCCR1B
  TCNT4  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR4A = 15624/1;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR4B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR4B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK4 |= (1 << OCIE4A);

  sei();//allow interrupts
}

// the loop routine runs over and over again forever:
void loop() {

  // read the input on analog pin 0:
  // int sensorValue = analogRead(A0);
  // // print out the value you read:
  // Serial.println(sensorValue);
  if(one_flag){
    one_flag = 0;
    if (!RTC.read()) {
      Serial.println("Read date error: is time set?");
    } else {
      Serial.print("Time: ");
      Serial.print(RTC.getYear());
      Serial.print("-");
      Serial.print(RTC.getMonth());
      Serial.print("-");
      Serial.print(RTC.getMonthDay());
      Serial.print(" ");
      Serial.print(RTC.getHour());
      Serial.print(":");
      Serial.print(RTC.getMinute());
      Serial.print(":");
      Serial.print(RTC.getSecond());
      Serial.print(" (");
      Serial.print(RTC.getTime());
      Serial.println(")");
    }

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
  }
}

ISR(TIMER4_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
  one_flag = 1;
}
