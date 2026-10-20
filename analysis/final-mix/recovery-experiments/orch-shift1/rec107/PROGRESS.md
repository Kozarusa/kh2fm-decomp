# rec107 progress
start 2026-10-13T05:21:12Z
claim 1 of 6: 001d5198 token 748983af961e45fd98d0a0b6e3f18857 attempts 1
v1: 21 words, first diff at 5: C21/loop shape -> next: increment index at loop end
001d5198 v1: 21 words; best v1 21 words; streak 0
v2: 0 words exact
submitted 001d5198 v2
claim 2 of 6: 001d53e8 token e9687e527f044b59a59ebc9ebc5c7ab4 attempts 1
v1: 4 words, first diff 11: C11 -> next: temporaries in load order 1,3,2
001d53e8 v1: 4 words; best v1 4; streak 0
001d53e8 v2: 7 words; best v1 4; streak 1
001d53e8 v3: 6 words; best v1 4; streak 2
001d53e8 v4: 6 words; best v1 4; streak 3 -> stop
blocked 001d53e8 -> register-allocation
claim 3 of 6: 001d59b0 token 8d3078d5cc394e539426d5e684649380 attempts 1
001d59b0 v1: 25 words; best v1 25; streak 0 (C21, do-while loop; reloaded global)
001d59b0 v2: 12 words; best v2 12; streak 0 (C11 swap)
001d59b0 v3: 12 words; best v2 12; streak 1
001d59b0 v4: 12 words; best v2 12; streak 2
001d59b0 v5: 9 words; best v5 9; streak 0
001d59b0 v6: 9 words; best v5 9; streak 1
v7: 0 words exact
submitted 001d59b0 v7
claim 4 of 6: 001d5cd0 token 48a9a37375c148729f5c51fc9ab68a1b attempts 1
001d5cd0 v1: 13 words; best v1 13; streak 0 (folded base)
001d5cd0 v2: 13 words; best v1 13; streak 1
v3: 0 words exact
submitted 001d5cd0 v3
claim 5 of 6: 001d5ec0 token 1188a0708ca74e97ab5f2edfb194c638 attempts 1
001d5ec0 v1: 12 words; best v1 12; streak 0 (C1: v0 holds entry value)
001d5ec0 v2: 11 words; best v2 11; streak 0 (returns u16 value ok; address calc mismatch)
001d5ec0 v3: 23 words; best v2 11; streak 1
001d5ec0 v4: 11 words; best v2 11; streak 2
001d5ec0 v5: 11 words; best v2 11; streak 3 -> stop
blocked 001d5ec0 -> address-materialization
claim 6 of 6: 001d6d00 token 77277cbf08a04c8d82bdc1cab5cc034e attempts 1
001d6d00 v1: 19 words; best v1 19; streak 0 (C20: needs s64 entry)
001d6d00 v2: 17 words; best v2 17; streak 0
001d6d00 v3: 15 words; best v3 15; streak 0 (pointer entry, size ok; layout of exits differs)
001d6d00 v4: 15 words; best v3 15; streak 1
v5: 0 words exact
submitted 001d6d00 v5
