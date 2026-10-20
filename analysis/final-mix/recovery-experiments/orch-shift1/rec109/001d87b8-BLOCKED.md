# 001d87b8 blocked
- Range: 001d87b8, 100 bytes. Versions tried: 5. Best: v2 with 8 differing words (104/100 bytes).
- First difference of the best version: !! 001d87d0: 0000102d  move	v0,zero | 001d87d0: 0000202d  move	a0,zero
- Changes tried: v1 result var + u8 flag (27, s1 saved, lbu); v2 early returns + u32 word then u8 flag (8); v3 result var again with swapped operand order (27); v4 u8* callee return and swapped second operand order (8, same as v2); v5 ternary on result var (27).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: compiled puts the zero return value and final load in a0 then move v0,a0, and adds s0,v0 where original adds v0,s0 on the first access; try volatile on the final load, or a bool/s32 return type variant, or restructuring so the zero is the return value register (C11).
