# 0013a820 blocked
- Range: 0013a820, 116 bytes. Versions tried: 5. Best: v2 with 13 differing words (116/116 bytes); v3, v4, v5 also 13.
- First difference of the best version: !! 0013a82c: 148f000e  bne	a0,t7,0x13a868   | 0013a82c: 548f000e  bnel	a0,t7,13a868
- Changes tried: C7 two separate top-level `if (code==0xffff) { if (mode==1) ...}` blocks (24 -> 13 words, size now matches); cursor[1] store through cursor (13); scalar globals plus &D pointer (13, optimizer normalises); rotating second-block store source order (13, output stays 8,4,12 instead of 4,12,8).
- Remaining differences: (1) bnel vs bne at the first mode test; (2) first block: original keeps base in t7 and the loop cursor in t6 with counter in t5 (addiu t6,t7,addr emitted before the first sw), compiled uses t7 as cursor and t6 as counter; (3) second block store order 4,12,8 vs compiled 8,4,12.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10c volatile (or asm memory barrier) stores in the second block to force 4,12,8 order; for the first block C11c bind counter to $13 (t5) and cursor to $14 (t6); the bnel may then disappear.
