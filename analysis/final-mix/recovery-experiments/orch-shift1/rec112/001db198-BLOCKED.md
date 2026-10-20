# 001db198 blocked
- Range: 001db198, 104 bytes. Versions tried: 5. Best: v2 with 21 differing words (92/104 bytes).
- First difference of the best version: !! 001db19c: 24020001  li	v0,1                                          | 001db19c: 2caf0003  sltiu	t7,a1,3
- Changes tried: v1 bool return, s64 args (26 words); v2 s64 return, nested ifs (21); v3 early returns (21, frame 16 vs 32, result in t7 not s1); v4 nested early returns (21, same); v5 separate inner variable (21, same).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the original keeps the result in s1 (zeroed before the jal to 001db200) and object in s0, with li v0,1 and move v0,zero in v0 for early exits; try making the result live across the first call (e.g. read result via volatile or consume it after the call) so it takes an s register (C12/C11).
