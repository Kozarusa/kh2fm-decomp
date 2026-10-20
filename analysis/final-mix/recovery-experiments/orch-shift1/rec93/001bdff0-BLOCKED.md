# 001bdff0 blocked
- Range: 001bdff0, 108 bytes. Versions tried: 8. Best: v5 with 2 differing words (108/108 bytes).
- First difference of the best version: !! 001be008: 25f036f0  addiu	s0,t7,14064                                | 001be008: ffbf0018  sd	ra,24(sp)
- Changes tried: v1 plain u8 array base (24 words, base folded); v2 asm "+r"(base) to keep lui/addiu then add (4); v3 count declared first (4); v4 temp for slot (4); v5 second asm on cursor (2); v6 volatile first asm (2); v7 volatile second asm (2, addiu one slot too early); v8 volatile asm with cursor and count (2).
- Why it stops here: budget reached (8 versions), no improvement for 3 versions.
- Next hypothesis: placement of addiu s0,t7,14064 between sd s2 and sd ra is a scheduling issue; try a different asm barrier shape (e.g. asm on a u32 copy of the base) or declaring the base as a typed struct pointer member.
