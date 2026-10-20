# 001e2c00 blocked
- Range: 001e2c00, 92 bytes. Versions tried: 1. Best: v1 with 11 differing words (88/92 bytes).
- First difference of the best version: !! 001e2c28: 3c050037  lui	a1,0x37 (compiled lui a0 first); the trap word 001e2c40 is original 'break' (0x0000000d), compiled 'teq zero,zero' from __builtin_trap.
- Changes tried: v1 straight translation with __builtin_trap and a tail-call return of func_001e7cc0: 11 words. The original calls func_001e7cc0 with jal and returns void (not a tail call), so v1 return type was also wrong.
- Why it stops here: the original has 'break 0' after the second call; the compiler trap builtin emits 'teq' and no accepted source shows a 'break 0' sequence, so exact needs instruction-emitting asm (forbidden by the manual).
- Next hypothesis: find an accepted break-0 primitive and copy it; make the function void with a non-tail call to func_001e7cc0, then fix lui a0/a1 ordering of the second call's argument setup.
