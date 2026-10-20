# 001a5928 blocked
- Range: 001a5928, 72 bytes. Versions tried: 6. Best: v3 with 2 differing words (72/72 bytes).
- First difference of the best version: !! 001a592c: ffbf0008  sd	ra,8(sp)  | 001a592c: ffb00000  sd	s0,0(sp)  (original saves ra then s0; compiled saves s0 then ra)
- Changes tried: plain version with u64/variadic declarations from accepted sibling (v1, 16 words: missing the nop in the delay slot of the first jal); void first callee (v2, 16); asm memory barrier before the first call (v3, 2); plain asm volatile (v4, 2); barrier after first call (v5, 2); barriers before and after (v6, 2).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C12/prologue - find a source form that yields the empty delay slot after the first jal without changing the prologue store order (ra before s0); e.g. make the first call's result a dead u64 local, or declare func_001c70e8 with (...).
