# 0028b078 blocked
- Range: 0028b078, 100 bytes. Versions tried: 4. Best: v1 with 5 differing words (100/100 bytes).
- First difference of the best version: !! 0028b080: 00a0702d move t6,a1 | 0028b080: 30a5ffff andi a1,a1,0xffff.
- Changes tried: v1 copied best prior target, renamed forbidden locals, returned tail callee result, 5 words; C3 widen value parameter v2 22; C11(c) bind value temporary t6 v3 24; C11(d) one guard v4 6.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: independently widen count parameter from v1 before adding any binding; original copies both full-width inputs without masks.
