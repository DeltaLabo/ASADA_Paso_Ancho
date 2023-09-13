#ifndef INC_MODBUS_WRAPPER_H_
#define INC_MODBUS_WRAPPER_H_

/****** Modbus settings ******/
#define SLAVE_ID 03
// 0 to read from Input regs, 1 for Holding regs
#define ReadFromIreg 0
// Frequency for sending Modbus requests to the slave
#define POLLING_FREQ_MS 1000 // ms

// Modbus function codes
enum {READHREGS = 0x03, READIREGS = 0x04, WRITEIREG = 0x06, WRITEIREGS = 0x10};

// Codes for every value that can be read via Modbus
// Leftover from previous version of the code, currently has no use
// but could be useful for debugging
enum {
    READALARMS = 0x21,
    SERIALNUMBER = 0x22,
    READWEEKDAY = 0x23,
    READDAY = 0x24,
    READMONTH = 0x25,
    READYEAR = 0x26,
    READHOURS = 0x26,
    READMINUTES = 0x27,
    VOLUMEUNIT = 0x28,
    FORWARDVOLUME_DOUBLE = 0x29,
    REVERSEVOLUME_DOUBLE = 0x30,
    READVOLUMERESINDEX = 0x31,
    SIGNEDCURRENTFLOW_DOUBLE = 0x32,
    READFLOWRESINDEX = 0x33,
    FLOWUNITS = 0x34,
    FLOWDIRECTION = 0x35,
    TEMPERATUREVALUE = 0x36,
    TEMPERATUREUNIT = 0x37,
    FORWARDVOLUME_UI32 = 0x38,
    REVERSEVOLUME_UI32 = 0x39,
	SIGNEDCURRENTFLOW_I32 = 0x40,
	NETSIGNEDVOLUME_DOUBLE = 0x41,
    NETUNSIGNEDVOLUME_DOUBLE = 0x42,
    NETSIGNEDVOLUME_I32 = 0x43,
    NETUNSIGNEDVOLUME_UI32 = 0x44,
    WRITEALARMS = 0x45,
    WRITEVOLUMERESINDEX = 0x46,
    WRITEVOLUMEFLOWINDEX = 0x47,
    WRITEWEEKDAY = 0x48,
    WRITEDAY = 0x49,
    WRITEMONTH = 0x50,
    WRITEYEAR = 0x51,
    WRITEHOURS = 0x52,
    WRITEMINUTES = 0x53,
};

// Word sizes for Modbus client response
enum {s_int16 = 16, s_uint32 = 32, s_int32 = -32, s_uint64 = 64, s_int64 = -64};

// Struct for handling in/out data buffers and tracking previous commands
struct ModbusHandler {
	// Raw In/Out data buffers
	uint8_t RxData[37];
	uint8_t TxData[10];
	// In data buffers
	uint16_t int16Buffer[16];
	uint32_t uint32Buffer;
	int32_t int32Buffer;
	uint64_t uint64Buffer;
	int64_t int64Buffer;
	// Last used command
	int LastUsed;
	// Parameters of the Modbus client response
	int ValuesInResponse;
	int signedResponseSizeinBits;
	int ReadOperation;
};

// Function prototypes
void ReadNRegs(struct ModbusHandler *handler, UART_HandleTypeDef *modbus_uart, int n, int d_size);
void WriteNRegs(struct ModbusHandler *handler, UART_HandleTypeDef *modbus_uart, int n, int d_size);
void ModbusReceive(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadAlarms(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void SerialNumber(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadWeekday(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadDay(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadMonth(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadYear(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadHours(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadMinutes(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void VolumeUnit(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ForwardVolume_double(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReverseVolume_double(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadVolumeResIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void CurrentFlow_double(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReadFlowResIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void FlowUnits(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void FlowDirection(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void TemperatureValue(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void TemperatureUnit(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ForwardVolume_ui32(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void ReverseVolume_ui32(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void CurrentFlow_i32(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void SignedVolume_double(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void UnsignedVolume_double(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void SignedVolume_i32(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void UnsignedVolume_ui32(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart);
void WriteAlarms(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteVolumeResIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteVolumeFlowIndex(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteWeekday(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteDay(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteMonth(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteYear(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteHours(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);
void WriteMinutes(struct ModbusHandler *handler, UART_HandleTypeDef *echo_uart, UART_HandleTypeDef *modbus_uart, uint8_t DataLow);

#endif /* INC_MODBUS_WRAPPER_H_ */
