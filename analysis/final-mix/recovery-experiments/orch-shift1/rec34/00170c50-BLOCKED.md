# 00170c50 blocked
- Range: 00170c50, 124 bytes. Versions tried: 4. Best: v1 with 24 differing words (104/124 bytes).
- First difference of the best version: !! 00170c60: 1440000a  bnez	v0,0x170c8c | 00170c60: 14400012  bnez	v0,170cac <func_00170c50+0x5c>
- Changes tried: v1 Ghidra-shaped loop with continue 24 words; v2 do-while with || condition 24 (same output); v3 one variable for node and return value (t6 as original) 26 words (112 bytes); v4 v3 with xori-style (value<10000)^1 condition 26 (compiler folds it).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C7/C8 variants: store the slti result in a separate variable so xori+bnez and nop delay slots survive, and make the D_0034dca0 read inside the current!=0 branch volatile (original uses bnezl with the head load in the delay of the other path).