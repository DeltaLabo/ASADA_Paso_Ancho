#ifndef __BMSWrapper_H__
#define __BMSWrapper_H__

#include <HardwareSerial.h>
#include <map>

/****** Settings ******/
// Timeout for BMS responses
#define BMS_TIMEOUT 1000 // ms

class BMSWrapper {
public:
    // Constructor to initialize the BMSWrapper with a reference to the serial interface
    explicit BMSWrapper(HardwareSerial& serial);

    void begin();

    // Initialize all code-to-name mappings
    void InitMaps();

    // Interpret and print a BMS error code
    void PrintError(uint8_t errorCode, HardwareSerial &Serial);

    uint8_t readBasicInformation(
        int* voltage, int* current,
        int* remainingCapacity, int* nominalCapacity
        );

    // Method to read voltage from the BMS
    uint8_t readVoltage(int* output);

    // Method to read current from the BMS
    uint8_t readCurrent(int* output);

    // Method to read remaining capacity from the BMS
    uint8_t readRemainingCapacity(int* output);

    // Method to read nominal capacity from the BMS
    uint8_t readNominalCapacity(int* output);

private:
    uint8_t calculateChecksum(const uint8_t* data, uint8_t length);

    HardwareSerial& _serial;
    std::map<uint8_t, const char*> errorCodeToName;

    uint8_t _lastBMSErrorCode = 0;
};

#endif // __BMSWrapper_H__