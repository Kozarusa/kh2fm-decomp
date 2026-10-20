# 0019f8c0 blocked
- Range: 0019f8c0, 52 bytes. Versions tried: 4. Best: v1 with 6 differing words (52/52 bytes).
- First difference of the best version: !! 0019f8d0: 50400005  beqzl	v0,0x19f8e8                                | 0019f8d0: 10400004  beqz	v0,19f8e4 <func_0019f8c0+0x24>
- Changes tried: v1 start from earlier attempt shape, 6 words (compiler emits movz). v2 C8b condition other way, 7 words. v3 C8c volatile read, 8 words (extra andi). v4 C7c early returns, 7 words (48 bytes, beqzl matches, movz remains).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C8 variant on v4 shape: keep sum in a separate variable from the returned value, or add asm barrier to stop the movz conversion (original is bnez with addu in delay slot, then move v0,zero).
