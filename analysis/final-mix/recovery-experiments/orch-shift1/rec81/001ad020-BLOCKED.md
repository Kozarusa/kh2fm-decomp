# 001ad020 blocked
- Range: 001ad020, 120 bytes. Versions tried: 6. Best: v3 with 6 differing words (120/120 bytes).
- First difference of the best version: !! 001ad024: 24e7000a  addiu	a3,a3,10   | 001ad024: 240e0158  li	t6,344
- Changes tried: C21 rewrite (17 words); entry pointer includes 0x608 (10); store order swap C10 (6); offset temp C11b (6); struct array indexing (10); register bind $16 on product C11c (26).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the multiply constant 344 and product should live in s0 while a3+10 is scheduled first; try C11d asm("" : "+r") on the product, or a volatile read of the index.
