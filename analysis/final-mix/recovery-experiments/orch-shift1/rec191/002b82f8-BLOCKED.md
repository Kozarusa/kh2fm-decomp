# 002b82f8 blocked
- Range: 002b82f8, 124 bytes. Versions tried: 4. Best: v1 with 28 differing words (108/124 bytes).
- First difference of the best version: `!! 002b82fc: ffbe0020  sd\ts8,32(sp)                                     | 002b82fc: 3c0f01e2  lui\tt7,0x1e2`
- Changes tried: C1 eight-argument call reconstruction, 28 words; C1 add ninth stack argument, 30 words; C1 use SDK variadic callee declaration, 30 words; C19 explicit frame transport, 28 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: eliminate s0/s1 loop-invariant address caching while retaining the nine-argument call and explicit frame transport, then restore sp from s8.
