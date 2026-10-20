# 002b1660 blocked
- Range: 002b1660, 120 bytes. Versions tried: 4. Best: v1 with 11 differing words (124/120 bytes).
- First difference of the best version: !! 002b167c: 54400013 bnezl v0,0x2b16cc | 002b167c: 54400014 bnezl v0,2b16d0.
- Changes tried: v1 fresh literal callee-result returns 11; C13 final call result assignment v2 11; final result empty guard v3 13; C11(c) result binding v4 13.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: express last conditional as if/else retaining outgoing callee result and local epilogue.
