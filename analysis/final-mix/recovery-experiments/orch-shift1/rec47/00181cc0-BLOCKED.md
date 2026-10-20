# 00181cc0 blocked
- Range: 00181cc0, 112 bytes. Versions tried: 7. Best: v6 with 20 differing words (108/112 bytes).
- First difference of the best version: !! 00181cc0: 948d0000  lhu	t5,0(a0)  vs compiled lhu t6,0(a0) (original keeps raw lhu value in t5 and recomputes sll/sra sext into t6 on every use; compiler carries one sign-extended value in t6 and uses a delay-slot copy).
- Changes tried: v1 s16 from lh (25 words, 92 bytes); v2 u16 with (s16) casts (27, lh folded); v3 s32 with shift sext (21, 108); v4 u16 with shift sext (21); v5 pre-check plus do-while (22); v6 volatile u16 loads plus (s16) casts (20); v7 s16 variable from volatile u16 load (20, 104 bytes).
- Why it stops here: no improvement for 3 versions of the same shape (v5, v7 not better than v6); compiler keeps folding the repeated sign extension.
- Next hypothesis: C11 bind the raw u16 to t5 (register ... asm("$13")) and force a separate sign-extension temp per use, or change the exit/tail structure so the loop-bottom check is not duplicated into a delay slot.
