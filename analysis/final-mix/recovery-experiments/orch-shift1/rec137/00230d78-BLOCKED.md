# 00230d78 blocked
- Range: 00230d78, 100 bytes. Versions tried: 8. Best: v6 with 8 differing words (100/100 bytes).
- First difference of the best version: !! 00230da0: 848e0004 lh t6,4(a0) | 00230da0: 848f0004 lh t7,4(a0)
- Changes tried: reconstruction v1 23 words; C18 union accesses v2 22 words; C9 volatile global v3 19 words; C1 reuse first pointer v4 17 words; C10 memory guards from v1 v5 10 words; C11 addition operand order v6 8 words; C11 first-value binding and guard v7 19 words; C11 temporary without binding v8 8 words.
- Why it stops here: budget reached.
- Next hypothesis: Tune independent source temporaries for all three stores together; the first-value binding alone disrupts the loop allocation.
