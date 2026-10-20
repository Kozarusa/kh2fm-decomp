# 00160d70 blocked
- Range: 00160d70, 108 bytes. Versions tried: 6. Best: v3 with 12 differing words (104/108 bytes).
- First difference of the best version: !! 00160d90: 56000002 bnezl s0,0x160d9c (compiled: beqz s0,160d9c with D load in delay slot, then bnezl a0 with lw t7 hoisted into its delay slot; original has bnez a0 + move s0,a0 and unscheduled nops).
- Changes tried: v1 for(;;) with break 17 words (wrong layout); v2 return instead of break 17; v3 while((node = ternary) != 0) with current=node in body 12 (layout right); v4 inline helper 12; v5 volatile head global 13; v6 same as v3 with call arg current 12.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: stop delay-slot hoisting of the owner load and the body (C9: volatile read of node->owner), and try if/else statement for the likely branch (C8).
