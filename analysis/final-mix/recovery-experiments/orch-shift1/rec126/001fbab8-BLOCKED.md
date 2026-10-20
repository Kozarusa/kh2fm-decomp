# 001fbab8 blocked
- Range: 001fbab8, 100 bytes. Versions tried: 4. Best: v1 with 17 differing words (100/100 bytes).
- First difference of the best version: !! 001fbac8: 0000282d  move	a1,zero | 001fbac8: afab0014  sw	t3,20(sp)
- Changes tried: v1 local Args struct (17); v2 Ghidra statement order (18); v3 inner as s32 (17); v4 volatile struct (17).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: same argument-block shape as blocked 001fb508/001fb8b8; find the source shape that delays sw inner,20(sp) and keeps move t6,a0 early (possibly a copy of object into a second variable).
