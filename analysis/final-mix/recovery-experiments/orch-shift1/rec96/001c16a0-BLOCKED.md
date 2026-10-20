# 001c16a0 blocked
- Range: 001c16a0, 76 bytes. Versions tried: 6. Best: v3 with 12 differing words (76/76 bytes).
- First difference of the best version: !! 001c16b0: 11c0000c  beqz	t6,0x1c16e4 | 15c00006 bnez t6,1c16cc
- Changes tried: v1 merged call, u32 return (18); v2 void merged call (18, 68 bytes); v3 two separate tail-call sites kind==0 / kind==1 (12, size exact, t5 copy matches); v4 tests swapped (16); v5 early-return form (12); v6 negated nesting (18).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original tests kind==0 first but lays the kind==0 call block last (reached via b into shared tail) and kind==1 block inline; need a branch-layout rewrite (e.g. switch, or goto-shared tail) or C8-style tweak.
