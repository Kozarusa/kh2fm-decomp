# 002ad338 blocked
- Range: 002ad338, 88 bytes. Versions tried: 8. Best: v7 with 2 differing words (88/88 bytes).
- First difference of the best version: !! 002ad35c: 258c0001 addiu t4,t4,1 | 002ad35c: 01aa6804 sllv t5,t2,t5.
- Changes tried: v1 fresh 18; C11(c) result binding v2 20; C11(d) one result guard v3 20; C11(c) index binding v4 16; C7(c) result assignment/break v5 20; C11(b) same-iteration word temporary v6 18; C7(c) result assignment/break v7 2; C11(a) mask/increment statement order v8 2.
- Why it stops here: budget reached (8).
- Next hypothesis: one empty guard on existing index after increment, separate from existing binding, to constrain scheduling.
- Specialty: register-allocation (instruction scheduling).
