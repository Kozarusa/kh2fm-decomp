# 00162bb0 blocked
- Range: 00162bb0, 116 bytes. Versions tried: 0. Best: none.
- First difference of the best version: n/a (not probed).
- Changes tried: none.
- Why it stops here: R3 condition: VU macro instructions (lqc2, qmtc2, vmulx.xyz, vsub.wxyz, sqc2) and the packet lists no accepted sibling with a similar sequence.
- Next hypothesis: R3 vu-macro: find an accepted VU macro sibling (vmulx scale + vsub) and copy its asm pattern.
