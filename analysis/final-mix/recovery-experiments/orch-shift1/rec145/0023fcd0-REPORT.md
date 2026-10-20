# 0023fcd0 submitted
- Range: 0023fcd0, 96 bytes. Source: orch1_rec145_0023fcd0_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11 moved the value load before the counter store (9 to 5 words); C11 bound the counter to t6 (5 to 0 words).
- Emitted assembly or register bindings: count bound to $14 because the original counter uses t6.
- Provisional: names and types are inferred from instructions only.
