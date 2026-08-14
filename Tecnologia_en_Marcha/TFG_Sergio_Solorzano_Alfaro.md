---
source: "Tecnologia_en_Marcha/TFG_Sergio_Solorzano_Alfaro.pdf"
title: "Sistema de control y monitoreo hídrico, basado en LoRaWAN™ para el acueducto principal de la Asociación Administradora del Acueducto Rural de Playa Sámara de Nicoya"
author: "Sergio Solórzano Alfaro"
converted_at: "2026-08-03T22:49:01Z"
conversion_notes: "Converted in four OCR chunks because the source PDF exceeds GLM-OCR limits (50 MB and 100 pages). Figure-description generation failed; OCR text and original captions were preserved where detected."
---

Instituto Tecnológico de Costa Rica

Escuela de Ingeniería Electromecánica


> **Figure Description:**
>
> _Descripción de figura no disponible._

LABORATORIO DELTA

<div align="center">

# “Sistema de control y monitoreo hídrico, basado en LoRaWAN $ ^{TM} $ para el acueducto principal de la Asociación Administradora del Acueducto Rural de Playa Sámara de Nicoya.”

</div>

<div align="center">

# Informe de Práctica de Especialidad para optar por el título de Ingeniero en Mantenimiento Industrial, con el grado académico de Licenciatura.

</div>

Sergio Solorzano Alfaro

Nicoya, Guanacaste, Junio 2021

Carrera Acreditada por:

engineerscanada


> **Figure Description:**
>
> _Descripción de figura no disponible._

ingénieurscanada



<div align="center">

# Hoja de datos

</div>

## Información del Estudiante:

Nombre: Sergio Solórzano Alfaro

Cedula: 1-1717-0434

Carné ITCR: 2016082625

Dirección de residencia en época lectiva: 300 metros Este del Liceo Experimental Bilingüe de San Ramón, San Isidro de San Ramón, Alajuela.

Telefono: 8774 5086

Correo electrónico: solorzanos117@gmail.com

## Información del Proyecto:

Título: Sistema de control y monitoreo hídrico, basado en LoRaWAN $ ^{TM} $ , para el acueducto principal de la Asociación Administradora del Acueducto Rural de Playa Sámara de Nicoya.

Asesor industrial: José Luis Jirón López.

Profesor guía: Ing. Juan José Rojas Hernandez.

Jurado evaluador:

- Ing. Alberto Garro Zavaleta.

- Ing. Oscar Monge Ruiz.

## Información de la Empresa:

Nombre: Asociación Administradora del acueducto rural de Playa Sámara.

Zona: Guanacaste.

Dirección: Contiguo a la delegación Policial de Playa Sámara de Nicoya. Provincia de Guanacaste, Nicoya, Sámara, 50205.

Actividad principal: Extracción, distribución y saneamiento de agua potable.

Contacto: José Luis Jirón López.

Telefono: 8860 9409



01 de junio, 2021

Escuela Ingeniería Electromecánica Instituto Tecnológico de Costa Rica Presente

Estimados señores (as):

Por medio de la presente queremos informarles que nuestra Asociación ha recibido el informe final del Proyecto de graduación "Sistema de control y monitoreo hídrico, basado en LoRaWAN $ ^{\mathrm{TM}} $ , para el acueducto principal de la Asociación Administradora del Acueducto Rural de Playa Sámara de Nicoya."

El proyecto fue realizado por el estudiante Sergio Solórzano Alfaro, carnet número 2016082625, para optar por el título de Ingeniero en Mantenimiento Industrial, con el grado académico de Licenciatura. El mismo se desarrolló con éxito en nuestras instalaciones, durante los meses de febrero a junio del 2021.

Atentamente,

Michael May Abbey

Deborah Nezii Waldron

Presidenta

Junta Directiva

RGXI

José Luis Jirón López

Administrador

ASOCIACION ADMINISTRADORA

ASAD.A.

SAMARA

Ced. Juri: 3-002-213342

Acueducto Rural de Samara de Nicoya

## Resumen

Los sistemas de abastecimiento de agua han sido esenciales en la mejora de la calidad de vida de las personas. En Costa Rica cerca del 29 % de la distribución de agua potable se lleva a cabo por las Asociaciones Administradoras de Acueductos Rurales (ASADAS), promoviendo la salud pública, la seguridad y la base para el desarrollo económico en el sector rural del país. Sin embargo, estas asociaciones comúnmente han operado con una insuficiente inversión en infraestructura, un escaso monitoreo de información hídrica y la ausencia de herramientas tecnológicas orientadas a su operación.

El presente proyecto ataca las necesidades expuestas por la administración de la ASADA de Playa Sámara de Nicoya. La ASADA solicito la autonomía operativa del sistema de bombeo y una recopilación de datos hídricos en tiempo real, que les permita impulsar mejoras en sus operaciones. En este trabajo se expone la implementación de tecnologías del internet de las cosas (IoT) como herramienta clave para respuesta autónoma del sistema de bombeo para demandas variables y la recopilación de datos hídricos. La información recopilada representa una herramienta clave en la evolución hacia una gestión hídrica digitalizada para el acueducto principal de ciudad turística de Sámara.

Se crearon tres dispositivos llamados IoT ASADAS V1.0, los cuales utilizan sistemas en chip Heltec LoRa 32 V2 para la automatización de acueductos rurales aprovechando lenguajes de programación de acceso libre, dispositivos compactos y bajos requerimientos energéticos asociados a una inversión financiera accesible para ASADAS. El software y hardware diseñados habilitan la capacidad de telecomunicación por LoRa™ a medidores ultrasónicos Octave, permitiendo la interpretación de mediciones de volumen y caudal hídrico promedio con un porcentaje de error de 0 % y 0,73 %, respectivamente.

Se plantea el uso de comunicación por red LoRaWAN™, protocolo clase C, para la implementación de un sistema de comunicación (internet de las cosas) en el acueducto de Playa Sámara. Dicho sistema posee la capacidad de intercomunicación de datos hídricos en tiempo real y la visualización de datos a la plataforma en internet de IoT Adafruit IO, relacionados a la operación del acueducto principal. Además, se diseñó un circuito de control eléctrico que posibilita la operación automatizada del sistema de bombeo principal, al vincular las señales enviadas por el dispositivo IoT ASADAS V1.0 con el mecanismo de arranque para cada bomba. Finalmente, se justifica la rentabilidad de implementación del sistema de IoT en comparación con las pérdidas financieras asociadas a la operación actual del acueducto principal de la ASADA Sámara.

Palabras Claves: ASADAS, LoRaWAN $ ^{ \mathrm{TM}} $ , Agua Digital, IoT, Octave, Automatización, Monitoreo.

## Abstract

Water supply systems have been essential in improving people’s quality of life. In Costa Rica, about 29% of potable water distribution is carried out by the Rural Aqueduct Management Associations (ASA-DAS), promoting public health, safety, and the basis for economic development in the rural sector of the country. However, these associations have commonly operated with insufficient investment in infrastructure, little water monitoring information, and the absence of technological tools aimed at their operation.

This project addresses the needs expressed by the administration of the ASADA of Playa Sámara de Nicoya. This ASADA requested the operational autonomy of the pumping system and a collection of water data in real time, which allows them to drive improvements in their operations. In this work, the implementation of Internet of Things (IoT) technologies is exposed as a key tool for the autonomous response of the pumping system for variable demands and the collection of water data. The information collected represents a key tool in the evolution towards digitized water management for the main aqueduct of the tourist city of Sámara.

Three devices called IoT ASADAS V1.0 were created, which use systems in Heltec LoRa 32 V2 chip for the automation of rural aqueducts taking advantage of free access programming languages, compact devices and associated low energy requirements to an accessible financial investment for ASADAS. The software and hardware designed enable the telecommunication capability by LoRa™ to Octave ultrasonic meters, allowing the interpretation of volume and average water flow measurements with an error percentage of 0% and 0.73%, respectively.

The use of network communication LoRaWAN™, class C protocol, is proposed for the implementation of a communication system (internet of things) in the aqueduct of Playa Sámara. Said system can intercommunicate water data in real time and display data to the IoT Adafruit IO internet platform, related to the operation of the main aqueduct. In addition, an electrical control circuit was designed that enables automated operation of the main pumping system, by linking the signals sent by the device IoT ASADAS V1.0 with the starting mechanism for each pump. Finally, the profitability of implementing the IoT system is justified in comparison with the financial losses associated with the current operation of the main aqueduct of ASADA Sámara.

Key Words: ASADAS, LoRaWAN $ ^{\mathrm{TM}} $ , Digital Water, IoT, Octave, Automation, Monitoring.

## Agradecimientos

Mis más sinceros agradecimientos a la comunidad de Playa Sámara y los colaboradores de la ASADA de

Playa Sámara, quienes me confiaron la dirección de este proyecto y me apoyaron, desde todos los

ámbitos, durante la ejecución del mismo.

Un agradecimiento especial a mi profesor guía Juan José Rojas y a los integrantes del Laboratorio Delta del primer semestre del 2021, quienes crearon un ambiente de colaboración y aprendizaje, que sin duda posibilitó el éxito del proyecto.

Quiero agradecer a todos mis familiares y todas mis amistades que, de forma directa e indirecta participaron en el desarrollo del proyecto y moldearon mi formación profesional.

Finalmente, un profundo agradecimiento a los profesores y funcionarios del Tecnológico de Costa Rica, quienes forjaron, durante cinco años, el profesional que busco ser.

Dedicatoria

A mi madre y a mi padre, cimientos de todos los proyectos que decide emprender.

## Indice general

Nomenclatura 2

1. Introducción 4

1.1. Reseña de la Empresa 5

1.1.1. ASADA Sámara 5

1.2. Antecedentes 6

1.2.1. El recurso hídrico en Costa Rica 6

1.2.2. El porcentaje de agua no facturada 7

1.2.3. Los esfuerzos país por la reducción del porcentaje de agua no facturada en ASADAS 7

1.2.4. Tecnologías Inteligentes de Infraestructura de Agua. 8

1.3. Planteamiento del Problema 9

1.3.1. Contexto del problema 9

1.3.2. Problema por resolver 11

1.3.3. Requerimientos de diseño 12

1.4. Objetivo General 14

1.5. Objetivos Específicos 14

1.6. Justificación 15

2. Metodología 17

2.1. Metodología seguida para el cumplimiento de los objetivos planteados 18

2.2. Definición del alcance de la investigación 21

2.3. Viabilidad para el desarrollo 21

3. Marco Teórico 22

3.1. La gestión de pérdidas hídricas 22

3.2. Conceptos de comunicación por radiofrecuencia . 23

3.2.1. Antenas y propagación de señales de radio . 23

3.3. Protocolo LoRaWAN™ . 26

3.3.1. Clases de comunicación en nodos . 27

3.3.2. Seguridad LoRaWAN™ . 27

3.3.3. Regulaciones en LoRa™ . 28

3.4. Protocolo MQTT . 28

3.5. Sistemas de IoT . 29

3.6. Definiciones relacionadas con placas de circuito impreso . 30

3.7. Sistema en Chip ESP32 . 34

3.8. Medición hídrica ultrasónica . 35

3.9. Sensores de nivel para tanques de agua potable . 36

4. Arquitectura del Sistema de IoT 37

4.1. Arquitectura de funcionamiento . 37

4.2. Programación de dispositivos . 39

4.2.1. Controlador maestro . 39

4.2.2. Nodos de medición y control . 47

4.3. Comunicación telemétrica mediante red LoRaWAN™ . 48

4.3.1. Cálculo del presupuesto de potencia de la señal . 51

4.3.2. Validación de comunicación en red LoRaWAN™ en Sámara . 52

4.4. Permisos y capacitaciones en el uso de la plataforma. 55

5. Comunicación digital de flujómetros Octave 57

5.1. Lógica de comunicación por pulsos del flujómetro Octave . 58

5.1.1. Funcionamiento del firmware de medición . 60

5.2. Experimentos de validación y resultados obtenidos para la comunicación con el módulo SSR Octave . 65

5.2.1. Octave de 50 mm (2 in) instalado en el TEC. 65

5.2.2. Octave de 100 mm (4 in) presente en el acueducto de la ASADA. 69

5.2.3. Simulación de flujos variables con generador de señales. 72

6. Diseño electrónico 76

6.1. Consideraciones y requerimientos establecidos para el diseño del circuito electrónico . 76

ÍNDICE GENERAL IX

6.2. Dispositivos involucrados . . . . .

10.4.3. Paso 3. Soldar las puntas de los cables de conexión en el punto de soldadura. . . . 127

10.4.4. Paso 4: Cortar un trozo de cinta de níquel que permita unir la cantidad de celdas seleccionada. . . . . 

## Índice de tablas

4. 1. Caudales típicos de operación en el acueducto de playa Sámara. . . . . 

## Índice de figuras

1.1. Vista en elevación del Acueducto principal de distribución de la ASADA de Playa Sámara. 9

1.2. Acueducto principal de distribución, ASADA-Sámara. 10

1.3. Requerimientos del sistema a diseñar para el acueducto rural de Playa Sámara de Nicoya. 12

1.4. Subsistemas del sistema de control y monitoreo en línea para el acueducto. 13

2.1. Metodología de diseño del sistema de control eléctrico y justificación financiera. 18

2.2. Metodología de diseño del sistema de comunicación. 19

2.3. Metodología para la creación de dispositivo electrónico. 20

3.1. Balance hídrico según AWWA. [1] . 23

3.2. Esquema del presupuesto de potencia de un enlace por radio. [2] . 24

3.3. Arquitectura de comunicación pormaya de LoRaWAN™. 26

3.4. Protocolo de comunicación LoRaWAN™. 28

3.5. Modelo de publicación y suscripción de MQTT. 29

3.6. Diagrama esquemático para un sensor oscuro con LDR. 31

3.7. PCB de doble capa diseñada con el software EAGLE [3]. 31

3.8. Pads en distintos elementos [3]. 32

3.9. Partes de PCBs terminadas [3]. 33

3.10. 1- Vía through-hole, 2- Blind vía 3- Burried vía [3]. 34

3.11. Principio de la medición hídrica ultrasónica. [4] . 35

4.1. Arquitectura del sistema de IoT. 38

4.2. Configuración básica para el Gateway en tanque principal. 39

4.3. Configuración básica para los Nodos del acueducto. 40

4.4. Ejemplo de Feeds creados en la plataforma Adafruit IO. 43

4. 5. Ejemplo de Triggers creados en la plataforma Adafruit IO. . . . . 

6.3. Conexión para alimentación de potencia a partir del circuito de gestión de carga solar

DFRobot. . . . . 

10.6. Acomodo de cintas de níquel de 6 mm en las celdas 18650. 127

10.7. Estación de soldadura por punto armada. 128

10.8. Puntos de soldadura por pulso en la cinta de níquel de 6 mm. 129

10.9. Cobertura de Kapton para la batería de 4 celdas. 130

10.10Colocación de tubo termo-retráctil para la batería de 4 celdas. 131

10.11Baterías de 4, 3 y 2 celdas finalizadas. 131

10.12Carga electrónica en DC RIGOL DL3021. 132

10.13Carga completa de batería de celdas 18650. 133

10.14Descarga completa de batería de celdas 18650. 134

## Nomenclatura

<table border="1"><tr><td>AIO</td><td>Plataforma de IoT Adafruit IO.</td></tr><tr><td>ANF</td><td>Agua no facturada.</td></tr><tr><td>ARESEP</td><td>Autoridad Reguladora de los Servicios Públicos.</td></tr><tr><td>ASADAS</td><td>Asociaciones administradoras de los Sistemas de Acueductos y Alcantarillados comunales en Costa Rica.</td></tr><tr><td>AWWA</td><td>American Water Works Association(Asociación Estadounidense de Obras Hidráulicas).</td></tr><tr><td>AyA</td><td>Instituto Costarricense de Acueductos y Alcantarillados.</td></tr><tr><td>BCIE</td><td>Banco Centroamericano de Integración Económica.</td></tr><tr><td>dB</td><td>Decibel.</td></tr><tr><td>DINA</td><td>Dirección Nacional del Agua.</td></tr><tr><td>ESPH</td><td>Empresa de servicios públicos de Heredia.</td></tr><tr><td>FSLP</td><td>Free Space Path Loss(Pérdidas por espacio libre).</td></tr><tr><td>GAM</td><td>Gran Área Metropolitana.</td></tr><tr><td>GPIO</td><td>General Purpose Input/Output(Entrada/salida de uso general)</td></tr><tr><td>GRAFCET</td><td>Graphe Fonctionnel de Commande Etape Transition(Diagrama de control con etapas y transiciones).</td></tr><tr><td>IoT</td><td>Internet of Things(Internet de las cosas).</td></tr><tr><td>IWA</td><td>International Water Association(Asociación Internacional del Agua).</td></tr><tr><td>LNA</td><td>Laboratorio Nacional de Aguas.</td></tr><tr><td>LoRa</td><td>Long Range(Largo Alcance).</td></tr><tr><td>LoRaWAN</td><td>LoRa Wide Area Network(Red de área amplia LoRa™).</td></tr></table>

LPWAN Low Power Wide Area Network (Red de área amplia de baja potencia).

MINAE Ministerio de Ambiente y Energía.

MQTT Message Queuing Telemetry Transport (Transporte de telemetría de Message Queue Server).

NRW Non-revenue Water (Agua no contabilizada).

ORAC Oficina Regional de Acueductos Comunales.

PCB Print Circuit Board (Placa de Circuito Impreso).

PELTEC Programa de Energías Limpias del TEC.

PNGIRH Plan Nacional de Gestión Integrada del Recurso Hídrico.

PNUD Programa de las Naciones Unidas para el Desarrollo.

RANC-EE Proyecto de Reducción de Agua No Contabilizada y Eficiencia Energética.

SENARA Servicio Nacional de Aguas Subterraneas, Riego y Avenamiento.

SETENA Secretaría Técnica Nacional Ambiental.

SIMASTIR Sistema de Monitoreo de Agua Subterránea en Tiempo Real.

SINIGIRH Sistema Nacional de Informacion para la Gestion Integrada del Recurso Hídrico.

SoC System on Chip (Sistema en Chip).

SWIT Smart Water Infrastructure Technologies (Tecnologías Inteligentes de Infraestructura Hídrica).

## Introducción

El agua es un recurso vital para el desarrollo de la vida del planeta. Está relacionada con todas las actividades cotidianas que realizamos como seres humanos. Esto implica un enorme y complejo sistema de distribución que se encarga de transportar millones de litros de agua potable, desde las fuentes hídricas hasta las llaves de consumo residencial, agrícola e industrial. Sin embargo, hoy en día las fuentes de agua se ven constantemente amenazadas. La creciente presión global, asociada al aumento demográfico, la contaminación y el cambio climático, significan para el sector del agua retos apremiantes con respecto a la eficiencia de la gestión de los recursos hídricos, los cuales son cada vez más escasos y poco fiables. Para enfrentar estos desafíos, es necesario un cambio fundamental en la forma como se administra el agua. [5]

Costa Rica goza de un cuantioso recurso hídrico, esto permitió que, en el 2018, se alcanzara una cobertura de agua intradomiciliaria del 97,8 %, de la cual un 92,4 % es de calidad potable. [6] A pesar de su abundancia, los recursos hídricos enfrentan severos retos, producto del crecimiento de la población, la industrialización, el desarrollo inmobiliario, la agricultura intensiva, y la mala planificación del uso del suelo.

En Costa Rica, se prevé que para el año 2020 la precipitación disminuya en un 15 % y para el 2050 en un 35 %. [7] En la provincia de Guanacaste se espera que para el año 2080, la precipitación anual se reducirá en un 65 %, profundizando la escasez de agua en la zona. [8]

En Costa Rica, las Asociaciones Administradoras de Sistemas de Acueductos y Alcantarillado (ASADAS) proporcionan servicios de agua potable y saneamiento a un aproximado del 28,7% de la población del país, principalmente en zonas suburbanas y comunidades rurales. Desafortunadamente, la mayoría de las ASADAS costarricenses se encuentran en una situación desprovista de personal técnicamente calificado, acceso a tecnología y asesorías en planes de inversión. Esto ha posicionado a las ASADAS, encargadas de la sostenibilidad y distribución del recurso hídrico, como instituciones vulnerables ante las amenazas derivadas del cambio climático. [9] Desde esta perspectiva nacional, la digitalización se convierte en un habilitador que permitirá al sector del agua, hacer la necesaria e importante transición, hacia un enfoque basado en la recopilación de datos de forma inteligente para un proceso de toma de decisiones mejor informado; que garantice soluciones integrales. Esto implica cambios en la cultura organizacional junto con la integración de herramientas digitales que apoyen el progreso del sector del agua a lo largo de la

curva de madurez digital, desde el despliegue oportunista e innovador para dar solución a los problemas relacionados con el agua. [5]

El presente trabajo tiene como objetivo, diseñar un sistema de control y monitoreo digital que facilite la gestión eficiente del recurso hídrico a la ASADA de Sámara (Nicoya). Específicamente se analizará la situación que enfrenta el acueducto de la ASADA Sámara, ubicada en la provincia de Guanacaste, en temas de distribución de agua y aprovechamiento del recurso hídrico. Actualmente, este acueducto posee una importante oportunidad de desarrollo tecnológico. Especialmente en la automatización de la operación de su sistema de bombeo, el control de nivel del tanque principal y la obtención de datos de consumo y demanda de agua en tiempo real, para el desarrollo en la gestión del servicio público de agua a cargo de la ASADA.

Partiendo de esta necesidad, se propuso la intercomunicación de dispositivos de hidro medición y control eléctrico, mediante el uso de una red LoRaWAN $ ^{TM} $ y el protocolo de comunicación MQTT para la publicación de datos en la plataforma de IoT Adafruit IO. Para lograr lo anterior, se diseñó un sistema de IoT que intercomunica, en localizaciones distintas, tres medidores de flujo ARAD Octave, dos sensores de nivel y el tablero de control del sistema de bombeo. Con el objetivo de optimizar la operación y automatizar el registro de mediciones de flujo y volumen en el acueducto principal.

El proyecto contempló el diseño y fabricación del circuito impreso (PCB), el diseño de la alimentación eléctrica de los dispositivos, mediante energía solar, el rediseno del tablero de control para el sistema de bombeo, el diseño e implementación de la red LoRaWAN $ ^{TM} $ en Playa Sámara y la programación del software de los nodos de comunicación y la pasarela de datos (Gateway) hacia internet utilizando un microcontrolador Heltec LoRa 32 V2.

La solución producto de este proyecto, fue planteada y diseñada para que sea de utilidad para las cientos de ASADAS restantes en el país, que posean necesidades similares dentro del esquema de operación electromecánico común de un acueducto rural. Tomando en cuenta la flexibilidad técnica del sistema para adaptarse a dispositivos existentes en ASADAS a un bajo costo monetario de implementación.

## 1.1. Reseña de la Empresa

## 1.1.1. ASADA Sámara

La empresa donde se efectuó el proyecto fue la Asociación Administradora del Sistema de Acueducto y Alcantarillado (ASADA) de Playa Sámara, ubicada en el cantón de Nicoya, en la provincia de Guanacaste. Esta organización se dedica principalmente a la extracción, potabilización y distribución de agua potable que abastece a más de 450 abonados, presentes en la comunidad de Playa Sámara. El recurso humano con el que cuenta la ASADA está compuesto por el administrador general, una secretaria y una cuadrilla de dos fontaneros. Adicionalmente, la ASADA es coordinada por una Junta Directiva nombrada por la comunidad.

## 1.2. Antecedentes

## 1.2.1. El recurso hídrico en Costa Rica

En Costa Rica el agua juega un papel fundamental en la agricultura, el consumo humano, la producción industrial, el turismo y la generación hidroeléctrica. La extracción hídrica total nacional para el 2013 alcanzó los 2,35 km $ ^{3} $ , destacando el sector agrícola con una extracción equivalente al 57 % del total de las extracciones. Las extracciones para el sector municipal alcanzaron el 32 % , y las extracciones para el sector industrial alcanzó el 11 %. De este volumen total extraído, el 66,2 % viene de fuentes superficiales y el 33,8 % de fuentes subterráneas. [10]

En el país existen múltiples organizaciones involucradas en la regulación global de la protección, extracción, uso, gestión y administración del recurso hídrico. En primera instancia el Instituto Costarricense de Acueductos y Alcantarillados (AyA) fue creado como órgano rector del recurso hídrico del país. En la actualidad, el Ministerio de Ambiente y Energía (MINAE) es el órgano rector con mayor relevancia. El MINAE se encarga de elaborar y dictar políticas, reglamentos y directrices en materia de manejo, uso y protección del recurso agua. Específicamente, por medio de la Dirección Nacional del Agua (DINA), como órgano jurídico adscrito al MINAE. En materia de conservación del agua, la responsabilidad es principalmente del MINAE; sin embargo, la rectoría la comparte con otros órganos del Estado como el Consejo Nacional Ambiental, Secretaría Ejecutiva del Consejo, la Secretaría Técnica Nacional Ambiental (SETENA) y el Servicio Nacional de Aguas Subterráneas, Riego y Avenamiento (SENARA). [11]

Por otra parte, la normativa relativa a la prestación del servicio de agua es regulada por Autoridad Reguladora de los Servicios Públicos (ARESEP) en coordinación con Ministerio de Salud (MS) y los criterios del Laboratorio Nacional de Aguas (LNA), perteneciente al AyA. [11] Adicionalmente, el país cuenta con 275 leyes vigentes, relacionadas con el agua y más de 1500 facilitadores del servicio en todo el territorio nacional. [12] Estos entes facilitadores se clasifican en cinco operadores de servicios de agua potable y saneamiento en Costa Rica. El AyA como principal prestadora del servicio, los Gobierno Locales (Municipalidades), la Empresa de servicios públicos de Heredia (ESPH), empresas privadas y las Asociaciones Administradoras de Sistemas de Acueductos y Alcantarillado (ASADAS).

Las ASADAS son todas aquellas asociaciones administradoras de sistemas de acueductos y alcantarillados comunales que se rigen por el Reglamento de las Administradoras de Sistemas de Acueductos y Alcantarillados Comunales. Se caracterizan por tener firmado un Convenio de Delegación con el AyA, para la prestación del servicio de agua. Según el Anuario estadístico (2012-2018) publicado por el AyA, las ASADAS poseen el 80 % de las fuentes de aprovechamiento de agua de Costa Rica, de las cuales el 75 % son nacientes. [13] Las anteriores cifras muestran la importante cantidad de fuentes de agua que están a cargo de las ASADAS. De acuerdo con informes de la Oficina Regional de Acueductos Comunales (ORAC), de la UEN Gestión de ASADAS, al finalizar el 2019; existen 1427 ASADAS, con 407 mil conexiones de agua, abasteciendo cerca 1,5 millones de habitantes costarricenses. [14]

## 1.2.2. El porcentaje de agua no facturada

Las pérdidas de agua han sido un problema para los sistemas distribuidores por mucho tiempo, pero la terminología y los cálculos de su concepto han evolucionado en el tiempo. Cuando se gestiona el flujo de agua de entrada y salida en un sistema de distribución, las empresas tradicionalmente se han referido a las pérdidas de agua como "agua no contabilizada". Sin embargo, la falta de términos y definiciones estandarizados ha generado desafíos de comunicación entre las empresas y mediciones inconsistentes que dificultan su adecuada comparación (benchmarking). [15] Esto llevó a la Asociación Internacional del Agua (IWA, por sus siglas en inglés International Water Association) en colaboración con la Asociación Estadounidense de Obras Hidráulicas (AWWA, por sus siglas en inglés American Water Works Association) a desarrollar una metodología de auditoría de agua, recomendada para contabilizar y controlar pérdidas en sistemas de distribución de agua potable.

