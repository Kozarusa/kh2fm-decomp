# 0014b9a8 blocked
- Range: 0014b9a8, 116 bytes. Versions tried: 8. Best: v8 with 3 differing words (116/116 bytes).
- First difference of the best version: !! 0014b9d8: 8d8f0008  lw	t7,8(t4)  (compiled: lw t6,8(t4); lq/sq use t7/t6 swapped)
- Changes tried: v1 plain struct+Quad loop 10 words; v2 void* decl for 80d8 17 words (size 112); v3 inline helper 10; v4 volatile dst field 17; v5 volatile Work* pointer 8; v6 volatile Quad store 7; v7 count declared first 7 (C11b no effect); v8 register binding w=t4 count=t5 3 words (C11c).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: Bind the dst pointer temp to $15 and the Quad temp to $14 (C11c), or load dst into a separate variable before the lq.
