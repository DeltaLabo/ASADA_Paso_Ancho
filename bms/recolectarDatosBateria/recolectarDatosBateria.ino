void setup() {
  Serial.begin(9600);
}

void loop() {
  pedidoUtil();
  delay(5000); 
}

void pedidoUtil()  {
  byte Datos[28];
  byte Pedido[7];

  Serial.println("\n #### LECTURA DE DATOS ÚTILES #### \n");

  Pedido[0] = 0xDD;
  Pedido[1] = 0xA5;
  Pedido[2] = 0x03;
  Pedido[3] = 0x00;
  Pedido[4] = 0xFF;
  Pedido[5] = 0xFD;
  Pedido[6] = 0x77;

  // Se piden los datos de la batería
  if (Serial.availableForWrite() > 7){
    Serial.write(Pedido, 7); // Envía los 7 bytes en una línea
  }
  else{
    Serial.print("No se pueden enviar los datos");
  }

  // Primeros 2 bytes siempre deberían ser DD 03
  for (int i = 0; i < 28; i++) {
    if (Serial.available() > 0){
      Datos[i] = Serial.read();
      Serial.print(Datos[i], HEX); // Imprime el byte en hexadecimal
      Serial.print(" ");
    }
    else{
      Serial.print(" No está disponible ");
      Serial.print(Serial.available());
    }
  }

  // Se comprueba que haya lectura
  if (Datos[0] != 0xDD || Datos[1] != 0x03) {
    Serial.println(" No se pudieron leer los datos generales ");
    return;
  }

  // Se lee el Status
  byte statusGeneral = Serial.read();
  Datos[2] = statusGeneral;
  Serial.print("Status: ");
  if (statusGeneral == 0x00) {
    Serial.println("OK");
  } else {
    Serial.println("FUCK");
  }

  // Se lee la longitud de los datos
  Serial.read();

  // Se lee el voltaje total de la batería
  byte vTotal[2];
  for (int i = 0; i < 2; i++) {
    while (!Serial.available()) {}
    vTotal[i] = Serial.read();
    Datos[3 + i] = vTotal[i];
  }

  // Se lee la corriente de la batería (se hace el tratamiento de signo)
  byte iTotal[2];
  for (int i = 0; i < 2; i++) {
    while (!Serial.available()) {}
    iTotal[i] = Serial.read();
    Datos[5 + i] = iTotal[i];
  }

  // Se leen los datos no utilizados
  for (int i = 0; i < 12; i++) {
    while (!Serial.available()) {}
    Serial.read(); // Descartar datos no utilizados
  }

  // Se lee el status de protección y se decodifica
  byte protectionStatus[2];
  for (int i = 0; i < 2; i++) {
    while (!Serial.available()) {}
    protectionStatus[i] = Serial.read();
    Datos[18 + i] = protectionStatus[i];
  }

  // Se lee la versión del software
  while (!Serial.available()) {}
  Serial.read(); // Descartar la versión del software

  // Se lee el porcentaje restante
  byte RSOC = Serial.read();
  Datos[20] = RSOC;

  // Se lee el funcionamiento de los MOSFET
  byte MOSFET = Serial.read();
  Datos[21] = MOSFET;

  // Se leen los datos no utilizados
  for (int i = 0; i < 2; i++) {
    while (!Serial.available()) {}
    Serial.read(); // Descartar datos no utilizados
  }

  // Se leen las temperaturas de los NTC
  for (int i = 0; i < 3; i++) {
    byte temp[2];
    for (int j = 0; j < 2; j++) {
      while (!Serial.available()) {}
      temp[j] = Serial.read();
      Datos[22 + (i * 2) + j] = temp[j];
    }
  }

  // Se leen los datos no utilizados
  for (int i = 0; i < 4; i++) {
    while (!Serial.available()) {}
    Serial.read(); // Descartar datos no utilizados
  }

  // SE EMPIEZA CON LA LECTURA DE TENSIONES

  // Se piden los datos de la batería
  Serial.write(0xDD);
  Serial.write(0xA5);
  Serial.write(0x04);
  Serial.write(0x00);
  Serial.write(0xFF);
  Serial.write(0xFC);
  Serial.write(0x77);

  // Primeros 2 bytes siempre deberían ser DD 04
  byte header[2];
  for (int i = 0; i < 2; i++) {
    while (!Serial.available()) {}
    header[i] = Serial.read();
  }

  // Se comprueba que haya una lectura
  if (header[0] != 0xDD || header[1] != 0x04) {
    Serial.println("No se pudo leer las tensiones de las celdas.");
    return;
  }

  // Se lee el Status
  while (!Serial.available()) {}
  Serial.read(); // Descartar el Status

  // Se lee la longitud de los datos
  while (!Serial.available()) {}
  Serial.read(); // Descartar la longitud de los datos

  // Se lee el voltaje de cada celda
  for (int i = 0; i < 4; i++) {
    byte VCelda[2];
    for (int j = 0; j < 2; j++) {
      while (!Serial.available()) {}
      VCelda[j] = Serial.read();
      Datos[24 + (i * 2) + j] = VCelda[j];
    }
  }

  // Se leen los datos no utilizados
  for (int i = 0; i < 4; i++) {
    while (!Serial.available()) {}
    Serial.read(); // Descartar datos no utilizados
  }

  // Calculamos el checksum
  uint16_t checksum = calcular_checksum(Datos);
  Datos[26] = (byte)(checksum >> 8); // Byte más significativo
  Datos[27] = (byte)(checksum & 0xFF); // Byte menos significativo

  // Enviamos los datos al monitor serie
  for (int i = 0; i < 28; i++) {
    Serial.print(Datos[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

uint16_t calcular_checksum(byte* datos) {
  uint32_t suma = 0;
  for (int i = 0; i < 27; i++) {
    suma += datos[i];
  }
  uint16_t checksum = (~suma) & 0xFFFF;
  return checksum;
}
