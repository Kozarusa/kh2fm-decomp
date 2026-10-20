# 001bfd60 blocked
- Range: 001bfd60, 60 bytes. Versions tried: 8. Best: v5 with 4 differing words (60/60 bytes).
- First difference of the best version: !! 001bfd6c: 0080102d  move	v0,a0 | compiled beq t7,a1 first, move v0,a0 in its delay slot (original: move v0,a0 then beq with xori in delay slot). Also slti t7,t5,8 / bnez t7 in original vs t6 in compiled.
- Changes tried: v1 natural loop (13 words, 56 bytes, no xori); v2 (value ^ 0) == 0 (13, folded); v3 ternary temp (13); v4 inline asm xori with "=r" (7); v5 "=&r" early clobber (4, best); v6 asm volatile (10); v7 register $15 bound loop flag (10); v8 separate found temp (4, no gain).
- Note: the original xori t6,t7,0 survives only through an emitted asm primitive; a pure C++ form that keeps it was not found, so even an exact match would need asm.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: find a C++ expression that keeps xori with 0 (for example a volatile or union typed flag) and tune delay-slot fill by reordering the return pointer copy.
