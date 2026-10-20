# 002a1ec8 blocked
- Range: 002a1ec8, 120 bytes. Versions tried: 8. Best: v8 with 4 differing words (120/120 bytes).
- First difference of the best version: !! 002a1ef8: 25ef4b60 addiu t7,t7,19296 | 002a1ef8: 39ce0010 xori t6,t6,0x10.
- Changes tried: fresh v1 9; C11(b) v2 flag temporary 9; C11(d) v3 pointer guard 8; C11(c) v4 offset t5 binding 7; C9 v5 memory clobber on pointer guard 9; C11(c) v6 flag t6 binding 7; C11(d) v7 flag guard 6; C7(a) v8 invert selection condition 4.
- Why it stops here: budget reached.
- Next hypothesis: C11(b) introduce an explicit base-address temporary before selection; then test binding and guard separately to place addiu before xori.
