# 0010a828 blocked
- Range: 0010a828, 92 bytes. Versions tried: 5. Best: v2 with 17 differing words (84/92 bytes).
- First difference of the best version: !! 0010a830: 25efa3dc  addiu	t7,t7,-23588   ; = D_0036a3dc              | 0010a830: c5e0a3dc  lwc1	$f0,-23588(t7)   ; = D_0036a3dc
- Changes tried: v1 direct form (18); v2 far modified in place plus scaled temp (17, best); v3 volatile constant globals (17); v4 constants read through local volatile pointers (17); v5 constants declared as arrays (17).
- Why it stops here: no improvement for 3 versions. Compiled is 8 bytes short: the original materializes each constant address with lui+addiu then lwc1 0(reg) and has extra instructions, which no tried change reproduced.
- Next hypothesis: C4(c)/C1: try f32 params in swapped meaning or pass through a double/global struct; also consider that the 4 elided words in the original may be nops from an asm-level schedule (boundary-review/float-transport).
