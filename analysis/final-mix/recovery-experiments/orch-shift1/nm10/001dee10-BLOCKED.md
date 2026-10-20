# 001dee10 blocked
- Range: 001dee10, 120 bytes. Versions tried: 7. Best: v4 with 2 differing words (120/120 bytes).
- First difference of the best version: !! 001dee40: 00000000  nop  | 001dee40: 01e0682d  move	t5,t7
- Changes tried: v1 prev-copy compare with base bound 14 (3); v2 copy bound to 15 (3); v3 base then end bindings inside inner if (4); v4 end bound 15 first then base bound 14, prev-copy compare (2, best); v5 post-decrement on 16-byte struct pointers with the same bindings (2); v6 while-first loop (20); v7 compare against end+0x10 (19).
- Remaining diff in v4: the loop head has move t5,t7 (copy of the pre-decrement counter) and bne compares t6,t5 instead of t6,t7 with the decrement in the delay slot.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: find a source form where the pre-decrement compare needs no copy (for example a for loop with the decrement as the loop increment, or an empty asm guard on the counter inside the loop).
