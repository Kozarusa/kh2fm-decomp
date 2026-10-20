# 0016f6f8 blocked
- Range: 0016f6f8, 120 bytes. Versions tried: 6. Best: v2 with 22 differing words (compiled size differs from target 120; v2 uses early return for the first test).
- First difference of the best version: !! 0016f6f8: 3c0e4000  lui	t6,0x4000 | 0016f6f8: 27bdfff0  addiu	sp,sp,-16
- Changes tried: v1 nested form with initial result=0 (27 words; result lives in s0 across call, sltiu); v2 early return plus signed s32 kind (22, slti now matches); v3 nested form with s32 kind (26); v4 if/else assignment form (23); v5 return-chain form (24); v6 u64 id and u64 callee declaration (32).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps the result in t6 with separate result=0 blocks for kind==0x16 and kind==0x18 (blocks placed after the epilogue, branching back) and lui scheduled before addiu sp; try a switch on kind with explicit separate cases, or goto-based join blocks, and a mask held in a variable to move the lui first.