# 001d0068 blocked
- Range: 001d0068, 60 bytes. Versions tried: 6. Best: v3 with 2 differing words (60/60 bytes).
- First difference of the best version: !! 001d006c: ffbf0008  sd	ra,8(sp)  vs compiled sd s0,0(sp) (sd ra and sd s0 swapped; rest identical).
- Changes tried: v1 s64 callee return (11, adds dsll32/dsra32); v2 register u32 asm("$16") without barrier (13, delay slot filled); v3 barrier plus register $16 binding (2, best); v4 v3 plus +r guard on result (2); v5 v3 with void* callee return (2); v6 v3 with varargs callee (2).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the nop-slot comes from the barrier but the sd s0/sd ra order stays swapped; need a construct that makes ra saved before s0 (e.g. a local that forces a distinct frame layout) rather than another delay-slot change.
