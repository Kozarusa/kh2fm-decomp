# 00187ab8 submitted
- Range: 00187ab8, 116 bytes. Source: orch1_rec50_00187ab8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: result variable initialized to zero (25 to 13 words); goto done and reset after loop (to 6); separate cursor local (to 4); C11c register binding of result to $15 (to 0).
- Emitted assembly or register bindings: result bound to $15 (t7) because the compiler otherwise chose t6.
- Provisional: names and types are inferred from instructions only.
