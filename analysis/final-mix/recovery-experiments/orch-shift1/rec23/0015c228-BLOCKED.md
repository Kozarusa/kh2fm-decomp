# 0015c228 blocked
- Range: 0015c228, 84 bytes. Versions tried: 6. Best: v2 with 2 differing words (84/84 bytes).
- First difference of the best version: !! 0015c26c: 3c0e0035  lui	t6,0x35 | 0015c26c: 3c0f0035  lui	t7,0x35 (and the final sw uses t5,-20700(t6) vs t5,-20700(t7)).
- Changes tried: v1 plain (14); v2 quotient into temp, af30 store after it (2); v3 pointer temp for af24 (2); v4 asm +r on count (10); v5 volatile D_0034af30 (2); v6 temp for base (2).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the original keeps a fresh lui t6 for the D_0034af24 store; try making D_0034af24 and D_0034af30 separate-section/array-member globals, or a register-binding (C11c) of the address through an asm-typed pointer.
