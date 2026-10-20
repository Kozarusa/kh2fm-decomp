# 001ad158 blocked
- Range: 001ad158, 116 bytes. Versions tried: 4. Best: v1 with 6 differing words (116/116 bytes).
- First difference of the best version: !! 001ad174: ffbf0028 sd ra,40(sp) | ffb00000 sd s0,0(sp) (prologue save order, s3/s4 assigned a1/a2 instead of a2/a1: original s3=a2,s4=a1, stores +8 then +4).
- Changes tried: v1 copy of earlier attempt (6); v2 swapped store order (8); v3 volatile stores (12); v4 temporaries for param_3/param_2 (6).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 register binding or asm+r on param_3 so it is allocated s3 before param_2 gets s4.
