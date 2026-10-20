# 002376d8 blocked
- Range: 002376d8, 68 bytes. Versions tried: 4. Best: v1 with 10 differing words (68/68 bytes). Source: orch1_rec141_002376d8_v1.cpp.
- First difference of the best version: !! 002376e8: 8c8c000c  lw	t4,12(a0)                                     | 002376e8: 8c8f000c  lw	t7,12(a0)
- Changes tried: R4 instruction-order translation v1: 10 words; C11(a) index-store reorder v2: 10 words; C11(b) base temporary v3: 10 words; C11(c) initialized pointer binding to $12 v4: 10 words.
- Why it stops here: no improvement for 3 versions. Equal word counts do not improve the best, including the later first difference in v4.
- Next hypothesis: C11(d) add an individually justified empty guard after assigning the bound pointer, then address the remaining store scheduling.
