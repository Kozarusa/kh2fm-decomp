# 0020e9f8 blocked
- Range: 0020e9f8, 76 bytes. Versions tried: 4. Best: v1 with 18 differing words (68/76 bytes).
- First difference of the best version: !! 0020e9f8: 3c0d0037  lui	t5,0x37  | 0020e9f8: 3c0f0037  lui	t7,0x37
- Changes tried: v1 scalar globals (18); v2 array-typed globals with [1]/[0] stores (18); v3 explicit pointer variables for out and scale (18); v4 volatile constant reads (18).
- Why it stops here: no improvement for 3 versions. The compiler folds lui+lwc1 offset; original materializes each constant address with lui+addiu then lwc1 0(reg), divides f1 first, and has 19 instructions vs 17.
- Next hypothesis: force address materialization with asm("" : "+r"(ptr)) on pointers to D_003707c0/D_003707c4/D_00359110 (C11d) and force the f1 divide first via a separate temporary.
