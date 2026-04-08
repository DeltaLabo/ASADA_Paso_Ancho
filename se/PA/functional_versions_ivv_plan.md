# Functional Versions and IVV Application for `se/PA`

## Planning basis

- Current date: **2026-03-26**.
- Procured items with ~1 month lead time:
  - Waveshare power components
  - Seeed Studio water depth meter
- Assumed receipt date: **2026-04-26**.
- **Server development can start immediately on 2026-03-26**.
- **Field-node hardware integration starts on 2026-04-27**, after the procured parts arrive.
- Functional versions are planned as **2-week intermediate deliverables**.
- The authoritative final PA baselines remain:
  - `se/PA/Field Node PA.dot`
  - `se/PA/Server Node PA.dot`
- Existing modeled verification scenarios already available for reuse:
  - `se/PA/scenario_ingest_validate_node_data.dot`
  - `se/PA/scenario_monitor_sensor_health.dot`
  - `se/PA/scenario_dashboard_filter_and_thresholds.dot`
  - `se/PA/scenario_notify_events_and_risks.dot`
  - `se/PA/scenario_authenticate_user.dot`
  - `se/PA/scenario_account_provisioning_and_password_validation.dot`
  - `se/PA/scenario_backup_time_series_db.dot`

## Functional version roadmap

| Version | Dates | Purpose | Allowed substitutes | Exit focus |
|---|---|---|---|---|
| Logistics | 2026-03-26 to 2026-04-26 | Order and receive long-lead field-node hardware | n/a | Field-node hardware available for integration |
| FV1 | 2026-03-26 to 2026-04-08 | Prove server ingest/storage path with simulated node data | Software telemetry simulator instead of field node and sensors | Valid data is ingested, invalid data is rejected, stored data is visible |
| Parallel server prep | 2026-04-09 to 2026-04-26 | Stabilize the server baseline while waiting for field-node parts | Bench and replay tools only | Deployment, test automation, and bench preparation are ready for hardware arrival |
| FV2 | 2026-04-27 to 2026-05-10 | Prove bench field node with real controller, modem, and power telemetry | Modbus flow simulator, analog depth emulator, bench DC supply instead of outdoor solar conditions | Real XIAO-based node uploads data and health telemetry end-to-end |
| FV3 | 2026-05-11 to 2026-05-24 | Prove threshold management, dashboard operations, and notifications | Replayed telemetry may be used to force thresholds and fault cases | Threshold changes affect detection/notification behavior |
| FV4 | 2026-05-25 to 2026-06-07 | Prove access control, account administration, and backup/restore path | Bench node or replayed telemetry may remain in place | Auth, provisioning, password handling, and backups are operational |
| FV5 | 2026-06-08 to 2026-06-21 | Full integrated baseline with final physical interfaces | No dummy sensors in the claimed configuration | Final integrated system baseline ready |

**Projected full system integration completion:** **2026-06-21**.

## Explicitly modeled functional versions

Two reduced PA views are provided for the highest-risk early increments:

1. `se/PA/FV1_simulated_telemetry_backbone.dot`
2. `se/PA/FV2_bench_field_node.dot`

These do not replace the final PA; they define the claimed subset for each intermediate deliverable.

## Applying the IVV strategy by version

The test sets below follow the IADT logic in `~/CanSatWorkshop/PM&SE/IVV.md`:

- **Inspection** for physical components and physical links
- **Analysis** for component exchanges and functional allocation
- **Demonstration / Testing** for scenarios and constraints
- **Reports by reference**: each execution record should reference the model element(s), baseline, as-tested configuration, evidence, pass/fail rationale, and deviations

---

## FV1 — Simulated telemetry backbone

**Dates:** 2026-03-26 to 2026-04-08  
**Modeled subset:** `se/PA/FV1_simulated_telemetry_backbone.dot`

**Scope claimed in this version**
- DigitalOcean host baseline available
- Traefik reverse proxy available
- FastAPI `Node Ingestion` available
- InfluxDB `Long-term Storage` available
- Grafana `Dashboard` available for visibility checks
- Telemetry source is a **software simulator**, not the final field node

**Associated tests**

