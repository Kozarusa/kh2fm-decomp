# rec129 progress
start 2026-10-13T08:15:00Z
claim 1 of 6: 0020e800 token a4553a80d3444856b8e944b859b2527b attempts 1
v1: 20 words, first diff at 0: C10 -> next: volatile quad store
v2: 20 words (identical), best v1 20, streak 1; next: struct copy
v3: 24 words; best v1 20; streak 2; next: union for aliasing
v4: 20 words; best v1 20; streak 3 -> stop
blocked 0020e800 -> store-order
claim 2 of 6: 0020e858 token 74fbe0a86c9c4caca098a11cc6ae0c93 attempts 1
v1 (0020e858): 20 words; best v1 20; streak 0; next: volatile slot reads (C9)
v2 (0020e858): 20 words; best v1 20; streak 1
v3 (0020e858): 18 words; best v3 18; streak 0; next: barrier after clamps
v4 (0020e858): 18 words; best v3 18; streak 1
v5 (0020e858): 18 words; best v3 18; streak 2
v6 (0020e858): 18 words; best v3 18; streak 3 -> stop
blocked 0020e858 -> store-order
claim 3 of 6: 0020e9f8 token 939e50b1d8a842b9a1d35ebf7e515f9a attempts 1
v1 (0020e9f8): 18 words; next: array globals
v2 (0020e9f8): 18 words; best v1 18; streak 1; next: pointer variables
v3 (0020e9f8): 18 words; best v1 18; streak 2; next: volatile reads
v4 (0020e9f8): 18 words; best v1 18; streak 3 -> stop
blocked 0020e9f8 -> address-materialization
claim 4 of 6: 0020eac0 token 75655d9620224c0c886e9b6d16cc5d99 attempts 1
v1 (0020eac0): 10 words; next: volatile globals
v2 (0020eac0): 10 words; best v1 10; streak 1; next: source order swapped
v3 (0020eac0): exact
submitted 0020eac0 v3
claim 5 of 6: 0020eaf8 token e429e898ae3944519d0d95d7948c503b attempts 1
v1 (0020eaf8): 23 words; next: reuse top var
v2 (0020eaf8): exact
submitted 0020eaf8 v2
claim 6 of 6: 0020ebd8 token 95e8a983b8f34da69e98b5145f2fafbf attempts 1
v1 (0020ebd8): exact
submitted 0020ebd8 v1
