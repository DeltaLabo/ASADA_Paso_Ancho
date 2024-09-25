#include "SIM7600Wrapper.h"
#include <Arduino.h>

// Constructor implementation
SIM7600Wrapper::SIM7600Wrapper(HardwareSerial& serial) : _serial(serial) {}

void SIM7600Wrapper::begin() {
  // Initialize code-to-name mappings to interpret readings
  InitMaps();
}

// Initialize all code-to-name mappings
void SIM7600Wrapper::InitMaps() {
    errorCodeToName[0] = "No error";
    errorCodeToName[11] = "SIM module not found";
    errorCodeToName[12] = "No signal";
    errorCodeToName[13] = "Insufficient data remaining";
    errorCodeToName[14] = "Logging error";
}

// Interpret and print a SIM error code
void SIM7600Wrapper::PrintError(uint8_t errorCode, HardwareSerial &Serial) {
    // Print the error code and its meaning
    Serial.print("Error code ");
    Serial.print(errorCode);
    Serial.print(": ");
    Serial.println(errorCodeToName[errorCode]);
}

// Method to send AT command and check for the expected response.
// expected_answer can be set to nullptr to skip
// checking the response and avoid clearing the input serial buffer.
uint8_t SIM7600Wrapper::sendATCommand(const char* ATcommand, const char* expected_answer, unsigned int timeout) {
    // answer = 1 means that the expected answer hasn't been found
    uint8_t x = 0, answer = 1;

    memset(response, '\0', 100);    // Initialize the response buffer

    while (_serial.available() > 0) _serial.read();   // Clean the input buffer

    _serial.println(ATcommand);    // Send the AT command

    uint32_t startTime;

    if (expected_answer != nullptr) {
        x = 0;
        startTime = millis();

        // Wait for the expected response within the timeout period
        do {
            if (_serial.available() != 0) {
                char currentChar = _serial.read();
                // Check if the index is within range to avoid
                // an overflow in the response buffer
                if (x < sizeof(response)/sizeof(char)) {
                    response[x] = currentChar;
                }
                x++;
                if (strstr(response, expected_answer) != NULL) {
                    answer = 0;
                }
            }
        } while ((answer == 1) && ((millis() - startTime) < timeout));

        _lastSIMErrorCode = (answer == 0) ? 0 : 11; // Set the error code based on the result
    } else {
        // Delay
        startTime = millis();
        while (millis() - startTime < timeout); 

        _lastSIMErrorCode = 0; // No error
    }

    return _lastSIMErrorCode;
}

// Method to check the signal reception of the SIM7600 module
uint8_t SIM7600Wrapper::checkSignal() {
    uint8_t result = 0;

    // Send the AT+CSQ command to query signal strength
    result = sendATCommand("AT+CSQ", nullptr, 300);

    // Check if the command was successfully sent and acknowledged
    if (result == 0) {

        if (_serial.available() > 0) {
            // Read the response from the SIM7600 module
            String response = _serial.readString();

            // Check if the response contains the "+CSQ:" prefix
            if (response.indexOf("+CSQ: ") != -1) {
                // Extract the <rssi> value from the response
                String rssiStr = response.substring(
                    response.indexOf("+CSQ: ") + sizeof("+CSQ: ") - 1,
                    response.indexOf(","));

                int rssi = rssiStr.toInt();

                // Check if the <rssi> value indicates no signal (99 or 199)
                if (rssi == 99 || rssi == 199) {
                    _lastSIMErrorCode = 12;  // No signal found
                    return _lastSIMErrorCode;
                } else {
                    _lastSIMErrorCode = 0;  // Signal found
                    return _lastSIMErrorCode;
                }
            }
        }
    }

    _lastSIMErrorCode = 11; // The module didn't respond to the request
    return _lastSIMErrorCode;
}

