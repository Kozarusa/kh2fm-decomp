# 00154b98 blocked
- Range: 00154b98, 120 bytes. Versions tried: 8. Best: v7 with 2 differing words (120/120 bytes).
- First difference of the best version: !! 00154bdc: 24910b58  addiu	s1,a0,2904                                 | 00154bdc: 00008012  mflo	s0
- Changes tried: v1 baseline 14; v2 item declared inside if 17; v3 object reused as cursor before the if 24; v4 division after stores 14; v5 item declared early, assigned inside if 8; v6 separate loop counter copy 17; v7 object reused as cursor inside the if 2; v8 swapped loop update statements 2 (no change).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: the only difference is the order of addiu s1 and mflo s0 in the blez delay slot; try a for-loop form, a volatile blocks read (C9), or moving the cursor add into the loop condition.