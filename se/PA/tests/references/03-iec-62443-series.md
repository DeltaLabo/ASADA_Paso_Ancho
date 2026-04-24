# IEC 62443 series

## Citation

International Electrotechnical Commission (IEC), **IEC 62443 — Security for industrial automation and control systems** (multi-part standard family), especially system and component security requirements.

## Why it is relevant here

The field node is an IACS edge component that exchanges telemetry over a public or semi-public cellular network. Even though the field-node PA is mainly a physical view, the related scenario views already model:

- authenticated upload,
- TLS-protected transport,
- explicit server-side validation,
- and health-state reporting.

IEC 62443 is relevant because it turns these topics into structured security expectations for systems and components.

## How this source is used in the test plan

This source supports tests for:

- authenticated device-to-server communications,
- rejection of malformed or unauthorized uploads,
- secure recovery after communications disturbances,
- ensuring security controls do not create unacceptable operational fragility.

## Practical takeaways applied to `Field Node PA.d2`

- The LTE/WAN path is a critical attack and failure surface, so transport protection and device identity are part of field-node acceptance.
- Security testing must be end-to-end with the server ingress path, because the node alone cannot prove the secure upload behavior.
- A good result is not only "blocked attack"; it is also "no silent operational breakage" under realistic remote-site conditions.

## Notes

Use this source mainly for the upload-path scenarios linked to:

- `se/PA/scenario_ingest_validate_node_data.d2`
- `se/PA/scenario_monitor_sensor_health.d2`

Environmental, ingress, and electrical-robustness tests should instead trace primarily to IEC 60068, IEC 60529, and IEC 61000.
