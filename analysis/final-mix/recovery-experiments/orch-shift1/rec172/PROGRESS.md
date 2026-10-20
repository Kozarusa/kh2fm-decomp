# rec172 progress
start 2026-10-17T17:47:19Z
claim 1 of 6: 0028f4a0 token 2274fdd1434a4eb7a78d246778b9054f attempts 1 blocker null
0028f4a0 R4.3: sole jr ra path never sets v0/f0; no callees; pure leaf void. R4.5 no callees. v1 mirrors indexed halfword loop.
0028f4a0 v1: 0 words; best v1 0 words; streak 0; submitted 0028f4a0 v1
claim 2 of 6: 0028f690 token dbc196c0fa6a4733815d41fcd2722055 attempts 1 blocker null
0028f690 R4.3: sole exit returns v0 selected pointer; no f0, no callees. R4.5 none. v1 pointer return, defined optional result, nonnull iteration cursor.
0028f690 v1: 9 words; best v1 9 words; streak 0. Baseline orch1_rec172_0028f690_v1.cpp; C11a move count initialization before value load, full source diff checked; operand order preserved.
0028f690 v2: 10 words; best v1 9 words; streak 1. Baseline orch1_rec172_0028f690_v1.cpp; C11b remove base temporary only; full source diff checked, operand order preserved.
0028f690 v3: 12 words; best v1 9 words; streak 2. Baseline orch1_rec172_0028f690_v1.cpp; C11c bind defined count to numeric $14 only; full source diff checked, operand order preserved.
0028f690 v4: 4 words; best v4 4 words; streak 0. Baseline orch1_rec172_0028f690_v4.cpp; C11c bind defined pointer $12 only; full source diff checked.
0028f690 v5: 8 words; best v4 4 words; streak 1. Baseline orch1_rec172_0028f690_v4.cpp; C11d single pointer guard before base only; full source diff checked.
0028f690 v6: 8 words; best v4 4 words; streak 2. Baseline orch1_rec172_0028f690_v4.cpp; C11c bind defined value $13 only; full source diff checked.
0028f690 v7: 8 words; best v4 4 words; streak 3; blocked 0028f690 -> register-allocation
claim 3 of 6: 0028ff68 token cc1bc08873ef4113abeaeb43b0854160 attempts 1 blocker null
0028ff68 R4.3 mixed entry/callee exits; R12 ABI block zero versions. R4.5 no declaration drafted. blocked 0028ff68 -> abi-layout
claim 4 of 6: 00290488 token 353a1014d3ff4a7fb3ab261b43ad5443 attempts 1 blocker null
00290488 R4.3 mixed entry/callee exits; R12 ABI block zero versions. R4.5 no declaration drafted. blocked 00290488 -> abi-layout
claim 5 of 6: 002914a8 token 0ff5262f77ef4b23bd426deecabcb49c attempts 1 blocker null
002914a8 R4.3 sole jr ra: all paths v0=s0, initialized zero or one; integer return; input a1 value transported to a0, unused a0 retained as positional parameter. R4.5 exact extern C u32 func_001a80c8(...) copied from packet-named fm_primary_addresspair_recovered_001a6c60.cpp. v1 direct loop.
002914a8 v1: 29 words; best v1 29 words; streak 0. C1 audit params return declaration and all paths correct. Baseline orch1_rec172_002914a8_v1.cpp; move result init before call (original lifetime across call) only; full source diff checked.
002914a8 v2: 24 words; best v2 24 words; streak 0. Baseline orch1_rec172_002914a8_v2.cpp; C9 volatile table reads (global plus required cursor qualifier) only; full source diff checked.
002914a8 v3: 23 words; best v3 23 words; streak 0. Baseline orch1_rec172_002914a8_v3.cpp; C2 explicit signed char table/cursor type to request lb only; full source diff checked.
002914a8 v4: 23 words; best v3 23 words; streak 1. Baseline orch1_rec172_002914a8_v3.cpp; C20 signed byte comparison domain s64 throughout only; full source diff checked.
002914a8 v5: 23 words; best v3 23 words; streak 2. Baseline orch1_rec172_002914a8_v2.cpp; C10d one memory guard before key load only; full source diff checked. Best remains v3.
002914a8 v6: 20 words; best v6 20 words; streak 0. Baseline orch1_rec172_002914a8_v6.cpp; C2 key signedness only (byte remains 0..255); full source diff checked.
002914a8 v7: 20 words; best v6 20 words; streak 1. Baseline orch1_rec172_002914a8_v6.cpp; C7c initial negative early return instead of enclosing if only; full source diff checked.
002914a8 v8: 24 words; best v6 20 words; streak 2; blocked 002914a8 -> branch-layout
claim 6 of 6: 002924d0 token 56867bcba0cc4e0494870cacaf95936a attempts 1 blocker null
002924d0 R4.3 sole jr ra returns defined v0 on both paths: object+11068 when a1 zero, otherwise callee result or fallback. R4.5 exact u32 func_001a80c8(...) from addresspair accepted source, u32 func_001a8190(s32) from sixwordnext 002ba140 accepted source. v1 unsigned integer address transport avoids null cursor arithmetic; earlier 18-word attempt not mandated copy.
002924d0 v1: 14 words; best v1 14 words; streak 0. C1 audit: all paths, integer parameters and exact callee declarations correct. Baseline orch1_rec172_002924d0_v1.cpp; C11d one object guard before fallback only; full source diff checked.
002924d0 v2: 15 words; best v1 14 words; streak 1. STOP received after probe/diff completed; no successor or claims. blocked 002924d0 -> prologue-epilogue
