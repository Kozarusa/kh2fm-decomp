# 001c0ba0 blocked
- Range: 001c0ba0, 116 bytes. Versions tried: 6. Best: v3 with 6 differing words (116/116 bytes).
- First difference of the best version: !! 001c0bc0: 25e8f254  addiu	t0,t7,-3500 | 24080001 li t0,1
- Changes tried: v1 u8* base (18); v2 s32* header (18); v3 volatile loop-bound read (6); v4 bound reloaded in both branches (26); v5 local table pointer at top (8); v6 table pointer inside if (6, same as v3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: swap of t0/t1 (table address vs constant 1) plus original bnel with bound reload in delay slot (compiled uses bne+nop and a duplicated path); try C11 register binding for the table pointer to $8, or bound reload in else-path only.
