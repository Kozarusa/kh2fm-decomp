# 001c0560 blocked
- Range: 001c0560, 80 bytes. Versions tried: 5. Best: v2 with 13 differing words (80/80 bytes).
- First difference of the best version: !! 001c0578: 56000002  bnezl	s0,0x1c0584 | 12000002 beqz s0,1c0584
- Changes tried: v1 next in s0 (17); v2 object=next before test, callee takes next (13); v3 ternary, callee void (14); v4 if(next) call continue, callee void (14); v5 same with callee arg (13).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original uses branch-likely (bnezl with lw a0,80(s0) in the delay slot) and puts the epilogue before the call block; try C8 volatile read of D_01d49350 or a do-while/goto layout.
