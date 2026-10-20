# 0016d450 blocked
- Range: 0016d450, 128 bytes. Versions tried: 0. Best: none.
- First difference of the best version: none (not probed).
- Changes tried: none.
- Why it stops here: R3 condition: VU macro instructions (lqc2, qmtc2, vmulx, sqc2) and the packet lists no accepted sibling with a similar sequence.
- Next hypothesis: find an accepted source using lqc2/vmulx/sqc2 with a static-local temporary (D_004f6300 return buffer) and copy its pattern.
