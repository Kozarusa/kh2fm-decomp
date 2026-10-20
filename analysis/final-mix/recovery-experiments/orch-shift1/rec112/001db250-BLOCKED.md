# 001db250 blocked
- Range: 001db250, 68 bytes. Versions tried: 4. Best: v1 with 16 differing words (64/68 bytes).
- First difference of the best version: !! 001db254: ffbf0010  sd	ra,16(sp)                                     | 001db254: 3c0f0037  lui	t7,0x37
- Changes tried: v1 plain f32 global, void* out buffer first arg (16); v2 volatile global read, C9 (16, identical output); v3 separate temporaries for field/global, C11b (16, identical); v4 u8 array global with f32 cast (16, identical).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original loads the object field (lw t7,108(a0); lwc1 f0,32(t7)) before forming the global address, and forms it as separate lui+addiu then lwc1 0(t7); try reading the field through a volatile pointer (C9) or a pointer-typed global variable with an explicit separate address (D as f32* via array cast), and check the 4-byte size gap (original 17 words, compiled 16).
