# Test plan for `se/PA/Field Node PA.d2`

## 1. Scope

This plan defines a **reference corpus of tests** for the field-node physical architecture modeled in:

- `se/PA/Field Node PA.d2`

The plan also uses related PA views to preserve end-to-end consistency with the modeled platform behavior.

This plan does **not** modify any Capella / D2 diagrams.

## 2. Views reviewed

The following views were reviewed before planning:

- `se/PA/Field Node PA.d2`
- `se/PA/Server Node PA.d2`
- `se/PA/FV1_simulated_telemetry_backbone.d2`
- `se/PA/FV2_bench_field_node.d2`
- `se/PA/scenario_ingest_validate_node_data.d2`
- `se/PA/scenario_monitor_sensor_health.d2`
- `se/PA/scenario_dashboard_filter_and_thresholds.d2`
- `se/PA/scenario_notify_events_and_risks.d2`
- `se/PA/scenario_authenticate_user.d2`
- `se/PA/scenario_account_provisioning_and_password_validation.d2`
- `se/PA/scenario_backup_time_series_db.d2`
- `se/PA/scenario_detect_server_tamper.d2`
- `se/PA/functional_versions_ivv_plan.md`
- `se/PA/BOM.md`

## 3. Architecture observations that drive the tests

The modeled field node is a **single-chain remote OT architecture**:

- one controller (`Seeed XIAO ESP32-C3`),
- one LTE path (`SIM7600G-H` + antenna),
- one RS485 sensing path,
- one analog sensing path,
- one main power chain (solar input, charger, battery, monitor, 5 V distribution),
- one enclosure claim (`IP67 Enclosure`).

No redundant controller, modem, or sensor path is modeled.

Therefore the test strategy is centered on:

1. **nominal functional correctness**,
2. **fault detection and health reporting**,
3. **autonomous recovery instead of failover**,
4. **environmental / EMC robustness of the assembled unit**,
5. **configuration-specific operational evidence** for future proven-in-use arguments.

## 4. Configuration rule

Two test configurations are allowed, but they support different claims:

### 4.1 Bench configuration

Use `se/PA/FV2_bench_field_node.d2` for early bench work with:

- bench DC supply,
- Modbus RTU flow simulator,
- analog depth emulator.

This is acceptable for interface, recovery, and many robustness tests.

### 4.2 Acceptance / proven-in-use configuration

For any claim about the final field node, freeze and record the exact configuration from `Field Node PA.d2`, including:

- real sensor set,
- exact wiring and connector arrangement,
- exact battery pack,
- exact modem / antenna,
- exact enclosure assembly,
- firmware revision,
- server ingress revision,
- SIM / APN / operator settings.

Do **not** use simulator-only evidence to support a proven-in-use claim.

## 5. Parameters that must be baselined before execution

The diagrams define structure, not all numeric limits. Before executing the tests below, freeze these parameters:

- `T_report` — nominal reporting period
- `T_fresh` — freshness timeout used by server validation / health logic
- accepted flow and level ranges
- plausibility / rate-of-change limits
- low-battery and brownout thresholds
- acceptable upload latency budget
- deployment temperature / humidity envelope
- target EMC severity profile
- target ingress / immersion severity profile

## 6. Statistical rules used in this plan

Source note: `se/PA/tests/references/07-reliability-demonstration-statistics.md`

### 6.1 Repeated scenario trials

For zero-failure repeated trials:

- **29/29 passes** → demonstrates about **90% success with 95% confidence**
- **59/59 passes** → demonstrates about **95% success with 95% confidence**

Default usage in this plan:

- critical recovery scenarios: **29 successful repetitions minimum**
- main nominal-operating scenario: **59 successful repetitions preferred**

### 6.2 Endurance / soak exposure

For zero-failure endurance campaigns at 95% confidence:

- **500 node-hours** → lower MTBF bound about **167 h**
- **1000 node-hours** → lower MTBF bound about **334 h**

Default usage in this plan:

- **500 node-hours minimum screening target**
- **1000 node-hours preferred first proven-in-use target**

### 6.3 Qualification-style environmental tests

For ingress, temperature, vibration, and EMC qualification:

- **1 fully assembled representative unit minimum**
- **3 units preferred** if budget allows, to reduce overconfidence from a single sample
- after each major exposure, run post-stress functional checks based on scenarios `FN-S01` and `FN-S03`

## 7. Scenario-based test plan

