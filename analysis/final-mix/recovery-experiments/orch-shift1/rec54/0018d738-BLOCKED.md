# 0018d738 blocked
- Range: 0018d738, 84 bytes. Versions tried: 6. Best: v2 with 4 differing words (84/84 bytes).
- First difference of the best version: !! 0018d754: 3c060019  lui	a2,0x19 | 0018d754: 3c0e01c6  lui	t6,0x1c6
- Changes tried: v1 array D_01c60cd8[0..1] (5 words); v2 two scalar globals (4); v3 pointer var + direct first store (5); v4 all stores through pointer (5); v5 asm pin of pointer (6); v6 volatile pointer (6).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original computes t6=&D_01c60cd8 (addiu t6,t7) before the first store, then sw 0(t7) and sw 4(t6): try a struct-typed global with pointer to member, or register binding of pointer to $14 (C11c).
