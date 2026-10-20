# 002642a8 blocked
- Range: 002642a8, 108 bytes. Versions tried: 4. Best: v4 with 2 differing words (108/108 bytes).
- First difference of the best version: !! 002642cc: 3c0e0037 lui t6,0x37 | 002642cc: 3c0e0000 lui t6,0x0.
- Changes tried: v1 direct switch 15 words; C11c result binding v2 23 words (rejected initialization across call); C7c early returns v3 22 words; C11b selector temporary v4 2 words.
- Why it stops here: R12 uncovered compiler-generated jump-table relocation. All code matches except table address; manual provides no supported relocation control.
- Next hypothesis: orchestrator must establish compiler-generated table relocation mapping to D_003732a0; no instruction asm workaround authorized.
