# 0018fd40 blocked
- Range: 0018fd40, 44 bytes. Versions tried: 4. Best: v1 with 8 differing words (44/44 bytes).
- First difference of the best version: !! 0018fd44: ffbf0000  sd	ra,0(sp) | 0018fd44: 0080782d  move	t7,a0
- Changes tried: v1 direct call (8); v2 locals in original load order a2,a1,a0,f12,a3 (9, 40 bytes); v3 volatile loads (8); v4 sibling declaration f32,u64,s32,u64,s64 with s32* (8).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original loads the first argument into t7 while a0 stays live (no move t7,a0 up front): bind first with register u32 first asm("$15") = object[0] (C11c) or pin it with asm("" : "+r"(first)) (C11d).
