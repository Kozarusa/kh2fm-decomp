# 001bc6a8 blocked
- Range: 001bc6a8, 84 bytes. Versions tried: 8. Best: v5 with 1 differing word (84/84 bytes).
- First difference of the best version: !! 001bc6c8: a2080004  sb	t0,4(s0)  vs compiled sb t0,4(a0) (original uses saved s0, compiled uses a0; the following move a0,a1 is in the same place).
- Changes tried: C3 u32 flag param (21 -> 2 words); C10c volatile sb (2); C10d barrier after sb (2, order worsened); C10d barrier between sh and sb (1, best); C11d asm "+r"(object) (4); barriers on both sides (1); barrier plus volatile sb (see v8 diff, not better).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C11c bind the object pointer to s0 with register u8* name asm("$16") so the byte store uses s0 instead of a0.
