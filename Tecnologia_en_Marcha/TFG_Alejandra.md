---
source: "C:/repos/ASADA_Paso_Ancho/TFG_Alejandra.pdf"
title: "TFG_Alejandra"
converted_at: "2026-07-07T22:46:30Z"
---

INSTITUTO TECNOLÓGICO DE COSTA RICA

ESCUELA DE INGENIERÍA ELECTROMECÁNICA


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]




> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

# “Desarrollo de un prototipo para recopilación y monitoreo remoto de datos hídricos de los tanques, basado en dispositivos IoT, en la ASADA Paso Ancho y Boquerón.”

</div>

<div align="center">

# Informe de Práctica de Especialidad para optar por el título de Ingeniero en Mantenimiento Industrial, con el grado académico de Licenciatura.

</div>

Alejandra Oviedo Muñoz

Marzo,2024


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



## Hoja de datos

Información del estudiante:

Nombre: Alejandra Oviedo Muñoz

Cedula: 208220829

Carné ITCR: 2019052248

Dirección exacta de domicilio: 200 metros al noreste de la plaza de Calle San

José, Grecia, Alajuela.

Números de teléfono: 89012022

Correos electrónicos: aleovim@gmail.com

Información del proyecto:

Título: Desarrollo de un prototipo para recopilación y monitoreo remoto de

datos hídricos de los tanques, basado en dispositivos IoT, en la ASADA Paso

Ancho y Boquerón.

Asesor industrial: Administrador Steven Rodriguez.

Profesor guía: Ing. Juan José Rojas Hernandez.

Jurado evaluador:

- Ing. Oscar Monge.

- Ing. Suzanne Melara.

Información de la empresa:

Nombre: ASADA Paso Ancho y Boquerón.

Zona: Cartago.

Dirección: Paso Ancho, Oreamuno de Cartago.

Actividad Principal: administrar los sistemas de acueducto y alcantarillado

comunales en Costa Rica.

Contacto: Administrador Steven Rodriguez.

Teléfono: 2536-6132.



19 de mayo del 2023

APB-JD 020-2023

Señor: Ing. Ignacio Del Valle Granados Coordinador de practica TEC

Asunto: Confirmación de la aceptación para la estudiante Alejandra Oviedo Muñoz, cedula número 2-0822-0829, carné de estudiante número 2019052248, para que realice su TFG en la ASADA Paso Ancho y Boquerón de Cot de Oreamuno de Cartago.

Estimado Ingeniero.

Me es grato comunicar la aceptación del TFG que realizara la estudiante Alejandra Oviedo Muñoz, cedula número 2-0822-0829, carné de estudiante número 2019052248, quien realizara su Trabajo Final de Graduación, en la ASADA Paso Ancho y Boquerón, que consiste en la gestión del "Desarrollo de un sistema de recopilación de datos y monitoreo remoto del nivel de agua del tanque principal", con dispositivos IoT.

El proyecto de cita reviste la tecnología disruptiva en aras de los avances tecnológicos de la domótica, con la automatización de procesos que realiza la ASADA de Paso Ancho y Boquerón de forma manual.

No se solicita confidencialidad.

Feliz de emitir el comunicado de cita, quedo a la orden para mejor resolver en lo que corresponda.

Atentamente,

JUAN PAULINO

Firmado digitalmente

MEJIA

por JUAN PAULINO

OROZCO

MEJIA OROZCO

(FIRMA)

(FIRMA)

Fecha: 2023.05.19

13:42:46-06'00'

Juan Paulino Mejia Orozco

Presidente

ASADA Paso Ancho y Boquerón.

## Resumen

El monitoreo de los tanques en las Asociaciones Administradoras de Acueductos Rurales (ASADAS) es crucial, ya que estas entidades gestionan de la distribución de agua potable en Costa Rica; para ello, es necesario supervisar los niveles de agua, el caudal y el volumen del tanque, por lo tanto, los sistemas de Internet de las Cosas (IoT) resultan de gran utilidad para lograr los objetivos planteados.

Este proyecto tiene como objetivo desarrollar un prototipo de sistema IoT para la ASADA de Paso Ancho y Boquerón, el cual permita el monitoreo remoto y en tiempo real del nivel, fujo y volumen de agua del tanque principal. Inicialmente, se debe realizar la arquitectura del sistema, identificando los componentes y requerimientos necesarios para la recopilación y transmisión de datos.

Seguidamente, se abarca la implementación del nodo de medición, donde se integra a varios sensores y el sistema de comunicación inalámbrico, LoRa, para capturar y enviar la información recopilada hacia la pera de enlace, incluyendo las pruebas exhaustivas para garantizar su correcto funcionamiento.

Una vez que se tiene operando el nodo, se integra la puerta de enlace, la cual actuará como intermediario entre el nodo y el servidor en la nube, abordando la recepción y procesamiento de datos antes de su transmisión, al asegurar la comunicación fluida y confiable. Adicionalmente, se realizarán las correspondientes pruebas adicionales para verificar el funcionamiento adecuado.

Finalmente, se definen los requerimientos necesarios para que los datos recopilados se visualizaran de manera efectiva en una plataforma para IoT en la nube, ThingSpeak,

proporcionado gráficas para la presentación intuitiva y fácil de usar, con el fin de analizar la información del sistema en tiempo real.

Palabras claves: ASADAS, Agua Digital, IoT, LoRa, Modbus, Monitoreo, Octave.

## Abstract

is crucial, since these entities manage the distribution of drinking water in Costa Rica, for these it is necessary to supervise the water levels, flow, and volume of the tank, so Internet of Things (IoT) systems are very useful to achieve the stated objectives.

This project aims to develop a prototype IoT system for the ASADA of Paso Ancho and Boquerón, allowing remote and real-time monitoring of the level, flow, and volume of water in the main tank. Initially, the system architecture must be carried out, identifying the components and requirements necessary for data collection and transmission.

Next, the implementation of the measurement node is covered, where it is integrated with several sensors and the wireless communication system, LoRa, to capture and send the collected information to the link bulb, including exhaustive tests to guarantee its correct operation.

Once the node is operational, the gateway is integrated, which will act as an intermediary between the node and the cloud server, addressing the reception and processing of data before its transmission, ensuring fluid and reliable communication. The corresponding additional tests will be carried out to verify proper operation.

Finally, the necessary requirements are defined for the collected data to be effectively visualized in a platform for IoT in the cloud, ThingSpeak, providing graphics for the intuitive and easy-to-use presentation, to analyze the system information in real time.

Key words: ASADAS, Digital Water, IoT, LoRa, Modbus, Monitoring, Octave.

## Índice general

Nomenclatura...11

1. Introducción...1

1.1 Reseña de la Empresa...2

1.2 Antecedentes...5

1.2.1 Recurso hídrico Costa Rica...5

1.2.2 Entidades reguladoras...5

1.2.3 Aguas no facturadas...6

1.2.4 Tecnologías Inteligentes de Infraestructura de Agua...6

1.3 Planteamiento del problema...7

1.3.1 Contexto del problema...7

1.4 Objetivo General...8

1.5 Objetivos Específicos...8

1.6 Justificación...9

1.6.1 Describa la situación actual y la deseada...10

2. Metodología...11

2.1 Metodología para el cumplimiento de los objetivos...11

2.2 Viabilidad...12

2.3 Alcance ... 13

3. Marco teórico ... 14

3.1 La gestión de pérdidas hídricas ... 14

3.2 American Water Works Association (AWWA) ... 14

3.3 Sistemas Ciber físicos ... 14

3.4 Teoría de señales de sensores/Sensores de nivel para tanques de agua potable ... 15

3.5 Transformación digital de datos ... 15

3.6 Digital Retrofit ... 16

3.7 Arad Octave: Medidores de agua ultrasónicos ... 16

3.8 Protocolo Modbus ... 16

3.9 Dispositivo de IoT/ Sistemas de IoT ... 18

3.10 Protocolo LoRaWAN ... 18

3.11 Antenas ... 19

3.12 Protocolo MQTT ... 19

3.13 Modelo de device-to-gateway ... 19

3.14 Protocolos de comunicación inalámbricos y de trasmisión de datos mediante

Internet ... 19

4. Arquitectura del Sistema IoT ... 21

5. Nodo de medición integrado ... 25

5.1 Programación y conexión ... 25

5.1.1 Sensor de nivel (SN) ... 27

5.1.2 Comunicación Modbus ... 27

5.1.3 Comunicación inalámbrica mediante red LoRa ... 28

6. Puerta de enlace para la recepción de datos ... 31

6.1 Implementación de Recepción de Datos en la Puerta de Enlace ... 31

6.2 Procesamiento de datos en la puerta de enlace antes de la transmisión a la nube 32

6.2.1 Definir la ruda del directorio y configuración de la comunicación en serie 32

6.2.2 Bucle principal para recepción y procesamiento de datos ... 33

6.3 Configuración del protocolo de comunicación para la transmisión de datos hacia la plataforma ThingSpeak, desde la puerta de enlace ... 33

7. Visualización para análisis de datos ... 35

7.1 Funcionalidades de la plataforma de visualización ... 35

8. Conclusiones ... 40

8.1 Recomendaciones relacionadas a la instalación en la ASADA Paso Ancho y Boquerón ... 41

Bibliografía ... 42

9. Anexos ... 46

9.1 Plano Gabinete de Control ... 46

9.2 Informe pruebas comunicación Modbus ... 47

9.3 Informe Pruebas Finales ... 50

9.4 Procedimiento Construcción Nodo medición. ... 54

9.5 Códigos para el sistema IoT... 56

9.5.1 Transmisión datos del nodo hacia puerta de enlace... 56

9.5.2 Receptor de datos hídricos en la puerta de enlace ... 56

9.5.3 Transmisor a plataforma ThingSpeak... 56

9.5.4 Visualización ThingSpeak... 56

10. Apéndices... 57

10.1 Hojas de datos e información de equipos ... 57

## Índice de tablas

Tabla 1 Arquitectura para sistema IoT, mediante sistemas de ingeniería...22

Tabla 2 Datos contenidos en el mensaje enviado...29

## Índice de figuras

Figura 1. Mapa de ubicación, ASADA Paso Ancho y Boquerón. [15]...19

Figura 2. Esquema del sistema del acueducto de Paso Ancho y Boquerón. [15]...20

Figura 3. Metodología para el desarrollo del Sistema IoT. Fuente: Elaboración propia, Lucidchart.

...33

Figura 4. Pantalla digital, medidor de agua ultrasónico Octave. [21]...37

Figura 5. Dispositivo Modbus donado al Laboratorio Delta por la ASADA Paso Ancho y

Boquerón. Fuente: Elaboración propia...38

Figura 6. Diagrama conexión Modbus. [21]...39

Figura 7. Diagrama para la arquitectura del sistema IoT. Fuente: Elaboración propia, Lucidchart.

...43

Figura 8. Arquitectura general del sistema IoT. Fuente: Elaboración propia, PowerPoint..47

Figura 9. Arquitectura detalla del nodo del sistema IoT. Fuente: Elaboración propia, PowerPoint.

...47

Figura 10. Metodología para la integración del nodo de medición. Fuente: Elaboración propia,

Lucidchart...49

Figura 11. Diagrama de conexión sensor de nivel. Fuente: Elaboración propia, OneNote..50

Figura 12. Diagrama de conexión, pruebas modulo Modbus. Fuente: Elaboración propia,

Lucidchart...51

Figura 13. Metodología para la puerta de enlace. Fuente: Elaboración propia, Lucidchart.55

Figura 14. Diagrama de flujo para la lógica de recepción de datos en la puerta de enlace. Fuente:

Elaboración propia, PowerPoint...57

Figura 15. Diagrama de flujo para la lógica de procesamiento de datos en la puerta de enlace.

Fuente: Elaboración propia, PowerPoint...58

Figura 16. Diagrama de flujo para el protocolo de comunicación para la transmisión de datos hacia

la plataforma en la nube. Fuente: Elaboración propia, PowerPoint. ...60

Figura 17. Gráfica del voltaje general (V) en función de del tiempo (date). Fuente: Elaboración

propia, ThingSpeak...63

Figura 18. Gráfica Voltaje de celda (V) en función del tiempo (date). Fuente: Elaboración propia,

ThingSpeak...64

Figura 19. Gráfica caudal (m3/h) en función del tiempo (date). Fuente: Elaboración propia,

