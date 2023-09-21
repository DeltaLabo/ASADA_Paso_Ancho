void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  pedidoUtil();
  delay(5000); 
}

void pedidoUtil()  {
  int i=0;
  byte DatosUtiles[28];
  byte DatosGeneral[200];//32
  byte DatosCeldas[200];//10
  byte PedidoGeneral[7] = {0xDD, 0xA5, 0x03, 0x00, 0xFF, 0xFD, 0x77};
  byte PedidoCeldas[7] = {0xDD, 0xA5, 0x04, 0x00, 0xFF, 0xFC, 0x77};

  Serial.println("#### LECTURA DE DATOS ÚTILES ####");

  Serial1.write(PedidoGeneral, sizeof(PedidoGeneral));
  //Serial.write(PedidoGeneral, sizeof(PedidoGeneral));
  if(Serial1.available() > 0){
    Serial1.readBytesUntil(0x77, DatosGeneral, 200);
    Serial.print("Datos Generales: ");
    for(i=0; i<sizeof(DatosGeneral); i++){
      if(DatosGeneral[i] < 16) Serial.print("0");
      Serial.print(DatosGeneral[i],HEX);
      Serial.print(" ");
    }
    Serial.println(" ");
  }

  Serial1.write(PedidoCeldas, sizeof(PedidoCeldas));
  //Serial.write(PedidoCeldas, sizeof(PedidoCeldas));
  if(Serial1.available() > 0){
    Serial1.readBytesUntil(0x77, DatosCeldas, 200);
    Serial.print("Datos de Celda: ");
    for(i=0; i<sizeof(DatosCeldas); i++){
      if(DatosCeldas[i] < 16) Serial.print("0");
      Serial.print(DatosCeldas[i],HEX);
      Serial.print(" ");
    }
    Serial.println(" ");
  }

  Serial.print("Datos seleccionados para transmisión: ");
  //Status
  DatosUtiles[0]=DatosGeneral[2];
  //Voltaje Actual
  DatosUtiles[1]=DatosGeneral[4];
  DatosUtiles[2]=DatosGeneral[5];
  //Corriente Actual
  DatosUtiles[3]=DatosGeneral[6];
  DatosUtiles[4]=DatosGeneral[7];
  //Protection Status
  DatosUtiles[5]=DatosGeneral[17];
  DatosUtiles[6]=DatosGeneral[18];

  for(i=0; i<sizeof(DatosUtiles); i++){
      if(DatosUtiles[i] < 16) Serial.print("0");
      Serial.print(DatosUtiles[i],HEX);
      Serial.print(" ");
    }
  Serial.println(" ");
}
