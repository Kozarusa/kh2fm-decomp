# 0028f690 blocked
- Range: 0028f690, 92 bytes. Versions tried: 7. Best: v4 with 4 differing words (92/92 bytes).
- First difference of the best version: !! 0028f6ac: 01a46821 addu t5,t5,a0 | 0028f6ac: 008d2021 addu a0,a0,t5.
- Changes tried: v1 direct translation 9; C11a count initialization reorder v2 10; C11b remove base temporary v3 12; C11c count $14 binding v4 4; C11c pointer $12 binding v5 8; C11d pointer guard v6 8; C11c value $13 binding v7 8.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C11b introduce address temporary preserving D_0035f480 then index operand order.
- R4.3: sole return path defines v0 as selected pointer, no callee results or f0.
- R4.5: no callees.