En el 2016, AWWA publicó la cuarta edición del Manual de prácticas de abastecimiento de agua M36, Water Audits and Loss Control Programs, ver [1]. Este manual se utiliza como guía para las empresas de agua potable en cómo utilizar la metodología de auditoría del agua para controlar económicamente pérdidas de agua e ingresos mediante el seguimiento de la eficacia del traslado de agua. Utiliza definiciones consistentes y términos sólidos que recomienda ser adoptados por todos los servicios de agua potable. Esta metodología desalienta el uso del término "agua no contabilizada" para evaluar la pérdida de agua y en su lugar recomienda el uso del término "agua no facturada" (NRW, por sus siglas en inglés Non Revenue Water). [1]

En Costa Rica, según datos del Estudio de Factibilidad del Proyecto de Reducción de Agua No Contabilizada y Eficiencia Energética (RANC-EE) se estimó para los acueductos de la GAM un 47,4 % de agua no contabilizada (NRW) (41,2 % de pérdidas físicas o reales y 6,2 % de pérdidas comerciales o aparentes) y para el conjunto de los sistemas periféricos un 57,2 % de NRW (52,2 % de pérdidas físicas o reales y 5,0 % de pérdidas comerciales o aparentes). [16] Los esfuerzos del gobierno costarricense buscan reducir este porcentaje en un 17 %. Por otra parte, el Banco Mundial recomienda que el índice de NRW sea menor al 25 %.

## 1.2.3. Los esfuerzos país por la reducción del porcentaje de agua no facturada en ASADAS

El Instituto Costarricense de Acueductos y Alcantarillados (AyA) estableció un plan de acción para reducir en un 17% el índice de agua no facturada y aumentar en un 7,5% la eficiencia energética al 2024, gracias a la implementación de un plan de 261 acciones del Proyecto RANC-EE. Este proyecto fue financiado en el 2015 por el Banco Centroamericano de Integración Económica (BCIE) con 130 millones US$. [17] Para lograr esta meta, se destacan dos soluciones en plan de acción por parte de la institución, que se alinean al uso de las IoT. Una es la implantación de una plataforma tecnológica moderna, basada en criterios de inteligencia de datos ("big data" y "smart water") y la otra es la implementación de un sistema de detección temprana de fugas, mediante el monitoreo de caudales y el uso de inteligencia artificial. [18]

En adición a los constantes esfuerzos que hace el AyA, por medio de sus múltiples órganos institucionales, por el mejoramiento de las condiciones que enfrentan la ASADAS, destaca uno de los proyectos más

importantes que ha sido puesto en marcha en Costa Rica para el mejoramiento operativo de las ASADAS, es el Proyecto AyA-PNUD-CRUSA. Según la información recopilada mediante un formulario, diseñado en el proyecto AyA-PNUD-CRUSA, solamente el 6% de las ASADAS conoce su porcentaje de agua no facturada mediante el uso de macro y micro medición. [7]

## 1.2.4. Tecnologías Inteligentes de Infraestructura de Agua.

Las tecnologías inteligentes de infraestructura del agua (SWIT, por sus siglas en inglés, Smart Water Infrastructure Technologies) están comenzando a revolucionar el suministro del servicio. Mientras que las empresas proveedoras tradicionales dependían del trabajo manual para llevar a cabo simples actividades de monitoreo del sistema, como comprobar los niveles de los reservoirios, cerrar válvulas para controlar la presión del agua y leer los contadores para calcular el consumo o enviar las facturas a los clientes. Las empresas proveedoras de servicios que adoptan las SWIT están completamente automatizadas. [19]

La Asociación Internacional del Agua (IWA), en su Programa de Agua Digital, está participando activamente en todo el sector internacional del agua para apoyar la adopción de un enfoque más inteligente para la gestión del agua, destacando las ventajas de la digitalización como un habilitador clave en el camino. Es aquí donde nace el concepto de "agua digital"; la Asociación del Agua del Reino Unido define el agua digital como la "explotación de datos para crear conocimientos prácticos mejorados y una mejor toma de decisiones", en temas de aprovechamiento, distribución y saneamiento del recurso hídrico. [20] Involucrando los componentes del IoT a la administración de recursos hídricos. La mayoría de las soluciones que involucran IoT y SWIT utilizan modulación de radiofrecuencia y protocolos de red para la intercomunicación de los dispositivos de medición y control. Uno de los tipos de modulación incipiente en la industria es LoRa $ ^{TM} $ (por sus siglas en inglés, Long Range).

## 1.3. Planteamiento del Problema

En las secciones anteriores se ha comentado sobre el contexto de las ASADAS a nivel nacional junto con los distintos retos y rezagos que enfrenta la infraestructura a cargo de estas organizaciones. Para efectos de este proyecto se enfocará en las necesidades específicas de la ASADA de Sámara de Nicoya.

## 1.3.1. Contexto del problema

La red de acueductos de la ASADA de Playa Sámara, actualmente utiliza un sistema de abastecimiento por gravedad a sus abonados, mediante un tanque principal y un tanque secundario, como se observa en las figuras 1.1 y 1.2. Toda el agua utilizada por el acueducto es extraída de dos pozos y bombeada al tanque principal por un sistema de bombeo principal. El agua enviada al tanque secundario es bombeada desde el tanque principal, para abastecer a los abonados que se encuentran a una mayor altitud respecto al tanque principal. El sistema cuenta con tres macro medidores de flujo hídrico, de tipo ultrasónicos modelo Octave, ubicados en tres puntos distintos del acueducto principal; uno a la salida de los pozos (producción hídrica), otro a la salida del sistema de rebombeo (caudal de rebombeo) y otro a la salida del tanque principal de abastecimiento (distribución hídrica general).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 1.1: Vista en elevación del Acueducto principal de distribución de la ASADA de Playa Sámara. Fuente: Elaboración propia, AutoCAD 2020. Basado en información de GoogleEarth.

</div>

Los tiempos de operación del sistema de bombeo principal son regulados mensualmente. Estos tiempos de operación son calculados manualmente por el administrador de la ASADA a partir de una aproximación del tiempo que le tomará al agua bombeada para alcanzar el nivel máximo del tanque. Lo anterior, tomando en cuenta la posible demanda y producción del acueducto. La programación de los periodos de encendido y apagado del sistema se dan de forma manual mediante dos temporizadores ubicados en cada uno de los

tableros de control de las dos bombas.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 1.2: Acueducto principal de distribución, ASADA-Sámara. Fuente: Elaboración propia, AutoCAD 2020. Basado en información de GoogleEarth.

</div>

Si bien el sistema de bombeo cumple la función de trasladar el agua de los posos al tanque principal, el actual mecanismo de funcionamiento supone inconvenientes para la administración de la ASADA, especificamente relacionados a la eficiencia en el aprovechamiento del recurso hídrico. La principal desventaja es la constante necesidad de regular y vigilar el tiempo de encendido del sistema de bombeo principal, debido a que existen fluctuaciones de la demanda en la comunidad turística de Sámara (temporadas de alta y baja cantidad de turistas en la zona).

Ocurre que el sistema es programado para responder a una demanda baja, cuando la demanda real es alta, provocando que se agote el agua en el tanque principal (mientras las bombas están apagadas) e interrumpiendo el servicio a los abonados. Caso contrario en que el temporizador se programa para responder a una demanda alta y en realidad la demanda es baja, provocando rebalses en el tanque principal y encendidos innecesarios del sistema de bombeo. Es decir, el sistema de bombeo actual es

incapaz de responder a fluctuaciones en la demanda de agua potable.

Por otra parte, la administración de la ASADA de Playa Sámara ha determinado que existe un porcentaje promedio de agua no facturada (NRW) del 40 %, en algunas ocasiones hasta un 50 %, atribuidas principalmente a la operación ineficiente del actual sistema de bombeo.

De acuerdo con la Red internacional de evaluación comparativa de servicios de agua y saneamiento (IBNET, por sus siglas en inglés The International Benchmarking Network for Water and Sanitation Utilities) el promedio mundial de este indicador se encuentra entre el 30% y 35%, dependiendo de la región geográfica dónde se compare. [21] IWA sugiere establecer un nivel aceptable de NRW en el punto en que los costos de recobrar el agua perdida sean iguales al valor de las cantidades recuperadas. [19] El desconocimiento de un NRW aceptable es un problema administrativo importante para la ASADA. Por lo que el alcance de este trabajo plantea atacar esta carencia de conocimiento al ofrecer las herramientas necesarias, con un enfoque de solución desde IoT, para la obtención de información que posibilite reducir las pérdidas de agua, reflejadas en el NRW, que se asocien a la tubería principal del acueducto, el tanque principal de almacenamiento y, de forma implicita, en el sistema de control de las bombas.

## 1.3.2. Problema por resolver

La Asada plantea la necesidad de una solución ingenieril que permita un control automatizado del sistema de bombeo, que evite el rebalse o vaciamiento de agua en tanque de abastecimiento principal. Adicionalmente, se solicito que la solución al problema que permitiera recopilar y visualizar datos hídricos relacionados con la operación del acueducto desde cualquier dispositivo, aprovechando la capacidad de comunicación de los flujómetros ultrasónicos instalados en el acueducto.

## 1.3.3. Requerimientos de diseño

A partir de las necesidades expuestas por la administración relacionadas, con el problema por resolver, se derivan los requerimientos para el diseño de la solución ingenieril. Principalmente se requiere de un sistema que maneje la operación del acueducto y recopile la mayor cantidad de información del mismo. Al analizar estos requerimientos de más alto nivel, resultan los requerimientos de funcionamiento específicos del sistema.

El sistema de automatización debe coordinar la operación del sistema de bombeo, a partir de los datos recopilados con relación al presente estado del acueducto, entiéndase el nivel del tanque actual junto con los caudales de demanda y producción manejados. Adicionalmente, el sistema debe ser capaz de adquirir la información hídrica en tiempo real para ser trasladada hasta el usuario y almacenada en algún tipo de base de datos. Además, es necesario que el traslado de información se dé de forma inalámbrica, considerando que los puntos de recolección de datos hídricos se encuentren lo suficientemente distanciados entre sí, que generan una comunicación alambraba poco viable.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 1.3: Requerimientos del sistema a diseñar para el acueducto rural de Playa Sámara de Nicoya. Fuente: Elaboración propia, Visio.

</div>

De esta forma, se debe instalar una red independiente de comunicación que permita intercomunicar los puntos de medición hídrica y se debe incorporar una salida de datos hacia internet (Gateway) para que los datos puedan ser visualizados desde cualquier dispositivo. Para alcanzar una red de comunicación dentro del acueducto principal y una salida de los datos se necesita de acceso a internet en algún lugar del acueducto.

Se requiere que cada la medición de caudales hídricas se dé en un intervalo menor a los 2 minutos. Esto debido a que el sistema que publica y suscribe la información a la plataforma en la nube, requiere mantener la conexión a partir de publicaciones de datos. De esta forma, se dispone que las mediciones deben ser tomadas cada 2 minutos, por ende, los caudales reportados serán caudales promedio transcurridos durante ese mismo intervalo. Este requerimiento específico del sistema fue descubierto durante el desarrollo del mismo, por temas de comunicación por protocolo MQTT con la plataforma en línea que se seleccionó para visualizar los datos. Si bien no fue un requerimiento que se tomó para la primera aproximación a la solución del problema, es importante considerarlo para este apartado, con el objetivo de que el lector tenga un panorama completo de los requerimientos del sistema.

Luego, se examinan los requerimientos generales del sistema, relacionados con las condiciones físicas en dónde deberá operar el mismo. Considerando que la disponibilidad de la electricidad en el acueducto es limitada para la mayoría de los puntos donde se ubican los medidores de flujo, los dispositivos involucrados en el sistema de monitoreo y control deben ser energéticamente autónomos. Además, las condiciones ambientales en el acueducto de Playa Sámara se caracterizan por ser altamente corrosivas y húmedas. De esta forma, los dispositivos deben ser lo suficientemente robustos para soportar dichas condiciones o estar adecuadamente protegidos ante las mismas.

De esta forma, se decide atacar los requerimientos de sistema general al dividirlo en subsistemas. Un subsistema que se encargue la comandar la comunicación de todos los agentes involucrados en el sistema general, otro subsistema para el control automatizado del bombeo y un subsistema que se encargue de la medición de datos hídricos provenientes de los flujómetros. (Ver figura 1.4).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 1.4: Subsistemas del sistema de control y monitoreo en línea para el acueducto Fuente: Elaboración propia.

</div>

## 1.4. Objetivo General

Desarrollar un sistema de control y monitoreo en línea que posibilite la operación automática del sistema de bombeo y la contabilización de agua asociada con la operación del acueducto principal de la ASADA de Sámara de Nicoya.

## 1.5. Objetivos Específicos

1. Diseñar un sistema de comunicación, basado en LoRaWAN $ ^{TM} $ , que permita la visualización de datos hídricos en tiempo real, desde una plataforma en internet.

2. Crear un dispositivo electrónico que incorpore la capacidad de telecomunicación a medidores ultrasonicos Octave, para el envío de variables hídricas mediante modulación $ LoRa^{TM} $ .

3. Diseñar un sistema de control eléctrico que permita la operación automática del sistema de bombeo, con base en la demanda hídrica variable del acueducto y la cantidad de agua contenida en el tanque principal.

4. Justificar, con base en un análisis financiero, la rentabilidad de la implementación del sistema de control y monitoreo en línea, con relación a las pérdidas financieras asociadas con la operación actual del acueducto principal de la ASADA Sámara.

## 1.6. Justificación

Los sistemas pequeños de abastecimiento de agua potable, usualmente enfrentan mayores desafíos para implementar nuevos programas de desarrollo y/o cumplir con regulaciones nacionales. [1] En el caso de Costa Rica, las ASADAS enfrentan un importante rezago en temas estructurales y manejo del recurso hídrico. [22] Como promedio general en Costa Rica, se estima que las ASADAS tienen pérdidas de agua de hasta el 60 % del total de agua que producen sus fuentes. [7] Esta situación se vuelve más crítica si se contempla la nula utilización de la tecnología en la atención de las ASADAS, y en el registro y seguimiento de los casos atendidos. [22]

Este proyecto busca alinearse con los esfuerzos país por hacer frente a desafíos como la carencia de información actualizada sobre la efectividad de operación de las ASADAS, en temas de medición de los sistemas de agua potable que permitan controlar fugas y disminuir el agua no facturada. Al desarrollar una herramienta tecnológica de bajo costo que habilita la capacidad de conectar mediciones hídricas a internet, provenientes de flujómetros ultrasónicos Octave. Específicamente con el objetivo de aprovechar los cientos de flujómetros de este tipo que fueron donados a ASADAS por el PNUD como parte del Proyecto de fortalecimiento de ASADAS e iniciativas nacionales como el Proyecto RANC-EE (AyA) y el Proyecto Fortalecimiento del Sistema Nacional de Gestión de la Información del Recurso Hídrico (SINGIRH) [22].

Las pérdidas de agua no solo conllevan al desperdicio del recurso hídrico, significan la sobre explotación del manto acuífero y un incremento innecesario en consumo energético del equipo de bombeo. El Banco Mundial menciona que "la energía representa uno de los componentes de costos más grandes, hasta un 20-30 por ciento de los presupuestos de operaciones y mantenimiento, para los servicios públicos de agua." [23]

Adicionalmente, la constante necesidad de regular el tiempo de bombeo y monitorizar manualmente el nivel del tanque, provoca que los fontaneros de cuadrilla dediquen gran cantidad de tiempo semanalmente a estas tareas, el cual podría ser destinado a tareas de mantenimiento y respuesta a averías. Si bien la administración de la ASADA de Sámara ha contabilizado su producción y demanda de agua para calcular las pérdidas en el acueducto junto con el NRW, existe la ausencia de los demás indicadores recomendados por AWWA y la determinación de sus valores aceptables desde el punto de vista financiero. La inexistencia de sistemas tecnológicos modernos a cargo de la obtención de datos de operación del sistema de bombeo y del acueducto, dificultan un seguimiento estandarizado relacionado con el progreso de las inversiones realizadas en el acueducto.

Las tecnologías inteligentes de infraestructura del agua (SWIT) están comenzando a revolucionar el suministro del servicio. A diferencia de las empresas proveedoras tradicionales, las ASADAS que dependen del trabajo manual para llevar a cabo simples actividades de monitoreo del sistema. Las empresas proveedoras de servicios que adoptan las SWIT automatizan actividades como comprobar los niveles de los reservoirios, cerrar válvulas para controlar la presión del agua y leer los contadores para calcular el consumo. [19] La automatización de estos procesos generan una enorme cantidad de datos que deben ser procesados, analizados y presentados de manera que puedan ser entendidos y utilizados por los tomadores de decisiones en dichas empresas. [24] Adoptando un enfoque más inteligente para la gestión del agua, mediante la digitalización como un habilitador clave en el camino.

Un sistema de monitoreo que facilite y almacene las mediciones realizadas por los macro medidores para su posterior análisis, en forma de indicadores de desempeño y auditorías de agua anuales, permitiría a la administración de la ASADA garantizar la rentabilidad y sostenibilidad de futuras inversiones para el acueducto. AWWA recomienda el uso de auditorías de agua como primer paso para un programa de control de pérdidas de agua en sistemas de abastecimiento pequeños, ya que permite identificar las cantidades y costos de pérdidas en el sistema y funciona como una herramienta para medir el progreso. [1]

La aplicación de un sistema de control automatizado y monitoreo en tiempo real del acueducto es fundamental para reducir y administrar las importantes pérdidas de agua asociadas a la distribución a cargo de la ASADA de Sámara. Permitirá el adecuado control del nivel de agua en el tanque de almacenamiento principal, abasteciendo de forma eficiente la demanda fluctuante de los más de 450 abonados de la zona turística de Sámara, caracterizada por periodos de alta y baja presencia de turistas (traducido a alta y baja demanda hídrica).

El desarrollo de este proyecto se vincula con los esfuerzos del país para implementar la Estrategia, Nacional de Cambio Climático. Se pretende brindar las herramientas para que los operadores de agua potable, saneamiento en el nivel de ASADAS, cuenten con insumos informativos documentados para la seguridad hídrica. Analizando la vulnerabilidad de los sistemas de agua potable y articulando medidas específicas para mejorar su protección y gestión. Adicionalmente, al contribuir al manejo y acceso de agua con calidad y continuidad para los abonados de la comunidad de Playa Sámara, procurando un consumo y uso eficiente del recurso hídrico de Nicoya, mediante el uso de tecnología para la recopilación de información relacionada con la distribución de agua potable, como insumo informativo documentado para la seguridad hídrica. Este proyecto se alinea específicamente con objetivos de las Naciones Unidas por el desarrollo sostenible (ODS) Consumo responsable y producción (número 12) y Agua limpia y saneamiento (número 6).

## Capítulo 2

## Metodología

En este capítulo se expone la metodología seguida para el cumplimiento de los objetivos planteados. A continuación, se resumen los aspectos más relevantes contenidos en los próximos capítulos y se exhiben las etapas de desarrollo del sistema de control y monitoreo hídrico.

- Capítulo 3: Muestra la recopilación de información y consideraciones teóricas en las que se sustenta el proyecto.

- Capitulo 4: Describe la programación de los firmware desarrollados y la selección de dispositivos involucrados en la comunicación del sistema de IoT.

- Capítulo 5: Exhibe el funcionamiento del firmware desarrollado para comunicarse con flujómetros Octave y los resultados obtenidos en la validación de su funcionamiento.

- Capítulo 6: Expone el diseño electrónico desarrollado para el control, comunicación y alimentación de potencia de los dispositivos involucrados en la operación del sistema.

- Capítulo 7: Propone un diseño de control eléctrico para el sistema de bombeo que permita la operación automática con base en la información recopilada por el sistema de comunicación a lo largo del acueducto.

- Capítulo 8: Analiza la rentabilidad de implementación del sistema propuesto, con base en una proyección de ahorros financieros en un escenario pesimista y optimista.

- Capítulo 9: Resume las conclusiones obtenidas del proceso de diseño, así como a las recomendaciones dadas a la administración de la ASADA.

## 2.1. Metodología seguida para el cumplimiento de los objetivos planteados

En esta sección se resume, en cuatro diagrams de flujo, la metodología seguida en los diseños y análisis ejecutados para el alcance de los objetivos específicos propuestos en este trabajo. En la figura 2.2 se expone los procesos involucrados en el desarrollo del sistema de comunicación. La creación del dispositivo electrónico para el envío de variables hídricas, se compuso de las fases mostradas en la figura 2.3. Mientras que en la figura 2.1 se muestran las etapas para el diseño del sistema de control eléctrico para el bombeo del acueducto y el proceso de análisis financiero que justifique la rentabilidad de la implementación del sistema de control y monitoreo en línea.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 2.1: Metodología de diseño del sistema de control eléctrico y justificación financiera.

Fuente: Elaboración propia, Visio.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 2.2: Metodología de diseño del sistema de comunicación.

Fuente: Elaboración propia, Visio.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 2.3: Metodología para la creación de dispositivo electrónico.

Fuente: Elaboración propia, Visio.

</div>

## 2.2. Definición del alcance de la investigación

Para efectos de este proyecto se plantea un alcance de tipo exploratorio, tomando en cuenta que se indagó la aplicación de una nueva tecnología, desde una perspectiva innovadora [25], enfocada en la gestión hídrica. Especificamente con el objetivo de monitorizar variables hídricas asociadas con la operación de equipos electromecánicos presentes en el acueducto principal de la ASADA de Playa Sámara. En términos generales se enfocará en la incorporación de dispositivos de monitoreo digital que informen el estado del acueducto principal, sin contemplar la micro medición en cada uno de los abonados. Esto requerirá la adaptación del tablero de control eléctrico, únicamente en el encendido y apagado (simultáneo o individual) de cada una de las bombas monofásicas presentes en sistema de bombeo. Las bombas existentes no poseen capacidad de modulación, esto implica que el sistema de control desarrollado no regulará el caudal ni la presión que entreguen las bombas durante su funcionamiento normal.

Por otra parte, el alcance de este proyecto no contempló modificaciones a las instalaciones hidráulicas. Entiéndase modificaciones al sistema de bombeo en pozos, ni al sistema de tuberías y válvulas actualmente instalado en la ASADA de Playa Sámara.

## 2.3. Viabilidad para el desarrollo

Durante el desarrollo del proyecto se dispuso únicamente del recurso humano y financiero de la administración de ASADA de Sámara, para la compra y asistencia en la instalación de todos los equipos y materiales necesarios. La ASADA de Sámara brindó mano de obra para la construcción de estructuras para el soporte de antenas, modificaciones en estructuras, asistencia en instalaciones de dispositivos de telecomunicación. En temas de disponibilidad y adquisición de equipos y dispositivos tecnológicos la mayoría de los componentes requeridos existen en el mercado nacional. La administración de la ASADA de Sámara, brindó los recursos financieros necesarios para la adquisición de materiales, equipos de comunicación, equipos eléctricos y la cancelación de servicios externos a la organización necesarios. Por otra parte, el acueducto principal de la ASADA de Sámara posee instalados tres macro medidores ultrasónicos de tipo Octave del fabricante Arad Group. Estos cuentan con la posibilidad de comunicación telemétrica, si se instala un módulo de comunicación eléctrica del mismo fabricante. Estos módulos de comunicación fueron adquiridos por la ASADA como parte del proyecto.

Adicionalmente, el Laboratorio Delta colaboró con el préstamo de equipos electrónicos de medición soldadura para experimentación y prototipado. Gracias al financiamiento del Programa de Energías Limpias del TEC (PELTEC) fue posible la fabricación de baterías y la manufactura de los prototipos desarrollados en este proyecto.

## Capítulo 3

## Marco Teórico

## 3.1. La gestión de pérdidas hídricas

Si bien el desarrollo de este proyecto no involucra específicamente el desarrollo de un programa de control de pérdidas, ni la aplicación de una auditoría de agua, es fundamental comprender sus componentes para que la información recopilada por el sistema de monitoreo propuesto, sea un insumo en la aplicación de auditorías de agua y el desarrollo de un programa de control de pérdidas, siguiendo los estándares AWWA/IWA, para la ASADA de Playa Sámara. La aplicación de una auditoría de agua es el paso básico para que una empresa de agua rinda cuentas de sus operaciones. La auditoría de agua aborda las preguntas ¿Cuánta agua se está perdiendo? y ¿Cuánto le está costando estas pérdidas a la empresa de agua? El método de arriba-abajo (ó top-down) puede proporcionar una buena evaluación preliminar de la pérdida de agua en reposo y conocimiento de la calidad de los datos de suministro de agua disponibles. Una auditoría de agua de arriba-abajo se puede realizar con muy poco esfuerzo o costo [1], haciéndolo factible para ASADAS. Para los sistemas que actualmente no auditan sus suministros, este es el primer paso recomendado por AWWA en el desarrollo de programas de control de pérdidas.

La auditoría de agua implica una revisión de registros y datos que rastrea el flujo de agua desde su fuente y tratamiento, por medio del sistema de distribución de agua. Detalla la variedad de componentes de suministro, consumo y pérdida que existen en un sistema de agua comunitario. La forma de resumir todos estos componentes, para su contabilización de una forma gráfica, es mediante el cálculo de un balance hídrico, como se muestra en la figura 3.1. Todos los datos de volumen se toman por un periodo de referencia, típicamente un año. [1] De esta forma, una auditoría de agua de arriba-abajo se estructura en dos pasos: (1) cuantificar, mediante medición o estimación, el consumo de agua individual y los componentes de pérdida de agua; y (2) realizar el cálculo del balance hídrico.

En los siguientes apartados se comentará sobre los mecanismos y conceptos teóricos que estarán asociados al sistema de toma, recolección y comunicación de datos entre los distintos dispositivos presentes en el acueducto principal de la ASADA de Sámara.

<table border="1"><tr><td rowspan="10">Volumen de agua fuentes propias</td><td rowspan="10">Volumen ingresado al sistema</td><td>Agua exportada</td><td colspan="3">Agua exportada facturada</td><td>Agua facturada</td></tr><tr><td rowspan="10">Agua suplida</td><td rowspan="4">Consumo autorizado</td><td rowspan="2">Consumo autorizado facturado</td><td>Consumo medio facturado</td><td rowspan="2">Agua facturada</td></tr><tr><td>Consumo no medio facturado</td></tr><tr><td rowspan="2">Consumo autorizado no facturado</td><td>Consumo medio no facturado</td><td rowspan="9">Agua no facturada</td></tr><tr><td>Consumo no medio y no facturado</td></tr><tr><td rowspan="6">Pérdidas de agua</td><td rowspan="3">Pérdidas aparentes</td><td>Inexactitudes en medición del cliente</td></tr><tr><td>Consumos no autorizados</td></tr><tr><td>Errores sistemáticos en manejo de datos</td></tr><tr><td rowspan="3">Pérdidas reales</td><td>Fugas en las tuberías de transmisión y distribución</td></tr><tr><td>Fugas y desbordamientos en los tanques de almacenamiento</td></tr><tr><td>Fugas en las conexiones de servicio hasta el punto de medición del cliente</td></tr><tr><td>Volumen importado de agua</td><td></td><td>

<div align="center">

Figura 3.1: Balance hídrico según AWWA. [1]

</div>

## 3.2. Conceptos de comunicación por radiofrecuencia

## 3.2.1. Antenas y propagación de señales de radio

Los sistemas de comunicaciones utilizan antenas para realizar enlaces punto a punto, difundir señales de radio, o bien transmitir o recibir señales en equipos portátiles. La antena es la parte de un sistema de transmisión o recepción que está diseñada para irradiar o recibir ondas electromagnéticas. [26]

Un decibel (dB) es una unidad de medida que se utiliza para expresar la relación de potencias, presiones sonoras u otras magnitudes en una escala logarítmica. dB es una relación que no representa de un valor absoluto. Al usar una potencia de entrada de referencia de 1 mW, la unidad se expresa en dBm. Otras notaciones de decibelios notables son: dBi y dBd (estos también representan relaciones) Los fabricantes de antenas utilizan estas unidades para medir el rendimiento de las antenas y son útiles para fines de comparación. El dBi se refiere a la ganancia de la antena con respecto a una antena isotrópica. Mientras que un dBd se refiere a la ganancia de la antena con respecto a una antena dipolo de referencia.

