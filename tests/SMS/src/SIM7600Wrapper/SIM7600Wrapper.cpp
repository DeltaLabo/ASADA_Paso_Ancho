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
    errorCodeToName[15] = "HTTP error";
    errorCodeToName[16] = "MQTT error";
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
    // Existing implementation...
    // ... Your existing code ...
}

// HTTP methods implementation
uint8_t SIM7600Wrapper::httpInit() {
    // Initialize HTTP service
    _lastSIMErrorCode = sendATCommand("AT+HTTPINIT", "OK", 10000);
    
    if (_lastSIMErrorCode != 0) {
        // If initialization fails, try to terminate and reinitialize
        sendATCommand("AT+HTTPTERM", "OK", 5000);
        _lastSIMErrorCode = sendATCommand("AT+HTTPINIT", "OK", 10000);
    }
    
    // Configure HTTP parameters if init succeeded
    if (_lastSIMErrorCode == 0) {
        // Set content type to JSON
        _lastSIMErrorCode = sendATCommand("AT+HTTPPARA=\"CONTENT\",\"application/json\"", "OK", 5000);
    }
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::httpSetURL(const char* url) {
    char command[200];
    sprintf(command, "AT+HTTPPARA=\"URL\",\"%s\"", url);
    _lastSIMErrorCode = sendATCommand(command, "OK", 5000);
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::httpSetHeaders(const char* headers) {
    char command[200];
    sprintf(command, "AT+HTTPPARA=\"USERDATA\",\"%s\"", headers);
    _lastSIMErrorCode = sendATCommand(command, "OK", 5000);
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::httpPost(const char* data, String* response) {
    char command[100];
    int dataLength = strlen(data);
    
    // Set the data length for the POST request
    sprintf(command, "AT+HTTPDATA=%d,10000", dataLength);
    _lastSIMErrorCode = sendATCommand(command, "DOWNLOAD", 5000);
    
    if (_lastSIMErrorCode == 0) {
        // Send the actual data
        _serial.print(data);
        delay(500); // Give time for data to be sent
        
        // Execute the HTTP POST action
        _lastSIMErrorCode = sendATCommand("AT+HTTPACTION=1", "+HTTPACTION: 1,", 20000);
        
        // If response is requested and POST was successful
        if (response != nullptr && _lastSIMErrorCode == 0) {
            // Read the HTTP response
            _lastSIMErrorCode = sendATCommand("AT+HTTPREAD", "OK", 10000);
            if (_lastSIMErrorCode == 0) {
                *response = String(this->response);
            }
        }
    }
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 15; // HTTP error
    }
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::httpGet(String* response) {
    // Execute the HTTP GET action
    _lastSIMErrorCode = sendATCommand("AT+HTTPACTION=0", "+HTTPACTION: 0,", HTTP_TIMEOUT);
    
    // If response is requested and GET was successful
    if (response != nullptr && _lastSIMErrorCode == 0) {
        // Read the HTTP response
        _lastSIMErrorCode = sendATCommand("AT+HTTPREAD", "OK", 10000);
        if (_lastSIMErrorCode == 0) {
            *response = String(this->response);
        }
    }
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 15; // HTTP error
    }
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::httpTerminate() {
    _lastSIMErrorCode = sendATCommand("AT+HTTPTERM", "OK", 5000);
    return _lastSIMErrorCode;
}

// MQTT methods implementation
uint8_t SIM7600Wrapper::mqttInit(const char* clientID) {
    // Configure MQTT parameters
    char command[100];
    sprintf(command, "AT+CMQTTSTART");
    _lastSIMErrorCode = sendATCommand(command, "OK", 5000);
    
    if (_lastSIMErrorCode == 0) {
        // Set client ID
        sprintf(command, "AT+CMQTTACCQ=0,\"%s\"", clientID);
        _lastSIMErrorCode = sendATCommand(command, "OK", 5000);
    }
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 16; // MQTT error
    }
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::mqttConnect(const char* broker, int port, 
                                   const char* username, const char* password) {
    char command[200];
    
    // Connect to the broker
    if (username != nullptr && password != nullptr) {
        sprintf(command, "AT+CMQTTCONNECT=0,\"%s:%d\",60,1,\"%s\",\"%s\"", 
                broker, port, username, password);
    } else {
        sprintf(command, "AT+CMQTTCONNECT=0,\"%s:%d\",60,1", broker, port);
    }
    
    _lastSIMErrorCode = sendATCommand(command, "+CMQTTCONNECT: 0,0", MQTT_TIMEOUT);
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 16; // MQTT error
    }
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::mqttPublish(const char* topic, const char* message, int qos) {
    char command[100];
    int messageLength = strlen(message);
    
    // Configure the topic and QoS for publishing
    sprintf(command, "AT+CMQTTTOPIC=0,%d", strlen(topic));
    _lastSIMErrorCode = sendATCommand(command, ">", 5000);
    
    if (_lastSIMErrorCode == 0) {
        // Send the topic
        _serial.print(topic);
        delay(100);
        
        // Configure the message payload
        sprintf(command, "AT+CMQTTPAYLOAD=0,%d", messageLength);
        _lastSIMErrorCode = sendATCommand(command, ">", 5000);
        
        if (_lastSIMErrorCode == 0) {
            // Send the message payload
            _serial.print(message);
            delay(100);
            
            // Publish the message with specified QoS
            sprintf(command, "AT+CMQTTPUB=0,%d,60", qos);
            _lastSIMErrorCode = sendATCommand(command, "+CMQTTPUB: 0,0", 10000);
        }
    }
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 16; // MQTT error
    }
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::mqttSubscribe(const char* topic, int qos) {
    char command[100];
    
    // Set the topic to subscribe to
    sprintf(command, "AT+CMQTTSUBTOPIC=0,%d,%d", strlen(topic), qos);
    _lastSIMErrorCode = sendATCommand(command, ">", 5000);
    
    if (_lastSIMErrorCode == 0) {
        // Send the topic
        _serial.print(topic);
        delay(100);
        
        // Execute the subscribe command
        sprintf(command, "AT+CMQTTSUB=0");
        _lastSIMErrorCode = sendATCommand(command, "+CMQTTSUB: 0,0", 10000);
    }
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 16; // MQTT error
    }
    
    return _lastSIMErrorCode;
}

uint8_t SIM7600Wrapper::mqttDisconnect() {
    // Disconnect from MQTT broker
    _lastSIMErrorCode = sendATCommand("AT+CMQTTDISC=0,120", "+CMQTTDISC: 0,0", 5000);
    
    if (_lastSIMErrorCode == 0) {
        // Release the client
        _lastSIMErrorCode = sendATCommand("AT+CMQTTREL=0", "OK", 5000);
        
        if (_lastSIMErrorCode == 0) {
            // Stop MQTT service
            _lastSIMErrorCode = sendATCommand("AT+CMQTTSTOP", "OK", 5000);
        }
    }
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 16; // MQTT error
    }
    
    return _lastSIMErrorCode;
}

// Helper method to create JSON payloads
String SIM7600Wrapper::createJSONPayload(const std::vector<std::pair<String, String>>& keyValues) {
    String json = "{";
    
    for (size_t i = 0; i < keyValues.size(); i++) {
        json += "\"" + keyValues[i].first + "\":\"" + keyValues[i].second + "\"";
        
        if (i < keyValues.size() - 1) {
            json += ",";
        }
    }
    
    json += "}";
    return json;
}

// Generic value logging function implementation
template <typename T>
uint8_t SIM7600Wrapper::logValue(const String& service, const String& endpoint, 
                               const String& varName, T value, 
                               const String& unit) {
    
    String valueStr = String(value);
    if (unit.length() > 0) {
        valueStr += " " + unit;
    }
    
    std::vector<std::pair<String, String>> data;
    data.push_back(std::make_pair("variable", varName));
    data.push_back(std::make_pair("value", valueStr));
    data.push_back(std::make_pair("timestamp", String(millis())));
    
    String jsonPayload = createJSONPayload(data);
    
    if (service.equalsIgnoreCase("http")) {
        // HTTP logging
        httpInit();
        httpSetURL(endpoint.c_str());
        httpSetHeaders("Content-Type: application/json");
        _lastSIMErrorCode = httpPost(jsonPayload.c_str());
        httpTerminate();
    } 
    else if (service.equalsIgnoreCase("mqtt")) {
        // MQTT logging
        _lastSIMErrorCode = mqttPublish(endpoint.c_str(), jsonPayload.c_str(), 1);
    }
    
    if (_lastSIMErrorCode != 0) {
        _lastSIMErrorCode = 14; // Logging error
    }
    
    return _lastSIMErrorCode;
}

// Explicit template instantiations for common types
template uint8_t SIM7600Wrapper::logValue<int16_t>(const String&, const String&, const String&, int16_t, const String&);
template uint8_t SIM7600Wrapper::logValue<int32_t>(const String&, const String&, const String&, int32_t, const String&);
template uint8_t SIM7600Wrapper::logValue<float>(const String&, const String&, const String&, float, const String&);
template uint8_t SIM7600Wrapper::logValue<String>(const String&, const String&, const String&, String, const String&);