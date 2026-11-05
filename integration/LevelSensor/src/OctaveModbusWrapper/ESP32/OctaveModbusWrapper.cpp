#include "OctaveModbusWrapper.h"

// Initialize Serial interface used for Modbus communication
OctaveModbusWrapper::OctaveModbusWrapper(HardwareSerial &modbusSerial) : _master(modbusSerial){}


void OctaveModbusWrapper::begin(uint32_t baudrate) {
  // Initialize name-to-code and code-to-name mappings to interpret readings
  InitMaps();
  // Start the modbus _master object
	_master.begin(baudrate);
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
        // Error: Response received, contains Modbus error code
        return response.getErrorCode();
      } else {
        if (response.hasError()) {
          // Error: Response received, contains Modbus error code
          return response.getErrorCode();
        } else {
          // If there are registers to read, process them
          if(_numRegisterstoRead > 0) {
            ProcessResponse(&response);
            // Assume no error occurred while processing
            return 0;
          }
          // If there are no registers to read, it was a write request
          else {
            // No error
            return 0;
          }
        }
      }
    }
  }
  // Error code 5: Timeout
  return 5;
}


// Processes the raw register values from the slave response and saves them to the buffers
// Returns void because it shouldn't throw any errors
void OctaveModbusWrapper::ProcessResponse(ModbusResponse *response){
  if (_signedResponseSizeinBits == 16){
    // Loop through the response
    for (int i = 0; i < 16; i++){
      // If the index corresponds to a valid register from the request
      if (i < _numRegisterstoRead) {
        // Save the register to the buffer
        int16Buffer[i] = response->getRegister(i);
      }
      // Clear the unused buffer positions
      else int16Buffer[i] = 0;
    }

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
      // 32 bit values are split into AB CD bytes, according to the memory map
      // Combine them into ABCD and save them to the buffer
      uint32Buffer = (static_cast<unsigned long>(response->getRegister(0)) << 16) + static_cast<unsigned long>(response->getRegister(1));

      // Clear the unused buffers
      int32Buffer = 0;
      doubleBuffer = 0.0;
    }
    else if (_signedResponseSizeinBits == -32){
      // 32 bit values are split into AB CD bytes, according to the memory map
      // Combine them into ABCD and save them to the buffer
      int32Buffer = (static_cast<unsigned long>(response->getRegister(0)) << 16) + static_cast<unsigned long>(response->getRegister(1));

      // Clear the unused buffers
      uint32Buffer = 0;
      doubleBuffer = 0.0;
    }
    else { // _signedResponseSizeinBits == -64

      // Clear the unused buffers
      int32Buffer = 0;
      uint32Buffer = 0;

      uint64_t auxDoubleBuffer = 0;

      // 64 bit values are split into HG FE DC BA bytes, according to the memory map
      // Combine them into ABCDEFGH and save them to the buffer
      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(3) >> 8) << 48; // H
      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(3) & 0xFF) << 56; // G

      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(2) >> 8) << 32; // F
      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(2) & 0xFF) << 40; // E

      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(1) >> 8) << 16; // D
      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(1) & 0xFF) << 24; // C

      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(0) >> 8);  // B
      auxDoubleBuffer |= static_cast<uint64_t>(response->getRegister(0) & 0xFF) << 8;  // A

      doubleBuffer = *reinterpret_cast<double*>(&auxDoubleBuffer);
    }
  }
}


// Read one or more Modbus registers in blocking mode
uint8_t OctaveModbusWrapper::BlockingReadRegisters(uint8_t startMemAddress, uint8_t numValues, int8_t signedValueSizeinBits){
  lastUsedFunctionCode = (0x04 << 8) + startMemAddress;

  // Calculate the number of registers from the number of values and their size
  // e.g.: 1 32-bit value occupies 2 registers (2 x 16bit)
  _numRegisterstoRead = numValues * abs(signedValueSizeinBits)/16;
  _signedResponseSizeinBits = signedValueSizeinBits;

  if (!_master.readInputRegisters(MODBUS_SLAVE_ADDRESS, startMemAddress, _numRegisterstoRead)) {
    // Error code 3: Modbus channel busy
    _lastModbusErrorCode = 3;
    return 3;
  }

  // Get error code from called funcion
  _lastModbusErrorCode = AwaitResponse();
  return _lastModbusErrorCode;
}


