# 0018a100 blocked
- Range: 0018a100, 96 bytes. Versions tried: 5. Best: v1 with 14 differing words (88/96 bytes).
- First difference of the best version: !! 0018a124: 11e0000b  beqz	t7,0x18a154 | 0018a124: 11e0000a  beqz	t7,18a150
- Changes tried: v1 straightforward while loop with early returns (14); v2 for(;;) with break and result var (16); v3 if + do-while (14); v4 separate iterator copy in an if/for (14, also swapped movn to movz and t4/t5); v5 Ghidra-literal for(;;) with break on key 22 (no gain).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps the iterator in v0 with delay-slot nops after beq (no scheduling), end value computed before loop and the not-found return placed mid-function; try volatile reads of the byte (C9) or declaring key as s32/u8-compared and an if/else structure (C7c) around the key==22 test.