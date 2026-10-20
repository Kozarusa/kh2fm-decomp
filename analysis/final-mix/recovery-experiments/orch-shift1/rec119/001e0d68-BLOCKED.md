# 001e0d68 blocked
- Range: 001e0d68, 92 bytes. Versions tried: 7. Best: v4 with 16 differing words (92/92 bytes).
- First difference of the best version: !! 001e0d70: 8d8d2bd0  lw	t5,11216(t4)   ; = D_00352bd0 | 001e0d70: 8d8e2bd0  lw	t6,11216(t4)   ; = D_00352bd0
- Changes tried: v1 volatile s32 global and volatile casts (20); v2 plus f32 temporaries (21); v3 union Word accesses, D as Word* (22, reload of D missing); v4 D as a Word union global (16, the reload pattern now matches); v5 Ent array indexing (16, same code); v6 no temporaries (20); v7 swapped add operands (16, same).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: all remaining diffs are register numbers (C11): original keeps D in t5, table in t6, address in t6 (addu t6,t6,t7) and loads $f0 after the sll, $f1 after the table load, $f2 after the addu; try C11(c) register bindings of the table value to t6/t5 or a different temporary structure.
