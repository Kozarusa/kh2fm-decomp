# 00160f10 blocked
- Range: 00160f10, 108 bytes. Versions tried: 8. Best: v6 with 3 differing words (108/108 bytes).
- First difference of the best version: !! 00160f30: 56000002  bnezl s0,0x160f3c | beqz s0,160f3c (the two loads in the ternary are swapped: original lw a0,128(s0) in bnezl delay slot, then lw a0,D_004f3b38).
- Changes tried: C7 literal Ghidra form (18); ternary in while condition (4); inline helper (12); struct typed (4); C11d asm (13); C11c register u8* next asm($4) with ternary (3, best); if/else (17); volatile D read (3).
- Why it stops here: budget reached.
- Next hypothesis: other ways to force the bnezl delay-slot-load form of the ternary (e.g. C8c volatile on the node->0x80 read) with the a0 binding kept.