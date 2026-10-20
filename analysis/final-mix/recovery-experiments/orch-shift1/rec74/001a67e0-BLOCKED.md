# 001a67e0 blocked
- Range: 001a67e0, 108 bytes. Versions tried: 8. Best: v5 with 15 differing words (100/108 bytes).
- First difference of the best version: !! 001a67ec: 1080000f  beqz	a0,0x1a682c   vs   10800011  beqz a0,1a6834 (branch offsets; real structural difference is the loop back-edge: original has bnez t7 to an out-of-line "bne t7,s0 loop; nop; b exit; nop" block after the epilogue, compiled has beqz/nop/bne/move inline).
- Changes tried: v1 do-while with break (16 words, 112 bytes, tail call to free); v2 while(cur && (prev=cur, cur!=node)) (16); v3 empty asm memory barrier after free to stop tail call (16, 100 bytes, fixes the jal vs j); v4 nested-if continue loop (16); v5 inline step() helper + while (15); v6 do-while (15); v7 for(;;) two breaks (15); v8 nested-if continue with helper (15).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: the original loop has the cur!=0 test and the cur!=node test as separate blocks with the exit block 'b' placed out of line (jump-threaded); try a goto-based layout or a labelled found/not-found structure, or a two-level inlined iterator where the first level exits via a return flag (C7b/C7c).