| ID | Scenario type | Scenario | Model references | Planned method | Statistical basis | Main acceptance criteria | Primary references |
|---|---|---|---|---|---|---|---|
| `FN-S01` | Expected use case | **Nominal acquisition and upload**: read RS485 flow + analog level, assemble telemetry, upload to server, store accepted data | `Field Node PA.d2`, `Server Node PA.d2`, `scenario_ingest_validate_node_data.d2`, `FV2_bench_field_node.d2` | Bench or final node with representative low / mid / high sensor stimuli, nominal battery state, nominal LTE path | **59 zero-failure upload cycles preferred**; 29 minimum for early acceptance | Every batch is syntactically valid, accepted by ingress, stored once, and reported with healthy status; no unexplained reset; no silent value corruption | NIST SP 800-82, IEC 61508, IEC 62443, statistics note |
| `FN-S02` | Expected use case | **Cold start and restart recovery** after installation or power interruption | `Field Node PA.d2`, `FV2_bench_field_node.d2`, `scenario_monitor_sensor_health.d2` | Repeated cold boots and power-cycle tests at nominal and low-but-valid supply conditions | **29 zero-failure restart cycles** | Node boots without manual intervention, initializes interfaces, and produces first accepted upload within `<= 3 x T_report`; health status becomes valid; no persistent fault latch after power restoration | IEC 61508, NIST SP 800-82, statistics note |
| `FN-S03` | Feared event | **Sensor interface fault**: RS485 disconnect / timeout and analog open, short, or out-of-range input | `Field Node PA.d2`, `scenario_monitor_sensor_health.d2`, `FV2_bench_field_node.d2` | Fault injection on each sensing path, followed by restoration | **29 successful detections per interface / fault family** where practical | Fault is detected within `<= 2 x T_report`; health state transitions to degraded or failed; no continued publication of apparently healthy but invalid data; normal healthy state returns after restoration | IEC 61508, NIST SP 800-82, statistics note |
| `FN-S04` | Feared event | **Stale, implausible, malformed, or unauthorized telemetry** | `scenario_ingest_validate_node_data.d2`, `Server Node PA.d2`, `FV1_simulated_telemetry_backbone.d2`, `FV2_bench_field_node.d2` | Use replay / fault-injection tooling plus bench node where needed to send stale timestamps, frozen values, missing fields, range violations, and invalid device credentials | **29 successful rejections per critical fault class**, or 59 stratified injections total | Invalid or unauthorized uploads are rejected or explicitly marked degraded according to the modeled rule; no malformed payload is silently stored as valid data | IEC 62443, NIST SP 800-82, IEC 61508, statistics note |
| `FN-S05` | Feared event | **LTE / WAN outage and autonomous recovery** | `Field Node PA.d2`, `Server Node PA.d2`, `scenario_monitor_sensor_health.d2` | Remove or attenuate WAN connectivity for short, medium, and prolonged outages; then restore service | **29 successful loss / recovery cycles** distributed across outage durations | Link degradation becomes visible in health status within `<= 2 x T_report`; after WAN restoration the node resumes accepted uploads within `<= 3 x T_report` without manual reboot; any non-delivery during outage is recorded as unavailable service, not hidden success | NIST SP 800-82, IEC 61508, IEC 62443, statistics note |
| `FN-S06` | Feared event | **Low battery / brownout during acquisition and modem transmission** | `Field Node PA.d2`, `scenario_monitor_sensor_health.d2`, `FV2_bench_field_node.d2` | Use programmable supply or battery emulator to sweep low-voltage conditions, especially during LTE transmit peaks | **29 successful low-voltage excursions** across representative battery states | Battery / power degradation is correctly reported; node does not enter a corrupt state; after voltage recovery it returns to valid operation without reflash or manual repair; no silent data corruption is introduced | IEC 61508, NIST SP 800-82, statistics note |
| `FN-S07` | Expected use case / evidence campaign | **Long-duration unattended mission-profile run** to build configuration-specific operational history | `Field Node PA.d2`, `scenario_ingest_validate_node_data.d2`, `scenario_monitor_sensor_health.d2`, `BOM.md` | Run the exact frozen configuration continuously with representative sensor profiles and realistic daily power / WAN disturbances | **1000 node-hours preferred**, **500 node-hours minimum**; report failures and node-hours honestly | Maintain valid acquisition / upload behavior for the campaign; zero unexplained critical lockup is the preferred target; log every anomaly, reset, gap `> 2 x T_report`, and corrective action; report resulting lower MTBF bound from actual exposure | IEC 61508, NIST SP 800-82, statistics note |
| `FN-S08` | Feared event | **Temperature and humidity exposure** during operation and recovery | `Field Node PA.d2`, `BOM.md` | Apply IEC 60068 cold / heat / damp-heat profiles selected from deployment envelope and vendor ratings; use assembled node | **Qualification test** on 1 representative unit minimum, 3 preferred; after each major exposure run **29 nominal uploads** and **10 sensor-fault checks** | No permanent damage, no unacceptable drift beyond frozen calibration tolerance, no loss of upload capability after recovery, and no latent intermittent fault introduced by exposure | IEC 60068, IEC 61508 |
| `FN-S09` | Feared event | **Water / dust ingress through the assembled enclosure** | `Field Node PA.d2`, `BOM.md` | IEC 60529 ingress test on fully assembled node with actual cable entries, antenna feedthrough, and seals | **Qualification test** on 1 representative assembled unit minimum | No ingress that compromises operation or safety; post-test node still passes `FN-S01` nominal checks and `FN-S03` sensor-fault checks; enclosure claim is tied to the exact assembly tested, not just the bare box | IEC 60529, IEC 61508 |
| `FN-S10` | Feared event | **Electrical disturbance / EMC upset** on DC, RS485, and analog interfaces | `Field Node PA.d2`, `FV2_bench_field_node.d2` | Apply applicable IEC 61000-4 immunity methods and severities selected for the deployment context | **Qualification test** per selected standard method; after each severity point run **10 nominal uploads** and recovery checks | No permanent damage; no silent corruption of stored measurements; any upset is self-recovering or clearly reported; the node returns to normal accepted uploads without manual intervention | IEC 61000-4, IEC 61508 |
| `FN-S11` | Feared event | **Vibration / handling loosens connectors, sensor wiring, or antenna path** | `Field Node PA.d2`, `BOM.md` | Apply transport / handling vibration and shock profile appropriate to installation and maintenance assumptions; inspect all modeled physical links before and after | **Qualification test** on 1 representative unit minimum, 3 preferred; post-stress run **29 nominal uploads** | No connector loosening, no intermittent RS485 / analog / modem behavior, no antenna-path degradation, and no broken enclosure seal after handling profile | IEC 60068, IEC 60529 |

