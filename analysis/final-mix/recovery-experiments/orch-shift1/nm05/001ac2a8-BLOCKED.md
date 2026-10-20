# 001ac2a8 blocked
- Range: 001ac2a8, 100 bytes. Versions tried: 6. Best: v3 with 2 differing words (100/100 bytes).
- First difference of the best version: !! 001ac2d0: 00c0982d  move	s3,a2 | 001ac2d0: 00e0902d  move	s2,a3 (a2/a3 saves swapped; original saves a2 first, a3 in the beqz delay slot)
- Changes tried: v1 empty "+r" guard on second (23); v2 guard on third (22); v3 local copies of second then third before the if (2); v4 identical to v3 by a failed edit (2); v5 copies in the order third then second (2); v6 volatile store of object[2] (2).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: bind the local copies of third/second to explicit s registers while keeping both parameters otherwise unguarded, or reorder the prologue-visible uses (use second before the if).
