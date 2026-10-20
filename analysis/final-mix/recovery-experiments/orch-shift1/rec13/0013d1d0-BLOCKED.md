# 0013d1d0 blocked
- Range: 0013d1d0, 56 bytes. Versions tried: 5. Best: v1 with 5 differing words (52/56 bytes).
- First difference of the best version: !! 0013d1dc: 11e00008  beqz	t7,0x13d200  (compiled branches to 13d1fc; original has a nop at 0x13d1fc and the shared jr ra at 0x13d200, 16-byte aligned).
- Changes tried: v1 early returns (5 words); v2 nested if (5); v3 return u32 / return func() (worse, extra move v0); v4 || condition (5); v5 while-wrapper (5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the original exit label is aligned (nop padding before jr ra); try forcing alignment or a different exit structure (goto/label, volatile child read C9).
