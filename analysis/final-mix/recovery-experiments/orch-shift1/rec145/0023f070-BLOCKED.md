# 0023f070 blocked
- Range: 0023f070, 76 bytes. Versions tried: 4. Best: v1 with 5 differing words (76/76 bytes).
- First difference of the best version: !! 0023f080: 00a0802d move s0,a1 | 0023f080: 0080802d move s0,a0
- Changes tried: C10 reversed independent stores in v2 (5 words); C11 introduced a value temporary in v3 (5 words); C11 bound value to s0 in v4 (5 words).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(d), add an empty read/write asm guard after the value binding.
