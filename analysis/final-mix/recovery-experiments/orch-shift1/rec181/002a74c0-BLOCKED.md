# 002a74c0 blocked
- Range: 002a74c0, 108 bytes. Versions tried: 5. Best: v2 with 2 differing words (108/108 bytes).
- First difference of the best version: !! 002a74ec: 258c0001 addiu t4,t4,1 | 002a74ec: 01ab6804 sllv t5,t3,t5.
- Changes tried: v1 unsigned fresh mirror 11; C11(b) v2 mask temporary 2; C11(a) v3 move mask calculation after increment 2; C11(d) v4 bit guard consuming incremented index 2; C9/C11(d) v5 mask memory guard 16.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11(c) bind an existing increment or mask temporary to constrain scheduler without adding another live value.