En la etapa preliminar de la organización del enlace inalámbrico, se recomienda realizar el cálculo del presupuesto de potencia (link budget), que muestra la energía de la señal de radio durante la propagación del transmisor al receptor. Esto permite estimar los posibles parámetros del enlace y seleccionar el equipo adecuado y su configuración. Es necesario considerar una serie de factores relacionados con la propagación de las señales electromagnéticas, junto con las características de los dispositivos transmisor y receptor.

El alcance de la señal entre dos puntos, depende de varios factores: la potencia del transmisor (TX, en dBm), la ganancia de la antena (en dBi que suma a la potencia TX), la sensibilidad del receptor (RX, en dBm), la frecuencia de la señal y la distancia en sí misma, pues a mayor distancia la señal se atenúa.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.2: Esquema del presupuesto de potencia de un enlace por radio. [2]

</div>

Esta atenuación de la señal por la distancia se conoce como las pérdidas por espacio libre (FSLP, por sus siglas en inglés Free Space Path Loss). En aplicaciones de radio típicas, es común expresar las FSLP en dB. Empleando la frecuencia f medida en GHz y la distancia d en km (entre TX y RX), las pérdidas por distancia se modelan como:

$$
F S L P [ d B ] = 9 2, 4 4 + 2 0 \log f + 2 0 \log d
$$

Conociendo el valor de la potencia de TX (sin antena) y la sensibilidad RX, es posible efectuar el inventario del enlace. Donde la potencia recibida PR es:

$$
P R [ d B ] = T X [ d B ] + G a n a n c i a a n t e n a [ d B ] - F S L P [ d B ]
$$

De esta forma, para garantizar teóricamente un enlace de comunicación exitoso, la potencia recibida en el RX debe ser mayor que la sensibilidad del RX. También, la línea de vista juega un papel fundamental, ya que, si entre el transmisor y el receptor existen obstáculos físicos, la señal igualmente se debilita. Adicionalmente, es necesario considerar el patrón de radiación o de antena y su polarización (para efectos prácticos, la posición de la antena de manera horizontal o vertical). Este patrón refleja la fuerza de las ondas de radio de la antena en diferentes direcciones en el espacio. El patrón de radiación depende del tipo de antena. Generalmente, para aplicaciones en las que el transmisor y el receptor se encuentran en una posición, es común emplear antenas tipo Yagi. Este tipo de antenas se caracterizan por ser altamente direccionales (tienen un "frente" y una "espalda"). Esto significa un patrón de radiación de largo alcance, pero en una dirección específica. Esto implica que, a la hora de colocar las antenas es necesario asegurarse de que ambos frentes estén alineados, es decir que las antenas se vean una a la otra.

## Indicador de intensidad en la señal recibida (RSSI)

Entre los elementos que conforman una red, existe un proceso llamado enrutamiento. Este proceso constituye un camino lógico por el cual se retransmiten mensajes desde un dispositivo inicio hasta un dispositivo final. La probabilidad de entrega exitosa de paquetes, se puede estimar utilizando varios métodos, mediante la intensidad de señal recibida RSSI (Received Signal Strength Indicator), el cual es una medida de la energía total de la señal recibida, expresada en dBm, o la relación señal a ruido total en banda (SNR, Signal-to-Noise Ratio). Ambos constituyen una manera de estimar la calidad de un enlace inalámbrico [27].

Cuando se estudia la calidad de enlace en una red inalámbrica, es necesario considerar aspectos como el conjunto de receptores (nodos) dispuestos de forma irregular en distintos lugares con respecto a un transmisor. Además, las distribuciones de calidad de enlace con control y sin control de potencia, son altamente dependientes del entorno y del hardware utilizado por los nodos. [27]

## 3.3. Protocolo LoRaWAN $ ^{TM} $

El Internet de las cosas (IoT) es una red de dispositivos físicos conectados a Internet que se pueden comunicar entre sí. Existe una serie de tecnologías inalámbricas utilizadas para conectar estos dispositivos a Internet, como: comunicación inalámbrica de corto alcance, comunicación celular y comunicación LPWAN. La tecnología LoRa $ ^{TM} $ pertenece a la tecnología LPWAN (por sus siglas en inglés, Low Power Wide Area Network).

LoRa $ ^{\mathrm{TM}} $ y LoRaWAN $ ^{\mathrm{TM}} $ son dos conceptos distintos. La modulación LoRa $ ^{\mathrm{TM}} $ se basa en técnicas de espectro ensanchado y una variación del espectro ensanchado chirp (CSS) con corrección de error directa integrada (FEC). Opera en los anchos de banda industriales, científicos y médicos (ISM) más bajos (EE. UU.: 915 MHz, UE: 433 MHz y 868 MHz). [28] Es la capa física o la modulación inalámbrica utilizada para crear el enlace de comunicación de largo alcance [29], independiente de las implementaciones de capa superior. La comunicación por LoRa $ ^{\mathrm{TM}} $ se caracteriza por utilizar bajas potencias de transmisión (Tx) para tazas de transferencia de datos bidireccionales bajas (0,3 kbps y 5,5 kbps) a largas distancias. LoRa $ ^{\mathrm{TM}} $ está administrada por LoRa Alliance y actualmente es propiedad de la empresa Semtech. La misma opera en la banda de radio ISM (Industrial, Científica y Médica) que está habilitada en todo el mundo para uso no comercial y no requiere de una licencia.

Cuando existen múltiples dispositivos conectados mediante LoRa $ ^{TM} $ utilizando el mismo protocolo LoRaWAN $ ^{TM} $ , se dice que se forma una red LoRaWAN $ ^{TM} $ . LoRaWAN $ ^{TM} $ define el protocolo de comunicación y la arquitectura del sistema para la red, estandarizado por LoRa Alliance, mientras que la capa física LoRa $ ^{TM} $ habilita el enlace de comunicación de largo alcance [29]. En una red LoRaWAN $ ^{TM} $ existen dos roles: Gateway y Nodo. Un Nodo es el dispositivo final; el sensor que recoge la información y la transmite. El Gateway es el mediador; recibe la información de los diferentes sensores y la retransmite, generalmente a través de Internet, a la nube para que esta unifique la información de todos los sensores y actue en consecuencia.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.3: Arquitectura de comunicación pormaya de LoRaWAN $ ^{TM} $ Fuente: LoRa Alliance [29].

</div>

## 3.3.1. Clases de comunicación en nodos

Los dispositivos de nodo de borde se pueden configurar con diferentes funciones. LoRaWAN $ ^{TM} $ define tres clases de dispositivos. Estas clases de dispositivos pueden negociar la latencia de la comunicación del enlace descendente de la red frente a la vida útil de la batería [28].

## Clase A:

Los dispositivos en clase A están diseñados para baja potencia, como sensores. Son la clase de mayor eficiencia energética, pero tienen el mayor tiempo de latencia. También incluye dispositivos que no necesitan transmitir datos todo el tiempo. Es la clase más soportada en casi todos los dispositivos compatibles con LoRaWAN $ ^{TM} $ , en este tipo de función el nodo solo entra en modo escucha (llamado ventana RX) después de enviar datos hacia el Gateway.

## Clase B:

La Clase B se centra en dispositivos que funcionan con baterías, como actuadores y sensores. Son energético eficientes, pero con un enlace descendente controlado por latencia. La comunicación es ranurada, sincronizada por una baliza externa, que permite al servidor saber cuándo el dispositivo final está escuchando. Este tipo de dispositivos tiene las ventanas de recepción con base a tiempos predeterminados con el Gateway, este tipo de nodos puede usar una batería o una fuente externa dependiendo de los tiempos asignados de escucha.

## Clase C:

La Clase C es utilizada por dispositivos finales bidireccionales con ranuras de recepcion máximas. Los dispositivos finales de la Clase C tienen ventanas de recepcion abiertas casi continuamente, que solo están cerradas durante la transmisión. Estos dispositivos deben usarse con una fuente de alimentación externa, son capaces de escuchar la interfaz aérea todo el tiempo, sin registrar latencia en el modo de recepcion o transmisión. [28]

## 3.3.2. Seguridad LoRaWAN $ ^{TM} $

Es extremadamente importante que cualquier LPWAN incorpore seguridad. LoRaWAN $ ^{\mathrm{TM}} $ utiliza dos capas de seguridad: una para la red y otra para la aplicación. La seguridad de la red garantiza la autenticidad del nodo en la red, mientras que la capa de seguridad de la aplicación garantiza que el operador de red no tenga acceso a datos de la aplicación del usuario final. Este protocolo utiliza el cifrado AES con intercambio de claves, utilizando un identificador IEEE EUI64 [29].


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.4: Protocolo de comunicación LoRaWAN $ ^{TM} $ Fuente: LoRa Alliance [29].

</div>

## 3.3.3. Regulaciones en LoRa $ ^{TM} $

El Reglamento al Plan Nacional de Atribución de Frecuencias (PNAF), en el artículo 19 (Notas CR061 y CR061A), menciona que se atribuye los segmentos de frecuencia de 895 MHz a 960MHz para el desarrollo de sistemas fijos de IMT (Telecomunicaciones Móviles Internacionales), siempre y cuando no introduzca interferencias perjudiciales en bandas de frecuencias adyacentes, atribuidas al servicio Móvil para el despliegue de sistemas IMT. Por otra parte, LoRa Alliance recomienda el uso de las bandas de frecuencia de 902MHz a 928MHz, para redes LoRaWAN $ ^{TM} $ ubicadas en América. [29]

## 3.4. Protocolo MQTT

El protocolo de mensajería MQTT (por sus siglas en inglés, Message Queue Telemetry Transport), es el protocolo estándar de comunicación en aplicaciones de IoT [30]. Como sugiere su nombre, es un protocolo de mensajería que admite la comunicación asincrónica entre partes. Un protocolo de mensajería asincrónica desacopla el remitente y el receptor del mensaje tanto en el espacio como en el tiempo, lo cual lo hace escalable en entornos de red poco confiables [31]. MQTT es un protocolo para el transporte de datos entre Cliente/Servidor, basado en un modelo de publicación y subscripción (Publish-Subscribe) a los denominados topics (jerarquías por temas). Cada vez que un mensaje es publicado será recibido por el resto de los dispositivos adheridos a un tópico del protocolo. Su función básica es posibilitar la lectura de datos y envío de comandos a dispositivos que requieren bajo ancho de banda y un menor consumo energético. En síntesis, el MQTT permite que puedan comunicarse sin demasiado esfuerzo.

El protocolo MQTT define dos tipos de entidades en la red: un intermediario de mensajes (broker) y un número de clientes. El broker es un servidor que recibe todos los mensajes de los clientes y luego enruta

esos mensajes a los clientes de destino relevantes. Un cliente es cualquier cosa que pueda interactuar con el intermediario para enviar y recibir mensajes. Un cliente podría ser un sensor de IoT en el campo o una aplicación en un centro de datos que procesa datos de IoT.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.5: Modelo de publicación y suscripción de MQTT. Fuente: Elaboración propia, Canva.

</div>

El cliente se conecta al broker. Puede suscribirse a cualquier "tema" de mensaje en el broker. El cliente publica mensajes bajo un tema, enviando el mensaje y el tema al broker. Luego, el broker reenvía el mensaje a todos los clientes que se suscriben a ese tema. Hay varios tipos de mensajes, según la función por ejecutar. Entre los más usuales se encuentran: connect, publish, subscribe, unsubscribe y disconnect.

## 3.5. Sistemas de IoT

El Internet de las cosas, o IoT, es un sistema de dispositivos informáticos, máquinas mecánicas y digitales, objetos, animales o personas interrelacionados a los que se les proporcionan identificadores únicos (UID) y la capacidad de transferir datos a través de una red sin requerir de la interacción de persona a persona o de persona a computadora [32]. Una solución completa de IoT integra cuatro componentes distintos: sensores / dispositivos (hardware), conectividad, procesamiento de datos (software) y una interfaz de usuario. Los sensores son los encargados de recolectar datos sobre su ambiente y aplicación específica. Luego, esos datos se envían a la nube (Internet) a través de una variedad de métodos de conexión que incluyen: celular, satélite, WiFi, Bluetooth, redes de área amplia de baja potencia (LPWAN) o conectarse directamente a Internet a través de Ethernet. Una vez que los datos llegan a la nube, el software realiza algún tipo de procesamiento en estos. Dicho software está alojado en la nube y es responsable de analizar los datos que recopila de los sensores y tomar decisiones. Finalmente, un sistema IoT completo necesita una interfaz de usuario. Para que todo esto sea útil, es necesario que los usuarios interactuen con el sistema de IoT. [33]

El verdadero valor de IoT se da cuando se integra con los sistemas comerciales y los flujos de datos existentes [33]. Por lo tanto, es fundamental que todos estos componentes se unan de manera efectiva y manejable, es aquí donde entran las plataformas de IoT. Las plataformas IoT son el software que conecta todos los puntos anteriores, a esto se le conoce como la Cadena de Valor de IoT. Una plataforma IoT facilita la comunicación, el flujo de la información, la administración de dispositivos y la funcionalidad de las aplicaciones.

Si se consideran los tipos de hardware disponibles, tanto de conectividad como sensores, se vuelve indispensable una herramienta que permita realizar cambios, escalar la operación y responder a incidentes de forma centralizada: ese es el rol que intentan cumplir estas plataformas. La plataforma IoT ayuda a conectar y hacer fluida la comunicación entre el hardware; manejar los diferentes protocolos de software y hardware, proveer seguridad para dispositivos y usuarios; recolectar, visualizar y analizar la información que los sensores y dispositivos reúnen; e integrar todo lo anterior en un servicio web. [34]

En el mercado existe una enorme cantidad y variedad de compañías que ofrecen sus servicios de plataformas de IoT, lo que complica la selección y adaptación. Para la selección correcta de una plataforma de IoT, Brian Ray plantea tres aspectos fundamentales que deben considerarse antes de tomar la decisión [35]. En primer lugar, presupuesto, habilidades de desarrollo y capacidades in-house, ya que el costo de las licencias para la plataforma es solo el comienzo, es necesario analizar cuánto cuesta la integración, los consultores necesarios para la implementación e incluso los desarrollos necesarios para generar una relación armónica entre la infraestructura existente y la nueva.

En segundo lugar, el modelo de negocios y sus necesidades específicas, para extraer dinero de un sistema, hay que agregar valor en alguna parte. Es necesario tener claridad respecto a qué es lo más valioso en la cadena de valor y concentrarse ahí, para después detectar qué plataformas son las que mejor se adaptan. En tercer lugar, criticidad del tiempo o del dinero, es importante saber si se intenta ahorrar dinero o ahorrar tiempo. Las plataformas que ofrezcan ahorrar tiempo probablemente son más costosas a largo plazo; mientras que las enfocadas en el ahorro de costos, suelen ser más difíciles de implementar e integrar.

## 3.6. Definiciones relacionadas con placas de circuito impreso

En este apartado se muestra, de forma introductoria, las definiciones asociadas a la terminología del diseño de tarjetas de circuito impreso.

## Esquemático

El esquemático o diagrama esquemático, es la representación visual de las interconexiones de los elementos en el circuito. Para los programas de diseño, a las conexiones se les conoce como Nets. Es recomendable realizar pruebas en una tarjeta de prototipos, para validar la funcionalidad del esquemático, o hacer uso de software de simulación como lo son aquellos derivados de SPICE. [3]


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.6: Diagrama esquemático para un sensor oscuro con LDR.

</div>

## Boardfile - Layout

El Boarfile es el archivo en donde se realiza el diseño físico de la tarjeta. El diseño de la misma se le conoce como Layout. Se puede observar en la figura 3.7 el boardfile, que es el archivo en general, el layout del boardfile es la manera en que se trazaron las señales o pistas en la tarjeta. Estos conceptos van de la mano. Cuanto se habla del archivo, se hace referencia al boardfile y cuando se habla del diseño en particular, se hace referencia al layout.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.7: PCB de doble capa diseñada con el software EAGLE [3].

</div>

## Pad en diseño

El pad es la zona en la tarjeta o diseño de la misma donde se coloca el pin de algn componente, los pads suelen ser rectangulares para elementos de montaje superficial, y redondos para los componentes through-hole y vías. En el diseño el pad se suele representar de manera visual solamente como un elemento

que parece ser que traspasa toda la PCB. En la figura 3.8 se observan algunos pads en diseño.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.8: Pads en distintos elementos [3].

</div>

## Footprint - Landpattern

El footprint es diseño de los pads para un elemento en particular, dependiente del estándar de empaquetado para ese componente. En las hojas de datos de los dispositivos o componentes electrónicos, los fabricantes suelen especificar las dimensiones de los componentes con lo que se puede generar un footprint. Se puede observar en la figura 3.8 que el circuito integrado del centro recae dentro de los pads que se pusieron ahí para crear el footprint determinado para ese integrado.

## Pad en el PCB

En el PCB el pad es aquel elemento o segmento de cobre que conecta un Net con un componente de montaje o de through-hole (agujero pasante), así como conecta el barrel o centro de la vía con la capa. Entre las características generales, esta que los pads son el principal contacto entre las conexiones del PCB con el exterior a través de los pads se sueldan los componentes de montaje superficial y through-hole. El soldermask es una capa que cubre todo el PCB menos los pads, para finalmente ser estañados.

## Soldermask

El soldermask es la capa física semitransparente que cubre el PCB en las caras superior e inferior. El soldermask se pone sobre la PCB para evitar oxidación del cobre. El soldermask recubre toda la cara de la PCB a excepción de los pads y suele tener color verde, aunque puede ser de otros colores, dependiendo del fabricante. En la mayoría de los programas de diseño el soldermask viene de la mano con los pads ya que a menos que se especifique lo contrario, este es un negativo de la capa de pads.

## Silkscreen

El silkscreen es una capa de serigrafía que sirve como indicador sobre la PCB, se recomienda imprimir el nombre del componente, el valor del componente, así como el contorno del componente. Aquí se puede


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.9: Partes de PCBs terminadas [3].

</div>

imprimir texto con información como la revisión, diseñador, código de barras, etiquetas, licencias, marca, institución, entre otras cosas.

## Net - Señal

El concepto de Net es en términos generales la señal por trazar, sin importar desde cuál punto de vista se vea, ya sea en esquemático o en layout, o si está trazado el segmento de cobre o no. Una Net por definición solo se limita a un segmento de una línea de comunicación, la misma está limitada por una conexión a un elemento sin importar si es pasivo o activo. Dentro de un diagrama esquemático la Net es limitada por un elemento activo o pasivo.

## Rat

Una rat no es más que una Net en el boardfile que no se encuentra trazada por cobre. Una rat no tiene ancho ni un camino específico. Es un vector que va de elemento a elemento y es definido por el software. El conjunto de rats que se encuentran en el boardfile antes de ser trazadas se le conoce como ratsnets. [3]

## Traza

El concepto más importante y con mayor peso dentro de lo que es una net, es la traza de cobre. Al realizar el routeo o el trazo de cobre para realizar la conexión de dos, elementos es posible controlar una gran cantidad de aspectos electromagnéticos y términos de una PCB [3]. La geométrica y los espaciamientos con otras señales, así como los materiales que se utilizan para el diseño y la fabricación de la PCB, definen aspectos que determinan la calidad final de la señal.

## Vía en diseño

La vía en el diseño se utiliza para transferir una traza o net entre diferentes capas, la misma tiene como parámetros de diseño el diámetro del pad y el diámetro de la perforación o drill. En el diseño la vía se limita a las transiciones de capa, pero en el PCB físico también se le conoce como vía a la perforación en los componentes through-hole. [3]

## Vía en PCB

La vía es comúnmente utilizada en PCBs para montaje de componentes through-hole o para interconnectar líneas de transmisión en capas diferentes. Las vías consisten en un barrel, pad y antipad. El barrel es un elemento en forma de tubo, el cual es conductivo y llena las paredes de la perforación. El pad conecta cada extremo del barrel a la capa deseada de la PCB. Este a su vez puede conectarse a un trazo de cobre, a un plano o dejarse sin conectar. El antipad es el espacio sin cobre entre el pad y algún otro segmento de cobre que no pertenezca a la señal del pad [3].


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.10: 1- Vía through-hole, 2- Blind via 3- Burried via [3].

</div>

## Layer (capa)

Las capas de diseño corresponden a un proceso en la fabricación del PCB. Las capas o layers de cobre se refieren a las capas que serán impresas en el PCB como trazas de cobre.

## 3.7. Sistema en Chip ESP32

ESP32 es la denominación de una familia de chips SoC de bajo costo y consumo de energía, con tecnología Wi-Fi y Bluetooth de modo dual integrado. El ESP32 fue creado y desarrollado por Espressif Systems, empleando un microprocesador Tensilica Xtensa LX6 en sus variantes de simple y doble núcleo.

Además, incluye interruptores de antena, radiofrecuencia, amplificador de potencia, amplificador receptor de bajo ruido, filtros, y módulos de administración de energía.

El ESP32 es capaz de funcionar de forma fiable en entornos industriales, con una temperatura de funcionamiento de $ - 4 0 \mathrm {^ \circ C} + 1 2 5 \mathrm {^ \circ C} $ . Alimentado por circuitos de calibración avanzados, ESP32 puede eliminar dinámicamente las imperfecciones del circuito externo y adaptarse a los cambios en las condiciones externas. Diseñado para dispositivos móviles, dispositivos electrónicos portátiles y aplicaciones de IoT, ESP32 logra un consumo de energía ultra bajo con una combinación de varios tipos de software patentado [36].

## 3.8. Medición hídrica ultrasónica

La medición de flujo hídrico utilizando tecnología ultrasónica posee múltiples aplicaciones, dada su elevada exactitud. Este tipo de medidores se caracterizan por la ausencia de partes móviles para su funcionamiento, por lo que se atribuye una insignificante pérdida de carga. El fabricante Arad Group explica el principio de medición ultrasónica, de una forma sencilla, con el siguiente ejemplo: Imagínese dos nadadores idénticos que cruzan un río a lo largo de una misma línea diagonal, uno con la corriente y el segundo contra la corriente. El nadador que nada con la corriente requiere de mucho menos tiempo para llegar a la otra orilla. Las ondas ultrasónicas se comportan exactamente de la misma manera.

La onda sónica que fluye con la corriente lo hace a mayor velocidad que la onda en dirección contra la corriente. El tiempo de cruce TAB (tiempo que requiere las ondas ultrasónicas para atravesar desde el sensor A hasta el sensor B) y TBA (desde el sensor B hasta el sensor A) se miden continuamente. La diferencia en los tiempos (TBA-TAB) es directamente proporcional a la media de la velocidad del flujo (Vm) del fluido. La tasa de flujo es el resultado de la velocidad multiplicada por el área de la sección de la tubería del flujo [4]. Ver figura 3.11.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 3.11: Principio de la medición hídrica ultrasónica. [4]

</div>

## 3.9. Sensores de nivel para tanques de agua potable

El sensor de nivel es un dispositivo electrónico que mide la altura del material, generalmente líquido, dentro de un tanque u otro recipiente. Los sensores de nivel se dividen en dos tipos principales: sensores de nivel de punto y sensores de nivel continuos.

Los sensores de nivel de punto se utilizan para marcar una altura de un líquido en un determinado nivel preestablecido. Este tipo de sensor funciona como alarma, mediante salidas digitales de relé conmutador, indicando un sobre llenado cuando el nivel determinado ha sido adquirido. Los sensores de nivel continuos pueden realizar el seguimiento del nivel de todo un sistema. Estos miden el nivel del fluido dentro de un rango especificado, en lugar de en un único punto, produciendo una salida analógica que se relaciona directamente con el nivel en el recipiente.

Para crear un sistema de gestión de nivel, la señal de salida está vinculada a un bucle de control de proceso y a un indicador visual. En la medición de nivel en tanques de agua potable, es común encontrar variedad de sensores con diferentes mecanismos de funcionamiento. Entre los más comúnmente utilizados destacan: sensores de flotador, ultrasónico sin contacto, ultrasónico de contacto, sensor capacitivo, por conductividad, por radar, por lámina vibrante y sensores de presión diferencial de nivel.

## Arquitectura del Sistema de IoT

Este capítulo se describe el funcionamiento general de los software diseñados específicamente para la intercomunicación de datos hídricos y la operación automática del acueducto. Primeramente, se describirá la arquitectura general de funcionamiento del sistema de IoT para el acueducto de Playa Sámara. Posteriormente, se abordarán aspectos relevantes de la programación de los dispositivos Heltec LoRa 32 V2. Luego, se explica el procedimiento de cálculo del presupuesto de señal requerido para la comunicación por radio frecuencia de todos los dispositivos. Finalmente, se exponen los resultados obtenidos referentes a la operación de la red LoRaWAN $ ^{TM} $ , instalada para el acueducto principal de Playa Sámara.

## 4.1. Arquitectura de funcionamiento

Fundamentalmente, el sistema de IoT diseñado, tiene como objetivo la operación y recopilación de información hídrica del acueducto de forma automática, para luego ser publicada en una plataforma en internet de acceso con cualquier dispositivo móvil. El sistema fue diseñado para tomar información de caudal y volumen hídrico en tres puntos críticos, donde se encuentran instalados flujómetros Arad Octave con capacidad de comunicación digital. Adicionalmente, el sistema toma en cuenta información del nivel del tanque principal y los caudales hídricos de demandados y producidos en el acueducto para coordinar la operación de dos bombas sumergibles que extraen el agua de los pozos de la Asada de Playa Sámara.

Es importante mencionar que únicamente existe la posibilidad de una red de WiFi en el tanque de abastecimiento principal. Esto implicó que la comunicación con los demás dispositivos se diese mediante radiocomunicación de largo alcance LoRa $ ^{TM} $ . La comunicación LoRa $ ^{TM} $ entre cada uno de los tres puntos opera a una frecuencia y bandas de acceso libre en Costa Rica. De esta forma se establece una red de radiofrecuencia LoRaWAN $ ^{TM} $ , generada gracias a tres módulos de desarrollo (dev-boards) de IoT tipo Heltec LoRa 32 V2, donde cada una posee un sistema en chip (SoC) de tipo ESP32 con funciones y programaciones distintas, las cuales se detallan más adelante. Gracias a la operación y comunicación simultánea de cada uno de estos dispositivos, el acueducto puede funcionar automáticamente y responder de forma automática al comportamiento inestable de la demanda y producción hídrica.

El sistema de IoT diseñado funciona bajo el esquema de control maestro-esclavo, esto significa que existe un controlador maestro, encargado de solicitar y procesar la información, y controladores esclavos, encargados de enviar información y realizar tareas de control simples. Como se ilustra en la figura 4.1 la arquitectura de comunicación del sistema de IoT es bidireccional, compuesta por la red LoRaWAN $ ^{TM} $ y comunicación por MQTT, vía WiFi, a la plataforma en internet Adafruit IO (AIO). Los nodos de comunicación presentes en la red LoRaWAN $ ^{TM} $ fueron programados en la funcionalidad de Clase C, ya que estos escuchan de forma continua las ordenes que envie el Gateway (controlador maestro).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.1: Arquitectura del sistema de IoT. Fuente: Elaboración propia, Canva.

</div>

El controlador maestro funciona con el firmware llamado tank.ino. Este programa fue diseñado para controlar de forma centralizada la operación del acueducto y funcionar como la puerta de enlace a internet (Gateway). El mismo procesa los datos recibidos de la red LoRaWAN $ ^{TM} $ y los publica en la plataforma en internet AIO, para ser visualizados desde cualquier dispositivo móvil con conexión a internet. El sistema recopila datos de flujos y volumen hídricos de demanda principal, demanda por rebombeo y producción de agua en pozos. La recopilación de información hídrica es posible gracias a dos firmware "esclavos" que funcionan como nodos de información, meter.ino y pump.ino. Estos nodos interpretan las mediciones de los flujómetros Octave y las envían al controlador maestro utilizando LoRa $ ^{TM} $ , tal y como se presenta en la figura 4.10. Por otra parte, se detallan las configuraciones del hardware y alimentación para el Gateway y los Nodos de comunicación en las figuras 4.2 y 4.3, respectivamente.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.2: Configuración básica para el Gateway en tanque principal. Fuente: Elaboración propia, Visio.

