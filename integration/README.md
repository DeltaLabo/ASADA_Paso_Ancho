# Integración del nodo de medición — ASADA Paso Ancho

Este directorio contiene el firmware de integración del nodo de campo. El objetivo del nodo es:

1. medir el **nivel de agua** del tanque con el sensor Seeed Studio S-LL-01;
2. leer **caudal instantáneo** y **volumen acumulado** del medidor ARAD Octave por Modbus RTU/RS485;
3. guardar mediciones localmente en una tarjeta microSD; y
4. comprobar conectividad celular con un módem Waveshare SIM7600G-H.

El controlador usado por el firmware actual es un **Seeed Studio XIAO ESP32-S3**. La selección de placa, los GPIO y las conexiones de este documento corresponden al ESP32-S3, no al XIAO ESP32-C3 mencionado en algunos documentos antiguos del repositorio.

> **Estado actual:** la adquisición, los promedios, el CSV y una prueba HTTP por LTE están programados. Todavía no se ha demostrado experimentalmente el funcionamiento completo de todos los periféricos juntos. En particular, las trazas recientes muestran que el Octave no responde por Modbus; el LL01 estaba desconectado; y todavía no se ha conservado una traza LTE con operador, señal, IP y respuesta HTTP.

## 1. Archivos principales

| Ruta | Propósito |
| --- | --- |
| [`LevelSensor/LevelSensor.ino`](LevelSensor/LevelSensor.ino) | Firmware integrado: LL01, Octave, microSD y SIM7600. |
| [`LevelSensor/pins.h`](LevelSensor/pins.h) | GPIO usados por cada interfaz. |
| [`LevelSensor/frequencies.h`](LevelSensor/frequencies.h) | Periodos de muestreo y registro. |
| [`PruebaInicializacionSD/PruebaInicializacionSD.ino`](PruebaInicializacionSD/PruebaInicializacionSD.ino) | Prueba aislada para inicializar la microSD. |
| [`PruebaSIM7600/PruebaSIM7600.ino`](PruebaSIM7600/PruebaSIM7600.ino) | Prueba aislada de UART, comandos AT, SIM, red, datos y HTTP. |
| [`LevelSensor/src/OctaveModbusWrapper/`](LevelSensor/src/OctaveModbusWrapper/) | Funciones para consultar los registros del Octave. |
| [`LevelSensor/src/IndustrialShields/`](LevelSensor/src/IndustrialShields/) | Implementación Modbus RTU usada por el wrapper. |
| [`LevelSensor/INTEGRACION_NODO_NIVEL_ASADA.md`](LevelSensor/INTEGRACION_NODO_NIVEL_ASADA.md) | Memoria técnica y trazabilidad de la integración. |
| [`../modbus-sim/`](../modbus-sim/) | Archivos opcionales para simular el Octave en una computadora. No son necesarios para operar el medidor real. |

Las copias de librerías que usa el sketch están dentro de `LevelSensor/src/`. La carpeta `integration/src/` contiene otra copia histórica; para el sketch actual debe tomarse como referencia la copia situada dentro de `LevelSensor`.

### Entorno de compilación

