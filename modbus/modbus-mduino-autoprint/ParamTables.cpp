#include "ParamTables.h"

// Initialize all name-to-code maps
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

    // Format: (Modbus function code << 8) + Start Address
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

    errorCodeToName[0] = "No error";
    errorCodeToName[1] = "Illegal Modbus Function";
    errorCodeToName[2] = "Illegal Modbus Data Address";
    errorCodeToName[3] = "Illegal Modbus Data Value";
    errorCodeToName[4] = "Modbus Server Device Failure";
    errorCodeToName[5] = "Modbus Timeout";
    errorCodeToName[6] = "16-bit Overflow";
    errorCodeToName[7] = "16-bit Underflow";
    errorCodeToName[8] = "32-bit Overflow";
    errorCodeToName[9] = "32-bit Underflow";
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