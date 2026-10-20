# 001d0068 blocked
- Range: 001d0068, 60 bytes. Versions tried: 5. Best: v2 with 2 differing words (60/60 bytes).
- First difference of the best version: !! 001d006c: ffbf0008  sd	ra,8(sp)  | compiled: ffb00000 sd s0,0(sp) (prologue sd s0 and sd ra swapped; rest identical).
- Changes tried: v1 plain (13 words, sd s0 filled the first jal delay slot); v2 asm memory barrier before first call (2 words); v3 barrier after first call (2 words); v4 varargs callee declaration (13 words); v5 empty asm volatile before first call (2 words).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: need nop in first jal delay slot while keeping sd ra before sd s0 (e.g. different callee return type for 001d01e0, or a different construct than asm to stop delay-slot fill).