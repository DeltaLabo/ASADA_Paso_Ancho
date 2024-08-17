#include "ParamTables.h"

// Initialize all name-to-code mappings
// All codes were defined by Arad in the Octave Modbus memory map and are the same for all compatible meters
void OctaveModbusWrapper::InitMaps() {
    flowUnitNameToCode["Cubic Meters/Hour"] = 0;
    flowUnitNameToCode["Gallons/Minute"] = 1;
    flowUnitNameToCode["Litres/Second"] = 2;
    flowUnitNameToCode["Imperial Gallons/ Minute"] = 3;
    flowUnitNameToCode["Litres/Minute"] = 4;
    flowUnitNameToCode["Barrel/Minute"] = 5;

    // Code 0 is not implemented, according to the memory map
    resolutiontNameToCode["0.001x"] = 1;
    resolutiontNameToCode["0.01x"] = 2;
    resolutiontNameToCode["0.1x"] = 3;
    resolutiontNameToCode["1x"] = 4;
    resolutiontNameToCode["10x"] = 5;
    resolutiontNameToCode["100x"] = 6;
    resolutiontNameToCode["1000x"] = 7;
    resolutiontNameToCode["10000x"] = 8;

    volumeUnitNameToCode["Cubic Meters"] = 0;
    volumeUnitNameToCode["Cubic Feet"] = 1;
    volumeUnitNameToCode["Cubic Inch"] = 2;
    volumeUnitNameToCode["Cubic Yards"] = 3;
    volumeUnitNameToCode["US Gallons"] = 4;
    volumeUnitNameToCode["Imperial Gallons"] = 5;
    volumeUnitNameToCode["Acre Feet"] = 6;
    volumeUnitNameToCode["Kiloliters"] = 7;
    volumeUnitNameToCode["Liters"] = 8;
    volumeUnitNameToCode["Acre-inch"] = 9;
    volumeUnitNameToCode["Barrel"] = 10;

    // Not all codes are implemented, according to the memory map
    alarmCodeToName[0] = "Leakage";
    alarmCodeToName[5] = "Measurement Fail";
    alarmCodeToName[7] = "Octave Battery";
    alarmCodeToName[11] = "Flow Rate Cut Off";
    alarmCodeToName[12] = "Module battery";
    alarmCodeToName[13] = "Water meter-Module communication error";

    temperatureUnitNameToCode["Not Active"] = 0;
    temperatureUnitNameToCode["Celsius"] = 1;
    temperatureUnitNameToCode["Fahrenheit"] = 2;

    flowDirectionNameToCode["No flow"] = 0;
    flowDirectionNameToCode["Forward flow"] = 1;
    flowDirectionNameToCode["Backward flow"] = 2;

    // Format: (Modbus function code << 8) + Start memory address
    // The function codes are 04 for Read Input Registers and
    // 06 for Write Single Register
    functionNameToCode["ReadAlarms"] = 0x0400;
    functionNameToCode["SerialNumber"] = 0x0401;
    functionNameToCode["ReadWeekday"] = 0x0411;
    functionNameToCode["ReadDay"] = 0x0412;
    functionNameToCode["ReadMonth"] = 0x0413;
    functionNameToCode["ReadYear"] = 0x0414;
    functionNameToCode["ReadHours"] = 0x0415;
    functionNameToCode["ReadMinutes"] = 0x0416;
    functionNameToCode["VolumeUnit"] = 0x0417;
    functionNameToCode["ForwardVolume_32"] = 0x0436;
    functionNameToCode["ForwardVolume_64"] = 0x0418;
    functionNameToCode["ReverseVolume_32"] = 0x043A;
    functionNameToCode["ReverseVolume_64"] = 0x0420;
    functionNameToCode["ReadVolumeResIndex"] = 0x0428;
    functionNameToCode["SignedCurrentFlow_32"] = 0x043E;
    functionNameToCode["SignedCurrentFlow_64"] = 0x0429;
    functionNameToCode["ReadFlowResIndex"] = 0x0431;
    functionNameToCode["FlowUnit"] = 0x0432;
    functionNameToCode["FlowDirection"] = 0x0433;
    functionNameToCode["TemperatureValue"] = 0x0434;
    functionNameToCode["TemperatureUnit"] = 0x0435;
    functionNameToCode["NetSignedVolume_32"] = 0x0452;
    functionNameToCode["NetSignedVolume_64"] = 0x0442;
    functionNameToCode["NetUnsignedVolume_32"] = 0x0456;
    functionNameToCode["NetUnsignedVolume_64"] = 0x044A;
    functionNameToCode["SystemReset"] = 0x0600;
    functionNameToCode["WriteWeekday"] = 0x0601;
    functionNameToCode["WriteDay"] = 0x0602;
    functionNameToCode["WriteMonth"] = 0x0603;
    functionNameToCode["WriteYear"] = 0x0604;
    functionNameToCode["WriteHours"] = 0x0605;
    functionNameToCode["WriteMinutes"] = 0x0606;
    functionNameToCode["WriteVolumeResIndex"] = 0x0607;
    functionNameToCode["WriteFlowResIndex"] = 0x0608;

    // Modbus error codes
    errorCodeToName[0] = "No error";
    errorCodeToName[1] = "Illegal Modbus Function";
    errorCodeToName[2] = "Illegal Modbus Data Address";
    errorCodeToName[3] = "Illegal Modbus Data Value";
    errorCodeToName[4] = "Modbus Server Device Failure";
    errorCodeToName[5] = "Modbus Timeout";
    // Number compression error codes
    errorCodeToName[6] = "16-bit Overflow";
    errorCodeToName[7] = "16-bit Underflow";
    errorCodeToName[8] = "32-bit Overflow";
    errorCodeToName[9] = "32-bit Underflow";
    // Modbus error code
    errorCodeToName[10] = "Invalid Resolution Index";

    // Create the reverse mappings
    for (const auto& entry : flowUnitNameToCode) {
        flowUnitCodeToName[entry.second] = entry.first;
    }
    for (const auto& entry : volumeUnitNameToCode) {
        volumeUnitCodeToName[entry.second] = entry.first;
    }
    for (const auto& entry : temperatureUnitNameToCode) {
        temperatureUnitCodeToName[entry.second] = entry.first;
    }
    for (const auto& entry : flowDirectionNameToCode) {
        flowDirectionCodeToName[entry.second] = entry.first;
    }
    for (const auto& entry : resolutiontNameToCode) {
        resolutionCodeToName[entry.second] = entry.first;
    }
    for (const auto& entry : functionNameToCode) {
        functionCodeToName[entry.second] = entry.first;
    }
}


