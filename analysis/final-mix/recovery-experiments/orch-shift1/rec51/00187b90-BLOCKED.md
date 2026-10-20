# 00187b90 blocked
- Range: 00187b90, 84 bytes. Versions tried: 5. Best: v2 with 4 differing words (84/84 bytes).
- First difference of the best version: !! 00187ba8: 8c8f0090  lw	t7,144(a0) | 00187ba8: 8c8e0090  lw	t6,144(a0)
- Changes tried: v1 straight mirror (6 words); v2 swap final two zero stores, 148 then 144 in source (4); v3 entry local loaded first (4); v4 data[0] before entry local (4); v5 temps entry/value/id (4).
- Remaining diff: t6/t7 swapped for the 144 and 136 loads, and sw data[0] / lhu delay-slot order after 188398 jal (4 words).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind the entry pointer to register t7 ($15) and the data value to t6 ($14) with a why comment, or C9 volatile read of 136.
