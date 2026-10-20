# rec170 progress
start 2026-10-17T17:31:52Z
claim 1 of 6: 0028ce38 token 705f153da12b4446a53505e5fa50e5fa attempts 1
blocked 0028ce38 -> abi-layout; zero versions; literal R4.3 mixed return audit
claim 2 of 6: 0028ce98 token 1e443c2437b648eda598726e3931d834 attempts 1
blocked 0028ce98 -> abi-layout; zero versions; literal R4.3 mixed return audit
claim 3 of 6: 0028d008 token cec4ff048b194229abc2e7f43e6bd1b7 attempts 1
0028d008 R4.3 audit: all exits return v0; null path explicitly zero; callee result retained then conditionally zeroed. v1 baseline original packet, fresh implementation; copied variadic declaration exactly from fm_oct7_extended_recovered_00.cpp; nullable cursor arithmetic guarded.
0028d008 v1: 13 words; best v1 13 words; streak 0. v2 baseline orch1_rec170_0028d008_v1.cpp; full source compared; sole control C15 native srav primitive removes explicit count mask, preserves short circuit and operand order.
0028d008 v2: compile error missing brace; best v1 13 words; streak 1. v3 baseline orch1_rec170_0028d008_v2.cpp; full diff solely closes result conditional before return.
0028d008 v3: 0 words; best v3 0 words; streak 0. Pre-submit audit: single function, declarations before, correct exact accepted variadic callee declaration, all v0 exits retained, guarded nonnull cursor arithmetic, C15 native shift precedent with individual why comment, no bindings.
submitted 0028d008 v3
claim 4 of 6: 0028d0f8 token 48fea57802fb4313b6e27eca4d59c916 attempts 1
blocked 0028d0f8 -> abi-layout; zero versions; R4.3 outgoing tail-callee result and R4.5 void declaration conflict
claim 5 of 6: 0028d140 token fdc63b291ab44e788f931faf31db0db3 attempts 1
blocked 0028d140 -> abi-layout; zero versions; R4.3 outgoing tail-callee result and R4.5 void declaration conflict
claim 6 of 6: 0028d2a0 token b272cc830f0e448cb45c8b2e35091de8 attempts 1
blocked 0028d2a0 -> abi-layout; zero versions; R4.3 mixed untouched-entry, outgoing result, f0 write paths; hard K6 exhausted
R11 report written; ended 2026-10-17T17:35:22Z; 1 submitted, 5 blocked, 0 released; K6 exhausted