- Placa: `esp32:esp32:XIAO_ESP32S3`.
- Framework: Arduino para ESP32.
- Librerías externas: [SdFat](https://github.com/greiman/SdFat) y [TinyGSM](https://github.com/vshymanskyy/TinyGSM).
- Modbus: código incluido dentro de `LevelSensor/src/`; no requiere instalar Modbus Slave en la computadora.
- Monitor serial USB: 9600 bit/s.
- UART del Octave: 2400 bit/s.
- UART del SIM7600: 115200 bit/s.

Desde la raíz se puede compilar con:

```powershell
.\compile.ps1
```

El archivo `upload.ps1` usa `COM5`; antes de ejecutarlo se debe confirmar el puerto que Windows asignó al XIAO.

## 2. Arquitectura actual

```text
                                           ┌───────────────────┐
LL01 ── divisor de tensión ── ADC D0 ─────>│                   │
                                           │                   │
Octave ── RS485 A/B ── SparkFun SP3485 ──>│ XIAO ESP32-S3    │
                    UART1 + RTS             │                   │
                                           │                   │
microSD <────────────── SPI D5/D8/D9/D10 ─>│                   │
                                           │                   │
SIM7600 <──────────────── UART2 D6/D7 ────>│                   │
                                           └───────────────────┘
```

Las interfaces son independientes:

- **ADC:** sensor de nivel;
- **UART1:** Octave por el transceptor RS485;
- **SPI:** tarjeta microSD;
- **UART2:** SIM7600;
- **USB:** programación y monitor serial.

Un error en Modbus no significa que el SIM7600 haya fallado, y una luz del SIM7600 no demuestra que Modbus esté funcionando.

## 3. Mapa de pines del XIAO ESP32-S3

| Función | Pin impreso en XIAO | GPIO usado en el código | Periférico |
| --- | ---: | ---: | --- |
| Entrada analógica de nivel | D0 / A0 | GPIO1 | Señal del LL01 después del divisor |
| Control de dirección RS485 | D1 | GPIO2 | RTS del transceptor SparkFun |
| TX Modbus | D2 | GPIO3 | Entrada `RX-I/DI` del transceptor |
| RX Modbus | D3 | GPIO4 | Salida `TX-O/RO` del transceptor |
| Chip Select microSD | D5 | GPIO6 | CS |
| TX celular | D6 / TX | GPIO43 | RXD del SIM7600 |
| RX celular | D7 / RX | GPIO44 | TXD del SIM7600 |
| Reloj SPI | D8 / SCK | GPIO7 | SCK de microSD |
| Datos SPI hacia XIAO | D9 / MISO | GPIO8 | MISO de microSD |
| Datos SPI desde XIAO | D10 / MOSI | GPIO9 | MOSI de microSD |

Los GPIO del XIAO trabajan a **3,3 V** y no deben recibir directamente señales de 5 V. El pinout oficial se encuentra en la [guía del XIAO ESP32-S3](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/).

## 4. Conexiones

Antes de cablear o cambiar conexiones, apagar todas las fuentes. Verificar siempre la serigrafía de la placa física: diferentes variantes pueden cambiar el nombre o la ubicación de los terminales.

### 4.1 Sensor de nivel Seeed Studio S-LL-01

El LL01 del proyecto tiene rango de 0 a 5 m, alimentación de 5 V y salida analógica de 0,5 a 4,5 V. Como el XIAO no admite 4,5 V en el ADC, se utiliza un divisor:

```text
LL01 señal ── 24,5 kΩ ──┬── D0/A0/GPIO1 del XIAO
                         │
                        47 kΩ
                         │
GND común ───────────────┴── GND del XIAO
```

| LL01 | Conectar a |
| --- | --- |
| Alimentación positiva | Fuente estable de 5 V |
| GND | Negativo de la fuente y GND común del sistema |
| Salida 0,5–4,5 V | Resistencia de 24,5 kΩ; el otro extremo llega al nodo A0 mostrado arriba |

El divisor entrega aproximadamente 0,329–2,958 V al ADC. El firmware reconstruye la tensión original y aplica:

```text
altura = (V_sensor - 0,5 V) × 5 m / 4 V
```

El resultado se limita entre 0 y 5 m. Por esa razón, una entrada desconectada puede terminar mostrando `5.000 m`; esto **no es una medición válida**. Falta implementar detección explícita de circuito abierto/corto y realizar la calibración con alturas reales conocidas.

Referencias: [página del sensor](https://wiki.seeedstudio.com/Sensor/SenseCAP/SenseCAP_Probe/Liquid-Level-Sensor/) y [datasheet del LL01](https://files.seeedstudio.com/products/314990619/res/Liquid%20Level%20Sensor-Datasheet.pdf).

### 4.2 Octave + módulo Modbus 96513110 + SparkFun RS485

El XIAO no puede conectarse directamente a los cables A/B del Octave. El breakout SparkFun BOB-10124 convierte la UART de 3,3 V a RS485 semidúplex.

#### Lado XIAO ↔ SparkFun BOB-10124

| XIAO ESP32-S3 | SparkFun RS485 | Función |
| --- | --- | --- |
| 3V3 | VCC | Alimentación del SP3485 a 3,3 V |
| GND | GND | Referencia común |
| D2 / GPIO3 / TX | `RX-I` o `DI` | Datos transmitidos por el XIAO |
| D3 / GPIO4 / RX | `TX-O` o `RO` | Datos recibidos por el XIAO |
| D1 / GPIO2 | RTS | Cambia entre transmisión y recepción |

`TX` y `RX` se cruzan por función: el TX del XIAO entra al driver y la salida del receptor llega al RX del XIAO.

#### Lado SparkFun ↔ módulo Modbus del Octave

| Cable del Octave | Función oficial | Conectar a |
| --- | --- | --- |
| Azul | D0 / A / Tx+ | Terminal **A** del SparkFun |
| Blanco/azul | D1 / B / Tx− | Terminal **B** del SparkFun |
| Naranja | Alimentación 5–24 VDC | Positivo de la fuente del módulo Octave |
| Blanco/naranja | Ground | Negativo de esa fuente y GND común |
| Rojo, si existe | Salida de pulso opcional | No se usa en este firmware |
| Negro, si existe | Ground de pulso | No se usa en este firmware |

No conectar el cable naranja del Octave al pin 3V3 del XIAO. El módulo Modbus del Octave requiere una alimentación externa dentro de 5–24 VDC. Para esta integración se comparte la referencia de tierra entre la fuente del Octave, el breakout RS485 y el XIAO.

Configuración que asume el firmware actual:

| Parámetro | Valor |
| --- | --- |
| Protocolo | Modbus RTU sobre RS485 semidúplex |
| Maestro | XIAO ESP32-S3 |
| Esclavo | Octave, dirección 1 |
| Velocidad | 2400 bit/s |
| Formato | 8 bits, sin paridad, 1 bit de parada (`8N1`) |
| Caudal | Función 04, inicio `0x29`, 4 registros, `double` de 64 bits |
| Volumen neto con signo | Función 04, inicio `0x42`, 4 registros, `double` de 64 bits |

La dirección, velocidad y formato del medidor instalado deben coincidir con estos valores. El manual indica una velocidad máxima de 9600 bit/s, pero eso no significa que la unidad concreta esté configurada a 2400 bit/s.

Si aparecen continuamente:

```text
Flow Modbus read failed or exceeded the logging range.
Volume Modbus read failed or exceeded the logging range.
```

no se recibió una medición válida. Revisar, en este orden: alimentación del módulo Octave, tierra común, A/B, TX/RX/RTS, dirección del esclavo, velocidad/formato y registros del modelo de módulo instalado.

Referencias: [manual de instalación del Octave en español](https://www.arad.co.il/wp-content/uploads/OCTAVE-Installation-Manuel-SP-002.pdf), [producto SparkFun BOB-10124](https://www.sparkfun.com/sparkfun-transceiver-breakout-rs-485.html), [esquemático del breakout](https://cdn.sparkfun.com/datasheets/BreakoutBoards/RS485_Breakout_v10.pdf) y [datasheet del SP3485](https://www.sparkfun.com/datasheets/Components/General/sp3485CN-LTR.pdf).

#### Adaptador Waveshare USB–RS232/485

El adaptador USB Waveshare sirve para que una **computadora** sea el maestro Modbus durante pruebas. No sustituye al breakout SparkFun cuando el maestro es el XIAO, porque su lado de control es USB y no UART TTL del microcontrolador.

Los archivos `.mbs` de [`../modbus-sim/`](../modbus-sim/) son bancos de registros para el programa comercial Modbus Slave. Son opcionales y el firmware no depende de ese programa ni de su licencia. La prueba final puede hacerse directamente contra el Octave real; para simulaciones futuras también puede prepararse un esclavo gratuito con Python/PyModbus.

Referencia: [Waveshare USB TO RS232/485](https://www.waveshare.com/wiki/USB_TO_RS232/485).

### 4.3 Tarjeta microSD

| XIAO ESP32-S3 | Módulo microSD |
| --- | --- |
| D5 / GPIO6 | CS |
| D8 / GPIO7 | SCK / CLK |
| D9 / GPIO8 | MISO / DO |
| D10 / GPIO9 | MOSI / DI |
| GND | GND |
| 3V3 o alimentación indicada por el fabricante | VCC |

La tensión de alimentación depende del lector utilizado. Las señales SPI del XIAO son de 3,3 V; no aplicar 5 V a sus GPIO. Como el modelo exacto del lector todavía no está identificado en el repositorio, hay que verificar si posee regulador y conversión de nivel antes de usar 5 V.

El firmware:

- intenta inicializar a 25 MHz y reintenta a 4 MHz;
- crea `/datos.csv` si no existe;
- escribe una fila cada 10 s;
- sincroniza y cierra el archivo después de cada fila; y
- reintenta la inicialización cada 30 s cuando falla.

La tarjeta debe estar insertada y formateada en un sistema de archivos compatible; para la prueba actual se recomienda FAT32. Para separar la SD del resto del sistema, cargar primero [`PruebaInicializacionSD.ino`](PruebaInicializacionSD/PruebaInicializacionSD.ino). El resultado esperado es:

```text
OK: microSD inicializada correctamente.
```

Referencia de software: [SdFat](https://github.com/greiman/SdFat).

### 4.4 Módem Waveshare SIM7600G-H

#### UART

| XIAO ESP32-S3 | SIM7600 |
| --- | --- |
| D6 / GPIO43 / TX | RXD |
| D7 / GPIO44 / RX | TXD |
| GND | GND |

La UART se configura a 115200 bit/s. El módem debe tener una alimentación estable apropiada para la variante de placa utilizada; no debe alimentarse desde el pin 3V3 del XIAO. Instalar la SIM con el equipo apagado y conectar la antena celular al puerto `MAIN`.

El firmware no controla `PWRKEY`: se supone que el módulo ya está encendido por su circuito físico o por el botón de la placa. Si la variante usada requiere una secuencia PWRKEY después de cada encendido, esa función todavía debe añadirse.

La prueba actual no envía las mediciones. Después de 30 s intenta:

1. obtener respuesta a `AT`;
2. inicializar el módem;
3. registrarse en la red;
4. activar datos con el APN `internet.ideasclaro`; y
5. solicitar por HTTP la página `example.com`.

Una luz `NET` fija normalmente significa que el módem está buscando red; no confirma la comunicación UART con el XIAO. La verificación completa requiere observar por el monitor serial:

```text
LTE: operator = ...
LTE: signal quality (CSQ) = ...
LTE: mobile data active, IP = ...
LTE: HTTP test response = HTTP/1.1 200 OK
```

Interpretación rápida:

| Mensaje | Diagnóstico principal |
| --- | --- |
| `LTE: no AT response from SIM7600.` | Alimentación, encendido, tierra, TX/RX o velocidad UART |
| `LTE: modem initialization failed; check SIM/PIN.` | Estado del módem o SIM bloqueada por PIN |
| `LTE: mobile network registration failed.` | Antena, SIM, cobertura, operador o modo de red; la UART sí respondió |
| `LTE: mobile data activation failed; check Claro APN.` | APN o servicio de datos |
| IP + `HTTP/1.1 200 OK` | UART, registro y salida de datos funcionaron en esa prueba |

El APN debe confirmarse con el operador y el plan de la SIM. `internet.ideasclaro` solo es apropiado si corresponde a la SIM instalada.

Referencias: [Waveshare SIM7600G-H](https://www.waveshare.com/wiki/SIM7600G-H_4G_Module), [diseño de hardware SIM7600G(-H)](https://files.waveshare.com/upload/5/52/SIM7600G%28-H%29_SIM7600NA%28-H%29_Hardware_Design_V1.08.pdf), [comandos AT incluidos en el repositorio](../SIM7600_AT_Commands.pdf) y [TinyGSM](https://github.com/vshymanskyy/TinyGSM).

### 4.5 Alimentación y tierra común

Una conexión de datos correcta no compensa una alimentación incorrecta. Como guía de integración:

| Componente | Alimentación prevista | Tierra |
| --- | --- | --- |
| XIAO ESP32-S3 | USB/5 V o sistema de potencia del nodo | GND común |
| LL01 | 5 V según datasheet | GND común |
| SparkFun BOB-10124 | 3,3 V del XIAO | GND común |
| Módulo Modbus Octave | 5–24 VDC externa | GND común mediante blanco/naranja |
| SIM7600G-H | Entrada de potencia de su placa, con fuente estable | GND común con el XIAO |
| microSD | Según el lector; lógica SPI a 3,3 V | GND común |

El panel solar, cargador y BMS pertenecen al subsistema de potencia. El firmware actual no lee el BMS, no mide tensión/corriente de batería y no controla el panel. Aunque existe `BMS_BAUDRATE` en el código, no hay una instancia UART, protocolo ni procesamiento de datos del BMS: esa integración sigue pendiente.

## 5. Comportamiento del firmware

| Actividad | Periodo programado |
| --- | ---: |
| Consulta de caudal Modbus | 1 s |
| Consulta de volumen Modbus | 1 s |
| Lectura del nivel | 1 s |
| Promedio y fila CSV | 10 s |
| Reintento de SD después de fallo | 30 s |
| Reintento LTE después de fallo | 30 s |
| Prueba HTTP cuando LTE está conectado | 60 s |

Caudal y volumen se guardan internamente multiplicados por 100 para conservar dos decimales. El CSV vuelve a escribirlos como decimales. La altura se guarda en centímetros y se escribe en metros.

Cabecera actual:

```csv
uptime_ms,signed_current_flow,net_signed_volume,water_height_m,flow_samples,volume_samples,height_samples
```

`uptime_ms` es tiempo desde el arranque, no fecha y hora. Los campos de caudal o volumen quedan vacíos cuando no hubo muestras válidas. Los contadores permiten saber cuántas muestras formaron cada promedio.

El volumen del Octave es un contador acumulado. Promediar sus lecturas no representa el consumo de esos 10 segundos; para calcular consumo por intervalo se deberá restar una lectura acumulada válida de la siguiente.

## 6. Cómo probar la integración por etapas

No conviene conectar todo por primera vez y diagnosticarlo como una sola unidad. El orden recomendado es:

### Etapa A — XIAO y monitor serial

1. Compilar para `esp32:esp32:XIAO_ESP32S3`.
2. Abrir el monitor a 9600 bit/s.
3. Reiniciar la placa y conservar la traza desde el arranque.

Desde la raíz del repositorio existen [`../compile.ps1`](../compile.ps1) y [`../upload.ps1`](../upload.ps1). El puerto de `upload.ps1` está fijado actualmente a `COM5` y debe cambiarse si Windows asigna otro puerto.

### Etapa B — microSD aislada

Cargar `PruebaInicializacionSD.ino`, comprobar la inicialización y leer la tarjeta en la computadora. Después volver al firmware integrado y confirmar que existe `datos.csv`, una sola cabecera y filas nuevas.

### Etapa C — LL01

Probar primero con tensiones seguras conocidas en el divisor y después con el sensor. Comparar `vAdc`, `vSensor` y `height`. Realizar varios puntos de calibración con alturas conocidas; no ajustar solamente cero y fondo de escala.

### Etapa D — Octave/RS485

1. Confirmar 5–24 V entre naranja y blanco/naranja.
2. Confirmar 3,3 V en VCC del SparkFun.
3. Revisar tierra común y cruce UART.
4. Revisar azul→A y blanco/azul→B.
5. Confirmar dirección 1, 2400 bit/s y 8N1 en el módulo instalado.
6. Verificar que desaparezcan ambos mensajes `Modbus read failed` y que los promedios dejen de mostrar `N/A`.

Si no responde, probar el Octave desde una computadora con el adaptador USB–RS485 ayuda a separar el problema del medidor del problema XIAO↔SparkFun.

### Etapa E — SIM7600

Cargar primero [`PruebaSIM7600.ino`](PruebaSIM7600/PruebaSIM7600.ino) con los demás periféricos desconectados. Abrir el monitor serial a 115200 bit/s y conservar la salida completa desde el arranque. La prueba busca automáticamente las velocidades UART más comunes, muestra comandos AT directos y entrega un resumen separado para UART, inicialización, SIM, registro celular, datos y HTTP. Al finalizar deja disponible un puente AT interactivo; seleccionar `Both NL & CR` para escribir comandos manualmente.

No declarar éxito por el LED. El criterio mínimo es ver operador, CSQ, IP y respuesta `HTTP/1.1 200 OK`.

### Etapa F — sistema completo

Conectar todos los periféricos, comprobar que cada interfaz sigue funcionando y comparar:

- número de consultas esperadas;
- muestras válidas por ventana;
- filas realmente escritas;
- reinicios o pausas durante transmisiones LTE; y
- recuperación después de desconectar y reconectar SD, RS485 y red celular.

## 7. Estado de integración y pendientes

| Subsistema | Programación | Evidencia disponible | Pendiente principal |
| --- | --- | --- | --- |
| LL01 | Implementada | El ADC y la conversión imprimen datos | Conectar sensor, calibrar y detectar abierto/corto |
| Octave Modbus | Implementada | Se observan intentos de lectura | Resolver falta de respuesta y confirmar unidades/configuración |
| microSD | Implementada + sketch aislado | Código de diagnóstico disponible | Confirmar con la tarjeta y lector físicos; conservar CSV de prueba |
| SIM7600 | Diagnóstico implementado | UART2 y prueba de red programadas | Obtener traza completa; confirmar alimentación, registro, APN e HTTP |
| Envío real de telemetría | No implementado | Solo HTTP a `example.com` | Definir servidor/API, formato, autenticación, TLS y reintentos |
| Sincronización horaria | No implementada | Solo `millis()` | RTC o tiempo de red y manejo de reinicios |
| BMS/medición de batería | No implementada | Solo constante de baudrate sin uso | Definir hardware, protocolo, pines y variables de salud |
| Panel solar/cargador | Fuera del firmware actual | Trabajo del equipo de potencia | Integrar estados/telemetría que exponga el subsistema de potencia |
| Alertas y dashboard | No implementados | Requerimientos del sistema | Backend, reglas de alarma y visualización móvil |
| Operación sin red | Parcial | CSV local y reintentos LTE | Cola de envíos pendientes y confirmación de entrega |
| Ciberseguridad | No implementada para producción | HTTP de diagnóstico sin datos | TLS, credenciales, almacenamiento de secretos y actualización segura |

## 8. Qué significa una prueba aprobada

- **Nivel aprobado:** altura contrastada en varios puntos conocidos, dentro de la tolerancia acordada, y fallas de cable detectadas.
- **Modbus aprobado:** lecturas repetibles sin `N/A`, unidades verificadas y recuperación después de desconectar/reconectar el bus.
- **SD aprobada:** `datos.csv` legible, una sola cabecera, filas coherentes y recuperación después de reinserción o reinicio.
- **LTE aprobado:** respuesta AT, registro, señal, IP y respuesta HTTP exitosa; después deberá probarse el servidor real.
- **Integración aprobada:** los cuatro subsistemas funcionan simultáneamente durante una prueba prolongada sin reinicios, corrupción ni pérdida silenciosa de datos.

Una compilación exitosa demuestra que el software es construible; no sustituye estas pruebas con el hardware real.

