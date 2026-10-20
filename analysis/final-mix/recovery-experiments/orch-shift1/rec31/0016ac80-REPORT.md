# 0016ac80 submitted
- Range: 0016ac80, 92 bytes. Source: orch1_rec31_0016ac80_v4.cpp (exact). Versions tried: 4 (v3 was a malformed file with literal escapes, counted).
- Changes that mattered: C20 u64 callee argument (16 to 2 words); C11 bind quad temp to $8 (2 to 0).
- Emitted assembly or register bindings: register Quad tmp asm("$8") to match t0 temporary.
- Provisional: names and types are inferred from instructions only.
