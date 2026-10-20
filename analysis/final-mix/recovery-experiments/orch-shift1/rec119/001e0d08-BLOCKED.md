# 001e0d08 blocked
- Range: 001e0d08, 92 bytes. Versions tried: 4. Best: v1 with 20 differing words (76/92 bytes).
- First difference of the best version: !! 001e0d08: 3c0c0035  lui	t4,0x35 | 001e0d08: 3c0b0035  lui	t3,0x35
- Changes tried: v1 volatile D pointer, f32 temporaries (20 words, 76 bytes); v2 struct members, no volatile (23, 52 bytes); v3 volatile object index (21, 92 bytes); v4 no temporaries (22, 92 bytes).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original reloads D, table and index before each of the three stores while hoisting the three lwc1 loads early; try C9 (volatile reads) on a union-typed object, or C11 register binding of the lui to t4 (12) with stores through one union type (C18).
