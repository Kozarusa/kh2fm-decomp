# 0016f930 blocked
- Range: 0016f930, 64 bytes. Versions tried: 6. Best: v2 (and v4) with 9 differing words (64/64 bytes).
- First difference of the best version: !! 0016f934: 0000682d  move	t5,zero                                     | 0016f934: 240c096a  li	t4,2410
- Changes tried: C11 declaration orders (index,pointer,result) v1 11 words; (pointer,result,index) v2 9; (pointer,index,result) v3 11; for-loop with result first v4 9; full asm register binding $12/$13/$14 v5 15 (adds moves, 68 bytes); (index,result,pointer) v6 11.
- Why it stops here: no improvement for 3 versions. Structure matches; only register numbers and instruction order of the 3 loop-init instructions differ (original allocates pointer t4, index t5, result t6, compiled is one register lower).
- Next hypothesis: C11(d) asm("" : "+r") after assignments, or bind only the pointer to $12 with the v2 ordering.