</div>

Los procesos de comunicación y medición de variables hídrica se ejecutan dentro del SoC ESP32 de forma independiente, esto gracias a que el ESP32 posee dos procesadores. Lo cual, permite ejecutar tareas de forma simultánea sin interferencias. De esta forma, todas las tareas relacionadas a la medición de caudal y volumen se ejecutan en un procesador aparte con el objetivo de que estas tareas no se vean interrumpidas por otras tareas relacionadas con la comunicación de datos.

En este apartado se expone la dinámica de comunicación telemétrica entre los dispositivos (utilizando LoRa) y la plataforma en línea Adafruit IO (mediante MQTT). Por otra parte, el proceso de comunicación entre los flujómetros y el SoC ESP32 se detalla más adelante en el Capítulo 5, y el diseño de control eléctrico para el bombeo se expone en el Capítulo 7.

## 4.2. Programación de dispositivos

## 4.2.1. Controlador maestro

La programación del controlador maestro se implementó como una máquina de estados. En la página siguiente se muestra la lógica de funcionamiento como un diagrama de control con etapas y transiciones (GRAFCET). Cada uno de los cuadrados representa la etapa o estado de funcionamiento en donde se realizan distintas tareas y las líneas cortas horizontales representan la condición que debe ocurrir para que se realice la transición al siguiente estado.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.3: Configuración básica para los Nodos del acueducto.

Fuente: Elaboración propia, Visio.

</div>

Cada una de las etapas de la máquina de estados fue implementada en el software de programación con un while, en donde el programa realiza tareas específicas de forma repetitiva, hasta que se cumpla cierta condición que provoca el cambio de ejecución de un while a otro (de una etapa a otra). Este cambio de etapas se realiza mediante una variable llamada State que toma el valor de la etapa que se debe ejecutar de acuerdo con el comportamiento de las variables monitorizadas en el acueducto. De esta forma, un bucle general de ejecución (loop) evalúa constantemente el valor de la variable State para asignar la etapa que debe ser ejecutada y sus tareas asociadas. Todas estas tareas son ejecutadas en el procesador principal del SoC ESP32 donde se implementó el software. Mientras que las tareas de medición de variables hídricas, asociadas al agua que se envía al rebombeo, se ejecutan en el procesador secundario.

El firmware maestro fue programado para comandar la operación de las bombas en dos modalidades, en modo manual y automático. El modo automático está compuesto por los estados nombrados como A1, B1, C1 y D1. En este modo el sistema constantemente verifica el estado de los sensores de detección de líquido para apagar el sistema de bombeo, si el tanque está lleno, o activar el bombeo si el tanque está en su nivel bajo. En el modo automático se le da prioridad de funcionamiento a la bomba de 15 HP, esto considerando que el pozo en donde está sumergida posee una mayor capacidad hídrica de extracción. La bomba de 10 HP, que extrae agua del pozo más antiguo, únicamente entra en funcionamiento cuando el caudal de producción de agua de la bomba de 15 HP es menor al caudal demandado total por el acueducto. De esta forma se evita que el tanque baje su nivel rápidamente, cuando la carga de demanda es elevada en temporada alta.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Tabla 4.1: Caudales típicos de operación en el acueducto de playa Sámara.

</div>

<table border="1"><tr><td>Caudal típico en bomba 15 HP</td><td>12,5 L/s</td></tr><tr><td>Caudal típico en bomba 10 HP</td><td>7,5 L/s</td></tr><tr><td>Caudal típico de operación simultánea</td><td>14,5 L/s</td></tr><tr><td>Caudal típico en temporada baja</td><td>10,0 L/s</td></tr><tr><td>Caudal típico en temporada alta</td><td>15,0 L/s</td></tr></table>

<div align="center">

Fuente: Elaboración Propia.

</div>

El modo manual (estado 3) implica que un usuario, desde cualquier dispositivo móvil, puede activar o desactivar el funcionamiento de cada bomba. Este último modo es útil en caso de que se necesite vaciar el tanque para darle mantenimiento o para el mantenimiento del sistema de bombeo. Adicionalmente, más adelante se plantea una modalidad manual desde el tablero de control en el bombeo principal.

De acuerdo con Limor Fried (conocida como Lady Ada, fundadora de Adafruit Industries), es necesario publicar datos al menos cada 5 minutos para mantener la conexión activa con el broker MQTT de Adafruit, en aplicaciones donde constantemente se necesita suscribir datos del broker. Por esta razón, se definió un tiempo de dos minutos para la subida de datos a la plataforma. Cada vez que se cumplen dos minutos de operación, el controlador maestro (Gateway) solicita datos hídricos a cada nodo de medición para publicarlos en la plataforma. La evaluación del tiempo de subida de datos se da en el estado A2 mostrado en el GRAFCET anterior.

## Comunicación con la plataforma Adafruit IO

Como se ha comentado anteriormente, la plataforma de IoT seleccionada es Adafruit IO. Al comparar diferentes plataformas de IoT se determinó que Adafruit IO es la más adecuada en términos financieros y técnicos. Esta plataforma permite tanto la publicación (subida) como la suscripción (descarga) de datos, a diferencia de la mayoría de plataformas que solo permite la publicación de datos. La posibilidad de suscripción de datos desde la plataforma, permite realizar tareas de comando desde cualquier dispositivo móvil. Esto es especialmente útil, considerando que para la operación segura del acueducto se requiere de una interfaz de contacto con un usuario.

Una limitante de esta plataforma es que no posee la capacidad de procesamiento de datos avanzado, como cálculos estadísticos o la ejecución de algoritmos complejos desde la plataforma. Sin embargo, desde la plataforma es posible ejecutar comandos simples como acciones temporizadas o acciones de respuesta a ciertas condiciones que posibilitan un control remoto de actuadores.

El controlador maestro es el encargado de la publicación (subida) y suscripción (descarga) de datos con la plataforma, gracias a que se encuentra ubicado en el punto geográficamente más elevado y con acceso a internet mediante conexión celular. Los datos enviados en ambas direcciones, mediante el protocolo MQTT y las librerías que provee la Adafruit IO, son manejados en forma de una cadena de carácteres dirigidos a un archivo secuencial desde el cual se puede agregar o leer información. Estos archivos son llamados dentro de la plataforma como feeds. En cada uno de los feeds se almacenan los distintos datos recopilados del acueducto y el funcionamiento del sistema, como se muestra en la figura 4.4. En total para esta aplicación se crearon 20 feeds.

<table class="table table-bordered"><thead><tr><th colspan="3">Bombas</th></tr><tr><th>Feed Name</th><th>Key</th><th>Last value</th></tr></thead><tbody><tr><td>☐ control10hp</td><td>pumps.control10hp</td><td>OFF</td></tr><tr><td>☐ control15hp</td><td>pumps.control15hp</td><td>OFF</td></tr><tr><td>☐ status10hp</td><td>pumps.status10hp</td><td>OFF</td></tr><tr><td>☐ status15hp</td><td>pumps.status15hp</td><td>OFF</td></tr></tbody></table>

<div align="center">

Figura 4.4: Ejemplo de Feeds creados en la plataforma Adafruit IO. Fuente: Elaboración propia.

</div>

Por otra parte, en la plataforma se realizan ciertas operaciones lógicas que permiten el control de los actuadores y la operación segura del acueducto. Estas operaciones se ejecutan como acciones de respuesta a ciertas condiciones en los datos que son publicados, llamadas triggers. La programación de estas posibilitan un control remoto y automático seguro. Por ejemplo, si el controlador maestro publica una alerta de error, la plataforma en línea apaga el sistema automático junto con las bombas y envía un correo electrónico con el mensaje de alerta al personal encargado.

<table class="table table-bordered"><thead><tr><th>ID</th><th>Created</th><th>Status</th><th>Last Action</th><th>Description</th><th>Action</th><th>Run Count</th></tr></thead><tbody><tr><td>24269</td><td>2021/01/1...</td><td>Active</td><td>2021/06/...</td><td>If status15hp is equal to "OFF" then set control15hp to "OFF".</td><td>Feed</td><td>278</td></tr><tr><td>24270</td><td>2021/01/1...</td><td>Active</td><td>2021/06/...</td><td>If status15hp is equal to "ON" then set control15hp to "ON".</td><td>Feed</td><td>220</td></tr><tr><td>24629</td><td>2021/02/...</td><td>Active</td><td>2021/06/...</td><td>If alerts is equal to "ALERTA: Sistema reiniciado" then set automatic to "ON".</td><td>Feed</td><td>437</td></tr><tr><td>24655</td><td>2021/02/...</td><td>Active</td><td>2021/04/...</td><td>If alerts is equal to "SISTEMA AUTOMATICO APAGADO: ERROR EN SENSOR...</td><td>Feed</td><td>15</td></tr><tr><td>24756</td><td>2021/02/...</td><td>Active</td><td>2021/06/...</td><td>If alerts is equal to "SISTEMA EN MODO MANUAL O ERROR TABLERO EN B...</td><td>Feed</td><td>209</td></tr><tr><td>25582</td><td>2021/05/...</td><td>Active</td><td>2021/06/...</td><td>If status10hp is equal to "ON" then set control10hp to "ON".</td><td>Feed</td><td>96</td></tr><tr><td>25583</td><td>2021/05/...</td><td>Active</td><td>2021/06/...</td><td>If status10hp is equal to "OFF" then set control10hp to "OFF".</td><td>Feed</td><td>127</td></tr><tr><td>25759</td><td>2021/05/...</td><td>Active</td><td>2021/06/...</td><td>If alerts is equal to "SISTEMA EN MODO MANUAL O ERROR TABLERO EN B...</td><td>Email</td><td>35</td></tr><tr><td>25760</td><td>2021/05/...</td><td>Active</td><td></td><td>If alerts is equal to "SISTEMA AUTOMATICO APAGADO: ERROR EN SENSOR...</td><td>Email</td><td>0</td></tr><tr><td>25959</td><td>2021/06/...</td><td>Active</td><td></td><td>If alerts is equal to "ALERTA: BATERÍA BAJA EN MACROMEDIDOR DEMAND...</td><td>Email</td><td>0</td></tr><tr><td>25960</td><td>2021/06/...</td><td>Active</td><td></td><td>If alerts is equal to "ALERTA: BATERÍA BAJA EN PRODUCCION" then email ...</td><td>Email</td><td>0</td></tr><tr><td>25961</td><td>2021/06/...</td><td>Active</td><td></td><td>If alerts is equal to "ALERTA: BATERÍA BAJA EN TANQUE" then email me the...</td><td>Email</td><td>0</td></tr><tr><td>25962</td><td>2021/06/...</td><td>Active</td><td></td><td>If alerts is equal to "ALERTA: ERROR EN COMUNICACION LoRa CON MACR...</td><td>Email</td><td>0</td></tr><tr><td>25963</td><td>2021/06/...</td><td>Active</td><td></td><td>If alerts is equal to "ALERTA: ERROR EN COMUNICACION LoRa CON PROD...</td><td>Email</td><td>0</td></tr></tbody></table>

<div align="center">

Figura 4.5: Ejemplo de Triggers creados en la plataforma Adafruit IO. Fuente: Elaboración propia.

</div>

Finalmente, toda la información relacionada a la operación del sistema se visualiza en la interfaz de usuario de la plataforma AIO, llamada dashboard. La sección de la interfaz que se muestra en la figura 4.6, se compone por una sección de control para el bombeo, indicadores del estado de cada bomba (verde si están activas y rojo si están apagadas), un historial de mensajes de alerta y las últimas mediciones de flujo hídrico promedio para la demanda y producción del acueducto.

Utilizando todos los datos hídricos recopilados en el acueducto, se presentan gráficas de comportamiento de la demanda y producción (en volumen y caudal hídrico). Adicionalmente, se muestran variables del sistema en tiempo real como el RSSI recibido de cada nodo de medición y el estado del voltaje en las baterías durante el día. Es posible acceder a esta información desde cualquier dispositivo móvil, como se muestra en la figura 4.7


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.6: Parte del dashboard diseñado para la visualización de datos hídrico y control del sistema de bombeo.

Fuente: Elaboración propia. Adafruit IO.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.7: Dashboard diseñado para la visualización de información recopilada por sistema de IoT desde dispositivo móvil.

Fuente: Elaboración propia. Adafruit IO.

</div>

## 4.2.2. Nodos de medición y control

En esta sección se expone el proceso de funcionamiento de los firmware "esclavos" meter.ino y pump.ino. Las figuras 4.8 y 4.9 muestran la lógica de operación en forma de diagrams de flujo.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.8: Diagrama del firmware meter.ino, para la comunicación de variables hídricas en demanda.

Fuente: Elaboración propia, Visio.

</div>

El firmware meter.ino se diseño para interpretar la información de únicamente un flujómetro, específicamente para la demanda principal del acueducto. Mientras que el programa pump.ino se diseñó con la capacidad de interpretar mediciones de dos flujómetros de forma simultánea y el accionar de dos relés que coordinen el encendido y apagado de dos bombas. De igual forma, las tareas relacionadas con la medición y las tareas relacionadas a la comunicación y accionamiento de actuadores se realizan en procesadores independientes. Las tareas de medición se explican con detalle en el capítulo siguiente.

Es importante mencionar que el programa de comunicación genera estímulos al proceso de medición y viceversa. Cuando el Gateway solicita datos a los Nodos el programa de comunicación toma el último valor de la variable de caudal promedio y volumen medio acumulado para enviarlo al Gateway. Las variables de caudal promedio y volumen medio acumulado constantemente son actualizadas por el software de medición, que se ejecuta en un procesar independiente. Por otra parte, cuando el Gateway reporta que los datos fueron recibidos al software de comunicación se reinicia el proceso de medición de caudal promedio y el volumen acumulado iguala al último valor de volumen enviado. El Gateway lleva una sumatoria de los valores de volumen medios por los nodos que reporta a la plataforma en línea como el volumen total de demanda, producción y un aproximado de la cantidad de agua que existe en el tanque (sabiendo cuánta agua entra y cuánta sale del mismo).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.9: Diagrama del firmware pump.ino, para el control de bombeo y la comunicación de variables hídricas.

Fuente: Elaboración propia, Visio.

</div>

## 4.3. Comunicación telemétrica mediante red LoRaWAN $ ^{TM} $

La red LoRaWAN $ ^{TM} $ diseñada funciona bajo el protocolo de clase C. Esta clase de protocolo establece que los nodos siempre están en modo de escucha y solo transmiten datos cuando el controlador principal (Gateway) da la orden. Para este tipo de clase de protocolo se gestionó una fuente de alimentación, ya que consume una alta cantidad de energía asociada a su operación continua. Por otra parte, la potencia de transmisión establecida para todos los dispositivos Heltec LoRa V2 es de 20dBm (100mW), relativamente baja si se compara con una potencia de transmisión de 40dBm (10W) típica de un PLC (100 veces mayor).

El manejo de datos dentro de la red LoRaWAN $ ^{TM} $ en Sámara, se da mediante paquetes de datos. Para aplicación se establecieron paquetes de datos donde su contenido pueden ser órdenes o mediciones. Un paquete de datos está compuesto por su contenido (mensaje) y la información relacionada con el mensaje (dirección de receptor, dirección de emisor y la cantidad de caracteres que posee el mensaje). Como se muestra en el siguiente fragmento del código.

Función para la transmisión de paquetes de datos por LoRa.

void LoRaSend(String outgoing, byte destination) {

    for(int i = 0; i < 5; i++){ // enviar mismo paquete 5 veces

        // (2 segundos de transmisión en total)

        LoRa.beginPacket();

        LoRa.setTxPower(txPower, RF_PACONFIG_PASELECT_PABOOST);

        // Packet header bytes:

        LoRa.write(destination);                // add destination address

        LoRa.write(localAddress);                // add sender address

        LoRa.write(outgoing.length());            // add payload length

        // add payload

        LoRa.print(outgoing);

        LoRa.endPacket();

    }

}

Los datos contenidos en cada mensaje son creados por cada dispositivo en un orden y delimitador establecido que únicamente el receptor y emisor conocen. Esto se hace con el objetivo de disminuir la cantidad de bits (tamaño) del mensaje y la energía asociada al envío del mismo. Por ejemplo, los mensajes enviados por el software meter.ino contienen datos del voltaje de la batería, la medición de volumen de agua acumulado y el caudal promedio, desde la última solicitud de datos, ordenados y delimitados por un carácter en específico. De esta forma, se diseñaron funciones específicas para la creación e interpretación de paquetes de información para que el sistema pueda comunicarse de forma exitosa.

Función para creación de paquetes de datos.

sprintf(mpack, "%.2f %s %.2f %s %.2f", demand_vol, delimiter, demand_av,

delimiter, battery_voltage);

LoRaSend(mpack, destination);

Una función "emisora" se encarga de tomar todos los datos que se necesitan transmitir y unirlos en una sola cadena de caracteres, utilizando la función sprintf. Una vez que el paquete llega al dispositivo destino, una función de interpretación en el receptor separa la cadena de caracteres de acuerdo con el orden y delimitador establecido, para asignar cada parte a una variable específica que puede ser el caudal de demanda, el estado de una de las bombas o una orden de activar el sistema de bombeo.

Interpretación de paquetes de mediciones recibidos por el software controlador.

```cpp

// incoming is the message received

incoming.toCharArray(charpacket,40);

int8_t p = 1; message_flag=0; attempt=0;

part = strtok(charpacket, delimiter);

while (part!=NULL) {

    if (p==1){

        pump15hp_flow = atof(part);    // RECEIVED PACKET TO FLOAT NUMBER

    }

    if (p==2){

        product_total = atof(part);    // FOR TANK LEVEL CALC

        pump15hp_vol += atof(part);    // RECEIVED PACKET TO FLOAT NUMBER

    }

    if (p==3){

        pump10hp_flow = atof(part);    // RECEIVED PACKET TO FLOAT NUMBER

    }

    if (p==4){

        product_total += atof(part);    // FOR TANK LEVEL CALC

        pump10hp_vol += atof(part);    // RECEIVED PACKET TO FLOAT NUMBER

    }

    if (p==5){

        prod_battery_voltage = atof(part);    // RECEIVED PACKET TO FLOAT NUMBER

    }

    p++;

    part=strtok(NULL, delimiter);

}

Serial .print("pump15hp_flow = "); Serial .println(pump15hp_flow);

Serial .print("pump15hp_vol = "); Serial .println(pump15hp_vol);

Serial .print("pump10hp_flow = "); Serial .println(pump10hp_flow);

Serial .print("pump10hp_vol = "); Serial .println(pump10hp_vol);

Serial .print("Battery Voltage = "); Serial .println(prod_battery_voltage,4);

```

Con relación con los datos que son manejados dentro de la red LoRaWAN $ ^{TM} $ se especificó que no existía algún requisito de confidencialidad. Esto considerando que la información está meramente relacionada con la operación de una institución de servicio público y datos de recurso hídrico a cargo de la ASADA de Playa Sámara de Nicoya. El fabricante de los SoC Heltec LoRa 32 V2 provee una librería de protocolo LoRaWAN $ ^{TM} $ , el cual permite la comunicación con cualquier LoRa $ ^{TM} $ Gateway que funcione con el protocolo LoRaWAN $ ^{TM} $ y todos los mecanismo de seguridad de transmisión de datos asociados al mismo. La información manejada en el sistema de comunicación carece de mecanismos de encriptación o cifrado en los mensajes adicionales a los incorporados en el protocolo LoRaWAN $ ^{TM} $ . Como mecanismo de identificación básico para cada dispositivo de la red LoRaWAN $ ^{TM} $ se asignó a cada transmisor una direc-

ción específica confidencial. De esta forma, los dispositivos únicamente escuchan mensajes que provengan de la dirección a la que enviaron. A pesar de que es un mecanismo de seguridad muy débil, evita que existan interferencias de comunicación si un dispositivo ajeno a la red LoRaWAN $ ^{TM} $ intentara comunicar mensajes a la misma frecuencia de operación.

## 4.3.1. Cálculo del presupuesto de potencia de la señal

Cada uno de los puntos por comunicar se encuentran distanciados entre sí poco más de 200 metros en línea recta, entre los puntos A-B y B-C mostrados en la figura 4.10. Lo que implica que el enlace de comunicación más lejano es de alrededor de 400 metros (del punto A al C).

El desconocimiento de la potencia de transmisión requerida para la comunicación por LoRa $ ^{TM} $ en el ambiente geográfico de Playa Sámara representó una limitación importante. Se logró establecer, en pruebas iniciales, un enlace de comunicación LoRa $ ^{TM} $ con un RSSI de -138dBm entre el medidor de demanda y los posos. Determinando un alcance de la señal LoRa $ ^{TM} $ cercano a los 200 m con una potencia de transmisión (TX) de 14 dB y una antena de 3 dBi. Se consideró la posibilidad de utilizar el dispositivo ubicado en el punto B como transmisor, sin embargo, por un tema de criticidad de comunicación entre el tanque y la estación de bombeo, se prefirió establecer un enlace de comunicación directa entre estos dos puntos.

Para posibilitar la comunicación entre los dos puntos de comunicación más lejanos (tanque y pozos) se definió la utilización de antenas direccionales de tipo Yagi. Se tomó el valor de potencia máxima de transmisión y la sensibilidad de receptor del Heltec LoRa V2 para presupuestar la ganancia requerida de las antenas, mediante las ecuaciones 3.1 y 3.2.

Al analizar el primer escenario de comunicación, se calcula un aproximado de las pérdidas de potencia por cables y obstáculos presente en Sámara a partir de la pérdida por distancia entre el medidor de demanda y los pozos (punto intermedio).

$$
F S L P _ {i n t e r m e d i a} [ d B ] = 9 2, 4 4 + 2 0 \log (0, 9 1 5 G H z) + 2 0 \log (0, 2 k m) = 7 7, 6 9 d B
$$

Así, a partir de la ecuación 3.2 se despejan las pérdidas por cables y obstáculos del RSSI medido en la primera prueba de campo.

$$
R S S I [ d B ] = T X [ d B ] + G a n a n c i a a n t e n a s [ d B ] - F S L P [ d B ] - P é r d i d a s a d i c i o n a l e s [ d B ]
$$

$$
P e r d i d a s a d i c i o n a l e s [ d B ] = T X [ d B ] + G a n a n c i a a n t e n a s [ d B ] - F S L P [ d B ] - R S S I [ d B ] = 8 0, 3 1 d B
$$

Una vez estimadas las pérdidas por cables y obstáculos se procede a calcular la ganancia de las antenas requeridas para un enlace de comunicación de 400 m. En este caso se utilizará la potencia máxima de transmisión que posee el Heltec LoRa V2 igual a 20 dB. Primero, se recalculan las pérdidas por distancia:

$$
F S L P _ {c r i t i c a} [ d B ] = 9 2, 4 4 + 2 0 \log (0, 9 1 5 G H z) + 2 0 \log (0, 4 k m) = 8 3, 7 1 d B
$$

Para luego presupuestar la potencia de enlace de la siguiente forma, donde la potencia del enlace PR debe ser mayor o igual a la sensibilidad del receptor RX:

$$
R X [ d B ] = T X [ d B ] + G a n a n c i a a n t e n a s [ d B ] - F S L P [ d B ] - P e r d i d a s a d i c i o n a l e s [ d B ]
$$

Para esta aplicación en específico se decidió mantener un margen de potencia en la comunicación (MG) de 20 dB para garantizar la estabilidad futura en el mismo.

$$
G a n a n c i a a n t e n a s [ d B ] = - T X [ d B ] - R X [ d B ] + F S L P [ d B ] + P e r d i d a s a d i c i o n a l e s [ d B ] + M G [ d B ]
$$

$$
G a n a n c i a a n t e n a s [ d B ] = - 2 0 d B - (1 3 8 d B) + 8 3, 7 1 d B + 8 0, 3 1 d B + 2 0 d B = 2 6 d B i
$$

De esta forma, se calcula que la ganancia de las antenas debe ser cercana a los 26 dBi entre los dispositivos ubicados a mayor distancia. A partir de este cálculo se seleccionan dos antenas direccionales de tipo Yagi con una ganancia de 11 dBi cada una (22 dBi en total).

## 4.3.2. Validación de comunicación en red LoRaWAN $ ^{TM} $ en Sámara

Se recomienda que, en un enlace de comunicación por LoRa $ ^{TM} $ , el indicador de fuerza de la señal recibida (RSSI) en el controlador central, ubicado en el tanque principal, sea mayor a -120 dBm [37] [38] para asegurar una fiabilidad en el transporte de datos. A pesar de que el Heltec LoRa V2 posee una sensibilidad como receptor cercana a los -139 dBm (hasta los -142dBm en pruebas de alcance realizadas) se prefirió mantener un margen de potencia en la señal, previendo posibles interferencias y/o pérdidas de potencia futuras.

Se registraron valores mínimos de -118 y -114 dBm al medir la potencia en la señal recibida (RSSI) por el controlador maestro, desde ambos nodos de medición durante aproximadamente 12 horas de operación. Ver figura 4.11. Ubicados en las localizaciones mostradas en la figura 4.10.

De esta forma se verifica el establecimiento de una red LoRaWAN $ ^{TM} $ en Sámara, que permite una comunicación por radio frecuencia estable entre los dispositivos involucrados.

## Asada Sámara


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.10: Posición de los dispositivos del sistema de IoT en el acueducto principal de Playa Sámara. Fuente: Elaboración propia, Canva.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.11: Potencia en la señal recibida (RSSI) por el controlador maestro, desde ambos nodos durante 24 horas de operación.

Fuente: Elaboración propia, AIO.

</div>

## 4.4. Permisos y capacitaciones en el uso de la plataforma.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.12: Capacitación efectuada a los funcionarios de la ASADA para el uso de la plataforma y dispositivos.

Fuente: Elaboración propia.

</div>

Las claves de acceso y operación de la plataforma fueron otorgadas al administrador del acueducto. Se recomendó que únicamente una persona tenga conocimiento de la clave de acceso a la plataforma en línea. Por otra parte, el usuario creado en la plataforma está asociado a una clave de identificación (IO Key) necesaria para la publicación de datos en los dispositivos. El acceso al IO Key está limitado al autor del proyecto y al administrador del acueducto.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 4.13: Acceso a información de la plataforma a los involucrados en la ASADA Sámara. Fuente: Elaboración Propia, Visio.

</div>

Se capacité a la totalidad del personal de la ASADA de Playa Sámara en uso e interacción con la plataforma. Se les explicó el significado de los distintos mensajes de alerta que puede publicar el sistema en la plataforma en línea y las acciones que se deben tomar en cada caso (ver tabla 4.2). Así mismo, se comentó acerca de las limitaciones, cuidados y tareas de mantenimiento asociadas a la operación del sistema de control y monitoreo.

<div align="center">

Tabla 4.2: Acciones requeridas con respecto a posibles mensajes de alerta que se envien a la plataforma

</div>

