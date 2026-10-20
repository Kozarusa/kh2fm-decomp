# 0019ee28 blocked
- Range: 0019ee28, 52 bytes. Versions tried: 6. Best: v3 with 7 differing words (52/52 bytes).
- First difference of the best version: !! 0019ee38: 3c0e0035 lui t6,0x35 (original) vs 44800000 mtc1 zero,$f0 (compiled).
- Changes tried: v1 separate globals, plain 0 (10 words, sw zero instead of swc1); v2 struct global (11); v3 local f32 zero=0.0f, 3 globals (7, size now matches); v4 cast array form for first store (7, same output); v5 State* pointer (7, different registers); v6 volatile first store (7, same as v3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps base t6=lui D_00350448 live, forms explicit pointer t7=t6+1096 for the +32 store, then a fresh lui for 0x350464; mtc1 is scheduled after the first lui. Try a struct with D_00350464 as separate global and compute the pointer via an asm-free u32 address expression, or move f32 zero below the first lui by declaring it after a dummy read.
