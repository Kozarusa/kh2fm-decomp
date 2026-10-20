# 001da420 blocked
- Range: 001da420, 56 bytes. Versions tried: 4. Best: v1 with 3 differing words (56/56 bytes).
- First difference of the best version: !! 001da440: 8dcf0004  lw	t7,4(t6)                                      | 001da440: 8dc20004  lw	v0,4(t6)
- Changes tried: v1 plain while loop (3 words); v2 do-while with next temp (compile error, scope); v3 do-while with next declared outside (6); v4 while with next temp inside body (3, same as v1).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original loop is bnez on t7 with move v0,t7 in delay slot (not branch-likely); try making the entry[1] reload volatile (C8c/C9) or a for(;;) loop with explicit break/if(next) value=next; continue.
