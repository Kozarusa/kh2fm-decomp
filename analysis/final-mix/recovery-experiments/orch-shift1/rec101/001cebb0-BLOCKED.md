# 001cebb0 blocked
- Range: 001cebb0, 88 bytes. Versions tried: 4. Best: v1 with 2 differing words (88/88 bytes).
- First difference of the best version: !! 001cebdc: 24040001  li	a0,1  | 001cebdc: 24c6ec08  addiu	a2,a2,-5112 (li a0 and addiu a2 swapped, only 2 words).
- Changes tried: v2 CreateTask declared (u64,u64,u8*) 2 words; v3 callback pointer in a local before the global store (C11b) 2 words; v4 memory barrier after the global store (C10d) 6 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 make the first CreateTask argument or the callback address a volatile read, or declare the global D_003521d0 as a pointer type.
