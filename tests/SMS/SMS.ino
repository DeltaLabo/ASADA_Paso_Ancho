/**
*  @filename   :   SMS.cpp
*  @brief      :   SIM7600CE 4G HAT demo
*  @author     :   Kaloha from Waveshare
*
*  Copyright (C) Waveshare     April 27 2018
*  http://www.waveshare.com / http://www.waveshare.net
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

#define LTE_TX_PIN D4
#define LTE_RX_PIN D5

HardwareSerial HwSerial(0);

char phone_number[] = "+50670077708";      //********** change it to the phone number you want to call
char text_message[] = "Laboratorio Delta le informa: Gracias por ser un ejemplo de que significa ser una persona increíble";      //

void setup() {
  delay(25000);

  HwSerial.begin(115200, SERIAL_8N1, LTE_RX_PIN, LTE_TX_PIN);
  Serial.begin(9600); // For logging

  Serial.println("Sending Short Message Test.");

  sim7600.PowerOn();
  sim7600.SendingShortMessage(phone_number,text_message);
}


void loop() {

}

