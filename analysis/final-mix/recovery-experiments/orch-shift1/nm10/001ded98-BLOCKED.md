# 001ded98 blocked
- Range: 001ded98, 120 bytes. Versions tried: 8. Best: v5 with 3 differing words (120/120 bytes).
- First difference of the best version: !! 001dedc0: 248f0040  addiu	t7,a0,64  | 001dedc0: 248d0040  addiu	t5,a0,64
- Changes tried: v1 reshaped loop with both bindings (21); v2 bind end to 15 only (8); v3 bind fixed base to 14 inside inner if with bool more (4); v4 both bindings (7); v5 previous-copy compare, base bound 14 (3, best); v6 v5 plus end bound 15 at declaration (5); v7 post-decrement compare on 16-byte struct pointers, base bound 14 (4); v8 v7 plus end bound 15 inside inner if (4).
- Remaining diff in v5: end lives in t5 and a move t7,t5 appears at loop head (original has a nop there and decrements t7 itself); the compiler needs a copy because the compare uses the pre-decrement value.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: v5 shape with the pre-decrement copy (previous) bound to $15 and end left free, or keep the copy as the counter and compute the compare against end+0x10 with end bound to $15 only after the beq check.
