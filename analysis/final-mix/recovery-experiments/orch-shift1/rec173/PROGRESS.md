# rec173 progress
start 2026-10-17T21:08:40Z
claim 1 of 6: 002925c0 token eff3c8eec31e4d2ca6f859ee288f831f attempts 1
002925c0 audit: single exit returns untouched final callee v0; declarations copied exactly from fm_primary_dependencyfamily_recovered_00272a00.cpp. v1 baseline original packet; fresh reconstruction, no earlier <=6-word attempt.
002925c0 v1: 16 words; best v1 16 words; streak 0. C1 audit found unsigned address extension. v2 baseline orch1_rec173_002925c0_v1.cpp; full-source diff: sole change fourth argument cast u32 to s32.
002925c0 v2: 5 words; best v2 5 words; streak 0. C2 word signedness analogue. v3 baseline orch1_rec173_002925c0_v2.cpp; full-source diff: sole change loaded first argument u32 to s32.
002925c0 v3: 4 words; best v3 4 words; streak 0. C11(b): v4 baseline orch1_rec173_002925c0_v3.cpp; full-source diff: introduce size temporary at same third operand, preserving operand order.
002925c0 v4: 4 words; best v3 4 words; streak 1. C11(c): v5 baseline orch1_rec173_002925c0_v4.cpp; full-source diff: sole change bind defined size to numeric $6 with own why.
002925c0 v5: 5 words; best v3 4 words; streak 2. C11(d): v6 baseline orch1_rec173_002925c0_v5.cpp; full-source diff: add one empty size guard with own why.
002925c0 v6: 6 words; best v3 4 words; streak 3
blocked 002925c0 -> address-materialization
claim 2 of 6: 00292a58 token 7d00dfc8fbe24c5f9f28e5b1d689e195 attempts 1
00292a58 audit: no entry arg read; sole tail exit returns callee v0. Accepted func_002fde18(...) declaration copied exactly from fm_primary_capacity_recovered_00303c48.cpp. v1 baseline packet, fresh source.
00292a58 v1: 0 words; best v1 0 words; streak 0. R8 audit passed: one function, all declarations before body, no forbidden names/asm/bindings, sole tail return forwards v0.
submitted 00292a58 v1
claim 3 of 6: 00292af0 token 72b965609bd04626be44a8cda65bf1bf attempts 1
00292af0 audit: a0 compared unmasked; u64 input. Both exits explicitly set v0 0/1; s32 return. v1 baseline packet, fresh source.
00292af0 v1: 18 words; best v1 18 words; streak 0. C1 audit: ordinary word argument avoids unnecessary halfword extension. v2 baseline orch1_rec173_00292af0_v1.cpp; full-source diff: sole input type u64 to u32.
00292af0 v2: 19 words; best v1 18 words; streak 1. C1(b) return-block audit: v3 baseline orch1_rec173_00292af0_v2.cpp; full-source diff: use separate initialized zero result at final exit.
00292af0 v3: 19 words; best v1 18 words; streak 2. C7(a): v4 baseline orch1_rec173_00292af0_v3.cpp; full-source diff: negate equality and swap explicit if/else bodies, no other controls.
00292af0 v4: 19 words; best v1 18 words; streak 3
blocked 00292af0 -> store-order
claim 4 of 6: 00292eb0 token f85d6a4ee8fd42c78dd8baad3c22a38f attempts 1
00292eb0 audit: all exits return defined -1/0 or outgoing callee v0 through t7. s64 transport follows original move and Ghidra advisory. No accepted callee declarations listed. v1 baseline packet fresh.
00292eb0 v1: 0 words; best v1 0 words; streak 0. R8 source audit passed, one function, no forbidden names/asm/bindings, all return paths preserved.
submitted 00292eb0 v1
claim 5 of 6: 002930d8 token 4ec304f451c14c3fa6ed1bb0b93790cb attempts 1
002930d8 audit: pure leaf, no v0/f0 writes; void permitted. No arguments or callees. v1 baseline packet, fresh reconstruction preserving duplicate count guard.
002930d8 v1: 22 words; best v1 22 words; streak 0. C1(b)/C9 missing loop reload. v2 baseline orch1_rec173_002930d8_v1.cpp; full-source diff: only loop-condition count read volatile.
002930d8 v2: 22 words; best v1 22 words; streak 1. C10(d): v3 baseline orch1_rec173_002930d8_v1.cpp; full-source diff: exactly one empty memory guard after store, own why. Baseline has no volatile read.
002930d8 v3: 23 words; best v1 22 words; streak 2. C11(c): v4 baseline orch1_rec173_002930d8_v3.cpp; full-source diff: route count accesses through defined numeric $11 address binding, own why; memory guard unchanged.
002930d8 v4: 29 words; best v1 22 words; streak 3
blocked 002930d8 -> register-allocation
claim 6 of 6: 00293668 token 4234114ce331483d88909b15860d84ae attempts 1
00293668 audit: no entry args; sole exit moves defined s0 result 0/1 to v0. Both accepted declarations copied exactly from fm_primary_oneword_recovered_00293b70.cpp. v1 baseline packet fresh.
00293668 v1: 19 words; best v1 19 words; streak 0. C7(a): v2 baseline orch1_rec173_00293668_v1.cpp; full-source diff: negate outer callee-result condition and swap its if/else blocks.
00293668 v2: 0 words; best v2 0 words; streak 0. R8 audit passed: all declarations before sole function, exact packet accepted declarations, no forbidden names/asm/bindings; all result paths defined.
submitted 00293668 v2
R11 done: K6 claim attempts exhausted; 3 submitted, 3 blocked, 0 released. WP-REPORT.md written.
