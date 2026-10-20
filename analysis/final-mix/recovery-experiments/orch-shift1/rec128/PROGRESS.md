# rec128 progress
start 2026-10-13T08:05:10Z
claim 1 of 6: 002072a8 token 0cdb26e3d3444a4797b16d31cc9f341f attempts 1
v1: 25 words, first diff at 2: C12/hoisting -> next: inline expressions without temps
v2: 0 words exact
submitted 002072a8 v2
claim 2 of 6: 00207308 token 8c5fa3fe505841b1a6234e91edff4df0 attempts 1
v1: 8 words, first diff at 1: C8 sltu -> next: volatile read of last field
00207308 v1: 8 words; best v1 8; streak 0
v2: 8 words, same; streak 1 -> next: nested result-variable form
v3: 10 words; best v1 8; streak 2 -> next: empty asm on result
v4: 9 words; best v1 8; streak 3 -> block
blocked 00207308 -> branch-layout
claim 3 of 6: 002092e0 token e70b5a81579d4943afec0e67334189bb attempts 1
v1: 12 words, first diff at 1: C13 tail call j -> next: memory barrier after call
v2: 15 words; best v1 12; streak 1 -> next: hoist loads into locals before branch (C9)
v3: 7 words; best v3 7; streak 0 -> next: move target computation before the other loads
v4: 6 words; best v4 6; streak 0 -> next: inline the compare
v5: 6 words; best v4 6; streak 1 -> next: order expected load between base and offset
v6: 7 words; best v4 6; streak 2 -> next: volatile read of expected on v4 shape
v7: 6 words; best v4 6; streak 3 -> block
blocked 002092e0 -> store-order
claim 4 of 6: 0020cf60 token bfd9aa9e93434919be4310efdc3d2784 attempts 1
v1: 3 words, first diff at 12: C10 load order -> next: locals in original order
v2: 6 words; best v1 3; streak 1 -> next: only floats in locals
v3: 6 words; best v1 3; streak 2 -> next: volatile float reads in v1 form
v4: 12 words; best v1 3; streak 3 -> block
blocked 0020cf60 -> store-order
claim 5 of 6: 0020df70 token a6046ae2c3664afcb657ff36d33ecba0 attempts 1
v1: 21 words, first diff at 3: C13 tail call -> next: barrier after last call
v2: 14 words; best v2 14; streak 0 -> next: declare header before count (C11a)
v3: 13 words; best v3 13; streak 0 -> next: swap store order (C10a)
v4: 13 words; best v3 13; streak 1 -> next: for loop with inline Quad constant
v5: 31 words; best v3 13; streak 2 -> next: bind count to t4 (C11c)
v6: 9 words; best v6 9; streak 0 -> next: barrier after sq (C10d)
v7: 4 words; best v7 4; streak 0 -> next: barrier after final sq
v8: 0 words exact
submitted 0020df70 v8
claim 6 of 6: 0020e7a8 token 9a9ca362661e4dc4ba01a0cb96fe57f3 attempts 1
v1: 20 words, first diff at 0: C14 zero quad por vs zero -> next: zero via __builtin_memset plus barrier
v2: link error (memset); best v1 20; streak 1 -> next: cast (Quad)(u64)0 plus barrier
v3: 20 words; best v1 20; streak 2 -> next: zero-register bound Quad
v4: 20 words; best v1 20; streak 3 -> block
blocked 0020e7a8 -> store-order
