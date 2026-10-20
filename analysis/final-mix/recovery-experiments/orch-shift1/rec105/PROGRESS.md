# rec105 progress
start 2026-10-13T05:07:02Z
claim 1 of 6: 001d3000 token 14cf2342ed23407cb19d9781d74ab5c8 attempts 1
v1: 12 words, first diff at 2: C11 -> next: separate num/den temporaries
v2: 12 words (no change), best v1 12 streak 1; next: direct expressions v3
v3: 12 words, best v1 12 streak 2; next: in-place value/high updates v4
v4: 10 words, best v4 10 streak 0; next: value-=low first, ratio temp v5
v5: 12 words, best v4 10 streak 1; next: v4 with value-=low before high-=low v6
v6: 10 words, best v4 10 streak 1 (tie, not better => streak 2 by rule: 2); next: den first then (value-low)/den v7
v7: 10 words, best v4 10 streak 3 -> stop
blocked 001d3000 -> register-allocation
claim 2 of 6: 001d37a0 token 25ec7e82faf34f0c95ad2d485de45987 attempts 1
v1: 28 words, first diff at 0: C9 -> next: volatile float globals
v2: 28 words (identical), best v1 28 streak 1; next: volatile node stores C10c
v3: 27 words (compile warnings), best v3 27 streak 0; next: v1 with array globals
v4: 28 words, best v3 27 streak 1; next: v1 with volatile struct members
v5: 26 words, best v5 26 streak 0; next: memory barriers C10d
v6: 26 words, best v5 26 streak 1; next: v5 with volatile pointer-form float globals
v7: 24 words, best v7 24 streak 0; next: local tail var
v8: 26 words, best v7 24 streak 1; next: v7 with one barrier after quad copy
v9: 23 words, best v9 23 streak 0; next: v9 with local tail var
v10: 25 words, best v9 23 streak 1; budget (8) exceeded by 2 in error -> stop
blocked 001d37a0 -> store-order
claim 3 of 6: 001d3b68 token b4f0f45093d147fe95e54823763fb5cc attempts 1
v1: 17 words, first diff at 2: C21/C12 -> next: Ghidra-literal loop with redundant null check
v2: exact; submitted 001d3b68 v2
claim 4 of 6: 001d3f38 token d57a2b1e03c546d38217c296a82c58c3 attempts 1
v1: 13 words, first diff at 2: slti vs sltiu -> next: s32 id
v2: 12 words, best v2 12 streak 0: C7 -> next: early returns
v3: 15 words, best v2 12 streak 1: -> next: switch statement
v4: exact; submitted 001d3f38 v4
claim 5 of 6: 001d44d8 token 7aa46be75332478cbb9662a9d7b59285 attempts 1
v1: 19 words, first diff at 0: C9 -> next: volatile global
v2: 21 words, best v1 19 streak 1: reload twice -> next: local base per iteration
v3: 17 words, best v3 17 streak 0: -> next: plain global, volatile cast only in loop
v4: 8 words, best v4 8 streak 0: -> next: volatile cast also for first read
v5: 17 words, best v4 8 streak 1: -> next: for(;;) with break
v6: 8 words, best v4 8 streak 2: -> next: reuse base variable for head
v7: 9 words, best v4 8 streak 3 -> stop
blocked 001d44d8 -> store-order
claim 6 of 6: 001d4f40 token 5f6525d5c016409d8f09b293a269bc87 attempts 1
v1: 25 words, first diff at 0: C4/C12 -> next: scale float converted before call
v2: 20 words, best v2 20 streak 0: C20 -> next: pointer object
v3: 19 words, best v3 19 streak 0: addiu placement, t6/t7 swap -> next: array global through local pointer
v4: 19 words (no change), best v3 19 streak 1: -> next: separate amount/result variables
v5: movn instead of movz (worse), best v3 19 streak 2: -> next: v4 with empty asm on pointer
v6: 4 words, best v6 4 streak 0: C11 t6/t7 -> next: register-bind amount to t6
v7: 5 words, best v6 4 streak 1 -> next (last): bind constant 1 to t7
v8: 2 words, best v8 2; budget 8 reached -> block
blocked 001d4f40 -> register-allocation
