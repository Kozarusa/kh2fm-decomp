# 001c3aa0 submitted
- Range: 001c3aa0, 128 bytes. Source: orch1_rec98_001c3aa0_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C1a, declaring func_0016bd60 with (u8*, s32) removed 64-bit pointer truncation (24 to 10 words). C11d/C9-style, pointer variable plus empty asm, produced the lui/addiu address before the lwc1 (10 to 0).
- Emitted assembly or register bindings: one empty asm("" : "+r"(coefficient)) with a why comment, no instruction emitted.
- Provisional: names and types are inferred from instructions only.