<table border="1"><tr><td>Mensaje de alerta</td><td>Gravedad</td><td>Acción necesaria</td></tr><tr><td>VOLÚMENES REINICIADOS</td><td>Baja</td><td>Ninguna. Los volúmenes acumulados se reinician al final de cada día a las 12 a.m.</td></tr><tr><td>TANQUE BIEN</td><td>Aviso</td><td>Ninguna.</td></tr><tr><td>TANQUE VACÍO</td><td>Aviso</td><td>Ninguna.</td></tr><tr><td>TANQUE LLENO</td><td>Aviso</td><td>Si el sistema se mantiene por mucho tiempo en este estado puede significar que el tanque se rebalsa. En ese caso revisar tanque.</td></tr><tr><td>AMBAS BOMBAS ENCENDIDAS POR ALTA DEMANDA</td><td>Aviso</td><td>Ninguna.</td></tr><tr><td>BOMBA 10HP ENCENDIDA POR INACTIVIDAD</td><td>Aviso</td><td>Ninguna.</td></tr><tr><td>SISTEMA AUTOMÁTICO APAGADO: ERROR EN SENSORES</td><td>Alta</td><td>Revisar de sensores de nivel de líquido en tanque principal. El sistema automático dejará de funcionar.</td></tr><tr><td>SISTEMA EN MODO MANUAL O ERROR TABLERO EN BOMBEO</td><td>Media / Alta</td><td>Revisar el tablero de control en bombeo en caso que no se haya activado el modo manual desde el tablero.</td></tr><tr><td>ALERTA: BATERÍA BAJA EN MACROMEDIDOR DEMANDA</td><td>Alta</td><td>Recargar baterías manualmente o gestionar la sustitución de las mismas</td></tr><tr><td>ALERTA: BATERÍA BAJA EN PRODUCCION</td><td>Alta</td><td>Recargar baterías manualmente o gestionar la sustitución de las mismas</td></tr><tr><td>ALERTA: BATERÍA BAJA EN TANQUE</td><td>Alta</td><td>Recargar baterías manualmente o gestionar la sustitución de las mismas</td></tr><tr><td>ALERTA: ERROR EN COMUNICACION LoRa CON MACROMEDIDOR DE DEMANDA</td><td>Alta</td><td>Verificar que el dispositivo esté encendido y contactar al ingeniero a cargo.</td></tr><tr><td>ALERTA: ERROR EN COMUNICACION LoRa CON PRODUCCION</td><td>Alta</td><td>Verificar que el dispositivo esté encendido y contactar al ingeniero a cargo.</td></tr><tr><td>ALERTA: Sistema reiniciado</td><td>Baja</td><td>Ninguna. Implica que puede existir un error en los volúmenes acumulados y el nivel del tanque calculado.</td></tr></table>

Fuente: Elaboración Propia.

<div align="center">

# Comunicación digital de flujómetros Octave

</div>

Los flujómetros Arad Octave, de tipo ultrasónico, representan una parte esencial de este proyecto. La exportación de información hídrica medida por los mismos es fundamental para la operación del sistema de IoT. Además, como parte del Proyecto de Fortalecimiento para la ASADAS, desarrollado por el PNUD, cientos de macro medidores hídricos Octave fueron donados a ASADAS a lo largo del país. Lo que ha generado que estos macro medidores sean la norma de medición hídrica en ASADAS.

Si bien, en el mercado de la automatización existen múltiples opciones de controladores lógicos programables (PLCs) ampliamente utilizados en aplicaciones de intercomunicación de automatización de máquinas, para este proyecto se optó por un enfoque distinto exento de PLCs. Con el objetivo de utilizar lenguajes de programación de acceso libre y dispositivos con un menor tamaño, menores requerimientos energéticos y un menor costo monetario de adquisición. De esta forma, se propone la utilización de sistemas en chip (SoC) de tipo ESP32 (fácilmente programables en C++ y soportados por Arduino IDE) para la automatización del acueducto principal.

En este capítulo se expone la lógica de comunicación empleada entre los flujómetros Arad Octave, encargados de medir caudal y volumen en el acueducto, y el SoC ESP32, encargado de interpretar y enviar los datos hídricos por radiocomunicación LoRa $ ^{TM} $ mediante el firmware programado meter.ino, descrito de forma general en este capítulo. De la misma forma, la lógica de medición de meter.ino se implementó en los firmware pump.ino y tank.ino para realizar las tareas de medición hídrica en el tanque principal y en el bombeo del acueducto. El lector puede consultar el código de este programa al dar click en el nombre del mismo o en la sección 10.5 de Anexos. Finalmente, se explican los experimentos de validación realizados para la interpretación de las señales recibidas del flujómetro, junto con los resultados obtenidos.

## 5.1. Lógica de comunicación por pulsos del flujómetro Octave

Los medidores Ultrasónicos Arad Octave poseen de distintas opciones de salidas eléctricas para comunicación: Doble salida de impulsos (digital) para los volúmenes, salida analógica (4-20mA) para rangos de flujo, y salidas Modbus y M-Bus para aplicaciones que requieran múltiples funcionalidades para controlar.

Octave posee tres tipos de salidas digitales (pulsos) disponibles: Una salida de transistor de drenaje abierto, una salida de contacto seco (relé) y la salida SSR (relé electrónico de estado sólido). Considerando que las variables más importantes para monitorizar en el acueducto serán los volúmenes, exclusivamente para la exportación de datos hídricos del medidor Octave, se seleccionó una salida de tipo digital con un módulo de conexión de pulsos de SSR. Esto con el objetivo de mantener la simplicidad y fiabilidad del ESP32 y el módulo de comunicación en la interpretación de la información proveniente del medidor Octave.

En la figura 5.1, se muestra el diagrama de conexión entre una entrada digital del SoC ESP32 y la entrada del módulo SSR Octave. El circuito consiste en una alimentación de la señal de 3,3 V en corriente directa, una resistencia de protección, un conmutador de SSR y una entrada de propósito general (GPIO) encargada de medir el estado de la señal. Cuando el conmutador se encuentre abierto el GPIO mide +3,3 V equivalente a un 1 lógico y cuando el conmutador se cierra el GPIO mide 0 V equivalente a un 0 lógico. De esta forma, es posible interpretar los cambios de estado del SSR (conmutador) como pulsos en la señal.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.1: Circuito "pull up" entre ESP32 y módulo de salida por pulsos SSR Fuente: Elaboración Propia, AutoCAD 2020.

</div>

Con el circuito anterior y el funcionamiento del flujómetro Ultrasónico Octave se genera un pulso por cantidad de volumen medio, dependiendo de la Resolución de pulso a la que fue programado el flujómetro Octave. En otras palabras, la Resolución de pulso representa cuánto equivale un pulso en

términos hídricos, específicamente en metros cúbicos de agua. Es decir, si el medidor Octave se programa con una Resolución de pulso de 1,0 m3 / pulso, cada vez que el flujómetro mida 1,0 m3 accionará el relé por un intervalo de tiempo fijo programable, dando una señal en forma de pulso. El intervalo de tiempo que dura el relé accionado se le llama ancho de pulso y, para efectos de la programación del medidor Octave, no varía en distintas condiciones de caudal. A diferencia del intervalo de tiempo que hay entre pulsos, el cual varía dependiendo de la magnitud de flujo hídrico medido. Este proceso para la comunicación de datos volumétricos es muy preciso y sencillo de interpretar, simplemente la cantidad de pulsos (interrupciones) simbolizan cuánto volumen de agua ha sido medido por el flujómetro. Sin embargo, para interpretar correctamente el caudal medido por el flujómetro, utilizando la comunicación por pulsos, es necesario realizar operaciones matemáticas y estadísticas adicionales.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.2: Interpretación de dos pulsos en salida digital de medidores Octave.

Fuente: Elaboración Propia.

</div>

Siguiendo la lógica de interpretación de volumen hídrico por Resolución de pulso de $1,0\mathrm{m}^{3}$ / pulso surgen dos variables importantes para el cálculo de caudal: el intervalo entre pulsos y el tiempo de muestreo. Si, por ejemplo, pasaran por el medidor $2,0\mathrm{m}^{3}$ en 5 segundos, se observarian 2 pulsos separados entre sí por 5 segundos, esta separación temporal entre pulsos sería el intervalo entre pulsos. En este escenario es posible inferir que el caudal hídrico promedio (Q) en esos 5 segundos fue de $0,40\mathrm{m}^{3}/\mathrm{s}$.

$$
Q = V o l u m e n \left(m ^ {3}\right) / t i e m p o (s e g u n d o s) = 2, 0 m ^ {3} / 5 s e g u n d o s = 0, 4 0 m ^ {3} / s
$$

De forma similar, si teóricamente pasaran $100\mathrm{m}^{3}$ con un caudal totalmente constante durante una hora (3 600 segundos), observariamos 100 pulsos distribuidos uniformemente separados 36 segundos entre sí. Observando los 100 pulsos distribuidos durante una hora, podríamos inferir que el caudal promedio durante esa hora es de $100\mathrm{m}^{3}/\mathrm{h}$. En este ejemplo el intervalo entre pulsos sería de 36 segundos y mientras que el tiempo de muestreo corresponde a una hora (tiempo al que corresponde el caudal promedio calculado). Esta misma lógica es aplicable para intervalos entre pulsos y tiempo de muestreo más cortos, siempre y

cuando la resolución de pulso lo permita y no interfieran con el ancho de pulso programado en el medidor Octave. Si se calcula el caudal, unicamente utilizando el intervalo entre dos pulsos y la resolución de pulso, se calcularía un caudal promedio durante ese intervalo de pulso, el cual se podría tomar como un caudal "instantáneo" $ \left( \mathrm{Q}_{i} \right) $ . En las condiciones del ejemplo anterior, con un intervalo entre pulsos $ \left( \Delta t \right) $ de 36 segundos y una resolución de pulso (RP) de $ 1 \mathrm{~m}^{3} $ , es posible calcular el caudal promedio durante esos 36 segundos, de la siguiente forma:

$$
Q _ {i} = R P / \Delta t = 1, 0 m ^ {3} / 3 6 s e g u n d o s = 0, 0 2 8 m ^ {3} / s = 1 0 0 m ^ {3} / h
$$

En este ejemplo, como el caudal es teóricamente constante durante toda la hora, el caudal promedio y el caudal "instantáneo" (para los 36 segundos) son equivalentes. En la práctica el caudal difícilmente será constante durante periodos prolongados de tiempo, por lo que muy probablemente no exista ese comportamiento de pulsos en la realidad, pero la lógica aplicada en la interpretación será la base para la utilizada en la práctica.

Para efectos del proyecto, los intervalos entre la solicitud de información de mediciones pueden variar. Esto debido a que el controlador maestro puede retrasarse en la solicitud de información a cada nodo de medición, por estar ocupado realizando tareas de control, o pueden ocurrir errores en la comunicación por $LoRa^{TM}$. Lo cual, afecta los tiempos de respuesta y solicitud de datos.

Mediante la comunicación por pulsos, ideal para comunicar volumen, es posible calcular un caudal promedio para un periodo de tiempo muy corto (utilizando el intervalo entre dos pulsos) que podría tomarse como medición "instantánea" de caudal. A partir de un conjunto de mediciones "instantáneas" se calcula un caudal promedio para tiempos de muestreo variables, que corresponden a los intervalos temporales entre solicitudes del controlador maestro.

Es importante resaltar que, bajo esta lógica de interpretación de caudal, la exactitud del caudal promedio se ve afectada directamente por la cantidad de pulsos que ocurridos en el tiempo de muestreo. Adicionalmente, la cantidad de pulsos que ocurren dependen de la resolución de pulso programada en el medidor Octave y la magnitud de caudal sucede en el momento. Esto significa que la cantidad de mediciones "instantáneas", registradas en un tiempo de muestreo fijo, varía con el caudal. A mayor caudal, mayor cantidad de volumen es medio, mayor cantidad de pulsos y por ende mayor cantidad de mediciones "instantáneas".

## 5.1.1. Funcionamiento del firmware de medición

Considerando lo anteriormente expuesto, se programó en C++ un software para la medición mostrado en la figura 5.3. Este software se ejecuta, utilizando un procesador secundario del ESP32, de forma simultánea con cada uno de los software de comunicación descritos en el capítulo anterior (meter.ino, pump.ino y tank.ino) para interpretar las señales digitales del medidor Octave.

> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.3: Diagrama de programación para software de interpretación de pulsos en salida digital de medidores Octave.

Fuente: Elaboración Propia.

</div>

Este programa se encarga de contabilizar digitalmente el volumen acumulado y calcular el caudal instantáneo y promedio a partir de la comunicación con el flujómetro Octave. Utilizando las siguientes fórmulas:

$$
Q _ {i n s t a n t á n e o} [ L / s ] = \left(1 \times 1 0 ^ {9} \times \frac {L}{s} \times \frac {\mu s}{m ^ {3}}\right) \times \left(\frac {R e s o l u c i o n d e P u l s o [ m ^ {3} ]}{I n t e r v a l o e n t r e p u l s o s [ \mu s ]}\right)
$$

Para el cálculo del caudal promedio, se efectúa un promedio ponderado para cada una de las mediciones instantáneas de caudal de la siguiente forma:

$$
Q _ {p r o m e d i o} [ L / s ] = \frac {\sum \left(Q _ {i n s t a n t a n e o} ^ {n} [ L / s ] \times I n t e r v a l o e n t r e p u l s o ^ {n} [ \mu s ]\right)}{\sum \left(I n t e r v a l o e n t r e p u l s o [ \mu s ]\right)}
$$

Al sustituir la ecuación 5.3 en 5.4, se obtiene una fórmula simplificada para un proceso de cálculo del caudal promedio más eficiente en el software. Tomando en cuenta que la cantidad de mediciones instantáneas de caudal es igual a la cantidad de pulsos se tiene la siguiente relación:

$$
Q _ {p r o m e d i o} [ L / s ] = \left(1 \times 1 0 ^ {9} \times \frac {L}{s} \times \frac {\mu s}{m ^ {3}}\right) \times \left(\frac {V _ {a c u m u l a d o} \left[ m ^ {3} \right]}{\sum \left(\mathrm {I n t e r v a l o e n t r e p u l s o s} \left[ \mu s \right]\right)}\right)
$$

Como se muestra en la figura 5.4, el software mide el intervalo entre pulsos $ \Delta $ t, en microsegundos, cada vez que ocurre una interrupción de bajada (estado lógico del pin de 1 a 0) y calcula una medición de caudal instantáneo mediante la relación 5.3. En cada interrupción se acumula, en una variable específica, la sumatoria total de cada uno de los intervalos medios. Una vez pasado el tiempo de muestreo, se recibe la orden del controlador maestro para enviar el volumen acumulado y el cálculo de caudal promedio. Cuando se recibe una señal de que el controlador maestro recibió con éxito el paquete de medición, se restablece a cero la sumatoria de los intervalos entre pulsos y el volumen acumulado, reiniciando el proceso de medición.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.4: Interpretación de pulsos en salida digital de medidores Octave.

Fuente: Elaboración Propia.

</div>

Así mismo, si deja de fluir agua por el medidor y, por ende, no se reciben más señales para un intervalo de tiempo mayor a 60 segundos, el software registra un caudal de cero, reinicia el proceso de medición de caudal y detiene el proceso de medición de intervalo temporal entre pulsos. El proceso reinicia cuando se reciba una nueva señal de pulso.

Con lo anterior en mente, es necesario seleccionar y programar un tiempo de muestreo, un ancho de pulso y una resolución de pulso que permitan interpretar una medición de caudal en tiempo real exacta con respecto a medición efectuada internamente por el flujómetro Octave. La resolución de pulso y el ancho de pulso son parámetros programables en el medidor Octave. El tiempo de muestreo es un parámetro que se programa en el controlador maestro del sistema de IoT (firmware tank.ino) y corresponde a la frecuencia con la que el maestro solicita datos hídricos para publicar en la plataforma de internet. Para efectos del proyecto, la solicitud de datos fue programada para efectuarse cada 2 minutos aproximadamente. Para las pruebas de funcionamiento efectuadas en el sistema, el tiempo de muestreo es un valor que varía levemente entre 120 y 150 segundos, dependiendo de la calidad de señal en la comunicación LoRa y la disponibilidad del controlador maestro.

En el acueducto principal de la Asada de Playa Sámara se cuenta con dos medidores Octave de 100 mm (4 in) y un Octave de 50 mm (2 in). Cada uno de los flujómetros Octave tiene un ámbito distinto de caudal normal de operación. A partir de las condiciones habituales de operación del medidor y el tiempo de muestreo se seleccionaron los parámetros de resolución de pulso y el ancho de pulso para cada Octave. Ver tabla 5.1.

Cambios en los parámetros de programación del flujómetro Octave únicamente pueden ser efectuados por un distribuidor certificado por el fabricante Arad. Para efectos del proyecto se solicitó a la empresa COPRODESA (único distribuidor oficial de Arad en Costa Rica) la programación de los equipos Octave con los parámetros mostrados en la tabla 5.1.

<div align="center">

Tabla 5.1: Resumen de parámetros de programación para medidores Octave instalados en el acueducto de Playa Sámara.

</div>

<table border="1"><tr><td>Flujómetro</td><td>Octave 100 mm</td><td>Octave 100 mm</td><td>Octave 50 mm</td></tr><tr><td>Ubicación</td><td>Pozos</td><td>Demanda</td><td>Tanque</td></tr><tr><td>Caudal típico [L/s]</td><td>125</td><td>90</td><td>10</td></tr><tr><td>Caudal típico [m3/h]</td><td>450</td><td>324</td><td>36</td></tr><tr><td>Caudal máximo [L/s]</td><td>347</td><td>347</td><td>139</td></tr><tr><td>Caudal máximo [m3/h]</td><td>1250</td><td>1250</td><td>500</td></tr><tr><td>Resolución de pulso [m3/pulso]</td><td>0.01</td><td>0.01</td><td>0.001</td></tr><tr><td>Cant. pulsos/min(típica)</td><td>75</td><td>54</td><td>60</td></tr><tr><td>Intervalo teórico entre pulsos(típico)[ms]</td><td>800</td><td>1111</td><td>1000</td></tr><tr><td>Cant. pulsos/min(máxima)</td><td>208</td><td>208</td><td>833</td></tr><tr><td>Intervalo teórico entre pulsos(mínimo)[ms]</td><td>288</td><td>288</td><td>72</td></tr><tr><td>Ancho de pulso progamado[ms]</td><td>93</td><td>90</td><td>6</td></tr></table>

Fuente: Elaboración Propia.

## 5.2. Experimentos de validación y resultados obtenidos para la comunicación con el módulo SSR Octave

Para el desarrollo y validación del software que interpreta las mediciones de caudal y volumen hídrico realizadas por el flujómetro Octave, fue necesario efectuar una serie de experimentos. Dichos experimentos permitieron conocer el comportamiento real de las señales digitales entregadas por flujómetros Octave de distintos tamaños y modelos (50 mm(2 in)-2020, 100 mm(4 in)-2015, 100 mm(4 in)-2016, respectivamente).

Las pruebas de funcionamiento realizadas con cada flujómetro consiste en una comparación de los datos hídricos de caudal y volumen reportados en la pantalla del medidor Octave frente a la interpretación de los datos hídricos efectuadas por el software meter.ino. En las siguientes secciones se presentan los resultados obtenidos para cada medidor Octave.

## 5.2.1. Octave de 50 mm (2 in) instalado en el TEC.

Los primeros experimentos se realizaron con un medidor Octave de 50 mm, adquirido por la ASADA de Playa Sámara. Este medidor se destinará para medir los volúmenes y caudales de demanda que viajan alrebombeo del acueducto. Aprovechando que al inicio del proyecto este flujómetro aún no se encontraba instalado en el acueducto, se utilizó como flujómetro experimental. Debido a que la ASADA carece de un equipo de bombeo modular e instalaciones experimentales que permitan someter al flujómetro a condiciones de operación variables, se solicito trasladar el flujómetro Octave de 50 mm a la Escuela de Ingeniería Electromecánica del Tecnológico de Costa Rica. Con el objetivo de instalarlo en la pared de agua existente en la escuela y efectuar las pruebas de funcionamiento descritas anteriormente.


> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.5: Instalación de medidor Octave de 50 mm en pared hídrica Fuente: Elaboración Propia.

</div>

Una vez que se contó con los permisos por parte de la ASADA y el Área de termo-fluidos de Escuela de Ingeniería Electromecánica, el flujómetro Octave de 50 mm se trasladó y se instaló (con ayuda del colega Pablo Vargas) en la pared hídrica de dicha escuela. Ver figura 5.5.

Es importante aclarar que el medidor Octave de 50 mm estaba configurado de fábrica con una resolución de pulso de 0,01 m $ ^{3} $ / pulso para todas las pruebas efectuadas en esta sección. Posteriormente, para efectos de operación en el acueducto, el medidor se programó con los parámetros presentados en la tabla 5.1. El módulo de comunicación utilizado en los experimentos de esta sección fue un módulo digital por pulsos SSR.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Intervalo de tiempo registrado entre pulsos en módulo SSR

de comunicación Octave

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.6: Resultados de interpretación en mediciones de flujo para el flujómetro Octave de 50 mm (2 in). Fuente: Flaboración Propia Excel

</div>

La lógica de interpretación de señales utilizada en esta prueba fue distinta a la explicada en la sección 5.1.1. En este caso la lógica utilizaba un tiempo de muestreo de 5 segundos para promediar los intervalos de pulso que existieron en esos 5 segundos para luego calcular el caudal promedio en ese tiempo. Este promedio de 5 segundos que representaba la medición "instantánea".

Al utilizar esta lógica de interpretación se identificó un inconveniente importante. Como se muestra en el recuadro rojo de la figura 5.6, un tiempo de muestreo tan corto genera que el software reporte una medición de 0,0 m $ ^{3} $ / h cuando aún fluye agua por la tubería. Esto sucede porque durante el tiempo de muestreo de 5 segundos no se envió una señal de pulso. Esto evidenció una limitante en la lógica de interpretación cuando un intervalo entre pulsos es mayor al tiempo de muestreo. Ocasionando que caudales bajos sean ignorados y reportando mediciones erróneas de 0,0 m $ ^{3} $ / h.

Con relación a los datos de volumen interpretados en el experimente se obtuvo un porcentaje de error de %0. Esto significa que la cantidad de volumen de agua contabilizado en la pantalla del flujómetro, durante los cuatro minutos de muestreo, fue exactamente igual a la cantidad de volumen interpretada por el software meter.ino implementado en el ESP32. Sin embargo, la lógica de cálculo de por tiempo de muestreo de 5 segundos ocasiona que la medición de volumen se actualice cada 5 segundos. En otras palabras, la medición de volumen del ESP32 se "atrasa" en comparación con la medición reportada en la pantalla del flujómetro Octave (la cual se actualiza cada segundo). Ver figura 5.7.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.7: Resultados de interpretación para mediciones volumétricas en Octave de 50 mm. Fuente: Elaboración Propia. Excel.

</div>

Por estas razones, se abandonó la lógica anteriormente utilizada y se diseñó la lógica de interpretación presentada en la sección 5.1.1. Al descartar la medición errónea de caudal descrita anteriormente, el porcentaje de error para la medición de caudal promedio en este experimento se redujo a 0,56 %, para los cuatro minutos de muestreo.

## Restricción en la comunicación de señales de volumen en tiempo real

En los experimentos realizados con el módulo de comunicación digital por pulsos SSR para flujómetros Octave se observó un comportamiento en la comunicación inesperado. Al analizar los intervalos entre pulsos registrados para distintas mediciones de flujos hídricos se observa un comportamiento que hace sospechar de una restricción en la comunicación en tiempo real del medidor. Si el lector analiza la figura 5.6 podrá identificar "saltos" bruscos y constantes en los valores de flujo instantáneo calculados por el ESP32 (línea color naranja en gráfico superior).

Si ahora se analiza el gráfico inferior de la misma figura 5.6, se identifican "saltos" similares para los intervalos entre pulsos medidas por el ESP32. Por alguna razón el módulo de pulsos SSR, utilizado en el experimento, solamente generó señales de pulsos en ventanas de comunicación de 1 segundo, es decir, los pulsos siempre se separan 2, 3, 4, 5 o 6 segundos discretos. Recordando que cada pulso simboliza una cantidad de volumen medida (en este caso 0,01 $ \mathrm{m}^{3} $ / pulso), un comportamiento de la señal en tiempo real "normal" para caudales variables serían pulsos separados por intervalos de tiempo no discretos.

Para distintos caudales es de esperar que al medidor le tome distintas cantidades de tiempo en medir 10 litros de agua (0,01 m $ ^{3} $ ). Si tomamos por ejemplo las mediciones de caudal tomadas antes que transcurrieran 1:26 minutos de la figura 5.6, el caudal varía entre 12,0 m $ ^{3} $ /h y 14,0 m $ ^{3} $ /h. Un caudal de 12,0 m $ ^{3} $ /h se asoci con un intervalo entre pulsos de 3,00 segundos y un caudal de 14,0 m $ ^{3} $ /h se asoci con un intervalo entre pulsos de 2,57 segundos. Si ahora observamos la línea azul en la figura 5.6 el flujómetro Octave en ningún momento registró un caudal de 12,0 m $ ^{3} $ /h, pero aún así envió pulsos separados por intervalos de 3 y 2 segundos. Mientras que para las demás mediciones de caudal registradas entre 14,0 m $ ^{3} $ /h y 12,0 m $ ^{3} $ /h no envió pulsos separados por intervalos entre de 3,00 y 2,57 segundos.

Este comportamiento de comunicación por pulsos ocasiona que los cálculos de flujo instantáneo discrepen con relación a los flujos reportados cada segundo en la pantalla del flujómetro Octave. Sin embargo, al largo plazo estos errores se "compensan", ocasionando que el cálculo de flujo promedio reportado por ambos dispositivos sea lo suficientemente similar.

Se consultó con COPRODESA (proveedor nacional de ARAD) si conocían la razón de este comportamiento y si el mismo era modificable en la programación del flujómetro. Sin embargo, en ese momento desconocían que el flujómetro Octave se comportaba de esa manera. Uno de los ingenieros de COPRODESA consultó, a la parte técnica del fabricante ARAD, si este comportamiento podía cambiarse en la programación del flujómetro Octave, pero desafortunadamente para el cierre del proyecto no se obtuvo respuesta alguna por parte del fabricante.

Los representantes de COPRODESA recomendaron utilizar una salida de tipo analógica (4-20mA) en aplicaciones que requieran comunicar específicamente el caudal medio por el flujómetro Octave. Para efectos del proyecto se descartó esta posibilidad y debido a que representa la necesidad de una electrónica y lógica distinta de comunicación. Tomando en cuenta el contexto de operación del sistema de IoT para la ASADA de Playa Sámara, se considera como aceptable un porcentaje de error menor al 1% respecto al flujómetro Octave. A continuación, se demostrará que los cálculos de caudal a partir de señales de volumen pueden tener una exactitud aceptable para la aplicación de medición en la ASADA.

## 5.2.2. Octave de 100 mm (4 in) presente en el acueducto de la ASADA.

Para conocer el funcionamiento de flujómetros Octave de mayor tamaño se efectuaron los mismos experimentos con dos medidores de 4 in ya instalados en el acueducto de Playa Sámara. Estos medidores son utilizados para medir caudales de mayor magnitud, correspondientes a la demanda principal del acueducto y la extracción total de agua realizada por el equipo de bombeo. Inicialmente se efectuó el experimento con el medidor de la demanda principal. En la figura 5.8 se muestran las conexiones realizadas en campo para llevar a cabo el experimento.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.8: Experimento con el medidor Octave de 100 mm (4 in) para la demanda principal de acueducto Fuente: Elaboración Propia.

</div>

El medidor Octave de 100 mm instalado en la demanda (ver figura 5.9) tenía una Resolución de pulso de 0,1 m $ ^{3} $ / pulso, programado de fábrica. Esta resolución de pulso, para los caudales típicos a los que está sometido el medidor, representó un inconveniente importante a la hora de interpretar una medición de caudal.

Al medir los intervalos entre pulsos de las señales entregadas por el módulo SSR Octave, se observó el mismo comportamiento observado en el medidor Octave de 50 mm (2 in). Los intervalos entre pulsos igualmente se daban con valores discretos de 9, 10 y 11 segundos para las mediciones efectuadas. En estas condiciones el tiempo de muestreo de 2 minutos no fue suficiente para capturar los pulsos suficientes que permitieran calcular caudales "instantáneos" representativos para un caudal típico de operación de 9,79 L/s (ver figura 5.9).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.9: Medición de intervalo entre pulsos en módulo SSR Octave, para un caudal típico de demanda. Fuente: Elaboración Propia.

