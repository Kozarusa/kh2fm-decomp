# 001682b8 blocked
- Range: 001682b8, 52 bytes. Versions tried: 7. Best: v2 with 2 differing words (52/52 bytes).
- First difference of the best version: !! 001682bc: ffbf0008  sd	ra,8(sp)  | 001682bc: ffb00000  sd	s0,0(sp)  (ra and s0 saves swapped; the rest is exact).
- Changes tried: v1 plain s64 (11, sd s0 filled the jal delay slot); v2 asm memory barrier before first call (2, best); v3 + register s0 binding (2); v4 plain asm volatile (2); v5 two barriers (2); v6 barrier clobbering $16 (6, sq frame); v7 u64 types (2).
- Why it stops here: no improvement for 3 versions (5 actually).
- Next hypothesis: find a construct that keeps the nop delay slot without reordering the prologue saves (ra then s0), e.g. a volatile local read or the callee declared via a different return type/variadic (C9/C10).
