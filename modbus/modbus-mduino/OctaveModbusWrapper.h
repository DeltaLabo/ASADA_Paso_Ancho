#ifndef __OctaveModbusWrapper_H__
#define __OctaveModbusWrapper_H__

/****** Modbus settings ******/
#define SLAVE_ADDRESS 1
#define MODBUS_BAUDRATE 2400

#include <Arduino.h>
#include "src/ModbusRTUMaster.h"
#include <fp64lib.h>
#include <stdint.h>

class OctaveModbusWrapper {
    public:
        explicit OctaveModbusWrapper(HardwareSerial &modbusSerial, HardwareSerial &logSerial, bool logtoSerial, bool logtoLoRa);

    public:
        void begin(uint32_t rate = 2400UL);

        void ReadAlarms();
        void SerialNumber();
        void ReadWeekday();
        void ReadDay();
        void ReadMonth();
        void ReadYear();
        void ReadHours();
        void ReadMinutes();
        void VolumeUnit();
        void ForwardVolume(int unsignedValueSizeinBits);
        void ReverseVolume(int unsignedValueSizeinBits);
        void ReadVolumeResIndex();
        void SignedCurrentFlow(int unsignedValueSizeinBits);
        void ReadFlowResIndex();
        void FlowUnits();
        void FlowDirection();
        void TemperatureValue();
        void TemperatureUnit();
        void NetSignedVolume(int unsignedValueSizeinBits);
        void NetUnsignedVolume(int unsignedValueSizeinBits);
        void SystemReset();
        void WriteAlarms(int value);
        void WriteWeekday(int value);
        void WriteDay(int value);
        void WriteMonth(int value);
        void WriteYear(int value);
        void WriteHours(int value);
        void WriteMinutes(int value);
        void WriteVolumeResIndex(int value);
        void WriteVolumeFlowIndex(int value);

        /****** Modbus response buffers ******/
        int int16Buffer[16];
        int32_t int32Buffer;
        uint32_t uint32Buffer;
        float64_t doubleBuffer;

        uint32_t modbusBaudrate = MODBUS_BAUDRATE;
    
    private:
        ModbusRTUMaster _master;
        HardwareSerial _logSerial;
        bool _logtoSerial;
        bool _logtoLoRa;

        /****** Parameters for the Modbus requests ******/
        // Number of registers to read for a Modbus request, is 0 for a write request
        int _numRegisterstoRead = 0;
        // Size, in bits, of the slave response values, is -32 for int32 and 32 for uint32
        int _signedResponseSizeinBits = 16;
};

#endif