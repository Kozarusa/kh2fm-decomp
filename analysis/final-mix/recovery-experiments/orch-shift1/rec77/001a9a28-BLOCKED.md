# 001a9a28 blocked
- Range: 001a9a28, 64 bytes. Versions tried: 6. Best: v3 with 7 differing words (84/64 bytes).
- First difference of the best version: !! 001a9a30: 3c0e0037  lui	t6,0x37  |  001a9a30: 3c0e0000  lui	t6,0x0
- Changes tried: v1 plain switch, no jump table (16 words, 32 bytes); v2 grouped cases, range check (16, 44 bytes); v3 separate identical bodies per case 0,2-5 gives the exact jump-table dispatch, but table address is local (lui/addiu 0) and one extra duplicated 5-word body remains (7); v4 return instead of break (7); v5 computed goto through extern D_0036d61c (15, goto dropped); v6 computed goto with label address taken via volatile (16).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: reference the table as extern D_0036d61c (address-materialization) while keeping a single shared body; e.g. computed goto where labels stay reachable, or a switch on a pointer-table lookup written with asm, copied from an accepted jump-table sibling.
