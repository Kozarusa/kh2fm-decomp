# rec124 progress
start 2026-10-13T07:34:24Z
claim 1 of 6: 001e7878 token 68484bb0e2eb4cfba9bc5345da319643 attempts 1
v1: 9 words, first diff at 4: C11 (plus wrong offset 116 vs 120) -> next: fix pad1 to 16
v2: 9 words, first diff 4: C11 s0/s1 swapped -> next: C11b temp copy of object
v3: identical to v2 (failed edit) 9 words; best v1 9; streak 2
v4: 12 words; best v1 9; streak 3 -> stop
blocked 001e7878 -> register-allocation
claim 2 of 6: 001e7cc0 token 933a4dd359174665ac32baf14533a3e9 attempts 1
submitted 001e7cc0 v1
claim 3 of 6: 001e9078 token 281bb6cd76d4474599c438efd7aa236e attempts 1
v1: 21 words, first diff at 1: C9/C10 schedule (88 vs 92 bytes) -> next: volatile global read
v2: 21 words (same code, volatile no effect); best v1 21; streak 1 -> next: C7 combine conditions
v3: 21 words (same code); best v1 21; streak 2 -> next: C10d memory barrier after store
v4: 3 words, first diff 6 (lui placement/reg); best v4 3; streak 0 -> next: C10c volatile store + volatile D instead of asm
v5: 21 words (my edit commented out the store); best v4 3; streak 1 -> next: redo volatile store
v6: 0 words exact
submitted 001e9078 v6
claim 4 of 6: 001eaee0 token 1d9e2295fadc49de91991ee1e126bff4 attempts 1
v1: 11 words, first diff 13: D reload missing (C9) -> next: volatile global
v2: 6 words, first diff 17: scheduling of lwc1 vs D reload; best v2 6; streak 0 -> next: C9 volatile source reads
v3: 10 words; best v2 6; streak 1 -> next: struct member form
v4: 6 words (same as v2); best v2 6; streak 2 -> next: C10c volatile stores (last)
v5: 4 words, first diff 12; best v5 4; streak 0 -> next: temp for first float
v6: 4 words (same); best v5 4; streak 1 -> next: volatile source on v5 base
v7: 4 words; best v5 4; streak 2 -> next (last): temp pointer after temp float
v8: 4 words; best v5 4; budget reached
blocked 001eaee0 -> store-order
claim 5 of 6: 001eb1b0 token 4f9bb098277d47d596445952d1537c32 attempts 1
v1: link error (callee symbol); fix declaration with asm label -> v2
v2: link error again (asm label symbol undefined); v3: plain extern C func_002f3d08
v3: 3 words, first diff 15 (offset 16 vs 64) -> next: u8* global +16
v4: 2 words, first diff 23: C10 store order -> next: swap cell[0]/cell[5] final stores
v5: 0 words exact
submitted 001eb1b0 v5
claim 6 of 6: 001eb228 token b086dd5e26f542e4b5a124db02bdf83f attempts 1
v1: 2 words, first diff 23: C10 store order -> next: swap cell[5]/cell[10]
v2: 0 words exact
submitted 001eb228 v2
