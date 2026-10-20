# 0011f078 blocked
- Range: 0011f078, 124 bytes. Versions tried: 8. Best: v7 with 6 differing words (124/124 bytes).
- First difference of the best version: !! 0011f0a8: 02507821  addu	t7,s2,s0   | compiled: 0202102a  slt	v0,s0,v0
- Changes tried: v1 plain while with done flag (18 words); v2 positive compare with early returns (~17); v3 result variable preset to 1 with break (~17, C7); v4 two separate ifs, shared epilogue (~15); v5 Ghidra bool done=count<=index (~14, extra xori); v6 bool more=index<count with if(more) body first (~16, blocks swapped); v7 if(!more){result=0;break;} then flag test break (6 words, C7b); v8 v7 plus more computed before entry plus inverted flag test with continue (6 words, no change).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: remaining diffs are the addu/slt order and the flag-test branch sense (bnezl to shared epilogue then b loop vs compiled beqzl); try C8/C9 volatile read of the entry byte, or restructure as for(;;) with index++ in the condition.
