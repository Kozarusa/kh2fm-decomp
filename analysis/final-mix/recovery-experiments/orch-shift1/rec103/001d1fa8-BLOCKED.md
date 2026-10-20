# 001d1fa8 blocked
- Range: 001d1fa8, 120 bytes. Versions tried: 4. Best: v1 with 4 differing words (120/120 bytes).
- First difference of the best version: !! 001d1fb0: 3c0f0035  lui	t7,0x35 | 001d1fb0: ffb00000  sd	s0,0(sp)
- Changes tried: v2 separate self variable (4 words); v3 empty asm on self (25 words); v4 vtable pointer temp before first store (4 words).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: compiler hoists move s0,a0 above the vtable sw and sd s0 above lui t7; try C11c register binding of s0 ($16) at the point after the vtable store, or have the first two stores go through a different base variable than the s0 copy.