ThingSpeak...64

Figura 20. Gráfica Volumen (m3) en función del tiempo (date). Fuente: Elaboración propia,

ThingSpeak...65

Figura 21. Gráfica nivel del agua (m) en función del tiempo (date). Fuente: Elaboración propia,

ThingSpeak...65

Figura 22. La intensidad de la señal (dBm) en función del tiempo (date). Fuente: Elaboración

propia, ThingSpeak...66

Figura 23. Pruebas realizadas en las instalaciones de la ASADA. Fuente: Elaboración propia. 78

Figura 24. Nodo de medición con sensor de nivel instalado en el tanque. Fuente: Elaboración

propia...80

Figura 25. Nodo de medición encendido. Fuente: Elaboración propia...81

Figura 26. Recepción de datos desde el PLC para ser transmitidos hacia la puerta de enlace. Fuente:

Elaboración propia...82

Figura 27. Transmisión de datos desde la puerta de enlace a la nube. Fuente: Elaboración propia.

...82

Figura 28. Visualización de datos en la plataforma ThingSpeak. Fuente: Elaboración propia. 83

Figura 29. Construcción completa interior gabinete. Fuente: Elaboración propia...85

Figura 30. Construcción completa nodo medición. Fuente: Elaboración propia...85

## Nomenclatura

<table border="1"><tr><td>ALG</td><td>Application Layer Gateway (puerta de enlace de nivel de aplicación).</td></tr><tr><td>ASADAS</td><td>Asociaciones administradoras de los Sistemas de Acueductos y Alcantarillados comunales en Costa Rica.</td></tr><tr><td>AWWA</td><td>American Water Works Association (Asociación Estadounidense de Obras Hidráulicas).</td></tr><tr><td>AyA</td><td>Instituto Costarricense de Acueductos y Alcantarillados.</td></tr><tr><td>CEPAL</td><td>Comisión Económica para América Latina y el Caribe.</td></tr><tr><td>FBSE</td><td>Functions Based Systems Engineering (Ingeniería en Sistemas Basada en Funciones).</td></tr><tr><td>IoT</td><td>Internet of Things (Internet de las Cosas)</td></tr><tr><td>IWA</td><td>International Water Association (Asociación Internacional del Agua).</td></tr><tr><td>LNA</td><td>Laboratorio Nacional de Aguas.</td></tr><tr><td>LoRa</td><td>Long Range (Largo Alcance).</td></tr><tr><td>LoRaWAN</td><td>LoRa Wide Area Network (Red de área amplia LoRa™)</td></tr><tr><td>LPWAN</td><td>Low Power Wide Area Network (Red de área amplia de baja</td></tr></table>

potencia).

<table border="1"><tr><td>MINAE</td><td>Ministerio de Ambiente y Energía.</td></tr><tr><td>MQTT</td><td>Message Queuing Telemetry Transport(Transporte de telemetría de Message Queue Server).</td></tr><tr><td>ODS</td><td>Objetivos Desarrollo Sostenible.</td></tr><tr><td>OPS</td><td>Organización Panamericana de la Salud.</td></tr><tr><td>PLC</td><td>Programmable Logic Controller(Controlador lógico programable).</td></tr></table>

## Capítulo 1

## Introducción

La distribución de agua potable es un sistema complejo encargado de llevar millones de litros desde las fuentes hídricas hasta los consumidores residenciales, agrícolas e industriales. Por lo tanto, se deduce cómo el agua es esencial para la vida en el planeta; sin embargo, el suministro de este recurso se ve amenazado por diversos factores como la creciente la contaminación y el cambio climático, lo cual representa un desafío importante para la gestión eficiente de los recursos hídricos cada vez más limitados. Para enfrentar esto, es necesario implementar un cambio fundamental en la forma en que se administra el agua. [1]

En Costa Rica hay un gran recurso hídrico y, según con datos del Laboratorio Nacional de Aguas (LNA), se estima que, entre los años 1990 y el 2019, el indicador nacional de población abastecida con agua de calidad potable, o gestionada en forma segura, aumentó de 50 % a 93 %. [27]

En este contexto, las Asociaciones y Comités Administradores de Acueductos (ASADAS) son de gran importancia, ya que suministran cerca del 28.7 % de la población con agua potable. Sin embargo, carecen de suficiente acceso a tecnología y asesoramiento en planes de inversión, lo que las hace vulnerables a las amenazas derivadas del cambio climático. Por lo tanto, es importante considerar su papel en la sostenibilidad y distribución del recurso hídrico. [2]

Los grandes distribuidores de agua del país cuentan con la tecnología y los recursos humanos y financieros para la adecuada gestión de abastecimiento; pero en las zonas rurales,

esto se encuentra en manos de las ASADA. Además, algunas de las nacientes se ubican en propiedades que no pertenecen a las entidades mencionadas, y la mayoría de las zonas en donde se ubican las captaciones son lejanas, de difícil acceso y con grandes riesgos de derrumbes, deslaves e inundaciones. A partir de lo anterior, es necesario considerar el ahorro en tiempos de monitoreo que implica la implementación de la digitalización de datos, en este caso, en el sector agua y las ASADAS de Costa Rica. [28]

Desde estas perspectivas, se puede considerar como la digitalización de datos está cambiando muchos sectores de la sociedad, desde la educación hasta el manejo de recursos naturales. Por lo tanto, se considera la integración de herramientas digitales que apoyen el progreso en el sector del agua, para responder a las necesidades de los clientes y, de esta manera asegurar el cumplimiento y servicios más seguros con regulaciones, lo cual implica cambios en la cultura organizacional. [1]

El presente proyecto tiene como objetivo, desarrollar un sistema de recopilación de datos que permita la supervisión remota, en tiempo real, del nivel de agua y de las macro mediciones de flujo del tanque principal, en la ASADA Paso Ancho y Boquerón. Primeramente, se construyó un prototipo funcional que facilite una gestión más eficiente de los recursos hídricos. En cuanto a esto, se contempló el diseño y construcción del prototipo, compuesto por un PLC, la fuente de la alimentación eléctrica de los dispositivos, mediante energía solar; el diseño del tablero de control, la implementación de la red LoRa para Paso Ancho, junto con la programación del software de los nodos de comunicación y la puerta de enlace (Gateway).

Finalmente, se busca con este proyecto, que el sistema planteado sea funcional para otras ASADAS del país que operan acueductos rurales y, principalmente, para el resto de los

tanques de la ASADA de Paso Ancho y Boquerón. Esto debido a la flexibilidad técnica para adaptarse a sistemas ya existentes a un menor costo de implementación, lo cual beneficia a estas organizaciones.

## 1.1 Reseña de la empresa

Las ASADAS son un ejemplo de organizaciones comunales para la colaboración, apropiamiento y gobernanza del recuro hídrico sin fines de lucro, Actualmente, existen más de 2000 en el país y trabajan bajo el marco legal de la Ley de Asociaciones.[14] Asimismo, son las encargadas de administrar los sistemas de acueductos y alcantarillados comunales, bajo el esquema acordado con el Instituto Costarricense de Acueductos y Alcantarillados (AyA), mediante un convenio de Delegación de Administración. En el caso de este proyecto, se trabajará con la ASADA de Paso Ancho y Boquerón, el cual se ubica en la provincia de Cartago (N°3), cantón Oreamuno (N°7), distrito de Cipreses (N°4), Costa Rica.[15]. A continuación, se presenta una figura que ilustra la ubicación de la ASADA.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 1. Mapa de ubicación, ASADA Paso Ancho y Boquerón. [15]

</div>

Las fuentes de abastecimiento para este acueducto son las nacientes, las cuales se

cloran en los tanques de almacenamiento. El sistema está compuesto por dos capacitaciones tipo nacientes, dos tanques de almacenamiento, líneas de conducción, redes de distribución y dos sistemas de desinfección, tal y como se presenta a continuación: [15]


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 2. Esquema del sistema del acueducto de Paso Ancho y Boquerón. [15]

</div>

Tanques de almacenamiento

## El salto

El tanque ubicado en la naciente el Salto, se encuentra en las coordenadas geográficas Longitud: -83,869669 Latitud: 9,891815, con una altitud aproximada de 1740,9089 msnm. Asimismo, es una estructura construida es a nivel del terreno, en plástico, tiene un volumen de 20 m3 que almacena el agua proveniente de la naciente mencionada, de 200 previstas [15].

## Boquerón

El tanque ubicado en la naciente el Boquerón se encuentra en las coordenadas geográficas Longitud: -83,855903 Latitud: 9,89307, con una altitud aproximada de 1776,6096 msnm. Se trata de una estructura de construcción a nivel del terreno, en concreto, tiene más 45 años de antigüedad y un volumen de 67 m3; almacena el agua proveniente de la naciente

mencionada. [15] Otro tanque de 200 m $ ^{3} $ de 500 previstas, para una totalidad de 700 previstas.

## 1.2 Antecedentes

## 1.2.1 Recurso hídrico Costa Rica

El clima en Costa Rica se define como tropical húmedo para la mayoría de las zonas, y frío para aquellas de mayor latitud, con un ancho territorial medio de 120km. Geográficamente, se establece la vertiente del Caribe, húmeda y lluviosa, sin déficit hídrico en todo el año; la subvertiente norte, la cual drena hacia el Río San Juan, río fronterizo con Nicaragua y, finalmente, la vertiente del Océano Pacífico, la más seca, con marcada disminución de caudales en el estiaje. [29]

Para el 2013, la extracción hídrica total nacional fue de 2.35 km $ ^{3} $ . EN este ámbito, se destaca el sector agrícola con un 57 % del total de las extracciones, considerando el riego y el sector ganadero con 0.22 km $ ^{3} $ . Adicionalmente, las extracciones para el sector municipal alcanzaron el 32 % del total y las extracciones para el sector industrial alcanzaron el 11 %. [29]

La OPS menciona en el Análisis Sectorial Agua Potable y Saneamiento (2002) que los inicios de los asentamientos humanos en Costa Rica fueron por ríos, quebradas y otros cauces, donde era necesario tener a toda la población del lugar con agua para consumo humano, lo que lleva al desarrollo de pozos artesanales para el abastecimiento puntual de agua, los cuales fueron los primeros sistemas de acueductos administrados por las municipalidades.[3]

## 1.2.2 Entidades reguladoras

En Costa Rica, hay varias organizaciones involucradas en la regulación global de la protección, extracción, uso, gestión y administración del recurso hídrico. Originalmente, el Instituto Costarricense de Acueductos y Alcantarillados (AyA) fue creado como el órgano

rector del recurso hídrico en el país [3]. Su objetivo era solucionar el problema de distribución y captación de agua; sin embargo, anterior a este, se emitió la Ley de Aguas en 1942, donde se establecía que los acueductos eran patrimonios del Estado. Tiempo después, aparece el AyA, dado que se evidenciaba que el Estado no era capaz de asumir lo acordado en la ley mencionada anteriormente. Por lo tanto, se emitió en 1953 la Ley General de Agua Potable, en la cual los organismos administradores, debían fijar tarifas adecuadas que permitieran la correcta operación y garantizar la potabilidad del agua, en resguardo de la salud pública.[3]

En la actualidad, el Ministerio de Ambiente y Energía (MINAE) es el órgano rector más importante, encargado de elaborar y establecer políticas, reglamentos y directrices para la gestión, uso y protección del recurso hídrico. [3]; mientras que, las ASADAS son todas aquellas asociaciones administradoras de sistemas de acueductos y alcantarillados comunales que se rigen por el Reglamento de las Administradoras de Sistemas de Acueductos y Alcantarillados Comunales.[4]

## 1.2.3 Aguas no facturadas

Durante mucho tiempo, las pérdidas de agua han sido un problema para los sistemas de distribución. Anteriormente, las empresas solían referirse a estas como "agua no contabilizada", al gestionar el flujo de entrada y salida del sistema de distribución. Sin embargo, la falta de términos y definiciones estandarizados ha generado desafíos de comunicación entre las empresas y mediciones inconsistentes que dificultan su comparación adecuada (benchmarking). Por lo tanto, la Asociación Internacional del Agua ha buscado desarrollar una metodología de auditoría de agua, para contabilizar y controlar las pérdidas de agua potable en los sistemas de distribución.[5]

