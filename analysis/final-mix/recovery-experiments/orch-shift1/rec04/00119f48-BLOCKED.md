# 00119f48 blocked
- Range: 00119f48, 112 bytes. Versions tried: 6. Best: v3 with 15 differing words (108/112 bytes).
- First difference of the best version: !! 00119f64: 0440000f  bltz	v0,0x119fa4  | 00119f64: 0440000e  bltz	v0,119fa0 (branch offsets shift because of the missing address instruction).
- Changes tried: v1 s32 param with mask temp (24); v2 u64 param (24); v3 mask test inline after call, status in its own s64 (15); v4 global as f32 array plus f32* local (15); v5 volatile f32* (15); v6 call result read before pointer formed (15).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original forms the address (lui + addiu t7) and loads lwc1 0(t7) as two steps; the compiler folds the offset into lwc1. Try declaring D_0036a898 as a u8 array and reading through a cast pointer stored in a u32/pointer-typed local, or an asm("" : "+r"(pointer)) after taking the address (C10d style, with why comment).
