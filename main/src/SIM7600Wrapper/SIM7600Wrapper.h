#ifndef __SIM7600Wrapper_H__
#define __SIM7600Wrapper_H__

/****** UART settings ******/
#define SIM_BAUDRATE 115200
// 8 bits, no parity, 1 stop bit
#define PARITY SERIAL_8N1

class SIMWrapper {
    public:
        // Initializer
        explicit SIMWrapper(HardwareSerial &modbusSerial);

        void CheckPower();
        void CheckSignal();

        uint32_t simBaudrate = MODBUS_BAUDRATE;

    private:
        Sim7x00 _sim7600;

        /****** Parameters for the SIM commands ******/
        // Storage variable for the AT command result code, which is also returned with each request
        uint8_t _lastSIMResultCode = 0;
};

#endif