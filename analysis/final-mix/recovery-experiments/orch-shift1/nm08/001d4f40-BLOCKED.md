# 001d4f40 blocked
- Range: 001d4f40, 104 bytes. Versions tried: 3. Best: v1 with 2 differing words (104/104 bytes).
- First difference of the best version: !! 001d4f7c: 0200202d  move	a0,s0  | 001d4f7c: 240f0001  li	t7,1
- Changes tried: v1 load object+0x2c into a local before binding one (2); v2 v1 plus empty asm "+r"(object) before the one binding (2); v3 empty asm "+r"(one) after binding (compile error from a malformed comment line, not evaluated).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: v3's asm guard on one, written correctly on its own line; or bind one inside the if-body after the lw a1 read.
