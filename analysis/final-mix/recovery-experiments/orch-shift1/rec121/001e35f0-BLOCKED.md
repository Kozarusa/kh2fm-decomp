# 001e35f0 blocked
- Range: 001e35f0, 96 bytes. Versions tried: 1. Best: v1 with 2 differing words (96/96 bytes).
- First difference of the best version: !! 001e3600: 3c0e0037  lui t6,0x37 | compiled lui t6,0x0 (jump table address D_0036eb28 is an unresolved relocation in the compiled object).
- Changes tried: v1 plain switch on byte at +168 with cases 2,4,6,8,10,12 -> 2 words (only the lui/addiu of the switch jump-table address differ; all other instructions match).
- Why it stops here: the remaining difference is the compiler-generated .rodata jump table address, which source cannot set to 0x0036eb28; no cookbook change affects it.
- Next hypothesis: the table address is only fixed by the full-build link layout; orchestrator should check whether the probe accepts jump-table relocations.
