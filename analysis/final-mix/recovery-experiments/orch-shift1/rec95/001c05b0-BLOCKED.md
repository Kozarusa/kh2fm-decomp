# 001c05b0 blocked
- Range: 001c05b0, 100 bytes. Versions tried: 5. Best: v2 with 2 differing words (100/100 bytes).
- First difference of the best version: !! 001c0600: 25ee9350  addiu	t6,t7,-27824   ; = D_01d49350 (compiled has lui t6 at that slot; the second global is addressed as 0x1d5 lui + -27820 offset, original uses addiu t6 base then 4(t6)).
- Changes tried: C1 two separate if(id==0xffff) blocks, 13 -> 2 words (v2); v3 identical to v2 (edit failed), 2; pointer base &D_01d49350 with pair[1], 2 words but addiu after the first sw (v4); asm +r pin on pointer, 3 (v5).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: declare the two globals as one struct/array D_01d49350 and use an s32* pointer assigned before the first store with the first store through a separate global alias (C11 ordering), or pass the pointer via a temp assigned before the loop-free block.
