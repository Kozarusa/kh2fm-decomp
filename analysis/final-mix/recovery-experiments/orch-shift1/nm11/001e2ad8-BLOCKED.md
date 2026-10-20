# 001e2ad8 blocked
- Range: 001e2ad8, 116 bytes. Versions tried: 4. Best: v1 with 3 differing words (116/116 bytes).
- First difference of the best version: !! 001e2b10: 0220282d  move	a1,s1  vs compiled move a2,s0 (a1/a2 moves swapped; also the final break vs teq from __builtin_trap).
- Changes tried: v1 temporaries for second/third (C11b) 3 words; v2 empty guard on third after first call (C11d) 3; v3 guard on second 7 (worse, saved regs swapped); v4 guard on both 3.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11c bind second to $17 and third to $16 with register asm and why comments; the break word cannot be produced anyway.