En el país, el Instituto Costarricense de Acueductos y Alcantarillados (AyA) ha establecido un plan de acción para reducir en un 17 % el índice de agua no facturada y aumentar en un 7,5 % la eficiencia energética al 2024. Para lograr esta meta, se destacan que una posible solución en el plan de acción por parte de la institución se alinea al uso de sistemas IoT. [6]

## 1.2.4 Tecnologías inteligentes de infraestructura de agua.

En la actualidad, es difícil cumplir con la demanda de agua, si no se invierte en crear y mantener estructuras para la prestación de servicios, ya que su calidad es necesaria. En América Latina y el Caribe es cada vez más la demanda en suministro de agua, pero debido a la alta desigualdad de ingresos en comparación a economías desarrolladas, es necesario el crecimiento en la digitalización para el manejo de información.[30]

Lo anterior, permite implementar mecanismos de respuesta a la demanda, y reducción de costos mediante medidores inteligentes y aplicaciones como Internet de las Cosas (IoT, por sus siglas en inglés). El cambio tecnológico puede contribuir a cambiar el paradigma bajo el cual se organizan y operan los servicios de agua y saneamiento. Por ende, estos avances contribuyen a un mejor manejo, de manera integrada, regulando la cantidad de agua utilizada por cada uno de los principales usuarios.[30]

La Asociación Internacional del Agua (IWA), en su Programa de Agua Digital, está participando activamente en todo el sector internacional del agua para apoyar la adopción de un enfoque más inteligente para su gestión. La mayoría de las soluciones que

involucran IoT y SWIT utilizan modulación de radiofrecuencia y protocolos de red para la intercomunicación de los dispositivos de medicion y monitoreo. Actualmente, uno de los tipos de modulación incipiente en la industria es LoRa $ ^{\mathrm{TM}} $ (por sus siglas en inglés, Long Range).[7]

## 1.3 Planteamiento del problema

En las secciones anteriores se ha comentado brevemente el contexto a nivel nacional de las ASADAS y los distintos retos que se enfrentan estas organizaciones. Este caso se enfocará específicamente en la ASADA Paso Ancho y Boquerón.

## 1.3.1 Contexto del problema

La red de acueductos presente en la ASADA Paso ancho y Boquerón utiliza un sistema de abastecimiento por gravedad en todos sus tanques, como se comentó anteriormente, la red localizada en Boquerón cuenta con dos tanques, donde, solamente, el principal posee medidores de agua ultrasónicos (Octave) adecuados para la instalación del módulo Modbus, los cuales se encuentran ubicados únicamente en la salida del tanque. Además, estos no trabajan al mismo tiempo, sino que se alternan o, en el caso de que alguno se vea interrumpido, el otro medidor toma su lugar. En estos es donde se estarán realizando las pruebas de funcionamiento del prototipo.

En el caso de la ASADA de Paso Ancho y Boquerón, se presentan dos sistemas de acueductos, observables en la Figura 1 (en El Salto y Boquerón), en los cuales, los tiempos para que los operadores observen los niveles del tanque pueden tardar de de una hora o más. Adicionalmente, se invierten 20 minutos en desplazarse y entre 40 a 45 minutos para inspeccionar y llevar a cabo otras tareas. Además, indica el administrador la ASADA, S. Rodríguez (comunicación personal, de mayo del 2023), que los porcentajes de aguas no facturadas están entre un 10-20 %.

Por lo tanto, la problemática que se busca resolver yace en, al estar los tanques de abastecimiento en una zona de difícil acceso para los usuarios de la ASADA, reducir los tiempos, para evitar el rebalse o vaciamiento de agua en los tanques. Ante esto, se requiere una solución que permita la recopilación y visualización de datos hídricos relacionados con la operación y niveles de agua del tanque principal, desde cualquier dispositivo, con un enfoque desde IoT.

El no contabilizar o facturar el agua es un problema mundial que afecta muchos acueductos y genera pérdidas millonarias. En Costa Rica, los estudios indican que alrededor del 50 % del agua potable no es facturada, lo que provoca un importante déficit financiero, Dado que el agua es un recurso fundamental, es esencial reducir al máximo su desperdicio desde un punto de vista ambiental. Además, desde una perspectiva financiera, la problemática implica una serie de costos. [8] Por ende, lo dicho anteriormente es necesario para garantizar un suministro adecuado y estable de agua a los usuarios y se evitan interrupciones en el servicio o desperdicio de agua. Además, contribuye a la conservación del recurso hídrico impedir pérdidas innecesarias. Asimismo, la ASADA se beneficiaría al facilitar implementación de la digitalización del agua para poder monitorear los niveles del tanque a larga distancia y vía internet.

## 1.4 Objetivo general

Desarrollar un prototipo para recopilación de datos que permita la supervisión remota, en tiempo real, del nivel de agua y de las macro mediciones de flujo del tanque principal, en la ASADA Paso Ancho y Boquerón.

## 1.5 Objetivos específicos

1. Generar la arquitectura de un sistema de recopilación de datos basado en IoT, para medición del nivel y flujo de agua del tanque principal.

Entregable: Arquitectura detallada del sistema.

2. Implementar un nodo de medición que integre los sensores de nivel de agua, macro medidores de flujo, el controlador y el sistema de comunicación inalámbrico.

Entregable: Documento de verificación del nodo según los requerimientos.

3. Implementar una puerta de enlace que sea capaz de recibir los datos provenientes del

nodo de medición y transmitirlos de manera eficiente a un servidor en la nube.

Entregable: Verificación de que la información es recibida y transmitida.

4. Visualizar los datos en una plataforma para IoT en la nube que permita la presentación y análisis de información recopilada por el sistema.

Entregable: Tablero de visualización.

## 1.6 Justificación

La importancia de este proyecto se relaciona a la necesidad mundial de reducir las aguas no facturadas, ya que esta situación afecta a todos los acueductos de alguna manera. Asimismo, se considera el impacto que la problemática puede tener en la escasez existente del recurso hídrico debido a la explotación y cambio climático, dado que en el Informe del estado de la nación (2020) se indica que, debido a problemas meteorológicos como las lluvias extremas e inundaciones, se ha presentado una baja en el caudal de los ríos; en consecuencia, se produce una disminución de las reservas de agua, las cuales son esenciales para los acueductos, lo cual ocasiona efectos directos en el ámbito mencionado.[8]

La Comisión Económica para América Latina y el Caribe (CEPAL), indica que en el país existe una necesidad de proteger los acuíferos y las tomas de agua; además, señala que los acueductos como las ASADAS, requieren una mejora de infraestructura, vigilancia y control de tomas de captación de nacientes. [8] Por lo anterior, se considera cómo en el caso de Costa Rica, estas entidades enfrentan un importante rezago en temas estructurales y manejo del recurso hídrico. Adicionalmente, se estima que las asociaciones mencionadas tienen pérdidas hasta deel 60 % del total de agua que producen sus fuentes. La situación se vuelve más crítica si se contempla la nula utilización de la tecnología en su atención, el registro y seguimiento de los casos atendidos.[9]

Los sistemas pequeños de abastecimiento de agua, potable pueden verse expuestos a desafíos a la hora de implementar programas nuevos de desarrollo debido a los desafíos tecnológicos. Aunado a esto, otro problema que es necesario considerar, son las pérdidas de agua, las cuales no solo llevan al desperdicio del recurso hídrico, sino, también, a un incremento en el consumo eléctrico.[9] Además, la constante necesidad de monitorear el nivel

del tanque provoca que el tiempo dedicado a estas tareas sea mayor, cuando se podría destinar a funciones, ya sea de mantenimiento o respuesta a averías.[9]

También, se considera que la solución propuesta es la adecuada para hacer frente a los desafíos que enfrentan las ASADAS en Costa Rica, debido a la escasez de tecnologías para la gestión de los recursos hídricos. Este planteamiento implica la medición de datos y visualización de los procesos para generar una gran cantidad de datos que se procesarán, analizarán y presentarán de manera que se comprendan y utilicen en las ASADAS. Por lo tanto, la digitalización será un habilitador clave para una gestión del agua más inteligente.[9]

Finalmente, la implementación de un sistema de monitoreo en tiempo real del acueducto podría asegurar la rentabilidad y sostenibilidad de futuras inversiones en la ASADA. Además, si se siguen las recomendaciones de la AWWA, se pueden reducir las pérdidas de agua y administrar el recurso hídrico de manera más eficiente. [9] Cabe mencionar que el proyecto se alinea con la Estrategia Nacional de Cambio Climático y los Objetivos de Desarrollo Sostenible de la Organización de las Naciones Unidas, en particular, con el duodécimo: Consumo responsable y producción; y el sexto: agua limpia y saneamiento. Por lo tanto, el objetivo es proporcionar información documentada y herramientas para que los operadores del acueducto puedan monitorear con mayor agilidad el nivel de agua del tanque de suministro. [9]

## 1.6.1 Descripción de la situación actual y la deseada

Debiera: la digitalización es un habilitador clave para una gestión del agua más inteligente, lo que lleva a generación y medición de una gran cantidad de datos que serán procesados, analizados y presentados, de manera que puedan ser comprendidos y utilizados

en las ASADAS, para reducir las aguas no facturadas. [9]

Dato suministrado: los porcentajes de agua no contabilizada en Dinamarca y Holanda son de un 6 % y, en Alemania, un 7 %. En contraste, las estadísticas sobre los acueductos propiedad del AyA, están por encima de estos. [20]

Desviación (problema): las ASADAS carecen de suficiente acceso a tecnología, afectando su papel en la distribución del recurso hídrico, generando las pérdidas de agua. Además, el tiempo invertido en monitorear el nivel del tanque es muy alto, mientras este se podría destinar a tareas de mantenimiento y respuesta a averías.[9]

Realidad: el tanque principal de suministro tiene una boya para inspeccionar el nivel de agua del tanque, por lo que los operadores se deben desplazar al lugar para verificar los niveles de agua. Además, las ASADAS enfrentan un importante rezago en temas estructurales y manejo del recurso hídrico. Además, se estima que tienen pérdidas de agua de hasta el 60 %. [9]

Dato suministrado: los operadores duran 20 minutos en llegar al tanque y de 40 a 45 minutos para realizar las tareas correspondientes, ya sean de inspección de nivel o mantenimiento. Asimismo, se presenta un porcentaje de aguas no contabilizadas entre 10 % y 20 %.

## Capítulo 2

## Metodología

A continuación, se presenta la metodología seguida para el cumplimiento de los objetivos planteados- Seguidamente, se desarrolla el procedimiento para las distintas partes del sistema IoT, planteado para el prototipo realizado para el proyecto ASADAS. En la figura 3, se evidencia la metodología utilizada.

## 2.1 Metodología para el cumplimiento de los objetivos

- Capítulo 4: en él se definen requerimientos necesarios mediante sistemas de ingeniería, como: funcional, comportamiento, estructura y experiencia. Lo anterior, para generar la arquitectura del sistema IoT, entre los que se encuentran: la recolección de datos hídricos del taque y el procesamiento de los datos. Finalmente, se realizará la transmisión de datos a la puerta de enlace y, de ahí, hacia la plataforma en la nube para la visualización y análisis de datos.

- Capítulo 5: se presenta la implementación del nodo de medición mediante la selección del sensor de nivel de agua y un módulo adecuado para adquirir los datos de los macro medidores de flujo Octave en las instalaciones de la ASADA. También, se selecciona un controlador compatible, para, posteriormente, realizar la conexión física y recibir los datos con el PLC M-Duino y conseguir la transmisión de datos mediante LoRa hacia la puerta de enlace. Finalmente, se realizan pruebas exhaustivas del nodo de medición para asegurarse de que los sensores están funcionando correctamente, la transmisión de datos es estable y el controlador responde según lo esperado.

- Capítulo 6: aquí se expone cómo, para la integración de la puesta de enlace fue necesario implementar un código para recibir los datos transmitidos por el nodo mediante LoRa y, al mismo tiempo, se incluyó una lógica adicional para procesar los datos, antes de enviarlos a la plataforma en la nube, ThingSpeak, mediante la configuración de un protocolo de comunicación WiFi. Asimismo, se realizaron pruebas exhaustivas para asegurarse de que la puerta de enlace reciba correctamente los datos del nodo, los procese y los transmita con éxito a la plataforma en la nube.

- Capítulo 7: finalmente, para la visualización en la plataforma ThingSpeak de la información recibida desde la puerta de enlace, fue necesario detallar las necesidades específicas, así como las funcionalidades esenciales para el análisis de los datos recopilados por el sistema y conseguir la presentación de información en un tablero de visualización.

