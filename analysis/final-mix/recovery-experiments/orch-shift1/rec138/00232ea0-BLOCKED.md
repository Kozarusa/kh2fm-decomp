# 00232ea0 blocked
- Range: 00232ea0, 104 bytes. Versions tried: 4. Best: v1 with 22 differing words (104/104 bytes), orch1_rec138_00232ea0_v1.cpp.
- First difference of the best version: !! 00232ea0: 8cce0000 lw t6,0(a2) | 00232ea0: 94ad0008 lhu t5,8(a1).
- Changes tried: v1 mirrored operations, 22 words, best v1, streak 0. C9 volatile data reads v2: 29 words, best v1, streak 1. C1a void setter signature v3: 29 words, best v1, streak 2. C10c volatile stores v4: 23 words, best v1, streak 3.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C18 union access could preserve mixed-width aliasing and avoid volatile extension instructions.