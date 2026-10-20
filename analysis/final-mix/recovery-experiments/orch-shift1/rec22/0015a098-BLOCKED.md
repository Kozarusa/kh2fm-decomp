# 0015a098 blocked
- Range: 0015a098, 128 bytes. Versions tried: 0. Best: none.
- First difference of the best version: none (not probed).
- Changes tried: none.
- Why it stops here: R3 condition. Contains VU macro instructions (lqc2, vsub.wxyz, sqc2) and the packet lists no accepted sibling with a similar sequence (only atan2f callers).
- Next hypothesis: vu-macro: find an accepted source with lqc2/vsub/sqc2 and copy its pattern, then recover the lq/sq vector copies and the atan2f tail call.