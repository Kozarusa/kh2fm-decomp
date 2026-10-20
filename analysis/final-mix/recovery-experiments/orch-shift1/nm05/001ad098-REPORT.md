# 001ad098 submitted
- Range: 001ad098, 92 bytes. Source: orch1_nm05_001ad098_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C11 -> v1 empty "+r" guard on global pointer (10 to 7 words); v2 bind it to $15 (5 words); v3 bind vtable address to $15 with guard (exact).
- Emitted assembly or register bindings: two register bindings to $15 (t7) plus empty "+r" guards, to match original register reuse; no instructions.
- Provisional: names and types are inferred from instructions only.
