# 001a82b0 blocked
- Range: 001a82b0, 64 bytes. Versions tried: 4. Best: v1 with 5 differing words (64/64 bytes).
- First difference of the best version: !! 001a82b4: 3c0e01c7  lui	t6,0x1c7   | 001a82b4: 2482000c  addiu	v0,a0,12
- Changes tried: v1 plain (5); v2 limit computed before next (5, identical); v3 stride variable 12 (5, identical); v4 inverted if structure (15).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original hoists lui of D_01c6cb98 into the bnez delay slot and loads li 12 before the lw; try a second global reference form (e.g. pointer-to-global alias or the global read in a different expression order) to change lui placement.