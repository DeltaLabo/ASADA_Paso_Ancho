#include "OctaveModbusWrapper.h"

OctaveModbusWrapper::OctaveModbusWrapper(HardwareSerial &modbusSerial, HardwareSerial &logSerial) : _master(modbusSerial), _logSerial(logSerial) {}

void OctaveModbusWrapper::begin() {
    // Start the modbus _master object
  InitMaps();
	_master.begin(MODBUS_BAUDRATE);
}


/****** Modbus communication functions ******/
// Read the Modbus channel in blocking mode until a response is received or an error occurs
uint8_t OctaveModbusWrapper::AwaitResponse(){
  // While the _master is in receiving mode and the timeout hasn't been reached
  while(_master.isWaitingResponse()){
    // Check available responses
    ModbusResponse response = _master.available();

    // If there was a valid response
    if (response) {
      if (response.hasError()) {
        // Response failure treatment. You can use response.getErrorCode()
        // to get the error code.
        _logSerial.print("Error: ");
        _logSerial.println(response.getErrorCode());
        // Error: Response received, contains Modbus error code
        return response.getErrorCode();
      } else {
        // Get the discrete inputs values from the response
        if (response.hasError()) {
          // Response failure treatment. You can use response.getErrorCode()
          // to get the error code.
          _logSerial.print("Error: ");
          _logSerial.println(response.getErrorCode());
          // Error: Response received, contains Modbus error code
          return response.getErrorCode();
        } else {
          // If there are registers to read, process them
          if(_numRegisterstoRead > 0) {
            // Get error code from called function
            ProcessResponse(&response);
            // Assume no error occurred while processing
            return 0;
          }
          // If there are no registers to read, it was a write request
          else {
            _logSerial.print(functionCodeToName[lastUsedFunctionCode]);
            _logSerial.println(": Done writing.");
            // No error
            return 0;
          }
        }
      }
    }
  }
  // Error code 5: Timeout
  _logSerial.println("Error: Timeout");
  return 5;
}


