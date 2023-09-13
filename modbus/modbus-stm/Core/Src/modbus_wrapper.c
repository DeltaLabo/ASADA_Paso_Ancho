#include "stdint.h"
#include "stm32wlxx_hal.h"
#include "modbus_wrapper.h"
#include "modbus_crc.h"
#include <stdlib.h>

/****** Modbus communication functions ******/
// Read one or more holding or input registers via Modbus
void ReadNRegs(struct ModbusHandler *handler, UART_HandleTypeDef *modbus_uart, int numRegisterstoRead, int signedValueSizeinBits){
    // Create Modbus PDU
	handler->TxData[0] = SLAVE_ID;  // slave address

    // Function code
	if (ReadFromIreg == 1) handler->TxData[1] = READIREGS;
	else handler->TxData[1] = READHREGS;

	handler->TxData[2] = 0x0; // register address high byte
	// low byte is set in the calling function

	handler->TxData[4] = 0x0; // number of registers high byte
	// number of registers low byte
	// calculated from the number of values to read and their size
	// e. g.: 1 32 bit value requires 2 registers (2 x 16 bits)
	handler->TxData[5] = numRegisterstoRead * abs(signedValueSizeinBits)/16;

	// number of values included in slave response
	// is only 1 or 16 for Octave meters
	if (numRegisterstoRead == 16) handler->ValuesInResponse = 16;
	else handler->ValuesInResponse = 1;

	handler->signedResponseSizeinBits = signedValueSizeinBits;

	uint16_t crc = crc16(handler->TxData, 6);
	handler->TxData[6] = crc&0xFF;   // CRC low
	handler->TxData[7] = (crc>>8)&0xFF;  // CRC high

	// Flag this as a reading (not writing) operation
	handler->ReadOperation = 1;

	// Send the Modbus PDU to the slave
	HAL_UART_Transmit(modbus_uart, handler->TxData, 8, 100);
}

// Write a single Modbus input register
void WriteSingleReg(struct ModbusHandler *handler, UART_HandleTypeDef *modbus_uart){
    // Create Modbus PDU
	handler->TxData[0] = SLAVE_ID;  // slave address

    // Function code
	handler->TxData[1] = WRITEIREG;
	handler->TxData[2] = 0x0; // register address high
	// low byte is set in the calling function

	handler->TxData[4] = 0x0; // Data high
	// low byte is set in the calling function

	uint16_t crc = crc16(handler->TxData, 6);
	handler->TxData[6] = crc&0xFF;   // CRC low
	handler->TxData[7] = (crc>>8)&0xFF;  // CRC high

	handler->ValuesInResponse = 1;
	handler->signedResponseSizeinBits = s_int16;
	// Flag this as a write (not read) operation
	handler->ReadOperation = 0;

	// Send the Modbus PDU to the slave
	HAL_UART_Transmit(modbus_uart, handler->TxData, 8, 100);
}

