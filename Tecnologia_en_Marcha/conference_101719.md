---
source: "C:/repos/ASADA_Paso_Ancho/paper/conference_101719.pdf"
title: "conference_101719"
converted_at: "2026-08-05T18:42:15Z"
---

<div align="center">

# Towards a Modular IoT System Architecture for Rural Aqueducts Using Model Based Systems Engineering

</div>

Anthony José Arguedas-Rodríguez

Tecnológico de Costa Rica

Cartago, Costa Rica

https://orcid.org/0009-0002-1662-1656

María José Angulo-Campos

Tecnológico de Costa Rica

Cartago, Costa Rica

Juan José Rojas-Hernádez

Juan José Montero-Jiménez

https://orcid.org/0009-0005-5842-1101

Tecnológico de Costa Rica

Tecnológico de Costa Rica

Cartago, Costa Rica

Cartago, Costa Rica

https://orcid.org/0000-0002-3261-5005

https://orcid.org/0000-0002-3215-3736

Abstract—Rural aqueducts play a vital role in sustaining the communities they serve by managing the essential water resource. A common challenge for rural aqueducts is related to water loss and rudimentary monitoring methods. Internet of Things (IoT) enabled systems offer a promising solution to improve water management, yet their design complexity and costs often exceed technical and financial capacities in rural aqueducts. This study proposes a Model-Based Systems Engineering (MBSE) approach to develop a modular IoT architecture tailored to rural aqueducts. Using the ARCADIA methodology and the Capella modeling tool, the process translates informal user needs into structured requirements and logical system designs. The resulting architectures are modular, adaptable, and aligned with end-user conditions. The methodology is accessible enough to be implemented by undergraduate students, positioning academic institutions as effective intermediaries for technology transfer. By formalizing needs and systematically guiding architecture development, MBSE offers a structured pathway to create IoT solutions for water monitoring and loss prevention. This approach provides a scalable, explainable framework to support the modernization of rural aqueduct systems.

Index Terms—rural aqueducts, internet of things, model-based systems engineering, technology transfer, water management

## I. INTRODUCTION

Water is an indispensable natural resource for life on Earth, and access to safe drinking water is both a basic human need and a fundamental right [1]. Ensuring the availability and quality of water is essential for the well-being and development of any population. Yet, for many rural communities worldwide, this remains a critical challenge.

In these communities, the problem is often related not only to water scarcity but also to the lack of adequate infrastructure for collection, treatment, and distribution [2] [3]. The responsibility for managing and maintaining this infrastructure frequently falls to locally administered rural aqueducts, which operate with limited resources, outdated technologies, and low

operational efficiency. These limitations contribute to issues such as water loss and unreliable service.

The Internet of Things (IoT) offers a promising means to address these limitations. Through automated monitoring and anomaly detection, IoT technologies can significantly enhance operational efficiency in rural aqueducts [4]. However, high costs and limited customization options make commercial IoT solutions largely inaccessible for these small-scale systems.

Developing low-cost, tailored IoT solutions represents a feasible alternative to support rural aqueducts. In this context, Systems Engineering may offer a structured approach to guide the development of these solutions, ensuring that technical, operational, and contextual factors are properly considered.

Academic institutions, particularly through student-led technology transfer initiatives, can play a key role by contributing technical expertise and promoting the use of systematic development methodologies. One of the main motivations of the current work are multiple independent student initiatives of IoT Systems for rural aqueducts [5] [6]. This enhances both the educational impact and the likelihood of producing reliable, scalable, and context-appropriate IoT systems.

To this end, this work proposes a generic system architecture for rural aqueducts developed using the ARCADIA method [7], a Model-Based Systems Engineering (MBSE) methodology. This architecture is intended to serve as a foundation for the design of modular IoT systems that address the specific challenges faced by rural aqueducts. The remainder of this paper is organized as follows: Section II presents the context of IoT systems for rural aqueducts and provides an overview of the current state of the art. Section III is dedicated to the proposed modular IoT system architecture for rural aqueducts. This section is divided in four parts, the theory background on system architecture based on ARCADIA method, the requirements analysis derived from initial needs and desires for the IoT system, the modular architecture proposal using ARCADIA method, and the implementation on a real case

