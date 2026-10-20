# 001dbcd0 submitted
- Range: 001dbcd0, 104 bytes. Source: orch1_rec114_001dbcd0_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11(c)+(d) - destination pointer bound to $15 with an empty asm guard (v3, 5 to 2 words); quad copy temp bound to $8 (v4, exact).
- Emitted assembly or register bindings: register binding of destination to $15 and of the quad copy to $8, each with a why comment; empty asm guards only.
- Provisional: names and types are inferred from instructions only.
