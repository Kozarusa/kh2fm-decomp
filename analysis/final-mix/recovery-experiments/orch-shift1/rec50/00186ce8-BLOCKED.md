# 00186ce8 blocked
- Range: 00186ce8, 44 bytes. Versions tried: 5. Best: v2 with 8 differing words (40/44 bytes).
- First difference of the best version: !! 00186cf0: 11e00006  beqz	t7,0x186d0c  vs compiled beqz t7,186d08 (original has an extra xori t7,t7,0 and loads value into t6, compiled loads into t7).
- Changes tried: v1 plain nested ifs (10 words); v2 inner pointer s32* at object+0x140 (8, a0 addiu now matches); v3 C8 separate low/high temps with ^0 (8, movn); v4 ternary (8, movz swapped regs); v5 asm barrier on low, ternary (8, right regs order wrong: high computed before low).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 bind value to $14 and low to $15, and emit the lone xori t7,t7,0 via asm (C11c/d) so slti low comes before slti high.
