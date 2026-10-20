# 00172fb0 blocked
- Range: 00172fb0, 84 bytes. Versions tried: 6. Best: v3 with 6 differing words (84/84 bytes).
- First difference of the best version: !! 00172fd8: a7af0008  sh	t7,8(sp)  (compiled has sb t5,1(sp) there; stores of u16 at 8/4/6 and byte 0 are scheduled 1,2,0,6,8,4 instead of 8,1,2,0,4,6).
- Changes tried: v1 baseline 11 words; v2 s32 a1 param (C2/C4 lwu->lw) 7; v3 u32 mask temp for 0xffff (C11) 6; v4 source reorder 8,1,2,0,4,6 (C10a) 6 identical output; v5 struct local 7; v6 volatile local stores (C10c) 15.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(d) asm volatile memory barrier after the first (offset 8) store, keeping v3 form.
