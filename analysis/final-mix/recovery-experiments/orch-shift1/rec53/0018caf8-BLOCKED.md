# 0018caf8 blocked
- Range: 0018caf8, 56 bytes. Versions tried: 1. Best: v1 with 2 differing words (56/56 bytes).
- First difference of the best version: !! 0018cb08: 3c0e0037  lui	t6,0x37  | 0018cb08: 3c0e0000  lui	t6,0x0 (second diff: addiu t6,t6,-13196 = D_0036cc74 vs 0)
- Changes tried: v1 plain switch over 0,1,3,4,6,7,0xf,0x10 returning 1, default 0 (2 words). Every other word, including the jump table sequence, matches.
- Why it stops here: the only differing words are the compiler-local jump table address (lui/addiu of D_0036cc74), unresolved in the standalone probe; no source change in the cookbook changes it.
- Next hypothesis: the orchestrator should check whether the probe/full-build resolves jump-table relocations (same pattern as 0018ca48); if it does, v1 source is the answer.
