# 001dcb98 blocked
- Range: 001dcb98, 104 bytes. Versions tried: 4. Best: v1 with 22 differing words (96/104 bytes).
- First difference of the best version: !! 001dcba4: 25efe7e8  addiu	t7,t7,-6168   ; = D_0036e7e8 | 001dcba4: 03a0602d  move	t4,sp
- Changes tried: v1 f32 array + Quad lq/sq copy (22 words); v2 pointer to D_ array before the load (22); v3 read global inside the loop expression (22); v4 aligned struct with struct assignment (22).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps address in t7 (addiu then lwc1 0(t7)) so address is a pointer-valued global/array element or a struct base used elsewhere; also epilogue is duplicated (ld ra in beq delay slot), implying the copy block is separate from a shared return; try volatile read of the pointer (C9) or register binding of the copy temp (t0, $8) per C11.