// Write a single Modbus register in blocking mode
uint8_t OctaveModbusWrapper::BlockingWriteSingleRegister(uint8_t memAddress, int16_t value){
  lastUsedFunctionCode = (0x06 << 8) + memAddress;

  // No registers need to be read for a write request
  _numRegisterstoRead = 0;
  _signedResponseSizeinBits = 16;

  if (!_master.writeSingleRegister(MODBUS_SLAVE_ADDRESS, memAddress, value)) {
    // Error code 3: Modbus channel busy
    _lastModbusErrorCode = 3;
    return 3;
  }
  // Get error code from called funcion
  _lastModbusErrorCode = AwaitResponse();
  return _lastModbusErrorCode;
}


/******* Utilities ********/

// Truncate 64-bit double to 16 bits
uint8_t truncateDoubleto16bits(double &input, int16_t &output){
  // Check for overflow or underflow
  // if input > DEC16MAX
  if (input > strtod(DEC16_MAX, nullptr)) {
    // Output the largest possible value to minimize the error
    output = INT16_MAX;
    // Error code 6: 16-bit Overflow
    return 6;
  }
  // if input < DEC16MIN
  else if (input < strtod(DEC16_MIN, nullptr)) {
    // Output the smallest possible value to minimize the error
    output = INT16_MIN;
    // Error code 7: 16-bit Underflow
    return 7;
  }
  // If there were no Overflow or Underflow errors
  else {
    // Scale, then cast to int16
    output = static_cast<int16_t>(input * strtod(SCALE_FACTOR, nullptr));
    // No error
    return 0;
  }
}

