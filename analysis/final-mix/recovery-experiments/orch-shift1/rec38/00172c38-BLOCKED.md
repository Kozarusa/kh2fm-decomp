# 00172c38 blocked
- Range: 00172c38, 100 bytes. Versions tried: 8. Best: v8 with 7 differing words (100/100 bytes).
- First difference of the best version: !! 00172c68: dfbf0010  ld	ra,16(sp)                                     | 00172c68: adf00004  sw	s0,4(t7)
- Changes tried: C7 loop forms (v1 break, v2 do-while, v3 nested continue, v6 && do-while) 15 words each; v4 early returns with duplicated tail 8 words; v5 asm barrier before test 10; v7 s64 result 9; v8 asm barrier on null path only 7.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C8 branch-likely: original uses beql into the shared tail (lw t7 in delay slot) and ld ra scheduled before the sw; try making the t7 reload on the match path volatile or a shared goto tail so the delay slot is filled from the tail.