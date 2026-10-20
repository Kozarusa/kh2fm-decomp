# 001b86e0 blocked
- Range: 001b86e0, 56 bytes. Versions tried: 4. Best: v1 with 5 differing words (56/56 bytes).
- First difference of the best version: !! 001b86f4: 8d8f00c0  lw t7,192(t4) (original) vs lw t6,192(t4) (compiled); counter loaded into t7 and the slot scale shifted before the increment in the original.
- Changes tried: v1 s32 array base, read index, offset, store index+1, store slot (5); v2 slot pointer computed before increment, double reads (12); v3 index, slot pointer, offset, increment, store (12); v4 u8 base with byte arithmetic (11, extra D_01d48d88 symbol, 60 bytes).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c)/(d) register-asm bind the index temporary to t7 (15) in v1, or reorder so the offset expression is computed after the increment store.
