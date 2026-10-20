# 0021ead0 blocked
- Range: 0021ead0, 128 bytes. Versions tried: 4. Best: v1 with 24 differing words (124/128 bytes).
- First difference of the best version: !! 0021eae8: c5e20000  lwc1	$f2,0(t7)   | 0021eae8: c5e10000  lwc1	$f1,0(t7)
- Changes tried: v1 volatile matrix + volatile table reads, constant via u8 array cast (24; all 16 stores in original order match); v2 volatile constant read (27); v3 cosine first, non-volatile reads (31); v4 separate index temps (24).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: same as 0021ea50/0021e9d0 family (sibling rotation builders): float registers allocated in a different order (orig cos f0, neg f1, sin f2, one f3) and the constant is loaded with lui/addiu/lwc1 0(t7) instead of folded; needs a shape that defeats offset folding without changing instruction order (a solution found for one sibling likely fixes all four).
