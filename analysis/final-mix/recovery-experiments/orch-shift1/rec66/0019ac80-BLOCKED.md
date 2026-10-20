# 0019ac80 blocked
- Range: 0019ac80, 124 bytes. Versions tried: 8. Best: v6 with 1 differing word (124/124 bytes).
- First difference of the best version: !! 0019ace4: 0000682d  move	t5,zero  | compiled: 00000000  nop (delay slot of the loop-back bnez).
- Changes tried: C21 rewrite v1 (26); v2 result=0/1 inside loop (33); v3 register t5 binding (3); v4 result=1/break/result=0 loop (4); v5 plus result=0 before loop (4); v6 v3 plus count/inner temps and result=0 before compare (1); v7 v6 with loop result=1/break/result=0 (2); v8 v6 plus result=0 at loop end after the early return (15).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: make the loop-back delay slot hold move t5,zero, e.g. `result = 0` placed as the loop condition side effect, or `while ((result = 0, object->index < 200))`-style comma expression, or a for(;;) with explicit continue and result=0 before the index test.
