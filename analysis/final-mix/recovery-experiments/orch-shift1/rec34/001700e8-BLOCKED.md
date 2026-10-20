# 001700e8 blocked
- Range: 001700e8, 120 bytes. Versions tried: 6. Best: v2 with 15 differing words (124/120 bytes).
- First difference of the best version: !! 001700ec: 3c0e0035  lui	t6,0x35 | 001700ec: 3c0c0035  lui	t4,0x35
- Changes tried: v1 flat s32 globals 28 words; v2 Node struct + D_0034dca0[] array 15 words; v3 loop with separate next temp 15; v4 Ghidra comma-loop 15 (132 bytes); v5 local head variable 15; v6 guarded do-while 15 (132 bytes, first part matches but bne instead of bnel).
- Why it stops here: no improvement for 3 versions (stuck at 15).
- Next hypothesis: C11 register binding (head in t7=15, current in t6=14, previous t5=13) or C8 branch-likely tweak on the first compare.