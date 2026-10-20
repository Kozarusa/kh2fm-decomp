# 001676b0 blocked
- Range: 001676b0, 120 bytes. Versions tried: 7 (v2 was a compile error from my edit). Best: v1 with 8 differing words (120/120 bytes).
- First difference of the best version: !! 001676c8: 01e56824  and	t5,t7,a1  | 001676c8: 01e57824  and	t7,t7,a1  (pressed lands in t7, original keeps it in t5 so t7 is free for the lui of the float address; also sd 24(a0) is scheduled before the lui in ours, after lwc1 in the original).
- Changes tried: v1 plain (8); v3 released computed before pressed (8, and/sd order changed); v4 pressed bound to $13 via register asm (8, ignored); v5 float load hoisted before branch (15); v6 asm "+r" on changed (8, no effect); v7 mask temp ~buttons plus released-first (8, same as v3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: make the compiler allocate released=t6 first and pressed=t5 (e.g. keep changed live past the branch via a volatile/asm use, or restructure as pressed = buttons & ~previous written through a separate temp), C11 reorder.
