# 001f0430 blocked
- Range: 001f0430, 44 bytes. Versions tried: 7. Best: v4 with 3 differing words (44/44 bytes).
- First difference of the best version: !! 001f043c: c4820014  lwc1	$f2,20(a0)  | 001f043c: c4810014  lwc1	$f1,20(a0)
- Changes tried: C4 float zero via empty asm guard (11 -> 6); memory barrier (6, no effect); C10 rotate zero stores (6 -> 3); drop temp (3); two temps (6); guard on first temp (5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 bind second load to $f2 via register f32 name asm("$f2") or different statement ordering so the 16(a1) store precedes the 8(a1) zero store.