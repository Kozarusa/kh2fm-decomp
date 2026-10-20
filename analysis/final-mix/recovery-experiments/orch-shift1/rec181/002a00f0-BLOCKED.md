# 002a00f0 blocked
- Range: 002a00f0, 120 bytes. Versions tried: 5. Best: v2 with 27 differing words (124/120 bytes).
- First difference of the best version: !! 002a00f4: ffb20010 sd s2,16(sp) | 002a00f4: 3c0e0036 lui t6,0x36.
- Changes tried: v1 fresh loop 29 words; C11(b) v2 cursor temporary 27; C11(b) v3 address temporary 29; C11(a) v4 independent initialization reorder 27; C11(c) v5 cursor t5 binding 27.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(d) guard an existing address temporary at one unique site to keep address setup before loop.
