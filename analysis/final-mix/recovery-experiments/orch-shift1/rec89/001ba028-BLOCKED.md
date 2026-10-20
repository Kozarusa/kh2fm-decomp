# 001ba028 blocked
- Range: 001ba028, 56 bytes. Versions tried: 5. Best: v2 with 12 differing words (56/56 bytes).
- First difference of the best version: !! 001ba028: 0000702d  move	t6,zero                                     | 001ba028: 3c0f01d5  lui	t7,0x1d5
- Changes tried: v1 direct returns (13 words, 52 bytes); v2 single exit with u8 result (12); v3 ternary for next (12); v4 volatile global with if/else (14, 60 bytes); v5 s32 result with u8 return (13, andi appears but loop shape unchanged).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original is an unrotated loop (bnezl on pointer with lw in delay slot, lui t5 hoisted after move t6,zero, loop-back b to the bnezl); compiler hoists lui/lw of the global above the loop. Try making the null-check on a pointer-typed variable (struct pointer, p ? p->next : head) or a for-loop with the global read placed inside a helper expression to avoid hoisting.
