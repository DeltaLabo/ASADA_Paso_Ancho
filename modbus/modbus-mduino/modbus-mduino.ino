/****** Modbus settings ******/
// 1 to use the RS485 port for Modbus, 0 for Serial1
#define USE_RS485 1
#define SLAVE_ADDRESS 1
// 1 to read from Input Registers, 0 to read from Holding Regs
#define READ_FROM_IREGS 0
#define MODBUS_BAUDRATE 9600
// Frequency for sending Modbus requests to the slave
#define POLLING_FREQ_MS 1000 // ms

#include "RS485.h"
#include "src/ModbusRTUMaster.h"
#include <fp64lib.h>
#include <stdint.h>

// Define the ModbusRTUMaster object, using the RS-485 port
ModbusRTUMaster master(RS485);

/****** Parameters for the Modbus requests ******/
// Number of registers to read for a Modbus request, is 0 for a write request
int numRegisterstoRead = 0;
// Size, in bits, of the slave response values, is -32 for int32 and 32 for uint32
int signedResponseSizeinBits = 16;

/****** Modbus response buffers ******/
int int16Buffer[16];
int32_t int32Buffer;
uint32_t uint32Buffer;
int64_t int64Buffer;
uint64_t uint64Buffer;
float64_t doubleBuffer;

// Control variable for the Modbus polling frequency
uint32_t lastSentTime = 0UL;


void setup() {
  // Set indicator LED pin as output
  // This LED toggles with the same frequency as the Modbus polling, for verification purposes
  pinMode(40, OUTPUT);
  // Initialize the indicator LED's state
  digitalWrite(40, LOW);

  // Use Serial0 port for debugging and printing the slave readings
  Serial.begin(9600);

  // Start the Modbus serial port
  // SERIAL_8N1: 8 bits, no parity, 1 stop bit
  RS485.begin(MODBUS_BAUDRATE, HALFDUPLEX, SERIAL_8N1);

  // Start the modbus master object
  master.begin(MODBUS_BAUDRATE);

  // Wait 500ms for Modbus startup
  delay(500);

  /****** Add Modbus requests to send once ******/
}


void loop() {
  // Check available responses often
  if (master.isWaitingResponse()) {
    ModbusResponse response = master.available();

    if (response) {
      if (response.hasError()) {
        // Response failure treatment. You can use response.getErrorCode()
        // to get the error code.
        Serial.print("Error ");
        Serial.println(response.getErrorCode());
      } else {
        // Get the discrete inputs values from the response
        if (response.hasError()) {
          // Response failure treatment. You can use response.getErrorCode()
          // to get the error code.
          Serial.print("Error ");
          Serial.println(response.getErrorCode());
        } else {
          // If there are registers to read, process them
          if(numRegisterstoRead > 0) {
            ProcessResponse(&response);
          }
          // If there are no registers to read, it was a write request
          else Serial.println("Done writing.");
        }
      }
    }
  }
  // Send requests at a certain frequency
  else if (millis() - lastSentTime >= POLLING_FREQ_MS) {
    // Update the control variable
    lastSentTime = millis();
    // Toggle the indicator LED at the Modbus polling frequency, for verification purposes 
    digitalWrite(40, !digitalRead(40));

    /****** Add Modbus requests to send at the polling frequency ******/
  }
}


/****** Modbus communication functions ******/
// Read the Modbus channel in blocking mode until a response is received or an error occurs
void AwaitResponse(){
  while(!master.isWaitingResponse()){
    // Wait until the master enters receiving mode
  }

  // Check available responses
  ModbusResponse response = master.available();

  // If there was a valid response
  if (response) {
    if (response.hasError()) {
      // Response failure treatment.
      Serial.print("Error ");
      Serial.println(response.getErrorCode());
    } else {
      // Get the values from the response
      if (response.hasError()) {
        // Response failure treatment.
        Serial.print("Error ");
        Serial.println(response.getErrorCode());
      } else {
        // If there are registers to read, process them
        if(numRegisterstoRead > 0) {
          ProcessResponse(&response);
        }
        // If there are no registers to read, it was a write request
        else Serial.println("Done writing.");
      }
    }
  }
}


