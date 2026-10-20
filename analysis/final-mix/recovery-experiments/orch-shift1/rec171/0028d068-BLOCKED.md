# 0028d068 blocked
- Range: 0028d068, 96 bytes. Versions tried: 7. Best: v4 with 2 differing words (96/96 bytes).
- First difference of the best version: !! 0028d0a4: 55e0fff9 bnezl t7,0x28d08c | 0028d0a4: 15e0fff8 bnez t7,28d088 <func_0028d068+0x20>
- Changes tried: v1 direct volatile translation 5 words; C11(a) initialize count inside branch v2 4; C11(c) bind count v3 10; C11(d) one count guard v4 2; C7(a) negated loop exit v5 2; C9 nonvolatile pointer global v6 14; C11(b) explicit pointer temporary with conditional reload v7 25.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7(c) restructure outer early return while retaining v4 loop and count guard.
