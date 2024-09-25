#ifndef __OctaveModbusWrapper_H__
#define __OctaveModbusWrapper_H__

#include <Arduino.h>
#include "../IndustrialShields/ModbusRTUMaster.h"
#include <stdint.h>
#include <cstdlib>
#include <map>
#include "ParamTables.h"

/****** Settings ******/
#define MODBUS_SLAVE_ADDRESS 1

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

        void begin(uint32_t baudrate = 2400);
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
        void PrintDouble(double &number, HardwareSerial &Serial);
        void PrintSerial(int16_t registers[16], HardwareSerial &Serial);
        void PrintAlarms(int16_t alarms, HardwareSerial &Serial);
        void PrintError(uint8_t errorCode, HardwareSerial &Serial);
        // Interpret the result of a Modbus request from its error code and print it to a Serial
        uint8_t InterpretResult(uint8_t errorCode, HardwareSerial &Serial);

        // Octave Modbus Requests
        uint8_t ReadAlarms(int16_t* output);
        uint8_t SerialNumber(int16_t* output);
        uint8_t ReadWeekday(int16_t* output);
        uint8_t ReadDay(int16_t* output);
        uint8_t ReadMonth(int16_t* output);
        uint8_t ReadYear(int16_t* output);
        uint8_t ReadHours(int16_t* output);
        uint8_t ReadMinutes(int16_t* output);
        uint8_t VolumeUnit(int16_t* output);
        uint8_t ForwardVolume_uint32(uint32_t* output);
        uint8_t ForwardVolume_double(double* output);
        uint8_t ReverseVolume_uint32(uint32_t* output);
        uint8_t ReverseVolume_double(double* output);
        uint8_t ReadVolumeResIndex(int16_t* output);
        uint8_t SignedCurrentFlow_int32(int32_t* output);
        uint8_t SignedCurrentFlow_double(double* output);
        uint8_t ReadFlowResIndex(int16_t* output);
        uint8_t FlowUnit(int16_t* output);
        uint8_t FlowDirection(int16_t* output);
        uint8_t TemperatureValue(int16_t* output);
        uint8_t TemperatureUnit(int16_t* output);
        uint8_t NetSignedVolume_int32(int32_t* output);
        uint8_t NetSignedVolume_double(double* output);
        uint8_t NetUnsignedVolume_uint32(uint32_t* output);
        uint8_t NetUnsignedVolume_double(double* output);
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
        double doubleBuffer;

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