# 001bc6a8 blocked
- Range: 001bc6a8, 84 bytes. Versions tried: 4. Best: v1 with 1 differing words (84/84 bytes).
- First difference of the best version: !! 001bc6c8: a2080004  sb	t0,4(s0)  vs compiled sb t0,4(a0).
- Changes tried: C11c register u8* asm("") binding (v1, 1 word, no effect on the result); v2 empty +r guard on bound object replacing the barrier (4); v3 volatile byte store on bound object, no barrier (2); v4 separate self copy with +r guard used for later stores plus barrier (2, stores sb/move a0 order swapped).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10 reorder so the byte store follows the argument move move a0,a1 is not possible; try making flag a pointer-based read or u8-typed parameter with the store through a volatile-qualified s0 copy.
