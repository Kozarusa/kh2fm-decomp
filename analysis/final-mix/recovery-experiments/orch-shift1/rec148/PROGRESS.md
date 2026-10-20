# rec148 progress
start 2026-10-15T17:19:27Z
claim attempt 1 of 6
claim 1 of 6: 00242908 token 893d418af0904a9a9cc8b9c6c3fdfb9a attempts 1 blocker null
v1 baseline original instructions; single initial reconstruction control
00242908 v1: 21 words; best v1 21 words; streak 0. v2 baseline v1; C1 callee return signature copied accepted source (and propagated return). All other controls preserved.
00242908 v2: 21 words; best v1 21 words; streak 1. v3 baseline v2; C1 add explicit original case1 path; preserved signature and all other controls.
v4 baseline v3; C1 mirror switch branch tree explicitly; all declarations and outer controls preserved.
00242908 v3: 16 words; best v3 16 words; streak 0. 00242908 v4: 20 words; best v3 16 words; streak 1. v5 baseline v4; C7 early common-label form replaces if/else tree only; outer and signature unchanged.
00242908 v5: 13 words; best v5 13 words; streak 0. v6 baseline v5; C7 negate less-than and exchange blocks via labels only. Other controls preserved.
00242908 v6: 5 words; best v6 5 words; streak 0. v7 baseline v6; C7 negate two-case and swap bodies only, preserving every other control.
00242908 v7: 17 words; best v6 5 words; streak 1. v8 baseline v6 explicitly (v7 branch experiment discarded); C11 empty guard separates result from comparison constant; all baseline controls preserved.
00242908 v8: 6 words; best v6 5 words; streak 2
blocked 00242908 -> register-allocation
claim attempt 2 of 6
claim 2 of 6: 00243150 token cbcab05164634bd894b98b540e5c207c attempts 1 blocker null
00243150 v1: 16 words; best v1 16 words; streak 0. v2 baseline v1; C9 volatile initial item read only forces original reload; all others preserved.
00243150 v2: 18 words; best v1 16 words; streak 1. v3 baseline v2; C1 widen local item transport to s32, retains signed halfword reads and volatile qualifier.
00243150 v3: 18 words; best v1 16 words; streak 2. v4 baseline v3; C11 bind cursor t6 only; all other controls preserved.
00243150 v4: 17 words; best v1 16 words; streak 3
blocked 00243150 -> register-allocation
claim attempt 3 of 6
claim 3 of 6: 00243230 token 831c266f3056406aa751259f030cca23 attempts 1 blocker null
00243230 v1: 17 words; best v1 17 words; streak 0. v2 baseline v1; R4 accepted callee signature correction only, cast preserves source pointer transport.
00243230 v2: 17 words; best v1 17 words; streak 1. v3 baseline v2; C11 adjusted base empty guard only, return expression adapted same value; all other controls preserved.
00243230 v3: 8 words; best v3 8 words; streak 0. v4 baseline v3; C11 bind pointer t5 only, preserves guard and all others.
00243230 v4: 8 words; best v3 8 words; streak 1. v5 baseline v4; C11 reorder address operands only; preserves pointer binding, guard, condition.
00243230 v5: 7 words; best v5 7 words; streak 0. v6 baseline v5; C11 bind mask t6 only; all other controls preserved.
00243230 v6: 4 words; best v6 4 words; streak 0. v7 baseline v6; C11 guard result computation only, all prior bindings/guard unchanged.
00243230 v7: 4 words; best v6 4 words; streak 1. v8 baseline v7; C11 bind result t4 only, original result guard retained.
00243230 v8: 0 words; best v8 0 words; streak 0. submitted 00243230 v8
claim attempt 4 of 6
claim 4 of 6: 00244938 token 1bae4a1906364d7b9dfb7820c5b10a22 attempts 1 blocker null
00244938 v1: 18 words; best v1 18 words; streak 0. v2 baseline v1; C1 accepted callee u32 argument declaration correction only.
00244938 v2: 18 words; best v1 18 words; streak 1. v3 baseline v2; C11 bind result s0 only; every other control retained.
00244938 v3: 15 words; best v3 15 words; streak 0. v4 baseline v3; C11 bind argument a0 only; result binding retained.
00244938 v4: 16 words; best v3 15 words; streak 1. v5 baseline v4; C11 result initialization guard only, other bindings retained.
00244938 v5: 12 words; best v5 12 words; streak 0. v6 baseline v5; C3 result transport s32 removes bool mask, retains result binding/guard.
00244938 v6: 12 words; best v5 12 words; streak 1. v7 baseline v6; C1 return s32 follows full v0 transport only, all controls retained.
00244938 v7: 11 words; best v7 11 words; streak 0. v8 baseline v7; C7 early return to common done label only; bindings/types/guard unchanged.
00244938 v8: 11 words; best v7 11 words; streak 1
blocked 00244938 -> branch-layout
claim attempt 5 of 6
claim 5 of 6: 00244a10 token dd2d8f4149e04e43bb18f61222658e3d attempts 1 blocker null
00244a10 v1: 19 words; best v1 19 words; streak 0. v2 baseline v1; C11 result s0 binding only.
00244a10 v2: 10 words; best v2 10 words; streak 0. v3 baseline v2; C11 initial zero guard only; binding and conditions retained.
00244a10 v3: 13 words; best v2 10 words; streak 1. v4 baseline v3; C7 negate byte test and exchange paths only; binding/guard preserved.
00244a10 v4: 0 words; best v4 0 words; streak 0. submitted 00244a10 v4
claim attempt 6 of 6
claim 6 of 6: 00244db8 token 010712d2cbac40da85448cc62ed5fffc attempts 1 blocker null
00244db8 v1: 4 words; best v1 4 words; streak 0. accepted declaration confirmed fm_oct7_extended_recovered_00.cpp. v2 baseline v1; C11 reverse object addition operands only.
00244db8 v2: 3 words; best v2 3 words; streak 0. v3 baseline v2; C11 introduce table temporary bound t6 only, expression and other controls preserved.
00244db8 v3: 2 words; best v3 2 words; streak 0. v4 baseline v3; C11 callback temporary bound t7 only, table binding retained.
00244db8 v4: 0 words; best v4 0 words; streak 0. submitted 00244db8 v4
