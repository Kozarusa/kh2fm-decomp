# 001b6d88 blocked
- Range: 001b6d88, 72 bytes. Versions tried: 6. Best: v3 with 2 differing words (72/72 bytes).
- First difference of the best version: !! 001b6d98: 25ee0001  addiu t6,t7,1 (original) vs andi t7,t7,0xff (compiled); addiu and andi swapped.
- Changes tried: v1 u8 next local (11 words); v2 s32 next local (7+); v3 s32 next + memory barrier (2); v4 u32 value, mask in compare (2); v5 u32 value, (u8) cast, no barrier (7+); v6 asm "+r" on value (2, C11d).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the addiu/andi order is likely a scheduler choice tied to how the 'value' is typed; try a pointer-based form (u8* p = object; ++ via *p) or a union/struct field access.