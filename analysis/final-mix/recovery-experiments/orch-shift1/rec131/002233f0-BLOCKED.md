# 002233f0 blocked
- Range: 002233f0, 88 bytes. Versions tried: 2. Best: v2 with 1 differing word (88/88 bytes).
- First difference of the best version: !! 00223430: 0000000d  break | 00223430: 00000034  teq	zero,zero
- Changes tried: v1 plain two calls, 12 words (second call became tail j); v2 added __builtin_trap() after the calls, 1 word (only trap encoding differs).
- Why it stops here: R3 break-trap rule: the trap is the last difference; __builtin_trap emits teq, and break 0 needs instruction-emitting asm which is forbidden.
- Next hypothesis: find a non-asm construct that makes ee-g++ emit break 0 (for example an abort-style intrinsic), or allow a precedent break asm primitive.
