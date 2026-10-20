# 00239e60 blocked
- Range: 00239e60, 88 bytes. Versions tried: 5. Best: v2 with 2 differing words (88/88 bytes).
- First difference of the best version: !! 00239e68: 25ef14bc addiu t7,t7,5308 | 00239e68: e48d0138 swc1 f13,312(a0).
- Changes tried: v1 scalar float stores 22 words; v2 C11 pointer temporary with empty guard 2 words; v3 C10 guard between stores 3 words; v4 C11 flag guard depending on loaded float 3 words; v5 C11 y tied to pointer guard 3 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(c), make the y store volatile from best v2 to constrain scheduling.
- Verbatim first difference: !! 00239e68: 25ef14bc  addiu	t7,t7,5308   ; = D_003714bc                | 00239e68: e48d0138  swc1	$f13,312(a0)
