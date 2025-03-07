#include "DataLogger.h"

DataLogger::DataLogger(SIM7600Wrapper& sim) : _sim(sim), _mqttPort(1883) {
    // Initialize with default values
}

void DataLogger::setHTTPEndpoint(String url) {
    _httpURL = url;
}

void DataLogger::setMQTTBroker(String broker, int port, String clientID, 
                              String username, String password) {
    _mqttBroker = broker;
    _mqttPort = port;
    _mqttClientID = clientID;
    _mqttUsername = username;
    _mqttPassword = password;
}

void DataLogger::setMQTTTopic(String topic) {
    _mqttBaseTopic = topic;
}

template <typename T>
void DataLogger::addVariable(String name, T value, String unit) {
    LogEntry entry;
    entry.name = name;
    entry.value = String(value);
    entry.unit = unit;
    
    _variables.push_back(entry);
}

String DataLogger::createJSONPayload() {
    String json = "{\"data\":[";
    
    for (size_t i = 0; i < _variables.size(); i++) {
        json += "{\"name\":\"" + _variables[i].name + "\",";
        json += "\"value\":\"" + _variables[i].value + "\",";
        json += "\"unit\":\"" + _variables[i].unit + "\"}";
        
        if (i < _variables.size() - 1) {
            json += ",";
        }
    }
    
    json += "],\"timestamp\":\"" + String(millis()) + "\"}";
    return json;
}

uint8_t DataLogger::logToHTTP() {
    uint8_t result = 0;
    
    if (_httpURL.length() == 0 || _variables.size() == 0) {
        return 14; // Logging error
    }
    
    // Initialize HTTP
    result = _sim.httpInit();
    if (result != 0) return result;
    
    // Set URL
    result = _sim.httpSetURL(_httpURL.c_str());
    if (result != 0) return result;
    
    // Set headers
    result = _sim.httpSetHeaders("Content-Type: application/json");
    if (result != 0) return result;
    
    // Create JSON payload
    String payload = createJSONPayload();
    
    // POST data
    result = _sim.httpPost(payload.c_str());
    
    // Terminate HTTP session
    _sim.httpTerminate();
    
    return result;
}

uint8_t DataLogger::logToMQTT() {
    uint8_t result = 0;
    
    if (_mqttBroker.length() == 0 || _mqttBaseTopic.length() == 0 || _variables.size() == 0) {
        return 14; // Logging error
    }
    
    // Initialize MQTT
    result = _sim.mqttInit(_mqttClientID.c_str());
    if (result != 0) return result;
    
    // Connect to broker
    if (_mqttUsername.length() > 0 && _mqttPassword.length() > 0) {
        result = _sim.mqttConnect(_mqttBroker.c_str(), _mqttPort, 
                                 _mqttUsername.c_str(), _mqttPassword.c_str());
    } else {
        result = _sim.mqttConnect(_mqttBroker.c_str(), _mqttPort, nullptr, nullptr);
    }
    
    if (result != 0) return result;
    
    // Create JSON payload for all variables
    String allDataJson = createJSONPayload();
    
    // Publish all data to base topic
    result = _sim.mqttPublish(_mqttBaseTopic.c_str(), allDataJson.c_str(), 1);
    
    // Also publish individual variables to separate topics
    if (result == 0) {
        for (const auto& var : _variables) {
            String individualTopic = _mqttBaseTopic + "/" + var.name;
            String individualPayload = "{\"value\":\"" + var.value + "\",\"unit\":\"" + var.unit + "\"}";
            
            result = _sim.mqttPublish(individualTopic.c_str(), individualPayload.c_str(), 0);
            if (result != 0) break;
        }
    }
    
    // Disconnect from broker
    _sim.mqttDisconnect();
    
    return result;
}

void DataLogger::clearVariables() {
    _variables.clear();
}

// Explicit template instantiations for common types
template void DataLogger::addVariable<int16_t>(String, int16_t, String);
template void DataLogger::addVariable<int32_t>(String, int32_t, String);
template void DataLogger::addVariable<float>(String, float, String);
template void DataLogger::addVariable<double>(String, double, String);
template void DataLogger::addVariable<String>(String, String, String);