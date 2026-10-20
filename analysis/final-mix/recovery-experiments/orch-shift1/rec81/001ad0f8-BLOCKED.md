# 001ad0f8 blocked
- Range: 001ad0f8, 92 bytes. Versions tried: 4. Best: v1 with 10 differing words (88/92 bytes).
- First difference of the best version: !! 001ad128: 3c0f0037  lui	t7,0x37   | 001ad128: 3c0e0037  lui	t6,0x37
- Changes tried: v2 u8 array cast read (10); v3 volatile f32 read (10); v4 f32 array decl plus pointer deref (10). All emit lui t6 + lwc1 off(t6) instead of lui/addiu t7 + lwc1 0(t7).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: make the address materialize via a pointer variable that is also kept live (e.g. an f32* held across the call, or asm +r on the pointer), or the global is reached through a struct/vtable-like pointer loaded with addiu.