// Method to check if the SIM7600 module is powered on and properly configured
uint8_t SIM7600Wrapper::initialCheck() {
    // Send the AT command to check if the module is powered on
    _lastSIMErrorCode = sendATCommand("AT", "OK", 1000);
    // Disable AT command echo
    if (_lastSIMErrorCode == 0) {_lastSIMErrorCode = sendATCommand("ATE0", "OK", 1000);}
    // Disable unsolicited new message indications
    if (_lastSIMErrorCode == 0) {_lastSIMErrorCode = sendATCommand("AT+CNMI=0,0", "OK", 1000);}

    return _lastSIMErrorCode;
}

// Method to delete all stored SMS messages
void SIM7600Wrapper::deleteAllSMS() {
    sendATCommand("AT+CMGD=,4", "OK", 5000);  // Delete all SMS messages
}

// Method to send an SMS message
uint8_t SIM7600Wrapper::sendSMS(const char* phoneNumber, const char* message) {
    uint8_t answer = 0;
    char aux_string[30];

    sendATCommand("AT+CMGF=1", "OK", 1000);    // Set SMS mode to text
    sprintf(aux_string, "AT+CMGS=\"%s\"", phoneNumber);
    answer = sendATCommand(aux_string, ">", 3000);    // Send the SMS number
    if (answer == 0) {
        _serial.print(message);
        _serial.write(0x1A);  // Send Ctrl+Z to indicate end of message
        answer = sendATCommand("", "OK", 20000);
        if (answer == 0) {
            _lastSIMErrorCode = 0;   // Sent successfully
            return _lastSIMErrorCode;
        }
    }
    _lastSIMErrorCode = 11;  // The module didn't respond
    return _lastSIMErrorCode;
}

// Method to check the remaining data and its expiration date by sending an SMS
// and parsing the response
uint8_t SIM7600Wrapper::checkRemainingData(
    float* remainingDataOutput,
    String* dataExpirationDateOutput
    ) {
    deleteAllSMS();  // Delete all stored SMS messages

    if (sendSMS("606", "SALDO") != 0) {  // Send "SALDO" message to 606
        _lastSIMErrorCode = 11;  // The module didn't respond
        return _lastSIMErrorCode;
    }

    // Delay 10 s
    uint32_t startTime = millis();
    while (millis() - startTime < 10000);

    // Read the first SMS
    if (sendATCommand("AT+CMGR=0", "OK", 300) != 0) {
        _lastSIMErrorCode = 11;  // The module didn't respond
        return _lastSIMErrorCode;
    }

    String convertedResponse = String(response);

    // Parse the response to find the remaining data amount
    int index = convertedResponse.indexOf("Saldo:");
    int startIndex;
    int endIndex;

    float remainingData;
    String dataExpirationDate;

    if (index != -1) {
        startIndex = index + sizeof("Saldo:") - 1;
        endIndex = convertedResponse.indexOf(" ", startIndex);
        remainingData = convertedResponse.substring(startIndex, endIndex).toFloat();

        if (remainingDataOutput != nullptr) {
            *remainingDataOutput = remainingData;
        }

        if (remainingData < MIN_DATA) {
            _lastSIMErrorCode = 13; // Insufficient data remaining
            return _lastSIMErrorCode;
        }
    } else {
        _lastSIMErrorCode = 11;  // The module didn't respond
        return _lastSIMErrorCode;
    }

    index = convertedResponse.indexOf("vence: ");
    if (index != -1) {
        startIndex = index + sizeof("vence: ") - 1;
        endIndex = convertedResponse.indexOf("\r\n", startIndex);
        dataExpirationDate = convertedResponse.substring(startIndex, endIndex);

        if (dataExpirationDateOutput != nullptr) {
            *dataExpirationDateOutput = remainingData;
        }
    } else {
        _lastSIMErrorCode = 11;  // The module didn't respond
        return _lastSIMErrorCode;
    }

    _lastSIMErrorCode = 0; // No error
    return _lastSIMErrorCode;
}