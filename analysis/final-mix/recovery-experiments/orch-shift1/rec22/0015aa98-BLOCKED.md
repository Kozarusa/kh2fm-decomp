# 0015aa98 blocked
- Range: 0015aa98, 92 bytes. Versions tried: 7. Best: v4 with 2 differing words (92/92 bytes).
- First difference of the best version: !! 0015aad0: ae120018  sw	s2,24(s0) (compiled swc1 $f20,28(s0); the original stores 0x20, 0x18, 0x1c, v4 emits 0x20, 0x1c, 0x18).
- Changes tried: v1 plain stores in original order (3 words, emitted 1c,20,18); v2 source reordered 1c,20,18 (5, register allocation swapped); v3 all three stores volatile (4, epilogue loads hoisted above stores); v4 volatile on 0x20 and 0x18 only (2); v5 volatile on 0x18 and 0x1c only (4, allocation swapped); v6 plain stores plus memory barrier before the float store (4, prologue order changed); v7 volatile float store only (3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C10, from v4 keep 0x20 volatile and make 0x1c volatile too after placing the 0x18 store plain, or put the memory barrier between the 0x20 and 0x18 stores.