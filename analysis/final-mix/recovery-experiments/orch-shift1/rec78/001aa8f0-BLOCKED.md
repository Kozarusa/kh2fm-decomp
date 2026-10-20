# 001aa8f0 blocked
- Range: 001aa8f0, 76 bytes. Versions tried: 8. Best: v5 with 8 differing words (76/76 bytes).
- First difference of the best version: !! 001aa8f4: 00a0702d  move	t6,a1 | 001aa8f4: 0080782d  move	t7,a0
- Changes tried: v1 void call + empty asm barrier (blocks tail call), 17 words (72 bytes). v2 u64 params, 17. v3 local for object[14], 12 words (76 bytes). v4 register asm bindings for a,b,c to t6,t5,t4 without asm use, 12 (ignored). v5 added asm "+r" after each binding (C11 d), 8 words (best). v6 also bound object and d, 17. v7 bound d to t1, 10. v8 v5 plus pointer local, 8.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: only scheduling order differs (original emits move t6,a1 first, then t7, addiu a1, f13 load, t1 move, lw t2, lw a0, f12 load last); try binding object via asm and reordering the asm statements, or placing the barrier differently.
