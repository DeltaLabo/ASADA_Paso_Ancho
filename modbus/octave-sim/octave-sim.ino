/****** Modbus settings ******/
// 1 to use the RS485 port for Modbus, 0 for Serial1
#define USE_RS485 1
#define SLAVE_ADDRESS 1
#define MODBUS_BAUDRATE 9600

#include "RS485.h"
#include "src/ModbusRTUSlave.h"

// Define the ModbusRTUSlave object, using the RS-485 or Serial1 port
ModbusRTUSlave slave((USE_RS485 == 1) ? RS485 : Serial1, SLAVE_ADDRESS);

/****** Octave memory map ******/
// 0x37 addresses, used for simulating the Alarms, Serial Number and Forward Volume registers on an Octave
const int numRegisters = 0x37;
uint16_t holdingRegisters[numRegisters];
uint16_t inputRegisters[numRegisters];


void setup() {
  // Use Serial0 port for debugging (optional, not implemented)
  //Serial.begin(9600);

  // Start the Modbus serial port
  // SERIAL_8N1: 8 bits, no parity, 1 stop bit
  if (USE_RS485 == 1) RS485.begin(MODBUS_BAUDRATE, HALFDUPLEX, SERIAL_8N1);
  else Serial1.begin(MODBUS_BAUDRATE, SERIAL_8N1);

  // Init ModbusRTUSlave object
  slave.begin(MODBUS_BAUDRATE);

  /****** Initialize memory map ******/
  // Alarms, random value
  // 0x85 = 133
  holdingRegisters[0] = 0x85;
  inputRegisters[0] = 0x85;

  // Serial number, random value
  // 0x0001 0002 0003 ...
  for (int i = 0x1; i <= 0x10; i++){
    holdingRegisters[i] = i;
    inputRegisters[i] = i;
  }

  // Addresses 0x11 to 0x17 are unused in the simulation (not in a real Octave though)
  for (int i = 0x11; i <= 0x17; i++){
    holdingRegisters[i] = 0;
    inputRegisters[i] = 0;
  }

  // Forward volume (uint64), random value
  // 0x0011001100110011 = 4785147619639313
  holdingRegisters[0x18] = 0x11;
  holdingRegisters[0x19] = 0x11;
  holdingRegisters[0x1A] = 0x11;
  holdingRegisters[0x1B] = 0x11;
  inputRegisters[0x19] = 0x11;
  inputRegisters[0x18] = 0x11;
  inputRegisters[0x1A] = 0x11;
  inputRegisters[0x1B] = 0x11;

  // Addresses 0x1C to 0x35 are unused in the simulation (not in a real Octave though)
  for (int i = 0x1C; i <= 0x35; i++){
    holdingRegisters[i] = 0;
    inputRegisters[i] = 0;
  }

  // Forward volume (uint32), random value
  // 0x00210022 = 2162722
  holdingRegisters[0x36] = 0x21;
  holdingRegisters[0x37] = 0x22;
  inputRegisters[0x36] = 0x21;
  inputRegisters[0x37] = 0x22;

  slave.setHoldingRegisters(holdingRegisters, numRegisters);
  slave.setInputRegisters(inputRegisters, numRegisters);
}


void loop() {
  // Process modbus requests
  slave.update();
}