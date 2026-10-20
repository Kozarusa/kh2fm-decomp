# 001852b8 blocked
- Range: 001852b8, 116 bytes. Versions tried: 8. Best: v6 with 12 differing words (116/116 bytes).
- First difference of the best version: !! 001852cc: 3c0f0037  lui	t7,0x37  | 001852cc: de060600  ld	a2,1536(s0)
- Changes tried: v1 u64 object 31 words (128 bytes); v2 u8* object 20; v3 array decl for floats 20; v4 volatile floats 20; v5 constant-address pointers 13 (ori instead of lui+addiu); v6 array pointers with asm("+r") to force address materialization 12; v7 sequential load of each 12 (loads reordered); v8 asm volatile 12.
- Why it stops here: budget reached (8 versions).
- Next hypothesis: the original schedules lui t7 / ld a2 / addiu t7 / move a0,v0 / lwc1 f12 via a single reused t7; try computing x and y in one expression with one shared pointer register (C11 a/b), e.g. the floats read as members of a struct at 0x36c8cc (D_0036c8cc[0], [1] is not it: addresses differ by 4 but originals use separate lui), or C10 reorder of the flags computation after the float loads.
