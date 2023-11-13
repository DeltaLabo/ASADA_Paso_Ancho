import os
import serial
import csv
from datetime import datetime

# Especifica la ubicación del directorio para los archivos CSV
csv_directory = "C:\\Users\\ASQ\\OneDrive - Estudiantes ITCR\\Semestre 2-2023\\Delta"

# Abre un archivo CSV para guardar los datos
def open_csv_file():
    timestamp = datetime.now().strftime("%Y-%m-%d_%H")
    csv_filename = f"loradata_{timestamp}.csv"
    csv_file_path = os.path.join(csv_directory, csv_filename)

    with open(csv_file_path, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile, delimiter=",")
        column_names = ["Header", "Timestamp", "RSSI", "Voltaje", "Corriente", "%Restante"] + [f"Voltaje {i}" for i in range(1, 5)] + ["Tail"]
        csvwriter.writerow(column_names)  # Escribe los nombres de las columnas en la primera fila

    return csv_file_path

# Configura la comunicación serie
ser = serial.Serial('COM12', 115200)  # Ajusta el puerto y la velocidad según tu configuración

# Abre un archivo CSV para guardar los datos
current_csv_path = open_csv_file()

while True:
    try:
        data = ser.readline().decode().strip()
        if data:
            if data.startswith("RSSI: "):
                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")  # Current timestamp
                rssi = data.split(" ")[1]  # Extrae el valor RSSI
                data = ser.readline().decode().strip()  # Lee la siguiente línea para los datos hexadecimales
                hex_data = data.split(": ")[1]  # Extrae los datos hexadecimales
                hex_values = hex_data.split(",")[:100]
                header = hex_values[0] + hex_values[1].strip("0x")
                voltaje = int(hex_values[2] + hex_values[3].lstrip("0x").rjust(2, '0'),16) / 100
                current = int(hex_values[4] + hex_values[5].lstrip("0x").rjust(2, '0'),16) / 1000
                per = int(hex_values[6],16)
                voltaje1 = int(hex_values[7] + hex_values[8].lstrip("0x").rjust(2, '0'),16) / 1000
                voltaje2 = int(hex_values[9] + hex_values[10].lstrip("0x").rjust(2, '0'),16) / 1000
                voltaje3 = int(hex_values[11] + hex_values[12].lstrip("0x").rjust(2, '0'),16) / 1000
                voltaje4 = int(hex_values[13] + hex_values[14].lstrip("0x").rjust(2, '0'),16) / 1000
                tail = hex_values[-2] + hex_values[-1].strip("0x")
                # Combina RSSI y los valores hexadecimales en una sola lista
                row_data = [header]+[timestamp]+[rssi]+[voltaje]+[current]+[per]+[voltaje1]+[voltaje2]+[voltaje3]+[voltaje4]+[tail]

                # Se verifica si ya se cambió de hora
                new_hour = datetime.now().strftime("%H")
                if current_csv_path and not current_csv_path.endswith(f"{new_hour}.csv"):
                    current_csv_path = open_csv_file()

                with open(current_csv_path, 'a', newline='') as csvfile:
                    csvwriter = csv.writer(csvfile, delimiter=",")
                    csvwriter.writerow(row_data)
                print(f"Datos escritos en el archivo CSV: {row_data}")  # Imprime los datos en la consola

    except KeyboardInterrupt:
        break
    except Exception as e:
        print(f"Error: {e}")

print(f"Datos de LoRa guardados en {current_csv_path}")
