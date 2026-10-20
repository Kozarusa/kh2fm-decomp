# 002953c8 blocked
- Range: 002953c8, 100 bytes. Versions tried: 4. Best: v1 with 18 differing words (96/100 bytes).
- First difference of the best version: !! 002953e0: 8c4c0008 lw t4,8(v0) | 002953e0: 8c4a0008 lw t2,8(v0).
- Changes tried: v1 unsigned offset transport, 18 words; C11c v2 offset binding, 22 words; C7c v3 else zero assignment, 18 words; C11d v4 loop-head guard, 18 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11c bind count to initialized $12 without changing other controls, then assess loop scheduling.
