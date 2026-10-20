# 001e2ad8 blocked
- Range: 001e2ad8, 116 bytes. Versions tried: 1. Best: v1 with 3 differing words (116/116 bytes).
- First difference of the best version: !! 001e2b10: 0220282d  move	a1,s1  (compiled: move a2,s0 first, a1,s1 second); also 001e2b30 original 'break' (0x0000000d) vs compiled 'teq zero,zero' from __builtin_trap.
- Changes tried: v1 straight translation with __builtin_trap for the never-returning tail: 3 words.
- Why it stops here: the original ends in 'break 0' after the last call; the compiler's only trap builtin emits 'teq', and no accepted source shows a 'break 0' sequence, so exact needs instruction-emitting asm (forbidden by the manual).
- Next hypothesis: find an accepted source that produces 'break 0' (a library-style abort or asm primitive) and copy it; then swap a1/a2 argument move order with a temp variable (C11).
