# 001d7f40 blocked
- Range: 001d7f40, 60 bytes. Versions tried: 5. Best: v2 with 10 differing words (60/60 bytes).
- First difference of the best version: !! 001d7f44: 1980000a  blez	t4,0x1d7f70 | 001d7f44: 0000782d  move t7,zero (move placed before blez; index in t7 instead of t5, byte in t6 instead of t7, compare in t5 instead of t6).
- Changes tried: v1 do-while with separate current var (13 words, mthi/mfhi artifact); v2 single result var (10 words); v3 C11c register bindings for index/item (10 words, size 64, mthi artifact returned); v4 for loop with break (12 words, movz); v5 index init inside the if (14 words).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 register allocation (reorder so index lands in t5), e.g. bind only the index to $13 while keeping result in v0 form from v2, or C8 to remove the movz/mthi merges.