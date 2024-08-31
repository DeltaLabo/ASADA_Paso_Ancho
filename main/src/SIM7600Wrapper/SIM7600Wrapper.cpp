#include "SIM7600Wrapper.h"


// Initialize Serial interface used for Modbus communication
SIMWrapper::SIMWrapper(HardwareSerial &simSerial) : _master(modbusSerial){}

void checkSIM7600() {
    uint8_t result = 0;
    result = sim7600.sendATcommand("AT", "OK", 1000);

    return 
}

void deleteAllSMS() {
    sim7600
}