</div>

Como resultado de este experimento se obtuvo un porcentaje de error en la interpretación del caudal promedio durante dos minutos de 14,3 %. Los datos obtenidos con los parámetros de de comunicación descritos anteriormente, se consideraron inacceptable para efectos de este proyecto. Por lo que el medidor instalado en la demanda fue programado con los parámetros descritos en la tabla 5.1.

## Verificación definitiva de interpretación de señales digitales de Octave.

Como prueba de validación final, se realizó el mismo experimento con los parámetros de funcionamiento para el medidor Octave de 100 mm, ubicado a la salida de los pozos, presentado en la tabla 5.1. Para este caso se obtuvo una mejor interpretación de las mediciones de caudal promedio, gracias a que se programó una Resolución de pulso de 0,01 m $ ^{3} $ / pulso. Este parámetro de funcionamiento provoca que el medidor Octave entregue una mayor cantidad de pulsos posibilitando una mayor cantidad de mediciones efectuadas por el SoC ESP32. Ver la figura 5.10.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.10: Resultados obtenidos para la interpretación de señales en Octave de 100 mm. Fuente: Elaboración Propia.

</div>

Si bien ocurre el mismo comportamiento inusual para los intervalos entre pulsos, provocando una desigualdad importante para las mediciones de caudal instantáneas (efectuadas con cada interrupción en la señal), el caudal promedio calculado se asemeja al caudal promedio reportado por el medidor Octave durante el tiempo de muestreo mostrado. Esta lógica de interpretación representó la mejor similitud con los

datos de caudal medidas por el flujómetro Octave, con un porcentaje de error de 0,72 % para el promedio reportado.

## 5.2.3. Simulación de flujos variables con generador de señales.

Para descartar defectos en la programación que interfieran con la medición de flujo, se efectuaron una serie de mediciones, utilizando un generador de señales. Este instrumento simuló flujos hídricos variables mediante señales de onda cuadrada con distintas frecuencias. Como se muestra en la figura 5.11, se conectó el generador de señales al pin de entrada de señal en el Heltec LoRa V2 como si fuera el flujómetro Octave.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.11: Montaje de experimento de simulación de flujo con el generador de señales Fuente: Elaboración Propia.

</div>

Con el objetivo de poner a prueba la capacidad del software programado para medir los intervalos temporales entre pulsos e interpretar mediciones, se conectó en paralelo un osciloscopio para observar la señal y medir manualmente los intervalos de tiempo entre pulsos (ver figura 5.12). El experimento consistió en una comparación entre las mediciones reportadas por el software y las mediciones manuales, utilizando un osciloscopio, para intervalos entre pulsos variables.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.12: Medición con osciloscopio de intervalos entre pulsos para la señal cuadrada generada.

Fuente: Elaboración Propia.

</div>

En la tabla 5.2.3 se muestran los intervalos entre pulsos medidas por los dispositivos para distintas frecuencias de señal entregada por el generador de señales, junto con el cálculo de porcentaje de error para cada muestra (tomando como valor teórico el medida con el osciloscopio). Como resultado se obtuvo un porcentaje de error promedio de 0,134 %. Este porcentaje de error se considera aceptable para la aplicación de funcionamiento. Es importante tomar en cuenta que la resolución del osciloscopio utilizado es mil veces menor a la resolución del SoC ESP32, por lo que muy probablemente contribuye a la leve discrepancia en las mediciones evidenciada en el porcentaje de error.

En este experimento se evidencia la capacidad del software meter.ino implementado en SoC ESP32 para interpretar distintos caudales asociados a señales de pulsos de frecuencia variable. Como se muestra en la figura 5.13, los intervalos temporales entre pulsos medios son inversamente proporcionales al caudal hídrico simulado.

Por otra parte, se demostró la capacidad de envío, por una red LoRaWAN $ ^{TM} $ compuesta por dos dispositivos Heltec LoRa V2 ubicada en el laboratorio, y exportación de los datos hídricos simulados a la plataforma en línea Adafruit IO (AIO). La totalidad de los datos hídricos tomados (promedio de mediciones cada dos minutos) en el experimento fueron publicados y graficados en tiempo real con éxito en AIO. Ver figura 5.14.

<div align="center">

Tabla 5.2: Comparación de intervalos temporales medidas con ESP32 y osciloscopio.

</div>

<table border="1"><tr><td>Intervalo entre pulsos ESP(μs)</td><td>Periodo medio en Osciloscopio(s)</td><td>% Error en medición temporal</td><td>Frec. de la señal(mHz)</td><td>Flujo calculado en ESP(m3/h)</td></tr><tr><td>3752668</td><td>3760</td><td>0.195%</td><td>265</td><td>959317</td></tr><tr><td>3643390</td><td>3640</td><td>0.093%</td><td>274</td><td>988091</td></tr><tr><td>3323619</td><td>3320</td><td>0.109%</td><td>301</td><td>1083157</td></tr><tr><td>3680284</td><td>3680</td><td>0.008%</td><td>271</td><td>978185</td></tr><tr><td>3559306</td><td>3560</td><td>0.019%</td><td>280</td><td>1011433</td></tr><tr><td>3723552</td><td>3730</td><td>0.173%</td><td>268</td><td>966819</td></tr><tr><td>3275176</td><td>3270</td><td>0.158%</td><td>305</td><td>1099178</td></tr><tr><td>3342109</td><td>3340</td><td>0.063%</td><td>299</td><td>1077164</td></tr><tr><td>3198605</td><td>3200</td><td>0.044%</td><td>312</td><td>1125491</td></tr><tr><td>2997714</td><td>3000</td><td>0.076%</td><td>333</td><td>1200915</td></tr><tr><td>3053711</td><td>3050</td><td>0.122%</td><td>327</td><td>1178893</td></tr><tr><td>2810394</td><td>2810</td><td>0.014%</td><td>355</td><td>1280959</td></tr><tr><td>2768557</td><td>2770</td><td>0.052%</td><td>361</td><td>1300316</td></tr><tr><td>2838131</td><td>2830</td><td>0.287%</td><td>353</td><td>1268440</td></tr><tr><td>2749400</td><td>2750</td><td>0.022%</td><td>363</td><td>1309377</td></tr><tr><td>2730773</td><td>2730</td><td>0.028%</td><td>366</td><td>1318308</td></tr><tr><td>2705489</td><td>2710</td><td>0.166%</td><td>369</td><td>1330628</td></tr><tr><td>2611721</td><td>2610</td><td>0.066%</td><td>383</td><td>1378401</td></tr><tr><td>2572307</td><td>2570</td><td>0.090%</td><td>389</td><td>1399522</td></tr><tr><td>2492018</td><td>2500</td><td>0.319%</td><td>400</td><td>1444612</td></tr><tr><td>2420190</td><td>2420</td><td>0.008%</td><td>413</td><td>1487487</td></tr><tr><td>2299874</td><td>2300</td><td>0.005%</td><td>434</td><td>1565303</td></tr><tr><td>2251112</td><td>2250</td><td>0.049%</td><td>444</td><td>1599210</td></tr><tr><td>2204886</td><td>2200</td><td>0.222%</td><td>454</td><td>1632737</td></tr><tr><td>2185988</td><td>2180</td><td>0.275%</td><td>458</td><td>1646853</td></tr><tr><td>2117724</td><td>2120</td><td>0.107%</td><td>471</td><td>1699938</td></tr><tr><td>2095185</td><td>2100</td><td>0.229%</td><td>476</td><td>1718225</td></tr><tr><td>2064333</td><td>2070</td><td>0.274%</td><td>483</td><td>1743905</td></tr><tr><td>1966675</td><td>1960</td><td>0.341%</td><td>510</td><td>1830501</td></tr><tr><td>1906372</td><td>1910</td><td>0.190%</td><td>523</td><td>1888404</td></tr><tr><td>1867115</td><td>1870</td><td>0.154%</td><td>534</td><td>1928108</td></tr><tr><td>1745323</td><td>1740</td><td>0.306%</td><td>574</td><td>2062655</td></tr><tr><td>1376714</td><td>1375</td><td>0.125%</td><td>727</td><td>2614922</td></tr><tr><td>1282533</td><td>1280</td><td>0.198%</td><td>781</td><td>2806945</td></tr><tr><td>911422</td><td>0,910</td><td>0.156%</td><td>1090</td><td>3949872</td></tr><tr><td>570714</td><td>0,570</td><td>0.125%</td><td>1750</td><td>6307888</td></tr><tr><td>427675</td><td>0,428</td><td>0.076%</td><td>2330</td><td>8417607</td></tr><tr><td colspan="2">Máximo</td><td>0,341%</td><td></td><td></td></tr><tr><td colspan="2">Mínimo</td><td>0,005%</td><td></td><td></td></tr><tr><td colspan="2">Promedio</td><td>0,134%</td><td></td><td></td></tr><tr><td colspan="2">Desviación estándar</td><td>0,098%</td><td></td><td></td></tr></table>

Fuente: Elaboración Propia.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.13: Medición de intervalo temporal entre pulsos vs caudal hídrico simulado Fuente: Elaboración Propia, Excel.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 5.14: Simulación del envío de datos por LoRa $ ^{TM} $ y publicación de datos hídricos en internet. Fuente: Elaboración Propia.

</div>

## Diseño electrónico

En el presente capítulo se expone la selección de los componentes electrónicos necesarios para la operación del sistema de IoT propuesto, tomando los requerimientos expuestos en la sección 1.3.3. Esto involucró el microcontrolador Heltec LoRa 32 V2, el gestor de carga de energía solar (encargado de la alimentación eléctrica), el dimensionamiento de las baterías, la selección de paneles solares, el diseño del circuito electrónico que une todos estos componentes y la fabricación del mismo.

## 6.1. Consideraciones y requerimientos establecidos para el diseño del circuito electrónico

La principal consideración, al iniciar el proceso de diseño de hardware, fue la similitud en las funciones que se requieren efectuar en cada uno de los puntos de comunicación. Si bien las necesidades de monitoreo en cada localización involucran distintos dispositivos con sus respectivos requerimientos de alimentación (ver tabla 6.1), se diseño un único hardware que reuniera los requerimientos integrales del sistema, buscando que fuese lo más compacta, sencilla y de fácil manufactura. Así, a pesar de que cada punto de comunicación posee un software de operación distinto, la solución de hardware sería la misma para todos los puntos. Con lo anterior en mente, el circuito electrónico se diseño para cumplir con los siguientes requerimientos:

- Debe tener la capacidad para alimentar energética el SoC Heltec LoRa V2, los módulos de comunicación SSR para los flujómetros Octave, los sensores de detección de líquido y el Router para el acceso a internet mediante WiFi. Esto a partir del controlador de carga solar para las baterías.

- Debe posibilitar la interpretación de señales digitales provenientes de los dos sensores de detección de líquido.

- Debe mantener el voltaje para todas las señales digitales recibidas por el SoC ESP32 en un valor menor a 3,3 V.

- Debe permitir la interpretación de señales digitales provenientes del módulo de comunicación SSR para dos flujómetros.

- Debe enviar una señal digital con el mayor voltaje posible, en corriente directa, al tablero de control eléctrico de bombeo para la activación de dos moto-bombas de forma independiente o simultánea.

- Debe recibir señales del circuito de control eléctrico sobre el estado de los contactores de alimentación de las moto-bombas por separado.

- Debe tener una geometría que facilite un ensamble en la parte superior con el circuito controlador de carga solar para las baterías mediante separadores verticales.

- El dispositivo diseñado debe ser manufacturado en una placa de circuito impreso (PCB).

## 6.2. Dispositivos involucrados

<div align="center">

Tabla 6.1: Dispositivos involucrados para la operación del sistema por ubicación en el acueducto.

</div>

<table border="1"><tr><td>Ubicación</td><td>Dispositivos</td><td>Consumo máximo(mA)</td><td>Voltaje de alimentación(V)</td></tr><tr><td rowspan="6">Pozos de producción</td><td>Módulo de señales Octave</td><td>30</td><td>12</td></tr><tr><td>Módulo de señales Octave</td><td>30</td><td>5-24</td></tr><tr><td>Relé de estado sólido(SSR)</td><td>15</td><td>3-32</td></tr><tr><td>Relé de estado sólido(SSR)</td><td>15</td><td>3-32</td></tr><tr><td>Heltec LoRa V2</td><td>135</td><td>3,3-5</td></tr><tr><td>Total</td><td>225</td><td></td></tr><tr><td rowspan="6">Tanque de almacenamiento principal</td><td>Módulo de señales Octave</td><td>30</td><td>5-24</td></tr><tr><td>Huawei Router 4G B311</td><td>250</td><td>12</td></tr><tr><td>Sensor de nivel líquido</td><td>20</td><td>5</td></tr><tr><td>Sensor de nivel líquido</td><td>20</td><td>5</td></tr><tr><td>Heltec LoRa V2</td><td>135</td><td>3,3-5</td></tr><tr><td>Total</td><td>455</td><td></td></tr><tr><td rowspan="3">Medidor de demanda</td><td>Módulo de señales Octave</td><td>30</td><td>5-24</td></tr><tr><td>Heltec LoRa V2</td><td>135</td><td>3,3-5</td></tr><tr><td>Total</td><td>165</td><td></td></tr></table>

Fuente: Elaboración Propia.

## 6.3. Alimentación eléctrica mediante energía solar

La autonomía energética del sistema de IoT fue parte de los requerimientos presentados por la administración de la ASADA. Esto considerando el difícil acceso a electricidad pública en dos puntos de monitoreo en el acueducto (el tanque principal y el medidor de demanda principal). De esta forma, se propuso la alimentación energética de todos los dispositivos presentes en el sistema utilizando baterías, con celdas de ion-litio tipo 18650 de 3,7 V y un sistema de carga por paneles solares.

Un aspecto importante por considerar fue la variedad de voltajes de alimentación que tienen los dispositivos requeridos para el funcionamiento del sistema de IoT. Como se muestra en la tabla 6.1, el rango de voltajes de alimentación varía entre 3,3 V hasta 24 V en corriente directa. Para solucionar la alimentación de potencia de los equipos se investigaron distintos dispositivos controladores de carga solar para baterías de ion-litio en el mercado, concluyendo que la mejor alternativa consistió en la adquisición del administrador de energía solar Solar Power Manager SKU DFR0535 del fabricante DFRobot.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.1: Descripción general de la placa Solar Power Manager DFR0535 Fuente: DFRobot.

</div>

Este dispositivo satisface todas las necesidades de alimentación de potencia del sistema, considerando que posee tres salidas de tensión a 3,3 V (DC), 5 V (DC) y 12 V (DC) que además cumplen con los requerimientos de potencia máxima requerida por el sistema. Adicionalmente, este módulo posee incorporado en su electrónica el MPPT (Seguimiento del punto de máxima potencia) para maximizar la eficiencia de conversión de energía solar bajo diversas intensidades de rayos del sol. Cuenta con una protección completa de la batería y sus salidas de potencia (sobre corriente, sobrecarga, sobre descarga y corto circuito), lo que garantiza una administración de energía confiable para la aplicación propuesta.

Según el fabricante DFRobot, "Los usuarios pueden conectar cualquier tipo de panel solar (monocristal, policristal, película delgada) siempre que el voltaje del circuito abierto esté dentro de los 7 V y 30 V.

Teniendo en cuenta el tamaño, peso, precio del panel y la corriente de carga máxima de 2A del módulo, se recomienda conectar un panel solar de no más de 20 W al terminal SOLAR IN". Tomando en cuenta que las condiciones climáticas durante el invierno, en Playa Sámara, se caracterizan por largos periodos de nubosidad y considerando que los sitios donde se deben colocar los paneles poseen gran cantidad de vegetación que implica la ausencia de luz solar directa, se seleccionó el panel solar policristalino RICH SOLAR 20 watts, con la mayor capacidad de potencia soportada por el dispositivo. De acuerdo con el fabricante RICH SOLAR, el panel solar de 20 W y 12 V posee clasificación IP65, es construido con vidrio templado resistente y marco de aluminio certificado para soportar condiciones ambientales agresivas. (ver figura 6.2).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.2: Panel solar policristalino RICH SOLAR 20 watts. Fuente: RICH SOLAR.

</div>

## 6.4. Dimensionamiento de baterias

Las baterías son parte esencial de la alimentación de potencia para los dispositivos mediante energía solar. Se diseñaron tres baterías con capacidades distintas para cumplir con los requerimientos energéticos para cada punto de monitoreo en el sistema durante 20 horas de funcionamiento continuo. Se calculó la capacidad requerida de cada batería a partir de la potencia de alimentación máxima para cada elemento. Producto de la corriente máxima de funcionamiento de cada dispositivo y su tensión de alimentación en corriente directa. El resumen y resultado de los cálculos realizados para el dimensionamiento de cada batería se muestran en la tabla 6.2.

Fue necesario manufacturar cada una de las baterías diseñadas y verificar su funcionamiento. El pro-

cedimiento de manufactura fue efectuado en el Laboratorio Delta de la Escuela de Electromecánica. Este proceso se detalla en la sección 10.4, en los anexos de este documento.

<div align="center">

Tabla 6.2: Cálculo de la capacidad en baterías y cantidad de celdas requeridas por localización.

</div>

<table border="1"><tr><td>Ubicación</td><td>Dispositivo</td><td>Consumo máx. (mA)</td><td>Voltaje de alimentación (V)</td><td>Potencia(W)</td></tr><tr><td rowspan="9">Pozos</td><td>Módulo de señales Octave</td><td>30</td><td>12</td><td>0,36</td></tr><tr><td>Módulo de señales Octave</td><td>30</td><td>12</td><td>0,36</td></tr><tr><td>SSR</td><td>15</td><td>12</td><td>0,18</td></tr><tr><td>SSR</td><td>15</td><td>12</td><td>0,18</td></tr><tr><td>Heltec LoRa V2</td><td>135</td><td>5</td><td>0,68</td></tr><tr><td colspan="2">Duración de la batería(horas)</td><td>20</td><td></td></tr><tr><td colspan="2">Capacidad requerida de la batería(mAh)</td><td>9750</td><td></td></tr><tr><td colspan="2">Cantidad de celdas18650(3450mAhc/u)</td><td>28</td><td>→3celdas</td></tr><tr><td rowspan="9">Tanque</td><td>Módulo de señales Octave</td><td>30</td><td>12</td><td>0,36</td></tr><tr><td>Huawei Router4G B311</td><td>100</td><td>12</td><td>1,25</td></tr><tr><td>Sensor de nivel líquido</td><td>20</td><td>5</td><td>0,10</td></tr><tr><td>Sensor de nivel líquido</td><td>20</td><td>5</td><td>0,10</td></tr><tr><td>Heltec LoRa V2</td><td>135</td><td>5</td><td>0,68</td></tr><tr><td colspan="2">Duración de la batería(horas)</td><td>20</td><td></td></tr><tr><td colspan="2">Capacidad requerida de la batería(mAh)</td><td>13806</td><td></td></tr><tr><td colspan="2">Cantidad de celdas18650(3450mAhc/u)</td><td>39</td><td>→4celdas</td></tr><tr><td rowspan="5">Demanda</td><td>Módulo de señales Octave</td><td>30</td><td>12</td><td>0,36</td></tr><tr><td>Heltec LoRa V2</td><td>135</td><td>5</td><td>0,68</td></tr><tr><td colspan="2">Duración de la batería(horas)</td><td>20</td><td></td></tr><tr><td colspan="2">Capacidad requerida de la batería(mAh)</td><td>5750</td><td></td></tr><tr><td colspan="2">Cantidad de celdas18650(3450mAhc/u)</td><td>17</td><td>→2celdas</td></tr></table>

Fuente: Elaboración Propia.

## 6.5. Diseño del circuito electrónico

## 6.5.1. Diseño de esquemático

La primera etapa en el diseño del circuito electrónico fue la creación del circuito esquemático en el software EAGLE. El archivo esquemático creado en EAGLE puede ser consultado en la sección 10.1 en anexos o en la dirección del archivo en línea ASADASIoTV1.sch.

Dado que toda la alimentación de los dispositivos se daba mediante el controlador de carga solar, fue necesario agregar terminales para la conexión del circuito desarrollado y dicho controlador. Se colocó un condensador electrolítico a la entrada de cada una de las terminales, con el objetivo de mantener un voltaje de alimentación estable. (Ver figura 6.3).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.3: Conexión para alimentación de potencia a partir del circuito de gestión de carga solar DFRobot. Elaboración propia. EAGLE Autodesk.

</div>

Se definió la conexión del SoC Heltec LoRa 32 V2, con los demás componentes y su alimentación de potencia, se daría mediante dos filas de 18 pines hembra. Tomando en cuenta un fácil montaje, sustitucion y mantenimiento para la conexión. En la figura 6.4 se muestra las conexiones en el circuito con cada uno de los pines del SoC Heltec LoRa 32 V2.

Se destinaron dos pines de sensor táctil capacitivo (TOUCH Pins) para la entrada de señales digitales. Cada uno de los pines se conectó con el circuito "pull up" mostrado en la figura 6.5. De esta forma el dispositivo es capaz de conectarse a dos módulos de comunicación por pulsos SSR desde las terminales mostradas. Se seleccionó una resistencia de 100 k $ \Omega $ con el objetivo de evitar que una corriente excesiva fluya a través del circuito asociada a un nivel lógico bajo o alto de la señal digital de entrada al Heltec LoRA V2.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.4: Conexión de los pines del Heltec LoRa 32 V2 a la PCB. Elaboración propia. EAGLE Autodesk.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.5: Entrada circuito "pull up" para conexión con módulo de comunicación por pulsos SSR. Elaboración propia. EAGLE Autodesk.

</div>

Se proporcionó al Heltec LoRa V2 la capacidad para enviar una señal a actuadores que funcionen con una tensión mayor a la salida digital en sus pines de propósito general (GPIO) de tres volts en corriente directa (DC). Se diseño un circuito para la activación desacoplada de actuadores mediante un Optotransistor (Optocoupler) y un transistor BJT. Este circuito fue diseñado para activar un relé de estado sólido con una tensión de 12 volts en DC (proveniente del controlador de carga solar). El circuito tiene la capacidad de manejar tensiones de activación de hasta 40 volts en DC. Por otra parte, dado que es una aplicación para el envío de señales y no alimentación de potencia, este circuito fue diseñado para manejar corrientes de activación menores a los 500 mA. Corrientes mayores dañarían el transistor 2N2222.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.6: Circuito para activación desacoplada de relés de estado sólido. Elaboración propia. EAGLE Autodesk.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.7: Divisor de voltaje para entrada de señales de sensores de líquido.

Elaboración propia. EAGLE Autodesk.

</div>

Ninguno de los pines GPIO del Heltec LoRa V2 puede someterse a una tensión mayor a 3,3 V en corriente directa. Fue necesario conectar un divisor de voltaje para permitir la recepcion de las señales enviadas por los sensores de nivel de líquido. El voltaje se reduce a la mitad con el divisor mostrado en la figura 6.7. Esto para que la señal de 5 V entregada por los sensores pueda recibirse a 2,5 V por el pin digital del Heltec LoRa V2. De igual forma, se colocó un divisor de voltaje para las entradas analógicas seleccionadas como los pines ADC 38 y 39, como se muestra en la figura 6.8. Uno de estos pines será destinado para medir continuamente el voltaje en las terminales de la batería de alimentación.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.8: Divisor de voltaje para entrada analógicas previstas. Elaboración propia. EAGLE Autodesk.

</div>

Se colocaron dos buses de cinco volts y 12 volts para la alimentación de potencia de los sensores de nivel de líquido y los módulos de comunicación, respectivamente. (Ver figura 6.9). Se consideró innecesario agregar protecciones de sobre corriente, corto circuito y sobre voltaje en la alimentación de estos dispositivos, ya que el circuito controlador de carga solar posee todas estas protecciones para alimentación de potencia de todos los dispositivos.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.9: Alimentación de sensores de líquido y módulos de comunicación por pulsos SRR Octave. Elaboración propia. EAGLE Autodesk.

</div>

Finalmente, se agregaron cuatro agujeros de montaje conectados a tierra para ensamblar la placa de circuito impreso, diseñada con la placa del circuito controlador de carga solar.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.10: Agujeros de montaje conectados a tierra. Elaboración propia. EAGLE Autodesk.

</div>

## 6.5.2. Pruebas de funcionamiento en prototipo

Al finalizar el diseño del circuito electrónico se efectuaron pruebas de funcionamiento en el laboratorio para validar la funcionalidad del esquemático descrito anteriormente. Las distintas partes del esquemático se conectaron e una placa de pruebas (protoboard).

En la figura 6.11 se muestra el prototipo para la validación del funcionamiento del esquemático diseñado. El circuito fue alimentado exitosamente por el controlador de carga solar. Además, el circuito fue capaz de activar un relé de estado sólido con una tensión de 12 volts y recibir señales digitales de cinco volts usando el Heltec LoRa V2. Validando la funcionalidad del esquemático diseñado.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.11: Prototipo de circuito para activación desacoplada de relés de estado sólido con 12 V. Fuente: Elaboración propia.

</div>

Por otra parte, en la figura 6.12 se muestra el prototipo de prueba para la validación del funcionamiento del circuito "pull up". Este circuito fue conectado a la alimentación y salida de señales del módulo de comunicación por pulsos SSR del medidor Octave de 50 mm. El comportamiento individual del circuito fue el esperado, validando la funcionalidad del mismo.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.12: Prototipo de circuito "pull up" para conexión con módulo de comunicación por pulsos SSR Fuente: Elaboración propia.

</div>

## 6.5.3. Diseño del boardfile

Una vez validated el funcionamiento del esquematico se procedió con el diseño de la placa de circuito impreso (PCB). El diseño de la PCB fue realizado utilizando el programa EAGLE de Autodesk. En este software se creó el archivo de la PCB (boardfile) requerido para su manufactura.

En la figura 6.13 se muestra el boardfile creado específicamente para el proyecto. En este archivo se especifican la disposición de los componentes electrónicos, las capas, vías, trazas y agujeros necesarios para la manufactura de la PCB. Las trazas para las señales fueron elaboradas con un ancho de 0,254 mm y las trazas para alimentación de potencia se especificaron con un ancho de 0,6096 mm. El arreglo de trazas para el circuito fue elaborado utilizando la herramienta de "autorouter" del software EAGLE.

El boardfile mencionado puede ser consultado por el lector en el siguiente enlace: ASADASIoTV1.brd.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.13: Archivo de PCB diseñado en EAGLE Fuente: Elaboración propia. EAGLE Autodesk.

</div>

## 6.5.4. Fabricación de placa de circuito impreso.

La manufactura de las PCBs y parte del ensamblaje se encargó a la empresa JLCPCB (al dar click en el enlace los llevará a la página oficial de manufactura). JLCPCB posee toda la documentación necesaria para encargar la manufactura de las PCBs, únicamente se necesita generar un conjunto de archivos Gerber de la PCB diseñada en Autodesk EAGLE, siguiendo los pasos detallados aquí. Además, se encargó en ensamble de elementos superficiales a JLCPCB. Para esto fue necesario generar una lista de materiales (BOM, Bill Of Materials) y una lista de posición de los componentes (CPL, Component Placement List) siguiendo el proceso mostrado aquí, al utilizar el software EAGLE de Autodesk. Es importante mencionar que todos los componentes que se soliciten para ensamble en el BOM y CPL a JLCPCB deben existir en la Librería de partes de JLCPCB. Una vez que se contó con todos los archivos necesarios, se ordenó y canceló la manufactura en la plataforma de JLCPCB para pedidos.

Se recibieron las PCB ASADA IoT V1.0 parcialmente ensambladas, como se muestra en las figuras 6.14 y 6.15. Posteriormente se procedió a ensamblar y soldar con estaño los componentes electrónicos restantes, en cada uno de los pads de la parte inferior de la placa (bottom).


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.14: Parte superior PCB recibida de JLCPBC (Top). Fuente: Elaboración propia.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.15: Parte inferior PCB recibida de JLCPBC (bottom).

