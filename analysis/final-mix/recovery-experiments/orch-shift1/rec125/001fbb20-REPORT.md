# 001fbb20 submitted
- Range: 001fbb20, 116 bytes. Source: orch1_rec125_001fbb20_v6.cpp (exact). Versions tried: 6.
- Changes that mattered: C18 one union type (u8/u16/u32/f32) for all accesses keeps load/store order (15 -> 7 words); C11 empty asm guard on the `other` parameter keeps its load after the prologue moves (7 -> 0).
- Emitted assembly or register bindings: one empty asm("" : "+r"(other)) with a why comment; no instruction emitted.
- Provisional: names and types are inferred from instructions only.