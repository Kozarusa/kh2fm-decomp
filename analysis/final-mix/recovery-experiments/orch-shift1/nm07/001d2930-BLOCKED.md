# 001d2930 blocked
- Range: 001d2930, 112 bytes. Versions tried: 4. Best: v1 with 2 differing words (112/112 bytes).
- First difference of the best version: !! 001d295c: 01c0982d  move	s3,t6  vs compiled move s0,a1 (the move s3,t6 and move s0,a1 are swapped).
- Changes tried: v1 C11c register s32 remaining asm("$16") (2, no change); v2 early-return form (2, no change); v3 u8* table local for D_0036e3d0 (19); v4 volatile D_00352668 (23).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: bind a base pointer to $19 (s3) to the lui value only (e.g. u8* base from the constant 0x350000 with D_00352668 accessed as base+0x2668), or guard the argument/count copies with an empty +r asm placed after the first global load.
