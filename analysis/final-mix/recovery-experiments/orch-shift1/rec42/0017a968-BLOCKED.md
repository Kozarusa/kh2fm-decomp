# 0017a968 blocked
- Range: 0017a968, 124 bytes. Versions tried: 8. Best: v4 (also v7, v8) with 2 differing words (124/124 bytes).
- First difference of the best version (v4): !! 0017a998: e5c0000c  swc1	$f0,12(t6)  | compiled: e6200510  swc1 $f0,1296(s1)
- Changes tried: v1 FVector operator= (23 words, self-check and sw zero); v2 Quad copy plus f32 zero variable (14); v3 FVector by value (15); v4 explicit asm lq/sq copy through t0, stores 0,1,2,3 (2); v5 order 3,0,1,2 (4); v6 barrier after [3] (7); v7 order 1,2,3,0 (2); v8 order 3,2,1,0 (2).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original store order is z[3],x[0],y[1],z[2] (offsets 12,0,4,8); try other source permutations (e.g. 2,3,0,1 / 0,3,1,2 with a temp pointer base), or volatile f32 stores (C10c).
