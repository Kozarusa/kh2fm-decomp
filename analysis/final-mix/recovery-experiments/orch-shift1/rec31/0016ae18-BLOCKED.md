# 0016ae18 blocked
- Range: 0016ae18, 64 bytes. Versions tried: 5 (v2 was malformed, did not compile). Best: v1 with 15 differing words (60/64 bytes).
- First difference of the best version: !! 0016ae1c: 248f0890  addiu	t7,a0,2192  | 0016ae1c: ffbf0018  sd	ra,24(sp)
- Changes tried: v1 plain Quad local copy (15 words); v3 volatile Quad read, C9 (15); v4 struct with Quad member (15); v5 aligned f32x4 struct copy (15). All compile to lq t7,2192(a0) hoisted/scheduled later, original forms t7=a0+2192 first and does lq t0,0(t7) after move s0,a0.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: read the quad through an explicit pointer variable (Quad* p = (Quad*)(object+0x890)) passed through an asm("" : "+r"(p)) barrier (C11d), or bind the temporary with register Quad asm("$8") (C11c).
