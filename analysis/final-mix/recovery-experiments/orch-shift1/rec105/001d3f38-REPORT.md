# 001d3f38 submitted
- Range: 001d3f38, 68 bytes. Source: orch1_rec105_001d3f38_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C2 (s32 id from u16 load gives slti, 13 to 12 words); switch statement with cases 0x11a, 0x158, 0x1e4 returning 0, default 1 reproduced the compiler's switch layout exactly (12 to 0).
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.