study for the physical architecture. Section IV is dedicated to the analysis and discussion on the proposed architecture. Finally, Section V concludes the paper and outlines future research directions.

## II. IOT SYSTEMS FOR RURAL AQUEDUCTS CONTEXT

The implementation of IoT systems for rural aqueducts is not new. In the last decade, multiple research initiatives have been developed and published. To ensure novelty on the work that is presented in this research, a complete and impartial search on previous studies has been conducted. Two research questions were proposed as a starting point for the literature survey:

- RQ1: Are there existing systems engineering-based (including ARCADIA MBSE) architectures for the design of IoT systems for rural aqueducts?

- RQ2: If they exist, are the architectures generic and modular?

Based on the research questions, a search on Scopus indexed publications was conducted based on title, abstract and keywords. The search queries were the following:

- "rural aqueduct" IoT architecture, "water distribution system" IoT architecture rural, "rural water supply" IoT architecture

- "systems engineering" IoT architecture "rural aqueduct", "systems engineering" "water distribution system" rural IoT, ARCADIA IoT architecture, ARCADIA "rural aqueduct" IoT, "model-based systems engineering" IoT rural water

The inclusion criterion was that the results had to be related to IoT systems and some aspect of water distribution systems, rural or not. The results of the search showed that three out of the eight queries for RQ1 and RQ2 returned zero results, and for the remaining five queries, a total of 75 results were retrieved. Out of these, only 21 met the inclusion criterion, and the most pertinent are presented below.

A systematic review by [8] provides a broad overview of IoT-based water monitoring and distribution systems, addressing applications, sensor technologies, and the role of artificial intelligence. However, no formal or generic architecture is proposed, though the need for such a framework is acknowledged. Similarly, [9] presents a methodology for designing IoT-based rural water distribution systems, applied to a case study in India. Despite its claims of generality, the work lacks a formal, layered architecture and systematic derivation from stakeholder requirements.

Paper [10] presents the IoTA4IWNet WDS architecture, which aims to provide a structure for water distribution systems with four distinct planes: edge, fog, cloud, and service. While its modularity and generality are suggested through broad technological coverage, no systems engineering approach is used, and no clear process is provided to adapt the architecture to specific stakeholder needs. In [11], another IoT architecture is presented named the REFlex Water architecture. The study introduces physical, middleware, and

application layers, emphasizing flexibility through declarative process models. However, the work lacks systematic guidance for translating stakeholder needs into system design. Similarly, [12] proposes a layered IoT architecture with modules for monitoring, control, and data management. While modular in structure, the absence of a formal methodology or modeling language limits its adaptability. A more formal approach is seen in the BRAIN-IoT framework by [13], which employs multiple formal modeling languages to structure system, software, and physical layers. Although grounded in systems engineering principles, the work does not follow ARCADIA, and the procedure for incorporating stakeholder needs is not detailed. Another example is found in [14], which describes a IoT-based water management tools for rural communities in India, focusing on water level monitoring. Despite claiming generality, the architecture is specific to the technology used, with no formal mechanisms for adaptation beyond basic configuration.

None of the reviewed studies explicitly apply the ARCA-DIA MBSE method or systematically integrate generality and modularity as architectural requirements. While some works imply modularity or use formal modeling, they do not provide structured, traceable processes to connect stakeholder needs with system behavior, leaving this task to the reader. The current work addresses the identified gaps in these existing generic architectures.

## III. A MODULAR IOT SYSTEM ARCHITECTURE FOR RURAL AQUEDUCTS

This section is intended for the main contribution of the current research. As a starting point, a brief introduction to the theoretical background used to develop the modular architecture is provided. Subsequently, the requirements analysis for the IoT system is conducted. Finally, the modular architecture is presented as the principal milestone in the process.

## A. Theoretical background on system architecture

Model-Based Systems Engineering (MBSE) represents a shift from traditional document-centric engineering to an approach centered on the use of a system model as the basis for the design process [15]. The Architecture Analysis and Design Integrated Approach (ARCADIA) is a structured Model-Based Systems Engineering (MBSE) method used to design complex systems through a series of interrelated engineering phases [7]. A key principle is the separation of user needs from system design, ensuring the system fulfills expectations without unnecessary complexity. The ARCADIA approach is illustrated in Figure 1 and explained hereafter.

