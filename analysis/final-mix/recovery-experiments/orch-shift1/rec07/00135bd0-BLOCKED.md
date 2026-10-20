# 00135bd0 blocked
- Range: 00135bd0, 128 bytes. Versions tried: 6. Best: v2 with 2 differing words (128/128 bytes).
- First difference of the best version: !! 00135c34: 25ce0001  addiu	t6,t6,1                                    | 00135c34: adf20010  sw	s2,16(t7)
- Changes tried: v1 baseline 25 words (compiler folded s1 to 32); v2 second compare against first-loaded variable -> 2 words; v3 explicit next temp -> 2; v4 slot pointer temp -> 3; v5 swapped store order -> worse; v6 count++ form -> 2.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10d asm volatile memory barrier between the two stores, or make the count store volatile, to move addiu before the slot store (only addiu/sw order differs).
