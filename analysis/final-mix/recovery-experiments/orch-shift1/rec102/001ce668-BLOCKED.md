# 001ce668 blocked
- Range: 001ce668, 96 bytes. Versions tried: 4. Best: v1 with 10 differing words (96/96 bytes).
- First difference of the best version: !! 001ce680: 25eeb9e0  addiu	t6,t7,-17952 | 001ce680: ade0b9e0  sw	zero,-17952(t7).
- Changes tried: v1 two identical if blocks with array globals 10; v2 local pointer variables 16; v3 separate scalar globals 20; v4 D_0036e2ec as array 10 (no change).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: in the original the base address (addiu t6) is computed before the first store and the f32 source address (lui/addiu t5) before the first block-2 store; try C10(d) memory barrier or volatile stores between the first store and the address use, or a struct type for the two blocks.