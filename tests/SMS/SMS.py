import serial
import time

def AT(command):
    ser.write(command + b'\r\n')
    # Discard leading whitespace
    ser.read_until(expected=b'\r\n')
    response = ser.read_until(expected=b'\r\n')
    # Discard trailing whitespace
    response = response.rstrip()
    print(response)

# Open the serial port
ser = serial.Serial('COM50', 115200)

# Give the serial connection some time to establish
time.sleep(1)

# Query signal quality
#ser.write(b'AT+CSQ\r\n')

# Wait for a response
#time.sleep(0.3)

# Send text to specified phone number
#ser.write(b'AT+CMGS="+50683789714"\r')
#time.sleep(0.3)
# Text message
#ser.write(b"test")
#time.sleep(0.3)
#ser.write(b'\x1A')

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

# Consultar saldo
ser.write()

# Close the serial port
ser.close()
