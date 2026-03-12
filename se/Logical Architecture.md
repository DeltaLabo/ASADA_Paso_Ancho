# Logical Architecture

The Logical Architecture decomposes the system into **Logical Components (LCs)** and their **Logical Functions (LFs)**, and defines the **Component Exchanges (CEs)** through which LCs communicate. It is available as two complementary views.

## System Boundary

The Logical Architecture is contained within the **System** boundary. All Logical Components (LCs) are internal to the System. External Actors (LAs) interact with the System through Component Exchanges at the boundary.

## Views

### 1. Detailed View — `logical_architecture.mmd`

Shows the System boundary containing all Logical Components, with their internal Logical Functions and data exchanges between individual functions. Use this view to understand:

- Which functions each LC is responsible for
- The specific data items exchanged between functions
- Intra-component flows (within the same LC)
- Constraints on individual functions (marked with `{c}`)
- What is inside vs. outside the System

### 2. Component Exchange View — `logical_architecture_ce.mmd`

A simplified view that shows the System boundary, hides Logical Functions, and displays only the Logical Components and the Component Exchanges between them. Use this view to understand:

- The overall LC-to-LC communication topology
- The communication pattern assigned to each exchange
- Which actors are internal (LCs within System) vs. external (LAs outside System)

## Component Exchange Patterns

CEs are communication mechanisms between LCs. CEs marked with *(crosses System boundary)* connect internal LCs to external Actors.

| Pattern | Description |
|---|---|
| **Publish-Subscribe** | One publisher distributes data to multiple subscribers asynchronously |
| **Message Queue** | Point-to-point asynchronous delivery for data persistence and forwarding |
| **Request-Reply** | Synchronous query or configuration exchange |
| **Push Notification** *(crosses System boundary)* | Asynchronous alert delivery to human actors |
| **Client-Server** *(crosses System boundary)* | Interactive presentation of data to human actors |
| **Data Export** *(crosses System boundary)* | Batch or on-demand data sharing with external entities |
| **Modbus** *(constrained, crosses System boundary)* | Hardware protocol for the Octave water meter sensor |
| **4-20mA Analog Signal** *(constrained, crosses System boundary)* | Hardware signal for the submersible water level sensor |

## External Actors

| Actor | Description |
|---|---|
| 👤 ASADA Paso Ancho Employee | Receives notifications and dashboard data; configures alert criteria |
| 📦 External data aggregators | Consume exported aqueduct data |
| 📦 Sensors | Octave Water Meter and Submersible Water Level Sensor — fixed hardware outside the system boundary |
