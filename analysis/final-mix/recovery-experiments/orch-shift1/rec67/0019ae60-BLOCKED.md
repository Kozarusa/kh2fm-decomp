# 0019ae60 blocked
- Range: 0019ae60, 92 bytes. Versions tried: 4. Best: v1 with 20 differing words (84/92 bytes).
- First difference of the best version: !! 0019ae6c: 25ed0001  addiu t5,t7,1 | 0019ae6c: 25ee0001 addiu t6,t7,1.
- Changes tried: C3 u32 unmasked next (20), C3 s32 next (20), volatile count with masks (20).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Compute count+1 from the raw lbu before the andi/sltiu (original addiu t5,t7,1 precedes andi), keeping the store of the unmasked value and mask only at the compare; try a (u8) cast on a u32 loaded once, or a conditional-branch rewrite that yields beqzl with ld ra in the delay slot.
