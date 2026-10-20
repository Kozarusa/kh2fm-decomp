# 0021ea50 blocked
- Range: 0021ea50, 128 bytes. Versions tried: 4. Best: v1 with 24 differing words (124/128 bytes).
- First difference of the best version: !! 0021ea68: c5e20000  lwc1	$f2,0(t7)   | 0021ea68: c5e30000  lwc1	$f3,0(t7)
- Changes tried: v1 volatile matrix + volatile table reads (24; all 16 stores in original order and values match), v2 non-volatile table reads (31), v3 pointer variable for the constant (24), v4 explicit negated temp (24).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: float register numbering is reversed (original cos f0, neg f1, sin f2, one f3) and D_00370b4c is loaded as lui/addiu/lwc1 0(t7) instead of a folded offset; try u32 address cast for the constant, or cosine declared before sine with volatile reads.
