# 0016b740 blocked
- Range: 0016b740, 96 bytes. Versions tried: 8. Best: v4 (also v5, v8) with 4 differing words (96/96 bytes).
- First difference of the best version: !! 0016b790: 51f0fff3  beql	t7,s0,0x16b760 | 0016b790: 15f0fffa  bne	t7,s0,16b77c
- Changes tried: v1 plain (23 words); v2 s64 id param + s32 callee return (19); v3 result=D;if(id!=0x236) form (22); v4 early return plus for(;;) with breaks (4); v5 do-while with break (4); v6 while(node=f(node)) return inside (9); v7 returns inside for(;;) (19); v8 continue form (4).
- Why it stops here: budget reached (8 versions). Only the loop tail differs: original ends the loop with beql t7,s0 (delay slot holds the epilogue ld s0) then a separate b back to the loop head; compiled uses bne + nop + b to epilogue.
- Next hypothesis: make the compare a branch-likely candidate: read *(node+8) through a volatile pointer (C8c/C9) or write the compare as a value-in-temporary (C8a) so the epilogue ld s0 fills the delay slot.