// Receive a Modbus response from the slave in blocking mode
void ModbusReceive(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
	if (handler->ReadOperation == 1){
	  if (handler->signedResponseSizeinBits == s_int16){
		// calculate how many bytes will be received depending on the amount of requested values
		if (handler->ValuesInResponse == 16) HAL_UART_Receive(modbus_uart, handler->RxData, 37, 100); // 100ms timeout
		else HAL_UART_Receive(modbus_uart, handler->RxData, 7, 100); // 100ms timeout

		for (int i = 0; i < handler->ValuesInResponse; i++){
			// Save each of the incoming values to the buffer
			handler->int16Buffer[i] = handler->RxData[i+i+3]<<8 | handler->RxData[i+i+4];
			// Print the values to serial, for visualization or debugging
			HAL_UART_Transmit(echo_uart, &handler->RxData[i+i+3], 1, 100);
			HAL_UART_Transmit(echo_uart, &handler->RxData[i+i+4], 1, 100);
		}

		// Clear the unused buffers
		handler->int32Buffer = 0;
		handler->uint32Buffer = 0;
		handler->int64Buffer = 0;
		handler->uint64Buffer = 0;
	  }

	  else {
			// Empty the int16 buffer
			for (int i = 0; i < 16; i++){
				handler->int16Buffer[i] = 0;
			}

			if ((handler->signedResponseSizeinBits == s_uint32) | (handler->signedResponseSizeinBits == s_int32)){
				// A 32-bit values is always sent as a 9-byte response
				HAL_UART_Receive(modbus_uart, handler->RxData, 9, 100); // 100ms timeout

				// The response comes in AB CD order (2 regs total), combine it into ABCD
				if (handler->signedResponseSizeinBits == s_uint32){
					handler->uint32Buffer = (uint32_t)handler->RxData[3]<<24 |
							(uint32_t)handler->RxData[4]<<16 |
							(uint32_t)handler->RxData[5]<<8 | (uint32_t)handler->RxData[6];

					// Clear the unused buffers
					handler->int32Buffer = 0;
					handler->int64Buffer = 0;
					handler->uint64Buffer = 0;
				}
				else{ // handler->signedResponseSizeinBits == s_int32
					handler->int32Buffer = (uint32_t)handler->RxData[3]<<24 |
							(uint32_t)handler->RxData[4]<<16 |
							(uint32_t)handler->RxData[5]<<8 | (uint32_t)handler->RxData[6];
					
					// Clear the unused buffers
					handler->uint32Buffer = 0;
					handler->int64Buffer = 0;
					handler->uint64Buffer = 0;
				}

				// Print the values to serial, for visualization or debugging
				for (int i = 3; i<=6; i++) HAL_UART_Transmit(echo_uart, &handler->RxData[i], 1, 100);
			}

			else{ // 64 bits
				// A 64-bit values is always sent as a 13-byte response
				HAL_UART_Receive(modbus_uart, handler->RxData, 13, 100); // 100ms timeout

				// The response comes in HG FE DC BA order (4 regs total), combine it into ABCDEFGH
				if (handler->signedResponseSizeinBits == s_uint64){
					handler->uint64Buffer = (uint64_t)handler->RxData[10]<<56 |
							(uint64_t)handler->RxData[9]<<48 | (uint64_t)handler->RxData[8]<<40 |
							(uint64_t)handler->RxData[7]<<32 | (uint64_t)handler->RxData[6]<<24 |
							(uint64_t)handler->RxData[5]<<16 | (uint64_t)handler->RxData[4]<<8 |
							(uint64_t)handler->RxData[3];
					
					// Clear the unused buffers
					handler->int32Buffer = 0;
					handler->uint32Buffer = 0;
					handler->int64Buffer = 0;
				}
				else{ // handler->signedResponseSizeinBits == s_int64
					handler->int64Buffer = (uint64_t)handler->RxData[10]<<56 |
							(uint64_t)handler->RxData[9]<<48 | (uint64_t)handler->RxData[8]<<40 |
							(uint64_t)handler->RxData[7]<<32 | (uint64_t)handler->RxData[6]<<24 |
							(uint64_t)handler->RxData[5]<<16 | (uint64_t)handler->RxData[4]<<8 |
							(uint64_t)handler->RxData[3];
					
					// Clear the unused buffers
					handler->int32Buffer = 0;
					handler->uint32Buffer = 0;
					handler->uint64Buffer = 0;
				}

				// Print the values to serial, for visualization or debugging
				for (int i = 10; i>=3; i--) HAL_UART_Transmit(echo_uart, &handler->RxData[i], 1, 100);
			}
		}
	}

	else{ // Write Operation
		// The slave response for a write operation is just an echo of the PDU (8 bytes)
		HAL_UART_Receive(modbus_uart, handler->RxData, 8, 100); // 100ms timeout

		// Save the echo of the written value to the buffer
		handler->int16Buffer[0] = handler->RxData[4]<<8 | handler->RxData[5];

		// Print the values to serial, for visualization or debugging
		HAL_UART_Transmit(echo_uart, &handler->RxData[4], 1, 100);
		HAL_UART_Transmit(echo_uart, &handler->RxData[5], 1, 100);
	}
}


/****** Octave Modbus wrapper ******/
void ReadAlarms(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = READALARMS;

	handler->TxData[3] = 0x0; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);
	ModbusReceive(handler, echo_uart, modbus_uart);
}

