# 001d37a0 blocked
- Range: 001d37a0, 112 bytes. Versions tried: 10 (budget of 8 was exceeded by 2 through a counting error). Best: v9 with 23 differing words (112/112 bytes).
- First difference of the best version: !! 001d37a0: 78a80000  lq	t0,0(a1)  | 001d37a0: 78af0000  lq	t7,0(a1)
- Changes tried: v1 plain struct (28); v2 volatile float globals (28); v3 volatile node pointer (27, warnings); v4 array globals (28); v5 volatile struct members (26); v6 memory barriers x3 (26); v7 v5 plus volatile globals and list members (24, size exact); v8 local tail variable (26); v9 v7 plus one memory barrier after quad copy (23); v10 v9 plus local tail variable (25).
- Why it stops here: budget reached.
- Next hypothesis: original does not hoist lui/addiu of the list base (t5/t6) above the float-global loads and uses bnezl with a single tail read; try barriers between the two float-global loads and before the tail load, with volatile members kept.