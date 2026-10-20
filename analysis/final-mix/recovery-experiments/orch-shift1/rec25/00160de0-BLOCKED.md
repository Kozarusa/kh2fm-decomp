# 00160de0 blocked
- Range: 00160de0, 108 bytes. Versions tried: 4. Best: v1 with 12 differing words (104/108 bytes).
- First difference of the best version: !! 00160e00: 56000002 bnezl s0,0x160e0c (compiled: beqz s0 with D load first, then bnezl a0 with lw t7 hoisted into its delay slot; original has bnez a0 + move s0,a0 in delay and unscheduled nops).
- Changes tried: v1 while((node = current ? current->next : head) != 0) with current=node in body 12; v2 volatile owner read 17; v3 duplicate of v1 12; v4 for(;;) with asm barrier on current 18.
- Why it stops here: no improvement for 3 versions (same loop shape as sibling 00160d70, also stuck at 12).
- Next hypothesis: control delay-slot filling of the loop body (C8/C9 variants such as a volatile read of the loop head or if/else for the likely branch); this function and 00160d70 are the same shape and likely share the fix.
