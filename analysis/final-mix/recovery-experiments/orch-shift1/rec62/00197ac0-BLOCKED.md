# 00197ac0 blocked
- Range: 00197ac0, 52 bytes. Versions tried: 4. Best: v1 with 12 differing words (48/52 bytes); v3 and v4 equal.
- First difference of the best version: !! 00197ac0: 27bdfff0  addiu	sp,sp,-16 (compiled has lui t7,0x35 first; original keeps addiu t7,t6,64 in the beqz delay slot then move a0,t7, with a shared-looking tail).
- Changes tried: v1 s32 global plain if (12); v2 u32 global + u64 callee param (14, dsll32/dsrl32 added); v3 s64 callee param (12); v4 u8* typed global and member temp (12).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: force the 0x40 sum into a temp register distinct from a0 (C11c register binding to $15 for the sum) or volatile global read (C9) to move lui after the sp adjustment.
