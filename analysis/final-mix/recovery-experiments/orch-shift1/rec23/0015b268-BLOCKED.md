# 0015b268 blocked
- Range: 0015b268, 100 bytes. Versions tried: 7. Best: v1 with 4 differing words (100/100 bytes).
- First difference of the best version: !! 0015b2ac: 3c0e0035  lui	t6,0x35 | 0015b2ac: 3c0f0035  lui	t7,0x35
- Changes tried: v1 plain (4); v2 volatile global pointer (8, moves a1 copy); v3 asm memory clobber (12, loses tail call); v4 u32 global with casts (4, same as v1); v5 volatile read only on final arg (5); v6 compile error; v7 local pointer + volatile final read (5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original reloads D_0034aa9c after the swc1 with t6/t7 swapped; try aliasing via a struct typed global with f32 member, or a union to prevent CSE of the second load without changing register assignment.
