# 0022f528 blocked
- Range: 0022f528, 120 bytes. Versions tried: 8. Best: v6 with 2 differing words (120/120 bytes).
- First difference of the best version: !! 0022f574: afae0004 sw t6,4(sp) | 0022f574: afaf0000 sw t7,0(sp).
- Changes tried: baseline v1 12 words; C11 object binding v2 15; C11 sentinel binding v3 6; C10 sentinel store order v4 4; C11 halfword binding v5 4; C11 field computation order v6 2; C11 separate temporaries v7 4; C9 volatile halfword loads v8 19.
- Why it stops here: budget reached.
- Next hypothesis: C10 use a narrowly placed empty memory guard with preloaded field temporaries to retain load order while enforcing second-field store first.