# 001b27f0 blocked
- Range: 001b27f0, 112 bytes. Versions tried: 4. Best: v1 with 12 differing words (112/112 bytes).
- First difference of the best version: !! 001b27fc: 03a0202d  move	a0,sp  (compiled: move a2,sp)
- Changes tried: v1 Quad locals (12); v2 reversed local declaration order, no effect (12); v3 single Frame struct, stack layout now matches 0/16/32 but scheduling still differs (12); v4 copy through Quad pointer, no effect (12).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: copy with the asm volatile lq $8,0(src); sq $8,0(dst) pattern from accepted 001b2780 (original uses t0 for lq/sq and does the copy before the delay slot of jal 1b6dd0), on top of the v3 Frame struct; then swap the stores at 0x100/0x104 to 0x104 first (C10a).
