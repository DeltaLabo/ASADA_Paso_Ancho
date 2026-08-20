---
source: "Tecnologia_en_Marcha/TFSC1663_312409_TFG_ELEC_Chavarría-Castro, Yostin Josue_2021.pdf"
title: "Implementación de un sistema prototipo para el monitoreo de la variación de nivel de líquido, en una ASADA ubicada en la comunidad de las Juntas de Abangares."
author: "Yostin Josue Chavarría Castro"
converted_at: "2026-08-20T17:14:47Z"
conversion_note: "PDF de 152 páginas convertido en 4 partes por el límite de 100 páginas del servicio OCR; algunas descripciones de figuras no estuvieron disponibles."
---

<!-- Páginas 1-40 -->

Tecnológico de Costa Rica

Escuela de Ingeniería Electrónica

Programa de Licenciatura en Ingeniería Electrónica

TEC

Tecnológico

de Costa Rica

<div align="center">

# Implementación de un sistema prototipo para el monitoreo de la variación de nivel de líquido, en una ASADA ubicada en la comunidad de las Juntas de Abangares.

</div>

<div align="center">

# Informe de Trabajo Final de Graduación para optar por el título de

Ingeniero en Electrónica con el grado académico de Licenciatura

</div>

Yostin Josue Chavarría Castro

San Carlos, 26 de agosto de 2021

Declaro que el presente documento de tesis ha sido realizado enteramente por mi persona, utilizando y aplicando literatura referente al tema e introduciendo conocimientos y resultados experimentales propios.

En los casos en que he utilizado bibliografía he procedido a indicar las fuentes mediante las respectivas citas bibliográficas. En consecuencia, asumo la responsabilidad total por el trabajo de tesis realizado y por el contenido del presente documento.


> **Descripción de figura no disponible.**

Yostin Josue Chavarría Castro

San Carlos, 26 de agosto de 2021

Ced:1-1627-0453

Instituto Tecnológico de Costa Rica Escuela de Ingeniería Electrónica Proyecto de Graduación Acta de Aprobación

<div align="center">

# Defensa de Proyecto de Graduación

Requisito para optar por el título de Ingeniero en Electrónica

Grado Académico de Licenciatura

</div>

El Tribunal Evaluador aprueba la defensa del proyecto de graduación denominado Implementación de un sistema prototipo para el monitoreo de la variación de nivel de líquido, en una ASADA ubicada en la comunidad de las Juntas de Abangares., realizado por el señor Yostin Josue Chavarría Castro y, hace constar que cumple con las normas establecidas por la Escuela de Ingeniería Electrónica del Instituto Tecnológico de Costa Rica.

Miembros del Tribunal Evaluador

LUIS DIEGO GOMEZ Firmado digitalmente por

RODRIGUEZ LUIS DIEGO GOMEZ

(FIRMA) RODRIGUEZ (FIRMA)

Fecha: 2021.08.25

19:25:14 -06'00'

JAVIER RIVERA ALVARADO (FIRMA)

Firmado digitalmente por JAVIER RIVERA ALVARADO (FIRMA)

Ing. Luis Diego Gomez Rodriguez Profesor Lector

M. Sc. Javier Rivera Alvarado Profesor Lector

PABLO CESAR

RODRIGUEZ

