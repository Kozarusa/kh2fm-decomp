# 00136a18 blocked
- Range: 00136a18, 56 bytes. Versions tried: 1. Best: v1 with 8 differing words (48/56 bytes).
- First difference of the best version: !! 00136a30: dfbf0000  ld	ra,0(sp)  (compiled has li t6,1 there)
- Changes tried: v1 plain call, call, store (8 words differ).
- Why it stops here: the range is two functions: 00136a18..00136a3c ends in a tail jump (j 0x136a40) with a padding nop, and 00136a40..00136a4c (li/lui/sb, jr ra) is a separate function listed as callee 00136a40. A single C++ function cannot emit this; boundary needs review (split the range).
- Next hypothesis: split into func_00136a18 (40 bytes, tail calls func_00136a40) and func_00136a40 (16 bytes).