# 00154ee8 blocked
- Range: 00154ee8, 72 bytes. Versions tried: 5. Best: v1 with 8 differing words (64/72 bytes).
- First difference of the best version: !! 00154efc: 51a00008  beqzl	t5,0x154f20                                | 00154efc: 51a00006  beqzl	t5,154f18 <func_00154ee8+0x30>
- Changes tried: v1 switch with result init 0x43 gives 8; v2 literal Ghidra if-chain collapses to 32 bytes (14); v3 switch with early returns in cases 0 and 2 gives 8; v4 switch with every case assigning result gives 8; v5 switch with a return in every case gives 8.
- Why it stops here: no improvement for 3 versions (the compiler always merges the two li 72 return blocks; the original keeps a separate jr ra block for value 0 and a bnel/b pair for value 2).
- Next hypothesis: C7(b)/(c): separate ifs with a volatile read of the value, or if/else instead of the switch so the case 0 and case 2 exits stay distinct blocks.