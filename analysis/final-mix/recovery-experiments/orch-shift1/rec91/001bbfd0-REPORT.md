# 001bbfd0 submitted
- Range: 001bbfd0, 60 bytes. Source: orch1_rec91_001bbfd0_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C5-like address materialization - the global address is held in a pointer variable forced into a register.
- Emitted assembly or register bindings: one empty asm("" : "+r"(p)) so the address is built in a register before the load; pattern copied from accepted 001675b0.
- Provisional: names and types are inferred from instructions only.
