# 001a7588 blocked
- Range: 001a7588, 80 bytes. Versions tried: 8. Best: v5 with 13 differing words (80/80 bytes).
- First difference of the best version: !! 001a758c: 00a0782d  move	t7,a1                                       | 001a758c: 0080782d  move	t7,a0
- Changes tried: v1 plain Quad copy 16 words; v2 duplicate returns 15; v3 Buf* dest 16; v4 typed callee 16; v5 volatile result read 13; v6 explicit reload 16; v7 nested ifs 15; v8 void* params 13.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: argument shuffle (original saves a1 in t7, a1=a0, a2=t7; compiled saves a0) and branch layout (original beqz then beql s0,sp with lq into t0 and lw v0 in the beqz delay slot and again after sq); try register-binding t7 (C11c) or a different arrangement of the Quad copy.
