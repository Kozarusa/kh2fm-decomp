# 001da420 submitted
- Range: 001da420, 56 bytes. Source: orch1_nm08_001da420_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C11c, the next-count load is bound to $15 (t7) and copied into the value variable.
- Emitted assembly or register bindings: one register binding of next to $15, with a why comment (original loads into t7 then moves to v0).
- Provisional: names and types are inferred from instructions only.
