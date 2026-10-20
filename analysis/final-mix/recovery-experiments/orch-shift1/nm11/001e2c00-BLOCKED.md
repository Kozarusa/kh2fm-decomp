# 001e2c00 blocked
- Range: 001e2c00, 92 bytes. Versions tried: 4. Best: v4 with 1 differing word (92/92 bytes).
- First difference of the best version: !! 001e2c40: 0000000d  break  vs compiled 00000034 teq zero,zero (trap only: __builtin_trap cannot emit break).
- Changes tried: v1 void + non-tail call via memory barrier (6 words); v2 local for second pointer (6); v3 empty guard on pointer (3); v4 empty guard on constant 357 (1, trap only).
- Why it stops here: R3 privileged condition; the only remaining word is the break trap.
- Next hypothesis: an accepted break-0 primitive is needed; none exists, so the trap word cannot be produced without instruction asm.
