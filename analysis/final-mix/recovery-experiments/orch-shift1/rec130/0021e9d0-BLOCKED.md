# 0021e9d0 blocked
- Range: 0021e9d0, 128 bytes. Versions tried: 4. Best: v1 with 20 differing words (124/128 bytes).
- First difference of the best version: !! 0021e9e8: c5e10000  lwc1	$f1,0(t7)   | 0021e9e8: c5e30000  lwc1	$f3,0(t7)
- Changes tried: C9 volatile read of D_00370b48 (20, no effect), declare 'one' first (20), volatile matrix param pointer C10c (31 words, but all 16 stores and the f-register numbers then match the original; only the table-load order and the lui+addiu+lwc1 0 form of D_00370b48 differ).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: start from v4 (volatile matrix) and make the two table reads volatile (C9) so sin is loaded before the cos index arithmetic, and make D_00370b48 reach the load through a separate address (pointer variable) to get addiu + lwc1 0(t7).
