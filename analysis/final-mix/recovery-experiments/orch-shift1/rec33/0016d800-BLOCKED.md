# 0016d800 blocked
- Range: 0016d800, 72 bytes. Versions tried: 4. Best: v1 with 2 differing words (72/72 bytes).
- First difference of the best version: !! 0016d814: 8de60004  lw	a2,4(t7)   | 0016d814: c5ec0008  lwc1	$f12,8(t7)
- Changes tried: v1 base (FVector return + operator=): 2 words. v2 separate temps in order: 2 words. v3 volatile int read: 5 words. v4 volatile float read: 5 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: only the lw a2 / lwc1 f12 order differs; try C10-style asm volatile("" ::: "memory") between the two loads, or pass the float as a struct member read after the int via a union.
