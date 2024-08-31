/**
*  @filename   :   Waveshare_SIM7600.cpp
*  @brief      :   Implements for sim7600 library
*  @author     :   Kaloha from Waveshare
*
*  Copyright (C) Waveshare     April 27 2018
*  http://www.waveshare.com  http://www.waveshare.net
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documnetation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to  whom the Software is
* furished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#include "Waveshare_SIM7600.h"
#include <HardwareSerial.h>

// Change to SoftwareSerial if needed
extern HardwareSerial SIMSerial;

Sim7x00::Sim7x00(){
}

Sim7x00::~Sim7x00(){
}

// Response from the SIM7600 module
char response[100];

/**************************Power on Sim7x00**************************/
uint8_t Sim7x00::PowerOnCheck(){
  uint8_t result = 0;

  // Check module power 3 times
  for (int i=0; i<3; i++) {
    result = sendATcommand("AT", "OK", 2000);
    if (result != 0) {
        break;
    }
  }

  SIMSerial.println("AT+CSQ");

  while(SIMSerial.available() == 0);

  char response[200];
  int responseIndex = 0;

  while (SIMSerial.available() > 0) {
    response[responseIndex] = SIMSerial.read();
    responseIndex++;
    // check if the desired answer (OK) is in the response of the module
    if (strstr(response, "OK") != NULL)    
    {
        break;
    }
  }
}


/**************************SMS sending and receiving message **************************/
//SMS sending short message
bool Sim7x00::SendingShortMessage(const char* PhoneNumber,const char* Message){
  uint8_t answer = 0;
  char aux_string[30];

  Serial.print("Setting SMS mode...\n");
  sendATcommand("AT+CMGF=1", "OK", 1000);    // sets the SMS mode to text
  Serial.print("Sending Short Message\n");
    
  sprintf(aux_string,"AT+CMGS=\"%s\"", PhoneNumber);

  answer = sendATcommand(aux_string, ">", 3000);    // send the SMS number
  if (answer == 1)
  {
      SIMSerial.println(Message);
      SIMSerial.write(0x1A);
      answer = sendATcommand("", "OK", 20000);
      if (answer == 1)
      {
          Serial.print("Sent successfully \n"); 
          return true;   
      }
      else
      {
          Serial.print("error \n");
          return false;
      }
  }
  else
  {
 //     SIMSerial.print(answer);
      Serial.print(" error.\n");
      return false;
  }
}

//SMS receiving short message
bool Sim7x00::ReceivingShortMessage(){
  uint8_t answer = 0;
  int i = 0;
  char RecMessage[200];

  Serial.print("Setting SMS mode...\n");
  sendATcommand("AT+CMGF=1", "OK", 1000);    // sets the SMS mode to text
  sendATcommand("AT+CPMS=\"SM\",\"SM\",\"SM\"", "OK", 1000);    // selects th memory

    answer = sendATcommand("AT+CMGR=1", "+CMGR:", 2000);    // reads the first SMS

  if (answer == 1)
    {
        answer = 0;
        while(SIMSerial.available() == 0);
        // this loop reads the data of the SMS
        do{
            // if there are data in the UART input buffer, reads it and checks for the asnwer
            if(SIMSerial.available() > 0){    
                RecMessage[i] = SIMSerial.read();
                i++;
                // check if the desired answer (OK) is in the response of the module
                if (strstr(RecMessage, "OK") != NULL)    
                {
                    answer = 1;
                }
            }
        }while(answer == 0);    // Waits for the asnwer with time out
        
 //       RecMessage[i] = '\0';
        
        Serial.print(RecMessage); 
        Serial.print("\n");      
        
    }
    else
    {
        Serial.print(answer);
        Serial.print(" error.\n");
    return false;
    }

  return true;
}

