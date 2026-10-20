# rec146 progress
start 2026-10-15T08:44:55.5866049Z
claim 1 of 6: 002415a0 token 9de7b99c48e84f79bfcf2323efea45f7 attempts 1 blocker null
002415a0 v1: 10 words; best v1 10 words; streak 0`nv1: 10 words, first diff at 10: C7 -> next: negate condition and explicit else
002415a0 v2: 10 words; best v1 10 words; streak 1
v2: 10 words, first diff at 10: C11 -> next: separate first argument temporary
002415a0 v3: 10 words; best v1 10 words; streak 2
v3: 10 words, first diff at 10: C11 -> next: bind first argument to a1
002415a0 v4: 16 words; best v1 10 words; streak 3
blocked 002415a0 -> branch-layout
claim 2 of 6: 00241608 token 725493e9adf24735a17f09f2a8a5835e attempts 1 blocker null
00241608 v1: 10 words; best v1 10 words; streak 0
v1: 10 words, first diff at 10: C7 -> next: negate condition
00241608 v2: 10 words; best v1 10 words; streak 1
v2: 10 words, first diff at 10: C11 -> next: separate argument temporary
00241608 v3: 15 words; best v1 10 words; streak 2
v3: 15 words, first diff at 11: C11 -> next: bind argument to a1
00241608 v4: 15 words; best v1 10 words; streak 3
blocked 00241608 -> branch-layout
claim 3 of 6: 00241670 token 0671df2ee23c4de0acaacda28e03ea6c attempts 1 blocker null
00241670 v1: 0 words; best v1 0 words; streak 0
submitted 00241670 v1
claim 4 of 6: 00241850 token d5ef62a886e949d6a2be64050e22d314 attempts 1 blocker null
00241850 v1: 13 words; best v1 13 words; streak 0
v1: 13 words, first diff at 3: C11 -> next: compute flag copy before offset
00241850 v2: 13 words; best v1 13 words; streak 1
v2: 13 words, first diff at 3: C11 -> next: bind flag to t6
00241850 v3: 11 words; best v3 11 words; streak 0
v3: 11 words, first diff at 4: C11 -> next: bind offset to t4
00241850 v4: 9 words; best v4 9 words; streak 0
v4: 9 words, first diff at 7: C11 -> next: bind source to t5
00241850 v5: 7 words; best v5 7 words; streak 0
v5: 7 words, first diff at 17: C9 -> next: volatile packed source read
00241850 v6: 7 words; best v5 7 words; streak 1
v6: 7 words, first diff at 17: C11 -> next: compute destination before copy
00241850 v7: 7 words; best v5 7 words; streak 2
v7: 7 words, first diff at 17: C11 -> next: bind destination to t7
00241850 v8: 7 words; best v5 7 words; streak 3
blocked 00241850 -> store-order
claim 5 of 6: 00241a00 token b06aaea9d3144f5b8ef921547ddd1e67 attempts 1 blocker null
00241a00 v1: 11 words; best v1 11 words; streak 0
v1: 11 words, first diff at 1: C11 -> next: bind result to v0
00241a00 v2: 13 words; best v1 11 words; streak 1
v2: 13 words, first diff at 4: C11 -> next: bind cursor to t6
00241a00 v3: 14 words; best v1 11 words; streak 2
v3: 14 words, first diff at 4: C11 -> next: empty cursor guard
00241a00 v4: 11 words; best v1 11 words; streak 3
blocked 00241a00 -> register-allocation
claim 6 of 6: 002421e8 token 3455159f8b68407cbb66d391816c82d0 attempts 1 blocker null
002421e8 v1: 19 words; best v1 19 words; streak 0
v1: 19 words, first diff at 1: C1 signature and paths checked; C11 -> next: bind preserved result to s0
002421e8 v2: 15 words; best v2 15 words; streak 0
v2: 15 words, first diff at 3: C11 -> next: empty result guard before call
002421e8 v3: 14 words; best v3 14 words; streak 0
v3: 14 words, first diff at 6: C7 -> next: negate call condition and swap bodies
002421e8 v4: 1 words; best v4 1 words; streak 0
v4: 1 words, first diff at 9: C9 -> next: volatile word global prevents narrowed read
002421e8 v5: 0 words; best v5 0 words; streak 0
submitted 002421e8 v5
R11 report saved; K6 exhausted; 2 submitted, 4 blocked, 0 released
