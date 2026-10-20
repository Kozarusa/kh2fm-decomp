# 001f4e18 blocked
- Range: 001f4e18, 96 bytes. Versions tried: 5. Best: v2 with 8 differing words (96/96 bytes).
- First difference of the best version: !! 001f4e48: fe200070  sd	zero,112(s1)                                  | 001f4e48: fe200088  sd	zero,136(s1)
- Changes tried: v1 single base pointer (22 words, size 80); v2 two pointers first=base+0xa0 second=base+0xb0 (8); v3 all stores volatile (8, ld ra misplaced); v4 only second-group volatile (9); v5 memory barrier between groups (14).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(b) reorder independent zero stores in source so the scheduler emits sd 112,120,128,136 then sw 44,12,36 (e.g. put sd 136 earlier/later), or volatile on only the first-group u64 stores.
