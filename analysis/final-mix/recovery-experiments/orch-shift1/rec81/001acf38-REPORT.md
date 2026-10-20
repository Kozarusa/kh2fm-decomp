# 001acf38 submitted
- Range: 001acf38, 120 bytes. Source: orch1_rec81_001acf38_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C21 rewrite to void with a memory barrier after the second call (keeps it a non-tail call).
- Emitted assembly or register bindings: asm volatile memory barrier after second call, to keep the jal plus own epilogue.
- Provisional: names and types are inferred from instructions only.
