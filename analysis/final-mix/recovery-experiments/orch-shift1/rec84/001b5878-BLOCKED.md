# 001b5878 blocked
- Range: 001b5878, 48 bytes. Versions tried: 4. Best: v1 with 12 differing words (52/48 bytes).
- First difference of the best version: !! 001b587c: ffbf0000  sd	ra,0(sp)  (compiled hoists addiu t6,a0,168 before the ra save and later does move a0,t6; original computes a0+168 into a0 in the beqz delay slot).
- Changes tried: v1 u8* param, variadic u64 callee (12 words); v2 s32 param (12, no change); v3 callee declared u32(s32) (12, no change); v4 early return form (12, no change).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c)/(d) compute the argument into a variable bound to register $4 (a0) after the flag test, e.g. register s32 arg asm("$4") = object + 0xa8, with a // why comment, so the add lands in the delay slot instead of a hoisted t6 temp.
