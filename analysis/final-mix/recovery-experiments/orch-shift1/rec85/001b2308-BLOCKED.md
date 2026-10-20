# 001b2308 blocked
- Range: 001b2308, 120 bytes. Versions tried: 5. Best: v2 with 13 differing words (120/120 bytes).
- First difference of the best version: !! 001b230c: ac800004  sw	zero,4(a0)  vs compiled lui t7,0x37
- Changes tried: v1 separate globals (20 words); v2 List struct global + Ghidra statement order (13); v3 volatile float read (13); v4 float array [0] (13); v5 pointer-to-float read (13).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original does sw zero,4(a0) before move s0,a0 and keeps the lwc1 pair after it with a0 used for swc1; try C10 (d) asm memory barrier after the first store, or C11 register binding of node to a0 role.
