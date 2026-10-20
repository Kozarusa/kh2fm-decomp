# 002b5108 blocked
- Range: 002b5108, 124 bytes. Versions tried: 4. Best: v2 with 17 differing words (140/124 bytes).
- First difference of the best version: `!! 002b5130: 0220302d  move a2,s1 | 002b5130: 0220202d  move a0,s1`
- Changes tried: fresh C++ reconstruction, 19 words; C11 post-store v0 output binding, 17 words; C11 function-scope v0 binding, 17 words; C11 separate third-argument temporary, 17 words.
- Why it stops here: R4.3 requires both outgoing callee results to flow out, but defined C++ return transport adds v0 preservation moves absent from the original; conservative R12 ABI blocking applies.
- Next hypothesis: resolve the mixed outgoing-result ABI contract, then isolate a2-before-a0 argument scheduling without discarding v0.
