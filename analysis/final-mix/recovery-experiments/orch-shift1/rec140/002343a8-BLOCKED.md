# 002343a8 blocked
- Range: 002343a8, 88 bytes. Versions tried: 4. Best: v1 with 11 differing words (88/88 bytes).
- First difference of the best version: !! 002343a8: 3c0a0036 lui t2,0x36 | 002343a8: 3c0b0036 lui t3,0x36.
- Changes tried: baseline v1: 11 words; C11 load reorder v2: 11 words; cursor temporary v3: 11 words; cursor binding v4: 11 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 guard the initialized cursor address binding; an explicit result binding also lowered the sibling targets by one word.