Fuente: Elaboración propia.

</div>

Finalmente, se fabricaron tres dispositivos IoT ASADAS V1.0 como el mostrado en la figura 6.16. El cual es alimentado por el controlador de carga solar y ensamblado en la parte superior del mismo. El funcionamiento del dispositivo final fue validated exitosamente mediante las mismas pruebas de funcionamiento descritas anteriormente. En la figura 6.17 se muestra el funcionamiento y comunicación simultánea entre los tres dispositivos, mediante LoRa $ ^{TM} $ , para el control de actuadores y envió de datos a la plataforma en línea Adafruit IO. En la tabla 10.1 se detalla la lista de materiales soldados a la placa y el costo total en materiales para los dispositivos.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.16: Dispositivo IoT ASADAS V1.0 completo.

Fuente: Elaboración propia.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.17: Funcionamiento simultáneo de tres IoT ASADAS V1.0.

Fuente: Elaboración propia.

</div>

## 6.6. Instalacion en sitio de los dispositivos electrónicos.

Fue necesario incorporar distintos elementos de protección y soporte físico a los IoT ASADAS V1.0 construidos. Con el propósito de garantizar una operación segura y duradera del sistema ante las condiciones climatológicas presentes en el acueducto de Playa Sámara de Nicoya. La representación gráfica de las instalaciones realizadas se detalla en la sección 10.3 de anexos.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.18: Gabinete IP65, panel solar y antena Yagi instalada en el tanque principal Fuente: Elaboración propia.

</div>

Se seleccionó un gabinete plástico con un grado de protección IP65 para contener los IoT ASADAS V1.0, los controladores de carga solar, las baterías y las conexiones por cable en cada uno de los tres puntos de monitoreo. Los gabinetes fueron seleccionados e instalados, a 3,5 metros sobre el nivel suelo, para proteger los dispositivos electrónicos del polvo, la lluvia y la vida salvaje a la que se verán sometidos en campo.

El polvo natural puede provocar fallas intermitentes o permanentes de los conjuntos de PCB bajo condiciones de temperatura entre 20 a 60 grados Celsius y humedades relativas entre 50% a 95% [39]. Dado que la humedad relativa en Playa Sámara típicamente es del 75%, se colocó un deshumidificador dentro de cada uno de los tres gabinetes para mantener una humedad relativa menor al 50%, garantizando un nivel de humedad óptimo para la operación de los dispositivos electrónicos dentro del gabinete.

Una limitante del diseño planteado es la ausencia de un mecanismo para el control de la temperatura

dentro del gabinete. Se descartó la posibilidad de la renovación del aire dentro del gabinete, considerando el alto contenido de sales (salinidad) y humedad relativa en el aire de Sámara, lo cual representarían una rápida degradación de los circuitos electrónicos. Por otra parte, se descartó un mecanismo de refrigeración activa para los gabinetes, considerando la necesidad de incorporación de una fuente de energía mayor, junto con el aumento en el costo de implementación que esto representaría.

Se procuró dejar espacio suficiente dentro del gabinete para que el aire dentro del mismo circule con libertad. Los componentes fueron separados de las paredes del gabinete plástico con el objetivo de disminuir la transferencia de calor por conducción desde el exterior. Además, el gabinete se colocó por debajo del panel solar, con el propósito de disminuir la incidencia directa de los rayos del sol durante el medio día.

Por otra parte, el controlador de carga solar está equipado con protecciones contra sobrecalentamiento, la cual limita automáticamente la corriente de carga para proteger chip de gestión de potencia IC LTC3652 y sobre corriente de las baterías, en caso de que las mismas sufran un sobre calentamiento. También, para mejorar el enfriamiento y maximizar la corriente de carga, se colocó una aleta de enfriamiento de aluminio en la parte inferior del módulo de carga solar.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 6.19: Contenido del gabinete IP65 instalado en el tanque principal.

Fuente: Elaboración propia.

</div>

<div align="center">

# Diseño propuesto para circuito de control electrico en bombeo

</div>

En este capítulo se propone un diseño de la lógica de circuitería eléctrica para sistema de control y potencia en las dos moto-bombas monofásicas encargadas de extraer, de dos pozos, la totalidad de agua que ingresa al acueducto. Si bien el software controlador posee la capacidad de comandar la operación del sistema de bombeo, respecto a variaciones medidas en la demanda del acueducto y el nivel actual en el tanque principal, es necesario adaptar control eléctrico y la alimentación de potencia a las moto-bombas sumergibles monofásicas para que funcionen en conjunto con sistema de IoT.

El actual sistema de alimentación eléctrica y sistema de control eléctrico para el bombeo principal de la Asada de Playa Sámara, posee importantes carencias en temas de seguridad eléctrica que incumplen aspectos presentes en el código eléctrico nacional. Como se ilustra en figura 7.1, el cableado eléctrico requiere de canalizaciones adecuadas, la estructura metálica de los gabinetes de control se encuentra corroída y la ventilación forzada de los mismos no es la recomendada. De esta forma se recomendó a la administración y la junta directiva de la Asada proceder con la renovación del sistema de control eléctrico con la mayor prontitud.

El alcance de este proyecto no contempló el diseño completo del gabinete de control eléctrico, únicamente se diseñó la lógica alambrada necesaria para la operación del mismo, en conjunto con el sistema de control y monitoreo desarrollado. De esta forma, aspectos como la selección del gabinete y la ventilación requerida para el mismo no fueron abordados en este trabajo. Además, por temas de disponibilidad financiera y alcance de este proyecto no se ejecutó el diseño de control eléctrico presentado.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 7.1: Instalaciones electricas actuales para bombeo del acueducto de Playa Sámara. Fuente: Elaboración Propia.

</div>

## 7.1. Consideraciones para el diseño de control eléctrico

Para el diseño del sistema de control eléctrico que mejor se adecue a las necesidades de automatización se tomaron en cuenta las siguientes consideraciones:

Se requiere que la operación del sistema de bombeo pueda efectuarse en el sitio de forma manual y de forma automática, mediante el sistema de monitoreo y control desarrollado. Por esta razón, se decide incorporar un selector de tres posiciones para que el encargado del sistema de control eléctrico pueda seleccionar el modo de operación del sistema que mejor se adapte a las necesidades específicas en determinado momento. Adicionalmente, este selector funciona como un paro de emergencia para el funcionamiento de las bombas. Ver figura 7.6.

En el modo automático el sistema de bombeo opera de acuerdo con las señales que envía el SoC Heltec Lora V2 hacia los relés de estado sólido (SSR) que energizan o desenergizan la bobina de los contactores. Por otra parte, mediante contactos auxiliares, conectados al ASADAS IoT V1.0 y con el firmware de comunicación pump.ino se monitoriza en todo momento el estado de los contactores para reportarlos al controlador principal tank.ino y a la plataforma en línea. Las conexiones entre el dispositivo electrónico de control y el tablero de control, se detallan en la figura 7.5.

Para el modo manual se decide utilizar un control de encendido con dos hilos (con un selector OFF-ON) para prevenir un paro definitivo en el sistema de bombeo cuando suceda una interrupción en el servicio eléctrico y el sistema opere en modo manual que apague las bombas. Con un selector el bombeo arrancará de nuevo por si solo cuando se restablezca el servicio sin necesidad de que alguien presione un botón, como en el caso de encendido con tres hilos.

Puede ocurrir que el nivel del pozo bajo porque la bomba extrae más agua de la que el acuífero puede reponer. Es fundamental agregar un mecanismo de protección para las bombas ante un bajo nivel de agua en los pozos que provoque que la bomba trabaje "en seco" y succione aire. Para evitar esto, se propone un relé de control de nivel con un retardo a la conexión para cada pozo. Se propone usar dos relés de control de nivel RM22LA32MR en la función de un nivel con retardo a la conexión (On-Delay). Ver figura 7.2.

El retardo a la conexión evita que existan arranques múltiples con intervalos de tiempo muy cortos, los cuales pueden ocasionar un sobrecalentamiento en el motor o un daño irreparable en el mismo. Arranques muy seguidos pueden ocurrir cuando el nivel del pozo bajo y el relé de control de nivel abre el contacto apagando el motor. Sin embargo, justo en el momento en que el motor se apaga, el pozo se empieza a llenar de nuevo, y en cuestión de segundos el relé de nivel vuelve a cerrar el contacto y permite el arranque del motor. Considerando que el motor se activaría inmediatamente, en modo manual o en modo automático (con IoT), y el ciclo se repite, arrancando y parando el motor en intervalos muy cortos. Esto puede acabar con el motor en cuestión de minutos.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 7.2: Modo de operación y conexión de sensores de nivel en pozos para relé de control de nivel propuesto.

Fuente: Hoja de instrucciones RM22LA32MR.

</div>

Finalmente, es necesario brindar la suficiente información al colaborador que atienda averías en del acueducto, para que pueda interpretar que sucede con el sistema de control y atacar el problema. Para esto se agregan luces piloto al panel de control para indicarle al colaborador el tipo de fallo que ocurre. Sea una sobrecarga en los motores de las bombas o el nivel del pozo es muy bajo para la operación segura de la bomba, junto con la información del estado operativo de las bombas. Ver figura 7.6.

En resumen, las entradas y salidas del sistema de control son las siguientes:


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 7.3: Diagrama de entradas y salidas para el control eléctrico del bombeo Fuente: Elaboración Propia. Visio.

</div>

## 7.2. Diagramas de control electrico

## 7.2.1. Diseño de lógica alambrada para control eléctrico


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 7.4: Diagrama de control electrico propuesto para el bombeo del acueducto de Playa Sámara. Fuente: Elaboración Propia. AutoCAD 2020.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 7.5: Diagrama de conexiones con el controlador en PCB. Fuente: Elaboración Propia. AutoCAD 2020.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 7.6: Disposición de selectores y señalización en panel de control.

Fuente: Elaboración Propia. AutoCAD 2020.

</div>

## 7.2.2. Diseño de control electrico de potencia

Por otra parte, se presenta un diseño para la alimentación eléctrica de potencia para los motores sumergibles de 15 HP y 10 HP. Las características eléctricas de los motores se muestran en la tabla 7.1.

<div align="center">

Tabla 7.1: Características eléctricas de moto-bombas sumergibles.

</div>

<table border="1"><tr><td>Descripción</td><td>Potencia[kW]</td><td>Corriente plena carga[A]</td><td>Corriente Máx[A]</td><td>Tensión monofásica[V]</td><td>Frec. [Hz]</td><td>Factor de servicio</td></tr><tr><td>Motobomba sumergible15HP-Franklin Electric</td><td>11</td><td>62</td><td>75</td><td>240</td><td>60</td><td>115</td></tr><tr><td>Motobomba sumergible10HP-Franklin Electric</td><td>75</td><td>44</td><td>51</td><td>240</td><td>60</td><td>115</td></tr></table>

<div align="center">

Fuente: Moto-bombas sumergibles Franklin Electric

</div>

El cálculo de corriente de selección para la alimentación de los motores se muestra en la tabla 7.2 utilizando un factor por servicio continuo del 125 % (Art. 430.23(A) [40]) para ambos motores y los factores de corrección por temperatura (Tabla 310.15(B)(2)(a) del NEC [40]) mostrados para una temperatura ambiente de Sámara de 34 $ ^{\circ} \mathrm{C}. $

<div align="center">

Tabla 7.2: Corrientes para selección de conductores.

</div>

<table border="1"><tr><td>Descripción</td><td>Corriente de plena(A)</td><td>F. Temp</td><td>F. CargaCont.</td><td>Conductores/ fase</td><td>Corriente selec. conductores(A)</td></tr><tr><td>Motobomba15HP</td><td>62</td><td>0,82</td><td>1,25</td><td>1</td><td>94,5</td></tr><tr><td>Motobomba10HP</td><td>44</td><td>0,82</td><td>1,25</td><td>1</td><td>67,1</td></tr><tr><td>Alimentador principal</td><td></td><td>0,88</td><td></td><td>1</td><td>138,1</td></tr></table>

<div align="center">

Fuente: Elaboración propia.

</div>

El cálculo para la corriente de selección para los conductores del alimentador principal se hizo de acuerdo con el Artículo 430.24 del NEC [40]. De la siguiente forma:

$$
I _ {a l i m e n t a d o r} [ A ] = \left(\frac {1 2 5 \% \times C o r r i e n t e p l e n a carga Motor 1 5 H P + C o r r i e n t e p l e n a carga Motor 1 0 H P}{f a c t o r d e c o rrección p o r t e m p e r a t u r a}\right)
$$

Se seleccionaron los calibres de cobre de la tabla 310.15(B)(16) [40] y los disyuntores, a partir de la tabla 430.52 y el artículo 240.6 del NEC, para la alimentación de los ramales mostrados en la tabla 7.3. Además, se calcularon las corrientes de sobrecarga como el 125 % de la corriente de plena carga (nominal) del motor, según el Art. 430.32 (1) [40].

Finalmente, en la figura 7.7 se representa gráficamente el diseño para la alimentación de potencia. En este diagrama se muestra la selección de contactores disponibles en el mercado costarricense y se propone el uso de bloques de distribución con una capacidad de 335 A, para alimentar de forma segura cada moto-bomba.

<div align="center">

Tabla 7.3: Selección de calibres de conductores de alimentación, disyuntores y cálculo de corrientes de sobrecarga.

</div>

<table border="1"><tr><td>Descripción</td><td>Calibre ramal AWG(Cu)</td><td>Ø[mm]SCH40</td><td>Corriente disyuntor[A]</td><td>Selección de Disyuntor[A]</td><td>Corriente sobrecarga[A]</td></tr><tr><td>Motobomba15HP</td><td>2THHN</td><td>38</td><td>155</td><td>150</td><td>77,5</td></tr><tr><td>Motobomba10HP</td><td>4THHN</td><td>38</td><td>110</td><td>100</td><td>55</td></tr><tr><td>Alimentador principal</td><td>1/0THHN</td><td>50</td><td>194</td><td>175</td><td></td></tr></table>

<div align="center">

Fuente: Elaboración propia.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 7.7: Diagrama de alimentación eléctrica de potencia para el sistema de bombeo del acueducto de Playa Sámara.

Fuente: Elaboración Propia. AutoCAD 2020.

</div>

<div align="center">

# Capítulo 8

</div>

## Análisis Financiero

En este capítulo se analiza la rentabilidad proyectada para la implementación y operación del sistema de IoT para la ASADA de Playa Sámara. Se compararán las pérdidas de hídricas totales del acueducto y las facturaciones energéticas asociadas con el consumo energético de bombeo, del año 2020, con una proyección de ahorros financieros ligados a la nueva operación automática del acueducto. Dicha proyección igualmente es basada en datos de financieros del año 2020.

## 8.1. Consideraciones para el análisis financiero

Como punto de partida para el análisis financiero se tomaron los intervalos diarios de operación típicos para cada una de las bombas, de forma individual, durante un mes de operación (ver tabla 8.1). Si bien los tiempos de operación para las bombas varian a lo largo del año (dependiendo la temporada de llegada de turistas) y son programados manualmente en respuesta a demandas mensuales esperadas. Se considerará para efectos de este análisis, a modo de aproximación, que la taza de cambios en los tiempos de operación diaria a lo largo del año es constante.

Al partir de dicho supuesto, se espera que la tasa de cambio en la facturación sea directamente proporcional para los demás meses del año. De esa forma, se asume también que un porcentaje de ahorro en la facturación energética proyectado, con base al escenario típico de operación, será el mismo para la facturación de los demás meses del año. Para el cálculo de la facturación energética típica se utilizó la Tarifa T-CS, Preferencial de carácter social vigente a la fecha, a la que pertenece la ASADA de Playa Sámara.

Se contempla igualmente una disminución en la cantidad de agua que es extraída de los pozos de la ASADA de Playa Sámara, ligada a una operación reducida del sistema de bombeo. Tomando en cuenta que la bomba de 15 HP y la bomba de 10 HP típicamente bombean agua a una razón de 12,5 L/s y 7,5 L/s, respectivamente, al trabajar individualmente. Con estos caudales típicos y las horas de operación típicas se calcula un volumen típico total bombeado al tanque principal al día. Este volumen base se compara con los volúmenes de agua totales bombeados para cada uno de los escenarios futuros de operación planteados.

<div align="center">

Tabla 8.1: Facturación energética típica, asociada al bombeo del acueducto, para el año 2020

</div>

<table border="1"><tr><td>Motobomba sumergible</td><td>Pozo 1</td><td>Pozo 2</td></tr><tr><td>Potencia en HP</td><td>15</td><td>10</td></tr><tr><td>Potencia en kW</td><td>11</td><td>7,5</td></tr><tr><td>Horas de operación diarias típicas</td><td>12</td><td>16</td></tr><tr><td>Volumen típico total entregado al día(m3)</td><td colspan="2">270</td></tr><tr><td>Consumo energético diario(kWh)</td><td>132</td><td>120</td></tr><tr><td>Consumo energético mensual(kWh)</td><td>3960</td><td>3600</td></tr><tr><td>Consumo total energético mensual(kWh)</td><td colspan="2">7560</td></tr><tr><td>Facturación por primeros 3000 kWh</td><td>271</td><td>950,00€</td></tr><tr><td>Facturación por más de 3000 kWh</td><td>247</td><td>380,00€</td></tr><tr><td>Cargo por potencia</td><td>76</td><td>211,77€</td></tr><tr><td>Facturación energética típica</td><td colspan="2">595 541,77€</td></tr></table>

Fuente: Elaboración Propia.

A partir de esta comparación, se obtiene un porcentaje de reducción en el volumen diario bombeado. El cual, se utilizará más adelante para estimar ahorros financieros asociados a pérdidas hídricas.

A partir del escenario típico base se plantean los dos escenarios a futuro, mencionados. Un escenario con proyecciones de ahora optimista y un escenario de ahora pesimista, ambos considerando una disminución en pérdidas de agua y una reducción del consumo energético asociado a una menor cantidad de horas de operación de las bombas al día. Para la estimación de ahora en ambos escenarios, se proponen nuevos intervalos de operación, tomando en cuenta la lógica de decisiones que fue programada en el dispositivo controlador. Se espera que el sistema le dé prioridad de operación a la bomba de 15Hp, mientras que la bomba de 10Hp operará únicamente en periodos en que la demanda supere la producción. Como se muestra en las tablas 8.2 y 8.3.

<div align="center">

Tabla 8.2: Cálculo de ahorros financieros ligados a la operación de bombeo en escenario optimista.

</div>

<table border="1"><tr><td>Motobomba sumergible</td><td>Pozo 1</td><td>Pozo 2</td></tr><tr><td>Potencia en HP</td><td>15</td><td>10</td></tr><tr><td>Potencia en kW</td><td>11</td><td>7,5</td></tr><tr><td>Horas de operación diarias esperadas</td><td>16</td><td>4</td></tr><tr><td>Volumen optimista total entregado al día(m3)</td><td colspan="2">230</td></tr><tr><td>Porcentaje de reducción en el volumen diario bombeado</td><td colspan="2">14.8%</td></tr><tr><td>Consumo energético diario(kWh)</td><td>176</td><td>30</td></tr><tr><td>Consumo energético mensual(kWh)</td><td>5280</td><td>900</td></tr><tr><td>Consumo total energético mensual(kWh)</td><td colspan="2">6180</td></tr><tr><td>Facturación por primeros 3000 kWh</td><td>271</td><td>950,00€</td></tr><tr><td>Facturación por más de 3000 kWh</td><td>172</td><td>515,00€</td></tr><tr><td>Cargo por potencia</td><td>76</td><td>211,77€</td></tr><tr><td>Facturación energética optimista</td><td>520</td><td>676,77€</td></tr><tr><td>% Ahorro energético mensual optimista</td><td colspan="2">12.6%</td></tr></table>

<div align="center">

Fuente: Elaboración Propia.

</div>

<div align="center">

Tabla 8.3: Cálculo de ahorros financieros ligados a la operación de bombeo en escenario pesimista.

</div>

<table border="1"><tr><td>Motobomba sumergible</td><td>Pozo 1</td><td>Pozo 2</td></tr><tr><td>Potencia en HP</td><td>15</td><td>10</td></tr><tr><td>Potencia en kW</td><td>11</td><td>7,5</td></tr><tr><td>Horas de operación diarias esperadas</td><td>16</td><td>7</td></tr><tr><td>Volumen pesimista total entregado al día(m3)</td><td colspan="2">252,5</td></tr><tr><td>Porcentaje de reducción en el volumen diario bombeado</td><td colspan="2">6,5%</td></tr><tr><td>Consumo energético diario(kWh)</td><td>176</td><td>52,5</td></tr><tr><td>Consumo energético mensual(kWh)</td><td>5280</td><td>1575</td></tr><tr><td>Consumo total energético mensual(kWh)</td><td colspan="2">6855</td></tr><tr><td>Facturación por primeros 3000 kWh</td><td>271</td><td>950,00€</td></tr><tr><td>Facturación por más de 3000 kWh</td><td>209</td><td>133,75€</td></tr><tr><td>Cargo por potencia</td><td>76</td><td>211,77€</td></tr><tr><td>Facturación energética pesimista</td><td>557</td><td>295,52€</td></tr><tr><td>% Ahorro en facturación energética mensual pesimista</td><td colspan="2">6,4%</td></tr></table>

Fuente: Elaboración Propia.

## 8.2. Rentabilidad en escenarios planteados

Utilizando el porcentaje de ahorros en la facturación energética y el porcentaje de disminución de agua bombeada, para los escenarios propuestos, se analiza la rentabilidad financiera de la implementación del sistema de monitoreo y control en el acueducto principal de la ASADA.

Partiendo del costo energético total, asociado al bombeo del año 2020, se proyectan los ahorros en facturación energética anual en un escenario pesimista y optimista. Adicionalmente, a partir del volumen de agua extraído y no facturado por la ASADA durante el mismo año (correspondiente al 43 % del volumen hídrico total extraído) junto con el porcentaje de reducción de pérdidas hídricas proyectada se calcula un ahorro financiero anual por pérdidas hídricas. Este ahorro financiero corresponde al agua perteneciente a pérdidas anuales totales que gracias a la nueva operación optimizada no será bombeada hacia el acueducto. El valor monetario de este porcentaje se calcula a partir de la facturación no percibida por pérdidas hídrica en el 2020.

En la tabla 8.4 se muestran los ahorros financieros totales proyectados para la ASADA, los cuales corresponden a 3 745 997,96 € en el peor de los escenarios y 8 387 377,52 € para el mejor de los casos.

Considerando el costo de implementación total del proyecto (detallado en la tabla 10.2 de los anexos) y el costo anual operativo del sistema, que corresponde al pago del servicio de internet móvil y el uso de la plataforma en línea para la visualización de datos, se calcula un periodo de recuperación de la inversión de 10,3 meses para el escenario pesimista y 4,6 meses para el escenario optimista (ver tabla 8.4). De esta forma, es posible justificar la rentabilidad de la implementación del sistema planteado, fundamentando que la ASADA podrá percibir beneficios monetarios en menos de un año para el peor de los escenario proyectados. Los cuales, se dan en forma de ahorros en facturación eléctrica y reducción de agua no facturada.

<div align="center">

Tabla 8.4: Ahorros financieros totales y periodo de recuperación de la inversión calculado.

</div>

<table border="1"><tr><td>Costo energético anual por bombeo(2020)</td><td colspan="2">8412580,00€</td></tr><tr><td>Porcentaje de agua extraida no facturada(ANF)(2020)</td><td colspan="2">43,05%</td></tr><tr><td>Volumen anual de agua no facturado[m3](2020)</td><td colspan="2">109303,00</td></tr><tr><td>Facturación no percibida por pérdidas hídricas(2020)</td><td colspan="2">49459899,00€</td></tr><tr><td>Escenario proyecto</td><td>Pesimista</td><td>Optimista</td></tr><tr><td>Ahorro energético anual proyecto</td><td>6,4%</td><td>12,6%</td></tr><tr><td>Ahorro en facturación energética anual proyecto</td><td>540263,77€</td><td>1059985,08€</td></tr><tr><td>Reducción de pérdidas hídricas proyecto</td><td>6,5%</td><td>14,8%</td></tr><tr><td>Reducción en puntos porcentuales para ANF total</td><td>2,8%</td><td>6,4%</td></tr><tr><td>Ahorro financiero anual por pérdidas hídricas</td><td>3205734,19€</td><td>7327392,44€</td></tr><tr><td>Ahorros financieros totales</td><td>3745997,96€</td><td>8387377,52€</td></tr><tr><td>Inversión total en el proyecto</td><td colspan="2">3215813,23€</td></tr><tr><td>Costo anual de operación(Internet+Plataforma IoT)</td><td colspan="2">232236,00€</td></tr><tr><td>Periodo para recuperación de la inversión[meses]</td><td>10,3</td><td>4,6</td></tr></table>

## Capítulo 9

## Conclusiones

Se diseñaron y fabricaron con éxito tres dispositivos IoT ASADAS V1.0 que, al trabajar de forma simultánea, conforman un sistema de comunicación (internet de las cosas), basado en una red LoRa $ ^{TM} $ , para el acueducto de Playa Sámara. Dicho sistema posee la capacidad de intercomunicación de datos hídricos en tiempo real y la visualización de datos a la plataforma en internet de IoT Adafruit IO, relacionados con la operación del acueducto principal.

Utilizando circuito impreso creado IoT ASADAS V1.0 y los software implementados en el SoC Heltec LoRa V2 se añadió la capacidad de telecomunicación por LoRa $ ^{TM} $ a tres medidores ultrasónicos Octave con un módulo de comunicación por pulsos de relé se estado sólido (SSR), presentes en el acueducto principal de la ASADA de Sámara. El dispositivo creado permite la interpretación de mediciones de volumen y caudal hídrico promedio con un porcentaje de error de 0 % y 0,73 %, respectivamente, tomando como valor de comparación las mediciones reportadas en la pantalla de los flujómetros. Dichas mediciones fueron comunicadas con éxito hacia el controlador maestro mediante modulación LoRa $ ^{TM} $ y publicadas en la plataforma en internet Adafruit IO.

Se diseñó un circuito de control eléctrico que posibilita la operación automatizada del sistema de bombeo principal. Al vincular las señales enviadas por el dispositivo IoT ASADAS V1.0 con el mecanismo de arranque para cada bomba (bobina del contactor). Tomando como insumo de información, para la toma de decisiones del sistema, el caudal de demanda hídrica actual del acueducto, el caudal de producción hídrica extraído de los pozos y el nivel agua presente en el tanque principal.

Se concluye que la implementación del sistema de IoT es rentable en comparación con las pérdidas financieras asociadas a la operación actual del acueducto principal de la ASADA Sámara. Se analizaron escenarios financieros con estimaciones de ahorro pesimista y optimista, para los cuales se pronostican ahorros financieros anuales de 3 745 998 € y 8 387 377 €, respectivamente, y periodos de recuperación de la inversion de 10 y 5 meses, respectivamente.

## 9.1. Recomendaciones para la administración de la ASADA

## 9.1.1. Recomendaciones de mantenimiento

Dentro de los gabinetes del sistema de monitoreo y control se colocó un deshumidificador pasivo para mantener la humedad relativa dentro del gabinete en un valor menor al 50 %. Se recomienda verificar mensualmente que el agente desecante del deshumidificador pasivo no se haya acabado. En caso que se acabe, es recomendable sustituirlo de inmediato para asegurar la mayor vida útil de los dispositivos electrónicos dentro del gabinete. Se recomienda abrir los gabinetes únicamente si es estrictamente necesario, con el fin de evitar que ingrese aire con polvo y con mayor humedad (es decir, que se renueve la humedad relativa dentro del gabinete a la humedad ambiental).

