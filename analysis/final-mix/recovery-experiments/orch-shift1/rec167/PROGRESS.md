# rec167 progress
start 2026-10-17T07:32:11Z
claim 1 of 6: 00288b78 token be08f2db70ec4038a48ef09fbe15216c attempts 1
R4.3 audit 00288b78: both exits preserve latest callee v0; explicit result returns preserve both. R4.5 declaration copied from packet sibling 00232510. v1 fresh mirror.
00288b78 v1: 18 words; best v1 18 words; streak 0. C1 audit paths complete, returns preserved. v2 baseline v1 single C2 global signedness s8 to u8; complete source diff inspected.
00288b78 v2: 18 words; best v1 18 words; streak 1. v3 baseline v2 single C2 local signedness s8 to u8; complete source diff inspected.
00288b78 v3: 17 words; best v3 17 words; streak 0. v4 baseline v3 single C11(b) introduce decrement temporary before branch; complete source diff inspected.
00288b78 v4: 17 words; best v3 17 words; streak 1. v5 baseline v4 single C7(c) early return replaces else; complete source diff inspected.
00288b78 v5: 17 words; best v3 17 words; streak 2. v6 baseline v3 single C7(a) negate condition and swap bodies; complete source diff inspected.
00288b78 v6: 18 words; best v3 17 words; streak 3. Stop R7.
blocked 00288b78 -> branch-layout
claim 2 of 6: 0028afd0 token 29e66f516e074f93bc134336f2513413 attempts 1
R4.3 audit 0028afd0 mixed entry-v0/callee-result paths; zero-version R12 ABI block.
blocked 0028afd0 -> abi-layout
claim 3 of 6: 0028b078 token e93a7034b2094b178f795833f2b3c013 attempts 1
0028b078 v1 baseline fm_call_fixed_width_all_10_0.cpp target: renamed forbidden locals, retained only target function and declarations; R4.3 tail call result returned u32; R4.5 declarations copied literally from packet-named 00272a00 accepted source. All exits tail callee.
0028b078 v1: 5 words; best v1 5 words; streak 0. v2 baseline v1 single C3 widen value parameter u16 to u32 to remove mask; complete source diff inspected.
0028b078 v2: 22 words; best v1 5 words; streak 1. v3 baseline v2 single C11(c) value temporary bound t6, no guard; complete source diff inspected.
0028b078 v3: 24 words; best v1 5 words; streak 2. v4 baseline v3 single C11(d) add one guard on stored before store; complete source diff inspected.
0028b078 v4: 6 words; best v1 5 words; streak 3. Stop R7.
blocked 0028b078 -> register-allocation
claim 4 of 6: 0028b120 token cf49503393df44cb925de0501065bbda attempts 1
0028b120 R4.3 audit pure leaf no v0/f0 set, no callee, void literal allowed. v1 mirror signed remainder/quotient and explicit builtin trap.
0028b120 v1: 10 words; best v1 10 words; streak 0. v2 baseline v1 C1(b) remove duplicate trap path: compiler division already emits original break7. Complete source diff inspected.
0028b120 v2: 6 words; best v2 6 words; streak 0. v3 baseline v2 C18 shared union access for half reads and word writes to preserve alias reload; complete source diff inspected.
0028b120 v3: 0 words; best v3 0 words; streak 0. R8 audit one function, no asm/bindings/Ghidra names, pure leaf void literal R4.3; no declarations after function.
submitted 0028b120 v3
claim 5 of 6: 0028b160 token b633fe6c7d33472a887aefde231dac11 attempts 1
0028b160 R4.3 audit v0 -1 then movn index at sole return, s32 result. v1 mirror unsigned count load plus signed comparisons and original loop.
0028b160 v1: 22 words; best v1 22 words; streak 0. C1 audit no missing arguments/paths. v2 baseline v1 C7(b) split compound while condition into do-loop equality break and count condition; complete source diff inspected.
0028b160 v2: 19 words; best v2 19 words; streak 0. v3 baseline v2 single C11(c) bind raw count t4, no guard; complete source diff inspected.
0028b160 v3: 19 words; best v2 19 words; streak 1. v4 baseline v3 single C11(d) guard count after load at one site; complete source diff inspected.
0028b160 v4: 18 words; best v4 18 words; streak 0. v5 baseline v4 single C11(b) signed loop limit temporary, final count cast unchanged; complete source diff inspected.
0028b160 v5: 18 words; best v4 18 words; streak 1. v6 baseline v5 single C11(c) bind existing signed limit t5; complete source diff inspected.
0028b160 v6: 18 words; best v4 18 words; streak 2. v7 baseline v6 single C11(d) add one guard site before final comparison; complete source diff inspected.
0028b160 v7: 19 words; best v4 18 words; streak 3. Stop R7.
blocked 0028b160 -> register-allocation
claim 6 of 6: 0028b218 token 11ba752dfc42490f8b4d69fbc669fb31 attempts 1
0028b218 R4.3 audit pure leaf no v0/f0 write and no callee, literal void allowed. v1 mirror nonzero branch first and ordered store.
0028b218 v1: 5 words; best v1 5 words; streak 0. C11(a) no independent calculation to reorder, C11(b) existing result already separate. v2 baseline v1 single C11(c) result bound t7; complete source diff inspected.
0028b218 v2: 0 words; best v2 0 words; streak 0. R8 audit one function, nothing after, no Ghidra names, t7 numeric binding own why comment; pure leaf void literal R4.3.
submitted 0028b218 v2; K6 hard stop, no more claims
