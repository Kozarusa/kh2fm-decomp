# 002aab90 submitted
- Range: 002aab90, 84 bytes. Source: orch1_rec184_002aab90_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C11 bind existing OR result to t5 in v2; add empty result guard in v3, preserving original OR-before-condition sequence.
- Emitted assembly or register bindings: result bound to $13 because original OR uses t5; empty +r result guard keeps OR result before condition. Separate versions, one guard site.
- Provisional: names and types are inferred from instructions only.
