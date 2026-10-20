# 001a3820 blocked
- Range: 001a3820, 72 bytes. Versions tried: 4. Best: v1 with 12 differing words (68/72 bytes).
- First difference of the best version: !! 001a3834: 11c0000a  beqz	t6,0x1a3860 | 001a3834: 15c00005  bnez	t6,1a384c
- Changes tried: C7 if/else with result variable (v2, 12 words); C13 u16 return type (v3, 12 words); C7 swap order, test 18 first (v4, 14 words). Compiler never emits the tail call (j) and emits jal plus epilogue.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: force tail call (original uses j func_001a67b0 with branch-likely beql), e.g. switch(type) or volatile read of command[2] (C9), or declare func_001a80c8 returning a pointer.