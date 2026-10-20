# 001d5d20 submitted
- Range: 001d5d20, 96 bytes. Source: orch1_rec106_001d5d20_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C11(d) empty asm on the base pointer (one lui+addiu base, 18 to 15 words); C11(d) empty asm on a constant 1 (slt with li register, 15 to 0).
- Emitted assembly or register bindings: two empty asm register constraints (base pointer, constant 1), each with a why comment; no instruction-emitting asm.
- Provisional: names and types are inferred from instructions only.
