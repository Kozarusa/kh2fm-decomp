# 001e0230 blocked
- Range: 001e0230, 108 bytes. Versions tried: 8. Best: v3 with 3 differing words (108/108 bytes).
- First difference of the best version: !! 001e0258: 56000002  bnezl	s0,0x1e0264  | 001e0258: 12000002  beqz	s0,1e0264
- Changes tried: v1 do-while with if/else into a separate next local (22); v2 D loaded into a head local before the ternary (19); v3 Link struct pointer typing with ternary (3, best); v4 ternary sense swap on Link typing (3); v5 for(;;) with if/else assigning node directly (17, gives beqzl); v6 same with node==0 first (16, gives the exact bnezl and slot loads but node lands in s0 directly); v7 node==0 first with a separate next local assigned to node (13, first 13 words exact including bnezl and move s0,a0); v8 v7 with if (next != 0) { call; continue; } break (13).
- Remaining diff in v7/v8: the compiler puts the call block inline after the test (beqz a0 to the epilogue); the original has bnez a0 to a call block placed after the epilogue, so the epilogue follows the test directly.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: start from v7 and change only the exit shape so the epilogue block follows the test (for example a while loop whose condition is the assignment, or move the call into a trailing block via goto), keeping the node==0 first / separate next structure that produced the correct first 13 words.
