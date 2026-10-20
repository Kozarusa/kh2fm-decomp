# 00239e60 blocked
- Range: 00239e60, 88 bytes. Versions tried: 4. Best: v1 with 2 differing words (88/88 bytes).
- First difference of the best version: !! 00239e68: 25ef14bc addiu t7,t7,5308 | 00239e68: e48d0138 swc1 $f13,312(a0).
- Changes tried: v1 copied the named best, 2 words; v2 C10c made only the y store volatile, 2 words; v3 C10d placed a memory barrier between x and y stores, 2 words; v4 C11c bound the initialized pointer to numeric register 15, 2 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Starting from v3, make the global constant read volatile to constrain its scheduling relative to flag initialization.