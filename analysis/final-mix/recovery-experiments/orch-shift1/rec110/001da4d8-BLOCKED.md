# 001da4d8 blocked
- Range: 001da4d8, 124 bytes. Versions tried: 11. Best: v8 with 9 differing words (124/124 bytes).
- First difference of the best version: !! 001da4ec: 01e27821  addu	t7,t7,v0                                    | 001da4ec: 25ce0001  addiu	t6,t6,1
- Changes tried: v1 if-chain (26); v2 switch (27, wrong size); v3 single variable base/result (26); v4 negate kind!=1 (19); v5/v6 kind==0 block as result=0 then conditional (19, no effect); v7 negate kind!=2 and kind!=0 tests (10); v8 kind as s32 (9); v9 result=0 then conditional (9); v10 ternary (9); v11 position temp (9).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: remaining 9 words are two scheduling clusters: (a) sw object[1] sits in the beq delay slot and li uses t7 (original) vs sw before li with t6 (compiled); (b) kind==0 block is beqzl with lw in the delay slot (original) vs bnez with move v0,zero in the delay slot; try volatile read of object[2] in the kind==0 arm (C8c/C9) or asm memory barrier after the object[1] store (C10d).
