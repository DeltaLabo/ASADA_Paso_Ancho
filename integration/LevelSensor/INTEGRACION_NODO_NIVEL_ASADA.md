# Primera integración del nodo de medición de agua

**Proyecto:** ASADA Paso Ancho  
**Configuración documentada:** XIAO ESP32-S3, sensor de nivel analógico, medidor Octave por RS485/Modbus, microSD por SPI y módem Waveshare SIM7600G-H por UART.  
**Referencia de firmware:** `integration/LevelSensor/LevelSensor.ino`, `pins.h` y `frequencies.h`; SHA-256 de `LevelSensor.ino`: `107D2AF8F78064FB37A55B1BB1D9BA1A4AB5A44420CB0680661313BC61E2B7BA`.  
**Fecha de la línea base documental:** 22 de octubre de 2026.  
**Estado:** integración de adquisición y registro local implementada; prueba de conectividad celular incorporada. El registro de una respuesta HTTP exitosa, la precisión metrológica y el cumplimiento del sistema completo requieren evidencia experimental conservada.

## 1. Alcance y criterio de ingeniería de sistemas

Esta integración reúne cuatro funciones del nodo: adquirir nivel de agua, consultar caudal y volumen, calcular medias de una ventana corta y guardar un registro local. También comprueba la comunicación celular mediante una petición HTTP de diagnóstico. La división permite verificar cada interfaz por separado y observar qué función falla sin atribuir el problema automáticamente al sistema completo.

El límite de esta versión es importante: **la petición LTE no transmite mediciones a la plataforma del proyecto**. Solicita la página principal de `example.com`, comprueba la respuesta y la muestra por el monitor serie. Tampoco hay todavía ingestión en servidor, autenticación del nodo, panel de visualización, sincronización de reloj, retransmisión de registros de SD ni monitor de batería implementados en este sketch. La microSD es almacenamiento **local**, no equivale al almacenamiento central modelado en la arquitectura.

La estructura funcional se corresponde parcialmente con la cadena *Provide supply and demand data*: medir volumen, caudal y nivel → agrupar mediciones → almacenar. La presentación remota queda fuera de la implementación actual. Véanse [`se/SA/fc_provide_sd_data.d2`](../../se/SA/fc_provide_sd_data.d2) y [`se/LA/fc_provide_sd_data.d2`](../../se/LA/fc_provide_sd_data.d2).

## 2. Configuración física e interfaces

| Función | Componente e interfaz | Conexión definida en el firmware | Estado de la identificación física |
|---|---|---|---|
| Control y cálculo | Seeed XIAO ESP32-S3 | Placa seleccionada al compilar | Implementado en firmware |
| Nivel | Sensor de salida analógica descrito en el código como S-LL-01 | Salida → 24,5 kΩ → D0/A0/GPIO1 → 47 kΩ → GND | Modelo exacto y alimentación del sensor pendientes de confirmar con etiqueta/ficha del montaje |
| Caudal y volumen | Medidor Octave, bus RS485, protocolo Modbus RTU | D1/GPIO2 = RTS; D2/GPIO3 = TX; D3/GPIO4 = RX del transceptor | Bornes A/B, terminación y alimentación del transceptor deben verificarse en el montaje |
| Registro | Módulo lector microSD por SPI | D5/GPIO6 = CS; D8/GPIO7 = SCK; D9/GPIO8 = MISO; D10/GPIO9 = MOSI | El modelo comercial del lector no consta en el código; verificar tensión de alimentación y niveles lógicos de su placa |
| Celular | Módulo Waveshare SIM7600G-H, UART TTL | D6/GPIO43 TX → RXD del módem; D7/GPIO44 RX ← TXD del módem; GND común | Referencia SIM7600G-H en el modelo físico; confirmar variante de placa, alimentación y encendido/PWRKEY reales |
| Diagnóstico | USB/monitor serie | `Serial.begin(9600)` | Monitor a 9600 bit/s; UART del módem a 115200 bit/s |

