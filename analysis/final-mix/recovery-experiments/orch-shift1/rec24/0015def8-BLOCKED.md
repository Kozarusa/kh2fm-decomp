# 0015def8 blocked
- Range: 0015def8, 112 bytes. Versions tried: 5. Best: v2 with 2 differing words (112/112 bytes).
- First difference of the best version: !! 0015df48: 8e2db244  lw t5,-19900(s1) | compiled 8e2eb244 lw t6,-19900(s1) (and the dependent sb base register t5 vs t6 at 0015df54).
- Changes tried: v1 same pattern as exact sibling 0015de98 with register bindings $15/$14 (4 words, store order of sw D_0034b244 vs lw wrong); v2 asm memory barrier after the D_0034b244 store fixed order (2 words); v3 bind reloaded pointer to $13 (3 words, prologue sd order changed); v4 declare $13 binding at top (3); v5 add asm +r on it (5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: obtain t5 for the final reload without a register binding that disturbs the prologue sd order (for example keep a different dead temporary live in t6, or restructure the final store as a separate inline pointer copy).
