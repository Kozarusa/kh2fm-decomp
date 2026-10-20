# 002adf60 blocked
- Range: 002adf60, 108 bytes. Versions tried: 7. Best: v4 with 15 differing words (100/108 bytes).
- First difference of the best version: !! 002adf64: 24020001 li v0,1 | 002adf64: 240b0001 li t3,1.
- Changes tried: v1 fresh source 24 words; C7c v2 alternate exit layout 24; C11b v3 success-result temporary 24; C11d v4 initial result guard 15; C11c v5 result binding v0 15; C11d v6 successful-return guard 15; C11c v7 array-base binding t3 15.
- Why it stops here: no improvement for 3 versions (v5, v6, v7); ties increment streak even when size or first difference improves.
- Next hypothesis: C11a reorder independent initial computations, then investigate C7 branch layout without combining controls. Successful/zero returns currently merge into one epilogue.
