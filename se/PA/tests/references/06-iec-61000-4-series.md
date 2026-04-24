# IEC 61000-4 series

## Citation

International Electrotechnical Commission (IEC), **IEC 61000-4 — Electromagnetic compatibility (EMC), testing and measurement techniques** (multi-part standard family), especially the immunity test methods commonly used for industrial equipment.

## Why it is relevant here

The field node contains long external conductors and exposed interfaces:

- DC input from the solar panel,
- battery and sense wiring,
- RS485 field cable,
- analog sensor cable,
- RF antenna path.

Those interfaces are common paths for electrical disturbances, especially in outdoor installations.

## How this source is used in the test plan

This source supports immunity testing for disturbances such as:

- electrostatic discharge,
- electrical fast transients / burst,
- surge,
- conducted RF,
- voltage dips / interruptions where applicable to the powered test setup.

## Practical takeaways applied to `Field Node PA.d2`

Acceptance is not simply "never glitches". For this class of remote node, the important questions are:

- does the node avoid permanent damage,
- are measurements protected from silent corruption,
- is any upset self-recovering,
- does the node return to normal upload behavior without manual intervention,
- is a degraded state visible when the disturbance has operational impact.

## Notes

Select the exact IEC 61000-4 methods and severity levels from the deployment environment, cable lengths, grounding concept, and vendor ratings. Always run pre- and post-disturbance functional scenarios after the EMC exposures.
