#ifndef DataLogger_h
#define DataLogger_h

#include <Arduino.h>
#include "../SIM7600Wrapper/SIM7600Wrapper.h"
#include <vector>
#include <map>

// Define log entry structure
struct LogEntry {
    String name;
    String value;
    String unit;
};

class DataLogger {
  public:
    DataLogger(SIM7600Wrapper& sim);
    
    // Configuration methods
    void setHTTPEndpoint(String url);
    void setMQTTBroker(String broker, int port, String clientID, 
                       String username = "", String password = "");
    void setMQTTTopic(String topic);
    
    // Add variables to be logged
    template <typename T>
    void addVariable(String name, T value, String unit = "");
    
    // Log data using the specified method
    uint8_t logToHTTP();
    uint8_t logToMQTT();
    
    // Clear all variables after logging
    void clearVariables();
    
  private:
    SIM7600Wrapper& _sim;
    String _httpURL;
    String _mqttBroker;
    int _mqttPort;
    String _mqttClientID;
    String _mqttUsername;
    String _mqttPassword;
    String _mqttBaseTopic;
    
    std::vector<LogEntry> _variables;
    
    // Convert all variables to JSON
    String createJSONPayload();
};

#endif