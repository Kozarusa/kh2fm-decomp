# 001c3670 blocked
- Range: 001c3670, 120 bytes. Versions tried: 5. Best: v2 with 2 differing words (120/120 bytes).
- First difference of the best version: !! 001c36ac: 25effca8  addiu t7,t7,-856 | 000e7080  sll t6,t6,0x2 (addiu of D_0032fca8 and the sll are swapped; everything else matches).
- Changes tried: v1 loop as while-with-comma (34 words); v2 simple do-while loop (2); v3 u32 array indexing D[word], D[word+4] (12); v4 bit computed before word (2, unchanged); v5 u8* base variable (12).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: force the addiu of D_0032fca8 before the sll, e.g. compute the array address as a u32* temporary before the shift, or an empty asm barrier between the srl and sll (C10d style).
