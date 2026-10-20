# 001cebb0 blocked
- Range: 001cebb0, 88 bytes. Versions tried: 5. Best: v2 with 2 differing words (88/88 bytes).
- First difference of the best version: !! 001cebdc: 24040001  li	a0,1  vs compiled addiu a2,a2,-5112 (li a0 and addiu a2 swapped).
- Changes tried: v1 empty +r guard on first argument 1 (3 words); v2 callback declared as single u8 and passed as &D_001cec08 (2); v3 v2 plus +r guard on callback pointer (2, now li a1/addiu swapped instead); v4 v2 plus +r guard on first argument (3); v5 v2 plus +r guard on 14001 (2).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: guard the callback pointer (v3) and additionally make 14001 or the first argument volatile, or move func_001ce8b8's argument through a local so the global store schedules later.
