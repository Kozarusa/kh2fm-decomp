# 001cfac0 submitted
- Range: 001cfac0, 48 bytes. Source: orch1_rec103_001cfac0_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: empty-asm pointer binding (precedent 0010f660) fixed address materialization; computing b,c,d products into temporaries before the first store (Ghidra order) fixed the mul/store order.
- Emitted assembly or register bindings: empty asm on the pointer to keep the address in a register (zero offset load); no instructions emitted.
- Provisional: names and types are inferred from instructions only.