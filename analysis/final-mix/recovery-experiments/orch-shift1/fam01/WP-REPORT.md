# fam01 report
Status: partial
Worker: orch1-fam01, model sonnet. Started 2026-10-12T18:30:20Z, ended 2026-10-12T19:00:00Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 00139858 | 116 | blocked:branch-layout | 6 | 4 | orch1_fam01_00139858_v2.cpp |
| 001398d0 | 116 | blocked:branch-layout | 6 | 4 | orch1_fam01_001398d0_v3.cpp |
| 00139948 | 116 | blocked:register-allocation | 6 | 2 | orch1_fam01_00139948_v2.cpp |
| 001399c0 | 116 | blocked:register-allocation | 3 | 2 | orch1_fam01_001399c0_v1.cpp |
| 00139a38 | 116 | blocked:register-allocation | 4 | 2 | orch1_fam01_00139a38_v1.cpp |
| 00139ab0 | 116 | submitted | 1 | 0 | orch1_fam01_00139ab0_v1.cpp |

Totals: 1 submitted, 5 blocked, 0 released.
Problems: Only the last sibling (00139ab0) found the exact recipe; the five earlier ones were blocked before it was known. Recipe (identical shape in all six; only global callee differs, D_00347f80 is the same): in a comma-while condition `while ((head = D_00347f80, node = (cur == 0 ? head->next : *(Node* volatile*)&cur->next), cur = node, node != 0)) { if (node->key == key) func(node); }` with `struct Node { s32 pad0; Node* next; s32 pad8; s32 padc; s32 key; }`, cur starting at 0. Loading the head unconditionally is what puts it in a0. Not retried because K=6 forbids reclaiming blocked addresses.
Exact next step: re-queue the five blocked siblings (00139858, 001398d0, 00139948, 001399c0, 00139a38) and apply the 00139ab0 source with only the function name and callee changed (00139580, 00139570, 001395a8, 00139598, 001396d0).
