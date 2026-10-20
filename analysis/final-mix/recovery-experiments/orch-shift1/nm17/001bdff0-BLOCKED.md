# 001bdff0 blocked
- Range: 001bdff0, 108 bytes. Versions tried: 5 attempts, including initial failed write/missing-source invocation; 4 compiled sources v1-v4. Best: v1 with 2 differing words (108/108 bytes).
- First difference of the best version: !! 001be008: 25f036f0  addiu	s0,t7,14064                                | 001be008: ffbf0018  sd	ra,24(sp)
- Changes tried: initial write syntax error and missing-source probe, no compilation/proof; v1 C11 cursor guard memory clobber (2); v2 accepted callee u32 return normalization with pointer cast (2); v3 C11 base guard memory clobber (2); v4 C11 bind base to $15 (2).
- Why it stops here: no improvement for 3 versions after v1; R7 streaks v1=0, v2=1, v3=2, v4=3.
- Next hypothesis: C11 introduce a separate arithmetic offset temporary consumed by the cursor guard, testing the dependency shape without binding s0; retain a fresh version name.
- Review: only empty asm; both guards and v4 binding each have an adjacent why comment. Earlier nm14 proof independently recounted as 2 words. No source/proof overwritten and no files outside WP written.
