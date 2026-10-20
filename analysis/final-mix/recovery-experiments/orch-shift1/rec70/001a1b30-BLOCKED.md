# 001a1b30 blocked
- Range: 001a1b30, 56 bytes. Versions tried: 4. Best: v1 with 13 differing words (48/56 bytes).
- First difference of the best version: !! 001a1b34: 908d01b2  lbu	t5,434(a0)                                   | 001a1b34: 908e01b2  lbu	t6,434(a0)
- Changes tried: v1 direct translation, 13 words. v2 separate s32 copy with & 0xff, 13 words (no change). v3 C11d asm "+r" on the u8 value, 13 words (no andi emitted). v4 duplicated the clamp in both branches (56 bytes, 13 words, branch layout differs).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original has andi t6,t7,0xff then move t7,t6 and two movn copies of the clamp; try C3 variants (u32 current from a u8 temp via cast chain) combined with v4 duplicated-clamp shape, and make amount s64 (C20) since Ghidra types it long.
