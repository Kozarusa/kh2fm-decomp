# 0013e3b0 submitted
- Range: 0013e3b0, 96 bytes. Source: orch1_rec12_0013e3b0_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C14 - lq/sq copy via t0 asm primitive (FVector operator= adds a self-assign guard that the original lacks).
- Emitted assembly or register bindings: two asm volatile lq/sq copies via t0, pattern from accepted fm_copy_helpers.cpp.
- Provisional: names and types are inferred from instructions only.
