# 0016d230 blocked
- Range: 0016d230, 76 bytes. Versions tried: 8. Best: v5 with 2 differing words (76/76 bytes).
- First difference of the best version: !! 0016d26c: adc06290  sw	zero,25232(t6)   ; = D_004f6290 | 0016d26c: ade00004  sw	zero,4(t7)
- Changes tried: v1 two globals (4 words); v2 pointer to D_004f6290, D store then p[1] (4); v3 pointer to D_004f6294 (4); v4 pointer at function top (9); v5 p[1] store first then D store (2, only the last two stores swapped); v6 volatile D (4); v7 volatile pointer (4); v8 array decl (4).
- Why it stops here: budget reached (8 versions); 3 versions without improvement.
- Next hypothesis: C10(d) asm volatile memory barrier between the two stores in the v5 layout so the addiu stays first but D store precedes p[1]; or C10(b) other store-order tricks.