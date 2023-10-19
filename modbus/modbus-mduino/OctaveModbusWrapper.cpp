#include "OctaveModbusWrapper.h"

OctaveModbusWrapper::OctaveModbusWrapper(HardwareSerial &modbusSerial, HardwareSerial &logSerial, bool logtoSerial, bool logtoLoRa) : _master(modbusSerial), _logSerial(logSerial) {
    _logtoSerial = logtoSerial;
    _logtoLoRa = logtoLoRa;
}

void OctaveModbusWrapper::begin() {
    // Start the modbus _master object
	_master.begin(MODBUS_BAUDRATE);
}


/****** Modbus communication functions ******/
// Read the Modbus channel in blocking mode until a response is received or an error occurs
void OctaveModbusWrapper::AwaitResponse(){
  // While the _master is in receiving mode and the timeout hasn't been reached
  while(_master.isWaitingResponse()){
    // Check available responses
    ModbusResponse response = _master.available();

    // If there was a valid response
    if (response) {
      if (response.hasError()) {
        // Response failure treatment. You can use response.getErrorCode()
        // to get the error code.
        _logSerial.print("Error ");
        _logSerial.println(response.getErrorCode());
      } else {
        // Get the discrete inputs values from the response
        if (response.hasError()) {
          // Response failure treatment. You can use response.getErrorCode()
          // to get the error code.
          _logSerial.print("Error ");
          _logSerial.println(response.getErrorCode());
        } else {
          // If there are registers to read, process them
          if(_numRegisterstoRead > 0) {
            ProcessResponse(&response);
          }
          // If there are no registers to read, it was a write request
          else _logSerial.println("Done writing.");
        }
      }
    }
  }
}


// Processes the raw register values from the slave response and saves them to the buffers
void OctaveModbusWrapper::ProcessResponse(ModbusResponse *response){
  _logSerial.println("Register values: ");

  if (_signedResponseSizeinBits == 16){
    // Loop through the response and print each register
    for (int i = 0; i < 16; i++){
      // If the index corresponds to a valid register from the request
      if (i < _numRegisterstoRead) {
        // Save the register to the buffer
        int16Buffer[i] = response->getRegister(i);
        _logSerial.print(response->getRegister(i));
        _logSerial.print(',');
      }
      // Clear the unused buffer positions
      else int16Buffer[i] = 0;
    }
    _logSerial.println();

    // Clear the unused buffers
    int32Buffer = 0;
    uint32Buffer = 0;
    doubleBuffer = 0.0;
  }
  else {
    // Clear the entire int16 buffer
    for (int i = 0; i < 16; i++){
      int16Buffer[i] = 0;
    }

    if (_signedResponseSizeinBits == 32){
      // The value is split into AB CD, combine it into ABCD and save it to the buffer
      uint32Buffer = (static_cast<unsigned long>(response->getRegister(0)) << 16) + static_cast<unsigned long>(response->getRegister(1));
      _logSerial.println(uint32Buffer);

      // Clear the unused buffers
      int32Buffer = 0;
      doubleBuffer = 0.0;
    }
    else if (_signedResponseSizeinBits == -32){
      // The value is split into AB CD, combine it into ABCD and save it to the buffer
      int32Buffer = (static_cast<unsigned long>(response->getRegister(0)) << 16) + static_cast<unsigned long>(response->getRegister(1));
      _logSerial.println(int32Buffer);

      // Clear the unused buffers
      uint32Buffer = 0;
      doubleBuffer = 0.0;
    }
    else { // _signedResponseSizeinBits == -64

      // Clear the unused buffers
      int32Buffer = 0;
      uint32Buffer = 0;

      // The value is stored in HG FE DC BA order, rearrange it to ABCDEFGH and save it to the buffer
      doubleBuffer = (static_cast<unsigned long long>(((response->getRegister(3) >> 8) | (response->getRegister(3) << 8))) << 48)
              + (static_cast<unsigned long long>(( (response->getRegister(2) >> 8) | (response->getRegister(2) << 8))) << 32)
              + (static_cast<unsigned long long>(( (response->getRegister(1) >> 8) | (response->getRegister(1) << 8))) << 16)
              + ((response->getRegister(0) >> 8) | (response->getRegister(0) << 8));

      // Convert the 64-bit floating point number to a string, then print it
      _logSerial.print("double: ");
      _logSerial.println(fp64_to_string(doubleBuffer, 10, 1)); // char *fp64_to_string(float64_t x, uint8_t max_chars, uint8_t max_zeroes)
    }
  }
  _logSerial.println();
}


