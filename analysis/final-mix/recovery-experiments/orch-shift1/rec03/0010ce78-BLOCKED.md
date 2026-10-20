# 0010ce78 blocked
- Range: 0010ce78, 120 bytes. Versions tried: 8. Best: v7 with 12 differing words (116/120 bytes).
- First difference of the best version: !! 0010ceb4: 11e00007  beqz	t7,0x10ced4   (compiled: beqz t7,10ced0, i.e. epilogue is duplicated instead of shared)
- Changes tried: v1 baseline 22 words; v2 u8 flag early returns 22; v3 u32 flag&0xff 30; v4 result declared after call 15; v5 if/else equal 15; v6 volatile field read (C8c) 15; v7 Ghidra-literal && chain with comma assignments 12; v8 result=1 then zero if equal 12.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original does `beq t7,a0; delay move t6,zero; li t6,1` instead of xor/sltu, and shares one epilogue; try C8(a)/(b) with a separate temp for the compared value, or make D_003417b0 reads volatile-ish only in the inner compare.
