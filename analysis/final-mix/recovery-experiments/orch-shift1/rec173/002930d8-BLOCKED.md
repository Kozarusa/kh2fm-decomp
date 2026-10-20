# 002930d8 blocked
- Range: 002930d8, 108 bytes. Versions tried: 4. Best: v1 with 22 differing words (100/108 bytes).
- First difference of the best version: !! 002930d8: 3c0b0036 lui t3,0x36 | 002930d8: 3c0f0036 lui t7,0x36.
- Changes tried: v1 22 words; C9 volatile loop count v2 22 words; C10(d) empty memory guard from v1 v3 23 words; C11(c) defined count pointer $11 binding from v3 v4 29 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 reorder count-address and table-address computations without pointer binding to preserve signed halfword loads.
