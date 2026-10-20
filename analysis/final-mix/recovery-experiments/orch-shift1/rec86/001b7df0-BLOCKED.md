# 001b7df0 blocked
- Range: 001b7df0, 120 bytes. Versions tried: 0. Best: none.
- First difference of the best version: none (not probed).
- Changes tried: none.
- Why it stops here: R3 condition: VU macro instructions (lqc2, vsub.wxyz, sqc2) and the packet lists no accepted sibling with a similar sequence.
- Next hypothesis: vu-macro: copy the lqc2/vsub.wxyz/sqc2 asm pattern from an accepted vsub source (e.g. fm_primary_orchbc_recovered_001786e0.cpp); function is a lookup (001b7998) then 0018a7d0 into a stack quad, then vector subtract into (*(obj+4)+0x870).
