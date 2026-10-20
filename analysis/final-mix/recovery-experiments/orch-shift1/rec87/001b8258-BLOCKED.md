# 001b8258 blocked
- Range: 001b8258, 52 bytes. Versions tried: 4. Best: v1 with 11 differing words (52/52 bytes).
- First difference of the best version: !! 001b8258: 3c0d7000  lui t5,0x7000 (original) vs lui t6,0x7000 (compiled); register allocation and lui hoisting differ.
- Changes tried: v1 plain stores (11); v2 pointer-typed globals (11, C11); v3 volatile globals (12, store order correct but registers differ, C10c); v4 swapped last two stores in source (11, C10a).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind the 0x70000000 constant and the 0x35 base registers with register asm bindings (t5=13, t4=12, t3=11), or volatile only on the last two globals.
