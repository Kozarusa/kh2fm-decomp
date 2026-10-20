# 0017d8c0 blocked
- Range: 0017d8c0, 112 bytes. Versions tried: 8. Best: v8 with 16 differing words (108/112 bytes).
- First difference of the best version: !! 0017d8e8: 0220202d  move	a0,s1 | 0c046dec jal 11b7b0 (original sets a0 before jal and puts addiu s0,s1,48 in the jal delay slot; compiled puts move a0 in the delay slot).
- Changes tried: v1 straight (19), v2 store via destination pointer (19), v3 volatile D (worse), v4 destination computed before calls (s0 reuse, closer), v5 volatile D (worse), v6 destination between calls (22), v7 register asm $16 on destination after calls (17), v8 v7 plus memory barrier before the constant load (16).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C7/C10 variants: the original branch has the lui of D_0036c574 duplicated in delay slot and the load after the join; try writing the copy as a nested if inside a separate non-inlined structure or pass the return of func_0011b7b0 through; scheduling of move a0 vs addiu in the jal delay slot is unresolved.
