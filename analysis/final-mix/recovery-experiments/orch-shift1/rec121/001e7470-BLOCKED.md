# 001e7470 blocked
- Range: 001e7470, 104 bytes. Versions tried: 4. Best: v1 with 3 differing words (104/104 bytes... compiled one word shorter: no trailing nop).
- First difference of the best version: !! 001e74cc: adcf0000  sw t7,0(t6) | 001e74cc: 03e00008  jr ra
- Changes tried: v1 plain volatile u32 accesses (loop nops come out of the compiler), 3 words: final sw is placed in the jr ra delay slot while original has sw, jr ra, nop. v2 empty asm volatile memory barrier after last store, 5 words (also swaps li/ori order). v3 volatile pointer variable for 0x1000a000, 11 words. v4 empty asm volatile (no clobber) after last store, 5 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: find a source form that leaves the last store out of the delay slot without reordering li/ori (e.g. a final volatile read of an unrelated constant mapped to an unused register, or a union/struct based register block access).
