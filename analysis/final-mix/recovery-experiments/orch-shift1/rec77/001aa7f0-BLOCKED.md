# 001aa7f0 blocked
- Range: 001aa7f0, 92 bytes. Versions tried: 5. Best: v2 with 3 differing words (92/92 bytes).
- First difference of the best version: !! 001aa834: dfbf0008  ld	ra,8(sp)  |  001aa834: ae00004c  sw	zero,76(s0)
- Changes tried: v1 struct form (Obj with Sub at +64; 4 words, arg offset typo); v2 fixed arg to object->q (3 words: ld ra comes after lw a0 instead of before sw 76); v3 volatile read of f0 in final call (worse); v4 compile error from a script mangling the register name (counted); v5 register-bound inner pointer in t7 (worse).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the struct form (see orch1_rec77_001aa7f0_v2.cpp) gets all stores right; only the ld ra slot differs. Try writing the last store as a Sub member (sub.d) before the call through a second pointer, or read object->f0 into a local before the inner stores, or order the epilogue by ending with a return of the call result.