| ID | IVV method | Model reference | As-tested configuration | Pass condition |
|---|---|---|---|---|
| FV1-I1 | Inspection | `FV1_simulated_telemetry_backbone.dot` | Droplet + Traefik + FastAPI + InfluxDB + Grafana + simulator | All modeled components are present in the deployed baseline |
| FV1-A1 | Analysis | `FV1_simulated_telemetry_backbone.dot` | HTTPS upload, routed ingest, storage write, dashboard query | All modeled exchanges are present and consistent with model intent |
| FV1-A2 | Analysis | `FV1_simulated_telemetry_backbone.dot` | FastAPI, InfluxDB, Grafana responsibilities | `Node Ingestion` validates/accepts-rejects payloads, `Long-term Storage` stores, `Dashboard` only queries/presents |
| FV1-T1 | Testing | `scenario_ingest_validate_node_data.dot` | Simulator sends valid, stale, missing-field, and out-of-range batches | Valid batches stored; invalid batches rejected with logged reason; no silent acceptance of malformed data |
| FV1-D1 | Demonstration | `scenario_ingest_validate_node_data.dot` + read-only subset of `scenario_dashboard_filter_and_thresholds.dot` | Grafana pointed at stored simulated data | Latest accepted data is visible within the agreed operational latency for the version |

**Recommended evidence**
- Compose/deployment manifest version
- API request/response logs
- Stored sample in InfluxDB
- Dashboard screenshot or exported panel image
- List of invalid payloads and rejection rationale

**Version-specific viewpoints to review**
- Fault hardening: malformed payloads, stale timestamps, missing values
- Statistical significance: repeat valid and invalid cases enough times to avoid one-off conclusions

---

## FV2 — Bench field node with real controller, modem, and power telemetry

**Dates:** 2026-04-27 to 2026-05-10  
**Modeled subset:** `se/PA/FV2_bench_field_node.dot`

**Scope claimed in this version**
- Real `Seeed XIAO ESP32-C3`
- Real RS485 interface, analog interface, LTE modem, battery monitor, charger/power path
- Dummy sensor substitutes allowed:
  - **Modbus/RS485 flow simulator** instead of the final flow-meter source
  - **Analog depth emulator** instead of the final Seeed depth sensor
  - **Bench DC input** instead of claiming final outdoor solar behavior

**Associated tests**

| ID | IVV method | Model reference | As-tested configuration | Pass condition |
|---|---|---|---|---|
| FV2-I1 | Inspection | `FV2_bench_field_node.dot` | XIAO, RS485, analog divider, LTE, INA219, charger, battery path, substitutes | All modeled physical components and physical links are present |
| FV2-A1 | Analysis | `FV2_bench_field_node.dot` | RS485, analog, UART, I2C, WAN exchanges | Implemented interfaces match model intent: RS485 for flow source, analog input for depth source, UART for modem, I2C for INA219 |
| FV2-A2 | Analysis | `Field Node PA.dot` subset + `FV2_bench_field_node.dot` | `Data Acquisition` LC allocation | Sensor readout, health packaging, and upload behavior remain in `Data Acquisition`; no foreign responsibilities are introduced |
| FV2-T1 | Testing | `scenario_ingest_validate_node_data.dot` | Real XIAO reads dummy sensors and uploads through LTE/server ingress | Server accepts correctly formed batches from the real node path |
| FV2-T2 | Testing | `scenario_monitor_sensor_health.dot` | Inject stale data, low-voltage condition, and modem/network loss | Health state transitions are observable as healthy / degraded / failed and are stored/presented correctly |

**Recommended evidence**
- Wiring photos
- Firmware revision and build hash
- Serial logs from XIAO and modem
- INA219 current/voltage captures
- Server-side ingest logs and stored health state samples

**Version-specific viewpoints to review**
- Fault hardening: sensor disconnect, modem drop, brownout/low-battery edge cases
- Statistical significance: repeated upload cycles, not just a single successful batch

---

## FV3 — Threshold management, dashboard operations, and notifications

**Dates:** 2026-05-11 to 2026-05-24

**Scope claimed in this version**
- Configuration API
- PostgreSQL configuration store
- Analytics worker
- Notification worker
- Dashboard views and threshold editing path
- Live bench node or replayed telemetry can be used as test means

**Associated tests**

| ID | IVV method | Model reference | As-tested configuration | Pass condition |
|---|---|---|---|---|
| FV3-I1 | Inspection | `Server Node PA.dot` subset | Config API, PostgreSQL, analytics worker, notifier, Grafana present | All modeled components for this subset are deployed |
| FV3-A1 | Analysis | `scenario_dashboard_filter_and_thresholds.dot` | Threshold update path | Threshold definitions flow through the modeled components without bypassing the intended path |
| FV3-T1 | Testing | `scenario_dashboard_filter_and_thresholds.dot` | User edits thresholds and queries filtered data | Edited thresholds persist and dashboard filtering behaves as expected |
| FV3-T2 | Testing | `scenario_notify_events_and_risks.dot` | Replayed or live data crosses configured thresholds | Detected events and predicted risks generate the correct notifications and audit records |

