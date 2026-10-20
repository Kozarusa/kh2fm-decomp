# 001eaee0 blocked
- Range: 001eaee0, 108 bytes. Versions tried: 8. Best: v5 with 4 differing words (108/108 bytes).
- First difference of the best version: !! 001eaf10: c60000a0  lwc1	$f0,160(s0) | 001eaf10: 8e2fe6e8  lw	t7,-6424(s1)
- Changes tried: v1 plain (11 words); v2 volatile global pointer C9 (6); v3 volatile source reads (10); v4 struct member form (6); v5 volatile dest members C10c (4); v6 temp for first float (4); v7 volatile source on v5 (4); v8 temp base pointer (4).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original loads the source float before the global pointer and schedules ld s0 before ld ra; try making the first store go through a separate non-volatile typed pointer, or C10d barrier between the call and the first load.
