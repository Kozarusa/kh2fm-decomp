# 0019eeb8 blocked
- Range: 0019eeb8, 120 bytes. Versions tried: 7. Best: v4 with 13 differing words (116/120 bytes); v7 also 13.
- First difference of the best version: !! 0019eef8: 01d06021  addu	t4,t6,s0 | 0019eef8: 020e8021  addu	s0,s0,t6
- Changes tried: v1 flat u32 array 21 words; v2 byte-offset addressing 21; v3 2D array 21; v4 hoisted row/word/mask locals outside if 13; v5 locals inside if 15 words-ish; v6 result preset before call 15; v7 u32 result with hoisted locals 13.
- Why it stops here: no improvement for 3 versions (v5, v6, v7).
- Next hypothesis: Bind the word pointer to t4 (register 12) and the result to t5 (13) with register asm bindings, or make the mask 1 a distinct constant from the preset result 1 (C11 c/d).
