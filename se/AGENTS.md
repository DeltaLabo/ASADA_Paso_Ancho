# Mermaid Diagram Styling Guide for ARCADIA Translation

This document describes the visual conventions used in the Mermaid diagrams that translate ARCADIA architectural models.

## Overview

The diagrams follow a consistent styling pattern across all architecture levels:
- **System Analysis (SA)** - `system_architecture.mmd`
- **Organizational Architecture (OA)** - `organizational_architecture.mmd`
- **Logical Architecture (LA)** - `logical_architecture.mmd`
- **Physical Architecture (PA)** - `physical_architecture.mmd`

---

## Actors (External Entities)

### Primary Actors
| Element | Emoji | Mermaid Class | Visual Style |
|---------|-------|---------------|--------------|
| Rural Aqueduct (User/Operator) | 👤 | `actorContainerClass` | Fill: `#fff9e6` (cream), Stroke: `#d4a017` (golden), Dashed border |
| External Data Aggregators | 📦 | `externalClass` | Fill: `#e6ffe6` (light green), Stroke: `#009900` (green) |
| Water Quality Standards Compliance Evaluator | 🏛️ | `systemClass` | Fill: `#e6f3ff` (light blue), Stroke: `#0066cc` (blue) |
| Water Distribution System | 🏛️ | `systemClass` | Fill: `#e6f3ff`, Stroke: `#0066cc` |

### Actor Functions
| Element | Emoji Prefix | Mermaid Class | Visual Style |
|---------|--------------|---------------|--------------|
| Actor Functions | 🟩 | `actorFunctionClass` | Fill: `#f9e79f` (light yellow), Stroke: `#b7950b` (dark goldenrod), 2px width |

**Examples:**
- `🟩 Consult water quality data`
- `🟩 Implement water quality control strategy`

---

## System Under Design

### System Container
| Element | Emoji | Mermaid Class | Visual Style |
|---------|-------|---------------|--------------|
| System | ⚙️ | `systemClass` | Fill: `#e6f3ff` (light blue), Stroke: `#0066cc` (blue), 3px width |

### System Functions
| Element | Emoji Prefix | Mermaid Class | Visual Style |
|---------|--------------|---------------|--------------|
| System Functions | 🟩 | `systemFunctionClass` | Fill: `#90ee90` (light green), Stroke: `#228b22` (forest green), 2px width |

**Examples:**
- `🟩 Measure water quality`
- `🟩 Predict water supply and demand`

---

## Logical Architecture

### Logical Components
| Element | Emoji | Mermaid Class | Visual Style |
|---------|-------|---------------|--------------|
| Logical Components | Various* | `logicalComponentClass` | Fill: `#87ceeb` (sky blue), Stroke: `#0066cc` (blue), 3px width |

*Component-specific emojis:
- 📬 Notifier
- 📊 Dashboard
- 💾 Long-term storage
- ⚙️ Data Processing
- 🔍 Event detection
- 📡 Data Acquisition
- 📁 Measurement window
- 🎛️ Distribution controller
- 🔌 Sensors

### Logical Functions
| Element | Emoji Prefix | Mermaid Class | Visual Style |
|---------|--------------|---------------|--------------|
| Logical Functions | 🟩 | `logicalFunctionClass` | Fill: `#90ee90` (light green), Stroke: `#228b22` (forest green), 2px width |

**Examples:**
- `🟩 Send notification about event`
- `🟩 Present measurements, events, and forecasts`

---

## Physical Architecture

### Physical Components (COTS/Off-the-shelf)
| Element | Emoji | Mermaid Class | Visual Style |
|---------|-------|---------------|--------------|
| External Systems | Various* | `externalSystemClass` | Fill: `#fff9e6` (cream), Stroke: `#d4a017` (golden), 3px width |
| Hardware Nodes | Various | `hardwareNodeClass` | Fill: `#ffffcc` (light yellow), Stroke: `#b8b800` (olive), 2px width |
| Internal Subcomponents | 🟦 | `physicalComponentClass` | Fill: `#87ceeb` (sky blue), Stroke: `#0066cc` (blue), 2px width |

*Physical system emojis:
- 📊 Grafana
- 🔊 Octave Ultrasonic Sensor
- 🔌 Single-wire pressure sensor
- ☀️ Solar panel
- 📡 LTE Antenna
- 📦 Enclosure
- 💾 InfluxDB
- 📬 Notifier

