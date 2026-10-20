# 001b43e0 submitted
- Range: 001b43e0, 80 bytes. Source: orch1_rec85_001b43e0_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C13 tail call blocked by an empty asm memory barrier after the last call.
- Emitted assembly or register bindings: asm volatile("" ::: "memory") after func_00105110, emits no instruction; reason: keeps jal plus shared epilogue instead of j tail call.
- Provisional: names and types are inferred from instructions only.
