# 00203ae8 blocked
- Range: 00203ae8, 92 bytes. Versions tried: 4. Best: v1 with 8 differing words (84/92 bytes).
- First difference of the best version: !! 00203aec: 11e00013  beqz	t7,0x203b3c  vs  11e00011 beqz t7,203b34 (compiled is 8 bytes short: original ends with beqz v0=0 / li v0,1 as a separate branch tail on f58, compiled collapses it to sltu v0,zero,t7).
- Changes tried: v2 C7/C8 reorder `if (f58 != 0) return 1; return 0` (8); v3 C8a result variable, Ghidra structure (10); v4 C8c volatile f58 read (8).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7(b)/(c): make the final test a nested if/else with explicit `return 1` blocks (or put the c9 test and f58 test in one && expression), or C12-style separate temp for f58 load.