VARGAS (FIRMA

Firmado digitalmente por

PABLO CESAR RODRIGUEZ

VARGAS (FIRMA)

Ing. Pablo Cesar Rodriguez Vargas Profesor Asesor

San Carlos, 26 de agosto de 2021

## Resumen

El Centro de Investigación y Estudio para el Desarrollo Sostenible (CIEDES) realiza diferentes estudios en la ASADA ubicada en las Juntas de Abangares, con el propósito de mejorar la administración de la ASADA. Para realizar estos estudios el CIEDES necesita de grandes cantidades de información para realizar un balance hídrico, este balance permite conocer todas las variables que intervienen en el manejo del agua, por lo que es necesario datos como temperatura, caudal, precipitación, turbidez, nivel de líquido en el tanque entre otros. Al conocer el nivel de líquido en el tanque se puede crear un modelo el cual permita conocer la demanda de la comunidad y la capacidad de la ASADA de suministrar dicha demanda. El proceso de recolección de datos de nivel de líquido en la asada es puntual, esto quiere decir que una persona se dirige al tanque de almacenamiento y toma el dato de nivel con una escala donde posteriormente se anota en un librete, este tipo de medición no permite evaluar cambios diarios por lo que construir un modelo no es posible. El presente proyecto tiene como objetivo mejorar la toma de datos de nivel de líquido en el tanque de captación y almacenamiento de agua con el fin de eliminar la medición puntual. El sistema diseñado toma el dato por medio de un sensor el cual mide la altura y se transmite el dato por medio de un módulo SIM utilizando protocolo HTTP, además se implementa un sistema de visualización de datos que permite realizar consultas y descargas de los datos tomados. El sistema diseñado también cuenta con sistema de captación de energía, de esta forma el sistema funciona autónomamente.

Palabras clave: Autonomía, protocolo HTTP, visualización datos, ASADA, tanque de almacenamiento.

## Abstract

The Centro de Investigacion y Estudio para el Desarrollo Sostenible (CIEDES) carries out different studies at the ASADA located in the Juntas de Abangares, with the purpose of improving the administration of the ASADA. To perform these studies, CIEDES needs large amounts of information to carry out a water balance, this balance allows knowing all the variables that intervene in water management, therefore data such as temperature, flow, precipitation, turbidity, level of water are necessary, liquid in the tank among others. By knowing the level of liquid in the tank, a model can be created which allows to know the demand of the community and the capacity of the ASADA to supply such demand. The liquid level data collection process in the ASADA is punctual, this means that a person goes to the storage tank and takes the level data with a scale where it is subsequently noted in a booklet, this type of measurement does not allows to evaluate daily changes so building a model is not possible. The present project aims to improve the data collection of liquid level in the water collection and storage tank in order to eliminate punctual measurement. The designed system takes the data through a sensor which measures the height and transmits the data through a SIM module using HTTP protocol, in addition a data visualization system is implemented that allows queries and downloads of the data taken. The designed system also has an energy harvesting system, in this way the system works autonomously.

Keywords: Autonomy, HTTP protocol, data visualization, ASADA, storage tank.

## Dedicatoria

El presente proyecto esta dedicado a mi padre José Alberto y mi madre María Cecilia. Ellos siempre me han ayudado y apoyado incondicionalmente durante toda mi vida. En cada etapa de crecimiento personal y profesional siempre han estado ahí para brindarme consejos y fuerzas para seguir adelante y luchar por los sueños. Todo lo que soy se lo debo a ellos y en esta etapa profesional les dedico un logro con el que podemos celebrar y compartir todos como familia. Gracias por siempre creer y confiar en mi persona.

También a mis hermanos y sobrinos quienes siempre me han apoyado y dado fuerzas para seguir adelante, este logro lo comparto y lo celebro con todos mis seres queridos.

<div align="center">

# Agradecimientos

</div>

Primero que todo agradecer a mi familia por el apoyo incondicional, por sacar siempre la mejor versión de mí y todas aquellas personas que me ayudaron a crecer profesionalmente.

A los profesores del TEC por ayudarme en el proceso de aprendizaje y todos aquellos funcionarios que desempeñan diferentes papeles y que hacen del TEC una institución muy prestigiosa.

A Don Edwin del CIEDES el cual confió en mí para llevar a cabo el desarrollo del proyecto. Un especial agradecimiento al Ing. Mauricio por apoyarme y aconsejarme de manera desinteresada durante la realización del proyecto.

A mis amigos y compañeros del TEC quienes hicieron de esta etapa una experiencia increible. Un agradecimiento especial al Ing. Daniel Chavarría y al Ing. Ricardo Vargas quienes me ayudaron y brindaron de manera desinteresada en el desarrollo de este proyecto.

Yostin Josue Chavarría Castro

San Carlos, 26 de agosto de 2021

## Indice general

Índice de figuras IV

Índice de tablas VII

1. Introducción 1

1.1. Problema existente e importancia de su solución 2

1.2. Solución Seleccionada 4

2. Meta y objetivos 7

2.1. Meta 7

2.2. Objetivo general 7

2.3. Objetivos específicos 8

3. Marco teórico 9

3.1. Protocolo TCP/IP 9

3.1.1. Protocolo IP 10

3.1.2. Protocolo TCP 11

3.1.3. Protocolo UDP 12

3.2. Protocolo HTTP 12

3.2.1. URL 13

3.2.2. Solicitud y Respuesta HTTP 14

3.3. Servidores Web 18

3.3.1. Tipos de servidores web 19

3.3.2. Gestores de bases de datos 21

3.4. Generación de energía fotovoltaica 25

3.4.1. Energía Solar 26

3. 4.2. Radiación solar . . . . .

6. Análisis de Resultados 100

6.1. Resultados y Análisis . . . . .

## Índice de figuras

1.1. Diagrama solución implementada 5

3.1. Ejemplo URL 13

3.2. Ejemplo solicitud y respuesta HTTP 14

3.3. Ejemplo método GET 15

3.4. Ejemplo de las cabeceras HTTP. 17

3.5. Diagrama de flujo entre el cliente y servidor 22

3.6. Potencial eléctrico fotovoltaico en Costa Rica. 27

3.7. Diagramas de dispersión 35

4.1. Sistema adquisición de datos 45

4.2. Solución utilizando el protocolo HTTP 47

4.3. Solución utilizando el protocolo MQTT parte 1 48

4.4. Solución 3 utilizando el protocolo MQTT parte 2 49

4.5. Medición utilizando el sensor de nivel ultrasónico 51

4.6. Sensor de nivel ultrasónico AJ-SR04 52

4.7. Medición utilizando el sensor de presión diferencial 53

4.8. Sensor de presión diferencial MPX5500DP 53

4.9. Arduino nano 55

4.10. ESP32 55

4.11. Raspberry Pi Zero 56

4.12. SIM900 58

4.13. SIM7600CE 59

4.14. RTC DS3231 59

5.1. Descripción Pines arduino nano 71

nce de figuras

5.2. Diagrama de conexión . . . . .

6. 1. Resultado sistema de potencia implementado. . . . . 

## Índice de tablas

4. 1. Tabla de limitaciones debido a la zona . . . . .

## Capítulo 1

## Introducción

El agua está presente en nuestras vidas en cada instante, inclusive el cuerpo humano está compuesto por un 60 % de líquido. [1] Por otro lado, el desarrollo humano ha permitido realizar distintos procesos de los cuales es necesario el uso de agua; los procesos industriales, agrícolas, uso personal, comercial, entre otros, han hecho del agua un recurso de suma importancia y hacer un uso adecuado del mismo es fundamental. [2]

Costa Rica ofrece una amplia cobertura de agua potable a casi todos los hogares costarricenses, entre el 97.5 a un 97.7 % de la población cuenta con cobertura de agua por cañería. Algunas de las entidades encargadas de suministrar este recurso tan importante son instituciones como Acueductos y Alcantarillados (AyA), municipios, acueductos rurales entre otros. [3]

El agua potable es muy importante para el desarrollo social, económico y ambiental de una región. El manejo adecuado del agua puede traer muchos beneficios a una comunidad, contar con sistemas o mecanismos que permitan evaluar cambios diarios a partir de datos históricos es determinante para el manejo adecuado y sostenible de acueductos.

Para planificar el uso del agua es importante determinar la distribución espacial y temporal del recurso hídrico, para ello se requiere datos de precipitación, caudal, demanda (uso), evapotranspiración entre otros. El enfoque del presente proyecto es la implementación de un sistema que permita monitorear la variación de nivel de líquido en un tanque de almacenamiento de agua potable con el fin de determinar la demanda y el suministro

de la zona. Para ello, se propone transmitir los datos de nivel de tanque remotamente por medio de una estación instalada en el tanque. La estación tendrá la función de recolectar la energía por medio de módulos que captan la energía solar y almacenarla en baterías, también se encarga de transmitir todos los datos que el sistema recolecte durante el día.

Mediante la recopilación de Información el Centro de Investigación y Estudio para el Desarrollo Sostenible CIEDES podrá realizar estudios para determinar la demanda de la zona y a partir de estos estudios se desarrollan modelos con el fin de mejorar la gestión en el manejo de acueductos.

A continuación, se detalla la problemática existente, la importancia de su solución, así como la solución seleccionada para dar fin a la problemática existente.

## 1.1. Problema existente e importancia de su solución

La colaboración entre la Universidad de Costa Rica y la municipalidad de Abangares, inicio como un proyecto que pretendía subsanar el problema de abastecimiento de agua potable en la ciudad de Las Juntas de Abangares a mediados del año 2000. A partir de ese momento, la Escuela de ingeniería Civil de la Universidad de Costa Rica inicia de manera informal sus labores de cooperación con el municipio, inicialmente enfocadas en el funcionamiento del acueducto municipal que abastece la ciudad de Las Juntas. Luego se amplía el enfoque de los proyectos de investigación, hacia la Gestión Integrada del Recurso Hídrico y el manejo de la cuenca del río Abangares. En febrero de 2012, se firma un Convenio de Cooperación entre la Universidad de Costa Rica y la Municipalidad de Abangares para continuar desarrollando proyectos conjuntos y mantener actualizados los anteriores, bajo la coordinación del Centro de Investigación y Estudio para el Desarrollo Sostenible (CIEDES). [2]

En los trabajos de apoyo sobre la gestión de acueductos rurales que realiza el CIEDES, uno de los factores a considerar es el registro programado de datos con el fin de planificar y modelar la fuente de abastecimiento. Este tipo de estudio permite en un futuro evaluar posibles cambios en el manejo de las asadas, por ejemplo, planificar el uso del agua en épocas de escasez.

Entre los trabajos de cooperación se encuentra uno ubicado en la comunidad de las juntas de Abangares, en este se desea conocer el nivel de líquido por medio de la variación del tanque en depósitos de captación y almacenamiento de agua potable en una ASADA, con el fin de modelar el comportamiento de la demanda y el suministro de agua. Por lo tanto, el monitoreo con cierta periodicidad del nivel resulta de gran importancia para la planificación de acciones en caso de situaciones que desmejoran la captación y suministro.

Existen dos tipos de acueductos, abastecidos por bombeo y abastecidos superficialmente. En acueductos abastecidos por bombeo existe un medidor de punto el cual posee dos estados, el primero es el punto crítico que acciona una bomba cuando el tanque está en niveles bajos de líquido y el segundo estado es el punto de apagado, el cual apaga la bomba cuando se alcanza el punto máximo en el tanque, este tipo de sistema permite definir la capacidad máxima de suministro de agua cuando se conoce estos dos estados. En acueductos abastecidos superficialmente la situación se vuelve más compleja, ya que, el abastecimiento depende de la fuente, la cual está ligada a variaciones estacionales como el clima y situaciones específicas de la zona, estos acueductos, tienen un punto de rebalse para evitar situaciones en la que el suministro supere la demanda.

En la ASADA ubicada en la comunidad de Abangares, la planta potabilizadora funciona de la siguiente manera: El agua proviene del río se entuba directamente a la planta, en la planta se realizan procesos de filtración y cloración del agua, luego del proceso de saneamiento, el agua se entuba hasta un tanque abastecido superficialmente.

El CIEDES o el personal administrativo de la ASADA realizan mediciones esporádicas para conocer el nivel de líquido en el tanque, esta medición consiste en que una persona se dirige a la asada específicamente al tanque ubicado ahí y lleva un registro cada 15 días de la altura del tanque utilizando una escala como principal medio para medir y se anota el dato en una libreta. Este tipo de medición puntual no permite evaluar cambios futuros debido a la escasez de los datos.

En la planificación del manejo integral de la Asada es importante conocer la demanda y como esta varía dependiendo de distintos factores, existen variables de las cuales no se puede tener control como lo son el clima y las condiciones ambientales de la zona; sin embargo, se puede construir un modelo el cual analice el volumen recolectado y su uso

en el tiempo. El uso del agua en el tiempo está estrictamente ligado a las prácticas del consumo humano (muchas veces desmedidas), mientras que el volumen recolectado está completamente ligado a la fuente y a factores estacionales.

Este proyecto permitirá planificar y mejorar el funcionamiento de todo el sistema de captación, almacenamiento y distribución de agua en acueductos rurales. Los datos de nivel de líquido del tanque de almacenamiento de agua permitirán realizar estudios en materia del uso que se le brinde al agua en la comunidad. El impacto que tiene el proyecto en el desarrollo de la comunidad es un punto importante a considerar, ya que, se busca una administración sostenible y eficiente del recurso hídrico.

## 1.2. Solución Seleccionada

En la actualidad existen sistemas que miden el nivel de líquido en tanques de almacenamiento, sin embargo, estos dispositivos son para uso industrial por lo que implementarlo en un proyecto como el presentado no es conveniente debido a que son sistemas completos con sensores y controladores. Por otro lado, existen sistemas de nivel de líquido, pero estos solo permiten accionar una alarma o encender alguna bomba por lo que su medición es puntual.

El CIEDES necesita una forma de adquirir y visualizar datos de forma remota sobre el nivel de líquido en un tanque de almacenamiento de agua ubicado en la asada de Abangares, esto con el propósito de eliminar la medición manual y obtener datos diarios. Para ello, se establecieron algunas restricciones o requerimientos por parte del director del CIEDES M.Sc Edwin Solórzano Campos, estos se muestran a continuación:

Almacenar datos del nivel de líquido del tanque. Los datos se generan cada hora o cada 20 minutos dependiendo de la hora del día y se almacenan.

- Datos obtenidos del sensor deben poseer una incertidumbre de al menos 1cm de manera que los datos sean bastante precisos.

- Interfaz para visualizar los datos de forma remota, por medio de consultas se generan gráficos y tablas con los datos almacenados, las consultas se hacen por fecha además

de poder generar archivos descargables excel.

No existe acceso de wifi por lo que será necesario acceder a internet por otro medio.

El sistema diseñado deberá funcionar con energía que no provenga de la red eléctrica. Hacer uso de alguna energía renovable.

Se debe probar el sistema de generación eléctrica para verificar el correcto funcionamiento de todo el sistema final.

- Implementar el prototipo medidor en condiciones similares al sitio de instalación del sistema final, específicamente condiciones similares a Abangares.

Tomando en cuenta las consideraciones de los puntos anteriores se decide implementar la solución de la figura 1.1.


> **Descripción de figura no disponible.**

<div align="center">

Figura 1.1: Diagrama solución implementada Fuente: Elaboración Propia

</div>

Para obtener los datos de nivel de líquido se utiliza un sensor ultrasónico impermeable capaz de resistir condiciones de gran humedad como las presentes en un tanque de almacenamiento de agua. Para la calibración del sensor se utiliza la regresión lineal, esta permite generar una ecuación que nos indica el comportamiento del sensor.

Para llevar a cabo la transmisión de datos, se decide implementar una estación de adquisición de datos en el tanque de almacenamiento, de esta forma el sistema contará con un sensor que permitan medir el nivel de líquido y transmitirlo por medio del protocolo HTTP, una vez transmitido el dato se almacena en una base de datos donde posteriormente se logre visualizar en una página web.

Se decide contratar un hosting ya que este permite muchos beneficios en cuanto al mantenimiento a un precio bastante accesible, de esta forma se obtiene un Cpanel en la nube en donde es más fácil gestionar la base de datos y la página web. Para el diseño de la página web se utiliza herramientas de diseño como Bootstrap 5, además de googlecharts como los gráficos de línea.

Para la implementación del sistema que alimente la estación de adquisición de datos, se dimensiona el consumo de los componentes utilizados, además debido a la naturaleza de las mediciones donde únicamente es necesario tomar mediciones a cierta hora del día, se implementa un interruptor timer, de esta forma se ahorra el consumo de energía de los dispositivos en standby de tal manera que el sistema de adquisición de datos se enciende solo cuando sea necesario.

El sistema de alimentación utiliza un panel solar que activamente está captando energía del sol y la almacena en una batería para su utilización durante el día, para verificar que el sistema de potencia funcione a lo largo del año se realizan simulaciones en PVsyst, de esta forma se puede aproximar el modelo a valores reales ya que este software utiliza bases de datos meteorológicos y nos brindan datos con bastante precisión, lo cual es de mucha ayuda cuando se desea instalar sistemas fotovoltaicos.

<div align="center">

# Capítulo 2

</div>

## Meta y objetivos

En el siguiente capitulo, mediante la identificación de la meta y objetivos se determina cual es el resultado final que se espera y de esta manera establecer las actividades necesarias que permitan guiar el proyecto durante la implementación del mismo.

## 2.1. Meta

Disponer de un sistema electrónico para el monitoreo de la variación de líquido en un tanque ubicado en la comunidad de las Juntas de Abangares, con el fin de eliminar la medición manual y obtener más datos que permita al Centro de Investigación en Desarrollo Sostenible (CIEDES) realizar sus diferentes estudios estadísticos en materia de consumo y suministro del agua potable.

## 2.2. Objetivo general

Implementar un sistema autónomo para monitoreo del nivel de líquido en sistemas de almacenamiento y distribución de agua.

## 2.3. Objetivos específicos

- Diseñar un prototipo medidor de nivel de líquido para un tanque de almacenamiento de agua a presión atmosférica.

Indicador: Gráficas y calibración del sensor a partir de la toma de datos a diferentes alturas, de manera que, se defina la presión del sensado en 95 % de similitud entre cada medición a un mismo nivel de líquido.

- Implementar un sistema de autonomía energética que suministre el consumo del sistema medidor cuando éste opera en condiciones habituales.

Indicador: El sistema de adquisición de datos funciona correctamente con el sistema energético implementado.

- Implementar el sistema de adquisición y visualización de datos del nivel de agua.

Indicador: Verificación del sistema funcionando; el dato se obtiene, transmite, almacena y visualiza.

<div align="center">

# Capítulo 3

</div>

## Marco teórico

## 3.1. Protocolo TCP/IP

El protocolo TCP/IP es el protocolo más utilizado en redes y el protocolo de internet estándar. [4] Este protocolo permite la comunicación de muchos equipos dentro de la red. El protocolo se basa en el modelo teórico de capas OSI en donde comparte cuatro capas, el objetivo de ambos es el mismo, establecer el funcionamiento mediante capas y dar acceso a los equipos conectados a la red.[5]

TCP/IP describe las reglas y guías generales que hacen posible que diferentes equipos puedan intercambiar información en una red. El modelo identifica los protocolos que se utilizan y asegura la conexión punto a punto, también define como se deben formatear, transmitir y enrutar los datos. [5]

Las 4 capas del protocolo TCP/IP son:

## Capa 1 o de acceso al medio

Esta capa determina el acceso físico de todos los equipos que están conectados en una red local. TCP/IP puede ser extendido a una red global ya que está diseñado de manera independiente del hardware que compone la red. En esta capa también se definen los protocolos y la topología de red a utilizar (estrella, malla, anillo entre otros), también

define como se mueven los paquetes en la capa de Internet. [5]

## Capa 2 o de Internet

En esta capa es donde trabaja el protocolo IP y se encarga de la estructura de los paquetes de datos que circulan en la red. Esta capa define como deben ser enviados los datos a través de la red, por medio de la administración de las direcciones IP que cada equipo tiene asignado en una red. Otra función que realiza esta capa es identificar los hosts mediante la dirección IP y direcciona los datagramas dando saltos de enrutador a enrutador hasta llegar al host final. [5]

## Capa 3 o de transporte

En esta capa se establecen los puertos lógicos que utilizan las aplicaciones para intercambiar información de un punto a otro, en esta capa se asigna un puerto a un tipo de aplicación. En esta capa trabajan otros protocolos como TCP y UDP, ambos se encargan del control de flujo y errores de los datos. [5]

## Capa 4 o de aplicación

En esta capa de definen los protocolos que se utilizaran en los distintos servicios solicitados por el usuario. Entre los protocolos que trabajan en esta capa se encuentra: HTTP (páginas web), HTTP (páginas web seguras), FTP (transferencia de archivos), DHCP (Configuración dinámica de host), SMTP (transferencia de correos). [5]

## 3.1.1. Protocolo IP

El protocolo IP o Internet Protocol se encarga de proporcionar a cada equipo conectado a una red una dirección IP. Este protocolo no está orientado a la conexión por lo que el intercambio de datos se puede realizar sin previo aviso entre el cliente y el servidor, esto permite que el paquete de datos identifique las direcciones IP del camino más corto a través de la red. [5]

A nivel de red el protocolo IP agrega una cabecera al paquete de datos con la IP de origen y destino con el fin de que sea capaz de recorrer la red. [5]

Existe dos versiones de IP, IPv4 e IPv6. La primera version del protocolo IPv4 usa direcciones de 32 bits pudiendo direccionar alrededor de 4 mil millones de hosts, esta primera version utiliza un formato separado por puntos un ejemplo podría ser 192.124.23.4. La segunda version IPv6 usa direcciones de 128 bits puedo direccionar miles de millones de hosts, el formato que utiliza son grupos de 4 dígitos hexadecimales separados por dos puntos un ejemplo podría ser 5a9d:db62:9ffa:763d. [5]

## 3.1.2. Protocolo TCP

El protocolo TCP es el que se encarga de establecer y permitir que dos hosts se conecten, además asegura la comunicación entre los dos puntos permitiendo el intercambio de datos. El protocolo TCP básicamente lo que hace es coger el datagrama IP y le añade sus propias cabeceras para asegurar el transporte. [5] Este protocolo está orientado a la conexión, esto quiere decir que los equipos deben aceptar la conexión antes de intercambiar los datos. Para finalizar la conexión, el que finaliza envía un mensaje FIN y el host que recibe responde con un mensaje ACK junto con otro fin, finalmente el que quiere cerrar la conexión envía un último mensaje ACK y se finaliza el socket abierto. TCP permite que los datos lleguen de forma ordenada. [6]

El protocolo TCP permite el control de flujo, en caso de una saturación en la red el protocolo es capaz de mitigarlo. Si un equipo transmite a 100Mbps y el equipo receptor solamente puede recibirla información a una velocidad de 50Mbps el protocolo TCP tiene la función de adaptarse dinámicamente, de esta forma se aprovecha al máximo el ancho de banda disponible. [6]

TCP también permite el control de congestión, si hay congestión en la red el protocolo permite que no se pierdan los datos, ya que se establece el envío nuevamente por parte del protocolo. [6]

Los puertos (Source Port y Destination Port) son fundamentales para identificar un socket, es decir una aplicación que recibe o transmite datos. Estos puertos van de 0 a

65535 y están clasificados según IANA a continuación: [6]

- Puertos conocidos: del 0 al 1023. Estos puertos están destinados para distintas aplicaciones, como por ejemplo HTTP, FTP, SSH, entre otros.

- Puertos registrados: del 1024 al 49151. Estos puertos están destinados para aplicaciones concretas, como sistemas gestores de bases de datos, BitTorrent, entre otros.

- Puertos privados: del 49152 al 65535. Estos puertos no están destinados para ninguna aplicación, y se pueden usar libremente sin afectar a otro protocolo.

## 3.1.3. Protocolo UDP

El protocolo UDP (User Data Protocol) es un protocolo que no esta orientado a la conexión, esto quiere decir que no es necesario establecer la comunicación de antemano. Mientras que exista un socket abierto en el destino se puede enviar los datagramas desde el origen. [6]

Este protocolo no brinda control de flujo por lo que, si un equipo es más rápido que el otro, es posible que se pierda información debido a que la red colapsa en el equipo más lento, por lo que se deberá reenviar lo datos nuevamente. Tampoco proporciona control de congestión por lo que si hay congestión en la red los datos se perderán ya que este protocolo no los vuelve a enviar. [6]

Cuando la rapidez es más importante que la fiabilidad, el protocolo UDP es una opción para considerar ya que los datagramas son de menor tamaño. [6]

## 3.2. Protocolo HTTP

El protocolo HTTP (HyperText Tranfer Protocol) tiene como objetivo definir y estandarizar la semántica y sintaxis del intercambio de la información que realizan diferentes equipos en una red. [7] Este es un protocolo de solicitud/respuesta que viene incluido dentro del protocolo TCP/IP específicamente en la capa de aplicación. Cada vez que se ingresa a una página web desde el navegador en internet por lo general el flujo de información se da por medio del protocolo HTTP, en donde el usuario realiza una

solicitud de algún servicio y el servidor responde con la información. [8]

## 3.2.1. URL

La URL (Uniforma Resourse Locator) es una dirección que se asigna a una web. La web se puede considerar como una serie de diferentes recursos estructurados, ya que desde los inicios se utilizó para compartir imágenes, documentos, archivos texto HTML, entre otros. [9] Cuando se ingresa a una página web desde el navegador o se pincha sobre un enlace, por lo general el navegador establece una conexión con el servidor por el puerto 80 TCP, salvo que se indique el puerto por la URL. [8]


> **Descripción de figura no disponible.**

<div align="center">

Figura 3.1: Ejemplo URL

</div>

Fuente: Elaboración Propia

Protocolo: La mayor parte del tiempo se utiliza el protocolo HTTP (o HTTPS para la forma segura de HTTP). Otros protocolos son: FTP, SMTP. [9]

Dominio: Es el nombre que se le asigna a una o más direcciones IP, la DNS es el sistema que gestiona dicho proceso, de esta forma es más fácil recordar un nombre que una dirección IP. [9]

Ruta: Indica el archivo o recurso al que quiere acceder, si no se indica en la URL los servidores tienen recursos configurados por defecto, el que normalmente se utiliza es: index.html, sin embargo, se pueden configurar otros como: index.jsp, index.php, default.asp, index.shtml, entre otros. [10]

Parámetros: Son los datos adicionales que identifican o filtran los recursos en el servidor. [9]

## 3.2.2. Solicitud y Respuesta HTTP

El protocolo HTTP solo gestiona solicitudes y respuestas. Cada solicitud y respuesta incluye una serie de cabeceras además del cuerpo del mensaje. Las cabeceras específican información adicional con respecto a los metadatos, cookies, almacenamiento cache, autorización, entre otros. El cuerpo del mensaje es donde los datos son transmitidos. [8]

Independientemente si se gestiona solicitudes o respuestas, el mensaje transmitido contiene 3 partes: [11]

- En la primera línea se especifica el método utilizado, el recurso al que se quiere acceder y la versión del protocolo. Está línea es diferente para la solicitud y respuesta.

- Luego se especifican las cabeceras.

- Finalmente se especifica el cuerpo del mensaje, este último es opcional.


> **Descripción de figura no disponible.**

<div align="center">

Figura 3.2: Ejemplo solicitud y respuesta HTTP

</div>

Fuente: Elaboración Propia

## Métodos HTTP

El protocolo HTTP posee una serie de comandos o métodos que son importantes para acceder a una dirección url, estos comandos son los que usan las APIs REST. REST (REpresentational State Transfer) es una arquitectura para el desarrollo web, en otras palabras, se puede ver como una interfaz entre diferentes sistemas que utilizan HTTP. Los diferentes métodos sirven para manipular los recursos y proporcionar el intercambio

de datos entre los equipos en una red. [10]

Para manipular los recursos, se utilizan los siguientes métodos:

- GET - Consulta y lee registros.

- POST - Crea registros.

- PUT - Edita registros.

- DELETE - Elimina registros.

- PATCH - Edita segmentos específicos de un determinado registro.

Otros comandos importantes son:

- OPTIONS - Permite saber las propiedades en una conexión.

- HEAD - Devuelve únicamente las cabeceras del recurso.

- TRACE - Sirve para depurar y permite conocer si la petición pasa por los proxys o servidores intermedios.

- CONNECT- Permite saber si un proxy puede ser intermediario y funcionar como un túnel hacia un destino deseado.

Los métodos más importantes en una conexión HTTP son el método GET y POST.

Método HTTP GET: La información que se envía es de forma visible. Esto quiere decir que la codificación de la información se realiza en el header de la solicitud HTTP, directamente desde la URL. Cada vez que se accede a un recurso por este método la codificación en la URL se separa por el interrogante "?" como se muestra en la figura 3.3. [12]

http://www.example.com/index.html?parametro1=valor1&parametro2=valor2&parametro3=valor3

## Figura 3.3: Ejemplo método GETP

Fuente: Elaboración Propia

- El tamaño de la URL está limitado a 2000 caracteres.

- No es recomendable enviar información sensible ya que los datos son visibles y es muy posible que sean intervenidos.

- No permite enviar datos binarios como archivos e imágenes.

- En PHP el array asociativo $_GET permite recopilar los datos que se envían desde la URL.

Método HTTP POST: La información que se envía es de forma no visible. Esto quiere decir que la codificación de la información se realiza en el cuerpo de la solicitud HTTP, por lo que la información no aparece directamente en la URL caso que sí sucede con el método GET. [12]

- No tiene límite en la cantidad de información que se quiera enviar.

- Se puede enviar información sensible ya que los datos se transmiten de forma no visible.

- Se pueden enviar datos binarios como imágenes y archivos.

- En PHP el array asociativo $_POST permite recopilar los datos que se envían por el cuerpo.

## Códigos de respuesta

Cada vez que un usuario realiza una solicitud, el servidor responde a la solicitud, para ver el estado de las respuestas existen una serie de códigos de respuesta que muestran el estado de dicha solicitud. Los diferentes códigos de respuesta están numerados por tres dígitos y son muy importantes ya que indican el resultado de la solicitud realizada. [10]

Los principales códigos son los que inician con el número dos, estos códigos indican la correcta ejecución de la transacción. Otro código muy importante son los que inicia con el número cuatro que indican si la solicitud es incorrecta. Todos los códigos de respuesta se muestran en la sección de anexos.

## Cabeceras

Como se mencionó anteriormente las cabeceras permiten intercambiar información adicional entre el cliente y el servidor cada vez que se genera una solicitud o una respuesta. El formato de las cabeceras tiene la forma [cabecera]:[valor], primeramente se ingresa el nombre de la cabecera seguido del valor, ambos separados por los dos puntos. Existe una gran cantidad de cabeceras que intervienen en diferentes comunicaciones. Un ejemplo del

intercambio de informacion entre un cliente y servidor se observa en la figura 3.4. [11]


> **Descripción de figura no disponible.**

<div align="center">

Figura 3.4: Ejemplo de las cabeceras HTTP.

</div>

Fuente: Elaboración Propia utilizando el software wareshark

## Versiones del protocolo HTTP

A lo largo de los años el protocolo más utilizado en la red ha sido HTTP. Desde sus inicios en 1989, se han lanzado una serie de versiones que se han adaptado a las distintas necesidades de los usuarios y la tecnología presente del momento. Las distintas versiones lanzadas se muestran a continuación: [7]

- HTTP/0.9: Es la primera version del protocolo HTTP, en esta version únicamente se podía transferir archivos HTML ya que no utilizaba cabeceras, tampoco existían los diferentes códigos de respuesta. Esta version ya no se utiliza.

- HTTP/1.0: En esta versión se incorpora los métodos como GET, HEAD, POST, esto permite un entorno más flexible entre los navegadores y servidores web. En la actualidad algunos proxys utilizan esta versión.

- HTTP/1.1: En esta versión se agrega muchas mejoras con respecto a su antecesor 1.0, entre las mejoras se destaca poder realizar múltiples peticiones a la vez por parte del cliente, además permite mantener la conexión abierta por lo que esta puede ser reutilizada y se añaden mejoras en la administración del caché. En la actualidad esta versión es todavía la más utilizada, por lo que a lo largo de los años se ha adaptado a distintos cambios y necesidades de los usuarios.

- HTTP/2: Esta versión no modifica la semántica de la versión anterior, pero se inclu-

ye mejoras que favorecen al usuario o a cualquier persona que posea una página web. Las mejoras incluyen la necesidad de menos recursos, esto implica que la latencia sea menor lo que permite al servidor gestionar varias peticiones al mismo instante. En otras palabras, se busca mejorar la seguridad y la rapidez de una web.

## 3.3. Servidores Web

Cuando llego el protocolo HTTP los usuarios necesitaban una forma de visualizar todos los datos solicitados, por este motivo nació el lenguaje de etiquetas (HyperText Markup Language). Este lenguaje permite que la página web muestre la información cada vez que se acceda a la misma. HTML se ha convertido en el estándar para los desarrolladores web independientemente si se utiliza el protocolo HTTP. Tonto HTML como HTTP se han ido adaptando a los distintos cambios, agregando funciones nuevas con el tiempo.

Cada vez que se ingresa a una página web desde el navegador este solicita la información a un equipo o computadora que está en otro parte del mundo, este equipo se denomina servidor web. Luego de transcurrir un tiempo muy corto el servidor web devuelve toda la información solicitada de manera que se pueda visualizar en una página web mediante los diferentes archivos HTML que la página posea.

El concepto de servidor y servidor web no es el mismo; el servidor es la maquina física que almacena todos los datos, se podría decir que es la parte que involucra todo el hardware; mientras que servidor web es un servicio web que se ejecuta en un servidor virtual o físico y este se encarga de despachar toda la información por medio de algún protocolo TCP/IP en la capa de aplicación, en otras palabras, el servidor web combina tanto el hardware como el software que se ejecuta en ese hardware. El servidor web es el encargado de recibir las solicitudes de los clientes y mostrar por medio de las páginas web toda la información solicitada, la información solicitada puede ser desde archivos textos, hasta imágenes y videos, entre otros. [13]

Las solicitudes que realicen los clientes o usuarios pueden devolver dos tipos de contenidos: estático o dinámico. El contenido estático es el que se devuelve tal y como

esta en el servidor sin ningún tipo de procesamiento como por ejemplo una imagen. El contenido dinámico es generado en el momento como por ejemplo un buscador, esto quiere decir que el contenido no existe en el servidor tal y como se muestra en la página web. [13]

Cada vez que se busca o accede a una determinada página web en internet, el servidor en otro lugar recibe una solicitud, para devolver el contenido solicitado primero se ejecutan los archivos que generen los datos y luego se devuelve todo el contenido al usuario, este proceso se realiza gracias a otros servicios o módulos destinados a este fin como lo puede ser PHP o ASP. [13]

PHP (HyperText Preprocessor) es un lenguaje de código abierto muy utilizado por los desarrolladores web y que se puede incrustar dentro de los archivos HTML. PHP se ejecuta dentro del servidor, generando los datos y archivos HTML para luego enviarlos al usuario. Esto permite que cada vez que se ejecute el archivo no se muestre el código ya que php accede a la base de datos por lo que las instrucciones se muestran ocultas y solo se muestra el archivo HTML con los datos. [14]

## 3.3.1. Tipos de servidores web

## Apache Web Server

Apache funciona básicamente en todos los sistemas operativos, MAC OS, Linux, Windows y demás. Es un software de código abierto que se puede personalizar muy fácil, estos servidores poseen una estructura modular por lo que se puede agregar distintos módulos dependiendo de los requisitos lo que permite realizar distintas modificaciones para adaptarse. En la actualidad el 60 % de todos los equipos se ejecutan en Apache web server. [15]

## ISS Web Server

ISS web server es un servicio desarrollado por Microsoft que ofrece todas funciones de Apache web server, el software no es de código abierto por lo que es muy difícil agregar

módulos personalizados. Estos servidores se pueden ejecutar en todos los equipos que utilicen el sistema operativo Windows. [15]

## Nginx Web Server

Nginx web server es un software de código abierto, se podría decir que es el segundo después de Apache, está compuesto por servidores proxys IMAP/POP3 la diferencia entre ambos es que uno almacena los datos por el correo y el otro los descarga y almacena localmente. La arquitectura que utiliza se basa en eventos altamente escalables que utiliza muy poca memoria, en los últimos años esta tecnología se ha vuelto muy popular y en el mundo aloja aproximadamente el 7.5% de los dominios. El alto rendimiento, la configuración simple, la estabilidad y el bajo uso de los recursos lo han hecho una opción a considerar hoy en día. [15]

## LiteSpeed Web Server

LiteSpeed web server (LSWS) es un servidor comercial, es la sustitucion del servidor web Apache con un alto rendimiento, proporciona todos los paneles de control compatibles con Apache, por lo que puede reemplazar todas sus funciones. LSWS brinda una migración fácil ya que tiene la capacidad de cargar archivos de configuracion de Apache y funcionar como su reemplazo. En la actualidad LSWS es el cuarto servidor más popular en el mundo. [15]

LSWS tiene una arquitectura basada en eventos, esto permite una menor cantidad de procesos cada vez que se realiza una solicitud por parte de un cliente, estas solicitudes son atendidas por una serie de procesos ya definidos, esto permite que el tiempo de respuesta sea menor en comparación con otros servidores debido a que muchos procesos se encuentran almacenados en la memoria. La ventaja de estos servidores web radica en el ahorro de memoria y del hardware necesario ya que no se tiene que cargar los procesos cada vez que se realiza una solicitud por parte del cliente. [16]

LSWS permite cargar paginas dinámicas mucho más rápido que otros servidores ya que incorpora una API que permite brindar soporte para python, php y rudy; esto

permite a su vez un entorno más eficiente para el usuario ya que el código se procesa de forma más rápida y segura. [16]

## 3.3.2. Gestores de bases de datos

Los DataBase Management System (DBMS) o sistemas gestores de bases de datos (SGBD) son los encargados de gestionar todo el acceso a la base de datos [17], a continuación, se enumera una serie de pasos que realizan estos software:

1. Un cliente solicita un acceso a la página web o algún archivo, este proceso se realiza mediante algún lenguaje de definición de datos o DDL.

2. El gestor de la base de datos intercepta la solicitud, la analiza e inspecciona los diversos esquemas.

3. Mediante el lenguaje de manipulación de datos o DML se manipula y procesa los datos ejecutando una serie de operaciones necesarias sobre la base de datos.

En la figura 3.5 se muestra el diagrama de flujo:


> **Descripción de figura no disponible.**

<div align="center">

Figura 3.5: Diagrama de flujo entre el cliente y servidor Fuente: Elaboración Propia

</div>

El rendimiento del gestor de la base de datos debe ser bueno ya que si el gestor es muy lento se puede obtener latencias muy elevadas cada vez que se solicita información. Actualmente existen diferentes gestores de bases de datos clasificados según dos tipos: Relacionales (SQL) y No relacionales (NoSQL), la diferencia entre ambos radica en como manipulan los datos.

## Sistemas Gestores de bases de datos Relacionales (SQL)

Los gestores de bases de datos relacionales establecen relaciones entre los diferentes datos, por cada tabla que se genere en la base de datos existe una relación entre los registros y sus atributos. [18]

A continuación, se detallan algunos gestores de datos relacionales:

## MySQL

Los gestores de bases de datos MySQL son los más utilizados para aplicaciones creadas en código abierto, es utilizado en gran parte de las páginas web, por lo que lo convierte en un gran favorito, MySQL permite realizar distintas funciones simultáneamente ya que es una gestor multihilo y multiusuario. [18]

Este gestor de datos está diseñado para trabajar con base de datos pequeñas por lo que si se trabaja con base de datos grandes el gestor puede trabajar de manera deficiente. Por lo que si se busca escalabilidad sería conveniente buscar un gestor que soporte base de datos más grandes.

## MariaDB

El gestor de base de datos MariaDB nace cuando Oracle adquiere los derechos de MySQL, por lo que este cuente con la mayoría de las características, además de que incluye nuevas extensiones. Este SGBD es de código abierto y completamente compatible con MySQL, se podría decir que es la versión actualizada de MySQL. [18]

Las ventajas que ofrece este gestor son:

- Aumento de los motores de almacenamiento, esto quiere decir que se aumenta la capacidad de almacenar, gestionar y recuperar los datos.

- Alta escalabilidad.

- Gran eficiencia, rapidez y seguridad.

- Extensiones y nuevas características relacionadas con su aplicación para Bases de datos NoSQL.

En definitiva, MariaDB es mucho más potente que MySQL, la única desventaja de MariaDB son algunas pequeñas incompatibilidades con MySQL.

## SQLite

SQLite es una librería programada en C e implementada en un gestor de base de datos, este SGBD funciona sin necesidad de un servidor, permite consultas y transacciones

muy eficientes, además es de código abierto y posee gran estabilidad. La desventaja de SQLite es que no soporta bases de datos muy grandes. [18]

## PostgreSQL

PostgreSQL es un gestor de base de datos de código abierto orientado a objetos. Es compatible con sistemas operativos como Mac OS, Linux, Windows, FreeBCD, OpenBCD, es robusto, eficiente y posee gran estabilidad. [18]

PostgreSQL está diseñada para trabajar con base de datos muy grandes, por lo que se vuelve muy lenta cuando se administra base de datos pequeñas.

## Microsoft SQL Server

Este gestor de base de datos está diseñado por Microsoft basado en un lenguaje de búsqueda estructurado Transact-SQL, este SGDB es capaz de manejar gran cantidad de información de manera simultánea. La principal desventaja de este gestor es su elevado costo. Posee una gran estabilidad, escalabilidad y seguridad. [18]

## Oracle

Oracle es el gestor de bases más completo y robusto, se utiliza principalmente en el ámbito empresarial. Brinda gran escalabilidad y seguridad en la protección de los datos.

## Sistemas Gestores de bases de datos No Relacionales (NoSQL)

Las bases de datos no relacionales (NoSQL) poseen las siguientes características: [18]

- No requiere ninguna estructura fija de datos como tablas.

- No garantiza completamente las características ACID.

- Posee una escalabilidad horizontalmente, esto quiere decir que funciona con diferentes servidores que funcionan como un todo. Estas bases de datos se configuran en una red de servidores denominada clúster.

Los tres principales gestores de bases de datos NoSQL son:

## MangoDB

MongoDB es un gestor de base de datos orientado en estructuras binarias de datos y mapas denominada BSON con un esquema dinámico que permite su fácil integración. Entre las grandes compañías que utilizan este gestor de base de datos se encuentra: Google, eBay, Facebook, Adobe, Cisco. [18]

## Redis

El principal uso de este gestor de base de datos es el almacenamiento en memoria cache para la administración de sesiones. Su arquitectura esta basa en el almacenamiento clave-valor, este tipo de SGBD es un vector muy grande que almacena datos de todo tipo, como cadenas, hash, listas, entre otros. [18]

## Cassandra

La arquitectura de Cassandra al igual que Redis utiliza almacenamiento clave-valor. Es un SGBD masivamente escalable. Grandes compañías como Twitter, Netflix, Facebook, Spotify o Instagram utilizan este SGBD. Cassandra cuenta con su propio lenguaje para representar consultas denominado CQL (Cassandra Query Languaje). [18]

## 3.4. Generación de energía fotovoltaica

Las energías renovables son inagotables, ya que provienen naturalmente, el sol, el viento, el agua, pueden generar energía de forma continua cada día siempre y cuando las condiciones ambientales lo permitan. Este tipo de energía ha sido utilizada por el hombre desde la antigüedad y la ventaja de utilizarla es que se pueden complementar entre sí. [19]

El sol es la fuente de energía que más llega a la tierra y se recibe por medio de la

radiación solar que se retiene en la atmosfera, esto permite mantener una temperatura constante facilitando la vida en el planeta. [19]

Con la ayuda de las energías renovables se puede obtener calor y electricidad, estos son los dos tipos de energía más utilizados por el hombre.

## 3.4.1. Energía Solar

La energía solar que llega de forma directa a la tierra permite calentar e iluminar, para aprovechar la radiación electromagnética que llega del sol es necesario contar con una serie de sistemas que permitan generar y almacenar energía, esta energía se puede aprovechar de dos maneras: [19]

Generación de Calor: Es la energía térmica que se aprovecha del sol para calentar distintos fluidos que circulan por captadores solares térmicos. [19]

Generación de Electricidad: Los sistemas fotovoltaicos permiten transformar la radiación solar en electricidad por medio de sistemas tecnológicos que integran células o módulos capaces de absorber la radiación y convertirla en electricidad. Este tipo de energía se puede almacenar en acumuladores para su posterior utilización. [19]

La figura 3.6 muestra el potencial eléctrico fotovoltaico en Costa Rica. De dicha figura se observa que el mayor potencial eléctrico se obtiene en las zonas cercanas al pacifico.

<!-- Páginas 41-80 -->

> **Descripción de figura no disponible.**

<div align="center">

Figura 3.6: Potencial electrico fotovoltaico en Costa Rica.

</div>

Fuente: https://solargis.com/es/maps-and-gis-data/download/costa-rica.

## 3.4.2. Radiación solar

El sol es una estrella que se ubica en el centro del sistema solar, posee una temperatura de 5500 grados Celsius, en cuyo interior suceden una serie de reacciones que producen perdidas que se transforman en energía y llega a la tierra en forma de radiación solar. [19]

Dependiendo de como incida los rayos solares en la tierra, se puede clasificar tres componentes indispensables en la radiación solar:

- Radiación Directa: Es la radiación que recibe de forma directa desde el sol, sin que se desvié cuando pasa por la atmosfera.

- Radiación Difusa: Es la radiación que no llega directamente ya se sufre cambios debido a la reflexión en la atmosfera.

- Radiación Albedo: Es la radiación directa y difusa que se recibe por la reflexión en el suelo o superficies cercanas.

Las tres componentes forman la radiación total que llega a la tierra, la radiación directa es la que mas llega y es la que principalmente se utiliza para aplicaciones fotovoltaicas. [19]

## 3.4.3. Descripción de sistemas fotovoltaicos

Los sistemas fotovoltaicos están formados por un conjunto de componentes, eléctricos, electrónicos y mecánicos que activamente captan energía solar disponible en una superficie, esta energía que captan se transforma en energía utilizable como la energía eléctrica. [19]

Los sistemas fotovoltaicos se dividen en 3 tipos: sistemas conectados a la red, sistemas aislados y sistemas de bombeo de agua. Los sistemas interconectados a la red se utilizan en viviendas, los sistemas aislados se utilizan en lugares donde normalmente no llega ningún servicio eléctrico o se utilizan en proyectos más pequeños donde es necesario mantener uno o varios equipos conectados, los sistemas de bombeo se utilizan en lugares donde hay pozos con agua que utilizan bombas de agua. Los componentes necesarios para cada sistema fotovoltaico varian dependiendo el sistema que se elija, por ejemplo, sistemas conectados a la red necesitan de un inversor para transformar corriente continua (DC) a corriente alterna (AC).

Para propósito del proyecto presentado es necesario implementar un sistema aislado. Los componentes que conforman este tipo de sistemas son: generador fotovoltaico (Paneles), regulador de carga y baterías.

## 3.4.4. Generador fotovoltaico

La principal función del generador fotovoltaico es por medio del efecto fotoeléctrico absorber fotones de luz y emitir electrones, cuando estos electrones son libres y se capturan se puede generar una corriente eléctrica que es utilizada posteriormente como electricidad. [20]

Los componentes que forman un generador fotovoltaico son:

- Célula: Transforma la radiación solar en energía eléctrica continua

- Modulo: Es un conjunto de células interconectadas que se montan en un marco resistente a la intemperie.

- Panel: Es la unión de varios paneles.

Los generadores fotovoltaicos se pueden fabricar a partir de distintos procesos,

entre ellos:

Monocristalino: En este proceso las células se fabrican a partir de bloques cilindricos de silicio, donde se cortan los cuatro lados del cilindro con el fin de construir laminas con bordes redondeados por el que se coloca abundante silicio. Este tipo de fabricación permite obtener purezas muy elevadas, lo que provoca un aumento en el rendimiento de cada célula, este rendimiento suele ser de hasta 20 %. [21]

Policristalino: Este proceso de fabricación es distinto al monocristalino; en este caso el silicio se funde con impurezas y se vierte en un molde cuadrado, como producto de este proceso se forman policristales que disminuyen la eficiencia de las células. El color de las células es azul mas claro y el rendimiento suele rondar los 16 %. Debido a que la eficiencia de las células disminuye, la generación de energía puede ser inferior al monocristalino, por lo que esta tecnología es adecuada cuando se cuenta con grandes superficies de terreno donde es posible instalar mas paneles. La ventaja principal de esta tecnología radica en su precio, el cual es bastante inferior si se compara con los monocristalinos. [21]

## 3.4.5. Reguladores de Carga

Los reguladores de carga incorporan un microprocesador que controlan los procesos de carga y descarga en las baterías. Las principales funciones del regulador de carga se enumeran a continuación.

- Protección contra sobrecarga: Cuando la batería llega al punto máximo de carga, el regulador corta el suministro proveniente de los paneles para evitar que la batería se dañe.

- Protección contra sobredescarga: Cuando las baterías llegan al punto mínimo de descarga, el regulador desconecta las baterías evitando que estas se dañen producto de una profundidad de descarga elevada. La profundidad de descarga depende de las baterías que se elijan, normalmente se establece una profundidad de descarga del 50 %.

- Protecciones contra sobreintensidades y sobretensiones: Otra función importante del regulador de carga es mantener el voltaje y la corriente óptima cuando se cargan las baterías, de esta manera se evita sobretensiones y sobreintensidades que puedan dañar la vida útil de las baterías.

## Reguladores PWM

Los reguladores PWM (Pulse width modulation) se basan en tecnología de modulación de ancho de pulso, estos reguladores permiten por medio de pulsos de alta frecuencia pasar la tensión de los paneles, la anchura de cada pulso depende del tiempo en que se deje pasar la tensión. Estos reguladores dependen del ciclo de trabajo, este ciclo de trabajo se origina en relación con el tiempo que deja pasar la tensión y el tiempo que no deja pasar nada. Los reguladores PWM permiten introducir más corriente sin necesidad de aumentar la tensión, esto permite obtener estados de carga de aproximadamente 95 % en la batería. [22]

Los reguladores PWM están formados por un transistor el cual tiene la función de unidad de control, este transistor funciona poniendo a la misma corriente y tensión los paneles y las baterías, esto provoca pérdidas que puede llegar de 25 a 30

## Reguladores MPPT

Los reguladores MPPT incluyen el control PWM por lo que la carga de las baterías se controla por pulsos, además de este control trae integrado un circuito MPPT el cual permite que los paneles funcionen en su punto máximo de potencia, esto permite reducir las pérdidas a 10 %. Se recomienda utilizar regulares MPPT en instalaciones de gran tamaño donde se busque generar la mayor cantidad de energía posible. [22]

Una ventaja de los regulares MPPT es que permite a los paneles y baterías trabajar a distinto voltaje, esto provoca que los paneles puedan trabajar en su punto máximo de potencia reduciendo las perdidas. [22]

En instalaciones aisladas, la elección de que regulador utilizar depende del siguiente criterio:

- Si se utiliza paneles de 36 o 72 células que poseen un voltaje lo suficientemente alto para cargar baterías de 12 y 24V bastara con regulares de tipo PWM.

- Si se utiliza paneles de 60 células, será obligatorio utilizar regulares MPPT, ya que estos paneles funcionan con un voltaje de punto máximo menor, por lo que si se utilizan regulares PWM el voltaje no será suficiente para cargar las baterías. Por otra parte, los reguladores MPPT permitirán ajustar los parámetros de modo que se trabaje en el punto óptimo de todos los componentes.

## 3.4.6. Baterías

Las baterías son acumuladores de energía que permiten almacenar una determinada cantidad de energía producida por los paneles. El propósito principal es almacenar la energía para luego utilizarla durante el día. [23]

Las baterías generan una corriente eléctrica debido a un proceso denominado reducción-oxidación, este proceso consiste en una reacción en la que un componente dentro de la batería gana electrones y otro la pierde. La capacidad de almacenar energía y generar corriente se degradan en el tiempo y depende de una serie de parámetros que se muestran a continuación:

- Velocidad de descarga: Es la velocidad a la que se vacía una batería. mide la velocidad con la que se vacía la batería. Entre mayor sea la velocidad de descarga menor será la vida útil de la batería.[23]

- Profundidad de carga y descarga: Es la cantidad de energía que ingresa a la batería cada vez que se carga. A mayor profundidad de carga, y descarga menor será la vida útil de la batería. Por ello, se recomienda mantener la batería con una profundidad de descarga del 50

En la actualidad existe una gran variedad de baterías para sistemas fotovoltaicos con distintos procesos de fabricación y tecnología, entre las más destacadas se encuentran:

## Baterías de plomo ácido

Las baterías de plomo ácido están formadas por celdas electroquímicas que convierten la energía eléctrica en energía química en un proceso reversible que permite poder descargar y carga la batería de manera ciclica. [24]

Estas bacterias se pueden fabricar de dos formas: inundadas y selladas. Las bacterias inundabas deben ser llenadas periódicamente con agua destilada, esto permite aumentar la vida útil de la batería, pero el mantenimiento debe ser mayor. Las baterías selladas como su nombre lo indica vienen selladas por lo que no se deberá realizar ningún mantenimiento, sin embargo, la vida útil de la batería disminuye debido al proceso de carga y descarga que provoca que con el tiempo la batería se vaya secando y queden inservibles. [25]

En las baterías de plomo ácido ocurren distintos fenómenos que pueden afectar la vida útil de la batería, estos fenómenos son la sulfatación y la estratificación.

La sulfatación ocurre en la batería cuando esta se ha descargado varias veces sin recargar o cuando se deja por periodos largos de tiempo en completa descarga. Cuando esto ocurre en la batería se puede acumular cristales que disminuyen la capacidad de almacenaje. [24]

La estratificación ocurre principalmente en las baterías inundadas cuando el electrolito se separa por densidades, donde el electrolito con mayor densidad cae al fondo y

el de menor flota encima. [24]

La principal ventaja de estas baterías es el bajo costo con respecto a todas las demás, además de que con bastante fiables. [24] Entre las desventajas esta que las baterías inundadas requieren ser instaladas en ambientes con ventilación, además de un mantenimiento regular para verificar fugas y el contenido de agua destilada, otra limitación es que no se puede colar de lado una junto a la otra. También tienen una profundidad de descarga menor en comparación con otras, esto provoca que tengan que ser cargadas con mayor frecuencia. El promedio de vida útil varia de 3 a 10 años. [25]

## 3.5. Descripción de los principales principios físicos y/o electrónicos relacionados con la solución del problema.

## 3.5.1. Regresión Lineal y correlación lineal

La regresión lineal y la correlación lineal simple son métodos estadísticos que estudian la relación lineal que existe entre dos variables. Antes de profundizar en cada uno de ellos, conviene destacar algunas diferencias: [26]

- La regresión consiste en la generación de una ecuación (modelo) que describe la relación existente entre ambas variables, esto permite predecir el valor de una variable a partir de la otra, mientras que la correlación cuantifica que tan relacionadas están las dos variables. Esto es importante, ya que, no basta con conocer la ecuación que describe la recta, sino es necesario verificar otros parámetros para determinar que efectivamente ambas variables se relacionan.

- En estudios de regresión lineal es común que una variable se controle y la otra se mida. En la correlación lo único que se desea saber es si las variables están relacionadas.[26]

- Por norma general, los estudios de correlación lineal preceden a la generación de modelos de regresión lineal. Primero se analiza si ambas variables están correlacio-

nadas y, en caso de estarlo, se procede a generar el modelo de regresión, ya que aun siendo la línea que mejor se ajusta a las observaciones de entre todas las posibles, el modelo puede ser malo.[26]

## Regresión lineal

La regresión lineal simple consiste en generar un modelo de regresión (ecuación de una recta) que permita explicar la relación lineal que existe entre dos variables. En el modelo estadístico la variable Y (también llamada variable explicada) se relaciona con la variable X (también llamada variable predictiva). [27]

El modelo de regresión lineal simple esta dado por la siguiente ecuación:

$$
Y _ {i} = \alpha + \beta X _ {i} + \in_ {i}
$$

Donde $ Y_{i} $ es la i-ésima observación de la variable dependiente, $ X_{i} $ es la i-ésima observación de la variable independiente, $ \alpha $ es la ordenada en el origen, $ \beta $ es la pendiente $ y\in es $ un error aleatorio.

La variable independiente se mantiene fija y es establecida por el investigador, esto supone que para valores fijos de X se podrían dar distintos valores para la variable Y. [27]

Diagrama de dispersión: El diagrama de dispersión es un gráfico con escala aritmética con 2 ejes, en el eje horizontal se presenta la variable independiente y en el eje vertical la variable dependiente. Este gráfico indica la relación entre ambas variables y en caso de estarlo indica la clase de línea o ecuación que describe dicha relación. El gráfico de dispersión se dibuja a partir de los intervalos (X,Y) de cada observación realizada, donde X y Y son las variables independientes y dependientes respectivamente.


> **Descripción de figura no disponible.**

<div align="center">

Figura 3.7: Diagramas de dispersion

</div>

Fuente: [27]

## Correlación lineal

Para determinar y estudiar la relación lineal entre dos variables es necesario determinar parámetros que permitan identificar dicha relación. Uno de estos parámetros es la covarianza, que indica la variación conjunta de dos variables. Para poder hacer comparaciones se estandariza la covarianza, generando lo que se conoce como coeficientes de correlación. Existen diferentes tipos, de entre los que destacan el coeficiente de Pearson, Rho de Spearman y Tau de Kendall. [26]

## Coeficiente de correlación lineal

El coeficiente de correlación lineal r mide la dependencia lineal existente entre la variable X y Y, este coeficiente no tiene dimensiones y siempre varía entre -1 y 1. [28]

- Si las variables son independientes r = 0.

- Si r>0 existe una relación directa entre las variables, es decir si se aumenta X, se aumenta Y.

- Si r<0 existe una relación inversa entre las variables, es decir si aumenta Y, se disminuye Y.

- Si existe una relación lineal exacta r toma el valor de -1 (relación inversa) y +1

(relación directa).

En la mayoría de los casos un coeficiente de correlación mayor que 0.75 o menor que -0.75 es considerado bastante aceptable, mientras que un coeficiente de correlación que cae 0.3 y -0.3 es considerado muy bajo.

Coeficiente de determinación

El coeficiente de determinación $ r^{2} $ describe el porcentaje de variabilidad de la variable independiente Y explicada por el modelo de regresión lineal. Su valor está acotado entre 0 y 1.

Cuando el coeficiente de determinación adquiere valores cercanos a 1, mayor será el ajuste del modelo, por el contrario, cuando adquiere valores cercanos a 0, menor será el ajuste del modelo, este último resulta en modelos poco fiables.

Un $ r^{2} $ mayor del 0.75 % indica una buena asociación lineal entre las variables, por lo que la variable X puede usarse para predecir Y.

Intervalo de confianza: Consiste en calcular dos números entre los cuales se encuentra el valor del parámetro poblacional que se desea estimar con una determinada probabilidad, dichos números son los límites del intervalo. [29] El intervalo de confianza es un indicador de la presión de una estimación: Cuanto más amplio sea el intervalo de confianza menor es la presión de la estimación. [30] El intervalo de confianza utilizado normalmente es IC=95 %, lo que indica que se puede estar 95 % seguro de que el intervalo de confianza contiene la media poblacional.

Para comprobar si la línea de regresión es significativa, se establecen las siguientes relaciones: [31]

- Hipótesis nula $ H_{0}, \beta=0 $

- Hipótesis alternativa $ H_{1}, \beta\neq0 $

- P es la probabilidad, está dada entre 0 y 1.

Se comprueba si el valor verdadero de la pendiente, $ \beta $ , es igual a 0. Si la línea es totalmente horizontal, la pendiente es cero y no existe ninguna relación lineal entre las variables. Pero, si la línea no es horizontal, la pendiente no es cero, y puede ser que exista

una relación entre las variables. [31]

Si P<0.05 se rechaza la hipótesis y si P>0.05 se acepta la hipótesis. Si se rechaza la hipótesis quiere decir que la variable X es importante para predecir la variable Y usando el modelo de regresión. Si se acepta la hipótesis esto quiere decir que la variable X no es importante para predecir la variable Y.

Residuos: El residuo es la diferencia entre el valor observado y el valor estimado por la linea de regresión, en otras palabras se puede considerar como el error aleatorio observado. En el análisis de los residuos se puede detectar:

- Si hay normalidad de los errores.

- Si efectivamente existe relación lineal entre las variables.

- Si existen valores anormales.

- Si hay independencia de los errores.

## 3.5.2. Cálculos asociados al sistema fotovoltaico

Para modelar sistemas fotovoltaicos es necesario conocer la carga que tienen los componentes utilizados con el fin de determinar el consumo diario, para ello es necesario conocer de antemano dos términos muy importantes, potencia eléctrica y energía eléctrica.

La potencia eléctrica de un circuito es la energía que se consume, se transporta o se genera cada instante en que el circuito esta encendido, dicho de otro modo representa el ritmo al que se consume, se transporta o genera la energía. El valor de la potencia se encuentra multiplicando la corriente por el voltaje[32]

$$
P = V * I \quad [ \mathrm {W} ]
$$

Donde P es la potencia en watts, I es la corriente del aparato en amperios y V es el voltaje en volts.

La energía es la capacidad que tiene un cuerpo de generar trabajo, su unidad de medida es el julio (J). Un julio es la energía que se transporta por un conductor cuando por este pasa una corriente y una intensidad de valor uno en un tiempo de un segundo.

[32] Cuando hablamos de consumos ya sea diarios o mensuales es conveniente utilizar otro sistema de unidades y este son los watts hora, en otras palabras, un kilovatio-hora (kWh) es la energía correspondiente a una potencia de 1 kW funcionando durante 1 h. Para calcular la energía se utiliza la ecuación 3.3

$$
E = P * H \quad [ \mathrm {W h} ]
$$

Donde E es la energía, P es la potencia y H son las horas de funcionamiento del componente eléctrico.

El consumo diario vendría siendo la energía, sin embargo, este valor no se puede tomar ya que para modelar sistemas fotovoltaicos es conveniente multiplicar el consumo diario por un factor de protección, este factor de protección toma en consideración las pérdidas que se generen en los componentes que conformen el sistema fotovoltaico.

$$
\text{Consumo Diario} = E * 20 \% \quad [\text{Wh}]
$$

Donde E es la energía y 20 % equivale al factor de protección que normalmente se utiliza cuando se modelan este tipo de sistemas.

Para determinar o definir el voltaje de operación del sistema fotovoltaico es necesario tener en cuenta varios criterios de diseño:

- De 1 a 2000 Wh de consumo diario, se recomienda hacer el sistema de 12V.

- De 2001 a 4000 Wh de consumo diario, se recomienda hacer el sistema a 24V.

- De 4001 Wh en adelante se recomienda hacer el sistema a 48V.

Cabe mencionar que todos los componentes que conformen el sistema fotovoltaico deberán trabajar al mismo voltaje.

Para calcular los modulo fotovoltaicos, se calcula la potencia fotovoltaica requerida, ecuación 3.5.

$$
\text{Potencia fotovoltaica requerida} = \frac{\text{Consumo diario}}{\text{Hora mínima solar}}
$$

La hora solar mínima depende del sitio donde se instalará el sistema fotovoltaico y de las condiciones solares.

Para determinar los módulos fotovoltaicos necesarios se utiliza la ecuación 3.6.

$$
\mathrm {N u m e r o d e m o d u l o s} = \frac {\mathrm {P o tencia f o t o v o l t a i c a r e q u e r i d a}}{\mathrm {P o tencia m o d u l o s}}
$$

En esta ecuación la potencia fotovoltaica requerida es la potencia necesaria para el funcionamiento de todos los componentes y la potencia del módulo es la potencia que genera el módulo fotovoltaico, este valor de potencia de modulo viene determinado por el fabricante y varía dependiendo del módulo que se elija.

Para determinar la batería o el conjunto de baterías es necesaria calcular el consumo de corriente durante el día, para ello se utiliza la ecuación 3.7.

$$
\mathrm {C o n s u m o C o r r i e n t e} = \frac {\mathrm {C o n s u m o D i a r i o}}{\mathrm {V o l t a j e S i s t e m a}} \quad [ \mathrm {A h} / \mathrm {d i a} ]
$$

Una vez obtenido el valor del consumo de corriente se utiliza la ecuación 3.8 para calcular el número de baterías en paralelo.

$$
\text{Número de baterías en paralelo} = \frac {\frac {\text {Consumo Corriente}}{\text {Días autonomía}}}{\frac {\text {Profundidad de descarga}}{\text {Capacidad Batería}}}
$$

Para determinar las baterías en serie se toma en consideración el voltaje del sistema y el voltaje de funcionamiento de la batería, por ejemplo:

- Si el voltaje del sistema es de 12V y el voltaje de la batería es de 12V, no será necesario hacer arreglo en serie.

- Si el voltaje del sistema es de 24V y el voltaje de la batería es de 12V, será necesario hacer dos arreglos en serie.

- Si el voltaje del sistema es de 48V y el voltaje de la batería es de 12V, será necesario hacer tres arreglos en serie.

## Capítulo 4

## Procedimiento Metodológico

En el siguiente capítulo se detalla el proceso metodológico seguido para identificar el problema, así como diferentes soluciones que puedan dar fin al problema surgido, a partir de la necesidad de digitalizar algún proceso que necesita mejorarse. Por otra parte, se analizará los componentes necesarios para realizar la implementación de la solución, se hace una comparativa entre los principales módulos del sistema. Finalmente se evalúa el desempeño y se proponen diferentes alternativas para el mejoramiento del sistema.

## 4.1. Reconocimiento y definición del problema

## 4.1.1. Generalidades

El CIEDES en sus diferentes proyectos de apoyo a la gestión de Asadas debe mantener un monitoreo constante de los cambios diarios y estacionales que puedan provocar un desabastecimiento del agua potable. Para conocer estos cambios es necesario monitorrear la variación del nivel de líquido a lo largo del día. Actualmente el CIEDES realiza estudios en la asada ubicada en Las Juntas de Abangares, en esta asada se realizan mediciones manuales puntuales del nivel de líquido en el tanque de captación y distribución de agua potable, estas mediciones las realiza por lo general un funcionario de la asada cada quince días y aunque se le solicite realizar mediciones más seguidas, estas no se realizan o los datos no son del todo confiables. Por otra parte, trasladarse hasta el sitio donde se

encuentra el tanque para la toma de medición conlleva una inversion de dinero y tiempo.

Planificar el uso del agua en distintas comunidades es de mucha importancia, ya que, con el creciente aumento en la población el abastecimiento del agua puede no ser el adecuado. En épocas del año donde el clima no permite recolectar grandes cantidades de agua proveniente del río, debido a la reducción del nivel de agua provocado por las grandes olas de calor y el intenso sol, y sumado al hecho de que en esas épocas del año el consumo por persona aumenta significativamente, puede ocasionar cortes del suministro de agua en la comunidad. Por lo que, es fundamental conocer la variación del agua durante el día, sin embargo, el sistema actual de medición no permite evaluar cambios estacionales o diarios y construir un modelo el cual pueda predecir el comportamiento del consumo del agua no es posible.

## 4.1.2. Síntesis del problema

El monitoreo del nivel de líquido en el tanque ubicado en la ASADA de Abangares es deficiente, la medición puntual del nivel de líquido que se realiza no permite conocer el comportamiento de la demanda y el suministro.

## 4.2. Obtención y análisis de información

Se realizo una primera reunión en la que se conoció al Señor Edwin Solórzano Campos, Director del Centro de Investigación en Desarrollo Sostenible en la UCR (CIEDES), esta reunión se hizo de manera virtual debido a cuestiones de confinamiento debido a la pandemia que se vivía en el 2020, en esta reunión y en otras se conversó acerca del propósito y el impacto que puede ocasionar el desarrollar un proyecto como estos en Las Juntas de Abangares, por otra parte se dio énfasis a las limitaciones que tenía el proyecto en cuanto a la zona.

Otro punto importante mencionado es que el CIEDES se encuentra realizando diferentes proyectos en Abangares desde hace varios años y entre los principales proyectos a desarrollar actualmente es un estudio en cuando al consumo diario en la zona y ha

expresado que los datos que se miden del agua no son suficientes para realizar dichos estudios. Por lo que una de las metas es realizar la transición de un sistema manual de medición a un sistema digital con el fin de obtener más datos y tener acceso a la información de una manera más sencilla y rápida.

## 4.3. Limitaciones y requerimientos

Para delimitar el alcance en el diseño de la solución es necesario tener en cuenta algunas limitaciones de la zona ver tabla 4.1, así como algunos requerimientos impuestos por el Director del CIEDES Edwin Solorzano ver tabla 4.2.

<div align="center">

Tabla 4.1: Tabla de limitaciones debido a la zona

</div>

<table border="1"><tr><td>Limitaciones</td><td>Detalle</td></tr><tr><td>Acceso a electricidad</td><td>No existe fuente cercana que suministre corriente al tanque de almacenamiento de agua.</td></tr><tr><td>Acceso vía GSM</td><td>En la zona no es posible acceder a internet, únicamente se puede acceder mediante mensajes vía GSM.</td></tr></table>

La ubicación de la zona donde se instalará el dispositivo medidor juega un papel muy importante, nos encontramos en una zona de difícil acceso a electricidad y a redes wifi.

<div align="center">

Tabla 4.2: Tabla de requerimientos

</div>

<table border="1"><tr><td>Requerimientos</td><td>Detalle</td></tr><tr><td>Almacenamiento de datos</td><td>El sistema podrá almacenar la información del sensor de líquido, así como la fecha y hora asociada a la medición.</td></tr><tr><td>Visualización de datos</td><td>Acceso remoto a los datos, visualización de la información almacenada mediante la generación de gráficos y archivos descargables en excel.</td></tr><tr><td>Periodicidad de las mediciones</td><td>El sistema deberá tomar mediciones cada 20 minutos o cada hora dependiendo de la hora del día.</td></tr></table>

Los requerimientos de la tabla 4.2 surgen a lo largo de diferentes reuniones para determinar las necesidades o requerimientos del cliente; al tratarse de un proyecto centrado en el monitoreo de una variable física, es importante definir el periodo con el que se va a realizar cada medición; en las distintas reuniones con Director del (CIEDES), él comentaba que se podría definir 2 mediciones: cada hora y cada 20 minutos, nos interesa una medición más periódica de 20 minutos cuando nos encontremos en las horas de desayuno (5 a 8 am), almuerzo(11am a 1pm) y cena (5 a 8 pm) donde el consumo de agua se puede disparar y una medición de cada hora en las otras horas del día.

Por otra parte, debido a la naturaleza del proyecto donde se requieren datos del nivel de líquido para realizar diferentes estudios, es importante que el manejo de los datos sea de una manera flexible para el usuario o usuarios finales, entre los requisitos era poder acceder a la información ingresando la fecha, una vez ingresada la fecha se muestra los valores medios y gráficos de dicha fecha, otro requisito importante es poder acceder a la información mediante archivos descargables compatibles con excel.

## 4.4. Evaluación de las alternativas y síntesis de una solución

## 4.4.1. Evaluación de alternativas de solución

Para dar solución a la problemática es necesario contar con un sistema que tome muestras o mediciones con el fin de determinar el nivel de líquido presente en el tanque, para ello el sistema de adquisición deberá contar con una serie de componentes que unidos realizaran las funciones necesarias que se requieran.

Entre las principales funciones se encuentra medir el nivel de liquido, para ello será necesario utilizar algún sensor que permita conocer el nivel de líquido en el tanque, además, de registrar el tiempo de cada medición por lo que utilizar un RTC (Real Time Clock por sus siglas en inglés) será indispensable. Como se indica en la tabla 4.1 una limitación de la zona es el acceso a internet, en este caso será imprescindible contar con un dispositivo que permita conectarse a internet como lo es un módulo SIM, entre las principales funciones que podemos destacar del módulo SIM es poder recibir y realizar mensajes de texto y llamadas, y la más importante y en la cual trabajaremos durante la implementación del proyecto es en conectarse a internet; por último y no menos importante es el procesador, este será el encargado de coordinar todos los dispositivos mencionados anteriormente.

La figura 4.1 muestra un diagrama general del sistema de adquisición de datos a implementar con todos los componentes necesarios a utilizar.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.1: Diagrama de componentes del sistema de adquisición de datos Fuente: Elaboración Propia

</div>

Anteriormente se mencionó que es necesario un sistema de adquisición de datos, sin embargo, para cumplir los requerimientos de la tabla 4.2 y limitaciones de la tabla 4.1, será necesario disponer de otros sistemas, entre ellos el sistema de potencia y el sistema de visualización de datos. Se decide dividir la solución del proyecto de la manera anterior ya que se puede ver cada sistema como sistemas que desempeñan funciones distintas, la tabla 4.3 muestra un resumen de los sistemas a implementar.

<div align="center">

Tabla 4.3: Sistemas necesarios para la implementación de la solución

</div>

<table border="1"><tr><td>Sistema</td><td>Función</td></tr><tr><td>Adquisición de datos</td><td>Sensado y transmisión del nivel de liquido.</td></tr><tr><td>Visualización de datos</td><td>Almacenar los datos del nivel de liquido, además de visualizar los datos según cumpla los requerimientos de la tabla 4.2.</td></tr><tr><td>Potencia</td><td>Suministrar la energía suficiente que permita el funcionamiento del sistema de adquisición de datos.</td></tr></table>

A continuación, se detalla algunas posibles alternativas para dar solución al problema presentado. Las soluciones propuestas poseen los sistemas mencionados en la tabla 4.3.

## Alternativa de solución 1

Anteriormente se detalló los componentes necesarios para el sistema de adquisición de datos; el sistema de potencia implementado deberá diseñarse en función del consumo de todos los componentes utilizados en el sistema de adquisición de datos, más adelante se detallara los pasos necesarios para la implementación del sistema de potencia.

En la primera alternativa de solución se pretende realizar el diseño siguiendo la figura 4.2. En esta solución se decide visualizar la información en una página web, de este modo cualquier dispositivo electrónico tendrá acceso a la información siempre y cuando se ingrese la url proveniente de la página web que se diseñe.

Al trabajar en una página web se decide utilizar un servidor web contratado, el servidor permite almacenar los datos por medio de una base de datos en este caso MariaDB.

El sistema de adquisición de datos realiza el sensado y los datos obtenidos del sensor se transmiten por medio del protocolo HTTP hasta almacenar los datos en la base de datos en el servidor contratado. Al contratar un servidor se evita agregar componentes adiciones al sistema final, por otra parte, existe servidores gratuitos como lo puede ser XAMPP el cual es un sistema de gestión a base de datos, si se decide implementar un servidor como el mencionado anteriormente será necesario una computadora o algún dispositivo que permita la instalación de XAMPP como lo es una raspberry pi.

Utilizar un servidor contratado puede aportar muchas ventajas, entre ellas podemos destacar el mantenimiento del servidor mejorando la gestión y la experiencia del usuario, medidas de seguridad implementadas por el servidor (sistema de antivirus, certificados SSL), por otra parte, hay muchas empresas que ofrecen distintos planes de alojamientos Host a un precio bastante económico.

Para crear la página web se utiliza principalmente PHP para la gestión de la base

de datos MySQL y se utiliza HTML y CSS para dar diseño y estilo a la página web, de esta forma se puede obtener una plataforma visual atractiva.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.2: Solución utilizando el protocolo HTTP

</div>

Fuente: Elaboración Propia

## Alternativa de solución 2

Otra alternativa de solución se puede observar en la figura 4.3, al igual que la solución anterior los sistemas de Adquisición de datos y de potencia se detallarán más adelante, para propósitos de solución nos interesa el entorno de visualización de datos y el protocolo de transmisión de datos.

En esta solución se utiliza el protocolo MQTT, este protocolo de transmisión de datos es un sistema de publicación y suscripción de diferentes topics, como se observa en la figura 4.3 el sistema de adquisición de datos publica en un topic, estos topics son temas establecidos por ejemplo "Abangares/altura_tanque", en este caso se publica la altura

del tanque en un topic denominado Abangares; para acceder a dicho topic será necesario suscribir los dispositivos que tendrán acceso a la información, de esta forma luego de realizar la publicación al tema se visualiza la información en una aplicación diseñada para cada dispositivo conectado al tema.

Para realizar dicho flujo de información es necesario contar con un bróker que será el responsable de recibir, filtrar y publicar los distintos mensajes en los diferentes clientes suscritos.

Existen brokers gratuitos como Mosquito y al igual que la solución anterior si se decide implementar uno será necesario algún dispositivo adicional, sin embargo, se puede optar por un proveedor de servicio en la nube como lo puede ser IBM, microsoft azure, AWS Iot (Amazon web server por sus sigla en inglés) entre otros.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.3: Solución utilizando el protocolo MQTT parte 1 Fuente: Elaboración Propia

</div>

se puede observar en la figura 4.4, en esta alternativa se decide visualizar los datos en una página web, de esta forma se evita el diseño de aplicaciones para cada dispositivo suscrito al tema. Para ello será necesario contar con un web socket. Web socket es una tecnología presente en navegadores y servidores web y que permite la comunicación bidireccional en nuestro caso entre el servidor web y el bróker. Por otro lado, la página web para visualizar los datos es diseñada en HTML y CSS.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.4: Solución utilizando el protocolo MQTT parte 2 Fuente: Elaboración Propia

</div>

## 4.4.2. Elección de componentes

## Selección sensor

Entre los principales componentes a elegir se encuentra el sensor de nivel, este componente es de suma importancia ya que permite conocer el nivel de líquido presente en el tanque, por lo que es importante elegir el sensor adecuado. Los principales sensores de nivel que podemos encontrar en el mercado son los sensores de nivel puntual y los sensores de nivel de medición continuo.

El sensor de nivel puntual permite conocer el nivel de líquido en un tanque, pero a un nivel puntual, es decir únicamente se puede conocer una altura en específico; por lo general este tipo de sensor se utiliza para la activación de alguna bomba o generación de algún tipo de alarma. Un gran atractivo de estos sensores es la gran variedad en el mercado, entre los sensores que podemos encontrar se encuentran los siguientes: Sensor de nivel de capacitancia, Sensor de nivel óptico, Sensor de nivel de conductividad, Interruptor de flotador. [33] Para propósitos del proyecto desarrollado utilizar algún sensor que brinde una medición puntual como los mencionados anteriormente no es factible ya que uno de los propósitos principales de llevar a cabo la implementación del proyecto es conocer la variación de nivel de líquido en el tiempo.

Por consiguiente, surge la necesidad de obtener una medición continua. Entre las alternativas se encuentra los sensores de nivel de medición continuo, la variedad de estos sensores en el mercado es muy poca, principalmente se encuentra los sensores ultrasónicos. Por otra parte, en sustitucion al sensor de nivel se podría utilizar un sensor de presión que mida la presión que ejerce el líquido en el fondo del tanque.

A continuación, se comparan ambas alternativas analizando ventaja y desventajas de su implementación.

## Sensor de nivel ultrasónico AJ-SR04

El sensor de nivel ultrasónico pertenece a la familia de sensores de proximidad donde las componentes principales a medir es la magnitud del tiempo y la distancia. Estos sensores no necesitan estar en contacto con el líquido medio, lo único necesario es

que el líquido medido refleje la onda del sensor. Como se muestra en la figura 4.5 el sensor ultrasónico se coloca en la parte superior del tanque y su función es medir la distancia entre el punto de referencia (nivel máximo) y el nivel de líquido presente en el tanque.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.5: Diagrama de medición utilizando el sensor de nivel ultrasónico Fuente: Elaboración Propia

</div>

Una de las características del sensor ultrasónico digital de la figura 4.6 es su impermeabilidad; este sensor tiene dos pines denominados trig y echo, el funcionamiento es muy básico, el pin trig envía un pulso de sonido y a partir de la captura del pulso en el pin Echo se calcula la diferencia de tiempo entre los pines, la altura del tanque se determina en base a la velocidad del pulso en el aire.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.6: Sensor de nivel ultrasónico AJ-SR04 Fuente: MicroJPM

</div>

Sensor de presión diferencial MPX5500DP

Los sensores de presión diferencial MPX no pueden estar en contacto con el líquido, estos sensores poseen dos puntas que se encargan de obtener las presiones, una punta mide la presión ejercida en el fondo del tanque y la otra punta mide presión ejercida en la parte superior del tanque. Debido a que el sensor no puede estar en contacto con el agua es necesario instalar el sensor fuera del tanque o como se muestra en la figura 4.7 instalarlo en la parte superior del tanque, de tal manera que será necesario comprar una manguera que ira conectada en las dos puntas del sensor. Al obtener las presiones superior e inferior la diferencia entre ellas permite obtener la presión hidrostática y mediante la ecuación que describe la presión en los fluidos se despeja la altura del tanque.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.7: Diagrama de medición utilizando el sensor de presión diferencial Fuente: Elaboración Propia

</div>

El sensor analógico de presión diferencial MPX5500DP que se muestra en la figura 4.8 entrega a la salida de 0 a 5 voltios ideal para trabajar con microcontroladores. El comportamiento del voltaje entregado por el sensor es lineal, a medida que aumenta el voltaje de salida del sensor, la presión en kilo pascales [Kpa] aumenta.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.8: Sensor de presión diferencial MPX5500DP Fuente: CRCibernetica

</div>

La tabla 4.4 muestra el costo y el consumo de cada alternativa de sensor.

<div align="center">

Tabla 4.4: Tabla de costos y consumo energético sensores

</div>

<table border="1"><tr><td>Componente</td><td>Precio[$]</td><td>Consumo[mA]</td></tr><tr><td>AJ-SR04</td><td>17,95</td><td>8</td></tr><tr><td>MPX5500DP</td><td>16,95</td><td>20</td></tr></table>

El sensor que se decide utilizar es el sensor ultrasónico, como se puede ver en la tabla 4.4 el bajo consumo energético del sensor AJ-SR04 es muy considerable con respecto al MPX5500DP, por otra parte los precios de ambos dispositivos son muy similares siendo la diferencia apenas de un dólar, adicionalmente se tiene que considerar el precio de la manguera si se decide utilizar el sensor MPX5500DP. Otra punto importante a considerar es la instalación del sensor, al tratarse de un tanque que se encuentra a nivel del suelo es conveniente instalar el sensor como se muestra en la figura 4.5, de esta forma se ahorra el colocar la manguera en la parte inferior del tanque tal y como se muestra en la figura 4.7. Por ultimo y el punto más importante fue la característica de impermeabilidad siendo el sensor ultrasónico el único que posee dicha cualidad, por consiguiente, la alternativa más clara a elegir es el sensor ultrasónico el cual lo hace ideal para ambientes húmedos como los de un tanque de almacenamiento de agua.

## Selección microprocesador

Un componente indispensable cuando hablamos de proyectos digitales es el microcontrolador capaz de ejecutar las instrucciones previamente establecidas en la memoria. Entre las alternativas que podemos encontrar en el mercado a un bajo precio, bajo consumo y fácil acceso son los siguientes:

## Arduino nano

El microcontrolador arduino es un dispositivo compacto,de bajo precio y consumo, posee I/O analógicas y digitales, salidas PWM. Esta placa es de código abierto, posee su propio software de programación denominado IDE arduino y su sintaxis de programación es muy similar a c y c++. Ademas posees interfases como SPI Interfaz periférica serial, UART Transmisor receptor asíncrono universal y $ I^{2} C $ . [34] y [35]


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.9: Arduino nano

</div>

Fuente: CRCibernetica

-ESP32

El microcontrolador ESP32 pertenece a la familia de chips SoC (tecnología que integra todos o gran parte de módulos que componen un computador). Este chip posee wifi, bluetooth, pines analógicos y digitales, salidas PWM, interfases de comunicación como SPI Interfaz periférica serial, UART transmisor receptor asíncrono universal y $ I^{2} C $ Entre los entornos de desarrollo se encuentra IDF de Espressif, entorno de desarrollo integrado arduino IDE y además es compatible con micropython. [36] y [37]


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.10: ESP32

</div>

Fuente: CRCibernetica

Raspberry Pi Zero

un ordenador de placa reducida y es compatible con varios sistemas operativos diseñados exclusivamente para esta placa, el más común es raspbian, ahora denominado Raspberry PI OS, este sistema operativo está basado en GNU/Linux llamada Debian el cual es un sistema libre desarrollado por miles de personas en todo el mundo.Además, esta placa incorpora una ranura de tarjeta microSD, puertos microUSB, posee 40 pines de entradas y salidas de propósito general GPIO. [38] y [39]


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.11: Raspberry Pi Zero Fuente: MicroJPM

</div>

<div align="center">

Tabla 4.5: Tabla de costos y consumo energético microcontroladores

</div>

<table border="1"><tr><td>Componente</td><td>Precio[$]</td><td>Consumo[mA]</td></tr><tr><td>Arduino nano</td><td>795</td><td>15</td></tr><tr><td>ESP32</td><td>1495</td><td>20</td></tr><tr><td>Raspberry Pi Zero</td><td>2495</td><td>40</td></tr></table>

Para la selección de que microcontrolador utilizar se analiza la tabla 4.5, en ella vemos que el precio y el consumo energético de las raspberry pi zero es muy considerable con respecto a las otras opciones por lo que queda descartado utilizar la raspberry pi.

Tanto el arduino nano como el esp32 son chips altamente potentes y para el proyecto implementado donde no se requiere mucha memoria o gran procesamiento utilizar cualquiera de los dos sería una gran opción, sin embargo, comparando los precios y el consumo energético se decide utilizar el arduino nano.

## Modulo SIM

Otro componente importante en el sistema de adquisición de datos es el módulo SIM, este permite realizar la conexión a internet y enviar los datos mediante algún protocolo. Para ello se analizan dos dispositivos del mismo fabricante, pero con distintas tecnologías. Para elegir el módulo adecuado es necesario estudiar las bandas con las que funciona cada proveedor en el país, dichas bandas se pueden observar en la tabla 4.6.

<div align="center">

Tabla 4.6: Resumen de bandas proveedores servicio SIM Costa Rica

</div>

<table border="1"><tr><td>Proveedor</td><td>Tecnología</td><td>Bandas</td></tr><tr><td rowspan="3">Kolbi</td><td>2G</td><td>B3(1800MHz)</td></tr><tr><td>3G</td><td>B5(850MHz)</td></tr><tr><td>4G</td><td>B3(1800MHz)yB7(2600MHz)</td></tr><tr><td rowspan="3">Claro</td><td>2G</td><td>B(1900MHz)</td></tr><tr><td>3G</td><td>B1(2100MHz)</td></tr><tr><td>4G</td><td>B3(1800MHz)</td></tr><tr><td rowspan="3">Movistar</td><td>2G</td><td>B3(1800MHz)</td></tr><tr><td>3G</td><td>B1(2100MHz)yB5(850MHz)</td></tr><tr><td>4G</td><td>B3(1800MHz)</td></tr></table>

## SIM900

El módulo SIM900 de la figura 4.12 es un módulo fabricado por simcom el cual permite realizar conexiones GPRS esta conexión permite acceder a internet utilizando únicamente redes 2G, las bandas de funcionamiento del módulo es 850/900/1800/1900. Entre las principales características del módulo SIM es que permite utilizar comandos para realizar distintos protocolos de transmisión como los son: TCP/IP, UDP, HTTP, FTP; por otra parte, el módulo posee antena, microfono, pines GPIO entre otros. Principalmente nos interesa la conexión GPRS ya que únicamente se hará uso de eso. [40]


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.12: Modulo SIM900

</div>

Fuente: Amazon.

## SIM7600CE

Otro gran alternativa es utilizar el módulo de la figura 4.13, al igual que el anterior modulo el chip es fabricado por simcom con la salvedad que la tecnología utilizada para su diseño es más moderna, este módulo permite realizar conexiones 2G, 3G, y LTE 4G. Las bandas que utiliza cada tecnología se muestran a continuación: GSM/GPRS/EDGE -> 9000/1800 MHz, WCDMA/HSPDA/HSPA+ -> B1/B8, LTE -> B1/B3/B8 entre otras bandas. Adicionalmente el módulo tiene antena 4G y permite realizar distintos protocolos en sus comandos como TCP/IP, HTTP, MQTT, UDP, entre otros. [41]


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.13: Módulo SIM7600CE Fuente: Mouser

</div>

El módulo SIM que se decide utilizar es el SIM7600CE debido a que este utiliza tecnología 3G y 4G, con lo que se puede obtener mayor cobertura en la zona de Abangares con los operadores Kolbi y claro como se observa en la sección de anexos A.2.

Otro componente indispensable a utilizar es el RTC. Este componente tendrá como única función registrar el tiempo y hora actual. Para ello se analizan dos alternativas como vemos en la tabla 4.8.

<div align="center">

Tabla 4.7: Tabla de costos RTC

</div>

<table border="1"><tr><td>Componente</td><td>Precio[$]</td></tr><tr><td>RTC DS1307</td><td>2,95</td></tr><tr><td>RTC DS3231</td><td>5,95</td></tr></table>

Se decide utilizar el RTC DS3231 de la figura 4.14 debido a que es la versión más reciente del DS1307.


> **Descripción de figura no disponible.**

<div align="center">

Figura 4.14: RTC Real Time clock"DS3231 Fuente: CRCibernetica

</div>

## Selección de panel solar y regulador de Carga

Según las limitaciones de la tabla 4.1, es necesario un sistema de potencia el cual provee de toda la energía necesaria para que el sistema de adquisición de datos funcione correctamente durante todo el año.

A continuación se detallan algunas alternativas en cuanto a paneles y reguladores, cada alternativa se eligió en base a los requisitos de consumo de todos los componentes utilizados en el sistema de adquisición de datos, los cálculos realizados para la correcta selección de los componentes del sistema de potencia se detallan en el capítulo 5.

Panel solar + regulador de carga, marca Tp Solar

El panel solar es de 20W monocristalino de alta eficiencia, posee resistencia al agua IP65.

El regulador de carga es de 10A apto para baterías de plomo ácido, AGM y GEL. Entre las características posee una interfaz de fácil operación, protección contra cortocircuitos, protección de descarga inversa de la batería, protección de polaridad inversa, protección de circuito abierto, protección contra sobrecarga. Puede soportar una potencia máxima de 100W a 12V y 200W a 24V.

Panel solar + regulador de carga, marca Eco Worthy

El panel solar es de 25W policristalino, las células son de alta eficiencia. El regulador de carga es de 3A y posee una salida USB de 5V a 3A.

Panel solar + regulador de carga, marca Solperk

El panel solar es de 20W monocristalino con células de alta eficiencia, resistente al agua.

El regulador de carga es de 8A, posee mantenimiento inteligente completamente automático, protección contra cortocircuitos, protección de circuito abierto, protección inversa, protección de sobrecarga, protección de bajo voltaje, protección de sobrecarga para mejorar la eficiencia del sistema. Puede cargar baterías de 12V como Wet, GEL, AGM.

<div align="center">

Tabla 4.8: Tabla de costos kit panel + regulador

</div>

<table border="1"><tr><td>Marca</td><td>Precio en $</td></tr><tr><td>Tp Solar</td><td>49.99</td></tr><tr><td>Eco Worthy</td><td>55.99</td></tr><tr><td>Solperk</td><td>59.95</td></tr></table>

Cualquier panel fotovoltaico de los mencionados anteriormente funciona a la perfección ya que todos son de 20W o superior, sin embargo, se descarta el de eco worthy debido a que las células son policristalinas y comparando con el monocristalino la eficiencia puede ser menor, por lo que las opciones a considerar son Tp Solar y solperk. La elección de que kit utilizar recae en el regulador de carga y en el precio, se decide utilizar el kit de Tp solar, debido a que el regular de carga puede soportar un poco más, siendo este de 10A, además el precio es menor.

## Selección de las baterías

Al igual que la selección del panel solar y el regulador de carga, para seleccionar la batería se toma en consideración los cálculos realizados en el capitulo 5. La capacidad de la batería deberá ser mínimo de 14Ah, sabiendo este dato se procede a buscar la batería en el mercado costarricense. Para la elección de la batería se decide utilizar tecnología de plomo-ácido sellada debido al bajo precio y al poco mantenimiento, en Costa Rica se encontró únicamente baterías de 7Ah y 17Ah. El precio de las baterías se muestra en la tabla 4.9.

<div align="center">

Tabla 4.9: Tabla de costos kit panel + regulador

</div>

<table border="1"><tr><td>Capacidad</td><td>Precio en $</td></tr><tr><td>7Ah</td><td>26.35</td></tr><tr><td>17Ah</td><td>63.9</td></tr></table>

para obtener una capacidad de 14Ah, sin embargo, utilizar baterías en paralelo no es recomendable debido a los siguientes aspectos: una batería se carga y la otra se descargar más rápido, corrientes de fuga entre las baterías; esto a la larga puede afectar la vida útil de la batería. Otro aspecto importante es que al regulador de carga le puede costar más cargar dos baterías que una sola o no seria tan eficiente regulando ambas cargas. Por esta razón se decide utilizar solo una batería de 17Ah. A pesar de que se supera la capacidad necesaria no representaría ningún problema en el diseño final.

Por otra parte la diferencia en precios entre ambas soluciones no es tan grande, dos baterías de 7Ah ronda los 53 dolares y una batería de 17Ah ronda los 64 dolares.

## 4.5. Implementación de la solución

Para la ejecución y desarrollo de la solución se siguió una serie de pasos que dieron fin al proyecto, estos pasos se detallan a continuación:

- Primeramente se define los requerimientos y las limitaciones del proyecto. También se estudian diferentes soluciones que puedan dar solución al problema y se elige una con la cual trabajar.

- Se cotiza algunos componentes en el mercado costarricense y extranjero. Se realiza una comparación entre los componentes y se elige el adecuado según criterios mencionados anteriormente. Entre los componentes se encuentra sensores, microcontroladores, módulos SIM, paneles solares, reguladores de carga, baterías y demás. Por otra parte, para el almacenamiento de los datos se decide contratar un hosting, de esta manera se sustituye la compra de más componentes. Al contratar el hosting se toma en cuenta la capacidad del disco, la memoria RAM, el CPU, el servicio al cliente, el precio mensual, entre otros; todas estas características proporcionan una gran ventaja al consumidor, además de que brinda todo el soporte y mantenimiento necesario.

- Una vez que se escoge todos los componentes, se estudia los lenguajes de programación necesarios, por una parte, se tiene el lenguaje c con el que funciona los microcontroladores, php para la administración de la base de datos del hosting,

lenguaje de etiqueta html y css para dar estilo y forma a la página web.

- Una vez contratado el hosting, se crea la base de datos en el CPanel que proporciona el hosting contratado y se genera una tabla que contendrá todos los datos, en la tabla se asigna un id para cada medición realizada y los parámetros de fecha, hora y la medición del nivel de liquido en el tanque.

- Se crea un usuario con privilegios que permita ingresar datos en el servidor. Luego se realiza un sketh en php que permite establecer la conexión con el servidor y la base de datos, para ello se ingresa los datos del servidor, la base de datos, el usuario con privilegios y la contraseña.

- Se crea otro sketch en php para ingresar el dato a la tabla mediante el método GET. Para probar que efectivamente se suben datos a la tabla se utiliza el navegador web de la computadora y se ingresa la URL con los parámetros por el método GET.

- Luego se realizan pruebas para determinar la presión del sensor y se calibra mediante una ecuación utilizando la regresión lineal. Se realizan mediciones a distintas alturas con el fin de definir el modelo lineal.

- Se estudian los comandos AT con los que funciona el módulo SIM, en los comandos AT está el protocolo http por lo que principalmente se estudian esos comandos y los de establecer la conexión a la red, así como otros más básicos como agregar el pin del sim.

- Luego se realizó el sketch del sistema de adquisición de datos, el sketch engloba la toma de los datos, el establecimiento de la conexión y el envío de los datos mediante el protocolo http.

- Cada vez que se envía un comando el módulo SIM responde, entre las respuestas esta que todo salió correcto y el comando se ejecutó bien o incorrecto cuando el comando no se ejecutó correctamente. De esta manera se agrega una rutina para verificar que efectivamente los comandos se ejecutan correctamente.

- Debido a que se necesita tomar medidas a ciertas horas del día, se decide implementar un interruptor timer que encienda el sistema de adquisición de datos, para ello se utiliza un transistor FET de potencia, este al trabajar en la zona de saturación y corte se comporta como un interruptor. El transistor seleccionado deberá soportar la corriente máxima de la carga que ronda los 2A.

- Para diseñar el entorno de visualización de datos, se estudia bootstrap y google-

charts, además de html y css. Para mostrar los datos se accede a la base de datos por medio de php. El lenguaje php tiene funciones establecidas para recorrer la tabla y guardar los datos en una matriz como por ejemplo la función mysqli_fetch_array().

- Luego se estudia la carga que tienen los componentes del sistema de adquisición de datos y se dimensiona los componentes del sistema de potencia. Para verificar que el sistema de potencia funcione correctamente a lo largo del año, se realiza dos simulaciones, una en PVSyst y otra en PVGis.

- Debido a que las baterías trabajan a 12V y todos los componentes funcionan a 5V, se utilizan reguladores de voltajes de 12V a 5V. El regulador para el circuito timer entrega poca corriente ya que este no necesita mucha; mientras que el sistema de adquisición de datos el regulador deberá brindar mínimo 2A debido a que el modulo SIM puede presentar picos de corrientes elevados.

- Se diseño las PCBs donde se colocarán los componentes y se manda a imprimir a una empresa China.

- Finalmente se conecta el sistema de adquisición de datos al sistema de potencia y se verifica que ambos funcionen correctamente.

## 4.6. Reevaluación y rediseño

Inicialmente se estaba realizando las pruebas con el módulo SIM900, este módulo fue proporcionado por el director del CIEDES, él comentaba que este módulo lo tenía desde hace ya algún tiempo, por esta razón se decide utilizar este módulo. Para realizar las pruebas se buscó un sitio cerca de la casa con las mismas condiciones de cobertura que las de Abangares, sin embargo, luego de realizar distintas pruebas el módulo se vuelve un poco lento para establecer la conexión a internet, cuando esto sucede algunos comandos AT fallan por lo que se acumula un error, estos casos no son siempre, pero si ocurren periódicamente. Además, este módulo solo permite conexiones 2G por lo que la cobertura se ve muy limitada, por otra parte, este módulo es el primero que salió al mercado ya hace varios años con una tecnología bastante vieja. Por esta razón se decide utilizar el módulo SIM7600 que permite redes 2G, 3G y 4G, de esta manera se puede dar una solución con un dispositivo más actualizado, además que la cobertura mejora enormemente ya que el

módulo permite conectarse a cualquier red.

Debido a que el sistema de adquisición solo tomará 40 mediciones durante el día, se decide implementar un interruptor timer, esto con el fin de reducir el consumo energético en gran medida. Si bien es cierto existen modos sleeps tanto para el arduino como para el módulo SIM7600CE no se deciden utilizar ya que el modo sleep del SIM7600CE alcanza un consumo de corriente 20mA, por esa razón el implementar un interruptor a utilizar modos sleeps no habrá un beneficio tan significativo, además de que mantener el consumo de un timer interruptor en un sistema que este captando energía diariamente no supondría ningún riesgo, ya que el sistema de potencia se diseña tomando en consideración el consumo del timer el cual es muy pequeño.

## Capítulo 5

## Descripción detallada de la solución

En el presente capitulo se detalla la solución elegida por medio de la comparación de las soluciones propuestas, además se especifica los sistemas necesarios para la implementación de la solución, así como la descripción de hardware y software utilizado.

## 5.1. Análisis de soluciones y selección final

En el capítulo 4 se presentan dos soluciones ambas muy similares, la diferencia principal radica en el protocolo de transmisión que se utiliza, la primera solución utiliza el protocolo HTTP, mientras que la segunda solución utiliza el protocolo MQTT. Para elegir que solución utilizar se comparan ambas soluciones destacando ventajas y desventajas de los distintos protocolos.

Antes de comparar las dos soluciones propuestas es importante mencionar un concepto muy importante el cual engloba estos dos grandes protocolos y este es el Internet de las Cosas o IoT (por sus siglas en ingles), este se refiere a dispositivos físicos que están conectados a internet, todos recopilando y compartiendo información en cada instante; gracias a chips en el mercado con gran capacidad de procesamiento a un precio bastante accesible ahora es posible conectar cualquier dispositivo a internet, esto permite enviar datos en tiempo real sin necesidad de que una persona esté presente en dicho proceso. [42] Un claro ejemplo de IoT es la domótica, este consiste en un conjunto de elementos o

<!-- Páginas 81-120 -->

sistemas capaces de automatizar los procesos en una vivienda; mediante la gestión inteligente de la seguridad, las comunicaciones, la iluminación y la energía se busca mejorar el bienestar de las personas. [43] Por lo general, estos sistemas están conformados por una gran cantidad de sensores que activamente están recopilando y enviando información con el fin de automatizar algún proceso desde algo tan pequeño como encender una luz hasta el control de alarmas en caso de que algo no esté bien, entre otros. Es importante tener en cuenta que estos dispositivos deben contar con gran seguridad, ya que si se desea controlar el encendido de un dispositivo es importante que dicho proceso se realice adecuadamente sin que otros puedan interferir o manipular dicho proceso.

<div align="center">

Tabla 5.1: Cuadro comparativo entre los protocolos HTTP y MQTT

</div>

<table border="1"><tr><td>HTTP</td><td>MQTT</td></tr><tr><td>Es un protocolo de Solicitud/Respuesta entre Cliente/Servidor.</td><td>Es un protocolo de Publicación/Suscripción que es gestionado por un bróker.</td></tr><tr><td>Mantiene la conexión activa durante un breve periodo de tiempo mientras el dato se envía.</td><td>No cierra la conexión, por lo que esta puede ser utilizada el mayor tiempo posible.Esta es una de las principales ventajas cuando se envían múltiples mensajes.</td></tr><tr><td>No hay cola compartida porque se tiene que reestablecer la conexión cada vez que se envía un dato.</td><td>Al no cerrarse la conexión los dispositivos remotos suscritos publican los datos en una cola compartida, por lo que este mismo posee un gestor de colas para organizar en los diferentes temas.</td></tr><tr><td>Se centra en la transmisión de documentos.</td><td>Se centra en la transmisión de datos a nivel de bytes.</td></tr><tr><td colspan="2">Continúa en la siguiente página</td></tr></table>

<div align="center">

Tabla 5.1 - Continuación de la página anterior

</div>

<table border="1"><tr><td>HTTP</td><td>MQTT</td></tr><tr><td>Especificaciones de mensajes más largas, lo que permite redactar mensajes y encabezados largos, la cabecera más pequeña tiene 26 bytes.</td><td>Especificaciones de mensajes bastante cortas, el tamaño del mensaje de paquete más pequeño es de 2 bytes.</td></tr><tr><td>El cliente tiene que solicitar los datos; el servidor tiene que buscar y procesar los datos solicitados, esto puede ser impulsado por eventos establecidos.</td><td>El servidor puede enviar los datos sin que el cliente lo solicite.</td></tr><tr><td>Establece una conexión TCP half díplex por lo que la información solo puede viajar en un solo sentido.</td><td>Establece una conexión TCP full díplex por lo que la información puede viajar en ambos sentidos.</td></tr><tr><td></td><td>Funciones de última voluntad: En caso de que un cliente se desconecte repentinamente a un tema, todos los demás clientes recibirán una notificación por parte del bróker.</td></tr><tr><td></td><td>Retención de mensajes: Esto permite que un cliente que se suscriba a un tema recibe una actualización de datos inmediata.</td></tr></table>

En redes 3G MQTT es 93 veces más rápido, usa 8 veces menos tráfico y gasta 170 veces menos energía en los receptores. En otros escenarios en pruebas realizas por flespi MQTT fue al menos 20 veces más rápido, usa 50 veces menos tráfico y es energéticamente un 22 % más eficiente. [44]

Podría decirse que MQTT es más seguro que HTTP, ya que una conexión que siempre esta activa se puede establecer de una manera más compleja. Cada vez que un

dispositivo necesita enviar datos a un sistema HTTP, los protocolos de seguridad deben restablecerse, pero en MQTT esto se puede hacer solo una vez. [45]

Dado que no se espera que se restablezcan las conexiones en MQTT, se puede implementar una función de seguridad manual mediante la cual cualquier dispositivo que intente conectarse debe ser autorizado mediante confirmación manual en una estación central [45]

El protocolo MQTT tiene claras ventajas con respecto al protocolo HTTP cuando hablamos de redes IoT donde existe una gran cantidad de sensores obteniendo y enviando información. Al poseer encabezados muy cortos el protocolo MQTT utiliza menor consumo energético, además utiliza un ancho de banda menor, por lo que el tiempo de respuesta es menor, esto permite que el protocolo no colapse cuando se envían muchos datos de diferentes dispositivos.

Ahora bien, como se mencionó en el capítulo 4, es necesario realizar 40 mediciones durante el día, cada vez que se hace una medición esta se transmite con el fin de tener un monitoreo actualizado regularmente. Al tener este tipo de sistema de monitoreo las claras ventajas del protocolo MQTT no son tan significativas con respecto al protocolo HTTP, por lo que ambos protocolos funcionarian bien. Por otra parte, la implementación de HTTP podría ser más sencilla ya que es posible generar una red de transmisión utilizando un archivo PHP con los métodos POST o GET.

En la solución 1 se decide utilizar una página web como medio de visualización de datos, esto permite que cualquier dispositivo pueda acceder de manera fácil a los datos, en el sentido del proyecto la seguridad no juega un papel tan importante, por lo que los datos pueden ser utilizados por cualquier persona ajena al CIEDES, tanto la comunidad como cualquier organización tendrá acceso a ellos.

De esta manera ahora si comparamos las dos propuestas de la solución 2, en la primera se debe realizar distintas aplicaciones para los distintos dispositivos que tendrán acceso a la información, por lo que sería conveniente en este sentido utilizar un web socket para mostrar los datos en una página web como se muestra en la segunda propuesta, de esta manera al igual que la solución 1 todos tendrán acceso a la información y no habría inconvenientes ya que la seguridad no es importante. Cabe mencionar que ambos

protocolos funcionan bien, la decisión de cual elegir recae en el diseñoador.

En este caso se decide implementar la solución 1 ya que como se menciona, la implementación de esta podría ser más sencilla debido a los archivos PHP que se generen, por otra parte, en la solución 2 la conexión entre el bróker y el web socket puede ser más compleja y como las claras ventajas del protocolo MQTT sobre el HTTP en el proyecto no son significativas se decide utilizar el protocolo HTTP.

## 5.2. Descripción del hardware

El hardware son los elementos tangibles que forman un sistema, en otras palabras, se refiere a los componentes, eléctricos, mecánicos y electrónicos que unidos forman un sistema que realiza distintas funciones.

## 5.2.1. Hardware Sistema adquisición de datos

## Arduino Nano

El microcontrolador arduino nano es la versión reducida del arduino uno, este posee un menor consumo energético, además de un tamaño bastante reducido. El procesador que utiliza es el Atmega328P, posee 6 pines analógicos y 14 pines digitales, entre otros. Tanto los pines analógicos como digitales serán utilizados por lo que únicamente se mencionan esos dos, sin embargo, la descripción de todos los pines se detalla en la figura 5.1. [34] y [35]


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.1: Descripción Pines arduino nano

</div>

Fuente: https://components101.com/microcontrollers/arduino-nano.

## AJ-SR04

El sensor ultrasónico AJ-SR04, es un sensor impermeable, brinda valores en el rango de 20cm a 800cm, por lo que podemos ver que posee una zona muerta en la cual el sensor no puede medir. El protocolo de comunicación que utiliza es TTL, con el pin TRIG transmite varios trenes de pulsos, estos se reflejan en el líquido y luego un tren de pulsos es recibido por el pin ECHO. La conexión del sensor junto con el arduino nano se puede observar en la tabla 5.2. Fuente: Hoja de datos AJSR04. [46]

<div align="center">

Tabla 5.2: Tabla de conexión pines, AJ-SR04 con el arduino nano

</div>

<table border="1"><tr><td>Pin AJ-SR04</td><td>Pin Arduino nano</td></tr><tr><td>Trig</td><td>D2</td></tr><tr><td>Echo</td><td>D3</td></tr><tr><td>Vcc</td><td>Vcc</td></tr><tr><td>GND</td><td>GND</td></tr></table>

## SIM7600CE

El módulo SIM 7600CE soporta comunicación 2G, 3G y 4G, además de redes como GPRS, EDGE, WCDMA, HSDPA, HSPA+ y LTE; el control del módulo se hace mediante comandos AT, estos comandos permiten conectar el módulo SIM a internet, por otra parte, este posee comandos para establecer distintos protocolos de transmisión como lo son TCP/IP, UDP, HTTP, MQTT, FTP, entre otros. Mediante la utilización de los pines TX y RX se establece una comunicación serial entre el arduino nano y el módulo SIM. Al conectar el módulo SIM a la alimentación este estará en modo standby por lo que es necesario el pin 12, este tiene la función de interruptor por lo que poner alguna salida del arduino en alto por algunos segundos permite que el módulo se encienda. [41]

<div align="center">

Tabla 5.3: Tabla de conexión pines, SIM7600 con arduino nano

</div>

<table border="1"><tr><td>Pin SIM7600</td><td>Pin Arduino Nano</td></tr><tr><td>Tx(D7)</td><td>D7</td></tr><tr><td>Rx(D8)</td><td>D8</td></tr><tr><td>D12</td><td>D12</td></tr><tr><td>Vcc</td><td>Vcc</td></tr><tr><td>GND</td><td>GND</td></tr></table>

## RTC DS3231

El reloj de tiempo real DS3231, es un módulo el cual registra la fecha y hora del día. Este funciona con el protocolo $ I^{2} C $ , además posee una batería de litio de 3V CR2032 con un tiempo de duración de aproximadamente 10 años, esta última característica es muy importante ya que puede mantener la fecha incluso si se corta el suministro de alimentación. En la tabla 5.5 se puede observar la conexión de los pines. [47]

<div align="center">

Tabla 5.4: Tabla de conexión pines, DS3231 con arduino nano

</div>

<table border="1"><tr><td>Pin DS3231</td><td>Pin Arduino nano</td></tr><tr><td>SDA</td><td>A4</td></tr><tr><td>SCL</td><td>A5</td></tr><tr><td>Vcc</td><td>Vcc</td></tr><tr><td>GND</td><td>GND</td></tr></table>

La figura 5.2 muestra el diagrama de conexión de todos los componentes del sistema de adquisición de datos.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.2: Diagrama de conexión del sistema de adquisición de datos

</div>

Fuente: Elaboración Propia utilizando el software fritzing.

## Interruptor timer utilizando el transistor IRFZ48n

El transistor IRFZ48n es un transistor de tipo FET, específicamente MOSFET, este es de alta potencia que puede soportar una corriente de drenador de 64A y un voltaje

entre drenador y fuente de 55V. Se utiliza un transistor de potencia debido a que el módulo SIM puede presentar picos de hasta 2A. [48] Para que el transistor opere como interruptor es necesario que este trabaje en la región de saturación y corte. El arduino nano y el RTC DS3231 controlan los tiempos de encendido del sistema de adquisición de datos mediante la activación de un pin digital que controla la región de operación del transistor. La ventaja de utilizar un transistor MOSFET es que se puede activar mediante el voltaje, en este caso se busca un transistor que pueda ser activado con los 5V que brinda el pin del arduino.

La figura 5.3 muestra las curvas características de operación del transistor IRFZ48n, del gráfico se observa que con un voltaje en la compuerta de 4.5V el transistor puede conducir una corriente de 4A, este transistor es ideal para nuestra aplicación debido a que conduce más de 2A.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.3: Caracteristicas de salida transistor IRFZ48n Fuente: Datasheet IRFZ48n.

</div>

<div align="center">

Tabla 5.5: Tabla de conexión pines, IRFZ48n con arduino nano

</div>

<table border="1"><tr><td>Pin DS3231</td><td>Pin Arduino nano</td></tr><tr><td>Gate</td><td>D7</td></tr><tr><td>Drain</td><td>Conectado al negativo del sistema de adquisición de datos.</td></tr><tr><td>Source</td><td>GND</td></tr></table>

Para que el transistor opere adecuadamente es necesario agregar unas resistencias con el fin de polarizar el transistor. La figura 5.4 muestra el diagrama de conexión del interruptor timer. La resistencia $ R_{G} $ permite proteger al arduino de una corriente inversa que pueda generar el transistor, además los transistores FET se activan con voltaje en la compuerta, por lo que gran parte de la corriente que da el pin del arduino se queda en la resistencia $ R_{G} $; por otra parte, la resistencia $ R_{S} $ tiene la función de que cuando el pin digital del arduino este apagado no quede un pin flotante lo que puede provocar el mal funcionamiento del transistor. El valor de $ R_{G} $ deberá ser pequeño, mientras que el valor de $ R_{S} $ deberá ser grande, de este modo todo el voltaje que proporciona el arduino queda en la resistencia $ R_{S} $ y gran parte de la corriente queda en $ R_{G} $ . La ecuación 5.1 muestra el voltaje en la compuerta, de la ecuación vemos que para que todo el voltaje llegue a la compuerta la resistencia $ R_{S} $ deberá ser bastante mayor con respecto a $ R_{G} $ .

$$
V _ {G} = \frac {V _ {P I N _ {A R D U I N O}} * R _ {S}}{R _ {G} + R _ {S}} \quad [ \mathrm {V} ]
$$


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.4: Diagrama de conexión del interruptor, SP = Sistema Potencia, SAD = Sistema Adquisición Datos.

</div>

Fuente: Elaboración Propia utilizando el software fritzing.

## 5.2.2. Hardware Interfaz visualización de datos

Se contrata un servicio hosting LiteSpeed, el que se contrata es lucusthost, este brinda las siguientes características, versión de PHP: 7.3.27, alojamiento de un dominio con 10 GB de espacio SSD NVMe, sin límite de tráfico, 1024 MB de RAM, 70 % de CPU, cPanel y SSL gratis.

## 5.2.3. Hardware Sistema autónomo de potencia

## Panel Solar

El panel solar tiene una fabricación de las células tipo monocristalina de alta eficiencia, proporciona una potencia de 20W, voltaje de circuito abierto (Voc) de 21.8 V, voltaje de potencia máxima (Vmp) de 18V, corriente de corto circuito (Isc) de 1.23 A,

corriente de potencia máxima (Imp) 1.11 A. Tiene una dimensión de 18.9x13.4x0.7in. El panel es resistente al agua IP65.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.5: Panel Solar monocristalino.

</div>

Fuente: Amazon.

## Regulador de Carga

El regulador de carga es PWM, trabaja en un voltaje nominal de 12 y 24 V, la corriente nominal es de 10A, soporta un voltaje máximo de panel de 50V y el máximo de potencia que puede soportar es 130W para una configuración de 12V y 260W para una configuración de 24V. El regulador posee una certificación ISO9001 para la gestión y aseguramiento de la calidad.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.6: Regulador de Carga.

</div>

Fuente: Amazon.

Batería

La batería es de plomo ácido sellada, posee una capacidad de 17Ah y trabaja a 12V. Al utilizar baterías selladas se ahorra el mantenimiento de esta, sin embargo, hay que tener en cuenta que la batería no puede estar en un lugar completamente cerrado ya que la temperatura de la batería puede aumentar dañándola.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.7: Batería marca dLux.

</div>

Fuente: Elaboración Propia.

La figura 5.8 muestra el diagrama de conexión del sistema de potencia. El panel solar, la batería y el sistema de adquisición de datos se conectan al regulador de carga.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.8: Diagrama de conexión Sistema de Potencia Fuente: Elaboración Propia.

</div>

## 5.3. Descripción del software

El código del sistema de adquisición de datos se muestra en la figura 5.9. Este sistema se accionado por un circuito que funciona como interruptor, el código del circuito interruptor es muy sencillo, únicamente realiza la verificación de la hora y enciende el sistema de adquisición de datos en caso de ser necesario por medio del mosfet. Apenas se inicia el sistema de adquisición de datos, el código realiza la verificación de la hora para tomar el dato, se realizan varias lecturas del nivel de líquido y se promedian, luego se ajusta la lectura según el modelo de regresión lineal obtenido, después se toma el dato de la fecha y la hora y se genera una URL concatenando los datos a enviar.

Para transmitir el dato se envía una serie de comandos AT uno por uno verificando la respuesta del comando enviado, si es la respuesta esperada se envía el siguiente comando sino se envía el mismo comando de nuevo.

Los comandos AT se envían por el serial desde el arduino hasta el SIM7600, cada vez que se envía un comando el SIM7600 responde, de esta forma se puede leer el serial

para verificar que efectivamente el comando se ingreso adecuadamente. Las respuestas de los comandos son: OK o ERROR, otros comandos brindan información adicional como el estado de la conexión a internet o la respuesta del protocolo HTTP cuando se envía los datos por la URL.

<div align="center">

Tabla 5.6: Tabla de comandos utilizados

</div>

<table border="1"><tr><td>Comando</td><td>Descripción</td></tr><tr><td>AT</td><td>Sirve para identificar que el modulo SIM7600 funcione correctamente.</td></tr><tr><td>AT+CPIN</td><td>Permite ingresar el PIN de la tarjeta SIM, este comando es necesario para reconocer el SIM.</td></tr><tr><td>AT+CREG</td><td>Indica si el modulo SIM se ha conectado a la red.</td></tr><tr><td>AT+HTTPINIT</td><td>Inicia el protocolo HTTP.</td></tr><tr><td>AT+HTTPPARA</td><td>Ingresa los parámetros a enviar mediante la URL.</td></tr><tr><td>AT+HTTPACTION</td><td>Indica el método a utilizar para el envió, los metodos son: GET, POST, HEAD, DELETE.</td></tr><tr><td>AT+HTTPTERM</td><td>Cierra el protocolo HTTP.</td></tr><tr><td>AT+CSQ</td><td>Proporciona la cantidad y la calidad de la señal recibida.</td></tr></table>


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.9: Diagrama de flujo del código del sistema adquisición de datos.

Fuente: Elaboración Propia.

</div>

## 5.4. Calibración sensor AJ-SR04

Como se mencionó en el capítulo 1, uno de los requerimientos del proyecto es que los datos provenientes del sensor sean datos confiables, dicho de otro modo datos precisos de nivel de líquido, para ello se realizan dos pruebas de calibración. Estas pruebas consisten en una serie de mediciones a distintas alturas con el fin de definir la presión del sensor. En la sección de anexo se adjunta las tablas respectivas de las pruebas realizadas.

Se realizan dos pruebas estableciendo una altura con una escala y tomando mediciones a dicha altura, al ser una prueba realizada por una persona es importante considerar errores asociados al sistema de medicion empleado, por esta razón se decide realizar 2 pruebas. A continuación la figura 5.10 y 5.11 muestran los valores promedios de las pruebas realizadas, cada prueba consta de 20 mediciones cada 20 centímetros.

<table border="1"><tr><td colspan="6">Datos promedio prueba 1</td></tr><tr><td>Valor real</td><td>Valor medio</td><td>Valor real</td><td>Valor medio</td><td>Valor real</td><td>Valor medio</td></tr><tr><td>20</td><td>18,92</td><td>120</td><td>116,93</td><td>220</td><td>214,90</td></tr><tr><td>40</td><td>38,60</td><td>140</td><td>136,02</td><td>240</td><td>235,74</td></tr><tr><td>60</td><td>58,28</td><td>160</td><td>156,11</td><td>260</td><td>254,77</td></tr><tr><td>80</td><td>77,70</td><td>180</td><td>174,83</td><td>280</td><td>274,31</td></tr><tr><td>100</td><td>97,11</td><td>200</td><td>195,44</td><td>300</td><td>294,09</td></tr></table>

<div align="center">

Figura 5.10: Resumen de los promedios prueba 1.

</div>

Fuente: Elaboración Propia.

<table border="1"><tr><td colspan="6">Datos promedio prueba 2</td></tr><tr><td>Valor real</td><td>Valor medio</td><td>Valor real</td><td>Valor medio</td><td>Valor real</td><td>Valor medio</td></tr><tr><td>20</td><td>19,54</td><td>120</td><td>117,67</td><td>220</td><td>215,12</td></tr><tr><td>40</td><td>38,47</td><td>140</td><td>137,12</td><td>240</td><td>236,21</td></tr><tr><td>60</td><td>57,95</td><td>160</td><td>156,77</td><td>260</td><td>255,01</td></tr><tr><td>80</td><td>77,84</td><td>180</td><td>176,43</td><td>280</td><td>275,77</td></tr><tr><td>100</td><td>97,68</td><td>200</td><td>196,51</td><td>300</td><td>295,12</td></tr></table>

<div align="center">

Figura 5.11: Resumen de los promedios prueba 2.

</div>

Fuente: Elaboración Propia.

Como se observa ambas pruebas muestran valores muy parecidos, con datos bastante precisos, mediciones mayores a 150cm poseen una incertidumbre aproximada de 5cm, mientras que alturas menores a 150cm la incertidumbre disminuye. La diferencia de

valores entre ambas pruebas se debe a errores del sistema de medición empleado y a la variabilidad de valores que el sensor aporta, ya que este último no brinda un valor exacto para cada medición, sino que brinda valores muy cercanos.

Para propósito de análisis de regresión y correlación lineal se decide utilizar los datos de la prueba 1, ya que ambas pruebas presentan mismas características. De esta manera se analiza la relación existente entre el valor real y el valor medio por el sensor.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.12: Gráfico de dispersion prueba 1.

</div>

Fuente: Elaboración Propia utilizando el software minitab.

La figura 5.12 muestra el diagrama de dispersion de todos los datos obtenidos de la prueba 1, como se ve en dicha figura la línea de color rojo es la recta que mejor se ajusta al modelo. Sin embargo, para determinar que efectivamente es un modelo confiable se realiza el análisis de correlación.

<div align="center">

Correlaciones en parejas de Pearson

</div>

<table border="1"><tr><td>Muestra 1</td><td>Muestra 2</td><td>Correlación</td><td>IC de 95% para ρ</td><td>Valor p</td></tr><tr><td>Valor Real</td><td>Valor Medido</td><td>1,000</td><td>(1,000; 1,000)</td><td>0,000</td></tr></table>

<div align="center">

Figura 5.13: Datos obtenidos correlación Pearson.

</div>

Fuente: Elaboración Propia utilizando el software minitab.

<div align="center">

Correlaciones en parejas de Spearman

</div>

<table border="1"><tr><td>Muestra 1</td><td>Muestra 2</td><td>Correlación</td><td>IC de 95% para p</td><td>Valor p</td></tr><tr><td>Valor Real</td><td>Valor Medido</td><td>0,998</td><td>(0,997;0,998)</td><td>0,000</td></tr></table>

<div align="center">

Figura 5.14: Datos obtenidos correlación Spearman.

</div>

Fuente: Elaboración Propia utilizando el software minitab.

Para determinar el coeficiente de correlación lineal se emplea la correlación de Pearson y Spearman figuras 5.13 y 5.14 respectivamente, con un intervalo de confianza IC=95 %. El coeficiente r es 1 para Pearson y 0.98 para Spearman, de lo anterior podemos afirmar que existe una relación directa lo cual es esperado, ya que estamos midiendo la misma variable.

El coeficiente de determinación $ r^{2} $ obtenido se muestra en la figura 5.15, este es 1, lo que indica que existe buena asociación lineal y el modelo esta ajustado a los datos. Esto es esperado ya que el coeficiente de determinación es el cuadrado del coeficiente de correlación de Pearson.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.15: Datos obtenidos del modelo de regresión.

</div>

Fuente: Elaboración Propia utilizando el software minitab.

Analizando la figura 5.16, podemos determinar si el modelo es el adecuado y cumple con los supuestos de análisis, para ello se analiza el comportamiento de los residuos. De la gráfica de probabilidad normal se observa que los residuos están distribuidos normalmente, esto debido a que los residuos siguen aproximadamente una línea recta. Del gráfico del residuo vs. ajuste, se observa que los puntos están dispersos aleatoriamente y no se observa ningún valor atípico. Del histograma podemos ver que la parte central de la distribución posee la mayor cantidad de casos comprendida entre -0.6 a +0.6, sin embargo, de este gráfico no se logra determinar que tenga una distribución simétrica, a simple vista pareciera que sí. Del gráfico de residuos vs orden se determina que los resi-

duos son independientes, ya que se ubican alrededor del eje central, no poseen tendencias ni patrones observables.


> **Descripción de figura no disponible.**

> **Descripción de figura no disponible.**

> **Descripción de figura no disponible.**

> **Descripción de figura no disponible.**

<div align="center">

Figura 5.16: Gráficos de residuos.

</div>

Fuente: Elaboración Propia utilizando el software minitab.

Del análisis anterior podemos afirmar que efectivamente ambas variables están correlacionadas y ahora es posible generar la ecuación que describe dicho modelo. La figura 5.17 y 5.18 muestra la ecuación para la prueba 1 y 2 respectivamente.

Ecuación de regresión

Valor Medido = -1,0143 + 0,982904 Valor Real

<div align="center">

Figura 5.17: Ecuación que describe el modelo de la prueba 1.

Fuente: Elaboración Propia utilizando el software minitab.

</div>

Ecuación de regresión

Valor medio = -0,8379 + 0,985339 Valor real

<div align="center">

Figura 5.18: Ecuación que describe el modelo de la prueba 2.

Fuente: Elaboración Propia utilizando el software minitab.

</div>

De las ecuaciones obtenidas para ambas pruebas se observa que la pendiente es aproximadamente la misma, siendo esta de 0,98. El otro termino varia ya que los datos tomados no son exactamente los mismos y para el cálculo de este valor es necesario el punto en el origen y los errores asociados a los residuos. Para verificar ambas ecuaciones primeramente se despejan, de tal manera, que se desea conocer el valor real a partir de la medición del sensor, esto se observa en las ecuaciones 5.2 y 5.3.

$$
\mathrm {V a l o r R e a l} = \frac {\mathrm {V a l o r M e d i d o} + 1 , 0 1 4 3}{0 , 9 8 2 9 0 4}
$$

$$
\mathrm {V a l o r R e a l} = \frac {\mathrm {V a l o r M e d i d o} + 0 , 8 3 7 9}{0 , 9 8 5 3 3 9}
$$

Una vez despejadas ambas ecuaciones se realiza una comparación utilizando los valores promedios de la figuras 5.10 y 5.11.

Como se observa en la figura 5.19 al tomar un dato del sensor y verificando el ajuste ambas ecuación funcionan correctamente, ya que, los valores entre ambos ajustes son aproximadamente el mismo, la variación que presenta es muy poca, máximo de un centímetro por intervalo. De esta forma podemos asegurar que efectivamente se calibra la presión del sensor, ya que por ejemplo si obtenemos un dato del sensor de 156,11 cm este lo aproxima a 159.860cm o 159.266cm siendo el valor real correcto de 160cm.

<table border="1"><tr><td colspan="3">Verificación ajuste utilizando datos promedio prueba 1</td></tr><tr><td>Datos</td><td>Ajuste 1</td><td>Ajuste 2</td></tr><tr><td>18,92</td><td>20,277</td><td>20,051</td></tr><tr><td>38,60</td><td>40,305</td><td>40,026</td></tr><tr><td>58,28</td><td>60,329</td><td>59,998</td></tr><tr><td>77,70</td><td>80,085</td><td>79,702</td></tr><tr><td>97,11</td><td>99,828</td><td>99,393</td></tr><tr><td>116,93</td><td>119,995</td><td>119,506</td></tr><tr><td>136,02</td><td>139,423</td><td>138,883</td></tr><tr><td>156,11</td><td>159,860</td><td>159,266</td></tr><tr><td>174,83</td><td>178,898</td><td>178,254</td></tr><tr><td>195,44</td><td>199,877</td><td>199,177</td></tr><tr><td>215,12</td><td>219,899</td><td>219,146</td></tr><tr><td>236,21</td><td>241,348</td><td>240,539</td></tr><tr><td>255,01</td><td>260,475</td><td>259,616</td></tr><tr><td>275,77</td><td>281,598</td><td>280,682</td></tr><tr><td>295,12</td><td>301,289</td><td>300,322</td></tr></table>

<table border="1"><tr><td colspan="3">Verificación ajuste utilizando datos promedio prueba 2</td></tr><tr><td>Datos</td><td>Ajuste 1</td><td>Ajuste 2</td></tr><tr><td>19,54</td><td>20,907</td><td>20,680</td></tr><tr><td>38,47</td><td>40,171</td><td>39,893</td></tr><tr><td>57,95</td><td>59,989</td><td>59,659</td></tr><tr><td>77,84</td><td>80,222</td><td>79,838</td></tr><tr><td>97,68</td><td>100,410</td><td>99,973</td></tr><tr><td>117,67</td><td>120,751</td><td>120,260</td></tr><tr><td>137,12</td><td>140,536</td><td>139,993</td></tr><tr><td>156,77</td><td>160,530</td><td>159,934</td></tr><tr><td>176,43</td><td>180,529</td><td>179,881</td></tr><tr><td>196,51</td><td>200,961</td><td>200,258</td></tr><tr><td>215,12</td><td>219,899</td><td>219,146</td></tr><tr><td>236,21</td><td>241,348</td><td>240,539</td></tr><tr><td>255,01</td><td>260,475</td><td>259,616</td></tr><tr><td>275,77</td><td>281,598</td><td>280,682</td></tr><tr><td>295,12</td><td>301,289</td><td>300,322</td></tr></table>

<div align="center">

Figura 5.19: Verificación ajuste utilizando los datos promedios Fuente: Elaboración Propia.

</div>

Para propósitos del proyecto se decide utilizar el modelo de la prueba 1, los coeficientes de la ecuación de ajuste se muestran en la figura 5.20, el error estándar del coeficiente es bastante bajo brindando ajustes muy precisos, el valor p de 0 nos indica que se rechaza la hipótesis, esto quiere decir que la variable X es importante para predecir el valor de Y.

<div align="center">

Coeficientes

</div>

<table border="1"><tr><td>Término</td><td>Coef</td><td>EE del coef.</td><td>Valor T</td><td>Valor p</td><td>FIV</td></tr><tr><td>Constante</td><td>-1,0143</td><td>0,0658</td><td>-15,40</td><td>0,000</td><td></td></tr><tr><td>Valor Real</td><td>0,982904</td><td>0,000362</td><td>2714,28</td><td>0,000</td><td>1,00</td></tr></table>

<div align="center">

Figura 5.20: Datos obtenidos de los coeficientes.

</div>

Fuente: Elaboración Propia utilizando el software minitab.

## 5.5. Interfaz visualización de datos

El diseño de la página web fue realizado en el lenguaje de etiquetas html, además se dio estilos mediante un archivo css. Los archivos html se mezclan con código PHP esto de tal manera que la página web pueda actualizar información proveniente de la base de datos del servidor web.

Para dar diseño a la página web se utilizaron herramientas de css como lo es Bootstrap 5, esto permite escribir menos css, ya que posee muchas clases definidas; entre las funciones de las clases utilizadas se mencionan las siguientes: centrar texto en columnas, poner texto en negrita, centrar horizontalmente, centrar verticalmente ajustar márgenes derecho, izquierdo, inferior y superior. Por otra parte, se utilizan clases para dar estilo a las tablas. Bootstrap además, cuenta con clases de tipo navbar que permiten diseñar un menú ya definido por Boostrap, en este caso en la página web de Bootstrap viene un código ejemplo de un menú tipo navbar en una versión muy simple y no tan bonito a la vista, por lo que se da estilo al menú, este menú se observa en la figura 5.21.

Para la generación de gráficos se utiliza la herramienta de gráficos de Google (googlecharts), estos son potentes, fáciles de usar y gratuitos. Entre la galería de gráficos se utiliza el gráfico de área, para la generación de este gráfico se copia el código que brinda Google y se modifica según las necesidades del proyecto. Además, se usó iconos de ionicons y logos de favicon.

Para satisfacer los requerimientos mencionados en capítulos anteriores es necesario generar una sección de consultas y descargas por fechas. Para ello, es necesario recorrer la base de datos con la fecha que se desea consultar o descargar. La fecha que se ingrese se guarda por el método POST, esto permite que los datos no sean visibles en la url de la página web.

Para ingresar a la base de datos es necesario crear un archivo php, el cual permita conectar un usuario con privilegios a la base de datos, este usuario con privilegios es distinto al usuario con el que ingresamos al gestor de la base de datos. La única función del usuario con privilegios es dar permiso para el acceso a la base de datos.

El archivo principal de la página web es index.php, el cual se podrá ver como el

inicio de la página web, este se observa en la figura 5.21. En este se muestra las ultimas 5 mediciones realizadas, esto con el fin de mantener informado a las personas que ingresen al sitio web con los datos más recientes de nivel de líquido en el tanque, se muestra una tabla y un gráfico para una mejor comprensión de los datos.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.21: Página web inicio.

</div>

Fuente: Elaboración Propia.

En la figura 5.22, se observa la sección de consultas.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.22: Página web sección consultas.

</div>

Fuente: Elaboración Propia.

Para la generación del archivo descargable en excel, primeramente, se había hecho con puro código en PHP y mediante unos headers, se generaba un archivo xls, sin embargo, este tipo de archivo no era compatible con las versiones más nuevas de office, por lo

que se decide utilizar una librería denomina phpExcel, aunque bien existe una versión actualizada denominada phpSpreed, se decide utilizar phpExcel, debido a que la versión actualiza necesita un composer para su instalación. La librería phpExcel permite generar archivos en el formato xlsl el cual es compatible con las nuevas versiones de office. La sección de descargas se muestra en la figura 5.23.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.23: Página web sección de descargas.

</div>

Fuente: Elaboración Propia.

## 5.6. Sistema de potencia

Para dimensionar el sistema de potencia requerido es necesario hacer un estudio de la carga de todos los componentes que se vayan a utilizar. Para determinar el consumo es necesario conocer el voltaje y el amperaje que cada componente requiera. Para ello, se decide realizar la medición de la corriente de cada componentes por separado utilizando un multimetro, de esta forma obtenemos un valor de corriente real en vez de utilizar los datos mostrados en el capítulo 4, los cuales fueron obtenidos de la hoja de datos de los fabricantes. La tabla 5.7, muestra el consumo de potencia de cada componente utilizado. Cabe mencionar que para el modulo SIM se toma un consumo de corriente de 2A, esto debido a que el modulo SIM puede presentar picos de hasta 2A por lo que el sistema deberá soportar dicho consumo.

<div align="center">

Tabla 5.7: Consumo de potencia componentes

</div>

<table border="1"><tr><td>Componente</td><td>Corriente[mA]</td><td>Voltaje[V]</td><td>Potencia[W]</td></tr><tr><td>Arduino nano</td><td>18.5</td><td>5</td><td>0.09250</td></tr><tr><td>AJ-SR04</td><td>1.5</td><td>5</td><td>0.00750</td></tr><tr><td>SIM 7600CE</td><td>2000</td><td>5</td><td>10</td></tr><tr><td>DS3231</td><td>8.65</td><td>5</td><td>0.0435</td></tr><tr><td>IRFZ20</td><td>-</td><td>-</td><td>-</td></tr></table>

Para determinar el consumo del sistema de adquisición de datos, se programa un encendido de 4 minutos para cada medición tomada, este tiempo comprende el encendido de todos los componentes, la toma y el envío de los datos; por lo que a lo largo del día las horas de consumo del sistema de adquisición de datos seria de 2,67 horas, mientras que el interruptor timer funcionara las 24 horas. El consumo del sistema de adquisición de datos se observa en la tabla 5.8.

<div align="center">

Tabla 5.8: Consumo energético del sistema de adquisición de datos

</div>

<table border="1"><tr><td>Componente</td><td>Potencia[W]</td><td>Horas</td><td>Energía[Wh]</td></tr><tr><td>Arduino nano</td><td>0.09250</td><td>267</td><td>0.247</td></tr><tr><td>AJ-SR04</td><td>0.00750</td><td>267</td><td>0.020</td></tr><tr><td>SIM 7600CE</td><td>10</td><td>267</td><td>2670</td></tr><tr><td>DS3231</td><td>0.0435</td><td>267</td><td>0.115</td></tr></table>

Para determinar el consumo del interruptor timer no se toma en cuenta el mosfet, ya que este tendrá un pequeño consumo cuando pase por la región lineal. El consumo del interruptor se observa en la tabla 5.9.

<div align="center">

Tabla 5.9: Consumo energético del interrupter

</div>

<table border="1"><tr><td>Componente</td><td>Potencia[W]</td><td>Horas</td><td>Energía[Wh]</td></tr><tr><td>Arduino nano</td><td>0.09250</td><td>24</td><td>222</td></tr><tr><td>DS3231</td><td>0.0435</td><td>24</td><td>1038</td></tr><tr><td>IRFZ20</td><td>-</td><td>-</td><td>-</td></tr></table>

El resumen del consumo total del sistema se observa en la tabla 5.10. El sistema de potencia dimensionado debe satisfacer el consumo tanto de potencia como de energía del sistema.

<div align="center">

Tabla 5.10: Resumen Consumo energético

</div>

<table border="1"><tr><td></td><td>Potencia [W]</td><td>Energía [Wh]</td></tr><tr><td>Sistema adquisición de datos</td><td>1014325</td><td>270825</td></tr><tr><td>Interruptor</td><td>013575</td><td>3258</td></tr><tr><td>Total</td><td>1023575</td><td>303405</td></tr></table>

Para elegir la capacidad del panel y la batería se utiliza las ecuaciones de la sección 3.5.2, dichas ecuaciones permiten dimensionar matemáticasmente los componentes necesarios según el consumo de energía durante el día. Para dimensionar dichos componentes es necesario tener distintos datos meteorológicos del lugar donde se instalará el sistema fotovoltaico, para ello, existen distintas páginas web que nos permite visualizar dichos datos meteorológicos accediendo a una base de datos de la nasa, únicamente es necesario ingresar el lugar por medio de las coordenadas o un mapa que brinda la misma página web.

En la tabla 5.11 se dimensiona el panel solar, en ella vemos que se utiliza una hora solar mínima de 2,5 horas, como se observa en la figura 5.24 la hora solar mínima en el año equivale aproximadamente 4 horas con un ángulo óptimo de $ 1 0^{o} $ , esta hora solar toma en cuenta la radiación tanto difusa como directa; pero para propósitos de diseños de sistemas fotovoltaicos la radiación que nos interesa es la directa. En la figura 5.25 se muestra que

en los últimos meses del año las horas de radiación directa equivale aproximadamente 2.5 horas por lo que se utiliza esta hora para los cálculos. Si vemos el ángulo óptimo coincide con la latitud del lugar siendo esta de $ 1 0, 2 7 7 ^{o} $ aproximadamente.

<div align="center">

Tabla 5.11: Cálculo para seleccionar la potencia del panel

</div>

<table border="1"><tr><td colspan="2">Panel</td></tr><tr><td>Consumo diario [Wh/día]</td><td>36,41</td></tr><tr><td>Hora Solar Mínima [h]</td><td>2,5</td></tr><tr><td>Potencia Fotovoltaica Requerida [W]</td><td>14,56</td></tr><tr><td></td><td></td></tr><tr><td>Potencia Panel Seleccionado [W]</td><td>20</td></tr><tr><td>Número de Paneles</td><td>0,728</td></tr></table>

Como vemos en la tabla anterior la potencia requerida del panel deberá ser 14.56W, de esta manera se decide utilizar un panel de 20W ya que es el más cercano a la medida que necesitamos, esto también nos garantiza que se podrá obtener más energía siempre y cuando las baterías lo permitan, por otro parte también nos indica que habrá energía que no se va a poder capturar debido a estados de completa carga de la batería. Si utilizamos paneles de 20W será necesario un panel como lo indica el número de paneles 0.728, sin embargo, también se podría utilizar dos paneles de 10W siendo la suma de los dos 20W.

En la tabla 5.12, se muestra los cálculos del dimensionado de la batería o baterías que serán necesarias. Cuando se dimensiona sistemas autónomos es necesario indicar los días de autonomía, en nuestro caso se estableció 2 días de autonomía con una profundidad de descarga de las baterías de 50 %. Como vemos en dicha tabla si establecemos esas condiciones y se elige una batería de 14 Ah el número de baterías necesarias en paralelo seria 0.867 y no es necesario ningún arreglo en serie debido a que el sistema trabaja a 12V, lo único que se tiene que asegurar es que la batería funcione a dicho voltaje. Por otra parte, se podría hacer un arreglo en paralelo con dos baterías de 7 Ah; sin embargo, utilizar arreglos de baterías en paralelo no es tan conveniente, debido a que una batería se carga más rápido que la otra, por lo que los voltajes en ambas serian un poco distintos, esto podría ocasionar problemas al regulador de carga en la lectura real del voltaje presente

en las baterías. Por esta razón se busca en el mercado una batería de 14Ah o superior.

<div align="center">

Tabla 5.12: Cálculo para seleccionar la batería

</div>

<table border="1"><tr><td colspan="2">Batería</td></tr><tr><td>Consumo diario [Wh/día]</td><td>3641</td></tr><tr><td>Voltaje del sistema [V]</td><td>12</td></tr><tr><td>Consumo corriente [Ah/día]</td><td>3034</td></tr><tr><td></td><td></td></tr><tr><td>Días de autonomía</td><td>2</td></tr><tr><td>Profundidad de descarga</td><td>50%</td></tr><tr><td>Capacidad de la batería [Ah]</td><td>14</td></tr><tr><td>Baterías en paralelo</td><td>0867</td></tr><tr><td>Baterías en serie</td><td>-</td></tr></table>

<div align="center">

Radiación solar promedio en Barrio La Gloria, Provincia de Guanacaste, Costa Rica (4.68 h)

</div>


> **Descripción de figura no disponible.**

<div align="center">

Horas solares por mes a 10°

</div>

<div align="center">

Figura 5.24: Promedio Hora Solar.

</div>

Fuente: Elaboración Propia utilizando la página web https://cceea.mx/solar.

<div align="center">

Latitud: 10.2777 | Longitud: -84.9419 | Radiación promedio mensual incidente en una superficie inclinada apuntada por el ecuador (kWh/m²/dia)

</div>

<table border="1"><tr><td></td><td>Enero</td><td>Febrero</td><td>Marzo</td><td>Abril</td><td>Mayo</td><td>Junio</td><td>Julio</td><td>Agosto</td><td>Septiembre</td><td>Octubre</td><td>Noviembre</td><td>Diciembre</td><td>Promedio anual</td></tr><tr><td>Difusa</td><td>1.71h</td><td>2.08h</td><td>1.86h</td><td>1.68h</td><td>2.07h</td><td>1.88h</td><td>2h</td><td>2.23h</td><td>2.29h</td><td>2.25h</td><td>2.26h</td><td>2.31h</td><td>2.26h</td></tr><tr><td>Directa</td><td>4.98h</td><td>3.1h</td><td>3.68h</td><td>4.58h</td><td>3.95h</td><td>5.13h</td><td>5.65h</td><td>4.98h</td><td>3.52h</td><td>3.17h</td><td>2.87h</td><td>2.68h</td><td>3.09h</td></tr><tr><td>Ángulo HORIZONTAL</td><td>4.7h</td><td>4.96h</td><td>5.84h</td><td>5.67h</td><td>4.67h</td><td>4.35h</td><td>4.19h</td><td>4.14h</td><td>4.36h</td><td>4.08h</td><td>4.1h</td><td>4.39h</td><td>4.62h</td></tr><tr><td>Ángulo LATITUDE</td><td>5.06h</td><td>5.19h</td><td>5.93h</td><td>5.57h</td><td>4.5h</td><td>4.16h</td><td>4.04h</td><td>4.05h</td><td>4.36h</td><td>4.18h</td><td>4.33h</td><td>4.75h</td><td>4.68h</td></tr><tr><td>Ángulo LAT_MINUS15</td><td>4.51h</td><td>4.82h</td><td>5.75h</td><td>5.67h</td><td>4.7h</td><td>4.4h</td><td>4.23h</td><td>4.15h</td><td>4.33h</td><td>4h</td><td>3.97h</td><td>4.2h</td><td>4.56h</td></tr><tr><td>Ángulo LAT_PLUS15</td><td>5.34h</td><td>5.29h</td><td>5.8h</td><td>5.2h</td><td>4.09h</td><td>3.74h</td><td>3.67h</td><td>3.78h</td><td>4.2h</td><td>4.17h</td><td>4.48h</td><td>5.05h</td><td>4.57h</td></tr><tr><td>Ángulo VERTICAL</td><td>3.48h</td><td>2.89h</td><td>2.33h</td><td>1.55h</td><td>1.5h</td><td>1.45h</td><td>1.45h</td><td>1.47h</td><td>1.74h</td><td>2.19h</td><td>2.79h</td><td>3.44h</td><td>2.19h</td></tr><tr><td>Rad opt</td><td>5.38h</td><td>5.29h</td><td>5.93h</td><td>5.67h</td><td>4.72h</td><td>4.45h</td><td>4.26h</td><td>4.15h</td><td>4.38h</td><td>4.2h</td><td>4.49h</td><td>5.11h</td><td>4.84h</td></tr><tr><td>Ang opt</td><td>33°</td><td>23.5°</td><td>12°</td><td>2°</td><td>11°</td><td>14.5°</td><td>12.5°</td><td>5°</td><td>5.5°</td><td>17°</td><td>28.5°</td><td>35°</td><td>9°</td></tr></table>

<div align="center">

Figura 5.25: Radiación Solar promedio mensual, las Juntas de Abangares.

</div>

Fuente: Elaboración Propia utilizando la página web https://cceea.mx/solar.

Para asegurar que efectivamente se está eligiendo los componentes correctos no basta con realizar únicamente los cálculos. Por esta razón, se decide similar el sistema autónomo, para ello existen diferentes softwares, entre los principales encontramos HOMER y PVSyst, por otra parte, existe una página web denominada PVGis que permite dimensionar rápidamente sistemas autónomos.

De modo que se decide realizar un dimensionado un poco más detallado con PVSyst. Este software posee distintas bases de datos meteorológicos lo que permite aproximar el sistema lo más real posible.

El software PVSyst permite ingresar el lugar por medio de un mapa como se observa en la figura 5.26, el punto negro representa el lugar donde se instalara el sistema fotovoltaico; una vez ingresado el sitio se selecciona la base de datos, la que se eligió fue meteonorm 8.0 como se observa en la figura 5.27.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.26: .Mapa ubicación geográfica Junta de Abangares.

</div>

<div align="center">

Fuente: Elaboración Propia utilizando el software PVSyst.

</div>


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.27: Base de datos meteorológica seleccionada.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.

Una ventaja de pvsyst es que permite ajustar el ángulo de inclinación de los paneles fotovoltaicos, como se ve en la figura 5.28 con una inclinación de 0 grados se obtiene un mayor rendimiento en verano; en la figura 5.29 con una inclinación de 15 grados se obtiene el mayor rendimiento durante todo el año, este ángulo se aproxima a la latitud del lugar; en la figura 5.30 con un ángulo de 30 grados se obtiene el mayor rendimiento en invierno. Para la simulación se decide utilizar el ángulo de 15 grados.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.28: Inclinación panel a 0 grados.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.29: Inclinación panel a 15 grados.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.30: Inclinación panel a 30 grados.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.

Posteriormente, se ingresa las necesidades del usuario como se observa en la figura 5.31, se ingresa el consumo por hora, en las horas de 5 a 8, 11 a 13 y 17 a 20, se realizan más mediciones, por lo que el consumo aumenta a 3 mediciones por hora. La energía que necesita suministrar el sistema al día es 36 Wh/dia, al mes 1.09 KWh/mes y al año 13.08 KWh/año.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.31: Necesidades del usuario por hora.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.

Una vez se ingresa las necesidades del usuario, el software automático sugiere la capacidad de la batería y la potencia del panel como se observa en la figura 5.32. El software sugiera utilizar paneles de 10W, sin embargo, se decide utilizar paneles de 20W ya que con 10W el sistema quedaría muy ajustado.


> **Descripción de figura no disponible.**

<div align="center">

Figura 5.32: Sugerencia de panel y batería dada por el software PVSyst Fuente: Elaboración Propia utilizando el software PVSyst.

</div>

PVsyst posee una base de datos de componentes que actualmente existen en el mercado, sin embargo, los que se compraron no están en dicha base de datos, por lo que se ingresan los datos de la hoja de datos, de esta manera se puede obtener una aproximación más precisa. Los resultados obtenidos de la simulación se muestran en el capitulo 6.

## Capítulo 6

## Análisis de Resultados

En este capítulo se exponen los resultados obtenidos de la implementación del proyecto, así como el análisis de los resultados tomando en consideración los objetivos y requerimientos planteados en capítulos anteriores.

## 6.1. Resultados y Análisis

La figura 6.1 muestra el resultado de la implementación del sistema de potencia, en dicha figura se muestra la batería, el panel y el regulador utilizado. El regulador PWM regula el voltaje del panel solar e introduce pulsos para cargar la batería, el voltaje que mantiene el regulador varía entre los 13.9 y 14.2V cuando introduce la carga en pulsos. Cuando la batería se carga el regulador mantiene el voltaje del panel entre los 13.9 y 14.2 pero no introduce carga a la batería.


> **Descripción de figura no disponible.**

<div align="center">

Figura 6.1: Resultado sistema de potencia implementado.

Fuente: Elaboración Propia.

</div>

La figura 6.2 muestra el sistema de adquisición de datos implementado.


> **Descripción de figura no disponible.**

<div align="center">

Figura 6.2: Resultado sistema de adquisición de datos implementado Fuente: Elaboración Propia.

</div>

## 6.1.1. Verificación de la calibración del sensor

Para verificar la calibración del sensor que se implementó, se realizan pruebas a diferentes alturas, cada prueba consiste en encender el sistema de adquisición de datos, tomar el dato del sensor y luego apagar el sistema. El código del sistema realiza 5 mediciones y las promedia, posteriormente se ajusta el dato al modelo calculado en el capítulo 5 y se brinda la altura del tanque. El sensor mide del punto máximo del tanque al nivel de líquido que hay, por lo que la altura del agua en el tanque equivale a la resta entre la altura máxima del tanque y el valor medido por el sensor. Los resultado de las pruebas se visualizan es las figuras 6.3 y 6.4, dichas figuras muestran la altura real medida con una cinta métrica, el promedio de los datos brindados por el sensor, la calibración del datos y

la altura del tanque.

<div align="center">

Altura medida 54cm

</div>

<table border="1"><tr><td>Promedio</td><td>Calibración</td><td>Altura Tanque</td></tr><tr><td>52,06</td><td>53,99</td><td>246,01</td></tr><tr><td>52,05</td><td>53,99</td><td>246,01</td></tr><tr><td>52,04</td><td>53,98</td><td>246,02</td></tr><tr><td>51,99</td><td>53,92</td><td>246,08</td></tr><tr><td>51,80</td><td>53,73</td><td>246,27</td></tr><tr><td>51,77</td><td>53,70</td><td>246,30</td></tr><tr><td>51,77</td><td>53,70</td><td>246,30</td></tr><tr><td>51,98</td><td>53,92</td><td>246,08</td></tr><tr><td>51,88</td><td>53,82</td><td>246,18</td></tr><tr><td>51,96</td><td>53,90</td><td>246,10</td></tr><tr><td>51,80</td><td>53,74</td><td>246,26</td></tr><tr><td>51,88</td><td>53,81</td><td>246,19</td></tr><tr><td>51,89</td><td>53,83</td><td>246,17</td></tr><tr><td>51,87</td><td>53,80</td><td>246,20</td></tr><tr><td>52,05</td><td>53,98</td><td>246,02</td></tr></table>

<table border="1"><tr><td>Promedio</td><td>Calibración</td><td>Altura Tanque</td></tr><tr><td>121,16</td><td>124,30</td><td>175,70</td></tr><tr><td>121,08</td><td>124,21</td><td>175,79</td></tr><tr><td>121,84</td><td>124,99</td><td>175,01</td></tr><tr><td>121,41</td><td>124,55</td><td>175,45</td></tr><tr><td>121,40</td><td>124,54</td><td>175,46</td></tr><tr><td>121,31</td><td>124,45</td><td>175,55</td></tr><tr><td>121,62</td><td>124,77</td><td>175,23</td></tr><tr><td>121,42</td><td>124,57</td><td>175,43</td></tr><tr><td>121,09</td><td>124,22</td><td>175,78</td></tr><tr><td>120,84</td><td>123,97</td><td>176,03</td></tr><tr><td>121,38</td><td>124,52</td><td>175,48</td></tr><tr><td>120,86</td><td>124,00</td><td>176,00</td></tr><tr><td>121,13</td><td>124,27</td><td>175,73</td></tr><tr><td>121,44</td><td>124,59</td><td>175,41</td></tr><tr><td>121,30</td><td>124,44</td><td>175,56</td></tr></table>

<table border="1"><tr><td>Promedio</td><td>Calibración</td><td>Altura Tanque</td></tr><tr><td>89,66</td><td>92,25</td><td>207,75</td></tr><tr><td>89,79</td><td>92,38</td><td>207,62</td></tr><tr><td>89,56</td><td>92,15</td><td>207,85</td></tr><tr><td>89,58</td><td>92,17</td><td>207,83</td></tr><tr><td>89,71</td><td>92,30</td><td>207,70</td></tr><tr><td>89,72</td><td>92,31</td><td>207,69</td></tr><tr><td>89,57</td><td>92,16</td><td>207,84</td></tr><tr><td>89,76</td><td>92,36</td><td>207,64</td></tr><tr><td>89,62</td><td>92,21</td><td>207,79</td></tr><tr><td>89,46</td><td>92,05</td><td>207,95</td></tr><tr><td>89,54</td><td>92,13</td><td>207,87</td></tr><tr><td>88,87</td><td>91,45</td><td>208,55</td></tr><tr><td>89,79</td><td>92,38</td><td>207,62</td></tr><tr><td>89,83</td><td>92,43</td><td>207,57</td></tr><tr><td>89,60</td><td>92,19</td><td>207,81</td></tr></table>

<table border="1"><tr><td>Promedio</td><td>Calibración</td><td>Altura Tanque</td></tr><tr><td>149,60</td><td>153,23</td><td>146,77</td></tr><tr><td>149,73</td><td>153,37</td><td>146,63</td></tr><tr><td>149,57</td><td>153,20</td><td>146,80</td></tr><tr><td>149,76</td><td>153,39</td><td>146,61</td></tr><tr><td>149,62</td><td>153,26</td><td>146,74</td></tr><tr><td>149,61</td><td>153,24</td><td>146,76</td></tr><tr><td>149,52</td><td>153,16</td><td>146,84</td></tr><tr><td>149,67</td><td>153,31</td><td>146,69</td></tr><tr><td>150,12</td><td>153,76</td><td>146,24</td></tr><tr><td>149,95</td><td>153,59</td><td>146,41</td></tr><tr><td>149,83</td><td>153,47</td><td>146,53</td></tr><tr><td>149,58</td><td>153,21</td><td>146,79</td></tr><tr><td>149,62</td><td>153,52</td><td>146,75</td></tr><tr><td>149,60</td><td>153,24</td><td>146,76</td></tr><tr><td>149,85</td><td>153,49</td><td>146,51</td></tr></table>

<div align="center">

Figura 6.3: Pruebas para verificar calibración del sensor 1.

</div>

Fuente: Elaboración Propia.


> **Descripción de figura no disponible.**

<div align="center">

Figura 6.4: Pruebas para verificar calibración del sensor 2. Fuente: Elaboración Propia.

</div>

Retomando los objetivos propuestos en el capítulo 2, el primer objetivo específico consistía en el diseño del prototipo medidor, el resultado del diseño y la implementación del sistema de adquisición de datos se observa en la figura 6.2. Para comprobar que los datos sean precisos las figuras 6.3 y 6.4 muestran diferentes datos que se tomaron aleatoriamente a diferentes niveles de altura, cada dato es bastante preciso cuando se realiza la calibración.

## 6.1.2. Transmisión y visualización de los datos

En el capítulo 5 se detalló dos 2 secciones para hacer consultas y descargas de datos. Una vez se ingresa la fecha que se desea consultar, los datos se muestran cómo se observa en las figuras 6.5, 6.6, 6.7. Se genera una gráfica y una tabla con todos los datos consultados.


> **Descripción de figura no disponible.**

<div align="center">

Figura 6.5: Gráfico de los datos consultados de la fecha 2021-07-04.

</div>

Fuente: Elaboración Propia.

<table border="1"><tr><td>Fecha</td><td>Hora</td><td>Altura</td></tr><tr><td>2021-07-04</td><td>1:00</td><td>217.89</td></tr><tr><td>2021-07-04</td><td>2:00</td><td>235.16</td></tr><tr><td>2021-07-04</td><td>3:00</td><td>221.25</td></tr><tr><td>2021-07-04</td><td>4:00</td><td>221.06</td></tr><tr><td>2021-07-04</td><td>5:00</td><td>218.74</td></tr><tr><td>2021-07-04</td><td>5:20</td><td>219.77</td></tr><tr><td>2021-07-04</td><td>5:40</td><td>211.22</td></tr><tr><td>2021-07-04</td><td>6:00</td><td>226.07</td></tr><tr><td>2021-07-04</td><td>6:20</td><td>225.42</td></tr><tr><td>2021-07-04</td><td>6:40</td><td>216.52</td></tr><tr><td>2021-07-04</td><td>7:00</td><td>217.4</td></tr><tr><td>2021-07-04</td><td>7:20</td><td>218.34</td></tr><tr><td>2021-07-04</td><td>7:40</td><td>211.33</td></tr><tr><td>2021-07-04</td><td>8:00</td><td>223.8</td></tr><tr><td>2021-07-04</td><td>9:00</td><td>214.59</td></tr><tr><td>2021-07-04</td><td>10:00</td><td>216.11</td></tr><tr><td>2021-07-04</td><td>11:00</td><td>178.19</td></tr><tr><td>2021-07-04</td><td>11:20</td><td>224.64</td></tr><tr><td>2021-07-04</td><td>11:40</td><td>219.26</td></tr><tr><td>2021-07-04</td><td>12:00</td><td>217.99</td></tr></table>

<div align="center">

Figura 6.6: Tabla de los datos consultados de la fecha 2021-07-04 parte 1.

Fuente: Elaboración Propia.

</div>

<!-- Páginas 121-152 -->

<table border="1"><tr><td>2021-07-04</td><td>12:20</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>12:40</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>13:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>14:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>15:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>16:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>17:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>17:20</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>17:40</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>18:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>18:20</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>18:40</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>19:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>19:20</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>19:40</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>20:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>21:00</td><td>298.97</td></tr><tr><td>2021-07-04</td><td>22:00</td><td>182.92</td></tr><tr><td>2021-07-04</td><td>23:00</td><td>193.06</td></tr><tr><td>2021-07-04</td><td>24:00</td><td>185.92</td></tr></table>

<div align="center">

Figura 6.7: Tabla de los datos consultados de la fecha 2021-07-04 parte 2.

Fuente: Elaboración Propia.

</div>

Si se desea descargar los datos se accede al menú en el apartado descargar y se ingresa la fecha, una vez que ingresa la fecha el archivo se descarga como se muestra en la figura 6.8. El archivos descargado se observa en las figuras 6.9 y 6.10.


> **Descripción de figura no disponible.**

<div align="center">

Figura 6.8: Página web consulta realizada.

Fuente: Elaboración Propia.

</div>

<table border="1"><tr><td></td><td>A</td><td>B</td><td>C</td></tr><tr><td>1</td><td>Fecha</td><td>Hora</td><td>Altura_Tanque</td></tr><tr><td>2</td><td>2021-07-04</td><td>1:00</td><td>217,89</td></tr><tr><td>3</td><td>2021-07-04</td><td>2:00</td><td>235,16</td></tr><tr><td>4</td><td>2021-07-04</td><td>3:00</td><td>221,25</td></tr><tr><td>5</td><td>2021-07-04</td><td>4:00</td><td>221,06</td></tr><tr><td>6</td><td>2021-07-04</td><td>5:00</td><td>218,74</td></tr><tr><td>7</td><td>2021-07-04</td><td>5:20</td><td>219,77</td></tr><tr><td>8</td><td>2021-07-04</td><td>5:40</td><td>211,22</td></tr><tr><td>9</td><td>2021-07-04</td><td>6:00</td><td>226,07</td></tr><tr><td>10</td><td>2021-07-04</td><td>6:20</td><td>225,42</td></tr><tr><td>11</td><td>2021-07-04</td><td>6:40</td><td>216,52</td></tr><tr><td>12</td><td>2021-07-04</td><td>7:00</td><td>217,4</td></tr><tr><td>13</td><td>2021-07-04</td><td>7:20</td><td>218,34</td></tr><tr><td>14</td><td>2021-07-04</td><td>7:40</td><td>211,33</td></tr><tr><td>15</td><td>2021-07-04</td><td>8:00</td><td>223,8</td></tr><tr><td>16</td><td>2021-07-04</td><td>9:00</td><td>214,59</td></tr><tr><td>17</td><td>2021-07-04</td><td>10:00</td><td>216,11</td></tr><tr><td>18</td><td>2021-07-04</td><td>11:00</td><td>178,19</td></tr><tr><td>19</td><td>2021-07-04</td><td>11:20</td><td>224,64</td></tr><tr><td>20</td><td>2021-07-04</td><td>11:40</td><td>219,26</td></tr></table>

<div align="center">

Figura 6.9: Archivo descargado en excel parte 1.

</div>

Fuente: Elaboración Propia.

<table border="1"><tr><td>20</td><td>2021-07-04</td><td>11:40</td><td>219,26</td></tr><tr><td>21</td><td>2021-07-04</td><td>12:00</td><td>217,99</td></tr><tr><td>22</td><td>2021-07-04</td><td>12:20</td><td>298,97</td></tr><tr><td>23</td><td>2021-07-04</td><td>12:40</td><td>298,97</td></tr><tr><td>24</td><td>2021-07-04</td><td>13:00</td><td>298,97</td></tr><tr><td>25</td><td>2021-07-04</td><td>14:00</td><td>298,97</td></tr><tr><td>26</td><td>2021-07-04</td><td>15:00</td><td>298,97</td></tr><tr><td>27</td><td>2021-07-04</td><td>16:00</td><td>298,97</td></tr><tr><td>28</td><td>2021-07-04</td><td>17:00</td><td>298,97</td></tr><tr><td>29</td><td>2021-07-04</td><td>17:20</td><td>298,97</td></tr><tr><td>30</td><td>2021-07-04</td><td>17:40</td><td>298,97</td></tr><tr><td>31</td><td>2021-07-04</td><td>18:00</td><td>298,97</td></tr><tr><td>32</td><td>2021-07-04</td><td>18:20</td><td>298,97</td></tr><tr><td>33</td><td>2021-07-04</td><td>18:40</td><td>298,97</td></tr><tr><td>34</td><td>2021-07-04</td><td>19:00</td><td>298,97</td></tr><tr><td>35</td><td>2021-07-04</td><td>19:20</td><td>298,97</td></tr><tr><td>36</td><td>2021-07-04</td><td>19:40</td><td>298,97</td></tr><tr><td>37</td><td>2021-07-04</td><td>20:00</td><td>298,97</td></tr><tr><td>38</td><td>2021-07-04</td><td>21:00</td><td>298,97</td></tr><tr><td>39</td><td>2021-07-04</td><td>22:00</td><td>182,92</td></tr><tr><td>40</td><td>2021-07-04</td><td>23:00</td><td>193,06</td></tr><tr><td>41</td><td>2021-07-04</td><td>24:00</td><td>185,92</td></tr></table>

<div align="center">

Figura 6.10: Archivo descargado en excel parte 2.

</div>

Fuente: Elaboración Propia.

El tercer objetivo específico consistía en la implementación del sistema de adquisición y visualización de datos. En las figuras 6.5, 6.6 y 6.7 se observa el sistema de visualización de datos cuando se realiza una consulta, todos los datos mostrados en las imágenes se transmitieron desde el sistema de adquisición de datos el cual transmite y guarda los datos en la base de datos del servidor. Las figuras 6.8, 6.9 y 6.10 muestran la sección de descargas, el archivo descargado contienen los datos de la fecha que se ingresó.

## 6.1.3. Resultados simulación sistema de potencia

Para realizar la simulación del sistema de potencia se ingresaron los datos de los componentes comprados, sin embargo, algunos datos no se podían ingresar debido a que se desconocía dichos datos, por lo que las pérdidas que podía generar el sistema no se simulan de la mejor manera. Por esta razón se simula tomando en cuenta el consumo del usuario y agregando perdidas por un 20 %. De esta forma a pesar de que no se logra similar las perdidas si se consideran en el modelo propuesto.

El informe general que brinda PVSyst se observa en la figura 6.11, la energía total disponible generada por el conjunto fotovoltaico a lo largo de un año es: 26.87KWh/year.

El consumo del sistema de adquisición de datos ronda los 13.26Wh/year por lo que la potencia sobrante que no se utiliza es de 12.32Wh/year.


> **Descripción de figura no disponible.**

<div align="center">

Figura 6.11: Resumen resultado simulación PVSyst.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.

La figura 6.12 muestra la relación de rendimiento del sistema de potencia implementado.


> **Descripción de figura no disponible.**

<div align="center">

Figura 6.12: Eficiencia Global del Sistema de potencia.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.

En la figura 6.13 se detalla el comportamiento del sistema mensualmente.

<table border="1"><tr><td></td><td>GlobHorkWh/m2</td><td>GlobEffkWh/m2</td><td>E_AvailkWh</td><td>EUnusedkWh</td><td>E_MisskWh</td><td>E_UserkWh</td><td>E_LoadkWh</td><td>SolFracratio</td></tr><tr><td>January</td><td>161.8</td><td>177.9</td><td>2.503</td><td>1.207</td><td>0.000</td><td>1.126</td><td>1.126</td><td>1.000</td></tr><tr><td>February</td><td>160.1</td><td>169.6</td><td>2.379</td><td>1.241</td><td>0.000</td><td>1.017</td><td>1.017</td><td>1.000</td></tr><tr><td>March</td><td>199.1</td><td>200.1</td><td>2.806</td><td>1.567</td><td>0.000</td><td>1.126</td><td>1.126</td><td>1.000</td></tr><tr><td>April</td><td>186.2</td><td>176.1</td><td>2.471</td><td>1.275</td><td>0.000</td><td>1.089</td><td>1.089</td><td>1.000</td></tr><tr><td>May</td><td>168.1</td><td>151.7</td><td>2.132</td><td>0.911</td><td>0.000</td><td>1.126</td><td>1.126</td><td>1.000</td></tr><tr><td>June</td><td>161.6</td><td>142.0</td><td>1.997</td><td>0.824</td><td>0.000</td><td>1.089</td><td>1.089</td><td>1.000</td></tr><tr><td>July</td><td>166.4</td><td>147.4</td><td>2.068</td><td>0.841</td><td>0.000</td><td>1.126</td><td>1.126</td><td>1.000</td></tr><tr><td>August</td><td>153.1</td><td>141.2</td><td>1.981</td><td>0.777</td><td>0.000</td><td>1.126</td><td>1.126</td><td>1.000</td></tr><tr><td>September</td><td>148.8</td><td>144.3</td><td>2.029</td><td>0.825</td><td>0.000</td><td>1.089</td><td>1.089</td><td>1.000</td></tr><tr><td>October</td><td>148.1</td><td>151.3</td><td>2.134</td><td>0.915</td><td>0.000</td><td>1.126</td><td>1.126</td><td>1.000</td></tr><tr><td>November</td><td>139.5</td><td>150.9</td><td>2.126</td><td>0.934</td><td>0.000</td><td>1.089</td><td>1.089</td><td>1.000</td></tr><tr><td>December</td><td>144.0</td><td>158.8</td><td>2.240</td><td>1.004</td><td>0.000</td><td>1.126</td><td>1.126</td><td>1.000</td></tr><tr><td>Year</td><td>1936.8</td><td>1911.3</td><td>26.866</td><td>12.320</td><td>0.000</td><td>13.253</td><td>13.253</td><td>1.000</td></tr></table>

Legends

GlobHor Global horizontal irradiation

GlobEff Effective Global, corr. for IAM and shadings

E_Avail Available Solar Energy

EUnused Unused energy (battery full)

E_Miss Missing energy

E_User Energy supplied to the user

E_Load Energy need of the user (Load)

SolFrac Solar fraction (EUsed / ELoad)

<div align="center">

Figura 6.13: Resultados principales mensuales de energía.

</div>

Fuente: Elaboración Propia utilizando el software PVSyst.

El segundo objetivo específico consistía en la implementación del sistema de potencia, la figura 6.1 muestra el sistema de potencia implementado, para comprobar que el sistema funcione correctamente se dimensiona el sistema como se explicó en el capítulo 5, además, se simulo el sistema con el software PVSyst, la figura 6.11 muestra que en todo el año el sistema de potencia tendrá disponible 26.87kWh de los cuales solo se usaran 13.25kWh y 12.32kWh no se usaran, este exceso de energía se debe al panel elegido ya que este es de 20W y el programa PVsyst sugería 10W. La diferencia entre el modelo calculado del panel y el brindado por pvsyst es debido a las horas de radiación solar, en el modelo calculado del capítulo 5 se utiliza únicamente la radiación directa ya que es la mas importante y la que permite que el panel genere más energía. El software PVSyst toma en cuenta la radiación total, tanto la directa como la difusa.

La eficiencia global del sistema es de 0.337 como se observa en la figura 6.12, esto se debe a que la potencia instala es menor con respecto a la energía que puede incidir en el panel fotovoltaico. La fracción solar es de 1 ya que la energía de la carga es igual a la energía del usuario debido a que las perdidas no se lograron similar, sin embargo, se consideró 20 % de perdidas en el consumo de energía ingreso. La figura 6.13 muestra un informe mensual de algunos parámetros, mensualmente el sistema de potencia proveerá

la energía suficiente para que el sistema de adquisición de datos funcione correctamente.

## 6.2. Costo del proyecto

La tabla 6.1 muestra los costos de la implementación del proyecto, el valor final de los costos es aproximadamente 500 dólares.

<div align="center">

Tabla 6.1: Costo del proyecto

</div>

<table border="1"><tr><td>Detalle</td><td>Costo $</td></tr><tr><td>Arduino nano</td><td>15.9</td></tr><tr><td>Módem SIM7600 CE</td><td>74.77</td></tr><tr><td>RTC 3231</td><td>11.9</td></tr><tr><td>Sensor AJ-SR04</td><td>17.95</td></tr><tr><td>Placas PCBs</td><td>2</td></tr><tr><td>Herramientas y otros componentes adicionales</td><td>30</td></tr><tr><td>Kit panel solar y regulador de carga</td><td>49.99</td></tr><tr><td>Batería</td><td>63.9</td></tr><tr><td>Envío componentes a Costa Rica</td><td>150</td></tr><tr><td>Alquiler servicio hosting</td><td>60.72</td></tr><tr><td>Gastos de transporte y alimentación</td><td>20</td></tr><tr><td>Total Costos</td><td>497.13</td></tr></table>

<div align="center">

# Capítulo 7

</div>

<div align="center">

# Conclusiones y recomendaciones

</div>

El presente capitulo expone las conclusiones y recomendaciones obtenidos durante la realización e implementación del proyecto.

## 7.1. Conclusiones

- Se logró diseñar un prototipo medidor de nivel de líquido para un tanque de almacenamiento y distribución de agua para la ASADA de la comunidad de las Juntas de Abangares.

- Se implementó una interfaz de visualización de datos amigable con el usuario y fácil de utilizar que permite realizar consultas y descargas de los datos transmitidos por el sistema de adquisición de datos.

- La utilización de una página web permite que cualquier dispositivo electrónico pueda acceder a la misma por medio de una dirección URL.

- El sistema de potencia implementado provee la energía suficiente que el sistema de adquisición de datos necesita permitiendo que este funcione correctamente a lo largo del día.

- El protocolo HTTP funciona en aplicaciones donde se transmiten pocos datos permitiendo que el protocolo no colapse.

- El sistema final implementado se diseñó para un tanque de almacenamiento de agua, sin embargo, se puede utilizar en otros tanques que contengan otro tipo de líquido, la única condición es que el líquido medio refleje la onda del sensor.

- El prototipo final se implementó en condiciones similares a las de Abangares, principalmente para realizar la calibración del sensor y la transmisión de datos en relación a la cobertura 2G, 3G y 4G.

## 7.2. Recomendaciones

- Es importante conocer la ubicación de las antenas de las compañías que brindan servicio telefónico con el fin de ajustar la posición de la antena del módulo SIM, esto permite que el módulo se conecte a la red con mayor facilidad.

- Se recomienda realizar pruebas del sistema de potencia a lo largo del año con el fin de verificar el correcto funcionamiento, principalmente en la época de invierno donde la radiación solar que incide en el panel es menor.

- Se recomienda instalar el panel en un lugar donde no se generen sombras durante el día, esto con el fin de evitar que el panel se dañe, ya que, si existe una sombra en un área del panel, ocasiona que algunas células del panel presenten mayor tensión provocando que estas trabajen a mayor rendimiento generando daño en algunas células con el tiempo.

## Bibliografía

[1] G. Pocock y C. D. Richards, Human Physiology: The Basis of Medicine. Elsevier España, 2004, ISBN: 84-458-1479-6.

[2] R. O. Vega, J. R. B. Brenes, M. A. Hernandez, P. V. Rivera y L. Y. R. Zamora, Informe de proyecto: B7521 MANEJO INTEGRAL DEL RECURSO HÍDRICO EN LA CUENCA DEL RIÓ ABANGARES. Universidad de Costa Rica, Vicerrectoria de Investigación, 2019.

[3] D. M. Alvarado y C. F. P. Barquero, Agua para consumo humano y saneamiento en Costa Rica al 2016. Metas al 2022 y al 2030. 1998. dirección: https://www. scielo.sa.cr/pdf/tem/v31n2/0379-3982-tem-31-02-72.pdf.

[4] A. Robledano, Que es TCP/IP, 2019. dirección: https://openwebinars.net/blog/que-es-tcpip/.

[5] J. A. Castillo, Protocolo TCP/IP - Que es y cómo funciona, 2020. dirección: https://www.profesionalreview.com/2020/03/21/protocolo-tcp-ip/.

[6] S. D. Luz, ¿Qué protocolo es mejor?: TCP vs UDP, descubre cuándo utilizar cada uno, 2021. dirección: https://www.redeszone.net/tutoriales/internet/tcp-udp-caracteristicas-uso-diferencias/.

[7] M. Acibeiro, ¿Cuál es la diferencia entre HTTP y HTTPS? 2018. dirección: https://es.godaddy.com/blog/diferencia-entre-http-y-https/.

[8] F. Berzal, F. J. Cortijo y J. C. Cubero, Desarrollo Profesional de Aplicaciones Web con ASP.NET, Primera Edición. iKor Consulting, 2007, ISBN: 84-609-4245-7.

[9] G. Aviani, HTTP and everything you need to know about it, 2018. dirección: https://faun.pub/http-and-everything-you-need-to-know-about-it-8273bc224491.

[10] M. Rodríguez, ¿Cómo funciona el protocolo HTTP? 2016. dirección: https://www. miguelra.com/ como-functiona-el-protocolo-http/.

[11] G. Escobar, El protocolo HTTP, 2017. dirección: https://blog.makeitreal.camp/ el-protocolo-http/.

[12] D. Lázaro, GET y POST en PHP, 2018. dirección: https://diego.com.es/gety-post-en-php.

[13] Á. de León, Funcionamiento de un servidor web, 2018. dirección: https://blog. infranetworking.com/funcionamiento-de-servidor-web/.

[14] P. Group, ¿Qué es PHP? Dirección: https://www.php.net/manual/es/intro- whatis.php.

[15] P. Godse, Understanding a Web Server and Types of Web Servers, 2018. dirección: https://www.milesweb.in/blog/hosting/web-server-types-web-servers/.

[16] Á. de León, Servidor LiteSpeed: ¿Qué es? Características y Ventajas, 2019. dirección: https://blog.infranetworking.com/servidor-litespeed/.

[17] C. Date, Introducción a los sistemas de bases de datos, Séptima Edición. Pearson Educación, 2001, ISBN: 968-444-419-2.

[18] R. Marín, Los gestores de bases de datos más usados en la actualidad. 2019. dirección: https://revistadigital.inesem.es/informatica-y-tics/los-gestores-de-bases-de-datos-mas-usados/.

[19] J. M. M. Muñiz y R. C. García, Energía Solar Fotovoltaica, 2da edición. Madrid: FC Editorial, 2007, ISBN: 978-84-96743-29-8.

[20] L. A. S. Díez, MODELOS DE POLIGENERACIÓN ENERGÉTICA DISTRIBUI DA EN ÁREAS RESIDENCIALES. España, 2011, ISBN: 978-84-614-8874-2.

[21] J. T. Montecelos, Replanteo y funcionamiento de las instalaciones solares fotovoltaicas. Madrid: Editorial Paraninfo, 2021, ISBN: 978-84-1366-033-2.

[22] M. B. Carreras, Installaciones solares fotovoltaicas. España: Editex, 2019, ISBN: 978- 84-9161-940-6.

[23] G. Ojeda, Baterías para placas solares: Funcionamiento y Mejores marcas, 2021. dirección: https://selectra.es/autoconsumo/info/componentes/baterias-solares.

[24] O. Style, Energía Solar Autónoma: Planificación, dimensionado e instalación de un sistema fotovoltaico autónomo. 2012, ISBN: 978-84-615-7887-0.

[25] C. Lane, What are the different types of solar batteries? 2021. dirección: https://www.solarreviews.com/blog/types-of-solar-batteries.

[26] J. A. Rodrigo, Correlación lineal y Regresión lineal simple, 2016. dirección: https://www.cienciadedatos.net/documentos/24_correlacion_y_regresionlineal.

[27] C. Q. Ruiz, Elementos de Inferencia Estadística. Editorial Universidad de Costa Rica, 1993, ISBN: 9977-67-104-4.

[28] M. C. C. Limeres, Regresión lineal simple, 2011-2012. dirección: http://eio usc.es/eipc1/BASE/BASEMASTER/FORMULARIOS-PHP-DPTO/MATERIALES/Mat_ 50140116_Regr_%5C%20simple_2011_12.pdf.

[29] R. Á. Cáceres, Estadística aplicada a las ciencias de la salud. Ediciones Díaz de Santos, 2007, ISBN: 978-84-7978-823-0.

[30] G. P. Gil y R. G. Vargas, Medicina Preventiva y Salud Pública. Elsevier España, 2000,ISBN: 84-458-1024-3.

[31] A. Carrasquilla-Batista, A. C. Rodríguez, K. N. Montero, O. G. Espinoza, J. Valverde y M. G. Barrantes, Regresión lineal simple y múltiple: aplicación en la predicción de variables naturales relacionadas con el crecimiento microalgal, 2016. dirección: https://www.scielo.sa.cr/pdf/tem/v29s5/0379-3982-tem-29-s5-33.pdf.

[32] P. Gómez-Esteban, [Electricidad I] Potencia y energía eléctricas, 2010. dirección: https://eltamiz.com/2010/02/04/electricidad-i-potencia-y-energia-electricas/.

[33] L. Prielipp, WHAT IS A LEVEL SENSOR? 2019. dirección: https://realpars. com/level-sensor/.

[34] Arduino nano, Components101. dirección: https://components101.com/microcontrollers/ arduino-nano.

[35] Arduino nano, Arduino Store. dirección: https://store.arduino.cc/usa/ arduino-nano.

[36] Datasheet ESP32 Series, Espressif Systems.

[37] ESP32 - DevKitC, Components101. dirección: https://components101.com/ microcontrollers/esp32-devkitc.

[38] Producto No. AD39838. Raspberry Pi Zero, MicroJPM. dirección: https://www microjpm.com/products/ad39838/.

[39] About Raspbian, Raspberrypi. direccion: https://www.raspbian.org/RaspbianAbout.

[40] SIM900 GSM GPRS, Amazon. dirección: https://www.amazon.com/-/es/m%C3%B3dulo-placa-desarrollo-antena-SIM900/dp/B07XY79G56/ref=sr_1_5?__mk_es_US=%C3%85M%C3%85%C5%BD%C3%95%C3%91&dchild=1&keywords=sim900&qid=1629428963&sr=8-5.

[41] Producto No. 426-TEL0124. SIM 7600CE, Mouser. dirección: https://www.mouser.co.cr/new/dfrobot/dfrobot-sim7600ce-t-4glte-arduino-shield/.

[42] S. Ranger, What is the IoT? Everything you need to know about the Internet of Things right now, 2020. dirección: https://www.zdnet.com/article/what-is-the-internet-of-things-everything-you-need-to-know-about-the-iot-right-now/.

[43] E. Sarachu, ¿Qué es la domótica? ¿Cómo funciona? 2020. dirección: https://e- ficiencia.com/domotica-que-es-y-como-functiona/.

[44] J. Bartnitsky, HTTP vs MQTT performance tests, 2018. dirección: https:// flespi.com/blog/http-vs-mqtt-performance-tests.

[45] R. Mitchell, HTTP vs MQTT - Which Communication Protocol Should You Use in Your IoT Application? 2020. dirección: https://www.electromaker.io/blog/article/http-vs-mqtt.

[46] Datasheet AJ-SR04, Shenzhen Anji electronic.

[47] Datasheet RTC 3231, Dallas Semiconductor.

[48] Datasheet IRFZ48n, International Rectifier.

## A.1. Diseño de las PCBs


> **Descripción de figura no disponible.**

<div align="center">

Figura A.1: Diseño PCB circuito interruptor

</div>

Fuente: Elaboración Propia


> **Descripción de figura no disponible.**

<div align="center">

Figura A.2: Diseño PCB circuito adquisición de datos Fuente: Elaboración Propia

</div>

## A.2. Cobertura en la comunidad de las juntas de Abangares: Latitud:10.278, Longitud: -84.9426


> **Descripción de figura no disponible.**

<div align="center">

Figura A.3: Cobertura 2G operador claro.

</div>

Fuente: http://mapas-claro.addax.cc/


> **Descripción de figura no disponible.**

<div align="center">

Figura A.4: Cobertura 3G operador claro.

</div>

Fuente: http://mapas-claro.addax.cc/


> **Descripción de figura no disponible.**

<div align="center">

Figura A.5: Cobertura 4G operador claro.

</div>

Fuente: http://mapas-claro.addax.cc/


> **Descripción de figura no disponible.**

<div align="center">

Figura A.6: Cobertura 2G operador kolbi.

</div>

Fuente: https://www.kolbi.cr/wps/portal/kolbi $ _{de}ev/personas/mas-servicios/mapa- $ $ de-cobertura/cobertura-movil-postpago $


> **Descripción de figura no disponible.**

Figura A.7: Cobertura 3G operador kolbi.

Fuente: https://www.kolbi.cr/wps/portal/kolbi $ _{d}ev/personas/mas-servicios/mapa- $ $ de-cobertura/cobertura-movil-postpago $


> **Descripción de figura no disponible.**

<div align="center">

Figura A.8: Cobertura 4G operador kolbi.

</div>

Fuente: https://www.kolbi.cr/wps/portal/kolbi $ _{d} $ ev/personas/mas-servicios/mapa- de-cobertura/cobertura-movil-postpago


> **Descripción de figura no disponible.**

Figura A.9: Cobertura 2G operador movistar Fuente: https://movistar.cr/cobertura-celular


> **Descripción de figura no disponible.**

<div align="center">

Figura A.10: Cobertura 3G operador movistar Fuente: https://movistar.cr/cobertura-celular

</div>


> **Descripción de figura no disponible.**

<div align="center">

Figura A.11: Cobertura 4G operador movistar.

</div>

Fuente: https://movistar.cr/cobertura-celular

## A.3. Datos utilizados para calibrar el sensor AJ-SR04

<div align="center">

Prueba 1

</div>

<table border="1"><tr><td>Valor Medido</td><td>Valor Real</td></tr><tr><td>18,95</td><td>20</td></tr><tr><td>18,97</td><td>20</td></tr><tr><td>19,02</td><td>20</td></tr><tr><td>18,93</td><td>20</td></tr><tr><td>18,88</td><td>20</td></tr><tr><td>18,95</td><td>20</td></tr><tr><td>18,93</td><td>20</td></tr><tr><td>19,07</td><td>20</td></tr><tr><td>18,80</td><td>20</td></tr><tr><td>18,90</td><td>20</td></tr><tr><td>18,93</td><td>20</td></tr><tr><td>18,86</td><td>20</td></tr><tr><td>18,93</td><td>20</td></tr><tr><td>18,88</td><td>20</td></tr><tr><td>18,88</td><td>20</td></tr><tr><td>18,86</td><td>20</td></tr><tr><td>18,93</td><td>20</td></tr><tr><td>18,86</td><td>20</td></tr><tr><td>18,90</td><td>20</td></tr><tr><td>38,60</td><td>40</td></tr><tr><td>38,60</td><td>40</td></tr><tr><td>38,71</td><td>40</td></tr><tr><td>38,62</td><td>40</td></tr><tr><td>38,57</td><td>40</td></tr><tr><td>38,60</td><td>40</td></tr><tr><td>38,66</td><td>40</td></tr><tr><td>38,67</td><td>40</td></tr><tr><td>38,50</td><td>40</td></tr><tr><td>38,50</td><td>40</td></tr><tr><td>38,64</td><td>40</td></tr><tr><td>38,62</td><td>40</td></tr><tr><td>38,60</td><td>40</td></tr><tr><td>38,55</td><td>40</td></tr></table>

<table border="1"><tr><td>38,60</td><td>40</td></tr><tr><td>38,62</td><td>40</td></tr><tr><td>38,48</td><td>40</td></tr><tr><td>38,59</td><td>40</td></tr><tr><td>38,66</td><td>40</td></tr><tr><td>38,64</td><td>40</td></tr><tr><td>58,24</td><td>60</td></tr><tr><td>58,52</td><td>60</td></tr><tr><td>58,60</td><td>60</td></tr><tr><td>58,36</td><td>60</td></tr><tr><td>58,38</td><td>60</td></tr><tr><td>58,55</td><td>60</td></tr><tr><td>57,93</td><td>60</td></tr><tr><td>58,40</td><td>60</td></tr><tr><td>58,40</td><td>60</td></tr><tr><td>58,33</td><td>60</td></tr><tr><td>57,88</td><td>60</td></tr><tr><td>58,31</td><td>60</td></tr><tr><td>58,05</td><td>60</td></tr><tr><td>58,43</td><td>60</td></tr><tr><td>57,97</td><td>60</td></tr><tr><td>58,41</td><td>60</td></tr><tr><td>58,48</td><td>60</td></tr><tr><td>58,04</td><td>60</td></tr><tr><td>58,34</td><td>60</td></tr><tr><td>58,04</td><td>60</td></tr><tr><td>77,38</td><td>80</td></tr><tr><td>77,45</td><td>80</td></tr><tr><td>78,02</td><td>80</td></tr><tr><td>77,90</td><td>80</td></tr><tr><td>77,57</td><td>80</td></tr><tr><td>77,91</td><td>80</td></tr><tr><td>77,98</td><td>80</td></tr><tr><td>77,66</td><td>80</td></tr><tr><td>78,02</td><td>80</td></tr><tr><td>78,05</td><td>80</td></tr></table>

<table border="1"><tr><td>77,96</td><td>80</td></tr><tr><td>77,47</td><td>80</td></tr><tr><td>77,52</td><td>80</td></tr><tr><td>77,81</td><td>80</td></tr><tr><td>77,36</td><td>80</td></tr><tr><td>77,45</td><td>80</td></tr><tr><td>77,71</td><td>80</td></tr><tr><td>77,48</td><td>80</td></tr><tr><td>77,95</td><td>80</td></tr><tr><td>77,38</td><td>80</td></tr><tr><td>97,02</td><td>100</td></tr><tr><td>97,12</td><td>100</td></tr><tr><td>96,98</td><td>100</td></tr><tr><td>97,17</td><td>100</td></tr><tr><td>97,05</td><td>100</td></tr><tr><td>97,15</td><td>100</td></tr><tr><td>97,02</td><td>100</td></tr><tr><td>97,10</td><td>100</td></tr><tr><td>96,98</td><td>100</td></tr><tr><td>97,33</td><td>100</td></tr><tr><td>97,09</td><td>100</td></tr><tr><td>97,09</td><td>100</td></tr><tr><td>97,34</td><td>100</td></tr><tr><td>97,00</td><td>100</td></tr><tr><td>97,09</td><td>100</td></tr><tr><td>97,05</td><td>100</td></tr><tr><td>97,17</td><td>100</td></tr><tr><td>97,10</td><td>100</td></tr><tr><td>97,17</td><td>100</td></tr><tr><td>97,12</td><td>100</td></tr><tr><td>117,03</td><td>120</td></tr><tr><td>116,40</td><td>120</td></tr><tr><td>116,59</td><td>120</td></tr><tr><td>117,03</td><td>120</td></tr><tr><td>117,07</td><td>120</td></tr><tr><td>116,96</td><td>120</td></tr></table>

<table border="1"><tr><td>117,12</td><td>120</td></tr><tr><td>117,13</td><td>120</td></tr><tr><td>116,43</td><td>120</td></tr><tr><td>116,98</td><td>120</td></tr><tr><td>116,62</td><td>120</td></tr><tr><td>116,50</td><td>120</td></tr><tr><td>117,00</td><td>120</td></tr><tr><td>117,19</td><td>120</td></tr><tr><td>117,01</td><td>120</td></tr><tr><td>117,07</td><td>120</td></tr><tr><td>117,13</td><td>120</td></tr><tr><td>117,05</td><td>120</td></tr><tr><td>117,10</td><td>120</td></tr><tr><td>117,17</td><td>120</td></tr><tr><td>135,97</td><td>140</td></tr><tr><td>136,00</td><td>140</td></tr><tr><td>136,27</td><td>140</td></tr><tr><td>135,78</td><td>140</td></tr><tr><td>135,88</td><td>140</td></tr><tr><td>135,90</td><td>140</td></tr><tr><td>136,05</td><td>140</td></tr><tr><td>135,88</td><td>140</td></tr><tr><td>136,14</td><td>140</td></tr><tr><td>136,21</td><td>140</td></tr><tr><td>136,22</td><td>140</td></tr><tr><td>135,86</td><td>140</td></tr><tr><td>136,14</td><td>140</td></tr><tr><td>136,05</td><td>140</td></tr><tr><td>135,79</td><td>140</td></tr><tr><td>135,15</td><td>140</td></tr><tr><td>136,33</td><td>140</td></tr><tr><td>136,14</td><td>140</td></tr><tr><td>136,10</td><td>140</td></tr><tr><td>136,63</td><td>140</td></tr><tr><td>155,69</td><td>160</td></tr><tr><td>156,08</td><td>160</td></tr></table>

<table border="1"><tr><td>156,12</td><td>160</td></tr><tr><td>156,12</td><td>160</td></tr><tr><td>156,15</td><td>160</td></tr><tr><td>156,10</td><td>160</td></tr><tr><td>156,15</td><td>160</td></tr><tr><td>156,03</td><td>160</td></tr><tr><td>156,00</td><td>160</td></tr><tr><td>156,34</td><td>160</td></tr><tr><td>155,88</td><td>160</td></tr><tr><td>156,27</td><td>160</td></tr><tr><td>156,36</td><td>160</td></tr><tr><td>155,96</td><td>160</td></tr><tr><td>156,31</td><td>160</td></tr><tr><td>156,17</td><td>160</td></tr><tr><td>155,72</td><td>160</td></tr><tr><td>156,17</td><td>160</td></tr><tr><td>156,22</td><td>160</td></tr><tr><td>156,41</td><td>160</td></tr><tr><td>175,05</td><td>180</td></tr><tr><td>175,15</td><td>180</td></tr><tr><td>175,14</td><td>180</td></tr><tr><td>175,19</td><td>180</td></tr><tr><td>174,78</td><td>180</td></tr><tr><td>174,28</td><td>180</td></tr><tr><td>174,69</td><td>180</td></tr><tr><td>174,48</td><td>180</td></tr><tr><td>175,08</td><td>180</td></tr><tr><td>174,48</td><td>180</td></tr><tr><td>174,79</td><td>180</td></tr><tr><td>174,74</td><td>180</td></tr><tr><td>175,12</td><td>180</td></tr><tr><td>174,86</td><td>180</td></tr><tr><td>174,88</td><td>180</td></tr><tr><td>174,72</td><td>180</td></tr><tr><td>174,93</td><td>180</td></tr><tr><td>174,59</td><td>180</td></tr></table>

<table border="1"><tr><td>175,03</td><td>180</td></tr><tr><td>174,52</td><td>180</td></tr><tr><td>195,29</td><td>200</td></tr><tr><td>195,72</td><td>200</td></tr><tr><td>195,18</td><td>200</td></tr><tr><td>195,10</td><td>200</td></tr><tr><td>195,12</td><td>200</td></tr><tr><td>195,27</td><td>200</td></tr><tr><td>195,25</td><td>200</td></tr><tr><td>195,20</td><td>200</td></tr><tr><td>195,15</td><td>200</td></tr><tr><td>195,34</td><td>200</td></tr><tr><td>195,72</td><td>200</td></tr><tr><td>195,75</td><td>200</td></tr><tr><td>195,37</td><td>200</td></tr><tr><td>195,37</td><td>200</td></tr><tr><td>195,42</td><td>200</td></tr><tr><td>195,87</td><td>200</td></tr><tr><td>195,89</td><td>200</td></tr><tr><td>195,89</td><td>200</td></tr><tr><td>195,46</td><td>200</td></tr><tr><td>195,53</td><td>200</td></tr><tr><td>214,62</td><td>220</td></tr><tr><td>215,20</td><td>220</td></tr><tr><td>215,15</td><td>220</td></tr><tr><td>214,68</td><td>220</td></tr><tr><td>214,51</td><td>220</td></tr><tr><td>214,60</td><td>220</td></tr><tr><td>215,35</td><td>220</td></tr><tr><td>214,50</td><td>220</td></tr><tr><td>214,84</td><td>220</td></tr><tr><td>214,96</td><td>220</td></tr><tr><td>216,02</td><td>220</td></tr><tr><td>215,47</td><td>220</td></tr><tr><td>215,46</td><td>220</td></tr><tr><td>214,58</td><td>220</td></tr></table>

<table border="1"><tr><td>214,60</td><td>220</td></tr><tr><td>215,25</td><td>220</td></tr><tr><td>214,82</td><td>220</td></tr><tr><td>214,70</td><td>220</td></tr><tr><td>214,05</td><td>220</td></tr><tr><td>214,72</td><td>220</td></tr><tr><td>235,56</td><td>240</td></tr><tr><td>236,14</td><td>240</td></tr><tr><td>235,64</td><td>240</td></tr><tr><td>235,78</td><td>240</td></tr><tr><td>235,04</td><td>240</td></tr><tr><td>236,04</td><td>240</td></tr><tr><td>235,37</td><td>240</td></tr><tr><td>236,10</td><td>240</td></tr><tr><td>236,58</td><td>240</td></tr><tr><td>235,21</td><td>240</td></tr><tr><td>236,55</td><td>240</td></tr><tr><td>234,61</td><td>240</td></tr><tr><td>235,52</td><td>240</td></tr><tr><td>235,88</td><td>240</td></tr><tr><td>236,21</td><td>240</td></tr><tr><td>235,11</td><td>240</td></tr><tr><td>236,16</td><td>240</td></tr><tr><td>236,10</td><td>240</td></tr><tr><td>235,95</td><td>240</td></tr><tr><td>235,33</td><td>240</td></tr><tr><td>255,07</td><td>260</td></tr><tr><td>254,80</td><td>260</td></tr><tr><td>255,26</td><td>260</td></tr><tr><td>254,95</td><td>260</td></tr><tr><td>255,36</td><td>260</td></tr><tr><td>255,21</td><td>260</td></tr><tr><td>255,09</td><td>260</td></tr><tr><td>254,92</td><td>260</td></tr><tr><td>254,42</td><td>260</td></tr><tr><td>254,69</td><td>260</td></tr></table>

<table border="1"><tr><td>255,05</td><td>260</td></tr><tr><td>254,75</td><td>260</td></tr><tr><td>254,51</td><td>260</td></tr><tr><td>253,39</td><td>260</td></tr><tr><td>254,93</td><td>260</td></tr><tr><td>254,39</td><td>260</td></tr><tr><td>254,56</td><td>260</td></tr><tr><td>254,59</td><td>260</td></tr><tr><td>254,63</td><td>260</td></tr><tr><td>254,76</td><td>260</td></tr><tr><td>273,65</td><td>280</td></tr><tr><td>274,25</td><td>280</td></tr><tr><td>274,28</td><td>280</td></tr><tr><td>274,40</td><td>280</td></tr><tr><td>274,06</td><td>280</td></tr><tr><td>273,68</td><td>280</td></tr><tr><td>274,06</td><td>280</td></tr><tr><td>274,21</td><td>280</td></tr><tr><td>274,18</td><td>280</td></tr><tr><td>274,76</td><td>280</td></tr><tr><td>274,81</td><td>280</td></tr><tr><td>274,42</td><td>280</td></tr><tr><td>274,71</td><td>280</td></tr><tr><td>274,79</td><td>280</td></tr><tr><td>274,30</td><td>280</td></tr><tr><td>274,69</td><td>280</td></tr><tr><td>274,26</td><td>280</td></tr><tr><td>274,74</td><td>280</td></tr><tr><td>274,28</td><td>280</td></tr><tr><td>273,65</td><td>280</td></tr><tr><td>294,83</td><td>300</td></tr><tr><td>294,65</td><td>300</td></tr><tr><td>294,28</td><td>300</td></tr><tr><td>294,72</td><td>300</td></tr><tr><td>294,38</td><td>300</td></tr><tr><td>294,55</td><td>300</td></tr></table>

<table border="1"><tr><td>294,40</td><td>300</td></tr><tr><td>294,41</td><td>300</td></tr><tr><td>293,93</td><td>300</td></tr><tr><td>293,56</td><td>300</td></tr><tr><td>294,19</td><td>300</td></tr><tr><td>293,63</td><td>300</td></tr><tr><td>293,66</td><td>300</td></tr><tr><td>294,17</td><td>300</td></tr><tr><td>293,30</td><td>300</td></tr><tr><td>292,10</td><td>300</td></tr><tr><td>294,41</td><td>300</td></tr><tr><td>293,76</td><td>300</td></tr><tr><td>294,12</td><td>300</td></tr><tr><td>294,71</td><td>300</td></tr></table>

<div align="center">

Prueba 2

</div>

<table border="1"><tr><td>Valor Medido</td><td>Valor Real</td></tr><tr><td>19,53</td><td>20</td></tr><tr><td>19,53</td><td>20</td></tr><tr><td>19,52</td><td>20</td></tr><tr><td>19,53</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>19,53</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>19,53</td><td>20</td></tr><tr><td>19,45</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>19,53</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>19,55</td><td>20</td></tr><tr><td>38,57</td><td>40</td></tr><tr><td>38,57</td><td>40</td></tr><tr><td>38,57</td><td>40</td></tr><tr><td>38,47</td><td>40</td></tr><tr><td>38,55</td><td>40</td></tr><tr><td>38,54</td><td>40</td></tr><tr><td>38,54</td><td>40</td></tr><tr><td>37,66</td><td>40</td></tr><tr><td>38,04</td><td>40</td></tr><tr><td>38,54</td><td>40</td></tr><tr><td>38,55</td><td>40</td></tr><tr><td>38,55</td><td>40</td></tr><tr><td>38,54</td><td>40</td></tr><tr><td>38,54</td><td>40</td></tr></table>

<table border="1"><tr><td>38,43</td><td>40</td></tr><tr><td>38,55</td><td>40</td></tr><tr><td>38,54</td><td>40</td></tr><tr><td>38,55</td><td>40</td></tr><tr><td>38,54</td><td>40</td></tr><tr><td>38,55</td><td>40</td></tr><tr><td>58,07</td><td>60</td></tr><tr><td>58,04</td><td>60</td></tr><tr><td>58,02</td><td>60</td></tr><tr><td>57,98</td><td>60</td></tr><tr><td>57,95</td><td>60</td></tr><tr><td>57,98</td><td>60</td></tr><tr><td>57,97</td><td>60</td></tr><tr><td>57,86</td><td>60</td></tr><tr><td>57,86</td><td>60</td></tr><tr><td>57,85</td><td>60</td></tr><tr><td>57,85</td><td>60</td></tr><tr><td>57,95</td><td>60</td></tr><tr><td>57,95</td><td>60</td></tr><tr><td>57,95</td><td>60</td></tr><tr><td>57,95</td><td>60</td></tr><tr><td>57,97</td><td>60</td></tr><tr><td>57,95</td><td>60</td></tr><tr><td>57,95</td><td>60</td></tr><tr><td>57,93</td><td>60</td></tr><tr><td>78,20</td><td>80</td></tr><tr><td>77,69</td><td>80</td></tr><tr><td>77,69</td><td>80</td></tr><tr><td>77,67</td><td>80</td></tr><tr><td>77,67</td><td>80</td></tr><tr><td>77,71</td><td>80</td></tr><tr><td>78,08</td><td>80</td></tr><tr><td>78,08</td><td>80</td></tr><tr><td>77,71</td><td>80</td></tr><tr><td>77,81</td><td>80</td></tr></table>

<table border="1"><tr><td>77,81</td><td>80</td></tr><tr><td>77,79</td><td>80</td></tr><tr><td>77,79</td><td>80</td></tr><tr><td>77,79</td><td>80</td></tr><tr><td>78,24</td><td>80</td></tr><tr><td>77,81</td><td>80</td></tr><tr><td>77,69</td><td>80</td></tr><tr><td>78,12</td><td>80</td></tr><tr><td>77,69</td><td>80</td></tr><tr><td>77,67</td><td>80</td></tr><tr><td>97,74</td><td>100</td></tr><tr><td>97,33</td><td>100</td></tr><tr><td>97,34</td><td>100</td></tr><tr><td>97,43</td><td>100</td></tr><tr><td>97,86</td><td>100</td></tr><tr><td>97,75</td><td>100</td></tr><tr><td>97,72</td><td>100</td></tr><tr><td>97,72</td><td>100</td></tr><tr><td>97,81</td><td>100</td></tr><tr><td>97,81</td><td>100</td></tr><tr><td>97,69</td><td>100</td></tr><tr><td>97,67</td><td>100</td></tr><tr><td>97,69</td><td>100</td></tr><tr><td>97,81</td><td>100</td></tr><tr><td>97,39</td><td>100</td></tr><tr><td>97,72</td><td>100</td></tr><tr><td>97,74</td><td>100</td></tr><tr><td>97,74</td><td>100</td></tr><tr><td>97,84</td><td>100</td></tr><tr><td>97,77</td><td>100</td></tr><tr><td>117,79</td><td>120</td></tr><tr><td>117,77</td><td>120</td></tr><tr><td>117,77</td><td>120</td></tr><tr><td>117,79</td><td>120</td></tr><tr><td>117,85</td><td>120</td></tr><tr><td>117,79</td><td>120</td></tr></table>

<table border="1"><tr><td>117,75</td><td>120</td></tr><tr><td>117,87</td><td>120</td></tr><tr><td>117,73</td><td>120</td></tr><tr><td>117,82</td><td>120</td></tr><tr><td>117,73</td><td>120</td></tr><tr><td>117,72</td><td>120</td></tr><tr><td>117,75</td><td>120</td></tr><tr><td>117,75</td><td>120</td></tr><tr><td>116,50</td><td>120</td></tr><tr><td>117,75</td><td>120</td></tr><tr><td>117,75</td><td>120</td></tr><tr><td>116,98</td><td>120</td></tr><tr><td>117,73</td><td>120</td></tr><tr><td>117,84</td><td>120</td></tr><tr><td>136,93</td><td>140</td></tr><tr><td>136,94</td><td>140</td></tr><tr><td>137,37</td><td>140</td></tr><tr><td>137,37</td><td>140</td></tr><tr><td>136,17</td><td>140</td></tr><tr><td>136,98</td><td>140</td></tr><tr><td>136,87</td><td>140</td></tr><tr><td>136,86</td><td>140</td></tr><tr><td>137,01</td><td>140</td></tr><tr><td>136,86</td><td>140</td></tr><tr><td>139,99</td><td>140</td></tr><tr><td>136,91</td><td>140</td></tr><tr><td>136,99</td><td>140</td></tr><tr><td>136,91</td><td>140</td></tr><tr><td>137,01</td><td>140</td></tr><tr><td>136,91</td><td>140</td></tr><tr><td>137,46</td><td>140</td></tr><tr><td>136,93</td><td>140</td></tr><tr><td>157,03</td><td>160</td></tr><tr><td>157,04</td><td>160</td></tr></table>

<table border="1"><tr><td>157,04</td><td>160</td></tr><tr><td>156,61</td><td>160</td></tr><tr><td>156,61</td><td>160</td></tr><tr><td>157,45</td><td>160</td></tr><tr><td>157,04</td><td>160</td></tr><tr><td>156,31</td><td>160</td></tr><tr><td>156,61</td><td>160</td></tr><tr><td>157,03</td><td>160</td></tr><tr><td>157,04</td><td>160</td></tr><tr><td>157,04</td><td>160</td></tr><tr><td>156,20</td><td>160</td></tr><tr><td>155,82</td><td>160</td></tr><tr><td>157,04</td><td>160</td></tr><tr><td>157,04</td><td>160</td></tr><tr><td>155,79</td><td>160</td></tr><tr><td>157,03</td><td>160</td></tr><tr><td>157,03</td><td>160</td></tr><tr><td>156,61</td><td>160</td></tr><tr><td>175,94</td><td>180</td></tr><tr><td>176,78</td><td>180</td></tr><tr><td>176,78</td><td>180</td></tr><tr><td>175,62</td><td>180</td></tr><tr><td>176,73</td><td>180</td></tr><tr><td>176,77</td><td>180</td></tr><tr><td>175,94</td><td>180</td></tr><tr><td>175,94</td><td>180</td></tr><tr><td>176,35</td><td>180</td></tr><tr><td>175,18</td><td>180</td></tr><tr><td>176,34</td><td>180</td></tr><tr><td>176,32</td><td>180</td></tr><tr><td>175,16</td><td>180</td></tr><tr><td>175,94</td><td>180</td></tr><tr><td>176,71</td><td>180</td></tr><tr><td>176,32</td><td>180</td></tr><tr><td>176,73</td><td>180</td></tr><tr><td>176,34</td><td>180</td></tr></table>

<table border="1"><tr><td>176,73</td><td>180</td></tr><tr><td>175,94</td><td>180</td></tr><tr><td>196,07</td><td>200</td></tr><tr><td>196,66</td><td>200</td></tr><tr><td>195,80</td><td>200</td></tr><tr><td>195,84</td><td>200</td></tr><tr><td>196,66</td><td>200</td></tr><tr><td>196,56</td><td>200</td></tr><tr><td>196,52</td><td>200</td></tr><tr><td>196,50</td><td>200</td></tr><tr><td>196,62</td><td>200</td></tr><tr><td>196,20</td><td>200</td></tr><tr><td>196,21</td><td>200</td></tr><tr><td>196,64</td><td>200</td></tr><tr><td>196,62</td><td>200</td></tr><tr><td>196,52</td><td>200</td></tr><tr><td>196,54</td><td>200</td></tr><tr><td>196,62</td><td>200</td></tr><tr><td>196,64</td><td>200</td></tr><tr><td>196,66</td><td>200</td></tr><tr><td>195,09</td><td>200</td></tr><tr><td>196,23</td><td>200</td></tr><tr><td>215,83</td><td>220</td></tr><tr><td>215,01</td><td>220</td></tr><tr><td>215,59</td><td>220</td></tr><tr><td>215,92</td><td>220</td></tr><tr><td>215,46</td><td>220</td></tr><tr><td>215,42</td><td>220</td></tr><tr><td>214,99</td><td>220</td></tr><tr><td>214,94</td><td>220</td></tr><tr><td>215,44</td><td>220</td></tr><tr><td>214,67</td><td>220</td></tr><tr><td>214,48</td><td>220</td></tr><tr><td>214,92</td><td>220</td></tr><tr><td>215,37</td><td>220</td></tr><tr><td>215,37</td><td>220</td></tr></table>

<table border="1"><tr><td>214,08</td><td>220</td></tr><tr><td>214,12</td><td>220</td></tr><tr><td>215,20</td><td>220</td></tr><tr><td>214,80</td><td>220</td></tr><tr><td>215,32</td><td>220</td></tr><tr><td>215,55</td><td>220</td></tr><tr><td>236,46</td><td>240</td></tr><tr><td>235,81</td><td>240</td></tr><tr><td>235,80</td><td>240</td></tr><tr><td>236,34</td><td>240</td></tr><tr><td>236,43</td><td>240</td></tr><tr><td>236,38</td><td>240</td></tr><tr><td>235,81</td><td>240</td></tr><tr><td>236,33</td><td>240</td></tr><tr><td>236,38</td><td>240</td></tr><tr><td>236,45</td><td>240</td></tr><tr><td>236,41</td><td>240</td></tr><tr><td>236,31</td><td>240</td></tr><tr><td>236,36</td><td>240</td></tr><tr><td>235,52</td><td>240</td></tr><tr><td>235,93</td><td>240</td></tr><tr><td>236,41</td><td>240</td></tr><tr><td>236,41</td><td>240</td></tr><tr><td>235,88</td><td>240</td></tr><tr><td>236,36</td><td>240</td></tr><tr><td>236,36</td><td>240</td></tr><tr><td>255,12</td><td>260</td></tr><tr><td>254,68</td><td>260</td></tr><tr><td>254,75</td><td>260</td></tr><tr><td>255,26</td><td>260</td></tr><tr><td>255,11</td><td>260</td></tr><tr><td>254,69</td><td>260</td></tr><tr><td>254,66</td><td>260</td></tr><tr><td>254,73</td><td>260</td></tr><tr><td>255,00</td><td>260</td></tr><tr><td>255,23</td><td>260</td></tr></table>

<table border="1"><tr><td>254,28</td><td>260</td></tr><tr><td>254,68</td><td>260</td></tr><tr><td>254,68</td><td>260</td></tr><tr><td>254,69</td><td>260</td></tr><tr><td>254,64</td><td>260</td></tr><tr><td>255,12</td><td>260</td></tr><tr><td>254,99</td><td>260</td></tr><tr><td>254,59</td><td>260</td></tr><tr><td>255,29</td><td>260</td></tr><tr><td>255,94</td><td>260</td></tr><tr><td>275,50</td><td>280</td></tr><tr><td>275,57</td><td>280</td></tr><tr><td>276,39</td><td>280</td></tr><tr><td>275,50</td><td>280</td></tr><tr><td>275,46</td><td>280</td></tr><tr><td>275,50</td><td>280</td></tr><tr><td>276,10</td><td>280</td></tr><tr><td>275,48</td><td>280</td></tr><tr><td>275,63</td><td>280</td></tr><tr><td>274,97</td><td>280</td></tr><tr><td>275,96</td><td>280</td></tr><tr><td>275,02</td><td>280</td></tr><tr><td>275,93</td><td>280</td></tr><tr><td>276,06</td><td>280</td></tr><tr><td>275,40</td><td>280</td></tr><tr><td>279,13</td><td>280</td></tr><tr><td>275,00</td><td>280</td></tr><tr><td>275,72</td><td>280</td></tr><tr><td>275,27</td><td>280</td></tr><tr><td>275,77</td><td>280</td></tr><tr><td>295,37</td><td>300</td></tr><tr><td>295,41</td><td>300</td></tr><tr><td>294,91</td><td>300</td></tr><tr><td>294,88</td><td>300</td></tr><tr><td>294,81</td><td>300</td></tr><tr><td>295,17</td><td>300</td></tr></table>

<table border="1"><tr><td>295,08</td><td>300</td></tr><tr><td>294,59</td><td>300</td></tr><tr><td>294,98</td><td>300</td></tr><tr><td>294,57</td><td>300</td></tr><tr><td>294,60</td><td>300</td></tr><tr><td>294,76</td><td>300</td></tr><tr><td>294,98</td><td>300</td></tr><tr><td>295,10</td><td>300</td></tr><tr><td>294,55</td><td>300</td></tr><tr><td>294,96</td><td>300</td></tr><tr><td>294,96</td><td>300</td></tr><tr><td>295,36</td><td>300</td></tr><tr><td>295,00</td><td>300</td></tr><tr><td>295,41</td><td>300</td></tr></table>

## A.4. Códigos de respuesta protocolo HTTP

<div align="center">

Tabla A.1: Códigos de respuesta HTTP

</div>

<table border="1"><tr><td>Código</td><td>Mensaje</td><td>Descripción</td></tr><tr><td>10X</td><td>Mensaje de informacion</td><td>Estos códigos no se utilizan en la version 1.0 del protocolo.</td></tr><tr><td>20X</td><td>Exito</td><td>Estos códigos indican la correcta ejecución de la transacción.</td></tr><tr><td>200</td><td>OK</td><td>La solicitud se llevó a cabo de manera correcta.</td></tr><tr><td>201</td><td>CREATED</td><td>Sigue a un comando POST e indica el exito, la parte restante del cuerpo indica la dirección URL donde se ubicará el documento creado recientemente.</td></tr><tr><td>202</td><td>ACCEPTED</td><td>La solicitud ha sido aceptada, pero el procedimiento que sigue no se ha llevado a cabo.</td></tr><tr><td>203</td><td>PARTIAL INFORMATION</td><td>Cuando se recibe este código en respuesta a un comando de GET indica que la respuesta no está completa.</td></tr><tr><td>204</td><td>NO RESPONSE</td><td>El servidor ha recibido la solicitud, pero no hay información de respuesta.</td></tr><tr><td>205</td><td>RESET CONTENT</td><td>El servidor le indica al navegador que borre el contenido en los campos de un formulario.</td></tr><tr><td>206</td><td>PARTIAL CONTENT</td><td>Es una respuesta a una solicitud que consiste en el encabezado range. El servidor debe indicar el encabezado contentRange.</td></tr><tr><td>30X</td><td>Redirección</td><td>Estos códigos indican que el recurso ya no se encuentra en la ubicación especificada.</td></tr><tr><td>301</td><td>MOVED</td><td>Los datos solicitados han sido transferidos a una nueva dirección.</td></tr><tr><td>302</td><td>FOUND</td><td>Los datos solicitados se encuentran en una nueva dirección URL.</td></tr><tr><td colspan="3">Continua en la siguiente página</td></tr></table>

<div align="center">

Tabla A.1 - Continuación de la página anterior

</div>

<table border="1"><tr><td>Código</td><td>Mensaje</td><td>Descripción</td></tr><tr><td>303</td><td>METHOD</td><td>Significa que el cliente debe intentarlo con una nueva dirección.</td></tr><tr><td>304</td><td>NOT MODIFIED</td><td>Si el cliente llevó a cabo un comando GET condicional y el documento no ha sido modificado, este código se envía como respuesta.</td></tr><tr><td>40X</td><td>Error debido al cliente</td><td>Estos códigos indican que la solicitud es incorrecta.</td></tr><tr><td>400</td><td>BAD REQUEST</td><td>La sintaxis de la solicitud se encuentra formulada de manera errónea o es imposible de responder.</td></tr><tr><td>401</td><td>UNAUTHORIZED</td><td>Los parámetros del mensaje aportan las específicaciones de formularios de autorización que se admiten.</td></tr><tr><td>402</td><td>PAYMENT REQUIRED</td><td>El cliente debe reformular la solicitud con los datos de pago correctos.</td></tr><tr><td>403</td><td>FORBIDDEN</td><td>El acceso al recurso simplemente se deniega.</td></tr><tr><td>404</td><td>NOT FOUND</td><td>El servidor no halló nada en la dirección específica.</td></tr><tr><td>50X</td><td>Error debido al servidor</td><td>Estos códigos indican que existe un error interno en el servidor.</td></tr><tr><td>500</td><td>INTERNAL ERROR</td><td>El servidor encontró una condición inesperada que le impide seguir con la solicitud.</td></tr><tr><td>501</td><td>NOT IMPLEMENTED</td><td>El servidor no admite el servicio solicitado.</td></tr><tr><td>502</td><td>BAD GATEWAY</td><td>El servidor que actúa como una puerta de enlace o proxy ha recibido una respuesta no válida del servidor al que intenta acceder.</td></tr><tr><td>503</td><td>SERVICE UNAVAILABLE</td><td>El servidor no puede responder en ese momento debido a que se encuentra congestionado.</td></tr><tr><td colspan="3">Continúa en la siguiente página</td></tr></table>

<div align="center">

Tabla A.1 - Continuación de la página anterior

</div>

<table border="1"><tr><td>Código</td><td colspan="2">Mensaje</td><td>Descripción</td></tr><tr><td>504</td><td>GATEWAY
TIMEOUT</td><td></td><td>La respuesta del servidor ha llevado demasiado tiempo en relación al tiempo de espera que la puerta de enlace podía admitir.</td></tr></table>
