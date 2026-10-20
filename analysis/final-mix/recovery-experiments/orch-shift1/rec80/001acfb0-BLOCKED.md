# 001acfb0 blocked
- Range: 001acfb0, 112 bytes. Versions tried: 4. Best: v1 with 9 differing words (112/112 bytes).
- First difference of the best version: !! 001acfbc: 10af0016  beq a1,t7,0x1ad018 | 10af0015 beq a1,t7,1ad014 (compiled adds move v0,zero for early return, join epilogue placed differently).
- Changes tried: v1 u32 return with return 0 early exit and return callee (9); v2 void if/else (11); v3 u32 fall-off-end (11); v4 void early returns (11).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7 - original joins both calls on one 'ld ra; jr ra' epilogue after a non-tail jal; try making the else call a non-tail call by using the result in a volatile/dummy or goto-style layout.
