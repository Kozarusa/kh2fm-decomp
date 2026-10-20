# 001ad098 blocked
- Range: 001ad098, 92 bytes. Versions tried: 4. Best: v1 with 10 differing words (88/92 bytes).
- First difference of the best version: !! 001ad0c8: 3c0f0037  lui t7,0x37 | 3c0e0037 lui t6,0x37 (compiler folds the low half into lwc1 -10340(t6); original does lui/addiu t7 then lwc1 0(t7), and stores swc1 before vtable).
- Changes tried: v1 f32 global (10); v2 array decl f32 D[] indexed 0 (10); v3 u8 array with volatile f32 read (10); v4 local f32* pointer and volatile store (10).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C5-like address materialization: make the address a separate pointer value that is also used elsewhere, or declare the constant as part of a larger struct so the address is not folded into the lwc1 offset.
