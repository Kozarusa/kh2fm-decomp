# 001a82b0 blocked
- Range: 001a82b0, 64 bytes. Versions tried: 3. Best: v2 (also v3) with 5 differing words (64/64 bytes); no version beat the earlier 5.
- First difference of the best version: !! 001a82b4: 3c0e01c7  lui	t6,0x1c7   | 001a82b4: 2482000c  addiu	v0,a0,12
- Changes tried: v1 local pointer to the global taken at top (15, lui hoisted before the branch); v2 volatile table read after the entry==0 test (5, same as before); v3 end pointer variable and ternary return (5, same).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original fills the bnez delay slot with the lui of the second path and loads li 12 before the lw; try C11(c) binding the second-path table pointer to $14 (t6) and the stride to $13 (t5) with a // why: comment, or an empty asm guard on the stride.
