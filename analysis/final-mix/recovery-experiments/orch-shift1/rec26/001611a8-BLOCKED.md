# 001611a8 blocked
- Range: 001611a8, 128 bytes. Versions tried: 8. Best: v1 with 3 differing words (128/128 bytes, bnezl head wrong); v6 matches the whole head including bnezl (16 words differ later).
- First difference of the best version (v1): !! 001611d8: 56000002  bnezl s0,0x1611e4 | beqz s0,1611e4 (loads swapped).
- Changes tried: comma-expression loop (3); for(;;) Ghidra form (28); __builtin_expect x2 (3, no effect); goto with out-of-line advance block, no loop (24, but produced bnezl); same goto inside for(;;) (16, head including bnezl matches, exit/body layout swapped: compiled does beqz a0 to epilogue and body inline, original bnez a0 to body placed after the epilogue); if(next!=0){call;continue;}return (16); break form (16).
- Why it stops here: budget reached.
- Next hypothesis: keep the goto structure of v6 (it yields the original bnezl head) and change only the exit/body layout (e.g. do-while or a second goto so the call block sits after the return).