# 001b0498 blocked
- Range: 001b0498, 64 bytes. Versions tried: 7. Best: v4 with 3 differing words (64/64 bytes).
- First difference of the best version: !! 001b04b4: 55e00006  bnezl	t7,0x1b04d0  vs  bnez t7 (non-likely); also 001b04c8 bnezl+li v0,1 vs beqzl+move v0,zero.
- Changes tried: v1 result var (6); v2 temp for flags (6); v3 volatile flags read (6); v4 early returns (3); v5 early return plus result var (6); v6 inverted nesting (9); v7 v4 with volatile flag byte (3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C8 try different shape yielding branch-likely with li v0,1 in delay slots, e.g. result initialised to 1 and cleared (result = 0) on the fall-through paths, or a goto-shared epilogue.
