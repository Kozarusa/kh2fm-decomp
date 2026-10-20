# 002a9ce8 blocked
- Range: 002a9ce8, 68 bytes. Versions tried: 1. Best: v1 with 15 differing words (64/68 bytes).
- First difference of the best version: !! 002a9cf0: ffb00000 sd s0,0(sp) | 002a9cf0: 0c040d5c jal 103570 <func_00103570>.
- Changes tried: v1 corrected allocator argument, address, and forwarded outgoing callee result; 15 words. No subsequent control.
- Why it stops here: R12 conservative block; first difference is prologue delay scheduling, with none of C12 controls applicable (no s-register binding, no volatile local, result already separate).
- Next hypothesis: prologue save scheduling requires a covered, ABI-preserving compiler control not supplied by this manual.
