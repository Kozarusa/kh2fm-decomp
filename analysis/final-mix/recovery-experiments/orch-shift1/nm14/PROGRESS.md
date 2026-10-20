# nm14 progress
start 2026-10-13T16:34:11Z
claim 1 of 6: 0020cf60 token dffa6aecbb8941218f58d53402699cf7 attempts 2
packet 0020cf60 read; v1 C10 alternative callee float arguments first
0020cf60 v1: 3 words; best v1 3 words; streak 0
v2 C10d memory barrier between integer and float argument loads; first write failed quoting, no source or evidence created
0020cf60 v2: 14 words; best v1 3 words; streak 1
v3 C10 alternate callee float argument placement after first integer
0020cf60 v3: 0 words; best v3 0 words; streak 0
review passed; submitted 0020cf60 v3
claim 2 of 6: 001b8988 token c8904a9483b04537be9dfbd710216bf9 attempts 2
packet 001b8988 read; v1 C10 separate global pointer
001b8988 v1: 0 words; best v1 0 words; streak 0
v2 review correction: copy accepted func_001db610 declaration from 001b84b8 per R4.5
001b8988 v2: 0 words; best v1 0 words; streak 1
review passed; submitted 001b8988 v2
claim 3 of 6: 001bdff0 token 3cb45a2f76754f6a8c2929a97f6701e7 attempts 2
packet 001bdff0 read; v1 C11 guard on u32 base instead of pointer
001bdff0 v1: 2 words; best v1 2 words; streak 0
v2 C11 cursor input-only guard instead of read/write
001bdff0 v2: 2 words; best v1 2 words; streak 1
v3 C11 bind cursor to s0
001bdff0 v3: 7 words; best v1 2 words; streak 2
v4 C11 typed struct member cursor
001bdff0 v4: 2 words; best v1 2 words; streak 3
blocked 001bdff0 -> prologue-epilogue
claim 4 of 6: 001c05b0 token d7f84678d6f746cda635f3590672c962 attempts 2
packet 001c05b0 read; v1 C11 two-word global array with pointer before direct first store
001c05b0 v1: 2 words; best v1 2 words; streak 0
v2 C11 input-only guard on pair before direct first store
001c05b0 v2: 9 words; best v1 2 words; streak 1
v3 C10d pair input guard with memory clobber
001c05b0 v3: 4 words; best v1 2 words; streak 2
v4 C11 bind pair to t6 from best v1
001c05b0 v4: 3 words; best v1 2 words; streak 3
blocked 001c05b0 -> store-order
claim 5 of 6: 001bba88 token 9bbdf2f7c51f4705a9d14ef8ee2edc26 attempts 2
packet 001bba88 read; v1 probe earlier unprobed draft bool IsExec and independent zero result
001bba88 v1: 10 words; best v1 10 words; streak 0
v2 C11 bind independent result to v0
001bba88 v2: 3 words; best v2 3 words; streak 0
v3 C7 explicit else reset for bound result
001bba88 v3: 0 words; best v3 0 words; streak 0
review passed; submitted 001bba88 v3
claim 6 of 6: 001c0410 token 840e7f5aa3854107b7cd93fe827475f9 attempts 2
packet 001c0410 read; v1 C11 bind halfword conversion temporary t6
001c0410 v1: 19 words; best v1 19 words; streak 0
v2 C1/C2 signed s32 temporary prevents generic unsigned float conversion
001c0410 v2: 0 words; best v2 0 words; streak 0
review passed; submitted 001c0410 v2
K=6 exhausted; write WP report
WP report written; all six claims concluded; recount complete; no source BOM or instruction-emitting asm; report literal register corrected directly
