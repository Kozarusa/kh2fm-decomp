# 002535d0 blocked
- Range: 002535d0, 104 bytes. Versions tried: 5. Best: v2 with 28 differing words (128/104 bytes).
- First difference of the best version: !! 002535e0: 81cf26c8 lb t7,9928(t6) | 002535e0: 2410ffff li s0,-1
- Changes tried: v1 initial translation 29; C9 volatile table v2 28; C2 explicit signed char v3 28; C20 s64 expressions v4 29; C11 reorder first load v5 28.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 bind initialized result and separately guard to delay initialization, then investigate compiler signed-byte load transport.
