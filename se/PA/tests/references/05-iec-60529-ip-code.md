# IEC 60529

## Citation

International Electrotechnical Commission (IEC), **IEC 60529 — Degrees of protection provided by enclosures (IP Code)**.

## Why it is relevant here

`Field Node PA.d2` explicitly models an **IP67 Enclosure**. That is a testable claim.

IEC 60529 is relevant because it provides the standard interpretation and test basis for ingress-protection claims against solids and water.

## How this source is used in the test plan

This source supports the feared-event scenario:

- water or dust ingress through the field enclosure or cable entries.

It also supports the requirement that the enclosure be tested in the **assembled state**, including:

- cable glands,
- antenna feedthrough,
- sensor cabling,
- power cabling,
- any seals disturbed during assembly.

## Practical takeaways applied to `Field Node PA.d2`

A nominal IP67 enclosure is not enough by itself; the claim must hold for the project's assembled configuration.

Therefore acceptance needs:

- a fully assembled representative unit,
- pre-test functional baseline,
- ingress test,
- post-test functional baseline,
- inspection for water / particulate entry,
- evidence tied to the exact enclosure build and seal arrangement.

## Notes

IEC 60529 covers ingress. It does not replace environmental cycling or EMC testing.
