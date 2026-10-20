# 001a5880 blocked
- Range: 001a5880, 116 bytes. Versions tried: 6. Best: v3 with 2 differing words (116/116 bytes); v4 also 2.
- First difference of the best version: !! 001a58ac: 25f4d4e8  addiu	s4,t7,-11032   ; = D_0036d4e8 | compiled 00c0802d  move	s0,a2 (move s0,a2 and addiu s4 are swapped; all registers match).
- Changes tried: v1 C11c bind counter to $16 (9; reallocates s-regs); v2 C11c bind table to $20 (20); v3 C11d asm +r guard on offset (2); v4 guard on offset, counter declared first (2); v5 C11d guard on table pointer (14); v6 mutate count directly, no copy (15).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: statement-level scheduling trick on the counter copy, e.g. make the loop counter copy volatile-free but computed from a post-guard value (asm +r on count after the table temp), or an empty-guard on value (a0 copy).