// Processes the raw register values from the slave response and saves them to the buffers
void ProcessResponse(ModbusResponse *response){
  Serial.println("Register values: ");

  if (signedResponseSizeinBits == 16){
    // Loop through the response and print each register
    for (int i = 0; i < 16; i++){
      // If the index corresponds to a valid register from the request
      if (i < numRegisterstoRead) {
        // Save the register to the buffer
        int16Buffer[i] = response->getRegister(i);
        Serial.print(response->getRegister(i));
        Serial.print(',');
      }
      // Clear the unused buffer positions
      else int16Buffer[i] = 0;
    }
    Serial.println();

    // Clear the unused buffers
    int32Buffer = 0;
    uint32Buffer = 0;
    int64Buffer = 0;
    uint64Buffer = 0;
    doubleBuffer = 0.0;
  }
  else {
    // Clear the entire int16 buffer
    for (int i = 0; i < 16; i++){
      int16Buffer[i] = 0;
    }

    if (signedResponseSizeinBits == 32){
      // The value is split into AB CD, combine it into ABCD and save it to the buffer
      uint32Buffer = (static_cast<unsigned long>(response->getRegister(0)) << 16) + static_cast<unsigned long>(response->getRegister(1));
      Serial.println(uint32Buffer);

      // Clear the unused buffers
      int32Buffer = 0;
      int64Buffer = 0;
      uint64Buffer = 0;
      doubleBuffer = 0.0;
    }
    else if (signedResponseSizeinBits == -32){
      // The value is split into AB CD, combine it into ABCD and save it to the buffer
      int32Buffer = (static_cast<unsigned long>(response->getRegister(0)) << 16) + static_cast<unsigned long>(response->getRegister(1));
      Serial.println(int32Buffer);

      // Clear the unused buffers
      uint32Buffer = 0;
      int64Buffer = 0;
      uint64Buffer = 0;
      doubleBuffer = 0.0;
    }
    else { // signedResponseSizeinBits == +-64
      // It is unclear whether the 64-bit have to be interpreted as uint64, int64 or double, so calculate all three

      // Clear the unused buffers
      int32Buffer = 0;
      uint32Buffer = 0;

      doubleBuffer = (static_cast<unsigned long long>(((response->getRegister(3) >> 8) | (response->getRegister(3) << 8))) << 48)
              + (static_cast<unsigned long long>(( (response->getRegister(2) >> 8) | (response->getRegister(2) << 8))) << 32)
              + (static_cast<unsigned long long>(( (response->getRegister(1) >> 8) | (response->getRegister(1) << 8))) << 16)
              + ((response->getRegister(0) >> 8) | (response->getRegister(0) << 8));

      // Convert the 64-bit floating point number to a string, then print it
      Serial.print("double: ");
      Serial.println(fp64_to_string(doubleBuffer, 10, 1));

      // The value is stored in HG FE DC BA order, rearrange it to ABCDEFGH and save it to the buffer
      uint64Buffer = (static_cast<unsigned long long>(((response->getRegister(3) >> 8) | (response->getRegister(3) << 8))) << 48)
                    + (static_cast<unsigned long long>(( (response->getRegister(2) >> 8) | (response->getRegister(2) << 8))) << 32)
                    + (static_cast<unsigned long long>(( (response->getRegister(1) >> 8) | (response->getRegister(1) << 8))) << 16)
                    + ((response->getRegister(0) >> 8) | (response->getRegister(0) << 8));


      Serial.print("uint64: ");
      Serial.println(str(uint64Buffer));

      // The value is stored in HG FE DC BA order, rearrange it to ABCDEFGH and save it to the buffer
      int64Buffer = (static_cast<unsigned long long>(((response->getRegister(3) >> 8) | (response->getRegister(3) << 8))) << 48)
                    + (static_cast<unsigned long long>(( (response->getRegister(2) >> 8) | (response->getRegister(2) << 8))) << 32)
                    + (static_cast<unsigned long long>(( (response->getRegister(1) >> 8) | (response->getRegister(1) << 8))) << 16)
                    + ((response->getRegister(0) >> 8) | (response->getRegister(0) << 8));

      Serial.print("int64: ");
      Serial.println(str(int64Buffer));
    }
  }
  Serial.println();
}


// Read one or more Modbus registers in blocking mode
void BlockingReadRegisters(int startMemAddress, int numValues, int signedValueSizeinBits){
  // Calculate the number of registers from the number of values and their size
  // e.g.: 1 32-bit value occupies 2 registers (2 x 16bit)
  numRegisterstoRead = numValues * abs(signedValueSizeinBits)/16;
  signedResponseSizeinBits = signedValueSizeinBits;

  if (READ_FROM_IREGS == 0) {
    if (!master.readHoldingRegisters(SLAVE_ADDRESS, startMemAddress, numRegisterstoRead)) {
      // Failure treatment
      Serial.println("Can't send request. Modbus master is awaiting a response.");
    }
  }
  else { // READ_FROM_IREGS == 1
    if (!master.readInputRegisters(SLAVE_ADDRESS, startMemAddress, numRegisterstoRead)) {
      // Failure treatment
      Serial.println("Can't send request. Modbus master is awaiting a response.");
    }
  }
  //AwaitResponse();
}


