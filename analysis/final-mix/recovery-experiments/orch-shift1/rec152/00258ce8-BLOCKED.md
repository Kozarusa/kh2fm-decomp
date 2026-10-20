# 00258ce8 blocked
- Range: 00258ce8, 88 bytes. Versions tried: 4. Best: v1 with 4 differing words (88/88 bytes).
- First difference of the best version: !! 00258d00: 240e9fd1 li t6,-24623 | 240e9fd0 li t6,-24624.
- Changes tried: v1 source original store order (4); C10 v2 volatile default stores (8); C10 v3 memory barrier between final stores (4); C11 v4 bind index2 constant t6 (6).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: retain best v1, combine correct constant scheduling with store-order constraint under fresh budget.
