import serial

ser = serial.Serial('COM10', baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=1.5)
ser.close()
ser.open()
ser.flush()

# Se piden los datos de la batería
ser.write(b'\xDD\xA5\x03\x00\xFF\xFD\x77')

# Primeros 4 bytes siempre deberían ser DD 03
header = ser.read(2)
print('Header:',bytes.hex(header, ' '),end='\n')

# Se lee el Status
status = int.from_bytes(ser.read(1), 'big')
print('Status: ',end='')
if status == 0:
    print('OK',end='\n')
else:
    print('FUCK',end='\n')

# Se lee la longitud de los datos
length = int.from_bytes(ser.read(1), 'big')
print('Length:',length,end='\n')

# Se lee el voltaje total de la batería
vt = int.from_bytes(ser.read(2), 'big') / 100
print('vt: ', vt, 'V', end='\n')

# Se lee la corriente de la batería (se hace el tratamiento de signo)
it = int.from_bytes(ser.read(2), 'big')
if ((it>>15) == 1):
    it = (65536 - it) / 100
else:
    it = it / 100
print('i: ', it, 'A', end='\n')

# Se lee la capacidad restante
remainingCapacity = int.from_bytes(ser.read(2), 'big') / 100
print('Remaining Capacity: ', remainingCapacity, 'Ah', end='\n')

# Se lee la capacidad nominal
nominalCapacity = int.from_bytes(ser.read(2), 'big') / 100
print('Nominal Capacity: ', nominalCapacity, 'Ah', end='\n')

# Se leen los ciclos que ha trabajado el controlador
cycles = int.from_bytes(ser.read(2), 'big')
print('Número de ciclos trabajados: ', cycles, end='\n')

# Se lee la fecha de producción y se le hace el tratamiento correspondiente
productionDate = int.from_bytes(ser.read(2), 'big')
dia = (productionDate & 0x1f)
mes = (productionDate>>5)&0x0f
anno = 2000+ (productionDate>>9)
print('Producido el: ', dia, '/', mes, '/', anno, end='\n')

# Se lee el equilibrio
equilibrium = int.from_bytes(ser.read(2), 'big')
print('Equilibrio: ', equilibrium, end='\n')

# Se lee el equilibrio en alto
equilibriumHigh = int.from_bytes(ser.read(2), 'big')
print('Equilibrio en alto: ', equilibrium, end='\n')

# Se lee el status de protección y se decodifica
protectionStatus = int.from_bytes(ser.read(2), 'big')

protection_info = {
    "Monomer Overvoltage Protection": bool(protectionStatus & 0b00000001),
    "Monomer Undervoltage Protection": bool(protectionStatus & 0b00000010),
    "Whole Group Overvoltage Protection": bool(protectionStatus & 0b00000100),
    "Whole Group Undervoltage Protection": bool(protectionStatus & 0b00001000),
    "Charging Over Temperature Protection": bool(protectionStatus & 0b00010000),
    "Charging Low Temperature Protection": bool(protectionStatus & 0b00100000),
    "Discharge Over Temperature Protection": bool(protectionStatus & 0b01000000),
    "Discharge Low Temperature Protection": bool(protectionStatus & 0b10000000),
    "Charging Overcurrent Protection": bool(protectionStatus & 0b00000001000),
    "Discharge Overcurrent Protection": bool(protectionStatus & 0b00000010000),
    "Short Circuit Protection": bool(protectionStatus & 0b00000100000),
    "Front-end Detection IC Error": bool(protectionStatus & 0b00001000000),
    "Software Lock MOS": bool(protectionStatus & 0b00010000000),}

active_protections = [key for key, value in protection_info.items() if value]

if active_protections:
    print('Protecciones activadas:', protectionStatus, ', '.join(active_protections))
else:
    print('No hay protecciones activadas UwU')

# Se lee la versión del software
softwareVersion = int.from_bytes(ser.read(1), 'big')
print('Versión del software: ', softwareVersion, end='\n')

# Se lee el porcentaje restante
RSOC = int.from_bytes(ser.read(1), 'big')
print('Porcentaje restante: ', RSOC, "%", end='\n')

# Se lee el funcionamiento de los MOSFET
MOSFET = int.from_bytes(ser.read(1), 'big')
if (MOSFET == 0):
    print('No hay MOSFET activos', end='\n')
elif (MOSFET == 1):
    print('Solo el MOSFET de carga está activo', end='\n')
elif (MOSFET == 2):
    print('Solo el MOSFET de descarga está activo', end='\n')
elif (MOSFET == 3):
    print('Ambos MOSFET están activos (carga y descarga)', end='\n')

# Se lee el número de celdas en serie
celdasSerie = int.from_bytes(ser.read(1), 'big')
print('Baterías en serie: ', celdasSerie, end='\n')

# Se lee el número de NTC
NTC = int.from_bytes(ser.read(1), 'big')
print('Número de sensores NTC: ', NTC, end='\n')

# Se leen las temperaturas de los NTC
for i in range(1, NTC + 1):
    NTCT = (int.from_bytes(ser.read(2), 'big')-2731) / 10
    print('- Temperatura del NTC', str(i) + ":", NTCT, "C", end='\n')

# Se lee el checksum
checksum = int.from_bytes(ser.read(2), 'big')
print('Checksum: ', checksum, end='\n')

# Se leen los bytes de final (debería ser 0x77)
rest = ser.readline()
print("End bytes: ",bytes.hex(rest, ' '),end='')

ser.close()