## 8. Execution order recommendation

1. **Bench bring-up** using `FV2_bench_field_node.d2`
   - `FN-S01`, `FN-S02`, `FN-S03`, `FN-S05`, `FN-S06`
2. **End-to-end validation** with server ingress
   - `FN-S04`
3. **Robustness qualification** on assembled hardware
   - `FN-S08`, `FN-S09`, `FN-S10`, `FN-S11`
4. **Operational evidence accumulation**
   - `FN-S07`

## 9. Evidence to collect for every test

For each execution record, capture at least:

- exact model reference(s)
- hardware serial numbers and BOM revision
- firmware build hash / commit
- server / ingress software revision
- SIM / operator / APN configuration where relevant
- wiring photos and assembly photos
- environmental profile or disturbance profile applied
- raw stimulus files or emulator settings
- node serial logs
- server logs and stored data extracts
- pass / fail decision with rationale
- anomalies, workarounds, and deviations from the frozen configuration

## 10. Exit view

The field-node architecture should only be described as robust enough for deployment when there is evidence for all of the following:

- nominal end-to-end operation is repeatable,
- sensor and communications faults are detected rather than hidden,
- low-power behavior is controlled,
- the assembled enclosure and interfaces survive relevant environmental stress,
- and a meaningful body of configuration-specific operating hours has been accumulated.

## 11. Reference corpus

See:

- `se/PA/tests/references/README.md`
- `se/PA/tests/references/00-model-and-configuration-sources.md`
- `se/PA/tests/references/01-nist-sp-800-82r3.md`
- `se/PA/tests/references/02-iec-61508-series.md`
- `se/PA/tests/references/03-iec-62443-series.md`
- `se/PA/tests/references/04-iec-60068-series.md`
- `se/PA/tests/references/05-iec-60529-ip-code.md`
- `se/PA/tests/references/06-iec-61000-4-series.md`
- `se/PA/tests/references/07-reliability-demonstration-statistics.md`
