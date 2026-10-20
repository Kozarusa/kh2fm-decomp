# 001904a8 blocked
- Range: 001904a8, 72 bytes. Versions tried: 8. Best: v8 with 5 differing words (72/72 bytes).
- First difference of the best version: !! 001904d4: 7e280000  sq	t0,0(s1)                                     | 001904d4: 0220102d  move	v0,s1
- Changes tried: C12 pointer to quad local kept live with asm (16 -> 6 words, frame/saves now match); C11 Quad typed copy (6); C11(c) temp bound to $8 (5).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C10 - make the store through result volatile (or add asm volatile memory barrier) so sq t0,0(s1) is scheduled directly after lq, before move v0,s1 and the ld ra reload.