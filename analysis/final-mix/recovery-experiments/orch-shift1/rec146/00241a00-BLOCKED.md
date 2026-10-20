# 00241a00 blocked
- Range: 00241a00, 68 bytes. Versions tried: 4. Best: v1 with 11 differing words (68/68 bytes).
- First difference of the best version: !! 00241a04: 0000102d move v0,zero | 00241a04: 0000682d move t5,zero.
- Changes tried: C11 result v0 binding: 13 words; cursor t6 binding: 14 words; empty cursor guard: 11 words.
- Why it stops here: no improvement for 3 versions. The later first difference in v4 is a tie, not an improvement.
- Next hypothesis: C7 explicit if/else may preserve separate return blocks and the original branch-likely loop.
