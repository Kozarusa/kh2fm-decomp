# 0020cf60 blocked
- Range: 0020cf60, 88 bytes. Versions tried: 4. Best: v1 with 3 differing words (88/88 bytes).
- First difference of the best version: !! 0020cf90: 8da80014  lw	t0,20(t5)   vs compiled lwc1 $f13,16(t5) (argument load order of lw t0 / lw a0 / lwc1 f12 / lwc1 f13 only)
- Changes tried: v2 all four loads in locals in original order 6 words; v3 only float loads in locals 6 words; v4 volatile float reads 12 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(d) memory barrier between locals, or a callee declaration with a different parameter order/types (e.g. ints for words, f32 pair declared first) to change argument evaluation order.