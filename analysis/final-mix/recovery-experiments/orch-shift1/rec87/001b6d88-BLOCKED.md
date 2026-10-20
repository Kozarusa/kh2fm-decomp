# 001b6d88 blocked
- Range: 001b6d88, 72 bytes. Versions tried: 6. Best: v3 with 2 differing words (72/72 bytes).
- First difference of the best version: !! 001b6d98: 25ee0001  addiu t6,t7,1 (original) vs andi t7,t7,0xff (compiled); addiu and andi are swapped.
- Changes tried: v1 plain u8 (14 words, mask dropped); v2 u32 with & 0xff (14); v3 volatile u8 read (2, C9); v4 u32 volatile + mask (2); v5 separate next/low vars (8); v6 s32 volatile + mask (3, slti instead of sltiu).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: obtain the addiu t6,t7,1 before the andi mask, e.g. keep the u8 volatile read of v3 and force the +1 temporary to be computed before the compare (asm barrier between, or use a pointer-increment form object[0] = object[0] + 1 from a second expression).
