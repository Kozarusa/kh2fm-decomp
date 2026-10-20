# 001e0fe8 blocked
- Range: 001e0fe8, 124 bytes. Versions tried: 7. Best: v4 with 12 differing words (124/124 bytes).
- First difference of the best version: !! 001e1010: 000f7e00  sll	t7,t7,0x18 | 001e1010: 000e7600  sll	t6,t6,0x18
- Changes tried: v1 s8 pointer (22, lb instead of lbu); v2 u8 load with s8 casts (14, 120 bytes, redundant store dropped); v3 separate result variable (20); v4 volatile first store (12, size matches, conditional becomes movn); v5 v4 plus separate result (18); v6 if/else store (19); v7 all u8 with s8 sign tests (22).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the branch around li -128 (bgez t5) is replaced by movn; try C8(c) volatile read of the sign-extended value, or move the sign compare so the sra of t5 happens in the bgez delay slot (C7/C8).
