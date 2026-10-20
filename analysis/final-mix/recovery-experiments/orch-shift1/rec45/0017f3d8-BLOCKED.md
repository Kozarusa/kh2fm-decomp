# 0017f3d8 blocked
- Range: 0017f3d8, 84 bytes. Versions tried: 7. Best: v2 with 4 differing words (84/84 bytes).
- First difference of the best version: !! 0017f410: 01e0102d  move	v0,t7 (original) vs swc1 $f12,4(t7) (compiled). Original order is move v0, swc1 f12, swc1 f13, sw a2; compiled is swc1 f12, move v0, sw a2, swc1 f13.
- Changes tried: v1 plain s32* indexing (20 words); v2 base=object+0x3c pointer with entry/slot split (4 words); v3 reorder source stores (4); v4 memory barrier between stores (worse); v5 asm +r copy for return value (4); v6 volatile float stores (4); v7 int store first (4).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(b)/C11: scheduler orders move v0 and the float vs int stores; try return type u32/pointer variants or declaring the float params as u32 (registry mangled name wtarget_0017f3d8jjjj suggests four unsigned params), or C8-style temporaries.
