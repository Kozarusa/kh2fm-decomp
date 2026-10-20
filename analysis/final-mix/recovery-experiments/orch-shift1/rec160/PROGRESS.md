# rec160 progress
start 2026-10-16T14:41:02.4161001Z
claim 1 of 6: 00275f08 token 71bca7f48c6e40b0b03f0c052b5ba8d0 attempts 1 blocker null
R4.3: a0 signed full-width; negative exit preserves 139d78 result; positive exit preserves 192048 result. v1 baseline original; direct conditional translation.
00275f08 v1: 3 words; best v1 3 words; streak 0. v2 baseline orch1_rec160_00275f08_v1.cpp; C11b only split positive address into original base+1308 pointer and store408. Full source diff inspected; operand order unchanged.
00275f08 v2: 3 words; best v1 3 words; streak 1. v3 baseline orch1_rec160_00275f08_v2.cpp; only one pointer guard at positive field store. Full source diff inspected one added guard.
00275f08 v3: 0 words; best v3 0 words; streak 0. R8 audited one function, single commented empty guard, both return paths preserve outgoing results.
submitted 00275f08 v3
claim 2 of 6: 00276438 token 2b0a9d001b3743ffb4af5eb488f3692b attempts 1 blocker null
00276438 R4.3 audit: zero-global exit leaves entry v0; no drafts/probes. Conservative R12 ABI block, no fabricated zero or void.
blocked 00276438 -> abi-layout
claim 3 of 6: 00276a90 token 2af277bfe29c423380d283fb2f82c4bc attempts 1 blocker null
R4.3: no inputs; every exit v0 explicitly s3 result0/1. v1 baseline original; direct shared-result loop.
00276a90 v1: 17 words; best v1 17 words; streak 0. v2 baseline orch1_rec160_00276a90_v1.cpp; C11a only move offset increment after call; full diff inspected preserves expressions/conditions.
00276a90 v2: 17 words; best v1 17 words; streak 1. v3 baseline orch1_rec160_00276a90_v2.cpp; one empty index guard before increment; full diff inspected.
00276a90 v3: 17 words; best v1 17 words; streak 2. v4 baseline orch1_rec160_00276a90_v3.cpp; only make single index guard volatile; full diff inspected.
00276a90 v4: 15 words; best v4 15 words; streak 0. v5 baseline orch1_rec160_00276a90_v4.cpp; C11c only bind offset s0; full diff inspected.
00276a90 v5: 13 words; best v5 13 words; streak 0. v6 baseline orch1_rec160_00276a90_v5.cpp; C11a only move index increment below flag test; full source diff inspected.
00276a90 v6: 0 words; best v6 0 words; streak 0. R8 audited all explicit0/1 exits; one function, each binding/guard commented.
submitted 00276a90 v6
claim 4 of 6: 00276b10 token dc6aac548d4244a0b551003c57fe7699 attempts 1 blocker null
R4.3: no args; nonempty32-loop final exit preserves final d78 or virtual-call result. v1 baseline original; direct loop with returned final result; callback a0 object.
00276b10 v1: 4 words; best v1 4 words; streak 0. v2 baseline orch1_rec160_00276b10_v1.cpp; C11b only table temporary; full source diff inspected preserves operand order.
00276b10 v2: 4 words; best v1 4 words; streak 1. v3 baseline orch1_rec160_00276b10_v2.cpp; C11c only table t6 binding; full diff inspected.
00276b10 v3: 3 words; best v3 3 words; streak 0. v4 baseline orch1_rec160_00276b10_v3.cpp; C11b only callback temporary; full diff inspected.
00276b10 v4: 3 words; best v3 3 words; streak 1. v5 baseline orch1_rec160_00276b10_v4.cpp; C11c only callback t7 binding; full diff inspected.
00276b10 v5: 1 words; best v5 1 words; streak 0. v6 baseline orch1_rec160_00276b10_v5.cpp; only use integer addition for second object address to preserve offset-first source operand order; full diff inspected.
00276b10 v6: 0 words; best v6 0 words; streak 0. R8 audit passes one function and separate why comments on both bindings; all final callee results preserved.
submitted 00276b10 v6
claim 5 of 6: 002799b0 token 776e6423930a40a18b55861447fae29b attempts 1 blocker null
R4.3: no args, v0/f0 never set and no callees; void permitted. v1 baseline original; direct sum loop.
002799b0 v1: 23 words; best v1 23 words; streak 0. C1 audit no missing paths. v2 baseline orch1_rec160_002799b0_v1.cpp; C9 only global pointer volatile to preserve reloads; full diff inspected.
002799b0 v2: 27 words; best v1 23 words; streak 1. v3 baseline orch1_rec160_002799b0_v1.cpp; one empty memory guard after initial store only; full diff inspected.
002799b0 v3: 18 words; best v3 18 words; streak 0. v4 baseline orch1_rec160_002799b0_v3.cpp; only one new memory guard after sum store, initial guard unchanged; full diff inspected.
002799b0 v4: 21 words; best v3 18 words; streak 1. v5 baseline orch1_rec160_002799b0_v4.cpp; only integer row addition preserving index-first source order; full diff inspected.
002799b0 v5: 21 words; best v3 18 words; streak 2. v6 baseline orch1_rec160_002799b0_v3.cpp; C11b only sum load temporary preserving addition order; full diff inspected.
002799b0 v6: 18 words; best v3 18 words; streak 3. Stop R7.
blocked 002799b0 -> register-allocation
claim 6 of 6: 0027a108 token 5617b6a0db094278b2202bc84b66bf36 attempts 1 blocker null
R4.3: no args; each exit preserves bc0/acc8/acb8 or tailaa40 result. v1 baseline accepted packet sibling 00271e08; adaptation exact address and mode15 from original; declarations copied.
0027a108 v1: 0 words; best v1 0 words; streak 0. R8 audit one function/no asm, all callee result exits preserved.
submitted 0027a108 v1
R11 written 2026-10-16T14:48:01.7479248Z; K6 exhausted; root review pending.
