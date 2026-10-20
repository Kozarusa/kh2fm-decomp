# 001466b0 blocked
- Range: 001466b0, 128 bytes. Versions tried: 0. Best: none.
- First difference of the best version: none (not probed).
- Changes tried: none.
- Why it stops here: R3 condition: VU macro instructions (lqc2, vmulax, vmadday, vmaddaz, vmaddw, vclipw, vnop, cfc2) and the packet lists no accepted sibling with a similar sequence.
- Next hypothesis: vu-macro specialist should find an accepted sibling using vclipw/cfc2 $18 and copy its asm pattern.
