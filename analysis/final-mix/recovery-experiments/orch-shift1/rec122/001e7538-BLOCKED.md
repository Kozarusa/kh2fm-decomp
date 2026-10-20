# 001e7538 blocked
- Range: 001e7538, 108 bytes. Versions tried: 4. Best: v1 with 4 differing words (108/108 bytes).
- First difference of the best version: !! 001e7550: 24060002  li	a2,2 | 001e7550: 356b3c00  ori	t3,t3,0x3c00
- Changes tried: v1 volatile MMIO reads (0x10009000, 0x1000a000, 0x10003c00), u8 state, asm cfc2.ni $29 (precedent: cfc2 in queueeta siblings): 4 words. v2 state u32: 4. v3 `> 0` compare: 4. v4 compile error (escaped newline typo in an asm-guard experiment), no result.
- Remaining differences: (a) li a2,2 / ori t3 swapped order (2 words); (b) original `andi t6,t6,0x100; sltu t6,zero,t6` vs compiled `sra t6,t6,8; andi t6,t6,1` for the first bit test (2 words).
- Why it stops here: no improvement for 3 versions (v2, v3, v4 after best v1).
- Next hypothesis: write the first test as `u32 masked = vif1 & 0x100; asm("" : "+r"(masked)); state = 0u < masked;` (the v4 idea, with the typo fixed) to force andi+sltu, then address the li/ori scheduling with a statement reorder.