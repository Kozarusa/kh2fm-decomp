# 001d9dd0 submitted
- Range: 001d9dd0, 92 bytes. Source: orch1_rec111_001d9dd0_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C21-style restructure - for loop whose condition re-reads the global table count each iteration (v1/v2 do-while with cached count gave 19 words).
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
