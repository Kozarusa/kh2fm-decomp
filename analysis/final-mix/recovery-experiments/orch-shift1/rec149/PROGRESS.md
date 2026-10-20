# rec149 progress
start 2026-10-15T20:02:48Z
claim 1 of 6: 00247bb0 token 115c50d3f9d441dda5855e2c58839093 attempts 1 blocker null
00247bb0 v1 baseline fresh: loop count 3..0, offset stride408, reload global and indirect call object argument.
00247bb0 v1: 1 words; best v1 1 words; streak 0. Baseline orch1_rec149_00247bb0_v1.cpp -> v2 C11(a): reverse only object-addition operands. Source diff checked: only D_0035ed34 + offset becomes offset + D_0035ed34 on object initialization; all else preserved.
00247bb0 v2: 1 words; best v1 1 words; streak 1. Baseline orch1_rec149_00247bb0_v2.cpp -> v3 C11(b): object addition integer-domain temporary expression, preserve operand order/loop/calls/types otherwise. Diff only object initializer.
00247bb0 v3: 0 words; best v3 0 words; streak 0. Review source passes R8: one function, no asm/bindings/Ghidra names.
submitted 00247bb0 v3
claim 2 of 6: 0024ad50 token f86de33c32694673910f9f0af900bee5 attempts 1 blocker null
0024ad50 v1 baseline fresh: separate result0, first byte>=2 sets1 else call nonzero sets1.
0024ad50 v1: 19 words; best v1 19 words; streak 0. C1 audit: signature and two call arguments/paths correct; optimizer removes carried zero result. Baseline orch1_rec149_0024ad50_v1.cpp -> v2 C11(d) empty result transport guard after initialization; sole inserted control; all conditions/types unchanged.
0024ad50 v2: 13 words; best v2 13 words; streak 0. Baseline orch1_rec149_0024ad50_v2.cpp -> v3 C7(a) negate byte condition and swap bodies; empty result guard preserved exactly. Diff only if/else orientation.
0024ad50 v3: 0 words; best v3 0 words; streak 0. R8 source review passes; empty guard has why comment.
submitted 0024ad50 v3
claim 3 of 6: 0024c828 token 6450f486123e48c9af77ab892d6175ec attempts 1 blocker null
0024c828 v1 baseline fresh packet: count2..0, stride408; integer-domain object addition matches original operand order.
0024c828 v1: 0 words; best v1 0 words; streak 0. R8 source review passes no asm/bindings.
submitted 0024c828 v1
claim 4 of 6: 0024eb50 token 1f05727a95394599b8ddb2b15a1ed23d attempts 1 blocker null
0024eb50 v1 fresh baseline mirrors pointer loop count4..0 null-check call validity zero or indirect call.
0024eb50 v1: 19 words; best v1 19 words; streak 0. C1 audit paths/ABI correct; extra block from branch layout. Baseline orch1_rec149_0024eb50_v1.cpp -> v2 C7(a): negate callee condition and swap bodies only; all other controls preserved.
0024eb50 v2: 0 words; best v2 0 words; streak 0. R8 source review passes no asm/bindings.
submitted 0024eb50 v2
claim 5 of 6: 0024f240 token 41f846c4878d473c892225cbd31e4d03 attempts 1 blocker null
0024f240 v1 fresh baseline: null/invalid returns true; signed table halfword versus object word.
0024f240 v1: 2 words; best v1 2 words; streak 0. C5 address decoded correctly but +2 folded to base. Baseline orch1_rec149_0024f240_v1.cpp -> v2 represent six-byte table entries as struct member at2; single layout control; other conditions/types/calls unchanged.
0024f240 v2: 0 words; best v2 0 words; streak 0. R8 source review passes no asm/bindings.
submitted 0024f240 v2
claim 6 of 6: 00250928 token 641ec529128448e6a9683a8fa92194f4 attempts 1 blocker null
00250928 v1 fresh packet baseline: count4..0 stride408 global reload and integer-domain object addition.
00250928 v1: 0 words; best v1 0 words; streak 0. R8 source review passes no asm/bindings.
submitted 00250928 v1; K6 exhausted
R11 report saved. Mechanical review review-auto-1.json PASS6 FAIL0; outside-WP flags require reviewer attribution, no worker writes outside WP.
