# 001abba8 blocked
- Range: 001abba8, 72 bytes. Versions tried: 4. Best: v1 with 3 differing words (72/72 bytes).
- First difference of the best version: !! 001abbd0: 8e2f000c  lw	t7,12(s1) | 001abbd0: dfbf0010  ld	ra,16(sp)
- Changes tried: v1 u8* base = object+20, plain stores, 3 words. v2 both loads into locals before stores, 4. v3 volatile reads inline, 3. v4 first plain, second volatile local, 4 (loads in swapped order).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(d) asm volatile memory barrier between the two loads and the stores, or a volatile read of object+16 placed first with the object+12 read through a plain local.
