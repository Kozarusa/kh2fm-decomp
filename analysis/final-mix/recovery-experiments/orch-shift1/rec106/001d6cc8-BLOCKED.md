# 001d6cc8 blocked
- Range: 001d6cc8, 56 bytes. Versions tried: 6. Best: v3 with 11 differing words (56/56 bytes).
- First difference of the best version: !! 001d6cc8: 14800004  bnez	a0,0x1d6cdc | 001d6cc8: 3c0f01d6  lui	t7,0x1d6 (compiled hoists the global load above the branch and uses beqz/movn).
- Changes tried: v1 early return (15); v2 swapped if/else (19); v3 load global before the branch (11); v4 load after branch, next computed after load (15); v5 ternary end compare (16); v6 Entry pointer arithmetic (15).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original has the lui hoisted into the bnez delay slot with the lw after the branch in the zero path and movz at the end; try an empty asm on the global address so the lui is computed once before the branch but the lw stays in each arm.
