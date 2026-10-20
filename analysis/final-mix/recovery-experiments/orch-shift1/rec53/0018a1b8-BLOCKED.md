# 0018a1b8 blocked
- Range: 0018a1b8, 96 bytes. Versions tried: 5. Best: v1 with 7 differing words (96/96 bytes).
- First difference of the best version: !! 0018a1dc: 11e0000b  beqz	t7,0x18a20c  | 0018a1dc: 11e0000c  beqz	t7,18a210 (delay slot gets move v0,zero instead of move a2,t4; loop cursor is t4 instead of a2)
- Changes tried: v2 separate cursor var (18 words); v3 reuse param `current` as cursor (16, registers match but extra move v0,zero in the beqz delay slot); v4 early return 0 when entry>=end (16); v5 Ghidra while(1) structure (20).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: in v3 the registers match; stop the compiler filling the beqz delay slot with move v0,zero (for example make the null result come from a variable assigned after the loop, or a volatile pointer read of current) so move a2,t4 sits in the delay slot.
