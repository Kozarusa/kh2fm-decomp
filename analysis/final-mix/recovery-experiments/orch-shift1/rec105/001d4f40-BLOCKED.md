# 001d4f40 blocked
- Range: 001d4f40, 104 bytes. Versions tried: 8. Best: v8 with 2 differing words (104/104 bytes).
- First difference of the best version: !! 001d4f7c: 0200202d  move	a0,s0  | 001d4f7c: 240f0001  li	t7,1 (the li t7,1 is scheduled 2 instructions earlier than the original, swapped with move a0,s0).
- Changes tried: v1 u64 object, plain flow (25); v2 scale converted to float before call (20); v3 object as u8* and callee u8* (19); v4 array global via local pointer (19); v5 raw/amount split (worse, movn); v6 empty asm "+r" on the global pointer (4); v7 bind amount to t6 (5); v8 v6 plus bind constant 1 to t7 via register (2).
- Why it stops here: budget reached.
- Next hypothesis: the scheduling of li t7,1 relative to move a0,s0 (C11/C10): try moving the constant into the if-body as a bound register after the lw a1 read, or an empty asm "+r"(one) after the object load so the li is emitted later.