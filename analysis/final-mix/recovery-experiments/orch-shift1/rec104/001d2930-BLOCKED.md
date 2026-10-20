# 001d2930 blocked
- Range: 001d2930, 112 bytes. Versions tried: 5. Best: v2 with 2 differing words (112/112 bytes).
- First difference of the best version: !! 001d295c: 01c0982d  move	s3,t6  (compiled has move s0,a1 here; the two moves are swapped, nothing else differs).
- Changes tried: v1 plain do-while (10 words, move s0,a1 hoisted into prologue); v2 local copy of count inside the if (2); v3 pre-decrement in loop condition (2); v4 nested ifs (2); v5 empty asm on the counter copy (2).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind the counter or the base pointer with register T name asm("$16")/("$19") to fix the order of move s3,t6 and move s0,a1.