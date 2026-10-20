# 0022f528 blocked
- Range: 0022f528, 120 bytes. Versions tried: 4. Best: v1 with 2 differing words (120/120 bytes).
- First difference of the best version: !! 0022f574: afae0004 sw t6,4(sp) | 0022f574: afaf0000 sw t7,0(sp).
- Changes tried: v1 copied rec136 v6, 2 words; C10 preloaded fields with full memory guard v2, 10 words; C10 narrow field guard with first preload dependency v3, 5 words; C10 preceding sentinel store dependencies v4, 5 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10 use volatile stores for only record.first and record.second, preserving ordinary halfword loads.