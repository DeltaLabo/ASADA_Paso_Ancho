# Reliability-demonstration statistics used in the plan

## Citation basis

This note applies standard zero-failure reliability-demonstration logic commonly used in reliability engineering and aligned with sources such as:

- **IEC 61124 — Reliability testing; compliance tests for constant failure rate / failure intensity**
- classical one-sided **binomial** and **exponential / Poisson** confidence-bound methods

## Why it is relevant here

The user explicitly asked for test planning that takes **statistics** into account.

For this project, most scenario tests are binary at the campaign level:

- either the node completed the scenario correctly,
- or it did not.

That makes zero-failure binomial planning a practical way to size repeated scenario trials.

Long-duration soak / endurance campaigns are better expressed in accumulated exposure time, which makes zero-failure exponential planning appropriate.

## Rule 1 — repeated scenario trials (binomial, zero failures)

To demonstrate a true per-trial success probability of at least `R` with confidence `C`, using `n` independent successful trials and **zero failures**:

`n >= ln(1 - C) / ln(R)`

Useful values:

| Target reliability `R` | Confidence `C` | Zero-failure trials `n` |
|---|---:|---:|
| 0.90 | 0.95 | 29 |
| 0.95 | 0.95 | 59 |
| 0.99 | 0.95 | 299 |

Interpretation used in the plan:

- **29/29 passes** is the minimum default demonstration for critical recovery scenarios.
- **59/59 passes** is preferred for the main nominal-operating scenario.
- Fewer trials may still be useful for engineering screening, but they should not be described as strong reliability evidence.

## Rule 2 — endurance / soak campaigns (time-based, zero failures)

For a zero-failure endurance test with accumulated exposure `T_total`, the one-sided upper confidence bound on failure rate is:

`lambda_upper = -ln(1 - C) / T_total`

The corresponding one-sided lower confidence bound on MTBF is:

`MTBF_lower = T_total / -ln(1 - C)`

At `C = 0.95`, `-ln(0.05) ≈ 2.996`.

Useful values at 95% confidence:

| Total zero-failure exposure | Lower MTBF bound |
|---|---:|
| 500 node-hours | 167 h |
| 1000 node-hours | 334 h |
| 2000 node-hours | 668 h |

Interpretation used in the plan:

- **500 node-hours** is a minimum screening endurance target.
- **1000 node-hours** is the preferred first proven-in-use evidence target for this exact field-node configuration.
- More hours are needed before making strong unattended-operation claims.

## Caveats

- Independence matters. Repeated trials should vary realistic operating states, not just repeat the exact same easy condition.
- Zero-failure counting is only credible when pass / fail criteria are fixed in advance.
- If failures occur, use full reliability analysis; do not keep quoting zero-failure tables.
- These methods do not replace environmental, ingress, EMC, or security test methods; they size repetition and exposure.
