# 0015cc80 blocked
- Range: 0015cc80, 108 bytes. Versions tried: 8. Best: v1 with 17 differing words (108/108 bytes).
- First difference of the best version: !! 0015cc94: c4810010  lwc1 $f1,16(a0) | compiled c4800010 lwc1 $f0,16(a0)
- Changes tried: v2 swap compare operands (17); v3 volatile global (17); v4 array decl D[0] (17); v5 u8[] cast f32* pointer (17); v6 nested ifs (17); v7 volatile deref (17); v8 inverted != form (20, 100 bytes).
- Why it stops here: budget reached. Original loads obj[4] into $f1 first then does addiu t7 + lwc1 0(t7) into $f0 (address materialized by addiu, compare f1,f0); compiled folds the offset into lwc1 -19464(t7) and loads global into $f1.
- Next hypothesis: the global is accessed through a pointer variable the compiler cannot fold (e.g. function-local pointer from a struct/table base, or D_0036b3f8 is a member of a larger struct accessed via address passed through asm("+r")); try asm("" : "+r"(ptr)) on a pointer to D_0036b3f8 (C11d).
