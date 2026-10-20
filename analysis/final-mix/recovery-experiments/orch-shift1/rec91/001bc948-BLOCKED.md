# 001bc948 blocked
- Range: 001bc948, 68 bytes. Versions tried: 4. Best: v1 with 11 differing words (64/68 bytes).
- First difference of the best version: !! 001bc94c: 19a0000c  blez	t5,0x1bc980  (compiled blez target 1 word shorter because the original has an extra andi t7,t7,0xff after sltiu).
- Changes tried: v1 plain do/while with early return 1 (11); v2 u8 flag variable (compile error, stray typo); v3 u8 flag variable (11, no andi emitted); v4 bool flag variable (11, no andi emitted).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: force the u8 truncation of the sltiu result, for example a u32 temporary masked with (value & 0xff) in the condition (C3b), or rewrite as a while-loop with the Ghidra shape (pointer advanced in the loop condition).
