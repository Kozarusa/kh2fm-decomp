# rec84 progress
start 2026-10-13T03:24:01Z
claim 1 of 6: 001b2380 token 71b6d4c200f24c4aa624c43d77427491 attempts 1
v1: 13 words, first diff at 1: C9/C11 -> next: array global for float
001b2380 v1: 13 words; best v1 13 words; streak 0
001b2380 v2: 13 words; best v1 13 words; streak 1 (array global no effect)
001b2380 v3: 13 words; best v1 13; streak 2 (volatile float no effect)
001b2380 v4: compile error (my typo); best v1 13; streak 3
001b2380 v5: 13 words; best v1 13; streak 4 (v5 was written after streak hit 3 at v4: my error)
blocked 001b2380 -> store-order
claim 2 of 6: 001b2520 token b714a6fc69b4437fa366031c97be4462 attempts 1
001b2520 v1: 20 words, first diff 0: reload missing -> try s32* items
001b2520 v2: 20 words; best v1 20; streak 1
001b2520 v3: 20 words; best v1 20; streak 2 (volatile store)
001b2520 v4: 13 words; best v4 13; streak 0 (asm memory barrier)
001b2520 v5: 2 words; best v5 2; streak 0 (barrier inside if)
submitted 001b2520 v6
claim 3 of 6: 001b3018 token e8fce40a3a864fd589e01353fb420e60 attempts 1
001b3018 v1: 1 word, first diff 14: C11 operand order -> swap addition
001b3018 v2: ? words; see below
001b3018 v3: exact
submitted 001b3018 v3
claim 4 of 6: 001b3208 token f2e24cdd9db546059ac18952e618a535 attempts 1
001b3208 v1: 23 words, first diff 0: C21/C11 -> two header variables
001b3208 v2: 23 words; best v1 23; streak 1 (two vars coalesced)
001b3208 v3: 25 words; best v1 23; streak 2 (integer form)
001b3208 v4: 21 words; best v4 21; streak 0 (for loop)
001b3208 v5: 26 words; best v4 21; streak 1 (asm pin)
001b3208 v6: 21 words; best v4 21; streak 2 (inner base var)
001b3208 v7: 21 words; best v4 21; streak 3
blocked 001b3208 -> register-allocation
claim 5 of 6: 001b5400 token 90275c3fdda44b1f91cc6667e3891b80 attempts 1
001b5400 v1: 18 words, first diff 5: C9/C13 -> volatile global
001b5400 v2: 22 words; best v1 18; streak 1 (volatile global)
001b5400 v3: 10 words; best v3 10; streak 0 (asm barrier; remaining tail call j vs jal)
001b5400 v4: 10 words; best v3 10; streak 1 (variadic decl no effect)
001b5400 v5: exact
submitted 001b5400 v5
claim 6 of 6: 001b5878 token a2f6625b0cc74a86904c19f7f191665b attempts 1
001b5878 v1: 12 words, first diff 1: C9 -> integer object
001b5878 v2: 12 words; best v1 12; streak 1
001b5878 v3: 12 words; best v1 12; streak 2 (s32 decl)
001b5878 v4: 12 words; best v1 12; streak 3
blocked 001b5878 -> register-allocation
WP report written
