# 0023f5b8 blocked
- Range: 0023f5b8, 92 bytes. Versions tried: 4. Best: v1 with 18 differing words (84/92 bytes).
- First difference of the best version: !! 0023f5c4: ffb20010 sd s2,16(sp) | 0023f5c4: ffbf0010 sd ra,16(sp).
- Changes tried: C1(a), preserve original incoming call arguments, 18 words; C7(c), early returns, 18 words; C10(c), volatile stores, 19 words. Initial source: 18 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Explain the original unused s2 save and restore before attempting further prologue matching.