El sistema de alimentación de potencia para los dispositivos requiere dos tareas de mantenimiento esenciales. En primer lugar, se recomienda una rutina de limpieza mensual para los paneles solares instalados, utilizando únicamente un trapo húmedo (sin usar jabones o productos de limpieza). En segundo lugar, se recomienda inspeccionar visualmente el estado de las baterías al menos una vez cada tres meses. El sistema de monitoreo en línea recopila datos sobre el estado de carga (tensión en las baterías) y alerta en la plataforma en internet cuando las mismas poseen un voltaje cercano a la descarga. Se recomienda gestionar la sustitucion de las baterías cuando sucedan alertas de descarga muy seguidas.

Se recomienda una inspección visual, al menos una vez al mes, del estado de las conexiones eléctricas relacionadas con el sistema de monitoreo y control, verificando que se encuentren en buen estado. Adicionalmente, se recomienda evitar el ingreso de agua a las fosas donde se encuentran instalados los flujómetros e inspeccionar constantemente el buen estado de las conexiones en dichas fosas.

## 9.1.2. Recomendaciones relacionadas con el manejo de datos

El sistema de recopilación de datos implementado en este proyecto, tiene la capacidad de reunir alrededor de 21 600 datos por cada variable de monitorizada al mes (cerca de 237 600 datos mensuales en total). Sin embargo, la plataforma en línea utilizada (Adafruit IO) únicamente almacena datos con 60 días de antigüedad. De esta forma, se remienda descargar, cada 60 días, y almacenar, en un disco duro, los datos relacionados con las variables hídricas y las variables de funcionamiento del sistema, con el objetivo de su posterior procesamiento y análisis.

Se recomienda reservar las claves y usuarios de acceso a la plataforma en internet Adafruit IO de forma confidencial. Igualmente, se recomienda que únicamente el administrador o un colaborador en específico de la ASADA, tenga acceso a la información presente en la plataforma y acceso al control manual remoto del sistema de bombeo.

## 9.1.3. Recomendaciones relacionadas a instalaciones electricas existentes

Se recomienda a la administración y la junta directiva de la Asada, proceder con la renovación del sistema de control eléctrico con la mayor brevedad posible, tomando en cuenta los aspectos de diseño presentados en el capítulo 7.

## 9.2. Posibles campos futuros de investigación

Utilizando algoritmos de inteligencia artificial para el aprendizaje de máquinas (Machine Learning) y la recopilación de datos hídricos del sistema actual, sería interesante incorporar pronósticos de demanda al sistema. Con el fin de optimizar aún más la operación del sistema de bombeo para que consuma la menor cantidad de energía al bombear una cantidad pronosticada de volumen demandado, incorporando autonomía posterior a la operación del sistema de bombeo.

Dado que el acueducto opera mediante un abastecimiento por gravedad a los abonados, sistema actual no recopila datos de presión para coordinar la operación del sistema de bombeo. Una aplicación futura podría incorporar el monitoreo de presiones en el acueducto, como información clave para ubicar fugas en tuberías principales del acueducto.

El estudio de la operación del sistema no fue abordado en este trabajo. Por lo que sería interesante estudiar si ocurre alguna disminución en el desempeño de los microcontroladores a lo largo del tiempo. Así como el estudio de la vida útil de microcontroladores en aplicaciones de este tipo, donde deben trabajar continuamente, de forma indefinida.

## Bibliografía

[1] George A. Kunkel, American Water Works Association, and AWWA (American Water Works Association). M36 Water Audits and Loss Control Programs. American Water Works Association, Denver, CO, 2016.

[2] Leonel Aleaga. Diseño de un sistema de telemetría y telecontrol (SCADA) para la red de distribución de agua potable de la ciudad de Loja. PhD thesis, 11 2010.

[3] H. Torres Ortega. Guía de diseño de PCB con EAGLE; Introducción y recomendaciones generales. hetpro, Guadalajara, Jalisco, 2014.

[4] Arad Group. Medidor de agua ultrasónico octave. Technical report, 2013.

[5] Zoran Kapelan, Weisbord Emma, and Vladan Babovic. Artificial intelligence solutions for the water sector. Digital Water - International Water Association, 2020.

[6] Darner Mora Alvarado and Carlos Portuguez Barquero. Agua para consumo humano por provincias y saneamiento por regiones manejados en forma segura en zonasurbanasy rurales de costa rica al 2018. Technical report, Laboratorio de Aguas - AyA, 2018.

[7] AyA-PNUD-CRUSA. Fortalecimiento del sistema nacional de gestión de la información del recurso hídrico(singirh) por medio de la consolidación del sistema de información de gestión de asadas(saga) y combate al agua no contabilizada en los cantones de san carlos y sarapiquí. Technical report, 2017.

[8] AyA. $5.5 millones para 395 acueductos comunales en guanacaste y zona norte. Technical report, Gobierno de la República, 2016.

[9] Héctor Paniagua Alfaro and Natalia Rodríguez Alfaro. Guía de Gestión Integral de Riesgos para ASADAS (GIRA). Programa de Naciones Unidas para el Desarrollo, Costa Rica (PNUD-Costa Rica), 2019.

[10] FAO. Perfil de país - costa rica. Technical report, AQUASTAT, Organizacion de las Naciones Unidas para la Alimentacion y la Agricultura, 2015.

[11] Seylin Elizondo, Vanessa Gómez, Sylvia Ramírez, Jennifer Ramírez, and Wander Cubero. Análisis Prospectivo del Sector de Agua Potable y Saneamiento de Costa Rica al año 2040. Facultad de Ciencias Económicas, Universiad de Costa Rica, San José, Costa Rica, 2015.

[12] K. Mora. El agua de costa rica aún tiene muchos retos y oportunidades por cumplir, 2020.

[13] AyA. Anuario estadístico 2012-2018. Technical report, Dirección de Planificación, 2019.

[14] AyA. Informe de gestión 2019. Technical report, Subgerencia de sistemas delegados, 2019.

[15] Erin Ress and J. Allan Roberson. The financial and policy implications of water loss. Journal - American Water Works Association, pages E77-E86, 2016.

[16] AyA. Contratación de consultor especializado para el proyecto ranc-ee; licitación pública internacional n. 2016li-000003-pri; secciOn 6: Términos de referencia. Technical report, 2016.

[17] Gobierno de la República de Costa Rica. Aya recibirá financiamiento del bcie y kfw para reducir el agua no contabilizada y mejorar los sistemas hídricos de costa rica, 2015.

[18] AyA. Aya establece ruta para reducir agua no contabilizada, Sep 18, 2020.

[19] Banco Interamericano de Desarrollo. De estructuras a servicios: el camino a una mejor infraestructura en américa latina y el caribe, ed. en español. 2020.

[20] Water Partnership. Digital water; capitalising on the commercial opportunities for uk plc. Technical report, 2020.

[21] IBNET. The international benchmarking network for water and sanitation utilities, 2017.

[22] AyA. Informe de la gestión realizada en la atención y el fortalecimiento de las asadas. Technical report, 2020.

[23] World Bank Group. Energy management for water utilities in latin america and the caribbean; case study series: Water utilities summary note. 2017.

[24] UNESCO & ONU-Agua. Informe mundial de las naciones unidas sobre el desarrollo de los recursos hídricos. Technical report, 2020.

[25] Roberto Hernández Sampieri, Carlos Fernández Collado, and Maria Pilar Baptista Lucio. Metodología de la investigación. McGraw-Hill, México, 6. ed. edition, 2014.

[26] 211-2018 - IEEE Standard Definitions of Terms for Radio Wave Propagation. IEEE, 2019.

[27] Angela Daboin. Medición de rssi y pruebas de cobertura para diferentes escenarios de propagación en una red inalámbrica de sensores. REDIP-Revista Digital de Investigación y Postgrado, 2, 01 2012.

[28] M. Saari, A. Muzaffar bin Baharudin, P. Sillberg, S. Hyrynsalmi, and W. Yan. Lora a survey of recent research trends. In 2018 41st International Convention on Information and Communication Technology, Electronics and Microelectronics (MIPRO), pages 0872-0877, 2018.

[29] LoRaAlliance. A technical overview of lora $ ^{\textcircled{R}} $ and lorawan $ ^{\mathrm{T M}} $ . Technical Marketing Workgroup 1.0, 2015.

[30] MQTT. Mqtt: The standard for iot messaging, 2020.

[31] Michael Yuan. Ibm; getting to know mqtt. 7 Enero 2020.

[32] L. Rosencrance y S. Shea M. Rouse, A. Gillis. Internet of things (iot). IoT Agenda, 2020.

[33] C. McClelland. What is an iot platform? iotforall, 2020.

[34] C. Holloway. Plataformas iot: Qué son y cómo elegir la mejor para el negocio,. IT Masters MAG, 2018.

[35] B. Ray. Iot platforms: What they are & how to select one. LinkLabs, 2016.

[36] ESPRESSIF SYSTEMS (SHANGHAI) CO. Socs esp 32., 2021.

[37] R. Franksson y A. Liljegren. Measuring a LoRa NetworkPerformance, Possibilities and Limitations. Karlskrona, Sweden: Blekinge Institute of Technology, 2018.

[38] Wongeun Choi, Yoon-Seop Chang, Yeonuk Jung, and Junkeun Song. Low-power lora signal-based outdoor positioning using fingerprint algorithm. ISPRS international journal of geo-information, 7(11):440, Nov 9, 2018.

[39] Bo Song, Michael Azarian, and Michael Pecht. Effect of temperature and relative humidity on the impedance degradation of dust-contaminated electronics. Journal of the Electrochemical Society, 160:C97-C105, 01 2013.

[40] National Fire Protection Association. NFPA 70 Código Eléctrico Nacional. 2014 edition, 2014.

Capítulo 10

Anexos

10. 1. Tablas detalle de inversion total en el proyecto

<div align="center">

Tabla 10.1: Costo de materiales para manufactura de controlador electrónico IoT ASADAS V1.0

</div>

<table border="1"><tr><td>Descripción</td><td>Proveedor</td><td>Cant</td><td>Precio Unid</td><td>Subtotal</td></tr><tr><td>Manufactura + ensamble parcial + envío de PCBs</td><td>JLCPCB</td><td>1</td><td>70 539,75 €</td><td>70 539,75 €</td></tr><tr><td>DG128-2 Bloque Terminal 2 Polos 5mm</td><td>MicroJPM</td><td>9</td><td>271,98 €</td><td>2 447,82 €</td></tr><tr><td>DG128-3 Bloque Terminal 3 Polos 5mm</td><td>MicroJPM</td><td>18</td><td>353,57 €</td><td>6 364,26 €</td></tr><tr><td>40 Pin 2.54mm de fila única macho</td><td>MicroJPM</td><td>1</td><td>244,96 €</td><td>244,96 €</td></tr><tr><td>40 Pin 2.54mm de fila única hembra</td><td>MicroJPM</td><td>4</td><td>381,06 €</td><td>1 524,24 €</td></tr><tr><td>6 Pin 2.54mm de fila única hembra</td><td>MicroJPM</td><td>3</td><td>179,64 €</td><td>538,92 €</td></tr><tr><td>2 Pines mini jumper para conector macho</td><td>MicroJPM</td><td>6</td><td>163,31 €</td><td>979,86 €</td></tr><tr><td>47uF @ 16V Capacitor Electrolítico</td><td>MicroJPM</td><td>9</td><td>119,67 €</td><td>1 077,03 €</td></tr><tr><td>Transistor 2N222 NPN 40V@500mA</td><td>MicroJPM</td><td>6</td><td>156,25 €</td><td>937,50 €</td></tr><tr><td>Opto-Transistor PC817</td><td>MicroJPM</td><td>6</td><td>750,00 €</td><td>4 500,00 €</td></tr><tr><td>Placa Adaptador para tarjeta Micro SD</td><td>MicroJPM</td><td>1</td><td>3 236,57 €</td><td>3 236,57 €</td></tr><tr><td>3 x Heltec LoRa 32(V2)+envío(vía FedEx)</td><td>Heltec Automation</td><td>1</td><td>91 157,00 €</td><td>91 157,00 €</td></tr><tr><td colspan="4">Total libre de impuestos</td><td>183 547,91 €</td></tr><tr><td colspan="4">IVA(13%)</td><td>23 861,23 €</td></tr><tr><td colspan="4">COSTO TOTAL</td><td>207 409,14 €</td></tr><tr><td colspan="4">COSTO MATERIALES POR DISPOSITIVO(3 x IoT ASADAS V1.0)</td><td>69 136,38 €</td></tr></table>

<div align="center">

Tabla 10.2: Costo total para implementación del sistema de IoT en Playa Sámara.

</div>

<table border="1"><tr><td>Detalle</td><td>Proveedor(es)</td><td>Cant.</td><td>Subtotal</td></tr><tr><td colspan="4">Equipo de telecomunicación</td></tr><tr><td>Antena YA5900W 890-960MHz11dB iN-Fem</td><td>Sistemas FotovoltaicosMainor Lisano</td><td>1</td><td>120 199,23€</td></tr><tr><td>Antena 433MHz-960MHz3dBi</td><td>Sistemas FotovoltaicosMainor Lisano</td><td>2</td><td>25 931,83€</td></tr><tr><td>Transporte a Playa Sámara</td><td>Sistemas FotovoltaicosMainor Lisano</td><td>1</td><td>84 750,00€</td></tr><tr><td>Antena Yagi Proxicast 11dBi</td><td>ENELCOM</td><td>1</td><td>78 695,71€</td></tr><tr><td>RP-SMA macho a N macho pigtaillmr-195/2ft</td><td>ENELCOM</td><td>1</td><td>23 870,84€</td></tr><tr><td>Conectores SMA para RG 316;RG 174;RG 58</td><td>ENELCOM</td><td>20</td><td>30 068,35€</td></tr><tr><td>Router 4G Huawei B311+planpostpago</td><td>Claro+ICE</td><td>1</td><td>65 300,00€</td></tr><tr><td colspan="4">Equipo para alimentación solar</td></tr><tr><td>RICH SOLAR-Panel solar de 20W y 12 volts</td><td>Sistemas FotovoltaicosMainor Lisano</td><td>3</td><td>206 005,28€</td></tr><tr><td>Módulo de gestión de energía-DFRobot</td><td>Sistemas FotovoltaicosMainor Lisano</td><td>3</td><td>93 818,05€</td></tr><tr><td colspan="4">Manufactura de controlador electrónico(IoT ASADAS)</td></tr><tr><td>Circuito impreso y componenteselectrónicos</td><td>Heltec Automation,jlcpcb,MicroJPM</td><td>3</td><td>207 409,14€</td></tr><tr><td colspan="4">Sensores y equipo de control</td></tr><tr><td>Sensores de nivel de líquido5V(LLE102000)</td><td>Sistemas FotovoltaicosMainor Lisano</td><td>2</td><td>107 077,96€</td></tr><tr><td>Fotek-Relé de estado sólido25ASSR-25DA</td><td>MicroJPM</td><td>2</td><td>16 875,00€</td></tr><tr><td>Módulos de comunicaciónOctavepor pulsosSSR</td><td>COPRODESA</td><td>3</td><td>183 944,79€</td></tr><tr><td colspan="4">Soportería y accesorios de montaje para equipos</td></tr><tr><td>Manufactura de postes metálicosy soporterías para páneles solares</td><td>SAMURO Soldadura</td><td>1</td><td>492 421,24€</td></tr><tr><td>Ensamble de postes metálicos congrúa</td><td>Servicio de grúa privada enSámara</td><td>1</td><td>64 000,00€</td></tr><tr><td>Gazas metálicas y tornillería</td><td>EPA,Tornillos Toyman</td><td>1</td><td>13 452,00€</td></tr><tr><td>Caja estanca c/conosIP55225x175x100mm</td><td>Distribuidora TécnicaS.A.(DITESA)</td><td>3</td><td>32 746,53€</td></tr><tr><td>Cable de controlBELDEN2Px22AWG</td><td>Distribuidora TécnicaS.A.(DITESA)</td><td>9m</td><td>12 204,50€</td></tr><tr><td>Cable de control4x22AWG</td><td>EPA</td><td>100m</td><td>32 200,00€</td></tr><tr><td>Accesorios eléctricosy gabinetes</td><td>Electro MAZ</td><td>1</td><td>165 587,78€</td></tr><tr><td>Conduit PVC y accesorios eléctricos</td><td>Enerplus&amp;FerreteríaSá-mara</td><td>1</td><td>257 400,00€</td></tr><tr><td>Materiales y m/obra para bases deconcreto</td><td>FerreteríaSámara</td><td>3</td><td>140 000,00€</td></tr><tr><td>Programación de flujómetroOctave</td><td>COPRODESA</td><td>3</td><td>150 855,00€</td></tr><tr><td>Viáticos estudiantiles</td><td></td><td></td><td>611 000,00€</td></tr><tr><td></td><td></td><td></td><td>TOTAL3 215 813,23€</td></tr></table>

## 10.2. Esquemático IoT ASADAS V1.0.


> **Figure Description:**
>
> _Descripción de figura no disponible._

10. 3. Planos constructivos y diagrams de control electrico


> **Figure Description:**
>
> _Descripción de figura no disponible._

<table><tr><td>No.</td><td>Descripción</td><td>Fecha</td></tr><tr><td colspan="3">Propietario
Asociación administradora
del acueducto rural de
Sámara</td></tr><tr><td colspan="3">Dirección
Playa Sámara de Nicoya,
Guanacaste</td></tr><tr><td colspan="3">Sistema de IoT para la
gestión del recurso
hídrico</td></tr><tr><td colspan="3">Dirección
Playa Sámara de Nicoya,
Guanacaste</td></tr><tr><td colspan="3">Detalles eléctricos
Estación de bombeo</td></tr><tr><td colspan="3">Diseñado por
Fecha
15 de mayo del 2021
Dibujado por
S. Solórzano
Aprovado por
J. J. Rojas</td></tr></table>

<table><tr><td>TEC | Tecnológico de Costa Rica</td></tr><tr><td>LABORATORIO DELTA</td></tr><tr><td>Propietario
Asociación administradora del acueducto rural de Sámara</td></tr><tr><td>No. Descripción Fecha</td></tr><tr><td>Sistema de loT para la gestión del recurso hídrico</td></tr><tr><td>Dirección
Playa Sámara de Nicoya, Guanacaste.</td></tr><tr><td>Instalaciones en tanque principal</td></tr><tr><td>Diseñado por S. Solórzano
Fecha 15 de mayo del 2021
Dibujado por S. Solórzano
Aprovado por J. J. Rojas</td></tr><tr><td>A203</td></tr><tr><td>Escala Como se indica</td></tr></table>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<table class="table table-bordered"><thead><tr><th>No.</th><th>Descripción</th><th>Fecha</th></tr></thead><tbody><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr></tbody></table>


> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

## 10.4. Procedimiento de manufactura de baterías en Laboratorio Delta


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.1: Estación de soldadura SUNKKO 709AD instalada en el Laboratorio Delta. Fuente: Elaboración Propia.

</div>

En esta sección se describe, paso por paso, el procedimiento seguido, el equipo utilizado y los materiales requeridos para manufacturar las baterías con la estación de soldadura SUNKKO 709AD. Las baterías presentadas en este documento fueron diseñadas y fabricadas para alimentar los dispositivos del sistema de IoT para ASADAS, desarrollado en este proyecto.

## Materiales y equipo utilizado

- Estación de soldadura SUNKKO 709AD.

- Pistola de calor SparkFun Heaterizer XL-3000

- Celdas 18650 SANYO.

- Fuente de calor (platilla de cocina).

- Cable color negro y rojo, calibre 22 AWG.

- Cintas de níquel, 3mm y 6mm de ancho.

- Tubo termo-retráctil de 60mm y 80mm de diámetro.

- Cinta Kapton.

- Soladura de estaño.

- Flux para estaño.

- Gafas de protección.

Como parte del proyecto, se instaló (y estrenó) una estación de soldadura SUNKKO 709AD en el Laboratorio Delta de la Escuela de Ingeniería Electromecánica. Este equipo fue adquirido por el Laboratorio Delta con fondos de la Fundación Tecnológica de Costa Rica, para ser utilizado por estudiantes de Tecnológico de Costa Rica.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.2: Primera soldadura exitosa realizada en el Laboratorio Delta. Fotografía cortesía del colega Erick Quirós.

</div>

Una vez que se selecciona la capacidad requerida para las baterías de ion-litio y se tiene a disposición los materiales descritos se procede a efectuar el procedimiento descrito a continuación.

## 10.4.1. Paso 1. Precalentar las cintas de níquel de 3mm.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.3: Precalentamiento de cintas de niquel.

Fuente: Elaboración Propia.

</div>

Observaciones: Este primer paso es opcional. Tiene como objetivo facilitar la adherencia de la soldadura de estado con la cinta de níquel. Ver figura 10.3.

## 10.4.2. Paso 2. Soldar un punto de soldadura en la cinta de níquel de 3mm precalentada y en los cables de conexión.


> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.4: Puntos de soldadura colocados en la cinta de níquel de 3 mm.

Fuente: Elaboración Propia.

</div>

Observaciones: Es recomendable colocar flux de soldadura, tanto en el cable como en la cinta de níquel, para una mejor adherencia de la soldadura de estaño. Ver figura 10.4

10. 4.3. Paso 3. Soldar las puntas de los cables de conexión en el punto de soldadura.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.5: Cintas de níquel de 3 mm soldadas al cable de conexión.

Fuente: Elaboración Propia.

</div>

Observaciones: Se recomienda cortar los cables de conexión con una longitud mayor a la requerida, para facilidad de manufactura.

## 10.4.4. Paso 4: Cortar un trozo de cinta de níquel que permita unir la cantidad de celdas seleccionada.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.6: Acomodo de cintas de níquel de 6 mm en las celdas 18650.

Fuente: Elaboración Propia.

</div>

10. 4.5. Paso 5: Programar la corriente de soldadura y la cantidad de pulsos en la estación de soldado SUNKKO 708AD.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.7: Estación de soldadura por punto armada.

Fuente: Elaboración Propia.

</div>

Observaciones: Se recomienda utilizar la mayor cantidad de pulsos posibles en el equipo (18 pulsos al activar los tres botones en la opción PULSE). Ver figura 10.7. Para programar una corriente de soldadura adecuada, se recomienda probar primero con la cinta de níquel para pruebas, dispuesta aparte.

Si tiene dudas con respecto a la programación del soldador por pulsos, consulte el manual de usuario de la estación de soldadura SUNKKO 709AD.

10. 4.6. Paso 6: Soldar las celdas a la cinta de níquel de 6mm utilizando la soldadura por pulsos.


> **Figure Description:**
>
> _Descripción de figura no disponible._

> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.8: Puntos de soldadura por pulso en la cinta de níquel de 6 mm.

Fuente: Elaboración Propia.

</div>

Observaciones: Se recomienda mantenerse presionado el pedal de accionamiento hasta concluir el punto de soldadura por pulsos. No es necesario presionar excesivamente el soldador por pulsos.

Evite soldar el recubrimiento plástico de las celdas 18650. Únicamente se deben colocar puntos de soldadura en la parte conductora metálica.

10. 4.7. Paso 7: Soldar las cintas de níquel de 3mm (que poseen el cable de conexión) a las cintas de níquel de 6mm en los polos de la batería.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.9: Cobertura de Kapton para la batería de 4 celdas.

Fuente: Elaboración Propia.

</div>

IMPORTANTE: Por seguridad es recomendable dejar un pequeño trozo de la cinta de níquel de 3 mm, separado del bus de la cinta de níquel de 6 mm. En caso de que circule una corriente mayor a 3 A la cinta de níquel de 3 mm se fundirá y abrirá el circuito, actuando como un fusible de emergencia. Adicionalmente, las baterías de ion-litio nunca deben operarse sin un circuito de control de carga y descarga.

Observaciones: Se recomienda soldar el cable de color rojo al polo positivo de la batería y cubrir inmediatamente con cinta Kapton todos los conductores positivos descubiertos. Seguidamente repetir con el cable negro en el polo negativo.

10. 4.8. Paso 8: Cubrir con termo-retráctil la batería y la junta por donde salen los cables de conexión.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.10: Colocación de tubo termo-retráctil para la batería de 4 celdas.

Fuente: Elaboración Propia.

</div>

Observaciones: Es importante colocar dos tubos termo-retráctiles en dirección horizontal y vertical a las baterías. Ver figura 10.10. Para calentar el tubo termo-retráctil se recomienda utilizar la pistola de calor SparkFun Heaterizer XL-3000 presente en el laboratorio.

## 10.4.9. Paso final: Disfrutar de sus nuevas baterias responsablemente.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.11: Baterías de 4, 3 y 2 celdas finalizadas.

Fuente: Elaboración Propia.

</div>

## 10.4.10. Pruebas de funcionamiento de las baterias

Cada una de las baterías se sometió a un proceso de carga y descarga completo, con el objetivo de verificar su funcionamiento correcto. Para realizar el proceso de carga de utilizó el controlador de carga solar DF Robot Solar Power Manager y para el proceso de descarga se conectaron las baterías a la Carga electrónica en DC RIGOL DL3021.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.12: Carga electrónica en DC RIGOL DL3021. Fuente: Elaboración Propia.

</div>

Se midió el voltaje y la corriente de carga y descarga para cada batería, utilizando un dispositivo MyDAQ y un programa para la adquisición de datos desarrollado en LabVIEW. Para las pruebas de carga y descarga se obtuvieron gráficas como la mostrada en las figuras 10.13 y 10.14.


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.13: Carga completa de batería de celdas 18650.

Fuente: Elaboración Propia. Excel.

</div>


> **Figure Description:**
>
> _Descripción de figura no disponible._

<div align="center">

Figura 10.14: Descarga completa de batería de celdas 18650.

Fuente: Elaboración Propia. Excel.

</div>

## 10.5. Códigos de firmware de operación para sistema de IoT en Sámara.

Los firmware desarrollados en este proyecto son de acceso público desde el repositorio en github del Laboratorio Delta o en el repositorio personal del autor.

Si desean observar el código de cada uno de los firmware solamente deben abrirlos desde el repositorio o en los siguientes vínculos:

10. 5.1. meter.ino

10. 5.2. pump.ino

10. 5.3. tank.ino

<div align="center">

# Capítulo 11

</div>

## Apéndices

## 11.1. Hojas de datos e informacion de equipos

Moto-bombas sumergibles Franklin Electric

Cajas de control para motores sumergibles Franklin Electric

Flujómetro Ultrasónico Arad Octave

Manual instalación Flujómetro Ultrasónico Arad Octave

Panel solar policristalino RICH SOLAR 20 Watt

Celdas Sanyo/Panasonic NCR18650GA

WiFi Móvil Huawei E5251s

Interruptores de nivel de líquido - SST

Antena Yagi PulseLarsen 890-960MHz 11dB iN-Fem Antenna

Proxicast 11 dBi Yagi Antena direccional

## 11.1.1. Componentes electrónicos utilizados

Heltec LoRa 32 V2

ESP32 Series - Espressif Systems

DF Robot Solar Power Manager

PC817 Opto Transistor

2N2222 Transistor BJT / NPN 40V - 500mA

Capacitor electrolítico 47uF - 16V

## 11.1.2. Elementos de control electrico propuestos

Bloque de distribución de potencia 335 A - Linergy

LC1D95AP7 - Contactor TeSys D - 3P(3 NO) - 95 A - Bobina 230 V AC 50/60 Hz

LC1D65AP7 - Contactor TeSys D - 3P(3 NO) - 65 A - Bobina 230 V AC 50/60 Hz

LADN22 - Bloque de contactos auxiliar TeSys D

LRD365 - Relé de sobrecarga térmica - TeSys LRD

LRD3363 - Relé de sobrecarga térmica - TeSys LRD

RM22LA32MR - Relé de control de nivel de líquido modular - Harmony

RM17UBE15 - Relé de control de tensión monofásica modular - Harmony

SSM1A16BD - Relé de estado sólido - Harmony, 6 A, zero voltage switching, input 4...32 V DC, output 24...280 V AC

RE17RMMW - Relé de retardo al arranque - Harmony
