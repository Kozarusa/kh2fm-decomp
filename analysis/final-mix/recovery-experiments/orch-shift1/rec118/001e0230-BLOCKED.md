# 001e0230 blocked
- Range: 001e0230, 108 bytes. Versions tried: 8. Best: v5 with 3 differing words (108/108 bytes).
- First difference of the best version: !! 001e0258: 56000002  bnezl	s0,0x1e0264  | 001e0258: 12000002  beqz	s0,1e0264
- Changes tried: C7 invert exit test (18->16), if/else select (16), C9 volatile D (19), ternary in while condition (3, best), ternary sense swap (3), volatile D with ternary (5), volatile node load (3).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: the compiler fills the beqz delay slot with the D load and orders the node load after; the original has bnezl with the node load in its delay slot and D load on fall-through; try computing D into a separate local before the loop condition or a u32 typed global.
