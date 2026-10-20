# 0020f188 blocked
- Range: 0020f188, 88 bytes. Versions tried: 8. Best: v5 with 7 differing words (88/88 bytes).
- First difference of the best version: !! 0020f190: ffbf0008  sd	ra,8(sp)   | 0020f190: ffb00000  sd	s0,0(sp)
- Changes tried: C13 asm volatile at end (17 -> 9), C10 memory barrier (10), drop temps (9), swap statement order (7), local dest pointer (7), asm guard on dest (11), volatile dest (9).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: prologue saves ra before s0 and original schedules lui s0 after the two ld; try register binding of s0 (C11c) or a different callee declaration signature (e.g. pointer arg types) to change scheduling.
