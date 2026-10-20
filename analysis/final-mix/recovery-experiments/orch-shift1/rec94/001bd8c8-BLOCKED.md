# 001bd8c8 blocked
- Range: 001bd8c8, 80 bytes. Versions tried: 5. Best: v2 with 8 differing words (80/80 bytes).
- First difference of the best version: !! 001bd8cc: ffbf0008  sd	ra,8(sp)  | compiled sd s0,0(sp)
- Changes tried: v1 plain call = 13 words (tail call j emitted); v2 asm memory barrier after the call to force jal = 8 words; v3 swapped addu operand order in source = 8 (no effect, canonicalized); v4 sibling-style varargs declarations = 8; v5 u32 object parameter = 8.
- Remaining diffs: ra/s0 save order (original ra first, then lw before move s0,a0), addu t5,t5,t7 vs addu t7,t7,t5 with lhu via t5, and move a0,s0 before move a1,v0.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 register binding of the table base to t5 ($13) so addu writes t5 (or C12 variant giving different prologue scheduling).
