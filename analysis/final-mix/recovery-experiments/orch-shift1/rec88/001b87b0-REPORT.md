# 001b87b0 submitted
- Range: 001b87b0, 76 bytes. Source: orch1_rec88_001b87b0_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C11(d) asm "+r" on the base pointer keeps it in its own register (11 words to exact).
- Emitted assembly or register bindings: empty asm with +r constraint on base pointer, to stop the compiler folding it into the loop pointer.
- Provisional: names and types are inferred from instructions only.
