# 0028d068 blocked
- Range: 0028d068, 96 bytes. Versions tried: 4. Best: v1 with 2 differing words (96/96 bytes).
- First difference of the best version: !! 0028d0a4: 55e0fff9 bnezl t7,0x28d08c | 0028d0a4: 15e0fff8 bnez t7,28d088 <func_0028d068+0x20>
- Changes tried: v1 unchanged rec171 v4 baseline, 2 words; C7(c) outer nonnegative early return v2, 23 words (100/96); C7(c) nonpositive-count early return from v2 v3, 23 words (100/96); C7(c) negative-index early return from v1 v4, 2 words (96/96). Full source diffs inspected; one intended control each.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7(c) replace do-while with equivalent for loop while preserving count initialization, its single guard, volatile accesses and operand order; do not repeat prior inner-loop negation or pointer-volatility removal.
