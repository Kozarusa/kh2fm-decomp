# 001d44d8 blocked
- Range: 001d44d8, 80 bytes. Versions tried: 7. Best: v4 with 8 differing words (80/80 bytes).
- First difference of the best version: !! 001d44d8: 3c0b01d6  lui	t3,0x1d6  | 001d44d8: 3c0d01d6  lui	t5,0x1d6
- Changes tried: v1 Ghidra-literal do-while (19); v2 volatile global (21); v3 volatile global with per-iteration base local (17); v4 plain global with volatile cast read of base inside loop only (8); v5 also volatile first read (17); v6 for(;;) with break (8); v7 base variable reused for first read (9).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original loads the base for the next iteration in the bnez delay slot with lui rematerialized into t3 (t3 used as the lui register for both the pre-loop load and the delay-slot reload); try forcing the base load register or a different loop shape (while with explicit pre-increment) so the load is software-pipelined into the delay slot.