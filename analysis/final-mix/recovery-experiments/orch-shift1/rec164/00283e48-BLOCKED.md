# 00283e48 blocked
- Range: 00283e48, 112 bytes. Versions tried: 7. Best: v4 with 13 differing words (112/112 bytes).
- First difference of the best version: !! 00283e4c: 3c0d0036 lui t5,0x36 | 00283e4c: 3c0f0036 lui t7,0x36.
- Changes tried: v1 direct18; row guard v2 14; row t6 v3 18; nextValue temporary v4 13; index t7 v5 18; next guard v6 17; reordered next/current v7 16.
- Why it stops here: no improvement for 3 versions under strict R7.
- Next hypothesis: global-address temporary then separate t5 binding may align initial allocation; each control separately.
