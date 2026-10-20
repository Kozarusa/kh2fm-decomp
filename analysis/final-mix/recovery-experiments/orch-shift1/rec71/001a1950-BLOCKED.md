# 001a1950 blocked
- Range: 001a1950, 60 bytes. Versions tried: 4. Best: v1 with 16 differing words (68/60 bytes).
- First difference of the best version: !! 001a1954: ffbf0000  sd	ra,0(sp)  vs compiled  andi t5,a3,0xff  (compiler hoists the u8 mask of a3 into a new temp t5 before the prologue store and copies it back with move a3,t5 on both paths; original masks a3 in place in the bnez delay slot, so no temps and 60 bytes).
- Changes tried: v2 C3 callee/method last param u32 (16 words, no change); v3 C3b u32 param with explicit & 0xff (16, no change); v4 C7c if/else instead of early return (16, worse structure).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 bind a3 value with register u32 flag asm("$7") and asm("" : "+r"(flag)) after the mask so the compiler masks in place; or C9 volatile read of the vtable slot to move the mask after the load.
