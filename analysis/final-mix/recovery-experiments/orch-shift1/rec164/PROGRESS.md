# rec164 progress
start 2026-10-16T20:38:34.4563547Z
claim 1 of 6: 00283e48 token 0e59c51a86a2461898aebccfb71303fd attempts 1 blocker null
R4.3 no inputs; both exits tailcall result flows out preserved. v1 baseline original direct branch/tailcall.
00283e48 v1: 18 words; best v1 18 words; streak 0. v2 baseline orch1_rec164_00283e48_v1.cpp; only row guard before branch; full diff inspected.
00283e48 v2: 14 words; best v2 14 words; streak 0. v3 baseline orch1_rec164_00283e48_v2.cpp; C11c only row t6 binding; full diff inspected.
00283e48 v3: 18 words; best v2 14 words; streak 1. v4 baseline orch1_rec164_00283e48_v2.cpp; C11b only nextValue temporary retaining comparison operand order; full diff inspected.
00283e48 v4: 13 words; best v4 13 words; streak 0. v5 baseline orch1_rec164_00283e48_v4.cpp; only index t7 binding; full diff inspected.
00283e48 v5: 18 words; best v4 13 words; streak 1. v6 baseline orch1_rec164_00283e48_v4.cpp; only next-index guard at single site; full diff inspected.
00283e48 v6: 17 words; best v4 13 words; streak 2. v7 baseline orch1_rec164_00283e48_v4.cpp; C11a only reorder independent next/current declarations; full diff inspected.
00283e48 v7: 16 words; best v4 13 words; streak 3. Stop R7.
blocked 00283e48 -> register-allocation
claim 2 of 6: 002853b8 token a41ed6f03d4543ed80d839117e60fc51 attempts 1 blocker null
002853b8 R4.3 final fa90 outgoing result, sole accepted fa90 void. Conservative R12 ABI block zero versions.
blocked 002853b8 -> abi-layout
claim 3 of 6: 00285d18 token 12db9c8e8c834b438d1278ef551ea68e attempts 1 blocker null
R4.3 a0 full unmasked; exits explicit0/1. v1 baseline original direct pointer scan.
00285d18 v1: 19 words; best v1 19 words; streak 0. C1 audit no paths missing; v2 baseline orch1_rec164_00285d18_v1.cpp; C9 only volatile reads; full diff inspected.
00285d18 v2: 19 words; best v1 19 words; streak 1. v3 baseline orch1_rec164_00285d18_v1.cpp; only full-register comparison parameter s64; full diff inspected.
00285d18 v3: 19 words; best v1 19 words; streak 2. v4 baseline orch1_rec164_00285d18_v1.cpp; only cursor representation pointer to index, same conditions/returns; full diff inspected.
00285d18 v4: 10 words; best v4 10 words; streak 0. v5 baseline orch1_rec164_00285d18_v4.cpp; C7c only shared-result break instead early return1; full diff inspected.
00285d18 v5: 0 words; best v5 0 words; streak 0. R8 audit one function/no asm explicit0/1 all paths.
submitted 00285d18 v5
claim 4 of 6: 002865d0 token 3ed5ab2068c846a288b2b0d3571bc028 attempts 1 blocker null
R4.3 a0 word used shift/mask; every exit preserves v0 callee+204. v1 baseline original direct bit setter with returned base.
002865d0 v1: 4 words; best v1 4 words; streak 0. v2 baseline orch1_rec164_002865d0_v1.cpp; only one combined guard before branch; full diff inspected.
002865d0 v2: 3 words; best v2 3 words; streak 0. v3 baseline orch1_rec164_002865d0_v2.cpp; only word t6 binding; full diff inspected.
002865d0 v3: 4 words; best v2 3 words; streak 1. v4 baseline orch1_rec164_002865d0_v3.cpp; only add word dependency to existing single guard so AND follows OR; full diff inspected.
002865d0 v4: 0 words; best v4 0 words; streak 0. R8 audit one function own why on binding/guard; preserves callee+204 outgoing result.
submitted 002865d0 v4
claim 5 of 6: 00287430 token 642925cdf2a44e1ea06312711c1f5533 attempts 1 blocker null
R4.3 a0/a1 used words; all exits preserve callee+164 v0. v1 baseline original direct bitsetter.
00287430 v1: 23 words; best v1 23 words; streak 0. v2 baseline orch1_rec164_00287430_v1.cpp; only split decrement before multiplication preserving operands; full diff inspected.
00287430 v2: 18 words; best v2 18 words; streak 0. v3 baseline orch1_rec164_00287430_v2.cpp; only result v0 binding; full diff inspected.
00287430 v3: 11 words; best v3 11 words; streak 0. v4 baseline orch1_rec164_00287430_v3.cpp; only one OR/word dependency guard; full diff inspected.
00287430 v4: 0 words; best v4 0 words; streak 0. R8 audit one function binding/guard each why and returned callee+164 all paths.
submitted 00287430 v4
claim 6 of 6: 00287b30 token 7cfc07c0cfcc419781bca32472839963 attempts 1 blocker null
00287b30 R4.3 outgoing tailcall result, accepted declarations only void; conservative R12 ABI block no draft.
blocked 00287b30 -> abi-layout
R11 written 2026-10-16T20:45:28.3856045Z; K6 exhausted; root review pending.
