# 00198dc0 blocked
- Range: 00198dc0, 128 bytes. Versions tried: 8. Best: v7 with 20 differing words (128/128 bytes).
- First difference of the best version: !! 00198dc0: 0080782d  move t7,a0 | 00198dc0: 240effff  li t6,-1
- Changes tried: v1 plain (31); v2 separate part pointers (26); v3 jumper=object+13 hoisted, gives move t7,a0 and s0=t7+52 (25); v4 signed consts (25, same asm); v5 memory barrier (25); v6 asm copy of base (24); v7 u32 variables mask/minus for constants, registers now match (20); v8 swap byte stores 1/2 (21).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: scheduler hoists sb 48/56 and sw 4 etc.; try volatile/barrier on only the byte stores or a different grouping of u8 vs u32 access (union, C18) to force original store order (sw0,4,8,12,16..28, sh46, sb48, sb56, then sb t4+2, sb t4+1).
