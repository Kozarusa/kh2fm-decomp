# 00139d78 blocked
- Range: 00139d78, 72 bytes. Versions tried: 8. Best: v7 with 8 differing words (68/72 bytes, see diff.txt for v7); v4 also 8 words (64/72).
- First difference of the best version: !! 00139d9c: 15c00004  bnez	t6,0x139db0   | 00139d9c: 01c0602d  move	t4,t6
- Changes tried: C1 inline-helper structure (16-17 words); &D->next list pointer (17); C9 volatile reload of D for list head (8 words, prologue and loads now match); C7 != 0/else form (9, worse); result initialised 0 only set to 1 in loop (worse); C3b u32 result with & 0xff (andi now emitted, still 8).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original has the exit-to-return block placed before the loop-continue block (bnez t6 to a block with beq t6,a0 to the shared return, li v0,1 in its delay slot, b loop top); try restructuring as do/while with the compare folded into the loop condition, e.g. a flag variable set in the loop and tested at the loop tail, with the u32 result & 0xff retained.
