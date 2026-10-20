# 001aa8f0 blocked
- Range: 001aa8f0, 76 bytes. Versions tried: 6. Best: v3 with 5 differing words (76/76 bytes).
- First difference of the best version: !! 001aa8f4: 00a0702d  move	t6,a1  |  001aa8f4: 0080782d  move	t7,a0
- Changes tried: v1 copy of rec78 v5 (8 words); v2 object copy bound to $15 for some reads (17); v3 f32 second = object[10] read into a local before the last read (5, best); v4 swapped the two local reads (5); v5 d bound to $9 with guard (7); v6 object+64 via integer add (5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original reads lw t2,56 and lwc1 via t7 but addiu a1 and lw a0 from a0, with moves t6 and t7 first; try a statement-order change that makes the compiler copy a0 to t7 after a1 to t6 (e.g. bind object to $15 only for the object[14] read).