The process begins with Operational Need Analysis, which models stakeholder activities and desired capabilities, focusing on what users must achieve independently of any supporting system. This helps define scope, avoid oversizing, and capture general needs by representing diverse operational contexts.

Next, the System Need Analysis identifies what the system must achieve by translating selected operational activities into system functions, enriched with non-functional constraints



<div align="center">

Fig. 1. Phases of the ARCADIA model-based systems engineering method [16].

</div>

such as performance, cost, and security. Functional exchanges model the necessary flows of information and resources between users, systems, and external actors.

The Logical Architecture phase organizes system functions into abstract components and defines how they interact through component exchanges. This architecture remains technologyagnostic, offering flexibility in implementation.

Finally, the Physical Architecture maps behaviors to actual hardware and software components. It captures nearly all system requirements in model form, enabling traceability from stakeholder needs to final design. Viewpoints, particularly modularity, guide the architecture to remain adaptable without requiring redesign when components change.

In this work, all system and organizational models developed throughout the various engineering phases were diagrammed using the Capella software. This tool provides both a dedicated modeling language and methodological guidance for all steps of the ARCADIA method [15].

## B. Requirements analysis of IoT systems for rural aqueducts

A central goal of this research is to develop a generic solution capable of addressing a wide range of functional and non-functional requirements, making it applicable to rural aqueducts operating under diverse conditions. To support this, an additional literature review was conducted to answer the question: What are the needs and desires of rural aqueducts that can be addressed by IoT systems?

The inclusion criteria required that studies focus specifically on the Internet of Things in the context of rural aqueducts or water distribution systems, excluding urban and industrial settings but allowing urban-rural interfaces. This process yielded 84 relevant papers.

Each paper was reviewed in full, and a large language model (gemini-2.5-pro-preview-05-06 by Google) [17] was used to extract identified needs and desires. The model was instructed to preserve the original phrasing where possible

and to restructure only when necessary—for example, by separating compound requirements expressed in prose for greater clarity.

Text embeddings were calculated for each need and desire using the all-MiniLM-L6-v2 model [18] to obtain vector representations of their semantic content. To remove any needs and desires potentially hallucinated by the large language model, the paper full texts were embedded as 100 character chunks, and the L2 distance between every need and desire and the most similar chunk in its originating full text was calculated. All needs and desires with a z-score greater than 3 with respect to this L2 distance were discarded as hallucinations.

With the aim of generating a small but representative needs and desires list, a BERTopic model [19] was trained to cluster the embeddings and derive keyword-defined topics. The three most representative documents per cluster and their associated keywords were used to derive up to three needs and desires per cluster. A summary of the representative needs and desires extracted for the review is presented in Table I.

## C. A modular IoT architecture development for rural aqueducts using ARCADIA method

Following the ARCADIA method, the needs and desires listed in Table I were translated into an organizational needs model, with rural aqueducts serving as the relevant organizational entities (Figure 2). This model represents the operational activities that rural aqueducts undertake to achieve their desired organizational capabilities. Based on the literature, these capabilities are identified as: (1) providing high-quality water, (2) complying with water quality standards, (3) mitigating water loss, and (4) sharing data with external entities.

It is important to note that this organizational analysis assumes rural aqueducts operate without the support of any systems (IoT-based or otherwise) to carry out their operational

<div align="center">

TABLE I

</div>

<div align="center">

NEEDS AND DESIRES EXTRACTED FROM THE PAPER FULL TEXT EMBEDDINGS USING BERTOPIC.

</div>

