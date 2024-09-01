#include "BMSWrapper.h"
#include <Arduino.h>

// Constructor implementation
BMSWrapper::BMSWrapper(HardwareSerial& serial) : _serial(serial) {}

void BMSWrapper::begin() {
    InitMaps();
}

// Initialize all code-to-name mappings
void BMSWrapper::InitMaps() {
    errorCodeToName[0] = "No error";
    errorCodeToName[18] = "BMS module not found";
}

// Interpret and print a BMS error code
void BMSWrapper::PrintError(uint8_t errorCode, HardwareSerial &Serial) {
    // Print the error code and its meaning
    Serial.print("Error code ");
    Serial.print(errorCode);
    Serial.print(": ");
    Serial.println(errorCodeToName[errorCode]);
}

// Calculate the checksum based on the datasheet
uint8_t BMSWrapper::calculateChecksum(const uint8_t* data, uint8_t length) {
    uint8_t checksum = 0;
    for (uint8_t i = 0; i < length; i++) {
        checksum += data[i];
    }
    checksum = ~checksum + 1;
    return checksum;
}

uint8_t BMSWrapper::readBasicInformation(
    int* voltage, int* current,
    int* remainingCapacity, int* nominalCapacity
    ) {
    uint8_t frame[7];
    frame[0] = 0xDD; // Start byte
    frame[1] = 0xA5; // Read command
    frame[2] = 0x03; // Read basic information
    frame[3] = 0x00; // Always 0 for read commands
    frame[4] = calculateChecksum(frame, 4); // Checksum 1
    frame[5] = calculateChecksum(frame, 5); // Checksum 2
    frame[6] = 0x77; // Stop byte

    _serial.write(frame, sizeof(frame));

    uint32_t startTime = millis();
    // Wait for BMS to respond
    while (_serial.available() == 0 && millis() - startTime < BMS_TIMEOUT);

    // Expecting 8 relevant bytes and 2 before them
    uint8_t response[2+8];

    if (_serial.available() >= 2+8) {
        // Read the relevant data
        _serial.readBytes(response, 2+8);
        // Discard the rest
        _serial.flush();

        // Decode the response
        if (voltage != nullptr) {
            *voltage = 10*(response[2] << 8 | response[3]); // mV
        }
        if (current != nullptr) {
            *current = 10*(response[4] << 8 | response[5]); // mA
        }
        if (remainingCapacity != nullptr) {
            *remainingCapacity = 10*(response[6] << 8 | response[7]); // mAh
        }
        if (nominalCapacity != nullptr) {
            *nominalCapacity = 10*(response[8] << 8 | response[9]); // mAh
        }

        _lastBMSErrorCode = 0; // No error
    } else {
        _lastBMSErrorCode = 18; // BMS didn't respond
    }

    return _lastBMSErrorCode;
}

uint8_t BMSWrapper::readVoltage(int* output) {
    return readBasicInformation(output, nullptr, nullptr, nullptr);
}

uint8_t BMSWrapper::readCurrent(int* output) {
    return readBasicInformation(nullptr, output, nullptr, nullptr);
}

uint8_t BMSWrapper::readRemainingCapacity(int* output) {
    return readBasicInformation(nullptr, nullptr, output, nullptr);
}

uint8_t BMSWrapper::readNominalCapacity(int* output) {
    return readBasicInformation(nullptr, nullptr, nullptr, output);
}