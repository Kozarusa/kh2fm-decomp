# 001abba8 blocked
- Range: 001abba8, 72 bytes. Versions tried: 7. Best: v4 with 3 differing words (72/72 bytes).
- First difference of the best version: !! 001abbd0: 8e2f000c  lw	t7,12(s1)  |  001abbd0: dfbf0010  ld	ra,16(sp)
- Changes tried: v1 locals plus memory barrier before both stores (10); v2 barrier after first load (6); v3 u8* form with barrier between stores (4); v4 u32* form object+5, base[83]/base[82] (3); v5 volatile second store (3); v6 volatile second load (3); v7 first load in a local (3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: ld ra must follow the second load (lw t7,12); try a register binding of the t6/t7 values (C11c) or reading both values as one 64-bit/Quad access.
