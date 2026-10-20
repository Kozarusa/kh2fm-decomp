# 0023c008 blocked
- Range: 0023c008, 104 bytes. Versions tried: 6. Best: v3 with 2 differing words (104/104 bytes).
- First difference of the best version: !! 0023c008: 3c0f0036 lui t7,0x36 | 0023c008: ac800058 sw zero,88(a0).
- Changes tried: C10 original store order v1: 22 words; zero-store rotation v2: 22 words; volatile stores v3: 2 words. C11 address temporary v4: 2 words; t7 binding v5: 2 words; empty address guard v6: 2 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Place a memory barrier before the first volatile store to constrain address materialization scheduling.
