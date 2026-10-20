# 0016ace0 blocked
- Range: 0016ace0, 88 bytes. Versions tried: 4. Best: v1 with 17 differing words (80/88 bytes).
- First difference of the best version: !! 0016acf0: 00a0802d  move	s0,a1   | 0016acf0: 0080802d  move	s0,a0
- Changes tried: v1 plain quad copy with Quad typedef (17); v2 dest pointer in a local variable (17, identical); v3 callee declared without args (17, identical); v4 object as u32 (17, identical).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original keeps s0=vector(a1), s1=object(a0) and computes dest in t7 (addiu t7,s1,1344) used as sq base with the D_0036c1b4 lui hoisted into the beql delay slot; try a struct wrapper with operator= / struct copy through a pointer so the address is not folded, or bind vector to s0 with register asm("$16").