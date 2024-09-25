import serial
import time

# Open the serial port
ser = serial.Serial('COM50', 115200, timeout=1)

# Give the serial connection some time to establish
time.sleep(1)

# Query signal quality
#ser.write(b'AT+CSQ\r\n')

# Wait for a response
#time.sleep(0.3)

# Send text to specified phone number
ser.write(b'AT+CMGS="606"\r')
time.sleep(0.3)
# Text message
ser.write(b"SALDO\x1A")
time.sleep(0.3)
print(ser.read_until(expected=b'OK\r\n'))

ser.write(b'AT+CMGF=1\r\n')
time.sleep(0.3)
print(ser.read_until(expected=b'OK\r\n'))
ser.write(b'AT+CMGR=0\r\n')
time.sleep(10)

print(ser.read_until(expected=b'OK\r\n'))

"""
# Start HTTP service
ser.write(b'AT+HTTPINIT\r\n')
ser.read_until(expected=b'\r\n')
print(ser.read_until(expected=b'\r\n'))
# Set HTTPS target
ser.write(b'AT+HTTPPARA="URL","')
ser.write(b'https://api.thingspeak.com/update?api_key=8YAXPYOSK23SSHOZ&field1=0')
ser.write(b'"\r\n')
ser.read_until(expected=b'\r\n')
print(ser.read_until(expected=b'\r\n'))
# GET Request
ser.write(b'AT+HTTPACTION=0\r\n')
ser.read_until(expected=b'\r\n')
print(ser.read_until(expected=b'\r\n'))
# Read HTTPS response
ser.write(b'AT+HTTPREAD=50\r\n')
ser.read_until(expected=b'\r\n')
print(ser.read_until(expected=b'\r\n'))
"""

# Close the serial port
ser.close()
