# 0010f6b8 blocked
- Range: 0010f6b8, 60 bytes. Versions tried: 6. Best: v1 with 7 differing words (48/60 bytes).
- First difference of the best version: !! 0010f6bc: 11c0000b  beqz	t6,0x10f6ec   (compiled: beqz t6,10f6e0; the compiler folds the result into `slt v0,t6,t7` and returns early, original keeps `slt t6; bnez t6; li v0,1; move v0,zero` with a shared jr ra)
- Changes tried: v1 result=0/1 with !(a<b) 7; v2 Ghidra-form `<=` 7; v3 separate count/limit temps (C8a) 7; v4 early-return form 7 (52 bytes); v5 volatile data pointer (C8c) 12; v6 bool return with && expression 7.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: force the compare to stay a branch condition instead of a materialized slt, e.g. make only the data[0] read volatile, or keep the comparison result in a separate s32 variable and branch on it (C8b write the condition the other way round with an else arm).
