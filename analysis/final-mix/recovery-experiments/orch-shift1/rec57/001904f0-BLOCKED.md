# 001904f0 blocked
- Range: 001904f0, 124 bytes. Versions tried: 7. Best: v2 with 8 differing words (124/124 bytes).
- First difference of the best version: !! 00190528: 1040000c  beqz	v0,0x19055c | 1040000b beqz v0,190558 (branch offset differs because the compiled zero-path has extra move a2,zero and the tail is laid out differently).
- Changes tried: C7 swap branches (14 -> 8 words, v2); 1902a8 as 2 args (11, v3); result > 0 (8, v4); D_0036cd20 as array deref (8, v6); s64 result plus pointer-local global read (8, v7). v5 was a compile error.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original loads D_0036cd20 via lui/addiu then lwc1 0(t7) after the epilogue restore, and passes a2=v0 (non-folded) into 001902a8; try asm("" : "+r"(result)) before the call to defeat constant folding, then a volatile read of the global.