<table border="1"><tr><td>Code</td><td>Need or desire</td></tr><tr><td>ND1.1</td><td>Identify sources of water pollution</td></tr><tr><td>ND1.2</td><td>Monitor water pollution</td></tr><tr><td>ND2</td><td>Monitor water pH</td></tr><tr><td>ND3</td><td>Monitor water turbidity</td></tr><tr><td>ND4</td><td>Monitor water conductivity</td></tr><tr><td>ND5</td><td>Monitor chlorine dosing</td></tr><tr><td>ND6</td><td>Ensure standards(from EPA, WHO, etc.) for water quality are fulfilled</td></tr><tr><td>ND7</td><td>Monitor water potability</td></tr><tr><td>ND8</td><td>Monitor fertilizer components(nitrate, fluoride, arsenic, zinc, calcium, potassium, phosphate) in water</td></tr><tr><td>ND9</td><td>Monitor bacterial proliferation in water</td></tr><tr><td>ND10</td><td>Mitigate water loss due to leakage</td></tr><tr><td>.</td><td>.</td></tr><tr><td>.</td><td>.</td></tr><tr><td>.</td><td>.</td></tr><tr><td>ND51</td><td>Wireless sensor networks</td></tr><tr><td>ND52</td><td>MQTT node communication</td></tr><tr><td>ND53</td><td>Mobile network connectivity</td></tr><tr><td>ND54</td><td>WiFi connectivity</td></tr><tr><td>ND55</td><td>LoRaWAN connectivity</td></tr></table>



<div align="center">

Fig. 2. Organizational needs analysis model for rural aqueducts.

</div>

activities. Consequently, monitoring tasks could be performed manually by the organizations, typically through direct inspection and physical testing, without any technological assistance. This reflects the reality of many rural aqueducts, where resource constraints limit access to automation. The intention behind omitting IoT systems at this stage is to emphasize the core responsibilities that rural aqueducts must fulfill, regardless of whether or not technological tools are available. Thus, all technology-specific needs and desires obtained from the literature were abstracted up to their core contribution to rural aqueducts.

To incorporate IoT systems as tools that support rural aqueducts in performing their operational activities more effectively, a generic and modular system needs model is presented in Figure 3. This model defines what the system must accomplish for its users while intentionally leaving the underlying technological implementation open for future design decisions.

The system is designed to deliver the following capabilities: (1) provide water quality data, (2) provide water loss data, (3) provide information on water supply and demand, (4) control water distribution, and (5) enable data sharing with external entities.

It is important to mention that the system-generated data on water quality and water loss go beyond basic measurements, as it also includes automated detection of pollution sources and water loss events, among other events. Rural aqueduct users are alerted of all events via notifications, offering enhanced insights that would be difficult to obtain through manual monitoring alone. The data flow that enables this event detection functionality is also modeled through functional exchanges within the system, describing the variables involved as inputs and outputs and the functions that produce and process them.

From this second perspective, monitoring activities are delegated to the system, while the organization's role shifts to consulting the collected data and implementing strategies

based on it. Modularity is incorporated by minimizing dependencies between functions across different system capabilities and by generalizing system functions to achieve high-level objectives through various methods and data sources. For example, the system function Measure water quality does not specify exact variables and metrics to maintain flexibility; however, common parameters identified in the literature—such as pH and turbidity—are included as constraints.

Another crucial implementation of modularity at the system needs analysis level is the separation of the water distribution system (WDS), hydraulic in nature, from the IoT system which is the focus of this work. To this purpose, the WDS is represented as an external entity for which only its interactions with the IoT system—water distribution parameters optimized by the latter—are constrained, while its internal functional content is recognized as out of scope.

Following the operational and system needs analysis, the design of the solution architecture proceeds with the definition of the logical architecture (Figure 4). This logical structure describes the desired system behaviors necessary to meet user needs. At this stage, the system is decomposed into behavioral components, each with distinct functions. Through the interactions and functional exchanges among these components, the collective behavior required from the system is realized.

The modularity requirement influenced the logical architecture by separating the behavioral components that interact with end users from those that interface with the environment, while simplifying the former. This design allows data acquisition and processing components to be modified to include or exclude variables as needed, yet they consistently communicate with users through the more generic long-term storage, dashboard, and notifier components. These latter components maintain consistent behavior regardless of the number or type of variables monitored or the complexity of detected events, as they merely respond to user requests by presenting pre-existing data



<div align="center">

Fig. 3. System needs analysis model of a generic and modular IoT system for rural aqueducts.

</div>

in predefined formats, such as notifications or dashboards.