// Truncate 64-bit double to 32 bits
uint8_t truncateDoubleto32bits(double &input, int32_t &output){
  // Check for overflow or underflow
  // if input > DEC32MAX
  if (input > strtod(DEC32_MAX, nullptr)) {
    // Output the largest possible value to minimize the error
    output = INT32_MAX;
    // Error code 8: 32-bit Overflow
    return 8;
  }
  // if input < DEC32MIN
  else if (input < strtod(DEC32_MIN, nullptr)) {
    // Output the smallest possible value to minimize the error
    output = INT32_MIN;
    // Error code 9: 32-bit Underflow
    return 9;
  }
  // If there were no Overflow or Underflow errors
  else {
    // Scale, then cast to int16
    output = static_cast<int32_t>(input * strtod(SCALE_FACTOR, nullptr));

    // Re-check for over/underflow in the sign bit, since fp64_compare doesn't work properly with
    // numbers slightly greater/smaller than DEC32_MAX/MIN

    // If the signs match
    if ((output > 0 && input > 0) || (output < 0 && input < 0) || (output == input)){
      // No error
      return 0;
    }

    // If the signs don't match, there was an error
    else {
      // If the input had a negative sign
      if (input < 0){
        // If the input was -0.0, special case
        if (std::abs(input) == 0.0) {
          // Remove the sign, the truncation is then complete
          output = 0.0;
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
// Parameter format: start address in the Modbus memory map, number of values to request, signed value size in bits
uint8_t OctaveModbusWrapper::ReadAlarms(int16_t* output) {
  uint8_t result = BlockingReadRegisters(0x0, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::SerialNumber(int16_t* output) {
  uint8_t result = BlockingReadRegisters(0x1, 16, 16);
  memcpy(output, int16Buffer, 16 * sizeof(int16_t));
  return result;
}

uint8_t OctaveModbusWrapper::ReadWeekday(int16_t* output) {
  uint8_t result = BlockingReadRegisters(0x11, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::ReadDay(int16_t* output) {
  uint8_t result = BlockingReadRegisters(0x12, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::ReadMonth(int16_t* output) {
	uint8_t result = BlockingReadRegisters(0x13, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::ReadYear(int16_t* output) {
	uint8_t result = BlockingReadRegisters(0x14, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::ReadHours(int16_t* output) {
	uint8_t result = BlockingReadRegisters(0x15, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::ReadMinutes(int16_t* output) {
	uint8_t result = BlockingReadRegisters(0x16, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::VolumeUnit(int16_t* output) {
	uint8_t result = BlockingReadRegisters(0x17, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::ForwardVolume_uint32(uint32_t* output){
  uint8_t result = BlockingReadRegisters(0x36, 1, 32);
  *output = uint32Buffer;
  return result;
}

uint8_t OctaveModbusWrapper::ForwardVolume_double(double* output){
  // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
  uint8_t result = BlockingReadRegisters(0x18, 1, -64);
  *output = doubleBuffer;
  return result;
}

uint8_t OctaveModbusWrapper::ReverseVolume_uint32(uint32_t* output){
  uint8_t result = BlockingReadRegisters(0x3A, 1, 32);
  *output = uint32Buffer;
  return result;
}

uint8_t OctaveModbusWrapper::ReverseVolume_double(double* output){
  // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
  uint8_t result = BlockingReadRegisters(0x20, 1, -64);
  *output = doubleBuffer;
  return result;
}


uint8_t OctaveModbusWrapper::ReadVolumeResIndex(int16_t* output){
	uint8_t result = BlockingReadRegisters(0x28, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::SignedCurrentFlow_int32(int32_t* output){
  uint8_t result = BlockingReadRegisters(0x3E, 1, -32);
  *output = int32Buffer;
  return result;
}

uint8_t OctaveModbusWrapper::SignedCurrentFlow_double(double* output){
  // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
  uint8_t result = BlockingReadRegisters(0x29, 1, -64);
  *output = doubleBuffer;
  return result;
}

uint8_t OctaveModbusWrapper::ReadFlowResIndex(int16_t* output){
	uint8_t result = BlockingReadRegisters(0x31, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::FlowUnit(int16_t* output){
	uint8_t result = BlockingReadRegisters(0x32, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::FlowDirection(int16_t* output){
	uint8_t result = BlockingReadRegisters(0x33, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::TemperatureValue(int16_t* output){
	uint8_t result = BlockingReadRegisters(0x34, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::TemperatureUnit(int16_t* output){
	uint8_t result = BlockingReadRegisters(0x35, 1, 16);
  *output = int16Buffer[0];
  return result;
}

uint8_t OctaveModbusWrapper::NetSignedVolume_int32(int32_t* output){
  uint8_t result = BlockingReadRegisters(0x52, 1, -32);
  *output = int32Buffer;
  return result;
}

uint8_t OctaveModbusWrapper::NetSignedVolume_double(double* output){
  // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
  uint8_t result = BlockingReadRegisters(0x42, 1, -64);
  *output = doubleBuffer;
  return result;
}

uint8_t OctaveModbusWrapper::NetUnsignedVolume_uint32(uint32_t* output){
  uint8_t result = BlockingReadRegisters(0x56, 1, 32);
  *output = uint32Buffer;
  return result;
}

uint8_t OctaveModbusWrapper::NetUnsignedVolume_double(double* output){
  // unsignedValueSizeinBits == -64, all 64-bit (double) values are signed
  uint8_t result = BlockingReadRegisters(0x4A, 1, -64);
  *output = doubleBuffer;
  return result;
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
    return 10; // Error code 10: Invalid Resolution Index
  }
	return BlockingWriteSingleRegister(0x7, value);
}

// value must be within 0 to 8, see table
uint8_t OctaveModbusWrapper::WriteFlowResIndex(uint8_t value){
  if (value > 8) {
    return 10; // Error code 10: Invalid Resolution Index
  }
	return BlockingWriteSingleRegister(0x8, value);
}