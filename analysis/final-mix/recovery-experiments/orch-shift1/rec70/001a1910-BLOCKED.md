# 001a1910 blocked
- Range: 001a1910, 64 bytes. Versions tried: 4. Best: v1 with 13 differing words (60/64 bytes).
- First difference of the best version: !! 001a191c: 8c8f0008  lw	t7,8(a0)                                      | 001a191c: 8c8e0000  lw	t6,0(a0)
- Changes tried: v1 void clamp, 13 words. v2 return s32 result and load entry[2] first, 13 words (v0 now matches but load/scheduling differs). v3 separate low/result variables, 13 words. v4 volatile read of entry[2], 13 words (reordered but extra move).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C9/C10 variants: make entry[0] load volatile and entry[2] plain so lw 8(a0) is first and copied to v0 via move; or explore the original delay-slot nop (branch not filled) with a volatile store ordering.
