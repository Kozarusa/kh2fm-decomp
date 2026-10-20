# 00167fc8 blocked
- Range: 00167fc8, 64 bytes. Versions tried: 6. Best: v3 with 5 differing words (64/64 bytes).
- First difference of the best version: !! 00167fe4: dfbf0000  ld	ra,0(sp)  |  000d7080  sll	t6,t5,0x2 (ra reload scheduled after the stores instead of before the index math).
- Changes tried: v1 natural order (10 words); v2 value read first, array store then counter store (10, identical output); v3 memory barrier between the two stores (5, registers now match); v4 volatile counter store (11); v5 barriers after loads and between stores (7); v6 Ghidra-order slot pointer (11).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(b)/C9 on v3: make the D_004f5250 read volatile, or move the barrier so the ra reload schedules before the index shift.
