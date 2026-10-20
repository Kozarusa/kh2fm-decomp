# 001c0410 blocked
- Range: 001c0410, 68 bytes. Versions tried: 6. Best: v3 with 3 differing words (68/68 bytes).
- First difference of the best version: !! 001c0418: 15e00009  bnez	t7,0x1c0440 (compiled bnezl, plus lhu/mtc1 using t7 instead of t6).
- Changes tried: C7 count++ after if, 17 -> 4 words (v2); C10d memory barrier after first store, 4 -> 3 (v3); C10c volatile first store, 4 (v4); temp for halfword with barrier, 3 (v5); C9 volatile u16 read, 8 (v6).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11 register binding for the lhu temp (t6) to avoid bnezl delay-slot duplication, or restructure with the store in a helper-free if/else (C7c).
