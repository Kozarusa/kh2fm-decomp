# 0019ca28 blocked
- Range: 0019ca28, 104 bytes. Versions tried: 4. Best: v1 with 5 differing words (104/104 bytes); v2 also 5.
- First difference of the best version: !! 0019ca3c: 8caf0000  lw	t7,0(a1)  | compiled afa0000c  sw	zero,12(sp) (zero store scheduled first).
- Changes tried: v1 local first=source[0] plus memory barrier after out.pointer=0 (5, different shape); v2 local first without barrier (5, same as rec69 v2); v3 barrier before out.pointer=0 (11); v4 u32 pointer field, zero store after first copy, barrier before call (25).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: make the whole Out local a union/array so the zero store is a store through the object pointer after addiu a0, or compute object+1 into a local before the copies so addiu a0 precedes sw zero.
