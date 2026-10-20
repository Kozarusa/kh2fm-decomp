# 002944f8 blocked
- Range: 002944f8, 84 bytes. Versions tried: 4. Best: v1 with 15 differing words (80/84 bytes).
- First difference of the best version: !! 00294510: ffb00000 sd s0,0(sp) | 00294510: 0c040d5c jal 103570 <func_00103570>.
- Changes tried: v1 literal outgoing u32 return, 15 words; C11b temporary v2, 15 words; C10d memory guard v3, 18 words; C10c first zero store volatile v4, 15 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11c initialized numeric register binding for first callee result, preserving outgoing callee return.
