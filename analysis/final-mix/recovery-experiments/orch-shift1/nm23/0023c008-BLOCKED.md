# 0023c008 blocked
- Range: 0023c008, 104 bytes. Versions tried: 4. Best: v1 with 2 differing words (104/104 bytes).
- First difference of the best version: !! 0023c008: 3c0f0036 lui t7,0x36 | 0023c008: ac800058 sw zero,88(a0).
- Changes tried: v1 copied the named best, 2 words; v2 C10d used a defined pointer and memory-clobber guard before the first volatile store, 2 words; v3 C10d used a memory-only barrier to permit split address scheduling, 2 words; v4 C10c removed volatility from only the first store, 3 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Starting from v1, make only the second zero store nonvolatile to test whether it changes address scheduling while preserving the first volatile store.