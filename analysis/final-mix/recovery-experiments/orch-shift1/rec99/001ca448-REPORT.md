# 001ca448 submitted
- Range: 001ca448, 76 bytes. Source: orch1_rec99_001ca448_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11d empty asm on the masked value (4 words to exact); the switch form matched the branch layout from v1.
- Emitted assembly or register bindings: one empty asm ("" : "+r"(bits)) with a why comment; no instruction emitted.
- Provisional: names and types are inferred from instructions only.