// Read one or more Modbus registers in blocking mode
void OctaveModbusWrapper::BlockingReadRegisters(int startMemAddress, int numValues, int signedValueSizeinBits){
  // Calculate the number of registers from the number of values and their size
  // e.g.: 1 32-bit value occupies 2 registers (2 x 16bit)
  _numRegisterstoRead = numValues * abs(signedValueSizeinBits)/16;
  _signedResponseSizeinBits = signedValueSizeinBits;

  if (!_master.readInputRegisters(SLAVE_ADDRESS, startMemAddress, _numRegisterstoRead)) {
    // Failure treatment
    _logSerial.println("Can't send request. Modbus _master is awaiting a response.");
  }

  AwaitResponse();
}


// Write a single Modbus register in blocking mode
void OctaveModbusWrapper::BlockingWriteSingleRegister(int memAddress, int value){
  // No registers need to be read for a write request
  _numRegisterstoRead = 0;
  _signedResponseSizeinBits = 16;

  if (!_master.writeSingleRegister(SLAVE_ADDRESS, memAddress, value)) {
    // Failure treatment
    _logSerial.println("Can't send request. Modbus _master is awaiting a response.");
  }

  AwaitResponse();
}


/****** Utilities ******/

// Convert uint64 to str to make it _logSerial-printable
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

// Convert int64 to str to make it _logSerial-printable
char* str( int64_t num ) {
    if ( num>=0 ) return str((uint64_t)num);
    char* p = str((uint64_t)(-num));
    *--p = '-';
    return p;    
}

// Truncate 64-bit double to 16 bits
int truncateDoubleto16bits(float64_t input, int16_t &output){
  // Check for overflow or underflow
  // if input > DEC16MAX
  if (fp64_compare(input, fp64_atof(DEC16_MAX)) == 1) {
    // Output the largest possible value to minimize the error
    output = INT16_MAX;
    // Error code 1: Overflow
    return 1;
  }
  // if input < DEC16MIN
  else if (fp64_compare(input, fp64_atof(DEC16_MIN)) == -1) {
    // Output the smallest possible value to minimize the error
    output = INT16_MIN;
    // Error code 2: Underflow
    return 2;
  }
  else {
    // Scale, then cast to int16
    output = fp64_to_int16(fp64_mul(input, fp64_atof(SCALE_FACTOR)));
    // No error
    return 0;
  }
}

// Truncate 64-bit double to 32 bits
int truncateDoubleto32bits(float64_t input, int32_t &output){
  // Check for overflow or underflow
  // if input > DEC32MAX
  if (fp64_compare(input, fp64_atof(DEC32_MAX)) == 1) {
    // Output the largest possible value to minimize the error
    output = INT32_MAX;
    // Error code 1: Overflow
    return 1;
  }
  // if input < DEC32MIN
  else if (fp64_compare(input, fp64_atof(DEC32_MIN)) == -1) {
    // Output the smallest possible value to minimize the error
    output = INT32_MIN;
    // Error code 2: Underflow
    return 2;
  }
  else {
    // Scale, then cast to int16
    output = fp64_to_int32(fp64_mul(input, fp64_atof(SCALE_FACTOR)));

    // Re-check for over/underflow in the sign bit, since fp64_compare doesn't work properly with
    // numbers slightly greater/smaller than DEC32_MAX/MIN

    // If the signs match
    if (fp64_signbit(output) == fp64_signbit(input)){
      // No error
      return 0;
    }

    // If the signs don't match, there was an error
    else {
      // If the input had a negative sign
      if (fp64_signbit(input) != 0){
        // If the input was -0.0, special case
        if (fp64_compare(fp64_abs(input), fp64_atof("0.0")) == 0) {
          // Remove the sign, the truncation is then complete
          output = fp64_atof("0.0");
          // No error
          return 0;
        }
        // If the input was a negative number
        else {
          // Output the largest possible value to minimize the error
          output = INT32_MIN;
          // Error code 2: Underflow
          return 2;
        }
      }
      // If the input had a "positive" sign
      else {
        // Output the largest possible value to minimize the error
        output = INT32_MAX;
        // Error code 1: Overflow
        return 1;
      }
    }
  }
}


