# 0022c758 blocked
- Range: 0022c758, 100 bytes. Versions tried: 7. Best: v4 with 3 differing words (100/100 bytes).
- First difference of the best version: !! 0022c7ac: 11e2fff8 beq t7,v0,0x22c790 | 0022c7ac: 15e2fff2 bne t7,v0,22c778 <func_0022c758+0x20>.
- Changes tried: v1 direct do/while, 14 words. C1 verified complete paths/signature and C7(a) nonzero if/else v2, 14 words. C7(c) common result and break v3, 13 words. C7(a) zero case first v4, 3 words. C7(a) continue/else break v5, 3 words. C7(c) shared finish label v6, 3 words. C7(c) direct equality return v7, 14 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7(c), flatten loop into explicit call label and put the finish block physically before the nonzero comparison block, preserving the original epilogue-first placement.
