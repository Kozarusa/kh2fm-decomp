# 001a3958 blocked
- Range: 001a3958, 112 bytes. Versions tried: 4. Best: v1 with 19 differing words (108/112 bytes).
- First difference of the best version: !! 001a3978: 14400007  bnez	v0,0x1a3998 | 001a3978: 0040802d  move	s0,v0
- Changes tried: v1 early return in while(1) (19 words); v2 if(entry!=0)/else return 0 (19, identical output); v3 result variable with break (26, extra s2); v4 do-while with bottom condition (19, same output as v1).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original puts the null-return block inline right after the call (bnez v0 forward, move s0,v0 in delay slot) and the success path ends with b to a shared epilogue; try a goto-based layout or make the s0 assignment separate from the call result (C8/C11).