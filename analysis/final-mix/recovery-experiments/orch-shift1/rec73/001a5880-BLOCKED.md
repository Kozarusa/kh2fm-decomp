# 001a5880 blocked
- Range: 001a5880, 116 bytes. Versions tried: 8. Best: v6 with 2 differing words (116/116 bytes).
- First difference of the best version: !! 001a58ac: 25f4d4e8  addiu	s4,t7,-11032   ; = D_0036d4e8  | 001a58ac: 00c0802d  move	s0,a2  (the move s0,a2 and the addiu s4 are swapped)
- Changes tried: C11 u64 value (v2, 15); separate loop counter copy inside the if (v3, 3); offset/table temps (v4, 13); counter declared before if (v5, 15); offset temp before counter (v6, 2); table temp first (v7, 13); asm barrier on counter (v8, 3).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: C11 - the only remaining difference is scheduling of `move s0,a2` after `addiu s4`; try a register binding of the counter to $16 and the table address to $20 (C11c) on v6.
