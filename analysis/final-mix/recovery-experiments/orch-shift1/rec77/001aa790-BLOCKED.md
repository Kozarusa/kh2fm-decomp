# 001aa790 blocked
- Range: 001aa790, 92 bytes. Versions tried: 4. Best: v1 with 3 differing words (92/92 bytes).
- First difference of the best version: !! 001aa7cc: ade00008  sw	zero,8(t7)  |  001aa7cc: dfbf0008  ld	ra,8(sp)
- Changes tried: v1 plain stores with inner=object+16 (3 words: ld ra scheduled 2 slots too early); v2 asm memory barrier before last store C10d (worse); v3 volatile inner pointer C10c (3); v4 volatile last store (3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: ld ra must be emitted after the two inner stores; try expressing the inner stores as struct member writes or via a bound register for the inner pointer (t7 = $15), or change the final call to pass object+16 computed inline.
