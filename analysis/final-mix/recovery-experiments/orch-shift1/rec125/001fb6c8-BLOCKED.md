# 001fb6c8 blocked
- Range: 001fb6c8, 84 bytes. Versions tried: 6. Best: v3 with 10 differing words (84/84 bytes).
- First difference of the best version: !! 001fb6d8: 0000282d  move	a1,zero  | 001fb6d8: afad0014  sw	t5,20(sp)
- Changes tried: v1 Ghidra-order struct stores (13); v2 separate object copy, no effect (13); v3 ascending field order, float registers correct (10); v4 original store order (11); v5 inner first (14); v6 table last (11).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C9/C10, make the sw of inner (offset 20) late via volatile frame fields or barrier, or reorder the copies of the object pointer so t6=a0 move is first.