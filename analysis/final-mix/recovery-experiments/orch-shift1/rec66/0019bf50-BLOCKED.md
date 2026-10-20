# 0019bf50 blocked
- Range: 0019bf50, 128 bytes. Versions tried: 4. Best: v1 with 25 differing words (100/128 bytes); v4 is the closest in structure (116/128 bytes, still 25 words).
- First difference of the best version: !! 0019bf6c: 26040590  addiu	a0,s0,1424  | compiled: 7a0f0540 lq t7,1344(s0) (the compiler folds the quad addresses into lq/sq offsets and drops the pointer compare registers).
- Changes tried: v1 Quad members in a struct (25); v2 u8* offsets (25); v3 register Quad temp at t0 ($8) per accepted 001906f0 (25, 100 bytes); v4 asm "+r" on the dst/src/vec address pointers (25, 116 bytes).
- Why it stops here: no improvement for 3 versions (R7).
- Next hypothesis: bind dst to $4 and src/vec to $15 with register ... asm("$4") / asm("$15") plus asm("+r") so the beql delay slot (t7 = vec) forms; then the tail: original is lwu + dsll32 + dsra32 + andi (u32 field widened to 64 bit then truncated to s32), try `return (s32)(u64)*(u32*)(object + 0x604) & 1` with an s64 intermediate.
