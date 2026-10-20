# 0018e0d8 blocked
- Range: 0018e0d8, 48 bytes. Versions tried: 6. Best: v1 with 12 differing words (40/48 bytes).
- First difference of the best version: !! 0018e0d8: 240f0003  li	t7,3 | compiled: 240f0004  li t7,4
- Changes tried: v1 plain if (12, xori+movz); v2 C8a separate slot var (12, movn); v3 C7 inverted if/else + u8 shift var (12); v4 asm("" : "+r") barrier in then-block (12, folded away); v5 s32 type (12); v6 ternary into u8 slot (12, andi at entry, 44 bytes).
- Why it stops here: no improvement for 3 versions; compiler always if-converts to movz/movn where the original uses bne with move in delay slot and a trailing andi 0xff on the merged value.
- Next hypothesis: C8c make the compare read volatile (value read through a volatile pointer) to force a real branch; keep a separate u8 shift temp.