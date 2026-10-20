# 001d53e8 blocked
- Range: 001d53e8, 100 bytes. Versions tried: 4. Best: v1 with 4 differing words (100/100 bytes).
- First difference of the best version: !! 001d5414: 81cd0003  lb	t5,3(t6)  (compiled: lb t5,2(t6); original loads bytes in order 1,3,2, compiled 1,2,3).
- Changes tried: v2 temporaries in load order 0,1,3,2 (7 words); v3 regrouped expression (b0|b3<<24)|(b1<<8|b2<<16) (6 words); v4 b0|b3<<24|((b1<<8)|(b2<<16)) (6 words).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C9, read bytes 3 and 2 through volatile s8 pointer, or C11 register binding of the three byte temporaries.
