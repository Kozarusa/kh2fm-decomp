# 0017cb78 blocked
- Range: 0017cb78, 124 bytes. Versions tried: 4. Best: v1 with 20 differing words (116/124 bytes).
- First difference of the best version: !! 0017cb94: 15cf000e  bne	t6,t7,0x17cbd0  (compiled bne offset 0xd; the original materializes the global with a separate addiu t7,t7,-15040 and loads lwc1 f12,0(t7) in the jal delay slot, compiled folds the offset into lwc1 -15040(t7)).
- Changes tried: v1 plain f32 global, two branches (20); v2 volatile f32 global (20); v3 u8 array global read through f32 cast (20); v4 volatile pointer variable (33).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: make the compiler keep the address in a register (global reached through a struct/array base or a non-folded pointer expression), and check whether the common tail (and with -2, sw) is one shared block with an if/else instead of the current else-if.
