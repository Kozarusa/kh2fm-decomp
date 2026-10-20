# 001ac2a8 blocked
- Range: 001ac2a8, 100 bytes. Versions tried: 4. Best: v1 with 2 differing words (100/100 bytes).
- First difference of the best version: !! 001ac2d0: 00c0982d  move s3,a2 (original) vs 00e0902d move s2,a3 (compiled); the a2/a3 moves are swapped around the beqz delay slot.
- Changes tried: v1 explicit $19/$18 bindings for second/third (2); v2 copy only second (2); v3 copy only third (2); v4 plain copies with one store barrier removed (10, parameter registers swap).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the delay-slot filler choice is scheduler-driven; try making the first != 0 test use a copy of first (separate local) or use second in the call-free path, e.g. a volatile read of second, so that the a2 move is scheduled last before the branch.