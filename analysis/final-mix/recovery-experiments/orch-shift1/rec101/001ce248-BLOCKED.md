# 001ce248 blocked
- Range: 001ce248, 88 bytes. Versions tried: 4. Best: v1 with 9 differing words (88/88 bytes).
- First difference of the best version: !! 001ce254: 0000382d  move	a3,zero  | 001ce254: 0080282d  move	a1,a0
- Changes tried: v1 plain expression b0|(b3<<24)|((b2<<16)|(b1<<8)) 9 words; v2 temps loaded in order 1,3,2,0 (C10a) 11 words; v3 regrouped high bytes (C7) 14 words; v4 reordered ors 13 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C9 volatile byte reads to force load order 1,3,2,0 and a1/a0 move after the loads.
