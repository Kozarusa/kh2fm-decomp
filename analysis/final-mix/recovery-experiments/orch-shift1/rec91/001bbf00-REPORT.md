# 001bbf00 submitted
- Range: 001bbf00, 64 bytes. Source: orch1_rec91_001bbf00_v3.cpp (exact). Versions tried: 3.
- Changes that mattered: C3-like - loaded the half into a u32 temporary before shift and mask, which removed the extra andi 0xffff.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
