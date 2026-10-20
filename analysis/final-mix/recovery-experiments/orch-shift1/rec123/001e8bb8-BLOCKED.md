# 001e8bb8 blocked
- Range: 001e8bb8, 108 bytes. Versions tried: 5. Best: v2 with 3 differing words (108/108 bytes).
- First difference of the best version: !! 001e8bec: 240603d6  li	a2,982 | 001e8bec: 2484ef98  addiu	a0,a0,-4200 (li a2 vs addiu a0 order swapped before the second call).
- Changes tried: v1 baseline 8 words; v2 asm memory barrier after last call to stop tail call (C13) 3 words; v3 line local 3 words; v4 pointer temps 3 words; v5 asm guard on line 3 words (shifted the swap earlier).
- Why it stops here: no improvement for 3 versions. Also the original `break` cannot be emitted (__builtin_trap gives teq), so the target cannot be exact without instruction-emitting asm.
- Next hypothesis: the final `break` needs instruction-emitting asm (not allowed); the li/addiu schedule swap may need a different argument expression form.