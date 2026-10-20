# 001144e8 blocked
- Range: 001144e8, 104 bytes. Versions tried: 5. Best: v2 (also v4) with 24 differing words (96/104 bytes).
- First difference of the best version: !! 001144ec: ffa50000  sd	a1,0(sp)  | 001144ec: 8c8e0010  lw	t6,16(a0)
- Changes tried: v1 key as u64 read via (s32*)&key (25); v2 key as 8-byte struct by value {low,high} (24, key loads from stack now match); v3 separate cursor variable (25); v4 result=0 declared up front (24); v5 index-based loop over base pointer (25).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original spills a1 to the stack (sd a1,0(sp)) BEFORE loading table->entries and sets v0=0 and v0=entries (loop pointer in v0, entries copy in t7) before the loop; try making the key address-taken/volatile-ish (C9/C10 asm barrier after the spill) or a do-while with the pointer as the return variable (C12b).