/**************************GPS positoning**************************/
bool Sim7x00::GPSPositioning(){

    uint8_t answer = 0;
    bool RecNull = true;
    int i = 0;
    char RecMessage[200];
    char LatDD[3],LatMM[10],LogDD[4],LogMM[10],DdMmYy[7] ,UTCTime[7];
    int DayMonthYear;
    float Lat = 0;
    float Log = 0;
    
    memset(RecMessage, '\0', 200);    // Initialize the string
    memset(LatDD, '\0', 3);    // Initialize the string
    memset(LatMM, '\0', 10);    // Initialize the string
    memset(LogDD, '\0', 4);    // Initialize the string
    memset(LogMM, '\0', 10);    // Initialize the string
    memset(DdMmYy, '\0', 7);    // Initialize the string
    memset(UTCTime, '\0', 7);    // Initialize the string

    Serial.print("Start GPS session...\n");
    sendATcommand("AT+CGPS=1,1", "OK", 1000);    // start GPS session, standalone mode

    delay(2000);

    while(RecNull)
    {
        answer = sendATcommand("AT+CGPSINFO", "+CGPSINFO: ", 1000);    // start GPS session, standalone mode

        if (answer == 1)
        {
            answer = 0;
            while(SIMSerial.available() == 0);
            // this loop reads the data of the GPS
            do{
                // if there are data in the UART input buffer, reads it and checks for the asnwer
                if(SIMSerial.available() > 0){    
                    RecMessage[i] = SIMSerial.read();
                    i++;
                    // check if the desired answer (OK) is in the response of the module
                    if (strstr(RecMessage, "OK") != NULL)    
                    {
                        answer = 1;
                    }
                }
            }while(answer == 0);    // Waits for the asnwer with time out
            
            RecMessage[i] = '\0';
            Serial.print(RecMessage);
            Serial.print("\n");

            if (strstr(RecMessage, ",,,,,,,,") != NULL) 
            {
                memset(RecMessage, '\0', 200);    // Initialize the string
                i = 0;
                answer = 0;
                delay(1000);
            }
            else
            {
                RecNull = false;
                sendATcommand("AT+CGPS=0", "OK:", 1000);
            } 
        }
        else
        {
            Serial.print("error \n");
            return false;
        }
        delay(2000);

    }

    strncpy(LatDD,RecMessage,2);
    LatDD[2] = '\0';
//    SIMSerial.print("LatDD:");
//    SIMSerial.print(LatDD);
    
    strncpy(LatMM,RecMessage+2,9);
    LatMM[9] = '\0';
//    SIMSerial.print(" LatMM:");
//    SIMSerial.print(LatMM);
    
    Lat = atoi(LatDD) + (atof(LatMM)/60);
    if(RecMessage[12] == 'N')
    {
        Serial.print("Latitude is ");    
        Serial.print(Lat);  
        Serial.print(" N\n");   
      }
    else if(RecMessage[12] == 'S')
    {
        Serial.print("Latitude is ");    
        Serial.print(Lat);
        Serial.print(" S\n");    
      }
    else
        return false;

    strncpy(LogDD,RecMessage+14,3);
    LogDD[3] = '\0';
//    SIMSerial.print("LogDD:");
//    SIMSerial.print(LogDD);
    
    strncpy(LogMM,RecMessage+17,9);
    LogMM[9] = '\0';
//    SIMSerial.print("LogMM:");
//    SIMSerial.print(LogMM);
    
    Log = atoi(LogDD) + (atof(LogMM)/60);
    if(RecMessage[27] == 'E')
    {
        Serial.print("Longitude is "); 
        Serial.print(Log);
        Serial.print(" E\n");
      }
    else if(RecMessage[27] == 'W')
    {
        Serial.print("Latitude is ");
        Serial.print(Lat);
        Serial.print(" W\n");      
      }
    else
        return false;

    strncpy(DdMmYy,RecMessage+29,6);
    DdMmYy[6] = '\0';
    Serial.print("Day Month Year is ");
    Serial.print(DdMmYy);
    Serial.print("\n");
    
    strncpy(UTCTime,RecMessage+36,6);
    UTCTime[6] = '\0';
    Serial.print("UTC time is ");
    Serial.print(UTCTime);
    Serial.print("\n");
    
    return true;
}

/**************************Other functions**************************/
uint8_t Sim7x00::sendATcommand(const char* ATcommand, const char* expected_answer, unsigned int timeout) {

    uint8_t x=0,  answer=0;
    unsigned long previous;

    memset(response, '\0', 100);    // Initialize the string
    
    delay(100);
    
    while( SIMSerial.available() > 0) SIMSerial.read();    // Clean the input buffer
    
    SIMSerial.println(ATcommand);    // Send the AT command 


    x = 0;
    previous = millis();

    // this loop waits for the answer
    do{
        if(SIMSerial.available() != 0){    
            // if there are data in the UART input buffer, reads it and checks for the asnwer
            response[x] = SIMSerial.read();      
//            SIMSerial.print(response[x]);
            x++;
            // check if the desired answer  is in the response of the module
            if (strstr(response, expected_answer) != NULL)    
            {
                answer = 1;
            }
        }
         // Waits for the asnwer with time out
    }while((answer == 0) && ((millis() - previous) < timeout));
    
//    SIMSerial.print("\n");   

    return answer;
}

char Sim7x00::sendATcommand2(const char* ATcommand, const char* expected_answer1, const char* expected_answer2, unsigned int timeout){
  uint8_t x=0,  answer=0;
    unsigned long previous;

    memset(response, '\0', 100);    // Initialize the string

    delay(100);

    while( SIMSerial.available() > 0) SIMSerial.read();    // Clean the input buffer

    SIMSerial.println(ATcommand);    // Send the AT command 

    x = 0;
    previous = millis();

    // this loop waits for the answer
    do{
        // if there are data in the UART input buffer, reads it and checks for the asnwer
        if(SIMSerial.available() != 0){    
            response[x] = SIMSerial.read();
            SIMSerial.print(response[x]);
            x++;
            // check if the desired answer 1  is in the response of the module
            if (strstr(response, expected_answer1) != NULL)    
            {
                SIMSerial.print("\n");
                answer = 1;
            }
            // check if the desired answer 2 is in the response of the module
            else if (strstr(response, expected_answer2) != NULL)    
            {
                SIMSerial.print("\n");
                answer = 2;
            }
        }
    }
    // Waits for the asnwer with time out
    while((answer == 0) && ((millis() - previous) < timeout));    

    return answer;

}

Sim7x00 sim7600 = Sim7x00();
