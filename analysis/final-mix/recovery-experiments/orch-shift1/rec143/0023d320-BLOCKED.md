# 0023d320 blocked
- Range: 0023d320, 72 bytes. Versions tried: 4. Best: v1 with 7 differing words (72/72 bytes).
- First difference of the best version: !! 0023d330: 8dcc9e1c lw t4,-25060(t6) ; = D_00349e1c | 0023d330: 91ed9e20 lbu t5,-25056(t7) ; = D_00349e20.
- Changes tried: C10 original store order v1: 7 words; source store reversal v2: 7 words; volatile stores v3: 13 words; memory barrier between stores v4: 9 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Introduce a temporary for the word global load before computing the byte flag, preserving the original load order.
