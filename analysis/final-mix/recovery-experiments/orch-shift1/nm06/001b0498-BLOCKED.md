# 001b0498 blocked
- Range: 001b0498, 64 bytes. Versions tried: 8. Best: v5 with 3 differing words (64/64 bytes).
- First difference of the best version: !! 001b04b4: 55e00006  bnezl t7,0x1b04d0 (original) vs bnez t7 (non-likely); also 001b04c8 bnezl+li v0,1 vs beqzl+move v0,zero.
- Changes tried: v1 result init 1 cleared on fall-through (16); v2 result var for last test only (6); v3 goto shared return (9); v4 result=1 in both branches (6); v5 owner local + early returns (3); v6 v5 with negated final test (3); v7 v5 with if/else nesting (9); v8 v5 with volatile flags read (3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the original has v0 preset to zero (move v0,zero in the beqz delay slot) and li v0,1 in both likely delay slots; try the owner pointer loaded through a volatile read, or an u8 flag local copy tested separately, to change how the scheduler fills delay slots.