# 001995b8 blocked
- Range: 001995b8, 60 bytes. Versions tried: 4. Best: v1 with 13 differing words (60/60 bytes).
- First difference of the best version: !! 001995b8: 0000682d  move t5,zero | 3c0f01c6  lui t7,0x1c6 (original uses bnezl with head load in delay slot, compiled uses lui hoist and beqz).
- Changes tried: v2 if/else node select (C7, 13); v3 volatile head read (C9, 14); v4 ternary in while condition (C8, 14).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Try a do/while or goto-style loop with the head load as a branch-likely delay slot (C8: separate temporary for node and previous, or make the previous test volatile) so the head load sits in the bnezl delay slot.