Additionally, three important concepts supporting modularity are introduced through component exchanges: buses, queues, and publish/subscribe (pub/sub) channels, also called topics. Buses transport measurement data from sensors to the data acquisition subsystem via a multi-point interface, allowing sensors measuring different variables to be added or removed without affecting the underlying infrastructure.

Queues are first-in, first-out buffers that temporarily store data until the receiving component is ready to consume it. This decouples data processing components from the data-producing components, enabling measurements to be processed not individually, when they lack context, but within a time window, by enabling the dedicated Measurement window behavioral component to trigger event detection and processing tasks only when the measurement windows are fully populated. Importantly, the rate at which windows populate is determined by user-configurable data collection frequencies and window sizes.

On a related note, pub/sub channels function as named queues that can be nested to represent hierarchies of variables, data streams, and events. Compared to queues, pub/sub channels generally involve higher latency and internet-based data transactions.

The generality and modularity of the proposed solution do not limit its value for potential IoT system designers, as it captures essential design guidelines within the component exchange models. Specifically, it requires that data transactions from acquisition and processing to long-term storage be enabled via a querying language. Moreover, the architecture prescribes routing all incoming user data requests through a dashboard, greatly simplifying user access control and interaction mechanisms.

## D. An implementation on a real case study

To exemplify how the generic and modular IoT architecture presented in this work can be tailored to specific contexts and configured for deployment, a physical IoT system architecture was developed for the rural aqueduct of ASADA Paso Ancho, in the province of Cartago, Costa Rica. The first step in this effort was to revise the operational analysis and preserve only the operational activities that this aqueduct carries out, and similarly for the system needs.

This operational need-based refinement was carried out up to the physical architecture, which is presented in Figure 5. The main modification done to the logical architecture is the implementation of technology-specific needs and desires, exemplified in the replacement of the sensor bus with the



<div align="center">

Fig. 4. Logical architecture of a generic and modular IoT system for rural aqueducts. Some functional exchanges and logical actors are hidden for clarity.

</div>

dedicated electrical communication channels for the sensors already present at this rural aqueduct. Also, physical components necessary for an actual on-site implementation where modeled and their functional and non-functional requirements were stated, for example in the case of the solar powered battery that powers the physical component (a microcontroller) that hosts the data acquisition and processing subsystems.

To show the modularity of the logical architecture, the longterm storage, dashboard, and notifier behavioral components were moved to software server hosts, connected to the microcontroller deployed on-site via mobile networks. This reduces physical and information technology maintenance costs for the rural aqueduct, while also improving the system robustness by separating behaviors into physical components without a shared failure mode.

## IV. DISCUSSION

The needs and desires extracted through data mining are representative of the general context of rural aqueducts. This is not only due to their alignment with findings from prior

literature reviews [8] [10], but also because they were systematically derived from a substantial portion of the available academic work on the topic. Additionally, the use of BERTopic to represent thematic groupings helped weight these needs and desires by frequency, offering a proxy for their relative importance across rural aqueduct systems.

The systematic progression from needs and desires to solution architecture, as prescribed by the ARCADIA method, was essential in achieving robust generality. Rather than limiting requirement consideration to early design stages, the method ensures that these requirements are fulfilled by the final solution through explicit traceability from logical or physical architecture back to stakeholder needs. The concept of operational analysis also plays a critical role in demonstrating and communicating this generality, allowing readers to relate the engineering approach directly to their own context-free from the constraints of specific technology choices.

The generic operational need analysis revealed that rural aqueducts share a core set of activities, each governed by



<div align="center">

Fig. 5. Physical architecture of an IoT system for ASADA Paso Ancho in Cartago, Costa Rica.

</div>

multiple non-functional requirements. For instance, the activity of monitoring water quality may involve variables ranging from turbidity and pH to bacterial presence. To support this diversity while preserving generality, non-functional requirements were assigned to the functions that can implement them. Enabling multiple configuration options in parallel required the component exchange between sensors and the data acquisition subsystem to be defined as a bus. This architecture allows data acquisition to interface with a wide range of sensors through shared physical connections, minimizing design complexity by ensuring uniform integration of compatible sensors.

