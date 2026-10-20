# 001cd4c0 blocked
- Range: 001cd4c0, 96 bytes. Versions tried: 8. Best: v6 with 12 differing words (100/96 bytes).
- First difference of the best version: !! 001cd4d0: 1440000f  bnez	v0,0x1cd510 | 001cd4d0: 1440000e  bnez	v0,1cd50c.
- Changes tried: v1 plain returns 20 words (92 bytes); v2 D_0032bae0 as u16 array 20; v3 result bound to $15 19; v4 if/else chain with bound result 19 (96 bytes); v5 compile error; v6 local base pointer u16* on v4 12; v7 restructured default-zero 15; v8 v6 without binding 26 (s0 used).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original merges the h>=51 branch and the isExec-true case into one shared "result = 0" block placed before the epilogue (branch target 0x1cd50c), with the others jumping past it; try a form with a shared tail block, e.g. a single flag combining (h>=51 || (b==0 && IsExec)) so result = 0 appears once, while result stays unbound.