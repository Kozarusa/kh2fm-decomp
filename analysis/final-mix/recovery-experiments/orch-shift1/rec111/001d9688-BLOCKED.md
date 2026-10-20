# 001d9688 blocked
- Range: 001d9688, 52 bytes. Versions tried: 4. Best: v1 with 8 differing words (48/52 bytes).
- First difference of the best version: !! 001d969c: 304f00ff  andi	t7,v0,0xff | 001d969c: 2c4f0063  sltiu	t7,v0,99
- Changes tried: v1 plain u8 value (8); v2 u32 value with (u8) compare cast (8, registers differ from instr 3); v3 separate next variable (8); v4 s32 value (8).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind the loaded value to $2 (v0) via register asm so the lbu lands in v0 with the unmasked add result merged back and a final u8 return mask; or volatile read of *pointer.
