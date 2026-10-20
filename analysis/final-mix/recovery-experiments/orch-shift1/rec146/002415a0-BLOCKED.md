# 002415a0 blocked
- Range: 002415a0, 100 bytes. Versions tried: 4. Best: v1 with 10 differing words (100/100 bytes).
- First difference of the best version: !! 002415c8: 0000402d move t0,zero | 002415c8: 16000003 bnez s0,2415d8.
- Changes tried: C7 negated condition with explicit else: 10 words. C11 separate argument temporary: 10 words. C11 a1 binding: 16 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 empty read-write guard on the argument binding may force earlier argument preparation.
