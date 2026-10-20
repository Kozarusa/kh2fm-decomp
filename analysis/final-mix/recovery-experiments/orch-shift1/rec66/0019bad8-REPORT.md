# 0019bad8 submitted
- Range: 0019bad8, 64 bytes. Source: orch1_rec66_0019bad8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: bit-field flag members (u32 :1) instead of masked u32 tests removed the extra andi 0xff (13 to 2 words); padding the first bit-field word with a 31-bit member fixed the field offsets (to exact). Closest to C18.
- Emitted assembly or register bindings: none.
- Provisional: names and types are inferred from instructions only.