The capability for pollution source identification further emphasizes the importance of modularity. This function depends on multiple sensor subsystems deployed across the aqueduct's service area to add geospatial resolution to water quality data. The proposed architecture supports this by decoupling data acquisition and processing from long-term storage, enabling distributed sensing nodes while centralizing storage to handle high volumes of concurrent connections. Importantly, this configuration is only one of many viable implementations allowed by the logical architecture, which remains agnostic to specific technologies.

With regard to data flow, the use of measurement queues

to decouple data production and processing is particularly relevant to the identified user desire of employing machine learning and other processing-heavy methods for pollution source and water loss event detection, among other tasks, in contrast to more lightweight and traditional rules-based approaches. Furthermore, this separation is also crucial in allowing system designers to implement the proposed architecture using wireless sensor networks, a common user need in the literature, where measurement nodes are commonly physically independent of data processing units yet operate at a high frequency [20].

In the case of automatic water distribution control, the architecture introduces an important modularity consideration by modeling the physical distribution infrastructure (tanks, valves, pipes) as a separate entity from the core IoT system. This decision acknowledges that water distribution systems are an operational prerequisite for any rural aqueduct, even in the absence of digital systems. To maintain generality, the architecture avoids specifying detailed functional or nonfunctional characteristics of distribution systems. Instead, it focuses on ensuring integration by requiring that such systems be capable of receiving control commands via a pub/sub communication channel.

The role of functional and component exchanges within ARCADIA models must be emphasized. These exchanges define the interactions between system functions, while remaining open to further refinement at the logical architecture level. This information not only informs the physical architecture but also clarifies external dependencies critical for system integration. As a result, individual functions or subsystems can be abstracted as self-contained modules—each potentially undergoing the ARCADIA method independently. This approach facilitates their development while positioning them as reusable, configurable components within broader IoT solutions, which, for example, would facilitate adapting the Notifier, Event detection and Data processing components to generate new insights based on the existing data flows, requiring substantially less adaptation effort compared to an IoT system architecture not developed as an MBSE model.

## V. CONCLUSIONS AND FUTURE WORK PERSPECTIVES

This work presented a generic and modular IoT system architecture for rural aqueducts, grounded in a systematic application of the ARCADIA Model-Based Systems Engineering method. By deriving needs and desires from a comprehensive literature-based data mining process, the solution addresses a broad spectrum of functional and non-functional requirements relevant to diverse rural contexts.

The ARCADIA method enabled a traceable and structured design process, ensuring that stakeholder needs are not only captured but also fulfilled throughout the logical and physical architecture stages. The operational analysis phase was particularly valuable in preserving generality, as it abstracted technological choices and allowed system designers to focus on what rural aqueducts must achieve, regardless of implementation constraints.

Modularity was a core design principle, reflected in the separation of user-facing and environment-interfacing components, the use of flexible communication models such as buses and pub/sub channels, and the definition of configurable system functions. This approach facilitates scalability, reusability, and adaptation to varying levels of technical capacity in rural settings.

Overall, the proposed approach provides a practical and adaptable foundation for developing IoT-based monitoring and control systems in rural aqueducts. It is further intended as a guideline for student-driven and academic technology transfer initiatives, fostering sustainable and context-aware digitalization in underserved water management systems.

Future work will focus on extending the identification and formalization of requirements through the use of text embeddings applied to a broader set of references. Additionally, further development of physical components with implementation-specific requirements is an opportunity to advance the proposed architecture into a complete, low-cost, and deployable solution for particular rural aqueducts.

## REFERENCES

[2] S. LeValley, K. Simukonda, F. Udenby, E. Nyirenda, and D. Meyer, "Improved but insufficient rural water infrastructure: qualitative insights from six villages in zambia," Journal of Water, Sanitation and Hygiene for Development, vol. 15, no. 5, pp. 384-397, 04 2025.

[3] L. Gaviria-Montoya, M. Pino-Gómez, and S. Soto-Córdoba, "Risk associated with the water infrastructure in rural water suppliers in turrialba cartago, costa rica," Sustain. Water Resour. Manag., vol. 6, p. 56, 2020.

[4] T. Robles, R. Alcarria, D. Martín, A. Morales, M. Navarro, R. Calero, S. Iglesias, and M. López, "An internet of things-based model for smart water management," in 2014 28th International Conference on Advanced Information Networking and Applications Workshops, 2014, pp. 821- 826.