### Physical Functions
| Element | Emoji Prefix | Mermaid Class | Visual Style |
|---------|--------------|---------------|--------------|
| Physical Functions | 🟩 | `physicalFunctionClass` | Fill: `#90ee90` (light green), Stroke: `#228b22` (forest green), 2px width |

### PCB Subcomponents (Nested)
| Component | Style |
|-----------|-------|
| Enclosure | Fill: `#f0f0f0` (gray), Stroke: `#666` |
| PCB | Fill: `#f5f5dc` (beige), Stroke: `#999` |
| XIAO ESP32-C3 | Fill: `#ffffcc` (light yellow), Stroke: `#b8b800` |

---

## Constraints

Constraints are documented within function labels using the `{c}` marker:

```mermaid
SF_AQ9["🟩 Measure water quality<br/><br/>{c} Real-time and remote<br/>{c} Metrics incl. pH, turbidity,<br/>fertilizer content..."]
```

**Convention:** `{c}` indicates a **constraint** on the function.

---

## Exchanges

### Functional Exchanges
| Element | Notation | Example |
|---------|----------|---------|
| Functional Exchange | 📨 + Label | `|"📨 Water quality measurement"|` |

**Arrow syntax:**
```mermaid
SourceFunction -->|"📨 Exchange Name"| TargetFunction
```

### Component Exchanges (Physical)
| Element | Notation | Example |
|---------|----------|---------|
| Physical Connection | 🔴 + Cable type | `|"🔴 TP Cable"|` |
| Signal Flow | 📡 + Signal type | `|"📡 Voltage signal"|` |
| Power Flow | ⚡ | `-.->|"⚡ Power"|` (dashed line) |

**Physical connection examples:**
```mermaid
OS_HW -->|"🔴 TP Cable"| Enclosure
PowerSystem -.->|"⚡ Power"| XIAO
```

---

## Complete Styling Reference

### Mermaid Class Definitions

```mermaid
%% Actor styling
classDef actorFunctionClass fill:#f9e79f,stroke:#b7950b,stroke-width:2px
classDef actorContainerClass fill:#fff9e6,stroke:#d4a017,stroke-width:2px,stroke-dasharray: 3 3

%% System styling
classDef systemFunctionClass fill:#90ee90,stroke:#228b22,stroke-width:2px
classDef systemClass fill:#e6f3ff,stroke:#0066cc,stroke-width:3px

%% Logical styling
classDef logicalFunctionClass fill:#90ee90,stroke:#228b22,stroke-width:2px
classDef logicalComponentClass fill:#87ceeb,stroke:#0066cc,stroke-width:3px

%% Physical styling
classDef physicalFunctionClass fill:#90ee90,stroke:#228b22,stroke-width:2px
classDef physicalComponentClass fill:#87ceeb,stroke:#0066cc,stroke-width:3px
classDef hardwareNodeClass fill:#ffffcc,stroke:#b8b800,stroke-width:2px
classDef externalSystemClass fill:#fff9e6,stroke:#d4a017,stroke-width:3px

%% External actors
classDef externalClass fill:#e6ffe6,stroke:#009900,stroke-width:3px
```

---

## Architecture Level Abbreviations

| Abbreviation | Meaning |
|--------------|---------|
| (SA) | System Analysis |
| (OA) / (OE) | Organizational Architecture / Operational Entity |
| (LA) / (LC) | Logical Architecture / Logical Component |
| (PA) | Physical Architecture |

---

## Visual Hierarchy Summary

```
Level 0: Actors (External)          - Cream/Yellow tones
Level 1: System Container           - Light Blue
Level 2: System Functions           - Light Green
Level 3: Logical Components         - Sky Blue
Level 4: Logical Functions          - Light Green
Level 5: Physical Systems (COTS)  - Cream/Yellow
Level 6: Physical Functions         - Light Green
Level 7: Hardware Nodes             - Light Yellow
Level 8: Internal Components      - Sky Blue
```

**Color Logic:**
- 🟨 **Yellow/Cream tones**: External actors and physical hardware (boundary elements)
- 🟦 **Blue tones**: Containers and structural components
- 🟩 **Green**: Functions at all levels (what the system does)
