import serial
# import datetime
# import csv
# import time
import struct
# import numpy as np
# import matplotlib.pyplot as plt
# import string

# pub_flag = 0
# date = datetime.datetime.now()
# date_string = date.strftime("%d_%m_%y_%H_%M")
# file_name = "data_" + date_string + ".csv"
# print("Saving to: ",end='')
# print(file_name) 

ser = serial.Serial('COM8', baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=1.5)
ser.close()
ser.open()
ser.flush()


ser.write(b'\xDD\xA5\x03\x00\xFF\xFD\x77')
header = ser.read(2)
print('Header:',bytes.hex(header, ' '),end='\n')
status = int.from_bytes(ser.read(1), 'big')
print('Status:',end='')
if status == 0:
    print('OK',end='\n')
else:
    print('FUCK',end='\n')
length = int.from_bytes(ser.read(1), 'big')
print('Length:',length,end='\n')
vt = int.from_bytes(ser.read(2), 'big') / 100
print('vt: ', vt, 'V', end='\n')
it = int.from_bytes(ser.read(2), 'big')
print(it & 0x7FFF)
if (it>>15) == 1:
    it = 65536 - it
print('i: ', it, 'A', end='\n')

rest = ser.readline()
print(bytes.hex(rest, ' '),end='')

# start = b'\x00'
# prev = b'\x00'
# read = b'\x00'
# buffer = ''
# time.sleep(1)
# ser.write(b'n')
# ser.readline().decode() #discard it
# ser.write(b'\x1B')
# print(ser.readline().decode(),end='')
# answer = input("")
# if answer == 'y':
#       pub_flag = 1
# ser.write(answer.encode())
# #ser.write(b'n')
# data = []
# while True:
#       try:
#             ser.read_until(b'S').decode()
#             buffer = ser.read(5).decode()
#             speed = float(buffer)
#             status = ser.read(1).decode()
#             buffer = ser.read(5).decode()
#             pub_speed = float(buffer)
#             if pub_flag == 1:
#                   print(speed,end='\t')
#                   print(status,end='\t')
#                   print(pub_speed)
#             else:
#                   print(speed)
#             date = datetime.datetime.now()
#             time_stamp = date.strftime("%d/%m/%y %H:%M:%S")
#             #data.append([time_stamp, speed, status ,pub_speed])
#             with open(file_name,'a+',newline='') as f:
#                   writer = csv.writer(f, dialect='excel')
#                   if pub_flag == 1:
#                         writer.writerow([time_stamp, speed, status ,pub_speed])
#                   else:
#                        writer.writerow([time_stamp, speed])

#       except:
#             print("Keyboard Interrupt")
#             break

ser.close()