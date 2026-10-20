# rec96 progress
start 2026-10-13T04:19:27Z
claim 1 of 6: 001bff88 token a8f250a03760421194162d640014b8eb attempts 1
v1: 9 words, first diff at 10: C1/tail -> next: make D_01d49350 array of 2
v2: 8 words, first diff at 10: C10 -> next: asm memory barrier before array stores
v3: 10 words, first diff at 10: C10(d) worse -> next: local pointer for array stores
001bff88 v3: 10 words; best v2 8; streak 1
v4: 8 words, first diff at 10: local ptr no gain -> next: volatile D_01d49350
001bff88 v4: 8 words; best v2 8; streak 2
v5: 9 words; best v2 8; streak 3 -> stop
blocked 001bff88 -> store-order
claim 2 of 6: 001c0560 token 73e5ce20387c4945aa5330c126d1e12a attempts 1
v1: 17 words, first diff at 1: C11 -> next: assign object=next before test
v2: 13 words, first diff at 6: C7 -> next: callee void(), ternary
001c0560 v2: 13 words; best v2 13; streak 0
v3: 14 words, first diff at 6: ternary worse -> next: v2 with C7(a) inverted test
001c0560 v3: 14 words; best v2 13; streak 1
v4: 14 words: callee has no arg is wrong (v2 right); -> next: v2 with if(next) call continue form
001c0560 v4: 14 words; best v2 13; streak 2
v5: 13 words; best v2 13; streak 3 -> stop
blocked 001c0560 -> branch-layout
claim 3 of 6: 001c0648 token 8ebd72699aa04fbc84618b78608056bb attempts 1
v1 001c0648: 0 words exact
submitted 001c0648 v1
claim 4 of 6: 001c0a00 token cbd58b0d5c4b403097309b1433590793 attempts 1
v1 001c0a00: 0 words exact
submitted 001c0a00 v1
claim 5 of 6: 001c0ba0 token 16bbfc4be1034456a331b9c740283e51 attempts 1
v1: 18 words, first diff at 2: C11 -> next: header s32* typed, entry = header+2
v2: 18 words, same -> next: volatile loop-bound read
001c0ba0 v2: 18 words; best v1 18; streak 1
v3: 6 words, first diff at 8: C9 gain -> next: C7 reload bound in both branches
001c0ba0 v3: 6 words; best v3 6; streak 0
v4: 26 words worse -> next: v3 with local table pointer
001c0ba0 v4: 26 words; best v3 6; streak 1
v5: 8 words, hoists table lui -> next: table pointer declared inside if
001c0ba0 v5: 8 words; best v3 6; streak 2
v6: 6 words; best v3 6; streak 3 -> stop
blocked 001c0ba0 -> register-allocation
claim 6 of 6: 001c16a0 token 4f36b6f0a83448a096a345cbb9fecbd9 attempts 1
v1: 18 words, first diff at 1: C1 -> next: void return
v2: 18 words, 68/76 bytes -> next: two separate call sites
001c16a0 v2: 18 words; best v1 18; streak 1
v3: 12 words, first diff at 4: C7 -> next: swap order of kind tests
001c16a0 v3: 12 words; best v3 12; streak 0
v4: 16 words worse -> next: v3 with early return form
001c16a0 v4: 16 words; best v3 12; streak 1
v5: 12 words, same -> next: C7(a) negate: if(kind!=0){if(kind==1)B}else A
001c16a0 v5: 12 words; best v3 12; streak 2
v6: 18 words; best v3 12; streak 3 -> stop
blocked 001c16a0 -> branch-layout
