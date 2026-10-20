# 001735b0 blocked
- Range: 001735b0, 92 bytes. Versions tried: 8. Best: v8 with 10 differing words (88/92 bytes).
- First difference of the best version: !! 001735e4: 25eff480  addiu	t7,t7,-2944   | 001735e4: 25eef480  addiu	t6,t7,-2944
- Changes tried: v1 compile error; v2 plain `*p = f()` 23 (extra s regs, no self check); v3 explicit temp + address compare 11; v4 if/else duplicated tail 12+; v5 Quad return type 23 (wrong ABI); v6 operator= with this!=&other self-check, temp then assign 11; v7 object->target = &(D = temp) 11; v8 asm pin on pointer 10.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C11: original keeps D address in t7 (lui t7; addiu t7,t7) with beql sp,t7 and sw in its delay slot and quad via t0; try making the pointer addiu target the same register (register Vec4* asm("$15")) plus quad temp bound to $8, and a branch-likely shape from the if/else duplicate of the sw.