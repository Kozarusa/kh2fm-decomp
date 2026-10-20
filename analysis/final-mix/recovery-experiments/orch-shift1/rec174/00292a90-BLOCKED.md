# 00292a90 blocked
- Range: 00292a90, 92 bytes. Versions tried: 8. Best: v8 with 14 differing words (100/92 bytes).
- First difference of the best version: !! 00292a90: 3c0f0036 lui t7,0x36 | 00292a90: 3c0e0036 lui t6,0x36.
- Changes tried: v1 22 words; C1b zero result temporary v2 22; C11c v0 result binding v3 19; C1b successful exit through result v4 19; C11d one success-exit guard v5 15; C9 volatile word flag read v6 15; C11b split entry and loop count v7 15; C11c t7 entry count binding v8 14.
- Why it stops here: budget reached.
- Next hypothesis: C1 recheck exit block merging; remove success-exit guard independently to recover the return delay-slot li, preserving count binding and word load.
