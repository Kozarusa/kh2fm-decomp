# 001b1bb8 submitted
- Range: 001b1bb8, 40 bytes. Source: orch1_pro01_001b1bb8_v2.cpp (exact). Versions tried: 2.
- Changes that mattered: v1 copied the best earlier attempt (eight_hour_001b1bb8_float_forward_1, 3 words: last three byte stores rotated). C10(a): writing the cursor stores in source order 1, 2, 3 makes the scheduler emit the original order 3, 1, 2.
- Emitted assembly or register bindings: `register u8* cursor asm("$15")` (the original addresses the last three bytes through t7 = object+20); empty `asm("" : "+r"(cursor))` (keeps the cursor from being folded into the store offsets). No instructions are emitted by the asm.
- Provisional: names and types are inferred from instructions only.
