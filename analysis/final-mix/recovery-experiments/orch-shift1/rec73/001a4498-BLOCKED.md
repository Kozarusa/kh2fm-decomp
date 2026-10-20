# 001a4498 blocked
- Range: 001a4498, 120 bytes. Versions tried: 8. Best: v6 with 5 differing words (120/120 bytes).
- First difference of the best version: !! 001a44c4: 25ef0778  addiu	t7,t7,1912   ; = D_00350778  | 001a44c4: 260e0100  addiu	t6,s0,256
- Changes tried: C4 f32 value+vector stores (v2, 10); C9 volatile float read (v3, 10); C10c volatile zero stores 0x32/0x31 (v4, 8); volatile 0x33 store (v5, 10, with bad float order); C10a vector stores in index order 0,1,2,3 (v6, 5); volatile 0x33 on v6 (v7, 7); volatile vtable store on v6 (v8, 8).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C10 - the remaining difference is the scheduling of lwc1 200(s0) / sw 204 / vtable store; try making object[0x31..0x33] a single volatile struct write order, or an asm memory barrier (C10d) after the 196 store.
