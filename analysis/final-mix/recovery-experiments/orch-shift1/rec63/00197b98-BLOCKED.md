# 00197b98 blocked
- Range: 00197b98, 80 bytes. Versions tried: 4. Best: v1 with 17 differing words (72/80 bytes).
- First difference of the best version: !! 00197b9c: 3c0f0035  lui	t7,0x35   | compiled: ffbf0000  sd ra,0(sp)
- Changes tried: v1 plain (17); v2 u8* object plus f32 array global (17, same); v3 volatile float read (17, size 76, ld ra delay slot now matches); v4 u8 array global with volatile cast (17, same as v3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original forms the float address with a separate lui/addiu pair into t7 (not folded into lwc1) and issues lui 0x35 before sd ra; try a register-bound pointer to D_0036d0a8 (C11c) or reading the float through a pointer variable assigned before the null test.
