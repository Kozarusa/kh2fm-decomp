# 001a74f8 submitted
- Range: 001a74f8, 52 bytes. Source: orch1_rec75_001a74f8_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C13 (void callee types, no stray argument, 7 to 6 words); empty asm memory barrier after the last call prevents the tail call (6 to 0).
- Emitted assembly or register bindings: empty asm volatile memory barrier (emits no instructions), to keep jal plus epilogue.
- Provisional: names and types are inferred from instructions only.
