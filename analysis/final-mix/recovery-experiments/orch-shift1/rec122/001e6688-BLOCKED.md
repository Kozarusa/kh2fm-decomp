# 001e6688 blocked
- Range: 001e6688, 92 bytes. Versions tried: 6. Best: v3 with 9 differing words (92/92 bytes).
- First difference of the best version: !! 001e6688: 3c0d01db  lui	t5,0x1db | 001e6688: 3c0f01db  lui	t7,0x1db
- Changes tried: v1 plain global arrays: 20 words (tail jump). v2 barrier after last call (C13): 15. v3 volatile arrays for store order (C10c): 9. v4 volatile scalar+pointer forms: 9. v5 non-volatile with barrier mid-stores: 17. v6 reordered source stores: 14.
- Why it stops here: no improvement for 3 versions (v4, v5, v6 after best v3).
- Next hypothesis: original is non-volatile (explicit addiu t7=&D_01da8cd0 and lui t5 reused for the scalar store, t3/t4 likewise) but store order 0,7,354690[0],354690[1],1,5,4,2,6,3 must come from the scheduler; try C11 register bindings for t5/t7/t3/t4 or a struct type for each global.