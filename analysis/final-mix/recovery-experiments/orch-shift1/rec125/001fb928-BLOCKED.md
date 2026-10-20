# 001fb928 blocked
- Range: 001fb928, 124 bytes. Versions tried: 7. Best: v4 with 14 differing words (128/124 bytes).
- First difference of the best version: !! 001fb92c: ffb00000  sd	s0,0(sp)  | 001fb92c: 8cce000c  lw	t6,12(a2)
- Changes tried: v1 straight (24); v2 single-expression base +160 (16); v3 volatile source (25); v4 memory barriers between stores, body matches (14, one extra word); v5 volatile read of other+12 (14); v6 single barrier (20); v7 trailing barrier (14).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the lw of other+12 should schedule after the prologue moves, and the extra word is a duplicated ld s0 at the join; try making the compare operands separate variables or change if to early return.