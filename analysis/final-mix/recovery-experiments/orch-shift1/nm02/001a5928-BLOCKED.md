# 001a5928 blocked
- Range: 001a5928, 72 bytes. Versions tried: 5. Best: v2 with 2 differing words (72/72 bytes); same as rec73 v3.
- First difference of the best version: !! 001a592c: ffbf0008  sd	ra,8(sp) | compiled ffb00000  sd	s0,0(sp) (ra and s0 prologue stores swapped; nop delay slot after first jal matches).
- Changes tried: v1 variadic (...) decl for func_001c70e8, no barrier (16: s0 store goes into jal delay slot); v2 memory barrier + dead u64 result of u64 func_001c70e8 (2); v3 asm clobber "$16" instead of memory (6, frame 32 with sq/lq); v4 clobber "$31" (16); v5 volatile local instead of barrier (12).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C12/C10 - find a construct that keeps both prologue stores out of the jal delay slot and orders ra first; e.g. a barrier placed inside a wrapper-less statement after storing an argument-free volatile read, or declare func_001c70e8 as returning s64 and consume it with a dummy comparison.
