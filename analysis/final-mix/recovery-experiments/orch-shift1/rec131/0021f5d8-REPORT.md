# 0021f5d8 submitted
- Range: 0021f5d8, 72 bytes. Source: orch1_rec131_0021f5d8_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11-style empty asm guard on the source pointer stopped the compiler folding the address into lwc1.
- Emitted assembly or register bindings: empty asm("" : "+r"(source)) with why comment; no instructions emitted.
- Provisional: names and types are inferred from instructions only.
