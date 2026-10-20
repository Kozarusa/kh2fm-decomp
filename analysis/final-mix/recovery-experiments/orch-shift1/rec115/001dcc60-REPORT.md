# 001dcc60 submitted
- Range: 001dcc60, 104 bytes. Source: orch1_rec115_001dcc60_v6.cpp (exact). Versions tried: 6.
- Changes that mattered: C7 goto layout with single result variable (25 to 3 words); C11(d) empty asm guard on the masked value (3 to 0 words).
- Emitted assembly or register bindings: one empty asm("" : "+r"(masked)) guard, with // why comment, to stop the compiler folding the mask test into sra/xori.
- Provisional: names and types are inferred from instructions only.
