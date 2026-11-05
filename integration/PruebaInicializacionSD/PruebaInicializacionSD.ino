#include <SPI.h>
#include <SdFat.h>

// Pines SPI del XIAO ESP32-S3
constexpr uint8_t SD_SCK_PIN  = 7;  // D8
constexpr uint8_t SD_MISO_PIN = 8;  // D9
constexpr uint8_t SD_MOSI_PIN = 9;  // D10
constexpr uint8_t SD_CS_PIN   = 6;  // D5

SdFat sd;

void setup() {
  Serial.begin(9600);

  uint32_t startTime = millis();
  while (!Serial && millis() - startTime < 5000) {
    delay(10);
  }

  Serial.println();
  Serial.println("==============================");
  Serial.println("Prueba de inicializacion microSD");
  Serial.println("==============================");

  Serial.println("Configurando SPI...");
  Serial.println("CS   = D5  / GPIO6");
  Serial.println("SCK  = D8  / GPIO7");
  Serial.println("MISO = D9  / GPIO8");
  Serial.println("MOSI = D10 / GPIO9");

  SPI.begin(
    SD_SCK_PIN,
    SD_MISO_PIN,
    SD_MOSI_PIN,
    SD_CS_PIN
  );

  Serial.println();
  Serial.println("Intentando inicializar a 25 MHz...");

  bool initialized = sd.begin(
    SdSpiConfig(
      SD_CS_PIN,
      SHARED_SPI,
      SD_SCK_MHZ(25)
    )
  );

  if (!initialized) {
    Serial.println("Fallo la inicializacion a 25 MHz.");
    sd.printSdError(&Serial);
    sd.end();

    Serial.println();
    Serial.println("Intentando nuevamente a 4 MHz...");

    initialized = sd.begin(
      SdSpiConfig(
        SD_CS_PIN,
        SHARED_SPI,
        SD_SCK_MHZ(4)
      )
    );
  }

  if (!initialized) {
    Serial.println();
    Serial.println("ERROR: no se pudo inicializar la microSD.");
    sd.printSdError(&Serial);

    Serial.println();
    Serial.println("Revisa:");
    Serial.println("1. Que la tarjeta este insertada.");
    Serial.println("2. Las conexiones CS, SCK, MISO y MOSI.");
    Serial.println("3. La alimentacion y GND.");
    Serial.println("4. Que la tarjeta este formateada como FAT32.");
    return;
  }

  Serial.println();
  Serial.println("OK: microSD inicializada correctamente.");

  if (sd.exists("datos.csv")) {
    Serial.println("OK: tambien se encontro /datos.csv.");
  } else {
    Serial.println("AVISO: la SD funciona, pero no existe /datos.csv.");
  }

  Serial.println();
  Serial.println("Prueba terminada.");
}

void loop() {
  // La prueba se realiza una sola vez.
}