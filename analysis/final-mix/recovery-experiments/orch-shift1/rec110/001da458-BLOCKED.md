# 001da458 blocked
- Range: 001da458, 124 bytes. Versions tried: 7. Best: v4 with 24 differing words (132/124 bytes).
- First difference of the best version: !! 001da478: 8c8f0008  lw	t7,8(a0)                                      | 001da478: 8c8e0008  lw	t6,8(a0)
- Changes tried: v1 plain (28); v2 reuse index as count (30); v3 Holder struct pointer + separate locals (30); v4 Holder + index reused for count (24, prologue now matches); v5 compile error; v6 precomputed next pointer (24); v7 u32 index with items mutation (30).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: first 4-iteration loop scheduling differs (original puts sw zero after sltiu and sw cursor in bnez delay slot, no nops; compiled has 2 nops and extra register t6/t7 swap); try C10 volatile on cursor store or asm memory barrier, or write the loop as for(;;) with counter in s1 coalesced with count.
