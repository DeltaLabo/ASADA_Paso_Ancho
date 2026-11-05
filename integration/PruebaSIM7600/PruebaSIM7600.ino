/*
 * Prueba aislada del Waveshare SIM7600G-H con Seeed XIAO ESP32-S3.
 *
 * Conexiones:
 *   XIAO D6 / GPIO43 / TX  -> RXD del SIM7600
 *   XIAO D7 / GPIO44 / RX  <- TXD del SIM7600
 *   XIAO GND                -- GND del SIM7600
 *
 * El SIM7600 debe usar una fuente adecuada para su placa. No alimentarlo
 * desde el pin 3V3 del XIAO. El sketch no controla PWRKEY.
 *
 * Monitor serial USB: 115200 baud, "Both NL & CR" para el puente AT.
 */

#include <HardwareSerial.h>

#define TINY_GSM_MODEM_SIM7600
#include <TinyGsmClient.h>

constexpr int MODEM_RX_PIN = 4;  // XIAO D7 recibe desde TXD del SIM7600
constexpr int MODEM_TX_PIN = 3;  // XIAO D6 transmite hacia RXD del SIM7600
constexpr uint32_t USB_BAUD = 115200;

// Cambiar si la SIM instalada no usa este APN.
const char APN[] = "internet.ideasclaro";
const char GPRS_USER[] = "";
const char GPRS_PASS[] = "";

HardwareSerial ModemSerial(2);
TinyGsm modem(ModemSerial);
TinyGsmClient client(modem);

bool uartOk = false;
bool initOk = false;
bool simOk = false;
bool networkOk = false;
bool dataOk = false;
bool httpOk = false;
uint32_t detectedBaud = 0;

String readModemResponse(uint32_t timeoutMs) {
  String response;
  const uint32_t startedAt = millis();
  uint32_t lastByteAt = startedAt;

  while (millis() - startedAt < timeoutMs) {
    while (ModemSerial.available()) {
      response += static_cast<char>(ModemSerial.read());
      lastByteAt = millis();
    }

    // Cuando ya llegaron datos, terminar después de 250 ms de silencio.
    if (response.length() > 0 && millis() - lastByteAt >= 250) break;
    delay(5);
  }

  return response;
}

void discardModemInput() {
  while (ModemSerial.available()) ModemSerial.read();
}

bool probeBaud(uint32_t baud) {
  ModemSerial.end();
  delay(100);
  ModemSerial.begin(baud, SERIAL_8N1, MODEM_RX_PIN, MODEM_TX_PIN);
  delay(300);

  for (int attempt = 1; attempt <= 3; ++attempt) {
    discardModemInput();
    ModemSerial.print("AT\r\n");
    String response = readModemResponse(1000);
    if (response.indexOf("OK") >= 0) return true;
    delay(200);
  }

  return false;
}

uint32_t detectModemBaud() {
  const uint32_t candidates[] = {115200, 9600, 57600, 38400, 19200};

  Serial.println("Buscando respuesta AT...");
  for (uint32_t baud : candidates) {
    Serial.print("  Probando ");
    Serial.print(baud);
    Serial.print(" baud: ");
    if (probeBaud(baud)) {
      Serial.println("OK");
      return baud;
    }
    Serial.println("sin respuesta");
  }

  return 0;
}

bool runRawAT(const char *command, uint32_t timeoutMs = 2500) {
  discardModemInput();
  Serial.print("\n> ");
  Serial.println(command);
  ModemSerial.print(command);
  ModemSerial.print("\r\n");

  String response = readModemResponse(timeoutMs);
  if (response.length() == 0) {
    Serial.println("< (sin respuesta)");
    return false;
  }

  Serial.print(response);
  if (!response.endsWith("\n")) Serial.println();
  return response.indexOf("OK") >= 0;
}

void printHeader() {
  Serial.println();
  Serial.println("================================================");
  Serial.println(" PRUEBA AISLADA XIAO ESP32-S3 + SIM7600");
  Serial.println("================================================");
  Serial.println("Cableado esperado:");
  Serial.println("  XIAO D6/GPIO43/TX -> RXD del SIM7600");
  Serial.println("  XIAO D7/GPIO44/RX <- TXD del SIM7600");
  Serial.println("  GND del XIAO      -- GND del SIM7600");
  Serial.println("El modem debe tener alimentacion propia estable,");
  Serial.println("antena MAIN conectada y SIM insertada.");
  Serial.println("Este sketch no acciona PWRKEY.");
  Serial.println();
}

void printSummary() {
  Serial.println();
  Serial.println("================ RESULTADO ================");
  Serial.print("1. UART / respuesta AT:       ");
  Serial.println(uartOk ? "OK" : "FALLO");
  Serial.print("2. Inicializacion del modem:  ");
  Serial.println(initOk ? "OK" : "FALLO");
  Serial.print("3. SIM detectada y lista:     ");
  Serial.println(simOk ? "OK" : "FALLO");
  Serial.print("4. Registro en red celular:   ");
  Serial.println(networkOk ? "OK" : "FALLO");
  Serial.print("5. Contexto de datos / APN:   ");
  Serial.println(dataOk ? "OK" : "FALLO");
  Serial.print("6. Solicitud HTTP:            ");
  Serial.println(httpOk ? "OK" : "FALLO");
  Serial.println("===========================================");

  if (!uartOk) {
    Serial.println("Diagnostico: revisar encendido/PWRKEY, fuente, GND,");
    Serial.println("TX/RX cruzados y velocidad UART.");
  } else if (!initOk) {
    Serial.println("Diagnostico: la UART responde, pero TinyGSM no logra");
    Serial.println("inicializar el modem. Revisar las respuestas AT anteriores.");
  } else if (!simOk) {
    Serial.println("Diagnostico: revisar insercion, contactos y PIN de la SIM.");
  } else if (!networkOk) {
    Serial.println("Diagnostico: revisar antena MAIN, cobertura, SIM activa,");
    Serial.println("modo de red y servicio del operador.");
  } else if (!dataOk) {
    Serial.println("Diagnostico: la red funciona; revisar APN y plan de datos.");
  } else if (!httpOk) {
    Serial.println("Diagnostico: hay datos e IP, pero fallo la prueba TCP/HTTP.");
  } else {
    Serial.println("Prueba completa exitosa: UART, SIM, red y datos funcionan.");
  }

  Serial.println();
  Serial.println("Puente AT activo. Puedes escribir comandos en el monitor");
  Serial.println("serial a 115200 usando la terminacion 'Both NL & CR'.");
  Serial.println("Ejemplos: AT, AT+CSQ, AT+CEREG?, AT+COPS?, AT+CPSI?");
}

