# 001884d0 blocked
- Range: 001884d0, 128 bytes. Versions tried: 4. Best: v1 with 4 differing words (128/128 bytes).
- First difference of the best version: !! 00188518: dfbf0010  ld	ra,16(sp) | 00188518: 94450014  lhu	a1,20(v0)  (lhu of the half argument is scheduled early in ours, last in the original delay slot of the tail j)
- Changes tried: v1 straight mirror with u8* entry and array global (4 words); v2 volatile u16 read (15, adds andi); v3 u16 id local after stores (4); v4 struct Pair global and struct Entry (4).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10(a) reorder statements so the entry load occurs after the second store, e.g. read source[1] into a temp before the first store, or C11(b) introduce a temp for the 136 value; or C10(d) memory barrier before the call.
