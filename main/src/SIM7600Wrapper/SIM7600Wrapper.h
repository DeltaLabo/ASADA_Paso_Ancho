#ifndef __SIM7600Wrapper_H__
#define __SIM7600Wrapper_H__

#include <HardwareSerial.h>
#include <map>

/****** Settings ******/
// Minimum acceptable amount of available data
#define MIN_DATA 150 // CRC


class SIMWrapper {
public:
    // Constructor to initialize the SIMWrapper with a reference to the serial interface
    explicit SIMWrapper(HardwareSerial& serial);

    void begin();

    // Initialize all code-to-name mappings
    void InitMaps();

    // Print the interpretation of an error code to serial
    void PrintError(uint8_t errorCode, HardwareSerial &Serial);

    // Method to check the signal strength of the SIM7600 module
    // Returns 0 if signal is found, otherwise returns 1
    uint8_t checkSignal();

    // Method to check if the SIM7600 module is powered on
    // Returns 0 if the module responds correctly, otherwise returns 1
    uint8_t checkPower();

    // Method to check the remaining data by sending an SMS and parsing the response
    // Returns 0 if remaining data is more than 150, otherwise returns 1
    uint8_t checkRemainingData();

    // Code-to-name mappings for errors
    std::map<uint8_t, String> errorCodeToName;

private:
    // Method to send AT command and check for the expected response
    uint8_t sendATCommand(const char* ATcommand, const char* expected_answer, unsigned int timeout);

    // Method to delete all stored SMS messages
    void deleteAllSMS();

    // Method to send an SMS message
    bool sendSMS(const char* phoneNumber, const char* message);

    HardwareSerial& _serial;  // Reference to the hardware serial interface
    char response[100];       // Buffer to store the response

    uint8_t _lastSIMErrorCode = 0;
};

#endif // SIM7600WRAPPER_H