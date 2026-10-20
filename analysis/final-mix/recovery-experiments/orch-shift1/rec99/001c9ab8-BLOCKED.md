# 001c9ab8 blocked
- Range: 001c9ab8, 124 bytes. Versions tried: 6. Best: v3 with 13 differing words (124/124 bytes).
- First difference of the best version: !! 001c9ad0: 14400010  bnez	v0,0x1c9b14 | 001c9ad0: 1440000f  bnez	v0,1c9b10 (original sets t7=1 in delay slot and returns through move v0,t7; compiled sets v0 directly).
- Changes tried: v1 return 0/return 1 with two separate ifs (18, bnezl and duplicated move zero); v2 single result variable with breaks (32, s2 saved); v3 merged || into one if (13); v4 result assigned after loop with goto (13, identical to v3); v5 early return 1 when func_001bc010 nonzero (14, t7 matches but failure branch polarity differs: bnez to loop-exit vs original beqz to shared failure block at end); v6 positive nested ifs with continue (14, identical to v5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original has two beqz branches to one shared "move t7,zero; b epilogue" block placed after the epilogue and the loop test falls into li t7,1; try a for-loop or while(1) with separate ifs that goto a common fail label, or a bool result variable compared at the exit.
