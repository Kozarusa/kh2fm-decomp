# 002b6ab8 blocked
- Range: 002b6ab8, 36 bytes. Versions tried: 7. Best: v5 with 5 differing words (32/36 bytes).
- First difference of the best version: `!! 002b6ac8: 01e0102d  move v0,t7 | 002b6ac8: dfbe0000  ld s8,0(sp)`
- Changes tried: C1 plain zero return, 9 words; C19 unused frame address, 9 words; C19 frame-transport binding, 6 words; C11 t7 binding, 6 words; C11 t7 guard, 5 words; C11 v0 binding, 5 words; C11 v0 guard, 5 words.
- Why it stops here: orchestrator stop at 90% usage.
- Next hypothesis: C19 explicit frame restoration before the epilogue, copied from accepted 002b6b84, while preserving the guarded t7 and v0 transports.
