# 00167c30 blocked
- Range: 00167c30, 96 bytes. Versions tried: 8. Best: v5 with 5 differing words (96/96 bytes).
- First difference of the best version: !! 00167c38: 3c0e0035  lui	t6,0x35  | 00167c38: 25efd6c0  addiu	t7,t7,-10560  (only the scheduling order of the prologue lui/addiu/li differs; 5 words, all in instructions 2..6).
- Changes tried: v1 plain pointer loop (24, loop unrolled, 72 bytes); v2 asm nop/nop in loop keeps it rolled (20); v3 struct-array indexed (19); v4 pointer to member (18, regs right); v5 opaque base via asm "+r" gives separate +68 addiu (5, best); v6 source declared first (5); v7 asm +r on source (5); v8 asm +r on index (5).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C10/C11 style reorder of the prologue materialization, e.g. asm +r on source placed before base, or compute slot base from source-independent expression, so the order is lui base, lui source, addiu base, addiu source, addiu 68, li.
