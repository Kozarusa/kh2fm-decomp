# 00281cf0 blocked
- Range: 00281cf0, 72 bytes. Versions tried: 4. Best: v1 with 14 differing words (68/72 bytes).
- First difference of the best version: !! 00281cfc: 25ef41a4 addiu t7,t7,16804 | 00281cfc: 3c0e0036 lui t6,0x36
- Changes tried: scalar v1 14; explicit address array v2 14; C11b pointer temporary v3 14; C11c t7 pointer binding v4 14.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11d single empty pointer guard to retain formed constant address before lwc1 offset0.
- ABI audit: a0 scalar preserved across call; outgoing 00281b30 v0 forwarded after halfword store; f0 used for float transfer before callee.
