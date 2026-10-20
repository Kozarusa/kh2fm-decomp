# 001bba88 blocked
- Range: 001bba88, 52 bytes. Versions tried: 4 (a v5 draft exists but was never probed). Best: v1 with 3 differing words (44/52 bytes).
- First difference of the best version: !! 001bba98: 10400006  beqz	v0,0x1bbab4                                 | 001bba98: 10400003  beqz	v0,1bbaa8 <func_001bba88+0x20>
- Changes tried: v1 result reuse, IsExec returns u64 (3 words; the zero path reuses v0, original has separate b + move v0,zero); v2 if/else with explicit result=0 (10); v3 early return/tail call (8, tail-called j); v4 ternary (8, tail-called).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: probe the unprobed v5 draft: declare IsExec as bool (as accepted siblings do) with u64 result = 0 set before the if, so the zero is materialized separately (C7/C8).
