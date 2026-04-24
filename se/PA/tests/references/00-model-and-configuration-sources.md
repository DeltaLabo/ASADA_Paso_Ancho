# Internal model and configuration sources

## Primary scope source

- `se/PA/Field Node PA.d2`
  - Physical architecture baseline for the field node.
  - Main elements under test: solar panel, enclosure, controller PCB, power subsystem, XIAO compute path, RS485 interface, analog interface, LTE modem, antenna, and all modeled physical links.

## Related PA views reviewed

These views were read to understand how the field node behaves inside the wider platform and to identify already-modeled test scenarios.

- `se/PA/Server Node PA.d2`
  - End-to-end landing point for field-node uploads.
- `se/PA/FV1_simulated_telemetry_backbone.d2`
  - Early server-only verification subset using a software node simulator.
- `se/PA/FV2_bench_field_node.d2`
  - Bench subset with the real XIAO-based node and dummy sensors.
- `se/PA/scenario_ingest_validate_node_data.d2`
  - Scenario for validation of uploaded telemetry, ranges, timestamps, and device authentication.
- `se/PA/scenario_monitor_sensor_health.d2`
  - Scenario for freshness, plausibility, battery, modem, and health-state derivation.
- `se/PA/scenario_dashboard_filter_and_thresholds.d2`
  - Downstream dashboard and configuration behavior reviewed for system context.
- `se/PA/scenario_notify_events_and_risks.d2`
  - Downstream analytics / notification behavior reviewed for system context.
- `se/PA/scenario_authenticate_user.d2`
  - Security context reviewed for system context.
- `se/PA/scenario_account_provisioning_and_password_validation.d2`
  - Security and credential-storage context reviewed for system context.
- `se/PA/scenario_backup_time_series_db.d2`
  - Operational backup context reviewed for system context.
- `se/PA/scenario_detect_server_tamper.d2`
  - Server-side tamper detection, audit evidence, and administrator notification context reviewed for system context.
- `se/PA/functional_versions_ivv_plan.md`
  - Existing IVV roadmap and versioning assumptions.
- `se/PA/BOM.md`
  - Procurement / product reference list for the exact hardware family.

## Configuration traceability baseline

For the purpose of this test corpus, the field-node configuration is the exact combination modeled in `Field Node PA.d2`, notably:

- `Waveshare Solar Panel (18V 10W)`
- `IP67 Enclosure`
- `Controller PCB`
- `Waveshare Solar Power Manager (D)`
- `18650 Battery Holder + 3P1S Li-ion Pack`
- `INA219 Battery Monitor`
- `Molex MicroFit 43045 4-pin Power Header`
- `Seeed Studio Expansion Board Base for XIAO`
- `Seeed XIAO ESP32-C3`
- `Seeed Grove RS485`
- `Analog Divider`
- `Waveshare SIM7600G-H 4G Module`
- `Waveshare Outdoor Antenna`
- `Octave Water Meter`
- `Submersible Water Level Sensor`

## Important modeling observation for test planning

The modeled field node is a **single-chain architecture**:

- one controller,
- one LTE path,
- one RS485 sensing path,
- one analog sensing path,
- one battery monitor,
- one main power chain.

No redundant controller, modem, or sensing path is modeled.

Therefore the test corpus emphasizes:

1. correct nominal behavior,
2. fault detection and health reporting,
3. autonomous recovery after disturbances,
4. robustness of the exact physical interfaces,
5. accumulation of configuration-specific operational evidence for proven-in-use claims.
