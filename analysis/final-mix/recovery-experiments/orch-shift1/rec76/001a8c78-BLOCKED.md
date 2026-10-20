# 001a8c78 blocked
- Range: 001a8c78, 84 bytes. Versions tried: 8. Best: v8 with 4 differing words (84/84 bytes).
- First difference of the best version: !! 001a8c94: 31ee001f  andi	t6,t7,0x1f   | 001a8c94: 31ee0080  andi	t6,t7,0x80
- Changes tried: v1 early returns with u8 kind (19); v2 result var, wrong semantics (19); v3 return 0/1 (20); v4 result var with || chain (17); v5 nested (20); v6 volatile load (18); v7 if/else index==0 branch, result var (16); v8 u32 byte/kind with (u8)kind cast at call (4).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: only the order/registers of the two andi differ (0x1f into t6 first, then 0x80 into t7): reorder so kind is computed and used before the 0x80 test (C11a), or bind kind to $14 (C11c/d).