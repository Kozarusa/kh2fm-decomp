# 001ac2a8 blocked
- Range: 001ac2a8, 100 bytes. Versions tried: 5. Best: v2 with 2 differing words (100/100 bytes).
- First difference of the best version: !! 001ac2d0: 00c0982d  move	s3,a2  | 001ac2d0: 00e0902d  move	s2,a3
- Changes tried: v1 plain stores (7 words, store order and move order); v2 asm memory barriers between stores for order 8,0,4 (2, only the a2/a3 move order differs); v3 register bindings $18/$19 (2); v4 swapped binding declaration order (2); v5 asm "+r" on second (23).
- Why it stops here: no improvement for 3 versions (v3, v4, v5).
- Next hypothesis: make the move of a2 precede the move of a3 by making the stores of object[1] and object[2] use values copied at different points (for example read third through a volatile local), C9.
