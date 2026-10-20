# 002a7678 blocked
- Range: 002a7678, 92 bytes. Versions tried: 5. Best: v2 with 2 differing words (92/92 bytes).
- First difference of the best version: !! 002a767c: ffbf0008 sd ra,8(sp) | 002a767c: ffb00000 sd s0,0(sp).
- Changes tried: v1 fresh preserving callee return 21; C12/C11(d) v2 entry memory barrier 2; C11(b) v3 system temporary 2; C11(c) v4 original s0 binding 2; C11(d) v5 ra clobber on existing entry barrier 21.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C12 scheduling alternative that preserves the original ra-before-s0 prologue while keeping the first call delay slot empty.
