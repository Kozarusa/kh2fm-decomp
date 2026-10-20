# 00198aa8 blocked
- Range: 00198aa8, 56 bytes. Versions tried: 5. Best: v2 with 1 differing word (56/56 bytes); v3 and v4 also 1.
- First difference of the best version: !! 00198ad4: 008f7821  addu	t7,a0,t7  (compiled: 01e47821  addu	t7,t7,a0; operand order of the address add).
- Changes tried: v1 direct (11 -> mult order wrong); v2 total temp (1 word); v3 swapped addend order (1); v4 u8* object param (1); v5 separate offset/address temps (8).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11c bind the scaled index (index*12) to register 15 / add asm("" : "+r") on it so the add is emitted as addu object,scaled; or compute total after address.
