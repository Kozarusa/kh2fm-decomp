# 00239f18 blocked
- Range: 00239f18, 92 bytes. Versions tried: 5. Best: v2 with 2 differing words (92/92 bytes).
- First difference of the best version: !! 00239f1c: c4800134  lwc1	$f0,308(a0)                                 | 00239f1c: e48c0138  swc1	$f12,312(a0)
- Changes tried: v1 scalar source 23 words; v2 C11 pointer temporary and empty guard 2 words; v3 C9 volatile x load 2 words; v4 C10(c) volatile y store 7 words; v5 C10(d) x/y dependencies on pointer guard 5 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(d), use a memory barrier between the x load and y store from best v2.
