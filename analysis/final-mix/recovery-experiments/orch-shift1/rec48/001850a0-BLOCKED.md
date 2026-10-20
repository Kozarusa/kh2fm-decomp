# 001850a0 blocked
- Range: 001850a0, 120 bytes. Versions tried: 6. Best: v3 with 5 differing words (112/120 bytes).
- First difference of the best version: !! 00185100: 523dfff3  beql	s1,sp,0x1850d0 | 00185100: 123dfff2  beq	s1,sp,1850cc
- Changes tried: v1 plain Quad copy with VU asm (6 words); v2 early return on out==temp (6); v3 register Quad copy asm("$8") fixed lq/sq t0 (5); v4 return inside the if (5); v5 separate result variable (5); v6 early return plus register t0 (5).
- Why it stops here: no improvement for 3 versions. Remaining diff: original uses beql with move v0,s1 in the delay slot and a duplicated move v0,s1 after the sq (return value set per path, 120 bytes); compiled shares one move v0 (112 bytes).
- Next hypothesis: C8(c) make the comparison/return use a volatile read, or hide the return value per path with asm("" : "+r"(out)) in the copy path.