[5] A. Oviedo Muñoz, "Desarrollo de un prototipo para recopilación y monitoreo remoto de datos hídricos de los tanques, basado en dispositivos IoT, en la ASADA paso ancho y boquerón," Specialization Practice Report to qualify for the title of Industrial Maintenance Engineer, with the academic degree of Licentiate, Tecnológico de Costa Rica, Escuela de Ingeniería Electromecánica, March 2024.

[6] S. Solórzano Alfaro, "Sistema de control y monitoreo hídrico, basado en LoRaWAN $ ^{\mathrm{TM}} $ , para el acueducto principal de la asociación administradora del acueducto rural de playa sámara de nicoya," Specialization Practice Report to qualify for the title of Industrial Maintenance Engineer, with the academic degree of Licentiate, Tecnológico de Costa Rica, Escuela de Ingeniería Electromecánica, June 2021.

[7] J.-L. Voirin, Model-Based System and Architecture Engineering with the Arcadia Method. ISTE Press - Elsevier, 2018.

[8] C. Z. Zulkifli, S. Garfan, M. Talal, A. H. Alamoodi, A. Alamleh, I. Y. Y. Ahmaro, S. Sulaiman, A. B. Ibrahim, B. B. Zaidan, A. R. Ismail, O. S. Albahri, A. S. Albahri, C. F. Soon, N. H. Harun, and H. H. Chiang, "Iotbased water monitoring systems: A systematic review," Water, vol. 14, no. 22, 2022.

[9] A. Maroli, V. Narwane, R. Raut et al., "Framework for the implementation of an internet of things (IoT)-based water distribution and management system," Clean Technologies and Environmental Policy, vol. 23, pp. 271-283, 2021.

[10] N. K. Velayudhan, P. Pradeep, S. N. Rao, A. R. Devidas, and M. V. Ramesh, "Iot-enabled water distribution systems—a comparative technological review," IEEE Access, vol. 10, pp. 101042-101070, 2022.

[11] R. Goncalves, J. J. M. Soares, and R. M. F. Lima, "An iot-based framework for smart water supply systems management," Future Internet, vol. 12, no. 7, 2020.

[12] X. Wu, "Application of intelligent technology in integrated urbanrural water supply project," in 2022 8th International Conference on Hydraulic and Civil Engineering: Deep Space Intelligent Development and Utilization Forum (ICHCE), 2022, pp. 1211-1218.

[13] X. Tao, D. Conzon, E. Ferrera, S. Li, J. Götz, L. Maillet-Contoz, E. Michel, M. Diaz-Nava, A. Baouya, and S. Chehida, "Model based methodology and framework for design and management of next-gen iot systems," in SAM-IoT, 01 2020.

[14] I. Sarkar, S. Karforma, R. Bose, and S. Roy, "Ubiquitous on-demand water reservoir tracking system for smart village," Universal Journal of Agricultural Research, vol. 10, no. 3, pp. 193-203, 2022.

[15] P. Roques, Systems Architecture Modeling with the Arcadia Method: A Practical Guide to Capella. ISTE Press - Elsevier, 2018.

[16] Thales, "Arcadia - capella mbse tool," https://mbse-capella.org/arcadia.html, accessed 2024-07-10.

[17] Gemini Team, Google, "Gemini 2.5: Pushing the frontier with advanced reasoning, multimodality, long context, and next generation agentic capabilities," https://storage.googleapis.com/deepmind-media/gemini/gemini_v2_5_report.pdf, 2025.

[18] Sentence-Transformers, "all-minilm-l6-v2," https://huggingface.co/sentence-transformers/all-MiniLM-L6-v2, 2022.

[19] M. Grootendorst, "Bertopic: Neural topic modeling with a class-based tf-idf procedure," 2022. [Online]. Available: https://arxiv.org/abs/2203.05794

[20] M. Abdelhafidh, M. Fourati, L. C. Fourati, and A. Abidi, "Remote water pipeline monitoring system iot-based architecture for new industrial era 4.0," in 2017 IEEE/ACS 14th International Conference on Computer Systems and Applications (AICCSA), 2017, pp. 1184-1191.