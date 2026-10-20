# 00292af0 blocked
- Range: 00292af0, 80 bytes. Versions tried: 4. Best: v1 with 18 differing words (72/80 bytes).
- First difference of the best version: !! 00292af4: 0000682d move t5,zero | 00292af4: 85ecf4e0 lh t4,-2848(t7).
- Changes tried: fresh v1 18 words; C1 input width v2 19 words; C1(b) separate zero result v3 19 words; C7(a) negate and swap if/else v4 19 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 bind initialized loop index to numeric $13 to retain initialization before count load.
