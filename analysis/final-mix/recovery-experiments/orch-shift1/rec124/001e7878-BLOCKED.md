# 001e7878 blocked
- Range: 001e7878, 104 bytes. Versions tried: 4. Best: v1 with 9 differing words (104/104 bytes); v2 also 9 and is the same code with the correct field offset 120 (v1 had a wrong offset 116).
- First difference of the best version: !! 001e7888: 0000802d  move	s0,zero | 001e7888: 0080802d  move	s0,a0
- Changes tried: v2 fix field offset (9 words, only s0/s1 swapped, C11); v3 identical to v2 by a failed edit (9); v4 C11b temp copy of the argument (12).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11c bind index to s0 / object to s1 with register ... asm("$16")/("$17") each with a why comment, or C11a restructure as a for loop.
