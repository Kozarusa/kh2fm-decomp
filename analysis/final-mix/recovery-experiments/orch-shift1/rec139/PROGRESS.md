# rec139 progress
start 2026-10-15T01:02:47.2429501Z
claim 1 of 6: 00232db0 token d4a9b057f8424798b5bd4532059b8908 attempts 1 blocker null
00232db0 v1: 21 words; best v1 21 words; streak 0
v1: 21 words, first diff at 0: C1 checked signature and paths; next: retain original global reloads with volatile pointer
00232db0 v2: 17 words; best v2 17 words; streak 0
v2: 17 words, first diff at 1: C11; next: reverse address operand order
00232db0 v3: 17 words; best v2 17 words; streak 1
v3: 17 words, first diff at 1: C11; next: separate sentinel temporary
00232db0 v4: 17 words; best v2 17 words; streak 2
v4: 17 words, first diff at 1: C11; next: bind sentinel to original t2
00232db0 v5: 15 words; best v5 15 words; streak 0
v5: 15 words, first diff at 1: C11; next: guard sentinel
00232db0 v6: 16 words; best v5 15 words; streak 1
v6: 16 words, first diff at 0: C11; next: bind index to original t3
00232db0 v7: 21 words; best v5 15 words; streak 2
v7: 21 words, first diff at 0: C11; next: guard index initialization
00232db0 v8: 20 words; best v5 15 words; streak 3
blocked 00232db0 -> register-allocation
claim 2 of 6: 00233410 token 0451cccca0d44f718f32e0b7d096063e attempts 1 blocker null
blocked 00233410 -> vu-macro; zero versions; no accepted sibling same sequence
claim 3 of 6: 002338a8 token 860b18845797452182a7d5e33b80be8d attempts 1 blocker null
002338a8 v1: 37 words; best v1 37 words; streak 0
v1: 37 words, first diff at 0: C1 signature/paths checked; C16 conversion helper differs; next: accepted 0016df28 cvt.w.s primitive
002338a8 v2: 29 words; best v2 29 words; streak 0
v2: 29 words, first diff at 1: C1 missing original stack-backed color accesses; next: volatile union
002338a8 v3: 26 words; best v3 26 words; streak 0
v3: 26 words, first diff at 2: C11; next: temporary global address
002338a8 v4: 31 words; best v3 26 words; streak 1
v4: 31 words, first diff at 0: C11; next: bind coefficient address t7
002338a8 v5: 31 words; best v3 26 words; streak 2
v5: 31 words, first diff at 0: C11; next: bind scaled value f0
002338a8 v6: 31 words; best v3 26 words; streak 3
blocked 002338a8 -> address-materialization
claim 4 of 6: 00234098 token b2a06f8000024ef38ddca35f2bb4fba2 attempts 1 blocker null
00234098 v1: 11 words; best v1 11 words; streak 0
v1: 11 words, first diff at 0: C11; next: compute increment temporaries before stores
00234098 v2: 11 words; best v1 11 words; streak 1
v2: 11 words, first diff at 0: C11; next: bind serial t3
00234098 v3: 10 words; best v3 10 words; streak 0
v3: 10 words, first diff at 0: C11; next: guard serial
00234098 v4: 12 words; best v3 10 words; streak 1
v4: 12 words, first diff at 0: C11; next: bind next serial t4
00234098 v5: 12 words; best v3 10 words; streak 2
v5: 12 words, first diff at 0: C11; next: guard next serial
00234098 v6: 8 words; best v6 8 words; streak 0
v6: 8 words, first diff at 7: C11 computation scheduling; next: guard pointer before serial increment
00234098 v7: 10 words; best v6 8 words; streak 1
v7: 10 words, first diff at 2: C11; next: bind index t6
00234098 v8: 11 words; best v6 8 words; streak 2
blocked 00234098 -> store-order
claim 5 of 6: 002341e8 token a200d25a7522452fa5f7e30967359a87 attempts 1 blocker null
002341e8 v1: 11 words; best v1 11 words; streak 0
v1: 11 words, first diff at 0: C11; next: bind serial t3
002341e8 v2: 10 words; best v2 10 words; streak 0
v2: 10 words, first diff at 0: C11; next: bind next serial t4
002341e8 v3: 10 words; best v2 10 words; streak 1
v3: 10 words, first diff at 0: C11; next: guard next serial
002341e8 v4: 8 words; best v4 8 words; streak 0
v4: 8 words, first diff at 7: C10 global stores moved ahead of payload store; next: memory barrier after payload
002341e8 v5: 11 words; best v4 8 words; streak 1
v5: 11 words, first diff at 2: C11; next: bind next index t5
002341e8 v6: 11 words; best v4 8 words; streak 2
v6: 11 words, first diff at 2: C11; next: guard next index before serial computation
002341e8 v7: 6 words; best v7 6 words; streak 0
v7: 6 words, first diff at 8: C11; next: make serial guard depend on next index
002341e8 v8: 4 words; best v8 4 words; streak 0
blocked 002341e8 -> store-order
claim 6 of 6: 00234298 token 3ae90a5add054be6a54ec261b5c72d00 attempts 1 blocker null
00234298 v1: 11 words; best v1 11 words; streak 0
v1: 11 words, first diff at 0: C11; next: bind next serial t4
00234298 v2: 11 words; best v1 11 words; streak 1
v2: 11 words, first diff at 0: C11; next: guard next serial
00234298 v3: 8 words; best v3 8 words; streak 0
v3: 8 words, first diff at 7: C10; next: payload store barrier
00234298 v4: 11 words; best v3 8 words; streak 1
v4: 11 words, first diff at 2: C11; next: bind next index t5
00234298 v5: 11 words; best v3 8 words; streak 2
v5: 11 words, first diff at 2: C11; next: guard next index
00234298 v6: 6 words; best v6 6 words; streak 0
v6: 6 words, first diff at 8: C11; next: serial dependency guard
00234298 v7: 4 words; best v7 4 words; streak 0
v7: 4 words, first diff at 12: C11; next: guard tag materialization before global stores
00234298 v8: 24 words; best v7 4 words; streak 1
blocked 00234298 -> store-order
K6 hard limit reached; no further claim
WP report written; done
