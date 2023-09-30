import tkinter as tk
import struct
from math import ceil

def convert_number():
    try:
        # Get the input number
        input_number = entry.get()

        # Convert the input number to an integer based on the selected type
        if input_type.get() == "dec":
            input_number = int(input_number)
        elif input_type.get() == "hex":
            input_number = int(input_number, 16)
        else:
            raise ValueError("Invalid input base")

        # Convert the number to the desired type
        if output_type.get() == "dec":
            result = str(input_number)
        elif output_type.get() == "hex":
            result = hex(input_number).upper()  # Convert to hex and capitalize letters
        elif output_type.get() == "double":
            # Pack the integer into bytes (assuming it's a 64-bit integer)
            packed_bytes = struct.pack('>Q', input_number)

            # Unpack the bytes as a double
            resulting_double = struct.unpack('>d', packed_bytes)[0]
            result = str(resulting_double)
        elif output_type.get() == "int16":
            # Pack the integer into bytes (assuming it's a 16-bit integer)
            packed_bytes = input_number.to_bytes(length=2, byteorder="big", signed=False)

            # Unpack the bytes as an int16
            resulting_number = int.from_bytes(packed_bytes, byteorder="big", signed=True)
            result = str(resulting_number)
        elif output_type.get() == "int32":
            # Pack the integer into bytes (assuming it's a 32-bit integer)
            packed_bytes = struct.pack('>L', input_number)

            # Unpack the bytes as an int32
            resulting_number = struct.unpack('>l', packed_bytes)[0]
            result = str(resulting_number)
        elif output_type.get() == "crc":
            # Pack the integer into bytes
            packed_bytes = input_number.to_bytes(length=ceil(input_number.bit_length()/8), byteorder="big", signed=False)

            # Compute the CRC for the byte array
            crc = 0xFFFF

            for byte in packed_bytes:
                crc ^= byte
                for _ in range(8):
                    if crc & 1:
                        crc = (crc >> 1) ^ 0xA001
                    else:
                        crc >>= 1

            crc = ((crc >> 8) & 0xFF) | ((crc << 8) & 0xFF00)

            # Convert the resulting CRC to hex
            result = hex(crc).upper()
        else:
            raise ValueError("Invalid output base")

        # Update the result Text widget
        result_text.config(state=tk.NORMAL)
        result_text.delete(1.0, tk.END)
        result_text.insert(tk.END, result)
        result_text.config(state=tk.DISABLED)

    except ValueError as e:
        result_text.config(state=tk.NORMAL)
        result_text.delete(1.0, tk.END)
        result_text.insert(tk.END, str(e))
        result_text.config(state=tk.DISABLED)

# Create the main window
window = tk.Tk()
window.title("Number Converter")

# Entry widget for the user to input a number
entry_label = tk.Label(window, text="Enter a number:")
entry_label.pack()

entry = tk.Entry(window)
entry.pack()

# Radio buttons for selecting input and output types
input_type_label = tk.Label(window, text="Select input type:")
input_type_label.pack()

input_type = tk.StringVar()
input_type.set("dec")

input_type_dec = tk.Radiobutton(window, text="Decimal", variable=input_type, value="dec")
input_type_hex = tk.Radiobutton(window, text="Hex", variable=input_type, value="hex")

input_type_dec.pack()
input_type_hex.pack()

# Result label
result_label = tk.Label(window, text="Result:")
result_label.pack()

# Text widget to display the converted number
result_text = tk.Text(window, height=1, width=15, state=tk.DISABLED)
result_text.pack()

# Radio buttons for selecting output type
output_type_label = tk.Label(window, text="Select output type:")
output_type_label.pack()

output_type = tk.StringVar()
output_type.set("dec")

output_type_dec = tk.Radiobutton(window, text="Decimal", variable=output_type, value="dec")
output_type_hex = tk.Radiobutton(window, text="Hex", variable=output_type, value="hex")
output_type_double = tk.Radiobutton(window, text="Double", variable=output_type, value="double")
output_type_int16 = tk.Radiobutton(window, text="int16", variable=output_type, value="int16")
output_type_int32 = tk.Radiobutton(window, text="int32", variable=output_type, value="int32")
output_type_crc = tk.Radiobutton(window, text="CRC (hex)", variable=output_type, value="crc")

output_type_dec.pack()
output_type_hex.pack()
output_type_double.pack()
output_type_int16.pack()
output_type_int32.pack()
output_type_crc.pack()

# Button to perform the conversion
convert_button = tk.Button(window, text="Convert", command=convert_number)
convert_button.pack()

# Start the main loop
window.mainloop()
