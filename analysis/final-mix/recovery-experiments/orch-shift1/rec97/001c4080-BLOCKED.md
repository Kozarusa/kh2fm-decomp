# 001c4080 blocked
- Range: 001c4080, 60 bytes. Versions tried: 5. Best: v2 with 11 differing words (64/60 bytes).
- First difference of the best version: !! 001c4098: a5c50004  sh a1,4(t6) | a5c50002  sh a1,2(t6) (store order: scheduler emits the six stores in a different order than the source).
- Changes tried: v1 six separate u8/u16 globals (15); v2 one u16 array D_01d49574 plus u8* low=-4 base (11); v3 struct at D_01d49570 in natural order (13); v4 v2 with permuted store order (13); v5 single array with negative byte offsets, no low var (15).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original has base t6=&D_01d49574, t5=t6-4 CSE'd and a direct global sh; find the source store order and pointer variables that keep that order (C10b/C10c volatile stores through two pointers u16* a=D_01d49574 and u8* b=(u8*)a-4).
