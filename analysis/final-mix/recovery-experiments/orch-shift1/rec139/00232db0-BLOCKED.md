# 00232db0 blocked
- Range: 00232db0, 100 bytes. Versions tried: 8. Best: v5 with 15 differing words (100/100 bytes), source orch1_rec139_00232db0_v5.cpp.
- First difference of the best version: !! 00232db4: 3c090036 lui t1,0x36 | 00232db4: 240affff li t2,-1.
- Changes tried: C1 checked signature and paths; v1 21 words. Volatile global reloads gave v2 17 words. C11 address operand reversal gave v3 17 words; sentinel temporary gave v4 17 words; sentinel register binding gave v5 15 words; sentinel guard gave v6 16 words; index binding gave v7 21 words; index guard gave v8 20 words.
- Streak sequence: v1 0, v2 0, v3 1, v4 2, v5 0, v6 1, v7 2, v8 3.
- Why it stops here: budget reached and no improvement for 3 versions.
- Next hypothesis: C11 reorder sentinel initialization relative to global address preparation, using the earliest best source v5.