// Processes the raw register values from the slave response and saves them to the buffers
// Returns void because it shouldn't throw any errors
void OctaveModbusWrapper::ProcessResponse(ModbusResponse *response){
  _logSerial.print(functionCodeToName[lastUsedFunctionCode]);
  _logSerial.print(": ");

  if (_signedResponseSizeinBits == 16){
    // Loop through the response and print each register
    for (int i = 0; i < 16; i++){
      // If the index corresponds to a valid register from the request
      if (i < _numRegisterstoRead) {
        // Save the register to the buffer
        int16Buffer[i] = response->getRegister(i);

        // If there is more than 1 int16 value, it means that we're reading the Serial
        if (_numRegisterstoRead > 1) {
          // Convert the ASCII code to a char
          _logSerial.print(char(int16Buffer[i]));
          // Leave space for the next char
          _logSerial.print(' ');
        }
        // If only 1 int16 was requested
        else {
          _logSerial.print(int16Buffer[i]);
          _logSerial.print(" ");

          // Print value interpretation for the functions that require it
          if (lastUsedFunctionCode == functionNameToCode["VolumeUnit"]){
            _logSerial.print(volumeUnitCodeToName[int16Buffer[i]]);
          }
          else if (lastUsedFunctionCode == functionNameToCode["FlowUnit"]){
            _logSerial.print(flowUnitCodeToName[int16Buffer[i]]);
          }
          else if (lastUsedFunctionCode == functionNameToCode["ReadVolumeResIndex"] || lastUsedFunctionCode == functionNameToCode["ReadFlowResIndex"]){
            _logSerial.print(resolutionCodeToName[int16Buffer[i]]);
          }
          else if (lastUsedFunctionCode == functionNameToCode["TemperatureUnit"]){
            _logSerial.print(temperatureUnitCodeToName[int16Buffer[i]]);
          }
          else if (lastUsedFunctionCode == functionNameToCode["FlowDirection"]){
            _logSerial.print(flowDirectionCodeToName[int16Buffer[i]]);
          }
          else if (lastUsedFunctionCode == functionNameToCode["ReadAlarms"]){
            if (int16Buffer[i] == 0) _logSerial.print("OK");
            else{
              // Bit-wise error check
              for (int j = 0; j < sizeof(alarmsIndices) / sizeof(alarmsIndices[0]); j++) {
                // If the (i+1)-th bit is set, print the corresponding error message
                if ((int16Buffer[i] & (1 << alarmsIndices[j])) != 0) {
                  _logSerial.print(alarmCodeToName[alarmsIndices[j]]);
                  _logSerial.print(" ");
                }
              }
            }
          }
        }
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
      _logSerial.println(fp64_to_string(doubleBuffer, 10, 1)); // char *fp64_to_string(float64_t x, uint8_t max_chars, uint8_t max_zeroes)
    }
  }
  _logSerial.println();
}


// Read one or more Modbus registers in blocking mode
uint8_t OctaveModbusWrapper::BlockingReadRegisters(uint8_t startMemAddress, uint8_t numValues, int8_t signedValueSizeinBits){
  lastUsedFunctionCode = (0x04 << 8) + startMemAddress;

  // Calculate the number of registers from the number of values and their size
  // e.g.: 1 32-bit value occupies 2 registers (2 x 16bit)
  _numRegisterstoRead = numValues * abs(signedValueSizeinBits)/16;
  _signedResponseSizeinBits = signedValueSizeinBits;

  if (!_master.readInputRegisters(SLAVE_ADDRESS, startMemAddress, _numRegisterstoRead)) {
    // Failure treatment
    _logSerial.println("Error: Can't send request. Modbus master is awaiting a response.");
    // Error code 3: Modbus channel busy
    return 3;
  }

  // Get error code from called funcion
  return AwaitResponse();
}


// Write a single Modbus register in blocking mode
uint8_t OctaveModbusWrapper::BlockingWriteSingleRegister(uint8_t memAddress, int16_t value){
  lastUsedFunctionCode = (0x06 << 8) + memAddress;

  // No registers need to be read for a write request
  _numRegisterstoRead = 0;
  _signedResponseSizeinBits = 16;

  if (!_master.writeSingleRegister(SLAVE_ADDRESS, memAddress, value)) {
    // Failure treatment
    _logSerial.println("Error: Can't send request. Modbus master is awaiting a response.");
    // Error code 3: Modbus channel busy
    return 3;
  }
  // Get error code from called funcion
  return AwaitResponse();
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
uint8_t truncateDoubleto16bits(float64_t &input, int16_t &output){
  // Check for overflow or underflow
  // if input > DEC16MAX
  if (fp64_compare(input, fp64_atof(DEC16_MAX)) == 1) {
    // Output the largest possible value to minimize the error
    output = INT16_MAX;
    // Error code 6: 16-bit Overflow
    return 6;
  }
  // if input < DEC16MIN
  else if (fp64_compare(input, fp64_atof(DEC16_MIN)) == -1) {
    // Output the smallest possible value to minimize the error
    output = INT16_MIN;
    // Error code 7: 16-bit Underflow
    return 7;
  }
  else {
    // Scale, then cast to int16
    output = fp64_to_int16(fp64_mul(input, fp64_atof(SCALE_FACTOR)));
    // No error
    return 0;
  }
}

// Truncate 64-bit double to 32 bits
uint8_t truncateDoubleto32bits(float64_t &input, int32_t &output){
  // Check for overflow or underflow
  // if input > DEC32MAX
  if (fp64_compare(input, fp64_atof(DEC32_MAX)) == 1) {
    // Output the largest possible value to minimize the error
    output = INT32_MAX;
    // Error code 8: 32-bit Overflow
    return 8;
  }
  // if input < DEC32MIN
  else if (fp64_compare(input, fp64_atof(DEC32_MIN)) == -1) {
    // Output the smallest possible value to minimize the error
    output = INT32_MIN;
    // Error code 9: 32-bit Underflow
    return 9;
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
          // Output the smallest possible value to minimize the error
          output = INT32_MIN;
          // Error code 9: 32-bit Underflow
          return 9;
        }
      }
      // If the input had a "positive" sign
      else {
        // Output the largest possible value to minimize the error
        output = INT32_MAX;
        // Error code 8: 32-bit Overflow
        return 8;
      }
    }
  }
}


/****** Octave Modbus Requests ******/
uint8_t OctaveModbusWrapper::ReadAlarms() {
  return BlockingReadRegisters(0x0, 1, 16);
}

uint8_t OctaveModbusWrapper::SerialNumber() {
  return BlockingReadRegisters(0x1, 16, 16);
}

uint8_t OctaveModbusWrapper::ReadWeekday() {
  return BlockingReadRegisters(0x11, 1, 16);
}

uint8_t OctaveModbusWrapper::ReadDay() {
  return BlockingReadRegisters(0x12, 1, 16);
}

