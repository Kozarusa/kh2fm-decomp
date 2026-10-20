# 0020e800 blocked
- Range: 0020e800, 84 bytes. Versions tried: 4. Best: v1 with 20 differing words (84/84 bytes).
- First difference of the best version: !! 0020e800: 7c800000  sq	zero,0(a0)  | 0020e800: 0006782a  slt	t7,zero,a2
- Changes tried: v1 plain Quad(TI) zero store (20); v2 C10c volatile Quad store, output identical (20); v3 aligned struct zero copy (24, adds frame); v4 union Node with Quad member, store order fixed but still scheduled differently and por+sq instead of sq zero (20).
- Why it stops here: no improvement for 3 versions. Original is unscheduled (sq zero,0(a0) first, jr with nop delay slot, lui 0x2000 not hoisted); compiler schedules and emits por+sq.
- Next hypothesis: obtain sq zero directly (precedent lq/sq primitive or a zeroed-register quad) and find a construct that prevents scheduling; C10d asm memory barrier after the quad store.
