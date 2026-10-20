# 001e3590 blocked
- Range: 001e3590, 96 bytes. Versions tried: 1. Best: v1 with 2 differing words (96/96 bytes).
- First difference of the best version: !! 001e35a0: 3c0e0037  lui	t6,0x37 | 001e35a0: 3c0e0000  lui	t6,0x0
- Changes tried: v1 plain switch on u8 at +168 (cases 1,3,5,7,9,11 -> 1..6, default 0): all instructions match except the lui/addiu of the jump-table address (D_0036eaf8), which is an unresolved relocation (0 in the compiled object). 2 words.
- Why it stops here: R3-like; the only differing words are the jump table address relocation, which source cannot change. No accepted source in the reference tree uses switch, so there is no pattern to copy.
- Next hypothesis: orchestrator should check whether the probe/full build resolves the .rodata jump table relocation for switch functions; otherwise no source-only change exists.