#ifndef __OctaveModbusWrapper_H__
#define __OctaveModbusWrapper_H__

/****** Modbus settings ******/
#define MODBUS_BAUDRATE 2400
#define MODBUS_SLAVE_ADDRESS 1

#include <Arduino.h>
#include "src/ModbusRTUMaster.h"
#include <fp64lib.h>
#include <stdint.h>
#include <ArduinoSTL.h>
#include <map>
#include "ParamTables.h"

// Bit indices to check for alarms
const uint8_t alarmsIndices[] = {0, 5, 7, 11, 12, 13};

// Scale factor for two decimal places
#define SCALE_FACTOR "100.0"

// Limit values that can represented in 16 and 32 bits with 2 decimal places
#define DEC16_MAX "327.67"
#define DEC16_MIN "-327.68"
#define DEC32_MAX "21474836.47"
#define DEC32_MIN "-21474836.48"

class OctaveModbusWrapper {
    public:
        explicit OctaveModbusWrapper(HardwareSerial &modbusSerial);

        void begin();
        void InitMaps();

        uint8_t AwaitResponse();
        void ProcessResponse(ModbusResponse *response);
        uint8_t BlockingReadRegisters(uint8_t startMemAddress, uint8_t numValues, int8_t signedValueSizeinBits);
        uint8_t BlockingWriteSingleRegister(uint8_t memAddress, int16_t value);

        void PrintDouble(float64_t &number, HardwareSerial &Serial);
        void PrintSerial(int16_t registers[16], HardwareSerial &Serial);
        void PrintAlarms(int16_t alarms, HardwareSerial &Serial);
        void PrintError(uint8_t errorCode, HardwareSerial &Serial);
        uint8_t InterpretResult(uint8_t errorCode, HardwareSerial &Serial);

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