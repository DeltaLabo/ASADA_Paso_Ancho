import serial

def pedidoGeneral():
    print("\n #### DATOS GENERALES DE LA BATERÍA #### \n")
    
    ser = serial.Serial('COM10', baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=1.5)
    ser.close()
    ser.open()
    ser.flush()

    # Se piden los datos de la batería
    ser.write(b'\xDD\xA5\x03\x00\xFF\xFD\x77')

    # Primeros 4 bytes siempre deberían ser DD 03
    header = ser.read(2)

    # Se comprueba que haya lectura
    if header!=b'\xdd\x03':
        print("No se pudieron leer los datos generales")
        return()
        
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
    
def pedidoCeldas():
    print("\n #### TENSIÓN DE LAS CELDAS #### \n")
    ser = serial.Serial('COM10', baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=1.5)
    ser.close()
    ser.open()
    ser.flush()
    
    # Se piden los datos de la batería
    ser.write(b'\xDD\xA5\x04\x00\xFF\xFC\x77')
    
    # Primeros 4 bytes siempre deberían ser DD 04
    header = ser.read(2)

    # Se comprueba que haya una lectura
    if header!=b'\xdd\x04':
        print("No se pudo leer las tensiones de las celdas.")
        return()
    
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
    
    # Se lee el voltaje de cada celda
    vCelda=[]
    for i in range(1, 4 + 1):
        vCelda.append((int.from_bytes(ser.read(2), 'big')) / 1000)
        print('- La tensión de la celda ', str(i) + "es de: ", vCelda[i-1], "V", end='\n')
    
    # Se lee el checksum
    checksum = int.from_bytes(ser.read(2), 'big')
    print('Checksum: ', checksum, end='\n')

    # Se leen los bytes de final (debería ser 0x77)
    rest = ser.readline()
    print(bytes.hex(rest, ' '),end='')
    
    ser.close()

def instruccionMOS():
    print("\n###      INSTRUCCIONES PARA LOS CANELES MOS       ###")
    print("### 1-  El software libera la acción sobre el MOS ###")
    print("### 2-  Se apaga el MOS de carga y luego descarga ###")
    print("### 3-  Se apaga el MOS de descarga y luego carga ###")
    print("### 4-  Se apagan ambos MOS al mismo tiempo       ###")
    modo = input("Ingrese el modo deseado: ")
    if modo==1:
        XX = b"\x00"
        # ser = serial.Serial('COM10', baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=1.5)
        # ser.close()
        # ser.open()
        # ser.flush()

        # Se envía la instrucción
        # ser.write(b'\xDD\x5A\xE1\x02\xXX\xCHECKSUM\x77')
    elif modo==2:
        XX = b"\x01"
    elif modo==3:
        XX = b"\x02"
    elif modo==4:
        XX = b"\x03"
    else:
        print("El modo de instruccion ingresado no es válido.")

