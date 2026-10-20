# 0022e0a8 blocked
- Range: 0022e0a8, 100 bytes. Versions tried: 7. Best: v4 with 3 differing words (100/100 bytes).
- First difference of the best version: !! 0022e0fc: 11e2fff8 beq t7,v0,0x22e0e0 | 0022e0fc: 15e2fff2 bne t7,v0,22e0c8
- Changes tried: v1 direct do loop, 14 words; C7 v2 nonzero branch first, 14; C7 v3 shared return, 13; C7 v4 zero branch first, 3; C7 v5 explicit continue/else break, 3; C7 v6 labelled blocks, 3; C11 v7 empty result guard on backedge, 4.
- Why it stops here: no improvement for 3 versions. Counts: v1 14, v2 14, v3 13, v4 3, v5 3, v6 3, v7 4. Earliest minimum is v4, independently recounted three !! rows.
- Next hypothesis: C9 volatile read of object comparison may preserve forward equality branch and original repeat-block placement. Guarding result changes branch to beql and loses original argument delay slot.
