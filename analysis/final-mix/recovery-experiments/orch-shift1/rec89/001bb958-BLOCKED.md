# 001bb958 blocked
- Range: 001bb958, 88 bytes. Versions tried: 5. Best: v2 with 21 differing words (84/88 bytes).
- First difference of the best version: !! 001bb95c: ffbf0000  sd	ra,0(sp)                                      | 001bb95c: 14800008  bnez	a0,1bb980 <func_001bb958+0x28>
- Changes tried: v1 u32 callee return (21, 92 bytes, extra dsll32/dsrl32); v2 u64 callee return (21, 84 bytes; body now matches, only the prologue differs); v3 combined conditions with && (23, s0 saved); v4 if/else early return (21); v5 u64 param with s64 cast (21).
- Why it stops here: no improvement for 3 versions. All remaining differences are one shift: the original has sd ra before the bnez with a nop in the delay slot, while the compiler fills the delay slot with sd ra.
- Next hypothesis: force sd ra out of the delay slot, for example reading a0 through a volatile or inserting an asm volatile memory barrier before the first branch (C12/C7), or wrap the prologue-visible work so the first branch is not delay-fillable.