def pedidoUtil():
    Datos=[]
    Datos.append(b"\xdd")
    Datos.append(b"\x07")
    print("\n #### LECTURA DE DATOS ÚTILES #### \n")
    
    ser = serial.Serial('COM10', baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=1.5)
    ser.close()
    ser.open()
    ser.flush()

    # Se piden los datos de la batería
    ser.write(b'\xDD\xA5\x03\x00\xFF\xFD\x77')

    # Primeros 4 bytes siempre deberían ser DD 03
    header = ser.read(2)

    # Se comprueba que haya lectura
    if header!=b'\xdd\x03':
        print("No se pudieron leer los datos generales")
        return()

    # Se lee el Status
    statusGeneral = ser.read(1)
    Datos.append(statusGeneral)
    print('Status: ',end='')
    if (statusGeneral == b"\x00"):
        print('OK',end='\n')
    else:
        print('FUCK',end='\n')

    # Se lee la longitud de los datos
    ser.read(1)

    # Se lee el voltaje total de la batería
    vTotal = ser.read(2) #UNIDAD = 10mV = Hay que dividirlo entre 100
    Datos.append(vTotal)

    # Se lee la corriente de la batería (se hace el tratamiento de signo)
    iTotal = ser.read(2) #UNIDAD = 10mAh = Hay que dividirlo entre 100 #EL MSB ES DE SIGNO (COMPLEMENTO 2)
    Datos.append(iTotal)

    # Se lee la capacidad restante
    ser.read(2) # UNIDAD = 10mAh = Hay que dividirlo entre 100
    # Se lee la capacidad nominal
    ser.read(2)
    # Se leen los ciclos que ha trabajado el controlador
    ser.read(2)
    # Se lee la fecha de producción
    ser.read(2)
    # Se lee el equilibrio
    ser.read(2)
    # Se lee el equilibrio en alto
    ser.read(2)

    # Se lee el status de protección y se decodifica
    protectionStatus = ser.read(2)
    Datos.append(protectionStatus)

    # Se lee la versión del software
    ser.read(1)

    # Se lee el porcentaje restante
    RSOC = ser.read(1)
    Datos.append(RSOC)

    # Se lee el funcionamiento de los MOSFET
    MOSFET = ser.read(1)
    Datos.append(MOSFET)
    
    # Se lee el número de celdas en serie
    ser.read(1)
    # Se lee el número de NTC
    ser.read(1)

    # Se leen las temperaturas de los NTC
    for i in range(0, 3):
        Datos.append(ser.read(2)) #UNIDAD = 0,1K = hay que restarle 2731 y dividir entre 10 para C

    # Se lee el checksum
    ser.read(2)
    # Se leen los bytes de final (debería ser 0x77)
    ser.readline()
    ser.close()

    # SE EMPIEZA CON LA LECTURA DE TENSIONES

    ser.open()
    ser.flush()
    
    # Se piden los datos de la batería
    ser.write(b'\xDD\xA5\x04\x00\xFF\xFC\x77')
    
    # Primeros 4 bytes siempre deberían ser DD 04
    header = ser.read(2)

    # Se comprueba que haya una lectura
    if header!=b'\xdd\x04':
        print("No se pudo leer las tensiones de las celdas.")
        return()
    
    # Se lee el Status
    ser.read(1)
    # Se lee la longitud de los datos
    ser.read(1)
    
    # Se lee el voltaje de cada celda
    for i in range(0, 4):
        Datos.append(ser.read(2)) # UNIDAD = 1mV = Hay que dividir entre 1000 para V
    
    # Se lee el checksum
    ser.read(2)
    # Se leen los bytes de final (debería ser 0x77)
    ser.readline()    
    ser.close()
    return(Datos)
    
def calcular_checksum(datos):
    suma = 0
    for byte in datos:
        suma += int.from_bytes(byte)
    checksum = (~suma) & 0xFFFF
    checksum_bytes = checksum.to_bytes(2, byteorder='big')
    checksum_hex = checksum_bytes.hex()
    return bytes.fromhex(checksum_hex)

def main():
    #pedidoGeneral()
    #pedidoCeldas()
    #instruccionMOS()
    
    # ESTRUCTURA DE LOS DATOS
    # HEADER = 2 bytes = \xdd \x07
    # STATUS = 1 bytes = \x00 cuando está bien
    # vTotal = 2 bytes = unidad de 10mV
    # iTotal = 2 bytes = unidad de 10mAh con el bit 15 de signo (negativos en complemento a 2)
    # protectionStatus = 2 bytes = \x00 \x00 cuando todo está bien
    # RSOC = 1 bytes = unidad de 1%
    # MOSFET = 1 bytes = mosfet activos
    # Temp1 = 2 bytes = unidad de 0,1K
    # Temp2 = 2 bytes = unidad de 0,1K
    # Temp3 = 2 bytes = unidad de 0,1K
    # VCelda1 = 2 bytes = unidad de 1mV
    # VCelda2 = 2 bytes = unidad de 1mV
    # VCelda3 = 2 bytes = unidad de 1mV
    # VCelda4 = 2 bytes = unidad de 1mV
    # ByteFinal = 1 bytes = b"\x77"
    # Checksum = 2 bytes
    # TOTAL = 28 BYTES

    Datos=[]
    Datos=pedidoUtil()
    checksum = calcular_checksum(Datos)
    Datos=list(Datos)
    Datos.append(checksum)
    Datos.append(b"\x77")
    for dato in Datos:
        print(bytes.hex(dato))

main()