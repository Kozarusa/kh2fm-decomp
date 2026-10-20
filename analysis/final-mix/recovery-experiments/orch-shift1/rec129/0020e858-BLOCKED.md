# 0020e858 blocked
- Range: 0020e858, 84 bytes. Versions tried: 6. Best: v3 with 18 differing words (84/84 bytes).
- First difference of the best version: !! 0020e858: 7c800000  sq	zero,0(a0)  | 0020e858: 70007ca9  por	t7,zero,zero
- Changes tried: v1 union Node with Quad member plus memory barrier after quad store (20); v2 volatile tail read (20); v3 added memory barrier after the word0 store (18, lui/addiu/or/sw now in original order); v4 barrier after clamps (18, no effect); v5 barrier before last store (18, no effect); v6 volatile slot pointer (18, no effect).
- Why it stops here: no improvement for 3 versions. Remaining diffs: quad zero emitted as por+sq instead of sq zero; original is unscheduled (clamp movz chain, table lui placed after sw, last store not in the jr delay slot; original has nop there).
- Next hypothesis: obtain a literal sq zero,0(a0) (precedent lq/sq primitive) and a way to stop the scheduler from hoisting lui 0x1db and filling the delay slot, e.g. register binding with C11(c) for t6/t7/t5.
