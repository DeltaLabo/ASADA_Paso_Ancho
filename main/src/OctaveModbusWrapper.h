#ifndef __OctaveModbusWrapper_H__
#define __OctaveModbusWrapper_H__

#include <Arduino.h>
#include "M-Duino/ModbusRTUMaster.h"
#include <fp64lib.h>
#include <stdint.h>
#include <ArduinoSTL.h>
#include <map>
#include "ParamTables.h"
#include "RS485.h"

/****** Modbus settings ******/
#define MODBUS_BAUDRATE 2400
#define MODBUS_SLAVE_ADDRESS 1
// 8 bits, no parity, 1 stop bit
#define PARITY SERIAL_8N1

// Bit indices to check for alarms
const uint8_t alarmsIndices[] = {0, 5, 7, 11, 12, 13};

// Scale factor for two decimal places
// Used for number compression
#define SCALE_FACTOR "100.0"

// Limit limit values that can represented in 16 and 32 bits with 2 decimal places,
// using a scale factor of 100
#define DEC16_MAX "327.67"
#define DEC16_MIN "-327.68"
#define DEC32_MAX "21474836.47"
#define DEC32_MIN "-21474836.48"

class OctaveModbusWrapper {
    public:
        // Initializer
        explicit OctaveModbusWrapper(HardwareSerial &modbusSerial);

        void begin();
        // Initialize all name-to-code mappings
        void InitMaps();

        // Read the Modbus channel in blocking mode until a response is received or an error occurs
        uint8_t AwaitResponse();
        // Processes the raw register values from the slave response and saves them to the buffers
        void ProcessResponse(ModbusResponse *response);
        // Read one or more Modbus registers in blocking mode
        uint8_t BlockingReadRegisters(uint8_t startMemAddress, uint8_t numValues, int8_t signedValueSizeinBits);
        // Write a single Modbus register in blocking mode
        uint8_t BlockingWriteSingleRegister(uint8_t memAddress, int16_t value);

        // Helper functions to print special data types
        void PrintDouble(float64_t &number, HardwareSerial &Serial);
        void PrintSerial(int16_t registers[16], HardwareSerial &Serial);
        void PrintAlarms(int16_t alarms, HardwareSerial &Serial);
        void PrintError(uint8_t errorCode, HardwareSerial &Serial);
        // Interpret the result of a Modbus request from its error code and print it to a Serial
        uint8_t InterpretResult(uint8_t errorCode, HardwareSerial &Serial);

        // Octave Modbus Requests
        uint8_t ReadAlarms();
        uint8_t SerialNumber();
        uint8_t ReadWeekday();
        uint8_t ReadDay();
        uint8_t ReadMonth();
        uint8_t ReadYear();
        uint8_t ReadHours();
        uint8_t ReadMinutes();
        uint8_t VolumeUnit();
        uint8_t ForwardVolume(uint8_t unsignedValueSizeinBits);
        uint8_t ReverseVolume(uint8_t unsignedValueSizeinBits);
        uint8_t ReadVolumeResIndex();
        uint8_t SignedCurrentFlow(uint8_t unsignedValueSizeinBits);
        uint8_t ReadFlowResIndex();
        uint8_t FlowUnit();
        uint8_t FlowDirection();
        uint8_t TemperatureValue();
        uint8_t TemperatureUnit();
        uint8_t NetSignedVolume(uint8_t unsignedValueSizeinBits);
        uint8_t NetUnsignedVolume(uint8_t unsignedValueSizeinBits);
        uint8_t SystemReset();
        uint8_t WriteWeekday(uint8_t value);
        uint8_t WriteDay(uint8_t value);
        uint8_t WriteMonth(uint8_t value);
        uint8_t WriteYear(uint8_t value);
        uint8_t WriteHours(uint8_t value);
        uint8_t WriteMinutes(uint8_t value);
        uint8_t WriteVolumeResIndex(uint8_t value);
        uint8_t WriteFlowResIndex(uint8_t value);

        /****** Modbus response buffers ******/
        int16_t int16Buffer[16];
        int32_t int32Buffer;
        uint32_t uint32Buffer;
        float64_t doubleBuffer;

        /****** Parameter maps ********/
        std::map<String, uint8_t> flowUnitNameToCode;
        std::map<uint8_t, String> flowUnitCodeToName;
        std::map<String, uint8_t> volumeUnitNameToCode;
        std::map<uint8_t, String> volumeUnitCodeToName;
        std::map<String, uint8_t> temperatureUnitNameToCode;
        std::map<uint8_t, String> temperatureUnitCodeToName;
        std::map<String, uint8_t> flowDirectionNameToCode;
        std::map<uint8_t, String> flowDirectionCodeToName;
        std::map<String, uint8_t> resolutiontNameToCode;
        std::map<uint8_t, String> resolutionCodeToName;
        std::map<uint8_t, String> alarmCodeToName;

        /****** Function name map *******/
        std::map<String, uint16_t> functionNameToCode;
        std::map<uint16_t, String> functionCodeToName;

        std::map<uint8_t, String> errorCodeToName;

        uint16_t lastUsedFunctionCode = 0;

        uint32_t modbusBaudrate = MODBUS_BAUDRATE;

    private:
        ModbusRTUMaster _master;

        /****** Parameters for the Modbus requests ******/
        // Number of registers to read for a Modbus request, is 0 for a write request
        uint8_t _numRegisterstoRead = 0;
        // Size, in bits, of the slave response values, is -32 for int32 and 32 for uint32
        int8_t _signedResponseSizeinBits = 16;
        // Storage variable for the Modbus error code, which is also returned with each request
        // Doesn't update when non-Modbus errors occur, i.e. when truncating a double
        uint8_t _lastModbusErrorCode = 0;
};

#endif