## 2.2 Viabilidad

En colaboración con el Laboratorio Delta de la Escuela de Ingeniería en Electromecánica del Instituto Tecnológico de Costa Rica, se busca implementar herramientas para la digitalización de las mediciones de nivel de agua en el tanque de suministro utilizando sensores y el protocolo Modbus, el cual fue suministrado por la ASADA de Paso Ancho y Boquerón, con el objetivo de lograr un monitoreo remoto y en tiempo real del nivel del tanque. Por lo tanto, se propone la integración de sistemas IoT basados en la tecnología LoRa, que consta de dos roles: el nodo y la puerta de enlace. Esto permitirá una comunicación eficiente de los datos y garantizará un monitoreo eficaz del suministro de agua.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 3. Metodología para el desarrollo del Sistema IoT. Fuente: Elaboración propia, Lucidchart.

</div>

## 2.3 Alcance

Para efectos de este proyecto se plantea un alcance de tipo exploratorio, tomando en cuenta que se indagó la aplicación de una nueva tecnología, desde una perspectiva innovadora [25], enfocada en la gestión hídrica. Específicamente, con el objetivo de monitorizar variables hídricas supuestas basadas en las presentes en el acueducto principal de la ASADA de Paso Ancho y Boquerón. En términos generales, se enfocará en la incorporación de dispositivos de monitoreo digital que informen el estado del acueducto, sin contemplar la micro medición en cada uno de los abonados, considerando que se trata de un prototipo con datos supuestos.

## Marco teórico

## 3.1 La gestión de pérdidas hídricas

Existen diversos organismos internacionales que poseen expertos en gestión de agua, con el fin de combatir las problemáticas que rodean el tema. [8] La aplicación de una auditoría de agua es el paso básico para que una empresa en el área rinda cuentas de sus operaciones. Este estudio aborda las preguntas como: ¿Cuánta agua se está perdiendo? y ¿Cuánto le está costando estas pérdidas a la empresa de agua? Por ende, para los sistemas que actualmente no auditan sus suministros, este es el primer paso recomendado por AWWA en el desarrollo de programas de control de pérdidas.[10]

## 3.2 American Water Works Association (AWWA)

EI AWWA establece criterios sobre la calidad del recurso hídrico, al mismo tiempo, valores recomendables de KPI para agua no contabilizada, estos afirman no tener un porcentaje de agua no contabilizada registrado para todos los acueductos. Por lo tanto, se recomienda que cada acueducto establezca su propio objetivo, en agua no contabilizadas, que espere alcanzar según las características que estos hayan establecido para las condiciones de trabajo. [11]

## 3.3 Sistemas Ciberfísicos

Algunos ejemplos de sistemas ciberfísicos (CPS) son: una central nuclear, la red eléctrica, un vehículo autónomo, una línea de producción automatizada. Estos son sistemas

dinámicos que constan de una parte física, como un proceso industrial y una virtual, con algoritmos de control implementados en una computadora; la información entre estas capas se intercambia mediate sensores y actuadores. En este caso, los sensores transmiten información del sistema físico, como temperatura, nivel de fluido, ente otros, a la capa virtual donde se encuentran los algoritmos de control.

Cabe resaltar que, debido a la interacción indirecta entre la capa física y la virtual, a través de conexiones remotas o inalámbricas, los CPS son vulnerables a ataques cibernéticos. El aumento de los ataques cibernéticos en la industria requiere medidas inmediatas para garantizar la seguridad de las empresas y minimizar los riesgos, los cuales representan grandes pérdidas económicas y pueden amenazar la seguridad e integridad de las personas. [19]

## 3.4 Teoría de señales de sensores/sensores de nivel para tanques de agua potable

Un sensor de nivel es un dispositivo electrónico que mide la altura de un material, generalmente líquido, dentro de un tanque u otro recipiente. Existen dos tipos principales de sensores de nivel: los de punto y los continuos. [9]

En la medición de nivel en tanques de agua potable, es común encontrar una variedad de sensores con diferentes mecanismos de funcionamiento. Entre los más utilizados se encuentran los sensores de flotador, los sensores ultrasónicos sin contacto, los sensores ultrasónicos de contacto, los sensores capacitivos, entre otros. [9] Un sensor, también conocido como detector o elemento primario, forma parte de un lazo de control o instrumento que, primero, detecta el valor de la variable de un proceso y, luego, asume ese valor correspondiente como predeterminado para el estado de salida. [8]

## 3.5 Transformación digital de datos

La Industria 4.0 (I4.0) se refiere a una etapa avanzada en el área, que se caracteriza por la utilización intensiva de tecnologías digitales como IoT, la nube, el big data y la inteligencia artificial. Lo anterior, ha evolucionado para abarcar otras áreas como: dimensiones empresariales como la cadena de suministro, los productos y servicios finales, y la forma en que los trabajadores operan en el sistema de producción.[18] Según Marcon et al., (2022): la Industria 4.0 es el resultado de un proceso de transformación digital en el entorno industrial, que implica una adopción tecnológica gradual y requiere atención tanto desde el punto de vista tecnológico, como desde una perspectiva organizativa y ambiental.

El mantenimiento predictivo se ha mejorado y optimizado mediante el uso de dispositivos IoT, junto con servicios basados en datos, la nube y algoritmos de inteligencia artificial. Estas soluciones implican cambios y configuraciones complejas en términos de integración de software y hardware, y, también, requieren cambios en los canales de distribución hacia una directa que controle la oferta y el suministro.[18]

## 3.6 Digital Retrofit

En un inicio, la definición de eficiencia juega un papel esencial para la comprensión de Digital Retrofit. La eficiencia según Markus et al., (2023) es: "la mejora de la relación entre los recursos utilizados y los resultados obtenidos". Por lo que, su objetivo principal no es necesariamente la reducción de consumo de recursos, es hacer más con menos. La optimización digital (Digital Retrofit) se logra con la mejora e incorporación de componentes digitales y/o conectados, los cuales pueden ser instalados directamente en la maquina o aplicados a la infraestructura. [17]

La eficiencia de los recursos es por lo tanto un factor significativo para lograr una

producción efectiva con el menos uso de materiales y energía. Por consiguiente, la transformación digital es un requisito necesario para alcanzar la eficiencia de los recursos y poder promover la sostenibilidad mediante Industria 4.0. [17]

## 3.7 Arad Octave: Medidores de agua ultrasónicos

La medición de OCTAVE se basa en sensores ultrasónicos de doble haz y tiempo de tránsito, que miden el tiempo que una onda ultrasónica tarda en viajar entre los sensores del medidor. Estos sensores funcionan como emisores y receptores, permitiendo que la onda ultrasónica viaje en ambas direcciones: a favor y en contra del flujo. La diferencia de tiempo entre las ondas que viajan en ambas direcciones se utiliza para calcular la velocidad del agua, ya que la onda viaja más lenta contra el flujo. Los valores de medición de flujo pueden ser transferidos a través de la comunicación estándar: salida digital o analógica. [21]


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 4. Pantalla digital, medidor de agua ultrasonico Octave. [21]

</div>

## 3.8 Protocolo Modbus

Modbus es considerado un protocolo viejo, pero está bien establecido debido a la facilidad que presenta para la comunicación entre PLC y otros equipos industriales, en el contexto de conectar este protocolo a Arad Octave, es compatible ya que permite la integración y comunicación con los equipos. [16] En la figura 6, se visualiza como conectar el protocolo Modbus al macro medidor.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 5. Dispositivo Modbus donado al Laboratorio Delta por la ASADA Paso Ancho y Boquerón. Fuente: Elaboración propia.

</div>

La salida del protocolo Modbus tiene las siguientes funciones disponibles [21]:

1- Alarmas (batería tuberías vacías).

2- Número de serie AMR.

3- Reloj en tiempo real.

4- Unidad de volumen.

5- Unidades de flujo.

6- Flujo de corriente.

7- Dirección de flujo.

8- Volúmenes de avance y retroceso.

9- Resolución de flujo y volumen.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 6. Diagrama conexión Modbus. [21]

</div>

## 3.9 Dispositivo de IoT/ Sistemas de IoT

El IoT es un sistema interconectado de dispositivos informáticos, máquinas, objetos y personas con identificadores únicos que pueden transferir datos a través de una red sin interacción de persona a persona o de persona a computadora. Cabe especificar que una solución completa de IoT incluye cuatro componentes distintos: sensores / dispositivos, conectividad, procesamiento de datos (software) y una interfaz de usuario. [9]

Actualmente, hay cuatro modelos de conectividad estandarizados, que aumentan la flexibilidad de la red y permiten adaptar los sistemas de IoT, según las necesidades del usuario: [8]

- Device-to-device (dispositivo a dispositivo).

- Device-to-cloud (dispositivo a la nube).

- Device-to-gateway (dispositivo a puesta de enlace).

- Back-End Data-Sharing (intercambio de datos a través del back-end).

Esta variedad de modelos aumenta la flexibilidad de red y permiten adaptar los sistemas de IoT, según las necesidades del usuario. Además, una plataforma IoT facilita la comunicación, el flujo de información, la administración de dispositivos y la funcionalidad de las aplicaciones.[8]

## 3.10 Protocolo LoRaWAN $ ^{TM} $

El Internet de las cosas (IoT) es una red de dispositivos físicos que se conectan a Internet y se comunican entre sí. En cuanto a esto, varias tecnologías inalámbricas son utilizadas para conectar estos dispositivos a Internet, como la comunicación inalámbrica de corto alcance, la comunicación celular y la comunicación LPWAN. Adicionalmente, la tecnología LoRa $ ^{\mathrm{TM}} $ se encuentra dentro de la categoría LPWAN (Red de Área Amplia de Bajo Consumo).[9]

Cabe resaltar que LoRa $ ^{\mathrm{TM}} $ y LoRaWAN $ ^{\mathrm{TM}} $ son dos conceptos diferentes. La primera, utiliza técnicas de espectro ensanchado y una variación del espectro ensanchado chirp (CSS) con corrección de error directa integrada (FEC). [9] La segunda, la capa física LoRa $ ^{\mathrm{TM}} $ solo habilita el enlace de comunicación de largo alcance. Dentro de la red LoRaWAN $ ^{\mathrm{TM}} $ existen dos roles: el nodo y la puerta de enlace (gateway). El nodo es el dispositivo final que recoge y transmite información, mientras que el gateway actúa como intermediario y retransmite la información de los diferentes sensores a través de Internet a la nube, donde se unifican los datos de todos los sensores y se toman acciones en consecuencia.[12]

## 3.11 Antenas

Una antena es un dispositivo metálico capaz de radiar y recibir ondas electromagnéticas del espacio. Cuando es utilizada para radiar ondas electromagnéticas, se trata de tipo emisora

y al emplearla para interceptar ondas, cumple la función de antena receptora. [23]

La directividad es la propiedad que tiene una antena de transmitir o recibir la energía irradiada en una dirección particular. En caso de una estación móvil y otra fija o ambas móviles, donde no se puede predecir donde estará una de ellas. La antena deberá radiar en todas las direcciones y para ello se utiliza una antena omnidireccional. [23]

## 3.12 Protocolo MQTT

MQTT es el protocolo estándar de comunicación en aplicaciones de IoT, el cual trabaja a partir de mensajería asincrónica que admite la comunicación entre partes desacopladas en espacio y tiempo, esto lo hace escalable en entornos de red poco confiables. El protocolo MQTT utiliza un modelo de publicación y subscripción a los topics y define dos entidades en la red: el intermediario de mensajes (broker) y los clientes. El primero recibe y enruta los mensajes a los clientes de destino y el segundo es cualquier objeto que pueda interactuar con el intermediario para enviar y recibir mensajes.[9]

## 3.13 Modelo de device-to-gateway

En ingles, se conoce a este modelo como el "Application Layer Gateway" (ALG), que se refiere a que el dispositivo se conecta a través de una puerta de enlace (Gateway) para acceder a un servicio en la nube.[13] Por lo tanto, para que esto funcione, es necesario contar con un software o aplicación que actue como intermediario en la comunicación entre ambas partes y durante este proceso puede haber otras funciones adicionales, como la traducción de protocolos.[8]

## 3.14 Protocolos de comunicación inalámbricos y de trasmisión de datos mediante Internet

Las arquitecturas de red tipo mesh (malladas) son esenciales para implementar el IoT