uint8_t OctaveModbusWrapper::ReadMonth(){
	return BlockingReadRegisters(0x13, 1, 16);
}

uint8_t OctaveModbusWrapper::ReadYear(){
	return BlockingReadRegisters(0x14, 1, 16);
}

uint8_t OctaveModbusWrapper::ReadHours(){
	return BlockingReadRegisters(0x15, 1, 16);
}

uint8_t OctaveModbusWrapper::ReadMinutes(){
	return BlockingReadRegisters(0x16, 1, 16);
}

uint8_t OctaveModbusWrapper::VolumeUnit(){
	return BlockingReadRegisters(0x17, 1, 16);
}

uint8_t OctaveModbusWrapper::ForwardVolume(uint8_t unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    return BlockingReadRegisters(0x36, 1, 32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    return BlockingReadRegisters(0x18, 1, -64);
  }
}

uint8_t OctaveModbusWrapper::ReverseVolume(uint8_t unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    return BlockingReadRegisters(0x3A, 1, 32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    return BlockingReadRegisters(0x20, 1, -64);
  }
}

uint8_t OctaveModbusWrapper::ReadVolumeResIndex(){
	return BlockingReadRegisters(0x28, 1, 16);
}

uint8_t OctaveModbusWrapper::SignedCurrentFlow(uint8_t unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    return BlockingReadRegisters(0x3E, 1, -32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    return BlockingReadRegisters(0x29, 1, -64);
  }
}

uint8_t OctaveModbusWrapper::ReadFlowResIndex(){
	return BlockingReadRegisters(0x31, 1, 16);
}

uint8_t OctaveModbusWrapper::FlowUnit(){
	return BlockingReadRegisters(0x32, 1, 16);
}

uint8_t OctaveModbusWrapper::FlowDirection(){
	return BlockingReadRegisters(0x33, 1, 16);
}

uint8_t OctaveModbusWrapper::TemperatureValue(){
	return BlockingReadRegisters(0x34, 1, 16);
}

uint8_t OctaveModbusWrapper::TemperatureUnit(){
	return BlockingReadRegisters(0x35, 1, 16);
}

uint8_t OctaveModbusWrapper::NetSignedVolume(uint8_t unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    return BlockingReadRegisters(0x52, 1, -32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    return BlockingReadRegisters(0x42, 1, -64);
  }
}

uint8_t OctaveModbusWrapper::NetUnsignedVolume(uint8_t unsignedValueSizeinBits){
  if (unsignedValueSizeinBits == 32) {
    return BlockingReadRegisters(0x56, 1, 32);
  }
  else { // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
    return BlockingReadRegisters(0x4A, 1, -64);
  }
}

uint8_t OctaveModbusWrapper::SystemReset(){
	return BlockingWriteSingleRegister(0x0, 0x1);
}

// value must be within 1 to 7
uint8_t OctaveModbusWrapper::WriteWeekday(uint8_t value){
	return BlockingWriteSingleRegister(0x1, value);
}

// value must be within 1 to 31
uint8_t OctaveModbusWrapper::WriteDay(uint8_t value){
	return BlockingWriteSingleRegister(0x2, value);
}

// value must be within 1 to 12
uint8_t OctaveModbusWrapper::WriteMonth(uint8_t value){
	return BlockingWriteSingleRegister(0x3, value);
}

// value must be within 14 to 99
uint8_t OctaveModbusWrapper::WriteYear(uint8_t value){
	return BlockingWriteSingleRegister(0x4, value);
}

// value must be within 0 to 23
uint8_t OctaveModbusWrapper::WriteHours(uint8_t value){
	return BlockingWriteSingleRegister(0x5, value);
}

// value must be within 0 to 59
uint8_t OctaveModbusWrapper::WriteMinutes(uint8_t value){
	return BlockingWriteSingleRegister(0x6, value);
}

// value must be within 0 to 8, see table
uint8_t OctaveModbusWrapper::WriteVolumeResIndex(uint8_t value){
  if (value > 8) {
    _logSerial.println("Error: Invalid Resolution Index");
    return 10; // Error code 10: Invalid Resolution Index
  }
	return BlockingWriteSingleRegister(0x7, value);
}

// value must be within 0 to 8, see table
uint8_t OctaveModbusWrapper::WriteFlowResIndex(uint8_t value){
  if (value > 8) {
    _logSerial.println("Error: Invalid Resolution Index");
    return 10; // Error code 10: Invalid Resolution Index
  }
	return BlockingWriteSingleRegister(0x8, value);
}