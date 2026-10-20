# 001e7470 blocked
- Range: 001e7470, 104 bytes. Versions tried: 2. Best: v2 with 5 differing words (100/104 bytes).
- First difference of the best version: !! 001e74b4: 240f0002  li	t7,2  | 001e74b4: 35ade010  ori	t5,t5,0xe010
- Changes tried: v1 memory barrier before last store (8 words); v2 barrier with "+r"(address) after last store (5 words). Both swap li/ori at 001e74b4 and keep the last sw in the jr ra delay slot (no trailing nop). The plain rec121 v1 (no barrier, 3 words) has correct li/ori order but also fills the delay slot.
- Why it stops here: R10-limited effort; every empty-asm barrier tried (also in rec121 v2/v4) either does nothing to the delay slot or reorders li/ori. Stopped after 2 versions as no cookbook change left that keeps li/ori order.
- Next hypothesis: make the epilogue jr ra a branch target (so reorg cannot fill the slot) e.g. via a source-level goto/early-exit structure, without adding a barrier that reorders li/ori.
