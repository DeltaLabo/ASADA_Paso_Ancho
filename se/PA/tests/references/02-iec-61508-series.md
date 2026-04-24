# IEC 61508 series

## Citation

International Electrotechnical Commission (IEC), **IEC 61508 — Functional safety of electrical / electronic / programmable electronic safety-related systems** (multi-part standard family).

## Why it is relevant here

IEC 61508 is relevant even when the project is not claiming a full SIL-certified product, because it provides disciplined guidance for:

- validation of hardware / software behavior,
- treatment of systematic faults,
- environmental and operational constraints,
- and the idea of **proven in use** for a specific configuration.

The user concern about "proven in use" matches IEC 61508 language: acceptance depends on evidence from the actual configuration and its operational experience, not on generic assumptions.

## How this source is used in the test plan

This source is used to justify tests that demonstrate:

- the exact field-node configuration behaves consistently,
- dangerous systematic behavior is not being introduced by integration choices,
- disturbances are detected and handled predictably,
- long-duration operation is evidence-bearing only when the tested configuration is frozen and traceable.

## Practical takeaways applied to `Field Node PA.d2`

- Evidence must be tied to the exact stack: XIAO ESP32-C3, SIM7600G-H, INA219, Waveshare power path, RS485 interface, analog divider, battery pack, antenna, enclosure, firmware revision, and wiring configuration.
- "Proven in use" cannot be claimed from a simulator alone; it requires accumulated operational evidence from the exact bench / pilot configuration.
- Environmental and electrical robustness are part of acceptance, because field faults often appear as systematic integration faults only under stress.
- Repeated successful operation and disciplined anomaly logging matter as much as single-pass functional demonstrations.

## Specific test implications

IEC 61508 supports planning for:

- cold start and restart recovery,
- low-voltage / brownout response,
- sensor-fault detection,
- communications-loss recovery,
- endurance / soak campaigns,
- controlled review of anomalies and corrective actions.

## Notes

Use this source together with the statistical note in `07-reliability-demonstration-statistics.md`; IEC 61508 explains why operational evidence matters, while the statistics note explains how much evidence is needed to support a claim.
