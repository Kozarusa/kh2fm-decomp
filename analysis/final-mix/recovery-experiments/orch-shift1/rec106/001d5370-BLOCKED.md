# 001d5370 blocked
- Range: 001d5370, 116 bytes. Versions tried: 4. Best: v1 with 4 differing words (116/116 bytes).
- First difference of the best version: !! 001d53b8: 8e4e0008  lw	t6,8(s2)                                      | 001d53b8: 8e4f0008  lw	t7,8(s2)
- Changes tried: v1 temp for first load, stores [1] then [0] (4 words); v2 no temp (9 words); v3 two temps loaded second-first (4 words); v4 stores [0] then [1] (9 words).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind the loaded values to t6/t7 with register asm ($14/$15) so first->t6, second->t7 and stores [1] then [0].