El XIAO asigna D0 a GPIO1, D5 a GPIO6, D6 a GPIO43, D7 a GPIO44 y D8–D10 a GPIO7–GPIO9, respectivamente, según el [pinout oficial de Seeed](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/). El código dedica UART1 al RS485 y UART2 al SIM7600; así sus comunicaciones son independientes. El módem necesita alimentación adecuada para su variante y masa común con el XIAO. El firmware **no controla PWRKEY**: el encendido se resuelve físicamente en el módulo. Waveshare documenta UART TTL, alternativas de alimentación y control de encendido para el [SIM7600G-H 4G Module](https://www.waveshare.com/wiki/SIM7600G-H_4G_Module); la conexión final debe cotejarse con la serigrafía de la placa instalada.

## 3. Sensor de nivel y divisor de tensión

El modelo usado en el firmware supone que el sensor entrega **0,5 V a 0 m** y **4,5 V a 5 m**. Su salida máxima excede la tensión admisible para la entrada analógica del XIAO, por lo que se interponen dos resistencias:

```text
Salida del sensor ── R1 = 24,5 kΩ ── A0 (GPIO1) ── R2 = 47 kΩ ── GND
                                      │
                                  ADC del XIAO
```

Con entrada ADC de alta impedancia, la fracción ideal aplicada a A0 es:

`r = V_ADC / V_sensor = R2 / (R1 + R2) = 47 / (24,5 + 47) = 0,65734`.

De este modo, los extremos supuestos de 0,5 y 4,5 V se convierten en aproximadamente **0,329 y 2,958 V** en A0. El software mide `analogReadMilliVolts(GPIO1)`, convierte a voltios, recupera `V_sensor = V_ADC / r` y calcula:

`altura_m = limitar_0_a_5 [ (V_sensor - 0,5 V) × (5 m / 4 V) ]`.

Como comprobación de la orientación del divisor, **0,75 m** equivalen a `V_sensor ≈ 1,10 V` y `V_ADC ≈ 0,723 V`. Invertir las resistencias cambiaría el factor a 0,34266 y produciría un error grande en la altura reconstruida. `ADC_11db` y resolución de 12 bits son las configuraciones programadas para abarcar esta ventana; no constituyen por sí mismas una calibración del ADC ni garantizan exactitud. La relación ideal no incluye tolerancias de resistencias, ruido, referencia/linealidad del ADC, caída en cableado ni incertidumbre del sensor. Se deben medir los valores reales de R1 y R2 y contrastar varios niveles conocidos antes de declarar precisión.

La función `constrain` fuerza cualquier valor calculado fuera de 0–5 m al extremo más cercano. **Una entrada abierta, un corto o una salida fuera de rango puede quedar registrada como 0 o 5 m**, sin marca de fallo. Es una limitación relevante para la detección de fallas del sensor. La lectura se almacena como centímetros enteros (`int16_t`) tras redondear y luego se imprime en metros con dos decimales.

## 4. Secuencia de ejecución y tratamiento de datos

1. `setup()` abre el monitor serie; configura el RS485 a 2400 bit/s, 8N1 y semidúplex; inicia el medidor Octave, el ADC, la microSD y UART2 del módem a 115200 bit/s.
2. Cada **1000 ms** se intentan leer `SignedCurrentFlow_double` y `NetSignedVolume_double` por Modbus. Solo se agregan muestras cuando la consulta devuelve éxito, el número es finito y cabe en el entero escalado. Una lectura fallida se informa por serie y no se introduce como cero.
3. Cada **1000 ms** se lee el ADC, se aplica el divisor y la curva lineal de nivel, y se agrega una muestra en centímetros. El monitor serie imprime tensión ADC, tensión reconstruida y altura para diagnóstico.
4. Cada **10000 ms** se calcula la media de las muestras disponibles en la ventana. `AverageCalculator` usa una suma `int64_t`, divide por la cantidad de muestras y reinicia el contador. Si no hubo muestras, la media no se calcula y el CSV deja vacío el campo correspondiente.
5. La misma ventana se intenta añadir a `/datos.csv`. El código conserva el número de muestras de cada variable, útil para distinguir una ventana completa de una degradada.
6. Tras las demás tareas del ciclo se atiende el módem. El primer intento ocurre unos **30 s** después del arranque. Ante fallo se reintenta después de 30 s; con conexión, la petición HTTP se repite aproximadamente cada 60 s.

Las magnitudes del Octave se escalan internamente ×100 para conservar dos decimales. **El firmware no consulta los registros de unidades del medidor**; antes de rotular caudal y volumen como m³/h o m³ en un informe, se debe comprobar su configuración real. Además, `NetSignedVolume` es una lectura acumulada del medidor: promediar sus valores durante 10 s no equivale al volumen consumido en esa ventana. Para ese cálculo haría falta una diferencia entre lecturas acumuladas válidas.

La programación por `millis()` es cooperativa, no una garantía de muestreo exacto. Las consultas Modbus y las llamadas al módem pueden bloquear el `loop` y alargar ventanas. Los datos del CSV se identifican por tiempo desde arranque, no por fecha/hora civil. El contador `millis()` de 32 bits se desborda aproximadamente a los 49,7 días; el CSV necesita un esquema temporal distinto para análisis longitudinal sin ambigüedad.

## 5. Almacenamiento microSD: elección de SdFat

El programa utiliza `SPI.begin(7, 8, 9, 6)` y `SdFat` con `SdSpiConfig(CS, SHARED_SPI, frecuencia)`. Intenta primero **25 MHz** y, si falla la inicialización, **4 MHz**. Crea `/datos.csv` cuando no existe, escribe una cabecera solo si el archivo está vacío, abre en modo adición, comprueba errores de escritura, llama a `sync()` y cierra el archivo. Tras una falla, deja continuar la adquisición y vuelve a intentar inicializar la tarjeta cada **30 s**.

Se eligió **SdFat** porque su API hace explícitos el modo y la velocidad SPI y ofrece las operaciones de comprobación, sincronización y diagnóstico usadas en esta implementación. Esto permite probar una frecuencia menor y distinguir fallas de inicialización de fallas de escritura. **No se eligió porque `SD.h` no exista:** la biblioteca SD del entorno ESP32 también puede servir para registro sencillo. Tampoco debe atribuirse una ventaja de rendimiento medida a este montaje; no hay comparación experimental entre bibliotecas. SdFat documenta las opciones de SPI y sistema de archivos en su [repositorio oficial](https://github.com/greiman/SdFat).

Formato exacto de la cabecera:

```csv
uptime_ms,signed_current_flow,net_signed_volume,water_height_m,flow_samples,volume_samples,height_samples
```

`uptime_ms` es el `millis()` capturado al comenzar la iteración; los campos de medición pueden quedar vacíos y los contadores indican cuántas muestras válidas los respaldan. La implementación confirma cada escritura con `sync()`, pero no dispone de cola persistente alternativa si la SD está ausente o falla. Tampoco recupera filas anteriores para enviarlas después por LTE.

## 6. Prueba celular implementada

`connectLTE()` primero espera una respuesta `AT`; luego inicializa TinyGSM, espera hasta 10 s el registro en red, informa operador y calidad de señal, y activa datos con el APN `internet.ideasclaro`. Si obtiene IP, `probeLTE()` abre TCP a `example.com:80`, envía `GET / HTTP/1.1` y muestra la primera línea recibida. Una respuesta `HTTP/1.1 200 OK` demuestra intercambio de paquetes en esa prueba. Es **HTTP sin TLS y solo para diagnóstico**; no se usa para enviar mediciones ni credenciales. Esta prueba no demuestra conectividad con el futuro servidor de ingestión.

Si aparece `LTE: no AT response from SIM7600.`, el fallo está antes de la SIM y del APN: revisar encendido/PWRKEY, alimentación, masa común, cruce TX/RX, pines UART TTL y velocidad. La ausencia del módem no impide por diseño la lectura de sensores ni el intento de registro en SD, aunque los intentos de conexión pueden demorar el ciclo. La calidad CSQ, una IP y el HTTP 200 tienen significados distintos: **solo el último confirma la petición de red completa**.

## 7. Trazabilidad de requerimientos y verificación

Esta matriz usa los requisitos publicados en [`README.md`](../../README.md), la arquitectura física [`Field Node PA.d2`](../../se/PA/Field%20Node%20PA.d2), el [plan IVV](../../se/PA/functional_versions_ivv_plan.md) y los [escenarios de prueba](../../se/PA/tests/READNE.md). Un vínculo de diseño no se contabiliza como requisito verificado sin un registro de ensayo.

| Necesidad / elemento | Evidencia en esta integración | Evaluación y verificación pendiente |
|---|---|---|
| `RDN3`: obtener datos del medidor Octave y del sensor de profundidad | Consultas Modbus para caudal/volumen y lectura ADC de nivel | **Parcial.** Se implementan dos interfaces; faltan ensayo con fuentes conocidas, verificación de unidades y resolución de la discrepancia con la descripción de sensor «24V One-Wire» del README. |
| `P1`: funcionar sin acceso local a Internet/energía | El fallo LTE no detiene el ciclo; el registro en microSD permite trabajar sin red | **Parcial.** La ausencia de red es tolerada; autonomía energética, alimentación solar y recuperación tras cortes no están demostradas. |
| `RND1` y `RND2`: tablero móvil y alertas | Datos locales disponibles como base de telemetría | **No implementados** por este firmware: no hay ingestión, tablero ni lógica de alertas. |
| `M1`, `M2`: gabinete y 48 h de exposición | Ninguna función de firmware verifica el encapsulado | **No evaluados.** Requieren montaje y ensayos ambientales/energéticos. |
| `CS1`: endurecimiento de ciberseguridad | El HTTP de diagnóstico no transporta mediciones | **No satisfecho para operación final.** Faltan autenticación de nodo, transporte cifrado, gestión de claves y revisión de amenazas. |
| Cadena SA/LA *Provide supply and demand data* | Medición y agrupación local; CSV en SD | **Parcial.** El almacenamiento/presentación central de la cadena sigue pendiente. |
| `FV2-I1` / `FV2-A1`: componentes y enlaces del banco | Pines y asignación ADC/RS485/UART/SPI documentados | **Inspección y análisis pendientes** sobre el equipo ensamblado. El modelo FV2 también incluye INA219 y ruta de potencia aún ausentes del sketch. |
| `FV2-T1`, `FN-S01`: carga nominal extremo a extremo | Solo hay petición HTTP genérica | **No satisfechos.** Se requieren envío de lotes reales, aceptación por el servidor, persistencia y repetición según el plan. |
| `FV2-T2`, `FN-S03`: salud del sensor y fallas | Modbus informa fallo; CSV registra cantidad de muestras | **Parcial.** Falta detectar entrada analógica abierta/cortada, publicar estado de salud y verificar transiciones. |
| `FN-S05`: pérdida y recuperación de WAN | Reintentos de LTE cada 30 s tras fallo | **Parcial.** Faltan inyección de fallas, telemetría de salud, contabilización de entregas perdidas y recuperación de carga al servidor. |
| `FN-S02`, `FN-S06`: reinicio y baja tensión | Inicio de interfaces y reintentos; no se mide batería | **Pendiente** ensayo repetido de arranque, perturbaciones de alimentación y transmisión LTE. |

**Discrepancia de configuración que debe cerrarse en control de cambios:** varios diagramas físicos y el plan FV2 citan **XIAO ESP32-C3**, mientras esta versión del firmware se compila para **XIAO ESP32-S3**. El README menciona sensor «24V One-Wire», pero el circuito y firmware actuales usan una salida analógica 0,5–4,5 V. Estas diferencias afectan pines, periféricos, interfaces y criterios de ensayo. El archivo [`se/Potential Expanded Requirements.md`](../../se/Potential%20Expanded%20Requirements.md) se identifica a sí mismo como archivo de un proyecto anterior; no se toma como línea base vigente sin aprobación de ingeniería.

## 8. Plan mínimo de evidencia para cerrar esta integración

| Prueba | Procedimiento | Evidencia y criterio de aceptación propuesto |
|---|---|---|
| Configuración | Fotografiar placa, variantes de módulo, divisor, conexiones, tarjeta y fuente; registrar versiones de librerías y firmware | Coincidencia entre `pins.h`, cableado y fotografías; identificar lector SD, sensor y variante del SIM7600 |
| Nivel analógico | Aplicar al menos 0,5; 1,1 y 4,5 V equivalentes a la salida del sensor, sin exceder la entrada ADC; medir ambos lados del divisor | Comparar `vAdc`, `vSensor` y altura serie/CSV con cálculo; registrar tolerancias e incertidumbre |
| Octave/RS485 | Leer valores conocidos o simulados, incluir desconexión y reconexión | Éxito de registros previstos, unidades confirmadas y campos vacíos/contadores coherentes al fallar |
| SD | Arrancar con y sin tarjeta; comprobar cabecera, varias filas y lectura tras corte controlado; repetir a 25 y 4 MHz si es necesario | CSV legible, una cabecera, campos y conteos correctos, recuperación observada tras insertar tarjeta |
| SIM7600 | Guardar traza de AT, operador, CSQ, IP y respuesta HTTP; probar desconexión/reconexión | `HTTP/1.1 200 OK` y continuidad de adquisición/CSV durante fallo; registrar tiempos reales de ciclo |
| Continuidad | Operar varias horas con condiciones representativas; registrar reinicios y lagunas | Sin bloqueo inexplicado; comparación entre muestras esperadas, muestras registradas y tiempos de actividad |

Los criterios numéricos de precisión del nivel, tolerancia de pérdida de muestras y tiempo máximo de recuperación deben acordarse antes de usar estos ensayos como aceptación formal. El plan IVV del repositorio define además repeticiones y escenarios más amplios para el nodo completo; esta tabla es el cierre mínimo de **esta primera integración**.

## 9. Dependencias y fuentes

- Configuración de compilación empleada para esta línea base: placa `esp32:esp32:XIAO_ESP32S3`, núcleo Arduino-ESP32 3.3.11, SdFat 2.3.0 y TinyGSM 0.12.0. El wrapper Octave está incluido bajo `integration/LevelSensor/src/`. Registrar en cada prueba las versiones efectivamente instaladas; una compilación no sustituye la validación con hardware.
- Firmware y asignación de pines: [`integration/LevelSensor/`](.).
- Modelos y requerimientos locales: [`README.md`](../../README.md), [`se/PA/Field Node PA.d2`](../../se/PA/Field%20Node%20PA.d2), [`se/PA/functional_versions_ivv_plan.md`](../../se/PA/functional_versions_ivv_plan.md), [`se/PA/tests/READNE.md`](../../se/PA/tests/READNE.md).
- [Seeed Studio: XIAO ESP32-S3 Getting Started](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started/) — correspondencia de pines.
- [Waveshare: SIM7600G-H 4G Module](https://www.waveshare.com/wiki/SIM7600G-H_4G_Module) — interfaz UART y opciones de alimentación de la familia de módulo modelada.
- [SdFat, repositorio del fabricante](https://github.com/greiman/SdFat) — API y capacidades de la biblioteca usada.
