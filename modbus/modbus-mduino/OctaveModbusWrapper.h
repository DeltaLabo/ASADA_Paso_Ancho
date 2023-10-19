#ifndef __OctaveModbusWrapper_H__
#define __OctaveModbusWrapper_H__

/****** Modbus settings ******/
#define SLAVE_ADDRESS 1
#define MODBUS_BAUDRATE 2400

#include <Arduino.h>
#include "src/ModbusRTUMaster.h"
#include <fp64lib.h>
#include <stdint.h>
#include <ArduinoSTL.h>
#include <map>

// Bit indices to check for alarms
const int alarmsIndices[] = {0, 5, 7, 11, 12, 13};

// Scale factor for two decimal places
#define SCALE_FACTOR "100.0"

// Limit values that can represented in 16 and 32 bits with 2 decimal places
#define DEC16_MAX "327.67"
#define DEC16_MIN "-327.68"
#define DEC32_MAX "21474836.47"
#define DEC32_MIN "-21474836.48"

class OctaveModbusWrapper {
    public:
        explicit OctaveModbusWrapper(HardwareSerial &modbusSerial, HardwareSerial &logSerial);

        void begin();
        void InitMaps();

        int AwaitResponse();
        void ProcessResponse(ModbusResponse *response);
        int BlockingReadRegisters(int startMemAddress, int numValues, int signedValueSizeinBits);
        int BlockingWriteSingleRegister(int memAddress, int value);

        int ReadAlarms();
        int SerialNumber();
        int ReadWeekday();
        int ReadDay();
        int ReadMonth();
        int ReadYear();
        int ReadHours();
        int ReadMinutes();
        int VolumeUnit();
        int ForwardVolume(int unsignedValueSizeinBits);
        int ReverseVolume(int unsignedValueSizeinBits);
        int ReadVolumeResIndex();
        int SignedCurrentFlow(int unsignedValueSizeinBits);
        int ReadFlowResIndex();
        int FlowUnit();
        int FlowDirection();
        int TemperatureValue();
        int TemperatureUnit();
        int NetSignedVolume(int unsignedValueSizeinBits);
        int NetUnsignedVolume(int unsignedValueSizeinBits);
        int SystemReset();
        int WriteWeekday(int value);
        int WriteDay(int value);
        int WriteMonth(int value);
        int WriteYear(int value);
        int WriteHours(int value);
        int WriteMinutes(int value);
        int WriteVolumeResIndex(int value);
        int WriteVolumeFlowIndex(int value);

        /****** Modbus response buffers ******/
        int int16Buffer[16];
        int32_t int32Buffer;
        uint32_t uint32Buffer;
        float64_t doubleBuffer;

        /****** Parameter maps ********/
        std::map<String, int> flowUnitNameToCode;
        std::map<int, String> flowUnitCodeToName;
        std::map<String, int> volumeUnitNameToCode;
        std::map<int, String> volumeUnitCodeToName;
        std::map<String, int> temperatureUnitNameToCode;
        std::map<int, String> temperatureUnitCodeToName;
        std::map<String, int> flowDirectionNameToCode;
        std::map<int, String> flowDirectionCodeToName;
        std::map<String, int> resolutiontNameToCode;
        std::map<int, String> resolutionCodeToName;
        std::map<int, String> alarmCodeToName;

        /****** Function name map *******/
        std::map<String, int> functionNameToCode;
        std::map<int, String> functionCodeToName;

        int lastUsedFunctionCode = 0;

        uint32_t modbusBaudrate = MODBUS_BAUDRATE;
    
    private:
        ModbusRTUMaster _master;
        HardwareSerial &_logSerial;

        /****** Parameters for the Modbus requests ******/
        // Number of registers to read for a Modbus request, is 0 for a write request
        int _numRegisterstoRead = 0;
        // Size, in bits, of the slave response values, is -32 for int32 and 32 for uint32
        int _signedResponseSizeinBits = 16;
};

#endif