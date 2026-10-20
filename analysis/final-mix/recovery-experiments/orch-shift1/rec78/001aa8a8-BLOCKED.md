# 001aa8a8 blocked
- Range: 001aa8a8, 72 bytes. Versions tried: 7. Best: v4 with 9 differing words (72/72 bytes).
- First difference of the best version: !! 001aa8ac: 00a0702d  move	t6,a1 | 001aa8ac: 0080782d  move	t7,a0
- Changes tried: v1 plain void call, 14 words (tail call j emitted). v2 callee returns s32, 14 (still tail call). v3 variadic u64 callee, 16 (worse). v4 empty asm memory barrier after call blocks tail call, 9 (best, only prologue register/ordering differ). v5 temporaries pointer/second/first/head, 16. v6 u64 params, 9. v7 temporaries for pointer and second float, 10.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind object copy to t7 and a1 copy to t6 with register asm("$15")/("$14") and reorder so move t6,a1 comes first; original loads f13 and a1=a0+64 from a0 but f12 from t7.
