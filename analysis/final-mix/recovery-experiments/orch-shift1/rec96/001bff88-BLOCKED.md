# 001bff88 blocked
- Range: 001bff88, 80 bytes. Versions tried: 5. Best: v2 with 8 differing words (80/80 bytes).
- First difference of the best version: !! 001bffb0: 240d0100  li	t5,256 | 3c0c01d5 lui t4,0x1d5
- Changes tried: v1 scalar globals (9 words; loop matches incl. nops); v2 D_01d49350 as 2-element array (8); v3 C10(d) memory barrier before array stores (10); v4 local pointer for array stores (8); v5 volatile array (9).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the scheduler hoists the D_01d49350 stores (lui t4/sw) ahead of the 4934c/48 stores; original keeps them last with addiu t3 after the store. Try C10(b)/different source order of the three tail globals, or a struct overlay.
