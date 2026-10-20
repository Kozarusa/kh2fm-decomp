# 002799b0 blocked
- Range: 002799b0, 96 bytes. Versions tried: 6. Best: v3 with 18 differing words (92/96 bytes).
- First difference of the best version: !! 002799b0: 3c0b0036 lui t3,0x36 | 002799b0: 3c0f0036 lui t7,0x36.
- Changes tried: v1 direct loop23; C9 global volatility v2 27; initial-store memory guard v3 18; separate sum-store guard v4 21; integer row addition v5 21; C11b sum temporary v6 18.
- Why it stops here: no improvement for 3 versions, strict R7 ties count.
- Next hypothesis: global-address temporary and later single t3 binding to recover original reload ownership; separate each control.
