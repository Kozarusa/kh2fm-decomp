# 002aa450 blocked
- Range: 002aa450, 84 bytes. Versions tried: 4. Best: v1 with 4 differing words (84/84 bytes).
- First difference of the best version: !! 002aa478: 8d8e0000 lw t6,0(t4) | 002aa478: 8d8d0000 lw t5,0(t4).
- Changes tried: C11 v2 separate flag temporary, 4 words; C11 v3 bind word to t6, 4 words; C11 v4 one empty result guard, 4 words. v1 correct return address, 4 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: bind result to original t5, separately from prior binding and guard controls, then investigate remaining OR/AND schedule.
