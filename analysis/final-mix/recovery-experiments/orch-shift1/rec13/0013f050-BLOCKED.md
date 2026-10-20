# 0013f050 blocked
- Range: 0013f050, 128 bytes. Versions tried: 4. Best: v1 with 16 differing words (136/128 bytes).
- First difference of the best version: !! 0013f090: 108e000d  beq	a0,t6,0x13f0c8  (compiled: bne a0,t6,13f0a0; inline tail-call blocks instead of out-of-line blocks after a beq/beqz/beq/bne chain with ld ra in the first delay slot).
- Changes tried: v1 early-return if chain (16 words); v2 switch order 0,1,2,3 (worse); v3 else-if chain order 1,0,2,3 (16); v4 switch order 1,0,2,3 (18).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original tail-call blocks are placed out of line after the compare chain with a shared ld ra in the first delay slot; try non-tail calls followed by a shared return, or volatile reads (C9) / goto-based block order (C7).
