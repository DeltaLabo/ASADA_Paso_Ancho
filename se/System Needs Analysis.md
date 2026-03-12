# System Needs Analysis

## System Architecture

The following diagram shows the complete system architecture, including all system functions, actors, sensors, and functional exchanges.

![System Architecture](system_architecture.mmd)

## Capabilities

### 1. Provide supply and demand data

The system collects real-time measurements from the aqueduct sensors, stores them, and presents them to operators for consultation.

![Provide S/D Data](fc_provide_sd_data.mmd)

### 2. Provide water loss data

The system collects measurements, quantifies water loss from them, stores results, and presents them to operators for consultation.

![Provide Water Loss Data](fc_provide_wl_data.mmd)

### 3. Alert about insufficient supply risk

The system detects insufficient supply conditions through two paths: a reactive path that notifies operators of current events, and a predictive path that forecasts high-probability scenarios. Both trigger the operator to define water distribution rules.

![Alert Insufficient Supply](fc_alert_insufficient_supply.mmd)

### 4. Alert about water loss risk

The system detects water loss through two paths: a reactive path that notifies operators of significant events (tank overflow, pipe burst), and a predictive path that forecasts high-probability water loss scenarios. Both trigger the operator to implement mitigation strategies.

![Alert Water Loss](fc_alert_water_loss.mmd)

### 5. Share data with external entities

The system makes stored measurements and events accessible to external data aggregators.

![Share External Data](fc_share_external_data.mmd)

### 6. Allow users to configure alerts

Operators consult presented data, analyze it, and configure alert criteria for both supply-side and water-loss-side detection and notification functions. This closes the feedback loop between the system's alerts and the operator's judgment.

![Configure Alerts](fc_configure_alerts.mmd)
