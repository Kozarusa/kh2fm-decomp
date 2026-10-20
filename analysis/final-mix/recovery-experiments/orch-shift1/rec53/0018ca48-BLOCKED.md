# 0018ca48 blocked
- Range: 0018ca48, 56 bytes. Versions tried: 8. Best: v3 (also v6) with 4 differing words (64/56 bytes).
- First difference of the best version: !! 0018ca54: 3c0e0037  lui	t6,0x37  | 0018ca54: 3c0e0000  lui	t6,0x0 (jump table address is an unresolved relocation in the probe; the other 2 words are a duplicated jr ra / li v0,1 block at the end)
- Changes tried: v1 plain switch 1,3,4 (15 words, branch tree, no table); v2 contiguous cases 3..7 (10, branch tree); v3 cases 0..5 and 18 with odd cases returning 1 (4, jump table emitted, extra duplicate li 1 block); v4 only case 1 returns 1 (7, li falls into shared jr ra); v5 cases 1,3,5 merged (7); v6 v3 minus case 5 (4); v7 break instead of return value (7); v8 cases 1,3 merged (7).
- Why it stops here: budget reached.
- Next hypothesis: the jump table is emitted with the right shape (v3); remaining diffs are the table relocation (lui/addiu of D_0036cc28, possibly unfixable in a standalone probe) and the duplicated return-1 block; try making case 1 the only return-1 body with an extra distinct non-return-value case (e.g. a case that `break`s) so the table has enough nodes without a second li 1 body.
