import pandas as pd
import requests
import time

# Lee la tabla de Excel
df = pd.read_excel('lora_receiver\\loradata_2023-11-13_Descarga.xlsx')

# Define tu API Key de ThingSpeak
api_key = 'R42USYBGS6QQDP6E'

# Define el URL de la API de ThingSpeak
url = f'https://api.thingspeak.com/update?api_key={api_key}'

# Itera a través de las filas del DataFrame y envía los datos a ThingSpeak
for index, row in df.iterrows():
    # Saltar los indices que ya fueron enviados
    if index < 0:
        continue

    timestamp = row['Timestamp']  # Cambia 'timestamp_column' al nombre de tu columna de timestamp
    caudal = row['Caudal']  # Cambia 'medicion_column' al nombre de tu columna de medicion
    voltaje = row['Voltaje']
    altura = row['Altura']
    restante = row['%Restante']
    volumen = row['Volumen']
    celda = row['Voltaje 1']
    rssi = row['RSSI']

    print(f'Dato {index}')
    # Construye los parámetros del POST request
    payload = {
        'field1': voltaje,
        'field2': celda,
        'field3': caudal,
        'field4': volumen,
        'field5': altura,
        'field6': rssi,
        'created_at': timestamp
    }
    
    # Envía los datos a ThingSpeak
    response = requests.post(url, params=payload)

    # Imprime la respuesta del servidor (opcional)
    print(response)

    time.sleep(15)