/****** Octave Modbus Requests ******/
void OctaveModbusWrapper::ReadAlarms() {
  BlockingReadRegisters(0x0, 1, 16);
}

void OctaveModbusWrapper::SerialNumber() {
  BlockingReadRegisters(0x1, 16, 16);
}

void OctaveModbusWrapper::ReadWeekday() {
  BlockingReadRegisters(0x11, 1, 16);
}

void OctaveModbusWrapper::ReadDay() {
  BlockingReadRegisters(0x12, 1, 16);
}

void OctaveModbusWrapper::ReadMonth(){
	BlockingReadRegisters(0x13, 1, 16);
}

void OctaveModbusWrapper::ReadYear(){
	BlockingReadRegisters(0x14, 1, 16);
}

void OctaveModbusWrapper::ReadHours(){
	BlockingReadRegisters(0x15, 1, 16);
}

void OctaveModbusWrapper::ReadMinutes(){
	BlockingReadRegisters(0x16, 1, 16);
}

void OctaveModbusWrapper::VolumeUnit(){
	BlockingReadRegisters(0x17, 1, 16);
}

void OctaveModbusWrapper::ForwardVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x36, 1, 32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    BlockingReadRegisters(0x18, 1, -64);
  }
}

void OctaveModbusWrapper::ReverseVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x3A, 1, 32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    BlockingReadRegisters(0x20, 1, -64);
  }
}

void OctaveModbusWrapper::ReadVolumeResIndex(){
	BlockingReadRegisters(0x28, 1, 16);
}

void OctaveModbusWrapper::SignedCurrentFlow(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x3E, 1, -32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    BlockingReadRegisters(0x29, 1, -64);
  }
}

void OctaveModbusWrapper::ReadFlowResIndex(){
	BlockingReadRegisters(0x31, 1, 16);
}

void OctaveModbusWrapper::FlowUnits(){
	BlockingReadRegisters(0x32, 1, 16);
}

void OctaveModbusWrapper::FlowDirection(){
	BlockingReadRegisters(0x33, 1, 16);
}

void OctaveModbusWrapper::TemperatureValue(){
	BlockingReadRegisters(0x34, 1, 16);
}

void OctaveModbusWrapper::TemperatureUnit(){
	BlockingReadRegisters(0x35, 1, 16);
}

void OctaveModbusWrapper::NetSignedVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x52, 1, -32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    BlockingReadRegisters(0x42, 1, -64);
  }
}

void OctaveModbusWrapper::NetUnsignedVolume(int unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    BlockingReadRegisters(0x56, 1, 32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    BlockingReadRegisters(0x4A, 1, -64);
  }
}

void OctaveModbusWrapper::SystemReset(){
	BlockingWriteSingleRegister(0x0, 0x1);
}

void OctaveModbusWrapper::WriteAlarms(int value){
	BlockingWriteSingleRegister(0x0, value);
}

void OctaveModbusWrapper::WriteWeekday(int value){
	BlockingWriteSingleRegister(0x1, value);
}

void OctaveModbusWrapper::WriteDay(int value){
	BlockingWriteSingleRegister(0x2, value);
}

void OctaveModbusWrapper::WriteMonth(int value){
	BlockingWriteSingleRegister(0x3, value);
}

void OctaveModbusWrapper::WriteYear(int value){
	BlockingWriteSingleRegister(0x4, value);
}

void OctaveModbusWrapper::WriteHours(int value){
	BlockingWriteSingleRegister(0x5, value);
}

void OctaveModbusWrapper::WriteMinutes(int value){
	BlockingWriteSingleRegister(0x6, value);
}

void OctaveModbusWrapper::WriteVolumeResIndex(int value){
	BlockingWriteSingleRegister(0x7, value);
}

void OctaveModbusWrapper::WriteVolumeFlowIndex(int value){
	BlockingWriteSingleRegister(0x8, value);
}