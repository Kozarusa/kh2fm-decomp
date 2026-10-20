# 0027bf20 blocked
- Range: 0027bf20, 68 bytes. Versions tried: 4. Best: v1 with 6 differing words (68/68 bytes).
- First difference of the best version: !! 0027bf30: 85cc0002 lh t4,2(t6) | 0027bf30: 85cc0004 lh t4,4(t6)
- Changes tried: v1 copied earlier function with mandatory name cleanup 6; C11a left halfword first statement v2 8; C11c count t4 binding v3 7; C11d one count guard v4 7.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C9 volatile first halfword read to preserve load order; compare result register allocation separately.