/****** Utilities ******/

// Convert to ASCII and print the Octave Serial Number
void OctaveModbusWrapper::PrintSerial(int16_t registers[16], HardwareSerial &Serial) {
    // Loop through the response and print each register
    for (int i = 0; i < 16; i++){
        // Only print printable characters (indices 48-57 of the ASCII table)
        if (registers[i] >= 48 && registers[i] <= 57)
        {
          // Convert the ASCII code to a char
          Serial.print(char(registers[i]));
        }
    }
    Serial.println();
}

// Interpret and print Octave Alarms
void OctaveModbusWrapper::PrintAlarms(int16_t alarms, HardwareSerial &Serial) {
    // Leave space for the interpretation
    Serial.print(": ");
    if (alarms == 0) Serial.println(alarmCodeToName[0]);
    else{
        // Bit-wise error check
        for (int j = 0; j < sizeof(alarmsIndices) / sizeof(alarmsIndices[0]); j++) {
            // If the (j+1)-th bit is set, print the corresponding error message
            // That is, the error codes correspond to the bit indices that are set to 1
            if ((alarms & (1 << alarmsIndices[j])) != 0) {
                Serial.print(alarmCodeToName[alarmsIndices[j]]);
                Serial.print(" ");
            }
        }
        Serial.println();
    }
}

// Print a 64-bit double number
void OctaveModbusWrapper::PrintDouble(float64_t &number, HardwareSerial &Serial) {
    // char *fp64_to_string(float64_t x, uint8_t max_chars, uint8_t max_zeroes)
    Serial.println(fp64_to_string(number, 12, 1));
}

// Interpret and print an Octave error code
void OctaveModbusWrapper::PrintError(uint8_t errorCode, HardwareSerial &Serial) {
    // Print the error code and its meaning
    Serial.print("Error code ");
    Serial.print(errorCode);
    Serial.print(": ");
    Serial.println(errorCodeToName[errorCode]);
}

// Interpret the result of a Modbus request from its error code and print it to a Serial
// Returns the error code for convenience
// The rest of the parameters needed to interpret the result are stored in the OctaveModbusWrapper object
uint8_t OctaveModbusWrapper::InterpretResult(uint8_t errorCode, HardwareSerial &Serial) {
    // Print the function name
    Serial.print(functionCodeToName[lastUsedFunctionCode]);
    Serial.print(": ");
    // If there was an error, print it
    if (errorCode != 0) PrintError(errorCode, Serial);
    else {
        // If it was a write request, just print that it's done
        if (_numRegisterstoRead == 0) Serial.println("Done writing");
        // For read requests, print the received value
        else {
            // 32- and 64-bit values don't need to be interpreted, just print them
            if (_signedResponseSizeinBits == 32) Serial.println(uint32Buffer);
            else if (_signedResponseSizeinBits == -32) Serial.println(int32Buffer);
            else if (_signedResponseSizeinBits == -64) PrintDouble(doubleBuffer, Serial);
            // Interpret the value if it's 16-bits
            else {
                // If there is more than 1 int16 value, it means that we're reading the Serial
                if (_numRegisterstoRead > 1) PrintSerial(int16Buffer, Serial);
                // If only 1 int16 was requested
                else {
                    // Print the value
                    Serial.print(int16Buffer[0]);

                    // Print value interpretation for the functions that require it
                    if (lastUsedFunctionCode == functionNameToCode["VolumeUnit"]){
                        // Leave space for the interpretation
                        Serial.print(": ");
                        Serial.println(volumeUnitCodeToName[int16Buffer[0]]);
                    }
                    else if (lastUsedFunctionCode == functionNameToCode["FlowUnit"]){
                        // Leave space for the interpretation
                        Serial.print(": ");
                        Serial.println(flowUnitCodeToName[int16Buffer[0]]);
                    }
                    else if ((lastUsedFunctionCode == functionNameToCode["ReadVolumeResIndex"]) || (lastUsedFunctionCode == functionNameToCode["ReadFlowResIndex"])){
                        // Leave space for the interpretation
                        Serial.print(": ");
                        Serial.println(resolutionCodeToName[int16Buffer[0]]);
                    }
                    else if (lastUsedFunctionCode == functionNameToCode["TemperatureUnit"]){
                        // Leave space for the interpretation
                        Serial.print(": ");
                        Serial.println(temperatureUnitCodeToName[int16Buffer[0]]);
                    }
                    else if (lastUsedFunctionCode == functionNameToCode["FlowDirection"]){
                        // Leave space for the interpretation
                        Serial.print(": ");
                        Serial.println(flowDirectionCodeToName[int16Buffer[0]]);
                    }
                    else if (lastUsedFunctionCode == functionNameToCode["ReadAlarms"]){
                        PrintAlarms(int16Buffer[0], Serial);
                    }
                    else Serial.println();  
                }
            }
        }
    }

    // Return the error code for convenience
    return errorCode;
}