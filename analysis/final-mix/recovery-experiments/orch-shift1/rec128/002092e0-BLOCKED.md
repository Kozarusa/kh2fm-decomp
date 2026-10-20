# 002092e0 blocked
- Range: 002092e0, 68 bytes. Versions tried: 7. Best: v4 with 6 differing words (68/68 bytes).
- First difference of the best version: !! 002092e4: 8ccd000c  lw	t5,12(a2)   vs compiled move t7,a0 (load/move scheduling order only; registers and branch match).
- Changes tried: v1 plain nested expression 12 words (tail j); v2 empty asm barrier after call 15 words (loads sunk into branch); v3 hoisted loads into locals 7; v4 target before expected 6; v5 inlined compare 6; v6 expected between base and offset 7; v7 volatile read of expected 6.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C9/C10 variants that put the lw t5,12(a2) before move t7,a0 and the lw t6,8(t5) before lw t3,12(a0) (e.g. volatile read of the base load, or u32/pointer typing of context).