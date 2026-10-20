# 0021f060 blocked
- Range: 0021f060, 120 bytes. Versions tried: 8. Best: v8 with 9 differing words (120/120 bytes).
- First difference of the best version: !! 0021f090: a0800028  sb	zero,40(a0)   | 0021f090: 018f6021  addu	t4,t4,t7
- Changes tried: v1 plain pointers (26), v2 typed structs (26), v3 volatile object accesses C10c (19), v4 volatile reload of base after offset read C9 (13), v5 u16 flags temp read first (21), v6 register-bind base to t3 C11c (11), v7 u32 flags temp (20), v8 register-bind table to t4 C11c (9).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: remaining 9 words are only the order of sb 40 vs addu, and the flags sequence (original: lhu flags, li 18, lw D, ori, sw 36, sh 18, sh 28 with D in t5, flags in t6); try binding the D temp to t5 and flags to t6 (C11c) and a non-volatile read order (C9) for D so the lw D lands after lhu.
