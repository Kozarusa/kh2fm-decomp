# 002b23e0 blocked
- Range: 002b23e0, 72 bytes. Versions tried: 8. Best: v5 with 2 differing words (72/72 bytes).
- First difference of the best version: !! 002b2414: 01ae6818 mult t5,t5,t6 | 002b2414: 01ae7018 mult t6,t5,t6.
- Changes tried: v1 fresh 8; C11(c) result binding v2 8; C11(d) result guard v3 4; C11(b) factor temporary v4 4; C11(c) factor binding v5 2; C11(d) factor guard v6 2; C11(b) reuse result for product v7 2; C11(d) product guard v8 5.
- Why it stops here: budget reached (8), also no improvement for 3 versions.
- Next hypothesis: test product transport through a separate unsigned temporary, then a binding in a separate version; retain operand order.
- Problems: PROGRESS initially guessed v5 tally as 4 before diff inspection; corrected to 2 before v6 probe and decisions. No stop counter reset.
