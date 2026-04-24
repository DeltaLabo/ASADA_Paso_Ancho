# Reference corpus for `se/PA/tests`

This folder stores the source notes used to derive the test plan for `se/PA/Field Node PA.d2`.

These files are **bibliographic / applicability notes**, not copies of the standards. That matters because several IEC standards are paywalled; this corpus captures why they are relevant and how they are applied to the modeled field-node configuration.

## Files

- `00-model-and-configuration-sources.md` — internal project views reviewed and the exact modeled configuration used as the traceability baseline.
- `01-nist-sp-800-82r3.md` — OT topology, communications, reliability, and security guidance for remote OT assets.
- `02-iec-61508-series.md` — functional safety, validation, systematic-fault control, and proven-in-use reasoning.
- `03-iec-62443-series.md` — IACS security requirements relevant to authenticated and protected remote telemetry.
- `04-iec-60068-series.md` — environmental robustness tests for temperature, humidity, vibration, and shock.
- `05-iec-60529-ip-code.md` — ingress-protection verification for the IP67 enclosure claim.
- `06-iec-61000-4-series.md` — EMC / electrical immunity tests for field wiring and power interfaces.
- `07-reliability-demonstration-statistics.md` — statistical rules used in the plan for repeated scenario trials and endurance campaigns.

## How to use this corpus

1. Freeze the **as-tested configuration** first.
2. Select the relevant scenario in `../READNE.md`.
3. Use the matching source note(s) here to justify the test objective, severity, and pass criteria.
4. Record evidence against the exact model element, BOM item, firmware build, and environmental setup used during execution.
