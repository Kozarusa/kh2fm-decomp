# 001fb478 blocked
- Range: 001fb478, 100 bytes. Versions tried: 5 (v3 was an invalid draft that never compiled). Best: v2 with 8 differing words (100/100 bytes).
- First difference of the best version: !! 001fb49c: ae00009c  sw	zero,156(s0)  | 001fb49c: 3c0e0036  lui	t6,0x36
- Changes tried: v1 straight translation (10); v2 temp u8 for the global read before the 141 store, registers now match (8); v4 swap 192/193 source order (9); v5 volatile global (8).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the lui/lbu are scheduled too early; try reading the global through a pointer (u8* p = &D) or keep the object pointer in a second variable so the scheduler keeps ld ra before lbu.