**Version-specific viewpoints to review**
- Fault hardening: duplicate events, noisy threshold crossings, notification retry behavior
- Statistical significance: multiple threshold crossings and reset cycles

---

## FV4 — Authentication, account administration, and backup/restore

**Dates:** 2026-05-25 to 2026-06-07

**Scope claimed in this version**
- Traefik TLS entry point
- Keycloak identity functions
- PostgreSQL identity/configuration store
- Grafana authenticated access path
- Restic backup path to DigitalOcean Spaces

**Associated tests**

| ID | IVV method | Model reference | As-tested configuration | Pass condition |
|---|---|---|---|---|
| FV4-I1 | Inspection | `Server Node PA.dot` subset | Traefik, Keycloak, PostgreSQL, Grafana, Restic, Spaces endpoint | All modeled components and links for auth/backup are present |
| FV4-A1 | Analysis | `scenario_account_provisioning_and_password_validation.dot` | Credential path and storage | Passwords are handled according to model intent: validation in Keycloak, salted-hash storage in PostgreSQL, no password storage in Grafana/FastAPI |
| FV4-T1 | Testing | `scenario_authenticate_user.dot` | Employee login through Traefik + Keycloak + Grafana | Authorized user receives an authenticated dashboard session |
| FV4-T2 | Testing | `scenario_account_provisioning_and_password_validation.dot` | Admin provisions user, user logs in | Provisioned account obeys password policy/RBAC/MFA constraints and authenticates successfully |
| FV4-T3 | Testing | `scenario_backup_time_series_db.dot` | Backup job writes encrypted artifact to Spaces and restore is attempted | Backup completes, artifact is encrypted, and restore verification succeeds |

**Version-specific viewpoints to review**
- Fault hardening: invalid password, lockout/MFA behavior, failed backup destination, restore of older artifact
- Statistical significance: repeat login/restore tests enough times to rule out a one-off result

---

## FV5 — Full integrated baseline

**Dates:** 2026-06-08 to 2026-06-21

**Scope claimed in this version**
- Final integrated subset from `Field Node PA.dot` and `Server Node PA.dot`
- Actual field sensing interfaces connected in the claimed configuration
- Enclosure, power chain, server services, dashboard, notifications, authentication, and backup all on one baseline

**Associated tests**

| ID | IVV method | Model reference | As-tested configuration | Pass condition |
|---|---|---|---|---|
| FV5-I1 | Inspection | `Field Node PA.dot` + `Server Node PA.dot` | Final integrated hardware/software baseline | All modeled physical components and physical links are present |
| FV5-A1 | Analysis | `Field Node PA.dot` + `Server Node PA.dot` | Full integrated exchange set | All modeled component exchanges are present and consistent with model intent |
| FV5-A2 | Analysis | Final PA + all reused scenarios | Final logical allocation baseline | Each logical component performs only its intended responsibilities |
| FV5-T1 | Testing | `scenario_ingest_validate_node_data.dot` | Final field node path | Final sensing chain ingests and stores accepted measurements correctly |
| FV5-T2 | Testing | `scenario_monitor_sensor_health.dot` | Final field node path with health fault injections where safe | Health telemetry and health-state derivation behave correctly on the final baseline |
| FV5-T3 | Testing | `scenario_notify_events_and_risks.dot` | Final end-to-end stack | Events/risks propagate to notifications and audit storage on the final baseline |
| FV5-T4 | Testing | `scenario_authenticate_user.dot` + `scenario_backup_time_series_db.dot` | Final operational baseline | Authorized access and operational backup both work on the same integrated baseline |
| FV5-T5 | New verification activity required by IVV strategy | To be modeled before execution | Endurance / autonomy / recovery campaign | Define and run a soak test for power autonomy, restart recovery, and communications recovery because these constraints are not fully covered by the existing scenarios |

## Reporting guidance for every version

Each version should end with a short controlled verification record that:

1. references the exact model elements used,
2. identifies the baseline/tag/commit under test,
3. identifies the as-tested hardware/software configuration,
4. stores the evidence links,
5. records pass/fail rationale,
6. records deviations from the modeled setup,
7. records anomalies, waivers, assumptions, and limits.

## Files generated for this plan

- `se/PA/functional_versions_ivv_plan.md`
- `se/PA/FV1_simulated_telemetry_backbone.dot`
- `se/PA/FV2_bench_field_node.dot`
- `se/PA/functional_versions_gantt.dot`
