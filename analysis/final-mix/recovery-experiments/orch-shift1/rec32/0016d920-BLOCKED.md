# 0016d920 blocked
- Range: 0016d920, 72 bytes. Versions tried: 8. Best: v7 with 4 differing words (72/72 bytes).
- First difference of the best version: !! 0016d93c: 27a40010  addiu	a0,sp,16 | 0016d93c: 8c8f0000  lw	t7,0(a0)
- Changes tried: v1 two Quad locals (10 words); v2 swapped declaration order (10); v3 Quad buffer[2] fixes stack slots (10); v4 volatile Pair* (9); v5 explicit destination pointer (9); v6 register Quad asm("$8") temporaries fixes quad register (10); v7 plus asm memory barrier between the copies (4); v8 plus explicit destination pointer before second load (4, identical diff).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: original loads pair->first via s0 after addiu a0,sp,16 and stores through a0 (move a1,sp in the jal delay slot); compiler reads the pair through a0 and addresses sp directly. Try making pair a register-bound s0 copy (C11c/d) or reading pair->first through a volatile pointer so the load uses s0 after destination is formed.