# 001d1760 blocked
- Range: 001d1760, 76 bytes. Versions tried: 7. Best: v4 with 8 differing words (68/76 bytes).
- First difference of the best version: !! 001d1768: 18a00007  blez	a1,0x1d1788 (compiled blez targets 1d1790; original has jr ra at 1788 with branch-likely beqzl+li v0,1 inside the first block, and a duplicated return tail with bnez/li v0,1 for the else path, compiled emits sltiu v0,t7,1).
- Changes tried: v1 early-return form (11); v2 swapped blocks with return 1 (12, result in t5); v3 returns in both (15); v4 single result variable, else-if (8); v5 else with literal returns (18); v6 else with return result/return 1 (18); v7 else-if return 1 (12).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C8 - keep the else-branch comparison from becoming sltiu (volatile read of the limit or a separate temp) so the duplicated bnez/jr tail is emitted.