void SerialNumber(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = SERIALNUMBER;

	handler->TxData[3] = 0x1; // register address low

	ReadNRegs(handler, modbus_uart, 16, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadWeekday(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = READWEEKDAY;

	handler->TxData[3] = 0x11; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadDay(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = READDAY;

	handler->TxData[3] = 0x12; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadMonth(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = READMONTH;

	handler->TxData[3] = 0x13; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadYear(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = READYEAR;

	handler->TxData[3] = 0x14; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadHours(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = READHOURS;

	handler->TxData[3] = 0x15; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadMinutes(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = READMINUTES;

	handler->TxData[3] = 0x16; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void VolumeUnit(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
    handler->LastUsed = VOLUMEUNIT;

	handler->TxData[3] = 0x17; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ForwardVolume(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, int unsignedValueSizeinBits){

	if (unsignedValueSizeinBits == 64) {
		handler->LastUsed = FORWARDVOLUME_DOUBLE;

		handler->TxData[3] = 0x18; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint64);
	}
	else { // unsignedValueSizeinBits == 32
		handler->LastUsed = FORWARDVOLUME_UINT32;

		handler->TxData[3] = 0x36; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint32);
	}


	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReverseVolume(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, int unsignedValueSizeinBits){
	if (unsignedValueSizeinBits == 64) {
		handler->LastUsed = REVERSEVOLUME_DOUBLE;

		handler->TxData[3] = 0x20; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint64);
	}
	else { // unsignedValueSizeinBits == 32
		handler->LastUsed = REVERSEVOLUME_UINT32;

		handler->TxData[3] = 0x3A; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint32);
	}

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadVolumeResIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
  handler->LastUsed = READVOLUMERESINDEX;

	handler->TxData[3] = 0x28; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void SignedCurrentFlow(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, int unsignedValueSizeinBits){
	if (unsignedValueSizeinBits == 64) {
		handler->LastUsed = SIGNEDCURRENTFLOW_DOUBLE;

		handler->TxData[3] = 0x29; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint64);
	}
	else { // unsignedValueSizeinBits == 32
		handler->LastUsed = SIGNEDCURRENTFLOW_INT32;

		handler->TxData[3] = 0x3E; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint32);
	}

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void ReadFlowResIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
  handler->LastUsed = READFLOWRESINDEX;

	handler->TxData[3] = 0x31; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void FlowUnits(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
	handler->LastUsed = FLOWUNITS;

	handler->TxData[3] = 0x32; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void FlowDirection(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
	handler->LastUsed = FLOWDIRECTION;

	handler->TxData[3] = 0x33; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void TemperatureValue(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
	handler->LastUsed = TEMPERATUREVALUE;

	handler->TxData[3] = 0x34; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void TemperatureUnit(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart){
	handler->LastUsed = TEMPERATUREUNIT;

	handler->TxData[3] = 0x35; // register address low

	ReadNRegs(handler, modbus_uart, 1, s_int16);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void NetSignedVolume(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, int unsignedValueSizeinBits){
	if (unsignedValueSizeinBits == 64) {
		handler->LastUsed = NETSIGNEDVOLUME_DOUBLE;

		handler->TxData[3] = 0x42; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint64);
	}
	else { // unsignedValueSizeinBits == 32
		handler->LastUsed = NETSIGNEDVOLUME_INT32;

		handler->TxData[3] = 0x52; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint32);
	}

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void NetUnsignedVolume(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, int unsignedValueSizeinBits){
	if (unsignedValueSizeinBits == 64) {
		handler->LastUsed = NETUNSIGNEDVOLUME_DOUBLE;

		handler->TxData[3] = 0x4A; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint64);
	}
	else { // unsignedValueSizeinBits == 32
		handler->LastUsed = NETUNSIGNEDVOLUME_UINT32;

		handler->TxData[3] = 0x56; // register address low

		ReadNRegs(handler, modbus_uart, 1, s_uint32);
	}

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteAlarms(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEALARMS;

	handler->TxData[3] = 0x0; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}

void WriteWeekday(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEWEEKDAY;

	handler->TxData[3] = 0x1; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteDay(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEDAY;

	handler->TxData[3] = 0x2; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteMonth(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEMONTH;

	handler->TxData[3] = 0x3; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteYear(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEYEAR;

	handler->TxData[3] = 0x4; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteHours(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEHOURS;

	handler->TxData[3] = 0x5; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteMinutes(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEMINUTES;

	handler->TxData[3] = 0x6; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteVolumeResIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEVOLUMERESINDEX;

	handler->TxData[3] = 0x7; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}


void WriteVolumeFlowIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow){
	handler->LastUsed = WRITEVOLUMEFLOWINDEX;

	handler->TxData[3] = 0x8; // register address low

	handler->TxData[5] = DataLow; // Data low

	WriteSingleReg(handler, modbus_uart);

	ModbusReceive(handler, echo_uart, modbus_uart);
}