void testHttp() {
  const char host[] = "example.com";
  constexpr uint16_t port = 80;

  Serial.println("\n[6/6] Probando TCP/HTTP con example.com...");
  if (!client.connect(host, port, 10)) {
    Serial.println("FALLO: no se pudo abrir la conexion TCP.");
    return;
  }

  client.print("GET / HTTP/1.1\r\n");
  client.print("Host: example.com\r\n");
  client.print("Connection: close\r\n\r\n");

  const uint32_t startedAt = millis();
  while (!client.available() && client.connected() &&
         millis() - startedAt < 15000) {
    delay(10);
  }

  String statusLine;
  if (client.available()) {
    statusLine = client.readStringUntil('\n');
    statusLine.trim();
  }
  client.stop();

  Serial.print("Respuesta HTTP: ");
  Serial.println(statusLine.length() ? statusLine : "(sin respuesta)");
  httpOk = statusLine.startsWith("HTTP/1.1 200") ||
           statusLine.startsWith("HTTP/1.0 200");
}

void setup() {
  Serial.begin(USB_BAUD);
  const uint32_t serialWaitStart = millis();
  while (!Serial && millis() - serialWaitStart < 5000) delay(10);

  printHeader();

  detectedBaud = detectModemBaud();
  uartOk = detectedBaud != 0;
  if (!uartOk) {
    // Dejar el puente AT en la velocidad esperada aunque el barrido falle.
    ModemSerial.end();
    ModemSerial.begin(115200, SERIAL_8N1, MODEM_RX_PIN, MODEM_TX_PIN);
    printSummary();
    return;
  }

  Serial.print("UART del modem detectada a ");
  Serial.print(detectedBaud);
  Serial.println(" baud.");

  Serial.println("\n--- Respuestas AT directas ---");
  runRawAT("ATE0");          // Desactiva eco para una salida mas clara.
  runRawAT("ATI");           // Identificacion del modem.
  runRawAT("AT+CPIN?");      // Estado de la SIM.
  runRawAT("AT+CFUN?");      // Estado funcional de radio.
  runRawAT("AT+CSQ");        // Calidad de senal.
  runRawAT("AT+CEREG?");     // Registro EPS/LTE.
  runRawAT("AT+COPS?");      // Operador.
  runRawAT("AT+CPSI?");      // Informacion de red y celda.

  Serial.println("\n[2/6] Inicializando el SIM7600 con TinyGSM...");
  initOk = modem.init();
  Serial.println(initOk ? "OK: modem inicializado." :
                          "FALLO: modem.init() no completo.");
  if (!initOk) {
    printSummary();
    return;
  }

  Serial.print("Modelo: ");
  Serial.println(modem.getModemInfo());
  Serial.print("IMEI: ");
  Serial.println(modem.getIMEI());

  Serial.println("\n[3/6] Verificando SIM...");
  const int simStatus = modem.getSimStatus();
  simOk = simStatus == SIM_READY;
  Serial.print("Estado SIM (TinyGSM): ");
  Serial.println(simStatus);
  Serial.print("CCID: ");
  Serial.println(modem.getSimCCID());
  if (!simOk) {
    Serial.println("FALLO: la SIM no aparece lista. Si solicita PIN,");
    Serial.println("desactivarlo temporalmente o agregar su manejo al sketch.");
    printSummary();
    return;
  }

  Serial.println("\n[4/6] Esperando registro celular (hasta 60 s)...");
  networkOk = modem.waitForNetwork(60000L);
  if (!networkOk) {
    Serial.println("FALLO: el modem no se registro en la red.");
    runRawAT("AT+CSQ");
    runRawAT("AT+CEREG?");
    runRawAT("AT+COPS?");
    runRawAT("AT+CPSI?");
    printSummary();
    return;
  }

  Serial.println("OK: registrado en la red.");
  Serial.print("Operador: ");
  Serial.println(modem.getOperator());
  Serial.print("Calidad de senal CSQ: ");
  Serial.println(modem.getSignalQuality());

  Serial.print("\n[5/6] Activando datos con APN '");
  Serial.print(APN);
  Serial.println("'...");
  dataOk = modem.gprsConnect(APN, GPRS_USER, GPRS_PASS);
  if (!dataOk || !modem.isGprsConnected()) {
    dataOk = false;
    Serial.println("FALLO: no se activo el contexto de datos.");
    printSummary();
    return;
  }

  Serial.println("OK: datos moviles activos.");
  Serial.print("IP: ");
  Serial.println(modem.localIP());

  testHttp();
  printSummary();
}

void loop() {
  // Puente USB <-> UART para enviar comandos AT manualmente.
  while (Serial.available()) ModemSerial.write(Serial.read());
  while (ModemSerial.available()) Serial.write(ModemSerial.read());
}

