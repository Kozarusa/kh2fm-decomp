# 002344c0 blocked
- Range: 002344c0, 92 bytes. Versions tried: 4. Best: v1 with 19 differing words (92/92 bytes).
- First difference of the best version: !! 002344c4: 3c090036 lui t1,0x36 | 002344c4: 3c0f01db lui t7,0x1db.
- Changes tried: volatile destination baseline v1: 19 words; C11 load reorder v2: 19 words; sequence temporary v3: 19 words; sequence address binding v4: 19 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 guard the initialized sequence address binding; normal destination accesses may restore the baseline schedule observed in siblings.