// Write a single Modbus register in blocking mode
void BlockingWriteSingleRegister(int memAddress, int value){
  // No registers need to be read for a write request
  numRegisterstoRead = 0;
  signedResponseSizeinBits = 16;

  if (!master.writeSingleRegister(SLAVE_ADDRESS, memAddress, value)) {
    // Failure treatment
    Serial.println("Can't send request. Modbus master is awaiting a response.");
  }
  //AwaitResponse();
}



/****** Utilities ******/

// Convert uint64 to str to make it Serial-printable
char* str( uint64_t num ) {
  static char buf[22];
  char* p = &buf[sizeof(buf)-1];
  *p = '\0';
  do {
    *--p = '0' + (num%10);
    num /= 10;
  } while ( num > 0 );
  return p;
}

// Convert int64 to str to make it Serial-printable
char* str( int64_t num ) {
    if ( num>=0 ) return str((uint64_t)num);
    char* p = str((uint64_t)(-num));
    *--p = '-';
    return p;    
}


/****** Octave Modbus Wrapper ******/
void ReadAlarms() {
  BlockingReadRegisters(0x0, 1, 16);
}

void SerialNumber() {
  BlockingReadRegisters(0x1, 16, 16);
}

void ReadWeekday() {
  BlockingReadRegisters(0x11, 1, 16);
}

void ReadDay() {
  BlockingReadRegisters(0x12, 1, 16);
}

void ReadMonth(){
	BlockingReadRegisters(0x13, 1, 16);
}

void ReadYear(){
	BlockingReadRegisters(0x14, 1, 16);
}

void ReadHours(){
	BlockingReadRegisters(0x15, 1, 16);
}

void ReadMinutes(){
	BlockingReadRegisters(0x16, 1, 16);
}

void VolumeUnit(){
	BlockingReadRegisters(0x17, 1, 16);
}

void ForwardVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x36, 1, 32);
  }
  else { // unsignedValueSizeinBits == 64
    BlockingReadRegisters(0x18, 1, 64);
  }
}

void ReverseVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x3A, 1, 32);
  }
  else { // unsignedValueSizeinBits == 64
    BlockingReadRegisters(0x20, 1, 64);
  }
}

void ReadVolumeResIndex(){
	BlockingReadRegisters(0x28, 1, 16);
}

void SignedCurrentFlow(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x3E, 1, -32);
  }
  else { // unsignedValueSizeinBits == 64
    BlockingReadRegisters(0x29, 1, -64);
  }
}

void ReadFlowResIndex(){
	BlockingReadRegisters(0x31, 1, 16);
}

void FlowUnits(){
	BlockingReadRegisters(0x32, 1, 16);
}

void FlowDirection(){
	BlockingReadRegisters(0x33, 1, 16);
}

void TemperatureValue(){
	BlockingReadRegisters(0x34, 1, 16);
}

void TemperatureUnit(){
	BlockingReadRegisters(0x35, 1, 16);
}

void NetSignedVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x52, 1, -32);
  }
  else { // unsignedValueSizeinBits == 64
    BlockingReadRegisters(0x42, 1, -64);
  }
}

void NetUnsignedVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x56, 1, 32);
  }
  else { // unsignedValueSizeinBits == 64
    BlockingReadRegisters(0x4A, 1, 64);
  }
}

void WriteAlarms(int value){
	BlockingWriteSingleRegister(0x0, value);
}

void WriteWeekday(int value){
	BlockingWriteSingleRegister(0x1, value);
}

void WriteDay(int value){
	BlockingWriteSingleRegister(0x2, value);
}

void WriteMonth(int value){
	BlockingWriteSingleRegister(0x3, value);
}

void WriteYear(int value){
	BlockingWriteSingleRegister(0x4, value);
}

void WriteHours(int value){
	BlockingWriteSingleRegister(0x5, value);
}

void WriteMinutes(int value){
	BlockingWriteSingleRegister(0x6, value);
}

void WriteVolumeResIndex(int value){
	BlockingWriteSingleRegister(0x7, value);
}

void WriteVolumeFlowIndex(int value){
	BlockingWriteSingleRegister(0x8, value);
}