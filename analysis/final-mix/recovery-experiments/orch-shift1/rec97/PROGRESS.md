# rec97 progress
start 2026-10-13T04:28:31Z
claim 1 of 6: 001c1708 token 6bcf4de730184a13bfc6fa3387f494ad attempts 1
v1: 14 words, first diff at 3: C11/C21 -> next: reuse param variable; 001c1708 v1: 14 words; best v1 14; streak 0
v2: exact. submitted 001c1708 v2
claim 2 of 6: 001c18d0 token 17b7c2c11cb148fc9ec9aae5138cbfdf attempts 1
001c18d0 v1: 27 words; best v1 27; streak 0 (C12 extra s1 for result) -> next: init result after call
001c18d0 v2: 19 words; best v2 19; streak 0 (C7) -> next: ternary for value
001c18d0 v3: 19 words; best v2 19; streak 1 -> next: early returns
001c18d0 v4: 18 words; best v4 18; streak 0 -> next: ternary with early returns
001c18d0 v5: 18 words; best v4 18; streak 1 -> next: share one variable for result and value
001c18d0 v6: 20 words; best v4 18; streak 2 -> next: C7 swap kind branches on v4
001c18d0 v7: 16 words; best v7 16; streak 0 -> next: ternary with swapped branches
001c18d0 v8: 16 words; best v7 16; streak 1; budget 8 reached
blocked 001c18d0 -> branch-layout
claim 3 of 6: 001c3670 token 51263799d74648dc9a8ccf4b3e7ba036 attempts 1
001c3670 v1: 34 words; best v1 34; streak 0 (C21 loop shape) -> next: simple do-while
001c3670 v2: 2 words; best v2 2; streak 0 (sll/addiu order) -> next: array indexing
001c3670 v3: 12 words; best v2 2; streak 1 -> next: v2 with bit computed before word
001c3670 v4: 2 words; best v2 2; streak 2 -> next: base pointer variable
001c3670 v5: 12 words; best v2 2; streak 3; stop
blocked 001c3670 -> address-materialization
claim 4 of 6: 001c4080 token e684d7f1cf334b8dbfd3096c54a1461f attempts 1
001c4080 v1: 15 words; best v1 15; streak 0 (address materialization; one base needed) -> next: base arrays
001c4080 v2: 11 words; best v2 11; streak 0 -> next: struct in natural order
001c4080 v3: 13 words; best v2 11; streak 1 -> next: v2 with permuted source store order (C10a)
001c4080 v4: 13 words; best v2 11; streak 2 -> next: all via one array, no low var
001c4080 v5: 15 words; best v2 11; streak 3; stop
blocked 001c4080 -> store-order
claim 5 of 6: 001c70e8 token b590fdb30de64c2d9cf8fe4519768959 attempts 1
001c70e8 v1: link error (invented symbol); best none; streak 1
001c70e8 v2: 23 words; best v2 23; streak 0 (C21/C5 base pointer) -> next: f32 array base D_01d498f0
001c70e8 v3: 24 words; best v2 23; streak 1 -> next: pointers p (=&D_01d498f0) and q=p-32 bytes
001c70e8 v4: 24 words (88/96 bytes); best v2 23; streak 2 -> next: source floats via pointers
001c70e8 v5: 23 words; best v2 23; streak 3; stop
blocked 001c70e8 -> store-order
claim 6 of 6: 001c7148 token d5e8722ab82d458e894327e82eb4d19c attempts 1
001c7148 v1: 25 words; best v1 25; streak 0 (C14/C11 src kept in a0) -> next: advance source variable
001c7148 v2: 26 words; best v1 25; streak 1 -> next: struct assignment with aligned Vec
001c7148 v3: 22 words; best v3 22; streak 0 -> next: local Dest* d
001c7148 v4: 25 words; best v3 22; streak 1 -> next: kn::FVector operator= (project vector type)
001c7148 v5: 23 words (116/108); best v3 22; streak 2 -> next: dest pointer variable with FVector
001c7148 v6: 23 words (104/108); best v3 22; streak 3 would stop; but structure matches, one more try allowed? NO - R7 says stop at 3
001c7148 v6: 23 words; best v3 22; streak 3; stop
blocked 001c7148 -> register-allocation
