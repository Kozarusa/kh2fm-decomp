# 001aff90 blocked
- Range: 001aff90, 80 bytes. Versions tried: 4. Best: v1 with 16 differing words (76/80 bytes).
- First difference of the best version: !! 001aff9c: 8dcf0004  lw	t7,4(t6)  vs  lw	t4,4(t6) (original loads count into t7 then copies it with move t4,t7 at 001affa8; compiled loads straight into t4 and is 4 bytes short).
- Changes tried: v1 pointer loop with count cached (16); v2 count re-read in loop condition (16); v3 volatile count read plus separate limit copy (16); v4 struct with for loop (19).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c/d) bind the count to t7 ($15) with register asm and copy into a separate loop-limit variable to force the move t4,t7.
