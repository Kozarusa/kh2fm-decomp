# 001b2380 blocked
- Range: 001b2380, 120 bytes. Versions tried: 5. Best: v1 with 13 differing words (120/120 bytes).
- First difference of the best version: !! 001b2384: ac800004  sw	zero,4(a0)  (compiled: lui t7,0x37 hoisted first; original stores next=0 through a0 before copying a0 to s0, loads float via addiu+lwc1 0(t7), and keeps sll a0,a1,4 in the jal delay slot).
- Changes tried: v2 float global as array D_0036d9cc[] (13 words, no change); v3 volatile float global (13, no change); v4 compile error (my typo, counts as a version); v5 float loaded into a temp before count store (13, no change). v5 was written one version past the 3-version streak limit (my error).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original likely has the first stores through a separate pointer copy (a0 used for swc1 16(a0) after move s0,a0), e.g. an inlined init helper; try C11(b) a separate temp pointer variable for the first field stores / C10(d) asm memory barrier after node->next=0.
