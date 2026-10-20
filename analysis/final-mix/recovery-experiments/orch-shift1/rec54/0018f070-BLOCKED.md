# 0018f070 blocked
- Range: 0018f070, 64 bytes. Versions tried: 5 (v1 compile error). Best: v2 with 13 differing words (56/64 bytes).
- First difference of the best version: !! 0018f070: 10800009  beqz	a0,0x18f098 | 0018f070: 1080000b  beqz	a0,18f0a0 <func_0018f070+0x30>
- Changes tried: v2 do/while with result var (13); v3 rewrite as while(1) with early returns (13); v4 if/else instead of load-then-override (13); v5 ternary do/while with break (14).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: original is an unrotated loop (back edge is a plain b to a bnezl load-select head, return-0 inline at the loop exit); try goto-based layout or a for(;;) with the node test as a volatile read (C9) to get bnezl and the inline v0=0 block.
