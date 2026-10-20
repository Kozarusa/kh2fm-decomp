# 00288b78 blocked
- Range: 00288b78, 112 bytes. Versions tried: 6. Best: v3 with 17 differing words (104/112 bytes).
- First difference of the best version: !! 00288ba0: 25eeffff addiu t6,t7,-1 | 00288ba0: 11e00005 beqz t7,288bb8.
- Changes tried: v1 mirror and literal outgoing result preservation 18 words; C2 global signedness v2 18; C2 local signedness v3 17; C11(b) decrement temporary v4 17; C7(c) early return v5 17; C7(a) negation and body swap v6 18.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind decrement temporary to t6 to constrain calculation scheduling; original separately sign extends loaded byte before branch.
