# nm07 progress
start 2026-10-13T05:07:02Z
claim 1 of 6: 001ca950 token 72ea08fa35a84b9fa916147ce263ee2d attempts 2
v1: 0 words exact
submitted 001ca950 v1
claim 2 of 6: 001bc6a8 token b071198359384a7abe8587a7d52bbb17 attempts 2
v1: 1 words, first diff at 8: C11c -> next: guard +r on bound object instead of memory barrier
v2: 4 words; best v1 1 words; streak 1
v3: 2 words; best v1 1 words; streak 2
v4: 2 words; best v1 1 words; streak 3 -> stop
blocked 001bc6a8 -> register-allocation
claim 3 of 6: 001c3670 token 3407fd332acf4a7b9c7429076c1c2d56 attempts 2
v1: 12 words (base temp CSE'd); best 12 on v1 (rec97 v2 was 2); streak 1 vs 2-word baseline
v2: 18 words; best v1 12 words; streak 1
v3: 0 words exact
submitted 001c3670 v3
claim 4 of 6: 001cebb0 token a4d927f3a1684e2498183031932fa2e6 attempts 2
v1: 3 words; best v1 3 words (rec101 v1 was 2)
v2: 2 words; best v2 2 words; streak 0
v3: 2 words; best v2 2 words; streak 1
v4: 3 words; best v2 2 words; streak 2
v5: 2 words; best v2 2 words; streak 3 -> stop
blocked 001cebb0 -> register-allocation
claim 5 of 6: 001d2930 token c5cf7d886012421084bc22304ee957f1 attempts 2
v1: 2 words; best v1 2 words; streak 0 (C11c bind s0 no change)
v2: 2 words; best v1 2 words; streak 1
v3: 19 words; best v1 2 words; streak 2
v4: 23 words; best v1 2 words; streak 3 -> stop
blocked 001d2930 -> register-allocation
claim 6 of 6: 001d0068 token d48e9281a4eb489c899d39884bac1d4e attempts 2
v1: 11 words (s64 return, bad); best v1 11 words
v2: 13 words; best v1 11 words; streak 1
v3: 2 words; best v3 2 words; streak 0
v4: 2 words; best v3 2 words; streak 1
v5: 2 words; best v3 2 words; streak 2
v6: 2 words; best v3 2 words; streak 3 -> stop
blocked 001d0068 -> prologue-epilogue
