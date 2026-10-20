# 001a81f0 blocked
- Range: 001a81f0, 104 bytes. Versions tried: 4. Best: v1 with 22 differing words (100/104 bytes).
- First difference of the best version: !! 001a81fc: 95cf0002  lhu	t7,2(t6)   | 001a81fc: 95cc0002  lhu	t4,2(t6)
- Changes tried: v1 plain do-while (22); v2 temp copy of count (22, same); v3 for loop (26); v4 count assigned in if condition (24).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c)/(d) register binding or asm barrier on count to force lhu into t7 then move t4,t7 (original has an extra move; compiled is 4 bytes shorter).