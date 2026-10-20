# 0019b328 blocked
- Range: 0019b328, 84 bytes. Versions tried: 5. Best: v2 with 19 differing words (88/84 bytes).
- First difference of the best version: !! 0019b330: 95ef0008  lhu t7,8(t7) | 0019b330: 95ec0008 lhu t4,8(t7).
- Changes tried: v1 plain return structure (21), v2 single-return with entry var (19), v3 if/else return (21), v4 separate result var (21), v5 u16 count (19).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Original keeps the cursor in v0, loads the count into t7 then copies it to t4 (move t4,t7) and all match/negative-id exits share one jr ra with nop delay; try an explicit extra temporary for the count copy and a goto-style shared exit to get a single epilogue (88 vs 84 bytes: duplicated jr ra in compiled).
