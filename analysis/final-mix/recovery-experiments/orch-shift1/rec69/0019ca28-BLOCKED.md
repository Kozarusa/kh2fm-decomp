# 0019ca28 blocked
- Range: 0019ca28, 104 bytes. Versions tried: 5. Best: v2 with 5 differing words (104/104 bytes).
- First difference of the best version: !! 0019ca3c: 8caf0000  lw	t7,0(a1)                                      | 0019ca3c: afa0000c  sw	zero,12(sp) (+ continuation line: original lw t7,0(a1) vs compiled sw zero,12(sp)).
- Changes tried: v1 baseline struct 16B (11 words, frame too small); v2 C12 pad struct to 32B (5 words); v3 C10a move pointer=0 after first copy (5, same); v4 pointer=0 just before call (5); v5 C10c volatile pointer (5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10d asm volatile memory barrier / different local layout so the zero store is scheduled after lw+addiu (original order: lw, addiu a0, sw zero 12(sp), move a1, sw 4(s0)).
