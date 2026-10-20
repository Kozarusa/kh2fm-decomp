# 001dbad0 blocked
- Range: 001dbad0, 104 bytes. Versions tried: 5 (v1 link error). Best: v2 with 4 differing words (104/104 bytes).
- First difference of the best version: !! 001dbb00: 3c0f0035  lui	t7,0x35   | 001dbb00: 3c0e0035  lui	t6,0x35
- Changes tried: v1 asm label on tail callee (link error); v2 plain callee decl, 4 words; v3 C11(b) separate destination pointer variable, 4 words; v4 u8 array decl for D_00352a60, 4 words; v5 C11(d) empty asm guard on destination, 4 words (t6/t7 swapped).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind destination with register asm("$15") (t7) and the copied quad temp to "$8" (t0), each with a why comment.