en una organización, ya que garantizan la interconexión de todos los dispositivos para compartir y enviar datos al servidor en la nube. En este tipo de red, los dispositivos forman una malla amplia que incluye una estación central y varios nodos. [8]

La principal ventaja de esta configuración es que todos los dispositivos pueden comunicarse entre sí, no solo con el enrutador o dispositivo central. Esto significa que, si un dispositivo se encuentra lejos del enrutador, los nodos pueden actuar como puentes, para permitir que los datos lleguen al enrutador y se tenga acceso a Internet. Esta característica es especialmente beneficiosa en aplicaciones de IoT que abarcan áreas extensas, como una planta industrial. [8]

## Arquitectura del Sistema IoT

El siguiente capítulo se presenta de qué manera fue necesario, para generar la arquitectura del sistema, utilizar conceptos de sistemas de ingeniería, donde fue esencial definir las partes del sistema IoT, y desarrollarla debidamente. Adicionalmente, fue primordial definir detalladamente sus requerimientos, mediante los medios mencionados anteriormente, por lo que se clasifica en: funcional, comportamiento, estructura y experiencia (FBSE por sus siglas en inglés). [31]


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 7. Diagrama para la arquitectura del sistema IoT. Fuente: Elaboración propia, Lucidchart.

</div>

La instalación total del sistema IoT para la ASADA de Paso Ancho y Boquerón, se proyecto para los tres tanques que la componen y se busca recopilar información hídrica del acueducto de forma automática, para luego ser publicada en una plataforma en internet de acceso con cualquier dispositivo móvil. Por lo tanto, el sistema fue diseñado para tomar información de caudal y volumen en la salida del tanque (macro medidores) con capacidad de comunicación digital. Cabe aclarar que para este proyecto los datos son supuestos, según los tomados en las pruebas realizadas en las instalaciones de la ASADA. Adicionalmente, se añadieron sensores de nivel (de presión) para supervisar el nivel del tanque. También, a los macro medidores Octave se les hizo la instalación del dispositivo como el módulo Modbus para recopilar y digitalizar la información y su posterior transferencia, mediante sistemas de comunicación inalámbrica como LoRa y MQTT.

Aunado a esto, entre los alcances del proyecto se definió el diseño de un prototipo para las condiciones de la instalación de la ASADA, con el detalle que los nodos de medición son todos iguales, por lo que solo es necesario definir la integración de uno de ellos, para que, en la futura instalación total, sea solo de calcar las condiciones específicas de la ASADA de Paso Ancho y Boquerón. En las figuras 8 y 9 se evidencia gráficamente a mayor detalle cómo se conforma la arquitectura del sistema, considerando todos los requerimientos definidos para esta.

<div align="center">

Tabla 1. Arquitectura para sistema IoT, mediante sistemas de ingeniería

</div>

<table border="1"><tr><td colspan="2">Funcional(F)</td></tr><tr><td>F1</td><td>Se debería medir los datos hídricos(nivel, volumen y caudal del tanque principal) para ser transmitidos.</td></tr><tr><td>F2</td><td>Se debería recolectar los datos hídricos digitalizados para ser interpretados y enviarlos a una plataforma de visualización.</td></tr><tr><td>F3</td><td>Se debería visualizar la información del tanque desde la distancia en el sistema de visualización.</td></tr></table>

<table border="1"><tr><td colspan="3">Comportamiento (B)</td></tr><tr><td>B1</td><td colspan="2">Se debería definir los nodos que componen el sistema y transmite la información hídrica al Gateway.</td></tr><tr><td>B2</td><td colspan="2">Gateway debería recibir la información de los nodos y la enviar vía internet a la plataforma de visualización.</td></tr><tr><td>B3</td><td colspan="2">Se debería visualizar la información hídrica recopilada en el sistema de visualización.</td></tr><tr><td colspan="3">Estructura (componentes del sistema y relación)</td></tr><tr><td colspan="3">Estructura nodo medición</td></tr><tr><td rowspan="4">N-Sn: Sensor de nivel (SN)</td><td>N-Sn1</td><td>Debería medir los niveles de agua del tanque principal.</td></tr><tr><td>N-Sn2</td><td>Debería estar conectado adecuadamente al controlador, con el transmisor de aislamiento de señal de corriente continua.</td></tr><tr><td>N-Sn3</td><td>Se podría realizar la transmisión de datos de nivel de los tanques al controlador.</td></tr><tr><td>N-Sn4</td><td>El sistema debería ser desmontable para aplicación de calibraciones.</td></tr><tr><td rowspan="4">N-M: Macro medidor de flujo Octave</td><td>N-M1</td><td>Se debería medir el caudal y volumen de salida del tanque.</td></tr><tr><td>N-M2</td><td>El macro medidor debería ser compatible al módulo Modbus.</td></tr><tr><td>N-M3</td><td>Se podría programar el módulo Modbus para acceder a la información de datos hídricos.</td></tr><tr><td>N-M4</td><td>Se debería conectar al PLC el módulo Modbus, para enviar la señal digital con los datos hídricos.</td></tr></table>

<table border="1"><tr><td rowspan="3">N-PLC: PLC M-Duino 21+LoRa</td><td>N-PLC1</td><td>Se debería recibir la señal del sensor de nivel (señal analógica).</td></tr><tr><td>N-PLC2</td><td>Se debería recibir la señal del macro medidor de flujo, vía dispositivo Modbus (señal digital).</td></tr><tr><td>N-PLC3</td><td>Se debería preparar la información hídrica del nodo para transmitir la mediante LoRa.</td></tr><tr><td rowspan="3">N-B: Sistema de potencia</td><td>N-B1</td><td>Se debería instalar el panel solar (generador de potencia).</td></tr><tr><td>N-B2</td><td>Se debería gestionar la energía y convertidor de voltaje.</td></tr><tr><td>N-B3</td><td>Batería podría almacenar la energía.</td></tr><tr><td rowspan="2">N-LoRa:ComunicaciónLoRa</td><td>N-LoRa1</td><td>Se debería transmitir información hídrica de los nodos, mediante la antena direccional.</td></tr><tr><td>N-LoRa2</td><td>Se debería recibir la información hídrica de los nodos, mediante antena omnidireccional, en la puerta de enlace</td></tr><tr><td rowspan="4">NG: Gabinete:</td><td>NG1</td><td>Se debería contener el controlador PLC M-Duino 21+LoRa</td></tr><tr><td>NG2</td><td>Se debería contener el almacenamiento de energía (batería).</td></tr><tr><td>NG3</td><td>Se debería contener el transmisor de aislamiento de señal de corriente continua.</td></tr><tr><td>NG4</td><td>Se debería localizar la antena direccional conectada al PLC.</td></tr><tr><td colspan="3">Estructura puerta de enlace (PE)</td></tr><tr><td>PE1</td><td colspan="2">Se debería recibir la información de los nodos, mediante recibidor LoRa con la antena omnidireccional.</td></tr><tr><td>PE2</td><td colspan="2">Se debería transmitir la información a la plataforma en la nube, ThingSpeak, vía WiFi.</td></tr><tr><td colspan="3">Experiencia</td></tr><tr><td>E1</td><td colspan="2">El sistema podría visualizar de la información recibida, en la plataforma</td></tr></table>

<table border="1"><tr><td></td><td>ThingSpeak, debe permitir la presentación clara de los datos recopilados.</td></tr></table>

Fuente: Elaboración propia, 2024.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 8. Arquitectura general del sistema IoT. Fuente: Elaboración propia, PowerPoint.

</div>


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 9. Arquitectura detalla del nodo del sistema IoT. Fuente: Elaboración propia, PowerPoint.

</div>

## Nodo de medición integrado

A continuación, este capítulo desarrollará cómo se integrará el nodo de medición, partiendo de la selección cuidadosa del sensor de nivel de agua y el módulo apropiado para capturar los datos del macro medidor de flujo Octave en las instalaciones de la ASADA, que se tratan respectivamente de un sensor de presión y el módulo Modbus. En este caso, se eligió previamente un controlador compatible con estos elementos para, luego, establecer la conexión física, considerando que sea compatible con lo anterior y reciba los datos, facilitando su transmisión mediante la tecnología LoRa hacia la puerta de enlace, tal y como se puede evidenciar en la Figura 10 como se encuentra conformado el capítulo.

## 5.1 Programación y conexión

Las opciones que se pueden utilizar en el ámbito de control eléctrico son variables y existen mediante el diseño y ensamble de un PCB; pero, en este caso, para mayor flexibilidad y optimización de trabajo, se adquirieron PLC M-Duino tipo LoRa para el sistema IoT; este equipo contiene la posibilidad de usar el módulo Modbus para su aplicación y comunicación mediante LoRa. Lo anterior, resulta de gran ventaja porque se adapta muy bien a las condiciones con las que se diseñó el prototipo.

La programación del prototipo se llevó a cabo mediante Arduino IDE 1.8.0 o mayor, el cual es un lenguaje tipo C, que permitirá realizar las funciones necesarias para cumplir con los objetivos planteados para el prototipo. Adicionalmente, las entradas de información que llegan al PLC son: la señal analógica de los sensores de nivel sumergibles y la digital con los datos hídricos de los macro medidores enviados mediante el módulo Modbus.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 10. Metodología para la integración del nodo de medición. Fuente: Elaboración propia, Lucidchart.

</div>

Además, la batería para energizar el equipo fue manufacturada en el Laboratorio Delta, con ciertas especificaciones para cumplir con los requerimientos según el fabricante del PLC. Los datos de esta se incluyen en el mensaje que se transmiten con la información del sistema. Para energizar el PLC, es necesario un convertidor DC/DC, serie DDR-120, el cual tiene varias

opciones de entradas: 9-18V/16.8-33.6V/33.6-67.2V/67.2-154V y opciones de salidas: 12V/24V/48V, este para convertir la tensión (corriente continua) a otra o, en este caso, para mantener los 24 V DC al PLC. [24]

## 5.1.1 Sensor de nivel (SN)

Sensor de nivel sumergible (JACTSE), posee una señal analógica tipo 4-20 mA, con un rango de medición de 0m a 5 m. Además, mide, primeramente, el nivel del tanque principal 200 m $ ^{3} $ de 500 previstas, el cual está dentro del rango de medición del sensor.

