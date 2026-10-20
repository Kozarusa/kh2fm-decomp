# 00288fd8 blocked
- Range: 00288fd8, 92 bytes. Versions tried: 7. Best: v4 with 11 differing words (92/92 bytes).
- First difference of the best version: !! 00289000: 00052840 sll a1,a1,0x1 | 00289000: 8c840030 lw a0,48(a0)
- Changes tried: v1 ordinary C++ 22 words; C9 first pointer read volatile v2 17 words; C11(a) initialization order v3 17 words; C11(b) distinct second counter v4 11 words; C9 second pointer read volatile v5 13 words; C11(d) one initialized selection guard v6 11 words; make existing guard volatile v7 11 words.
- Why it stops here: no improvement for 3 versions after best v4; ties count as failures under strict R7.
- Next hypothesis: C8(b) reverse selection condition and branch bodies while preserving the current baseline controls, then separately test C8(c) conditional volatility if necessary.
!! 00289000: 00052840  sll	a1,a1,0x1                                    | 00289000: 8c840030  lw	a0,48(a0)
