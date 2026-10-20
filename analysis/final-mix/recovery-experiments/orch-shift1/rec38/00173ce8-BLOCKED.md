# 00173ce8 blocked
- Range: 00173ce8, 128 bytes. Versions tried: 0. Best: none.
- First difference of the best version: n/a (not probed).
- Changes tried: none.
- Why it stops here: R3 condition: VU macro instructions (lqc2, vmulax, vmadday, vmaddaz, vmaddw, sqc2) and the packet lists no accepted sibling with a similar sequence.
- Next hypothesis: VU macro: copy the lqc2/vmulax..vmaddw/sqc2 pattern from an accepted vector matrix-multiply source (e.g. fm_primary_queuedelta_recovered_002f3cd8.cpp), combined with the Vec4 self-check store pattern from 001735b0.