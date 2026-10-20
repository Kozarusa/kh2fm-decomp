# 001e3c18 blocked
- Range: 001e3c18, 128 bytes. Versions tried: 5. Best: v1 with 25 differing words (compiled 128/128 bytes in v3/v5, v1 ended with tail call j).
- First difference of the best version: !! 001e3c30: 8492009c  lh s2,156(a0) | 001e3c30: 8491009c  lh s1,156(a0)
- Changes tried: v1 plain chain, 25 words (prologue matched; s1/s2 swapped for the two lh values, last call became a tail call j). v2 u64 arg for 3650 plus load order 156,136,158, 29 words (prologue order changed: s0 stored before ra, lwu). v3 u32 arg, load order, memory barrier after last call to stop tail call (C13 reverse), 29 words, tail call fixed. v4 compile error (stray backslash in generated source). v5 declaration order handle,158,156, 29 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: keep v1 loads but get the original sd ra-first prologue and lh s2=156/s1=158 pairing (C11 register binding or a non-void return type so the last call is not a tail call, C12/C13).
