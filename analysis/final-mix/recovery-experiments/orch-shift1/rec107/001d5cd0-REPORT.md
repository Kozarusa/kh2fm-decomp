# 001d5cd0 submitted
- Range: 001d5cd0, 76 bytes. Source: orch1_rec107_001d5cd0_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C11(d) empty asm on the table base pointer stops the compiler folding the 4150 offset into the lbu (13 words to 0).
- Emitted assembly or register bindings: one empty asm("" : "+r"(base)) to keep the base address in its own register.
- Provisional: names and types are inferred from instructions only.
