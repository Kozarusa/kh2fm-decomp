# 0019bf00 submitted
- Range: 0019bf00, 80 bytes. Source: orch1_rec67_0019bf00_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: C-fold avoidance: holding the 0x100000 mask in a variable stopped the compiler folding the bit test into sra/andi (9 words to exact).
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
