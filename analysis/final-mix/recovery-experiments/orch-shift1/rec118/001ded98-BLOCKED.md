# 001ded98 blocked
- Range: 001ded98, 120 bytes. Versions tried: 7. Best: v4 with 5 differing words (120/120 bytes).
- First difference of the best version: !! 001dedc0: 248f0040  addiu	t7,a0,64  | 001dedc0: 248e0040  addiu	t6,a0,64
- Changes tried: C13 memory barrier after calls (26->24), C7 swap if/else order, bit4 block first (24->5), explicit fixed compare temp (7), compare against end+0x10 (21), pre-decrement copy compare (5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 bind loop counter to t7 ($15) and fixed compare base to t6 ($14) with register binding and // why: comments, so the loop ends in bne t6,t7 with a0 untouched.
