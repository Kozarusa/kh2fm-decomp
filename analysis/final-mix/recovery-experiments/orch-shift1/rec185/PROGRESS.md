# rec185 progress`nstart 2026-10-18T17:39:49Z

claim 1 of 6: 002aacd8 token 0e3d30262df44145a42201643fb7e3f5 attempts 1 blocker null
R2/R3 002aacd8 128 bytes; both paths return explicit boolean v0. v1 fresh unsigned shifts.
002aacd8 v1: 29 words; best v1 29 words; streak 0. C1 audit: paths/parameters/results complete, no floats. v2 baseline v1; C11b introduce mask temporary at loop only; preserves operands.
002aacd8 v2: 12 words; best v2 12 words; streak 0. v3 baseline v2; C2 signed comparison cast only, shift stays unsigned.
002aacd8 v3: 11 words; best v3 11 words; streak 0. v4 baseline v3; C11b nonnegative-path mask temporary only; preserves operands.
002aacd8 v4: 2 words; best v4 2 words; streak 0. v5 baseline v4; C11a reverse address-add operands only.
002aacd8 v5: 2 words; best v4 2 words; streak 1. v6 baseline v4; C11b address temporary only; preserves original operand order.
002aacd8 v6: 0 words; best v6 0 words; streak 0. Manual R8 audit passed; submitted 002aacd8 v6
claim 2 of 6: 002ab258 token c9d081abed0c4fa0bd6017d95858ab1f attempts 1 blocker null
R2/R3 002ab258 84 bytes. R4.3 both paths leave modified callee v0 (base+136), represented as returned u32. Exact accepted declaration s32 func_002a9d68(void). v1 fresh; unsigned address transport.
002ab258 v1: 0 words; best v1 0 words; streak 0. Manual R8 audit passed one function/declarations/unsigned transport/both return paths. submitted 002ab258 v1
claim 3 of 6: 002abdc8 token 658e7331203b4ddea63861bca82fdbe5 attempts 1 blocker null
R2/R3 002abdc8 96 bytes. R4.3 only exit returns callee result+320. R4.5 declaration copied exactly. v1 fresh, unsigned shifts/address transport.
002abdc8 v1: 0 words; best v1 0 words; streak 0. Manual R8 audit passed one function/declarations/unsigned shifts/address transport/only return. submitted 002abdc8 v1
claim 4 of 6: 002ac268 token b92a2fc412c24fca9f14a583c5fc566a attempts 1 blocker null
R2/R3 002ac268 128 bytes. Literal R4.3 only exit returns masked second callee result (index&31). R4.5 declarations copied exactly. v1 fresh unsigned shifts/address transport; s8,s32 parameters consistent callee contract.
002ac268 v1: 31 words; best v1 31 words; streak 0. v2 baseline v1; C1/R4.3 first parameter s32 instead of s8 to remove entry truncation, all else preserved.
002ac268 v2: 27 words; best v2 27 words; streak 0. R12 ABI conflict with exact accepted s8 callee declaration; conservative stop before scheduling.
blocked 002ac268 -> abi-layout
claim 5 of 6: 002adf60 token 5b01bd5f40ba44dc8a8a941840d7913f attempts 1 blocker null
R2/R3 002adf60 108 bytes. R4.3 two explicit return results 0/1. v1 fresh; unsigned shifts, loop index signed comparison.
002adf60 v1: 24 words; best v1 24 words; streak 0. C1 audit parameters/returns/paths complete, no floats. v2 baseline v1; C7c move successful return into loop, failed return after loop; only exit layout control.
002adf60 v2: 24 words; best v1 24 words; streak 1. v3 baseline v1; C11b introduce success-result temporary only.
002adf60 v3: 24 words; best v1 24 words; streak 2. v4 baseline v3; C11d one empty guard after initial success result. Unique full context count1, added guard count1. Complete diff follows and inspected before separate probe.
002adf60 v4: 15 words; best v4 15 words; streak 0. v5 baseline v4; C11c bind existing success result to v0 only; existing guard preserved.
002adf60 v5: 15 words; best v4 15 words; streak 1. v6 baseline v5; C11d add one guard at successful return only. Unique full context count1; added guard count1. Complete diff inspected before separate probe.
002adf60 v6: 15 words; best v4 15 words; streak 2. v7 baseline v6; C11c bind existing array pointer to t3 only; both guards preserved.
002adf60 v7: 15 words; best v4 15 words; streak 3. STOP strict R7.
blocked 002adf60 -> register-allocation
claim 6 of 6: 002b16d8 token ee4d694e3fbd4bf69cc3327abe74a4c6 attempts 1 blocker null
R2/R3 002b16d8 44 bytes. Literal R4.3 both exits set v0 (0 or equality). v1 fresh ordered locals; no calls.
002b16d8 v1: 5 words; best v1 5 words; streak 0. C10 source loads already original order. v2 baseline v1; C11d one second-field guard after assignment. Unique context count1; added guard count1. Complete diff inspected before separate probe.
002b16d8 v2: 6 words; best v1 5 words; streak 1. v3 baseline v2; C11c second-field t5 binding only; guard and operands preserved.
002b16d8 v3: 0 words; best v3 0 words; streak 0. Manual R8 audit passed: one function, both return paths defined, binding and guard separate versions/commented, numeric register. submitted 002b16d8 v3. K6 reached; no further claims.
start 2026-10-18T17:39:49Z
R0 initialization note: initial heading/start separator was a literal backtick-n; original preserved. All later records use actual newlines.
