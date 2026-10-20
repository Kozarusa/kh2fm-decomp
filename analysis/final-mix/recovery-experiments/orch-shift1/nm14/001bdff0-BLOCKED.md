# 001bdff0 blocked
- Range: 001bdff0, 108 bytes. Versions tried: 4. Best: v1 with 2 differing words (108/108 bytes).
- First difference of the best version: !! 001be008: 25f036f0  addiu	s0,t7,14064                                | 001be008: ffbf0018  sd	ra,24(sp)
- Changes tried: v1 C11 guard u32 base 2 words; v2 input-only cursor guard 2 words; v3 cursor binding s0 7 words; v4 typed struct member cursor 2 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 memory-clobber cursor guard scheduling, followed by accepted callee declaration normalization. Two WPs have now blocked; next attempt belongs to opus WP per brief rule 2.
