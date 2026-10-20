# 001e2660 blocked
- Range: 001e2660, 84 bytes. Versions tried: 7. Best: v4 with 3 differing words (84/84 bytes).
- First difference of the best version: !! 001e2674: 51e50004  beql	t7,a1,0x1e2688  vs compiled beq t7,a1 (also lq/sq use t7/160(a0) instead of lq t0,0(a1); sq t0,0(t7)).
- Changes tried: v1 do-while 22 words; v2 for-loop 5; v3 destination pointer var 5; v4 rotated zero stores (174,175,172,173) 3; v5 temp Quad value 3; v6 volatile quad read 3; v7 aligned struct copy 3.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: make the copy emit beql with lq into t0 and sq through the t7 address register (e.g. a different pointer form, or conditional expression such as the compare against the destination pointer written as source != dest with else-less structure).
