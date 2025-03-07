#ifndef SIM7600Wrapper_h
#define SIM7600Wrapper_h

#include <Arduino.h>
#include <map>
#include <vector>

// Minimum data threshold (in MB)
#define MIN_DATA 50.0

// Timeout constants
#define HTTP_TIMEOUT 20000
#define MQTT_TIMEOUT 10000

class SIM7600Wrapper {
  public:
    // Constructor
    SIM7600Wrapper(HardwareSerial& serial);
    
    // Basic modem functions
    void begin();
    uint8_t initialCheck();
    uint8_t checkSignal();
    
    // SMS functions
    uint8_t sendSMS(const char* phoneNumber, const char* message);
    void deleteAllSMS();
    uint8_t checkRemainingData(float* remainingDataOutput = nullptr, 
                              String* dataExpirationDateOutput = nullptr);
    
    // HTTP functions
    uint8_t httpInit();
    uint8_t httpSetURL(const char* url);
    uint8_t httpSetHeaders(const char* headers);
    uint8_t httpPost(const char* data, String* response = nullptr);
    uint8_t httpGet(String* response = nullptr);
    uint8_t httpTerminate();
    
    // MQTT functions
    uint8_t mqttInit(const char* clientID);
    uint8_t mqttConnect(const char* broker, int port, 
                        const char* username = nullptr, 
                        const char* password = nullptr);
    uint8_t mqttPublish(const char* topic, const char* message, int qos = 0);
    uint8_t mqttSubscribe(const char* topic, int qos = 0);
    uint8_t mqttDisconnect();
    
    // Generic value logging function
    template <typename T>
    uint8_t logValue(const String& service, const String& endpoint, 
                     const String& varName, T value, 
                     const String& unit = "");

    // Helper methods
    void PrintError(uint8_t errorCode, HardwareSerial &Serial);

  private:
    HardwareSerial& _serial;
    uint8_t _lastSIMErrorCode;
    std::map<int, const char*> errorCodeToName;
    char response[100];

    // Initialize error code mappings
    void InitMaps();
    
    // Send AT command and wait for response
    uint8_t sendATCommand(const char* ATcommand, 
                         const char* expected_answer, 
                         unsigned int timeout);
                         
    // JSON formatting helpers
    String createJSONPayload(const std::vector<std::pair<String, String>>& keyValues);
};

#endif