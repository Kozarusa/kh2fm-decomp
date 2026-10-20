# 0027ead0 blocked
- Range: 0027ead0, 60 bytes. Versions tried: 7. Best: v4 with 4 differing words (60/60 bytes).
- First difference of the best version: !! 0027eae0: 3c0d0036 lui t5,0x36 | 0027eae0: 81ecf24c lb t4,-3508(t7)
- Changes tried: v1 scalar 8; C11b object temporary v2 8; C11b pointer temporary preserving addition order v3 7; C11c t4 pointer v4 4; C11c a0 object v5 4; C11d single object guard v6 10; C9 volatile object global v7 10 against v5 baseline.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: isolate independent address materialization order with a base temporary; no instruction asm permitted.
- ABI: no incoming args, terminal 0028da70 result forwarded on every path.
