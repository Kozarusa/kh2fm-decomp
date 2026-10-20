# 002342f0 blocked
- Range: 002342f0, 88 bytes. Versions tried: 7. Best: v4 with 10 differing words (88/88 bytes).
- First difference of the best version: !! 002342f0: 3c0a0036 lui t2,0x36 | 002342f0: 3c0c0036 lui t4,0x36.
- Changes tried: C11 load reorder v2: 11 words; address temporaries v3: 11 words; initialized register bindings v4: 10 words; cursor guard v5: 21 words; sequence guard v6: 18 words; result guard v7: 12 words. Baseline v1: 11 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10 volatile stores may prevent the parameter store from moving after the global stores.