# 001dee10 blocked
- Range: 001dee10, 120 bytes. Versions tried: 6. Best: v3 with 5 differing words (120/120 bytes).
- First difference of the best version: !! 001dee38: 248f0040  addiu	t7,a0,64  | 001dee38: 248e0040  addiu	t6,a0,64
- Changes tried: C11 register bindings t7/t6 (7), struct-pointer post-decrement loop (7), pass pointer to callee so a0 stays live plus bit4 block first (5, best), same with struct loop (7), prev-copy compare (5), bindings on best (7).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: compiler allocates the fixed compare base to t5 and counter to t6 where the original uses t6 and t7; try declaring the base after the -32 check as a separate scope or an asm("" : "+r") guard on the counter.
