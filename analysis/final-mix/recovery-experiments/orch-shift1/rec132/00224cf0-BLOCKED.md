# 00224cf0 blocked
- Range: 00224cf0, 76 bytes. Versions tried: 1. Best: v1 with 4 differing words (84/76 bytes).
- First difference of the best version: !! 00224d08: 3c0e0037 lui t6,0x37 | 00224d08: 3c0e0000 lui t6,0x0.
- Changes tried: C1: reconstructed the switch and confirmed all paths against pseudocode; v1 has 4 differing words.
- Why it stops here: R12 conservative block. The original range omits the case 3 block needed for the documented 0x600000 assignment; compiler places that block at 00224d3c and 00224d40, beyond the 76-byte target. Remaining in-range differences are jump-table relocation address words, not a misdecoded D_ global.
- Next hypothesis: Check function boundary and jump-table relocation tooling before further source variants. The recovered switch matches every in-range instruction except the two jump-table address words, but needs the trailing case block outside this range.