Para la conexión adecuada del sensor se sebe utilizar un transmisor de aislamiento de señal de corriente continua, modelo GLG, el cual tiene disponible una entrada y una salida respectivamente, 4-20 mA a 0-10 V. Debido a que la señal analógica que recibe el PLC es de tipo 0-10V, (ver Figura 5.7 y corresponde a la entrada 10.7, la cual va conectada a la primera salida del transmisor. Además, es posible observar cómo se energiza y se conecta la entrada del trasmisor; en este caso, se trata de un sensor de dos cables. Una vez realizada la conexión de la Figura 5.7, y mediante el código en Arduino IDE 1.8.19 completo, según las especificaciones, es posible realizar las pruebas para el sensor, presente en el anexo 9.3.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 11. Diagrama de conexión sensor de nivel. Fuente: Elaboración propia, OneNote.

</div>

## 5.1.2 Comunicación Modbus

Para la digitalización de los datos medidos por lo flujómetros Arad Octave de tipo

ultrasónico, el módulo utilizado fue el Modbus. Los flujómetros Arad son muy importantes para el proyecto, ya que la exportación de la información hídrica brindada es fundamental para el sistema IoT y su adecuado funcionamiento. Además, beneficia aquellas aplicaciones que requieren múltiples funcionalidades para controlar, la comunicación mediante Modbus resulta de gran utilidad.

Los medidores Ultrasónicos Arad Octave fueron usados para este caso en específico. Adicionalmente, el módulo Modbus se utiliza para tratar con una señal digital, donde viene recopilada la información de los macro medidores y la transmite al PLC. [9]

También, es importante considerar todas las especificaciones del fabricante, para así obtener el mejor desempeño posible, los más importantes a destacar estarian: adquirir el módulo NFC para su adecuada configuración y que los modelos de los medidores si correspondan al indicado (I4.02).

Al realizar las pruebas necesarias en las instalaciones para el módulo Modbus fue necesaria la siguiente conexión:


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 12. Diagrama de conexión, pruebas modulo Modbus. Fuente: Elaboración propia, Lucidchart.

</div>

Una vez realizadas las pruebas funcionales (anexo 9.2), los resultados fueron exitosos, se logró comprobar la adquisición de caudal y volumen en los macromedidores de flujo Arad Octave, una vez instalado el módulo Modbus con el lector NFC (solo es necesario para la programación inicial), y mediante el código en Arduino IDE para programar el PLC, se puede dar paso recopilación completa de información influyendo los niveles de agua del tanque.

## 5.1.3 Comunicación inalámbrica mediante red LoRa

El protocolo de comunicación con la red LoRa, establece que los nodos definidos están en modo de escucha y solo transmiten datos a puerta de enlace (gateway) cuando lo pide, ya que este sería el controlador. Para este protocolo es necesario definir el mensaje con la información que se transmite. Los paquetes de datos compuestos por: su contenido (mensaje) y la información relacionada con el mensaje (cantidad de carácteres en el mensaje) [9]. Long Range (LoRa) amplía los principios tradicionales de espectro para reducir la cantidad de energía que se necesita para transmitir bits a través del canal.[22]. En resumen, es necesario programar el transmisor, código en anexo 9.5, porque este enviará un contador como carga útil en paquetes LoRa a intervalos regulares, proporcionando transmitir datos de forma inalámbrica mediante tecnología LoRa.

<div align="center">

Tabla 2. Datos contenidos en el mensaje enviado.

</div>

<table border="1"><tr><td>Tamaño Byte</td><td>Contenido</td></tr><tr><td>2bytes= \xdd \x07</td><td>Header</td></tr><tr><td>1bytes= \x00</td><td>Estatus</td></tr><tr><td>2bytes</td><td>Voltaje Total(unidad de 10mV)</td></tr><tr><td>2bytes</td><td>Corriente Total(unidad de 10mAh)</td></tr><tr><td>2bytes= \x00 \x00</td><td>Estatus de Protección</td></tr><tr><td>1bytes</td><td>Porcentaje Restante(unidad de 1%)</td></tr><tr><td>1bytes</td><td>MOSFET</td></tr><tr><td>2bytes</td><td>Temperatura1(unidad de0,1K)</td></tr><tr><td>2bytes</td><td>Temperatura2(unidad de0,1K)</td></tr><tr><td>2bytes</td><td>Temperatura3(unidad de0,1K)</td></tr></table>

<table border="1"><tr><td>2 bytes</td><td>Voltaje Celda 1 (unidad de 1mV)</td></tr><tr><td>2 bytes</td><td>Voltaje Celda 2 (unidad de 1mV)</td></tr><tr><td>2 bytes</td><td>Voltaje Celda 3 (unidad de 1mV)</td></tr><tr><td>2 bytes</td><td>Voltaje Celda 4 (unidad de 1mV)</td></tr><tr><td>1 bytes = b"\x77"</td><td>ByteFinal</td></tr><tr><td>2 bytes</td><td>Checksum</td></tr><tr><td>4 bytes</td><td>Caudal (metros cúbicos/segundo)</td></tr><tr><td>4 bytes</td><td>Volumen (metros cúbicos)</td></tr><tr><td>4 bytes</td><td>Sensor de nivel (metros)</td></tr><tr><td>28 BYTES</td><td>TOTAL</td></tr></table>

Fuente: Elaboración propia, 2024.

La información es trasmitida mediante la antena direccional y se recibe con la antena omnidireccional; esta propuesta es debido a que la instalación de tanques en la ASADA está en dos localizaciones diferentes a distancias contrarias a las oficinas (El salto y Boquerón). Por lo tanto, se busca, en la futura instalación, posicionar ambas antenas direccionales, enviando la información de los nodos en una sola dirección a la puerta de enlace, lo cual se

las direcciones.

Para lo anterior, es necesario un frame, el cual es una estructura de datos, en la cual se incluye la información hídrica definida en los nodos de la arquitectura del sistema IoT. Mediante comunicación inalámbrica (LoRa) se transmiten estos datos a las puertas de enlace. Una vez que se define el mensaje (frame), donde se transmite la información hídrica, como se muestra en la Tabla 2, se pueden realizar las eventuales pruebas de la transmisión de todos los datos hídricos. La información que se busca enviar es: el caudal y volumen, medidos por el macro medidor; y el nivel del tanque, según el sensor de nivel sumergible. Además, los datos generales de la batería, como es posible evidenciar en la estructura del mensaje.

Las antenas Yagi pueden ser direccionales de alto rendimiento y funcionan mejor cuando están apuntadas directamente hacia la torre, desde la cual intentas recibir una señal. [26] El primer paso recomendado para instalarla es determinar el mejor lugar; en el caso del prototipo, se está utilizando el gabinete montado en un carrito, donde la antena está montada a un poste bajo, para realizar las pruebas con facilidad (figura 6.1). La antena direccional es apuntada hacia la omnidireccional, en la cual se recibirá el mensaje definido, con estructura de datos donde se incluye la información hídrica.

En este caso, se realizaron las pruebas (anexo 9.3y 9.4) para ambas antenas para verificar que se está transmitiendo la información de datos hídricos adquiridos y de la batería en el gabinete de control, desde la antena direccional, hacia al recibidor LoRa, mediante la antena omnidireccional. Lo anterior fue posible, por lo que los códigos para enviar y recibir la información son funcionales para la integración del sistema. Con lo anterior, ya se puede avanzar a la integración de la puerta de enlace, en donde se recibe la información de los nodos y se espera transmitir hacia un tablero de visualización de datos.

## Puerta de enlace para la recepción de datos

En este capítulo se expone cómo, para la integración de la puerta de enlace, fue necesario seguir los pasos expuestos en la siguiente imagen, implementando un código para recibir los datos transmitidos desde el nodo de medición. mediante tecnología LoRa, a donde, seguidamente, se deben enviar a la plataforma en la nube para su visualización y el respectivo análisis de información hídrica recolectada.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 13. Metodología para la puerta de enlace. Fuente: Elaboración propia, Lucidchart.

</div>

## 6.1 Implementación de Recepción de Datos en la Puerta de Enlace

Para la integración de la puerta de enlace y permitir la recepción de información de los nodos y la transmisión a la plataforma de visualización vía internet, es necesario implementar un código en la puerta de enlace, con el fin de recibir los datos transmitidos por el nodo, a través de la conexión inalámbrica (antena direccional), mediante una antena omnidireccional, la cual recibe la información desde todas las direcciones, lo que facilita la recepción de información.

El código implementa la funcionalidad de un receptor LoRa en la puerta de enlace, para esto se configuran los pines de comunicación, con la finalidad de iniciar, posteriormente, con la comunicación serial y establecer la frecuencia de operación del módulo. El bucle principal del programa espera la recepción de un paquete de datos proveniente de la antena direccional con los datos hídricos. Además, verificar si hay un paquete de datos LoRa disponible para ser analizado, al ser detectado, se procede a leer los datos recibidos y almacenarlos en un arreglo de bytes.

Cuando se recibe el paquete, se lee y se convierte en una cadena de texto hexadecimal mostrando los datos recibidos para su visualización en el monitor serial, donde se imprime la intensidad de la señal recibida (RSSI), como medida de la calidad de la conexión. En resumen, este código (anexo 9.5) establece una comunicación con el módulo LoRa, espera la recepción de datos y muestra la información recibida, incluyendo la intensidad de la señal. Por ende, es útil para probar la capacidad de recepción del módulo LoRa y verificar la calidad de la conexión. Se representa lo anterior en un diagrama de flujo seguidamente:


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 14. Diagrama de flujo para la lógica de recepción de datos en la puerta de enlace. Fuente: Elaboración propia, PowerPoint.

</div>

## 6.2 Procesamiento de datos en la puerta de enlace antes de la transmisión a la nube

En este sentido, es necesario implementar una lógica adicional en la puerta de enlace para procesar los datos recibidos del nodo de medición. Este código específico se encarga de recibir datos de un dispositivo LoRa, a través de una conexión serie y almacenarlos en un archivo CSV. El anterior está disponible en el repositorio del laboratorio delta, anexo 9.5. Para lograr esto, se realizan los siguientes pasos:

## 6.2.1 Definir la ruda del directorio y configuración de la

## comunicación en serie

Se define la ruta del directorio donde se guardarán los archivos CSV para facilitar el acceso y organización de los datos. Además, la comunicación serie se establece utilizando la biblioteca serial para conectar con el dispositivo LoRa. Seguidamente, se especifica el puerto COM y la velocidad de comunicación para asegurar una conexión estable.

## 6.2.2 Bucle principal para recepcion y procesamiento de datos

El programa ejecuta un bucle principal que opera de manera continua para recibir y

procesar los datos provenientes del dispositivo LoRa. Después, se lee una línea de datos desde el puerto serie y se decodifica para su posterior procesamiento. A partir de los datos recibidos, se estructura esta información en una lista para su posterior almacenamiento y se incorpora un mecanismo para manejar excepciones que puedan surgir durante la ejecución del programa. En la siguiente imagen se representa la lógica de lo anterior mediante un diagrama de flujo.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 15. Diagrama de flujo para la lógica de procesamiento de datos en la puerta de enlace. Fuente: Elaboración propia, PowerPoint.

</div>

Al realizar las pruebas (anexo 9.3), para asegurar que la puerta de enlace está recibiendo la información de nodo de medición, para su posterior transmisión hacia la plataforma en la nube fue necesario realizar la construcción física de la puerta de enlace, donde fue posible verificar. Por lo que las pruebas finales realizadas, fueron una vez que estaba el prototipo con todas sus partes. Las pruebas fueron llevadas a cabo, en la escuela de Mantenimiento Industrial en el tanque de almacenamiento en el ala Sur, donde se instala el sensor de nivel.

Es necesario realizar la debida preparación del entorno, por lo que se debe asegurar que todos los componentes están correctamente conectados y que el equipo este debidamente

alimentado. Al iniciar el sistema y se realiza la transmisión de datos desde el PLC, y se envía el mensaje desde el nodo hacia la puerta de enlace ubicada en el laboratorio Delta.

La información recopilada para el nivel del tanque se recibió con éxito, en el caso del caudal y volumen a no existir un macro medidor de flujo Octave que cumpla con las especificaciones, los datos hídricos utilizados fueron en base a los recopilados en las pruebas realizadas para el módulo Modbus en las instalaciones de la ASADA.

Finalmente se inicia con la transmisión de datos a la nube, ThingSpeak, para poder visualizar los datos tomados, para este se realiza la configuración para el protocolo de comunicación debido.

## 6.3 Configuración del protocolo de comunicación para la transmisión de datos hacia la plataforma ThingSpeak, desde la puerta de enlace

Para la transmisión de información de los datos hídricos recopilados es necesario configurar el protocolo de comunicación WiFi, para ser enviados desde la puerta de enlace y puedan ser visualizados en la plataforma en la nube ThingSpeak. La programación del código tiene como objetivo enviar datos a la plataforma en la nube, incluyendo las librerías necesarias para la gestión de la conexión WiFi y la comunicación con ThingSpeak. Para ello, se define el nombre y la contraseña de la red a la que conectará, así como la clave de escritura API de ThingSpeak y el número de canal al que se enviarán los datos.

Para el código (anexo 9.5), se inicializan variables clave, como: un objeto cliente WiFi, para establecer la conexión; una variable para almacenar el tiempo del último envío de datos y un intervalo de tiempo entre cada transmisión. Además, se definen variables para los datos que se enviarán y otra para registrar posibles errores de ThingSpeak. En la configuración

inicial del programa, se inicia la comunicación serial y se establece el modo de WiFi como estación (cliente) para iniciar la comunicación con la plataforma En la imagen a continuación se presenta con un diagrama de flujo para la transmisión de datos a la nube.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 16. Diagrama de flujo para el protocolo de comunicación para la transmisión de datos hacia la plataforma en la nube.

Fuente: Elaboración propia, PowerPoint.

</div>

Adicionalmente, en el bucle principal, se verifica si ha pasado el tiempo especificado desde el último envío de datos. En caso afirmativo, se intenta conectar a la red WiFi indicada. Una vez conectado, se generan los datos y se envían a ThingSpeak. Posteriormente, se comprueba si la operación fue exitosa y, en caso de que suceda, se muestra un mensaje confirmando la actualización del canal. De lo contrario, se informa sobre cualquier problema que haya surgido durante el envío de datos. El bucle se repite continuamente, asegurándose de verificar periódicamente si es el momento de enviar los datos nuevamente, según el intervalo establecido.

En resumen, este código facilita la conexión WiFi, la generación y el envío de datos hacia ThingSpeak para su almacenamiento y visualización. Siempre se asegura de mantener la conexión WiFi y de gestionar adecuadamente cualquier error que pueda surgir durante el

proceso de envío de datos. El siguiente capítulo, permite visualizar una vez que se hace la transmisión de datos desde la puerta de enlace hasta la plataforma en la nube va WiFi, después de realizar las pruebas del sistema completo.

<div align="center">

# Visualización para análisis de datos

</div>

En este capítulo se presentará un tablero de visualización que permita presentar y analizar la información recopilada por el sistema en la plataforma en la nube, ThingSpeak. Para esto, es necesario realizar las pruebas integrales del sistema para asegurarse que todo el sistema funcione en conjunto y verificar que los datos están fluyendo de manera continua desde el nodo hacía la plataforma en la nube a través de la puerta de enlace.

## 7.1 Funcionalidades de la plataforma de visualización

La plataforma ThingSpeak fue seleccionada para presentar los datos recolectados en la nube, debido a que esta proporciona una interfaz de fácil utilidad y permite a los usuarios crear canales de datos, visualizar y analizar datos en tiempo real. Además, es compatible con una amplia variedad de dispositivos y protocolos IoT. En este sentido, una de las funciones que resulta útilesla capacidad de agregar gráficos personalizados. Al proporcionar una API robusta, es posible enviar y recibir datos de forma programática, facilitando la integración con toros sistemas y servicios.

Una vez que se define que la plataforma ThingSpeak, se seleccionan los datos necesarios para presentar para su visualización gráfica. Entre los datos seleccionados se encuentran: voltaje general y de celdas de la batería, el caudal y volumen recopilados del macro medidor de flujo Octave, la altura según el sensor de nivel, y la intensidad de la señal (RSSI).

Finalmente, lo que se espera de esta sección es poder realizar un monitoreo y registro de los resultados. Además, lograr un análisis de los resultados, para mejorar el rendimiento y confiabilidad del sistema, así como identificar cualquier anomalía o área de mejora. Por lo tanto, el tablero de visualización en la plataforma ThingSpeak debe ser ordenado y presentar la información de manera clara y completa para la comprensión de los usuarios, específicamente, los de la ASADA.

Mediante la prueba final (anexo 9.3), fue posible implementar la manera para visualizar los datos recopilados según el prototipo construido, cabe recalcar que la información de la batería fue recopilada durante las pruebas de las antenas para la transmisión de datos desde el nodo de medición. En el caso del volumen y caudal, se definieron valores aleatorios, según los antecedentes de las pruebas llevadas en las instalaciones de la ASADA, ya que en esta se encuentra en micromedidor compatible con el módulo Modbus. El caso del nivel de agua se analizó mediante los hallazgos recopilados para el tanque en la Escuela de Electromecánica. A continuación, se presenta las gráficas representativas de los datos recopilados en la plataforma ThingSpeak (anexo 9.5).


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 17. Gráfica del voltaje general (V) en función de del tiempo (date). Fuente: Elaboración propia, ThingSpeak.

</div>




> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 18. Gráfica Voltaje de celda (V) en función del tiempo (date). Fuente: Elaboración propia, ThingSpeak.

</div>


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 19. Gráfica caudal (m3/h) en función del tiempo (date). Fuente: Elaboración propia, ThingSpeak.

</div>




> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 20. Gráfica Volumen (m3) en función del tiempo (date). Fuente: Elaboración propia, ThingSpeak.

</div>


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 21. Gráfica nivel del agua (m) en función del tiempo (date). Fuente: Elaboración propia, ThingSpeak.

</div>




> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 22. La intensidad de la señal (dBm) en función del tiempo (date). Fuente: Elaboración propia, ThingSpeak.

</div>

Los resultados presentados se tratan de las representaciones gráficas visualizadas en la plataforma ThingSpeak de los datos recopilados en las pruebas de funcionamiento, estas contienen 1107 entradas de datos. El caso del voltaje general y el voltaje de celda es posible evidenciar la descarga de la batería con el paso del tiempo. Para el caudal y volumen, se definen valores supuestos según las mediciones realizadas en los macromedidores de la ASADA, el caudal estaba entre 32 y 48 metros cúbicos por hora, mientras que el volumen 10 000/50 000 metros cúbicos, por lo tanto, fue posible observar el comportamiento de ambos bajo estos valores. El caso de la altura indica que el tanque estaba con un nivel de agua de 0.80 m y se mantiene contante en las mediciones realizadas.

Capítulo 8

## Conclusiones

En primer lugar, se diseñó y construyó con éxito un prototipo para la recopilación de datos, en donde al trabajar todas sus partes de forma simultánea, conforman un sistema de comunicación (Internet de las cosas), basado en una red LoR, que permite la supervisión remota, del nivel de agua y de los macromedidores de flujo del tanque principal en la ASADA de Paso Ancho y Boquerón. Dicho sistema posee la capacidad de intercomunicación de datos hídricos en tiempo real y la visualización de información en la plataforma en internet.

En segundo lugar, la generación detallada de la arquitectura del sistema fue ejecutada con éxito. En este aspecto, se ha logrado una estructura bien definida y fácil de comprender, que abarcó la selección de sensores, dispositivos de comunicación, las partes del nodo de medición, puerta de enlace y la plataforma de visualización. Al cumplir con los requisitos específicos del proyecto, se completó el desarrollo e implementación del sistema IoT de recopilación de datos.

En tercer lugar, el nodo de medición se implementó y verificó con éxito, según los requerimientos establecidos para la transmisión de información hacia la puerta de enlace. La integración de el sensor de nivel, el módulo Modbus para los macromedidores de flujo, el controlador y los sistemas de comunicación inalámbrica, se instalaron de manera eficiente asegurando la adquisición confiable de datos.

En cuarto lugar, la puerta de enlace demostró ser funcional y eficiente en la recepción de datos hídricos recopilados en el nodo de medición y en su posterior transmisión a un servidor en la nube. La configuración, programación y selección adecuada del sistema de

comunicación LoRa para la recepción de la información, ha garantizado una transmisión y recepción confiable de datos en todo momento.

Finalmente, la plataforma de visualización en la nube, ThingSpeak, proporcionó una interfaz clara y accesible para monitorear y analizar la información recopilada por el prototipo del sistema IoT. Las gráficas visualizadas garantizan que los datos se presentan de una manera efectiva facilitando su análisis respectivo. Además, se llevaron a cabo pruebas exhaustivas de verificación y validación en cada etapa del proyecto, garantizando el funcionamiento correcto y confiable del sistema en condiciones supuestas.

## 8.1 Recomendaciones relacionadas a la instalación en la

## ASADA Paso Ancho y Boquerón.

Se recomienda que, para realizar la propuesta de diseño para la instalación en los tres tanques de la ASADA de Paso Ancho y Boquerón, como fue solicitado, se deben seguir las siguientes consideraciones:

Primeramente, considerar el modelo de los macromedidores de flujo Octave, que, para poder adquirir los datos hídricos recopilados, es necesario realizar la instalación del dispositivo Modbus. Para lograr esto, el modelo debe ser 4.02 en adelante; por lo tanto, la adquisición de estos macromedidores es esencial. Seguidamente, para la instalación de los sensores de nivel, es importante realizar los ajustes necesarios en los tanques para poder colocarlos de manera que permita recopilar la información mediante el nodo de medición.

Finalmente, para la transmisión de datos desde el nodo de medición, en los tanques, hacia la puerta de enlace, en las oficinas de la ASADA, es necesario, generar una propuesta de instalación del gabinete de control, junto al poste, donde se coloca el panel solar y la antena direccional. Detallando que, durante las pruebas, no fue necesario apuntar la antena

direccional, exactamente hacia donde estaba la omnidireccional para lograr la recepcion de datos hídricos.

## Bibliografía

[1] Zoran Kapelan, Weisbord Emma, and Vladan Babovic. Artificial intelligence solutions for the water sector. Digital Water - International Water Association, 2020.

[2] Héctor Paniagua Alfaro and Natalia Rodríguez Alfaro. Guía de Gestión Integral de Riesgos para ASADAS (GIRA). Programa de Naciones Unidas para el Desarrollo, Costa Rica (PNUD-Costa Rica), 2019.

[3] Seylin Elizondo, Vanessa Gómez, Sylvia Ramírez, Jennifer Ramírez, and Wander Cubero. Análisis Prospectivo del Sector de Agua Potable y Saneamiento de Costa Rica al año 2040. Facultad de Ciencias Económicas, Universiad de Costa Rica, San José, Costa Rica, 2015.

[4] AyA. Anuario estadístico 2012-2018. Technical report, Dirección de Planificación, 2019.

[5] Erin Ress and J. Allan Roberson. The financial and policy implications of water loss. Journal - American Water Works Association, pages E77-E86, 2016.

[6] AyA. Aya establece ruta para reducir agua no contabilizada, Sep 18, 2020.

[7] Water Partnership. Digital water; capitalising on the commercial opportunities for uk plc. Technical report, 2020.

[8] Monge-Rojas, V. (2022). Diseño de un sistema IoT de recolección de datos en tiempo real mediante una red tipo mesh para el control de la calidad del agua y el agua no contabilizada en el acueducto del Parque Industrial Zeta de Cartago [Trabajo final de graduación, Instituto Tecnológico de Costa Rica]. Repositorio TEC.

[9] Solorzano-Alfaro, S. (2021). Sistema de control y monitoreo hídrico, basado en LoRaWAN $ ^{\mathrm{TM}} $ , para el acueducto principal de la Asociación Administradora del Acueducto Rural de Playa Sámara de Nicoya. [Trabajo final de graduación,

Instituto Tecnológico de Costa Rica]. Repositorio TEC.https://hdl.handle.net/2238/13234

[10] George A. Kunkel, American Water Works Association, and AWWA (American Water Works Association). M36 Water Audits and Loss Control Programs. American Water Works Association, Denver, CO, 2016. American Water Works Association, «Key Performance Indicators for Non-Revenue

[11] Water. AWWA Water Loss Control Committee Report, » Noviembre 2019. [En Iínea]

Available:

https://www.awwa.org/Portals/0/AWWA/ETS/Resources/WLCCKPIReport%2020

19.pdf?ver=2019-11-20-094638-933. [Último acceso: 2022 Marzo 2022].

[12] LoRaAlliance. A technical overview of lora $ ^{\circledR} $ and lorawan $ ^{\mathrm{T M}} $ . Technical Marketing Workgroup 1.0, 2015.

[13] K. Rose, S. Eldridge y L. Chapin, «La Internet de las cosas - Una breve reseña,» The Internet Society (ISOC), 2015. [En línea]. Available: https://www.internetsociety.org/wp-content/uploads/2017/09/reportInternetOfThings-20160817-es-1.pdf. [Último acceso: 1 Octubre 2022].

[14] Dirección de agua. (2023). ASADAS.

https://da.go.cr/asadas/#:~:text=Las%20Asociaciones%20administradoras%20de%20los,de%20la%20Ley%20de%20Asociaciones.

[15] Gaviria-Montoya L; Pino-Gómez M, Soto-Córdoba S. (2016). EVALUACIÓN DE LA GESTIÓN DE LA ASADA DE PASO ANCHO Y BOQUERON, CIPRESES, OREAMUNO, DESDE UNA PERSPECTIVA DEL USO SOSTENIBLE DEL RECURSO HÍDRICO. Cartago.

[16] Octave. (2022). Modbus Reference. https://docs.octave.dev/docs/modbus-reference

[17] Markus Kröll, M., Christian Cseh, C. (2023). Implementation Model for Digital Retrofit for Sustainable Production. EL SEVIER, Volumen (217), 1- 9.https://doi.org/10.1016/j.procs.2022.12.244

[18] Marcon, E., Le Dain M., & Frank. A. (2022). Designing business models for Industry 4.0 technologies provision: Changes in business dimensions through digital transformation. EL SEVIER, volumen (185), 1-15. https://doi.org/10.1016/j.techfore.2022.122078 [19] Verdugo-German, J. (2017). Detección de ataques en sistemas ciber físicos. [Maestría en Ciencias en Electrónica y Telecomunicaciones con orientación en Instrumentación y Control, CICESE]. Repositorio Institucional. https://cicese.repositorioinstitucional.mx/jspui/bitstream/1007/3039/1/Tesis_Versión_Final_Eduardo_22_nov_2019.pdf

[20] Controlaría general de la república, «Informe sobre la auditoría operativa acerca de la eficiencia y eficiencia del Instituto Costarricense de Acueductos y Alcantarillados para garantizar la prestación del servicio de abastecimiento de agua potable.

Informe Nro. DFOE-AE-IF-08-2012,» Área de servicios ambientales y de energía, Noviembre 2012. [En línea]. Available:

https://cgrfiles.cgr.go.cr/publico/docs_cgr/2012/SIGYD_D_2012022464.pdf.

[Último acceso: 31 Marzo 2022].

[21] ARAD GROUP (2020). Installation Manual OCTAVE Ultrasonic Water Meters. OCTAVE-Installation-Manual-UK-01-2021.pdf (arad.co.il)

[22] Ertürk, M. A, Aydin, M. A, Büyükakkaslar, M. T., & Hayrettin Evirgen, H. (2019). A Survey on LoRaWAN Architecture Protocol and Technologies. Future Internet, 11, 216; doi:10.3390/fi11100216

[23] Monachesi, E., Frenzel, A. M., Chaile, G., Agustín, C., & López, F. A. G. (2011).

Conceptos generales de Antenas. Recuperado de: http://www. edutecne. utn. edu. ar/wlan_frt/antenas. pdf, 20.

[24] MEAN WELL (2018) 120W DIN Rail Type DC-DC Converter. DDR-120B-24 pdf, DDR-120B-24 Description, DDR-120B-24 Datasheet, DDR-120B-24 view ::: ALLDATASHEET ::::

[25] Industrial Shields (2020) M-DUINO PLC ARDUINO ETHERNET & LORA 21 I/Os ANALOG/DIGITAL PLUS USER GUIDE. M-Duino_21+_LoRa_User_Guide.pdf

[26] AlternativeWireless (2023) Installing A Yagi Antenna. https://www.alternativewireless.com/cellular-antennas/yagiantennas/installing-yagi cellular antenna.html#:~:text=Point%20the%20main%20center%20beam,strength%20reading%20from%20the%20phone.

[27] Mora D., Portuguez C. (2021). AGUA PARA CONSUMO HUMANO Y SANEAMIENTO EN COSTA RICA AL 2020: BRECHAS EN TIEMPOS DE PANDEMIA. Technical report, Laboratorio de Aguas - AyA, 2018.

[28] Soto-Córdoba, S. M., Gaviria-Montoya, L., & Pino-Gómez, M. (2016). Situación de la gestión del agua potable en las zonas rurales de la provincia de Cartago, Costa Rica. Revista Tecnología en Marcha, 29, 67-76.

[29] FAO. Perfil de país - costa rica. Technical report, AQUASTAT, Organizacion de las Naciones Unidas para la Alimentacion y la Agricultura, 2015.

[30] Banco Interamericano de Desarrollo. De estructuras a servicios: el camino a una mejor infraestructura en américa latina y el caribe, ed. en español. 2020.

[31] Jimenez, J. J., Vingerhoeds, R. (2019). A System Engineering Approach to Predictive Maintenance Systems: from need and desires to logical architecture.

[32] Roques, P. (2018). Systems Architecture Modeling with the Arcadia Method. (1st) ISTE Press y Elsevier.

## Anexos

## 9.1 Plano Gabinete de Control


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

9. 2 Informe pruebas comunicación Modbus

</div>

Descripción:

Para la digitalización de los datos medidos por lo flujómetros Arad Octave, de tipo ultrasónico, el módulo utilizado fue el Modbus. Los flujómetros Arad son muy importantes para el proyecto, ya que la exportación de la información hídrica brindada por ellos es fundamental para el sistema IoT y su adecuado funcionamiento. Aquellas aplicaciones que requieren múltiples funcionalidades para controlar, la comunicación mediante Modbus resulta de gran utilidad.

La instalación de la red sería en todos los tanques que componen la ASADA de Paso Ancho y Boquerón, con la ventaja que los nodos definidos son los mismos. Para este proyecto, lo esencial es la construcción de un prototipo, el cual, una vez funcionando, solo se debe replicar para cada tanque. Además, se busca recopilar información hídrica del acueducto de forma automática, para luego ser publicada en una plataforma en internet de acceso con cualquier dispositivo móvil.

Los medidores Ultrasónicos Arad Octave, tienen distintas opciones de salidas eléctricas para comunicación: doble salida de impulsos (digital) para los volúmenes, salida analógica (4-20mA) para rangos de flujo, y salidas Modbus y M-Bus para aplicaciones que requieran múltiples funcionalidades para controlar. Para este caso, el módulo Modbus en específico se trata de una señal digital, en la cual viene recopilada la información de los macromedidores y la transmite al PLC. [9] En cuanto al módulo Modbus, para su adecuada aplicación, fue necesario seguir una serie de pasos que corresponden a los requerimientos del fabricante para el adecuado funcionamiento.

Requerimientos:

- Verificar que la versión de los macro medidores sea I4.02 o superior, según el número

de serie proporcionado por el fabricante.

- Adquirir el módulo NFC o RS232 necesario para configurar el medidor. La configuración inicial permite el uso de un código personalizado, lo que implica la programación del medidor para habilitar la funcionalidad Modbus.

- Obtener el software Arad Smart Meters, este software se utiliza para la programación inicial y, a partir de ahí, se puede utilizar el módulo Modbus.

- Instalar el módulo Modbus en el Octave.

- Programar el módulo Modbus, mediante Smart Meters y el NFC Reader.

- Editar el archivo de Arduino con los comandos que se desean enviar.

- Programar el PLC con el código

- Conectar el PLC y el módulo Modbus

- Conectar el PLC a la laptop para imprimir los valores leídos.

Para las pruebas realizadas en los macro medidores del tanque principal en la ASADA de Paso Ancho y Boquerón, fueron necesarios una serie de materiales esenciales para efectuarlas.

Materiales:

- Laptop

-PLC

-NFC Reader.

-Modulo Modbus con cable y 2 tuercas Allen.

Procedimiento:

Al desplazarse a las facilidades, de antemano, fue necesario verificar que se contaban con las versiones adecuadas de Smart Meters para la configuración inicial y que el código en Arduino IDE funcionara correctamente, ubicado en el anexo 9.5. El diagrama de conexión es el de la Figura 12.

Una vez instalado el módulo Modbus al sensor ultrasónico Octave, el siguiente paso fue utilizar el lector NFC (solo es necesario para la programación inicial); este debe estar a menos de 5 cm del macro medidor para que funcione correctamente, la contraseña de Smart Meters es: arad1941. Una vez realizada la conexión del PLC con el módulo (figura 5.7), se pruebó el código en Arduino IDE para los comandos que se deseaban enviar, el primero fue el número de serie del macromedidor.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 23. Pruebas realizadas en las instalaciones de la ASADA. Fuente: Elaboración propia.

</div>

## Resultados:

De primera mano la prueba no funcionó, no se estaba enviando el mensaje, esto a un probable fallo de hardware. Por lo tanto, se recurrió a pruebas más primitivas mediante un adaptador RS485 y RealTerm, donde se solicita el número de serie del Octave.

Esta prueba fue exitosa; por lo tanto, posteriormente, se consiguieron los datos hídricos medidos por el macro medidor, como el caudal y el volumen. Una vez obtenido este

resultado, se vuelve al código en Arduino IDE para programar el PLC, el cual respondió adecuadamente.

## 9.3 Informe de pruebas finales

Descripción:

Para realizar las pruebas finales del sistema completo, se trasladó el nodo de medición al ala sur de la Escuela, donde se realiza la instalación del sensor de nivel en el tanque, es importante asegurarse de que todos los dispositivos LoRa, el PLC y la puerta de enlace, estén correctamente instalados y configurados para el contexto de la prueba, así como que estén bien alimentados y conectados según las especificaciones.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 24. Nodo de medición con sensor de nivel instalado en el tanque. Fuente: Elaboración propia.

</div>

Procedimiento:

Para el inicio del sistema se deben encender todos los dispositivos y espera a que se inicien correctamente, para, seguidamente, empezar con la transmisión de datos desde el PLC a través de LoRa hacia la puerta de enlace, verificando, al mismo tiempo, que los datos se estén transmitiendo correctamente y que la puerta de enlace los esté recibiendo sin problemas.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 25. Nodo de medición encendido. Fuente: Elaboración propia.

</div>

Adicionalmente, es necesario confirmar que hay un procesamiento de datos en la puerta de enlace donde se esté procesando los datos recibidos mediante tecnología LoRa correctamente y preparándolos para su transmisión a través de WiFi. Además, verifica que los datos procesados sean precisos y estén formateados adecuadamente para su envío a la plataforma en la nube.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 26. Recepción de datos desde el PLC para ser transmitidos hacia la puerta de enlace. Fuente: Elaboración propia.

</div>

Para la transmisión de datos a la plataforma en la nube se debe verificar que la puerta de enlace la realiza a través de WiFi. Además, se debe confirmar que los datos se estén recibiendo correctamente en la plataforma en la nube y que estén siendo registrados según lo esperado.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 27. Transmisión de datos desde la puerta de enlace a la nube. Fuente: Elaboración propia.

</div>

## Resultados:

Una vez que se verifica que los datos estén fluyendo de manera continua desde el PLC hasta la plataforma en la nube, a través de la puerta de enlace, se debe monitorear el sistema durante las pruebas para detectar cualquier anomalía o problema. Si lo anterior se logra con éxito, es posible hacer el envío de datos hacia la plataforma en la nube: registrando los resultados de las pruebas, incluyendo cualquier error encontrado y las acciones tomadas para resolverlo. Finalmente, se permite analizar los resultados de las pruebas y realizar los ajustes necesarios para mejorar el rendimiento y la confiabilidad del sistema.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 28. Visualización de datos en la plataforma ThingSpeak. Fuente: Elaboración propia.

</div>

## 9.4 Procedimiento Construcción Nodo medición.

Para la construcción del prototipo se utilizó una estructura móvil, de proyectos pasados, que se encontraba disponible en el Laboratorio Delta, para mayor facilidad de movilidad (Figura 24) y realizar las pruebas más ágilmente. Este tenía instalado un gabinete HOFFMAN serie GL66 600x400 mm, por lo que se realiza el diseño del montaje de control eléctrico en él, todos los equipos fueron montados al riel din 35mm, con gavetas de plástico, el plano del fondo falso para el gabinete, que se encuentra en el anexo 9.1.

Seguidamente, se realizó la construcción de la batería en el Laboratorio Delta, la cual se carga mediante el panel solar que tenía ya instalado el carrito. Además, se instaló al riel din, para realizar la conexión necesaria y lograr la energización del PLC y el transmisor de aislamiento.

## Resultados:

Una vez realizado el montaje físico del diseño propuesto, fue necesario integrar un fusible para el PLC para mayor facilidad de conexión y desconexión de la batería. Finalmente, una vez montada la antena al poste, fue necesario ponerle un adaptador para conectarla a la entrada del PLC, resultados en las figuras 29 y 30.


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 29. Construcción completa interior gabinete. Fuente: Elaboración propia.

</div>


> **Figure Description:**

[Descripción de figura no disponible: error al generar la descripción.]



<div align="center">

Figura 30. Construcción completa nodo medición. Fuente: Elaboración propia.

</div>

## 9.5 Códigos para el sistema IoT.

Los programas incorporados en este proyecto están disponibles para el público en general a través del repositorio del Laboratorio Delta en la plataforma GitHub.

Además, se pueden observar a destalle los códigos principales a las partes del sistema, donde se permite ingresar al código directamente o revisarlo en general por medio del repositorio.

9. 5.1 Transmisión datos del nodo hacia puerta de enlace

9. 5.2 Receptor de datos hídricos en la puerta de enlace

9. 5.3 Transmisor a plataforma ThingSpeak.

9. 5.4 Visualización ThingSpeak.

## Apéndices

<div align="center">

# 10.1 Hojas de datos e informacion de equipos

</div>

Octave: Medidor de agua ultrasónico

Módulo Modbus SRS

PLC M-Duino 21+LoRa

Transmisor de aislamiento GLG

Convertidor DC/DC, serie DDR-120

Batería

Gabinete HOFFMAN

Sensor de nivel ultrasónico

Antena direccional Yagi

Antena omnidireccional Yagi