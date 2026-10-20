# 001a6bc8 blocked
- Range: 001a6bc8, 108 bytes. Versions tried: 4. Best: v1 with 9 differing words (108/108 bytes).
- First difference of the best version: !! 001a6be4: 8e0d0600  lw	t5,1536(s0)   vs   8e0e0600  lw t6,1536(s0)
- Changes tried: v1 temps loaded in order b,a,c and stores c,a,state,b (9 words); v2 mask of flags_b split from the or (9, same output); v3 volatile state member (9, same output); v4 loads in order c,a,b (11).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: only register numbers (b in t5, a in t4, c in t6) and the position of the flags_b store (original last, after state) differ; try C11 register binding of value_b to $13 and value_c to $14 (with why comments), or an asm("" : "+r") after the b mask.
