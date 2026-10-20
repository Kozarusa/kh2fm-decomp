# 001d9228 blocked
- Range: 001d9228, 92 bytes. Versions tried: 7. Best: v4 with 7 differing words (96/92 bytes).
- First difference of the best version: !! 001d9240: 0000102d  move	v0,zero                                     | 001d9240: 0000202d  move	a0,zero
- Changes tried: v1 result var (25 words, extra s1 saved); v2 early returns (9, lbu instead of lw); v3 result var + u32 read masked to u8 (25); v4 early returns + u32 read + base vars (7); v5 if/else result (7); v6 register result asm("$2") (17, beqzl); v7 asm keep on result (7).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: final return value is allocated to a0 with a trailing move v0,a0; original keeps it in v0 via move v0,zero in branch delay slots; try a ternary/&& expression form or a u64 result.
