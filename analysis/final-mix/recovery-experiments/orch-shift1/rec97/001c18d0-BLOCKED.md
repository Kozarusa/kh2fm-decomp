# 001c18d0 blocked
- Range: 001c18d0, 104 bytes. Versions tried: 8. Best: v7 with 16 differing words (108/104 bytes).
- First difference of the best version: !! 001c18e8: 1040000e  beqz v0,0x1c1924 | 1040000d  beqz v0,1c1920 (branch targets shift because the kind chain is laid out out-of-line).
- Changes tried: v1 initial, result live across call -> extra s1 (27 words); v2 C12 init result after call (19); v3 ternary for value (19); v4 early returns (18); v5 ternary + early returns (18); v6 shared result/value variable (20); v7 C7 kind!=0 outer branch (16); v8 swapped ternary (16).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original uses branch-likely (beqzl/beql) with loads in delay slots for the kind==0 / kind==1 chain, value held in t7; try C8(c) volatile read of data[0xf]/data[0xd], or a switch-style form.
