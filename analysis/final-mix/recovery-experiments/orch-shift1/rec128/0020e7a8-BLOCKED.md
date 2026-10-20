# 0020e7a8 blocked
- Range: 0020e7a8, 84 bytes. Versions tried: 4. Best: v1 with 20 differing words (84/84 bytes).
- First difference of the best version: !! 0020e7a8: 7c800000  sq	zero,0(a0)   vs compiled slt t7,zero,a2 (compiler emits por t7,zero,zero + sq t7 for a Quad zero, and schedules the clamp first)
- Changes tried: v2 __builtin_memset + barrier (link error, memset undefined); v3 (Quad)(u64)0 plus barrier 20 words; v4 register Quad bound to $0 plus barrier 20 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C14: the sq zero primitive (allowed only as a lq/sq copy after plain copy fails) or a zero source the compiler keeps as the zero register; also the store-order and clamp-order scheduling still differ after that.