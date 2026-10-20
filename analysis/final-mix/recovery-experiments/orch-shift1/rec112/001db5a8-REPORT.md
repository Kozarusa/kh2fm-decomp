# 001db5a8 submitted
- Range: 001db5a8, 104 bytes. Source: orch1_rec112_001db5a8_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C13 - empty asm memory barrier after the second call to stop the tail call (j) the original does not have.
- Emitted assembly or register bindings: empty asm volatile memory barrier only, to prevent tail call.
- Provisional: names and types are inferred from instructions only.
