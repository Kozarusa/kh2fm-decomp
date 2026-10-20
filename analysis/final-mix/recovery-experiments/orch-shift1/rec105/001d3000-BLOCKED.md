# 001d3000 blocked
- Range: 001d3000, 92 bytes. Versions tried: 7. Best: v4 with 10 differing words (92/92 bytes).
- First difference of the best version: !! 001d3008: c5e000f8  lwc1	$f0,248(t7)  | 001d3008: c5e200f8  lwc1	$f2,248(t7)
- Changes tried: v1 plain C (12); v2 num/den temporaries (12, C11b); v3 direct expressions no temps (12); v4 in-place high-=low, value-=low, value/=high (10); v5 value-=low first plus ratio temp (12); v6 v4 with value-=low before high-=low (10); v7 value=(value-low)/high (10).
- Why it stops here: no improvement for 3 versions (v5, v6, v7 after best v4).
- Next hypothesis: original keeps the 0xf8 limit in $f0 and does value-low in the branch-likely delay slot ($f12 in place); try C11(c) register binding of high to $f0 is not possible for floats, so try volatile reads (C9) of the 0xf4/0xf0 fields or keeping high unmodified and using a separate den variable assigned after the 0xf4 load.