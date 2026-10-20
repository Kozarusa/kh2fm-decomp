# 0019c090 blocked
- Range: 0019c090, 104 bytes. Versions tried: 8. Best: v6 with 15 differing words (100/104 bytes).
- First difference of the best version: !! 0019c0b0: 15e00005  bnez t7,0x19c0c8 | 0019c0b0: 15e00004 bnez t7,19c0c4.
- Changes tried: v1 bool locals (21); v2 u8 flag1 (22, lbu); v3 result var return form (20); v4 literal masks (21, ori merge); v5 result var if/else (21); v6 else-if for 0x20/0x1000000 tests (15); v7 mask var in else block (15); v8 split ifs (20).
- Why it stops here: no improvement for 3 versions after v6.
- Next hypothesis: Make the second flag test branch around 'flag2 = 1' (original: move t5,zero in delay of bnez 0x20 test, then lui/and/beqz skipping li t5,1) instead of the compiler's sltu t5,zero,t7; try an || condition where the 0x1000000 mask is a non-foldable register value without hoisting its lui above the 0x20 test.
