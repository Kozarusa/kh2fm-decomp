# 001be4e0 blocked
- Range: 001be4e0, 92 bytes. Versions tried: 6. Best: v3 with 9 differing words (92/92 bytes).
- First difference of the best version: !! 001be4e4: 240f0074  li	t7,116  | compiled sd s0,0(sp) (original li t7,116 first, then sd s0, sd ra; mult a0,a1,t7; compiled uses li a0,116 after move s0,a0).
- Changes tried: v1 inline call args (23 words, 96 bytes); v2 reorder store after table load (23); v3 entry pointer computed first as a local (9, best); v4 entry expression order +0x24 first (9); v5 field loaded into a local before call (9); v6 struct array access Entry[index] (9).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 register binding or an extra temp so the 116 constant lands in t7 (li t7,116 before the sd saves) and lw t6/t7 chain follows mult; try a 64-bit object parameter (C20).
