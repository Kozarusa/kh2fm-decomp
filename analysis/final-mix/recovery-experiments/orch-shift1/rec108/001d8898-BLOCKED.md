# 001d8898 blocked
- Range: 001d8898, 108 bytes. Versions tried: 8. Best: v6 with 7 differing words (112/108 bytes).
- First difference of the best version: !! 001d88b0: 0000102d  move	v0,zero | 001d88b0: 0000702d  move t6,zero (the result variable lives in t6 instead of v0, so the final sltu goes to t6 plus an extra move v0,t6 at the end, +4 bytes).
- Changes tried: v1 nested bool result (29 words, s1 saved); v2 early returns with u8 cast (12); v3 s32 return, bool flag (12); v4 bool result with else branch (12); v5 base += index*0x38 with s32 early returns (8); v6 v5 plus 0 < bits (7); v7 single s32 result variable (7); v8 C11c result bound to $2 (20).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: the result must share v0 with the callee return; try a bool/u8 typed result with early returns written as ternary, or a volatile read (C9) of the second load, to avoid the separate result register t6.