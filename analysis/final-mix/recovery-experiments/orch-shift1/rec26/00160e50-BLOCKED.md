# 00160e50 blocked
- Range: 00160e50, 108 bytes. Versions tried: 8. Best: v4 with 4 differing words (108/108 bytes).
- First difference of the best version: !! 00160e70: 56000002  bnezl s0,0x160e7c | beqz s0,160e7c (original loads a0=128(s0) in likely delay slot then D_004f3b38; compiled swaps the two loads); also 00160ea0 lw t7,424(a0) vs 424(s0).
- Changes tried: C7 ternary in while cond (12 words); C9 volatile load (17); node assigned in condition (4); swap ternary arms (4); for/if-else forms (17).
- Why it stops here: budget reached.
- Next hypothesis: make the body load use a0 not s0 (register-bind next to $4, C11c) and force bnezl form for the ternary.