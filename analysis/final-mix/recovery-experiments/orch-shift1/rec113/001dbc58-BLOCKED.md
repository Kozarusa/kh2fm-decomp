# 001dbc58 blocked
- Range: 001dbc58, 116 bytes. Versions tried: 4. Best: v1 with 19 differing words (112/116 bytes).
- First difference of the best version: !! 001dbc64: ffb10008  sd	s1,8(sp) | 001dbc64: 00e0902d  move	s2,a3
- Changes tried: v1 plain Quad copy (19); v2 separate dest pointer and Quad temp (19, identical output); v3 16-byte-aligned struct copy (19, identical); v4 volatile Quad dest (19, identical).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original does addiu t7,s0,48 then lq t0 / sq t0,0(t7) before the other stores and the sd s1 precedes move s2,a3; try the lq/sq copy primitive from a precedent source, or reorder so vector is read before the call result-independent stores (C10a/b).
