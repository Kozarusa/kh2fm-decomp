# 002925c0 blocked
- Range: 002925c0, 72 bytes. Versions tried: 6. Best: v3 with 4 differing words (72/72 bytes).
- First difference of the best version: !! 002925d4: 3c060002 lui a2,0x2 | 002925d4: 3c070029 lui a3,0x29.
- Changes tried: C1 signed callback address v2 5 words; signed word argument v3 4 words; C11(b) size temporary v4 4 words; C11(c) defined $6 binding v5 5 words; C11(d) one empty guard v6 6 words. v1 16 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Reorder independent callback-address computation relative to size temporary without altering operand order or declarations.
