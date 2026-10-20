# 002b99a0 blocked
- Range: 002b99a0, 40 bytes. Versions tried: 6. Best: v3 with 2 differing words (40/40 bytes).
- First difference of the best version: `!! 002b99ac: 3c0f01e3  lui\tt7,0x1e3                                     | 002b99ac: 3c0e01e3  lui\tt6,0x1e3`
- Changes tried: C19 explicit frame transport/restoration, 6 words; C11 bind result to t7, 5 words; C11 bind returned copy to v0, 2 words; C11 bind address formation to t7, 2 words; C11 guard pointer binding, 7 words; C9 volatile global read, 2 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: force the relocation base and loaded result to share t7 without instruction-emitting asm.
