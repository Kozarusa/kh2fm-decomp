# 001b8988 blocked
- Range: 001b8988, 72 bytes. Versions tried: 4. Best: v1 with 2 differing words (72/72 bytes).
- First difference of the best version: !! 001b8990: 3c0f01d5  lui	t7,0x1d5 | 001b8990: ffbf0000  sd	ra,0(sp)  (lui and sd ra swapped; everything else matches).
- Changes tried: C10 volatile global store (2 words); C10 reorder source so object[3] loads first (2 words); C11d asm +r on value (10 words, 76 bytes).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: make the global store go through a separate pointer variable (u8* p = &D_01d48d94) or an asm volatile memory barrier before the store (C10d) so the lui is emitted before the prologue sd.
