# rec79 progress
start 2026-10-13T02:30:59Z
claim 1 of 6: 001abdf0 token 5e68a347dddc4176b11d387e7807ba98 attempts 1
v1: 17 words, first diff 0: C7/C21 -> next: switch
v2: 16 words; best v2 16; streak 0 (switch)
v3: 12 words; best v3 12; streak 0 (if/if/if)
v4: 0 words exact. submitted 001abdf0 v4
claim 2 of 6: 001abe80 token 2f57cabc3dbf412b971e2b0f896080fd attempts 1
v1: exact. submitted 001abe80 v1
claim 3 of 6: 001ac078 token 2ee8bead99cc47919efa90cc38f27bc4 attempts 1
v1: 26 words (s64 params); best v1 26
v2: 9 words; best v2 9; streak 0 (s32 params)
v3: 5 words; best v3 5; streak 0 (reg bind t4/t6)
v4: 5 words; best v3 5; streak 1 (cond bind ignored)
v5: 15 words; best v3 5; streak 2 (volatile)
v6: 6 words; best v3 5; streak 3 -> stop
blocked 001ac078 -> register-allocation
claim 4 of 6: 001ac2a8 token 434a9be3116e4ea7b87f376029a090aa attempts 1
v1: 7 words (stores order, s2/s3 swap); best v1 7
v2: 2 words (move order a2/a3); best v2 2; streak 0
v3: 2 words; best v2 2; streak 1 (bind regs)
v4: 2 words; best v2 2; streak 2 (decl order)
v5: 23 words; best v2 2; streak 3 -> stop
blocked 001ac2a8 -> register-allocation
claim 5 of 6: 001ac5b8 token 62d9e4e431fe426c9a9588120761d95f attempts 1
v1: 25 words, compiled 120/116; best v1 25 (separate globals; tail via struct next)
v2: 25 words, 120/116 bytes; best v1 25 (tail now beql ok); streak 1
v3: 25 words; best v1 25; streak 2 (following temp)
v4: 15 words (do-while guard); best v4 15; streak 0
v5: 15 words (same output as v4); best v4 15; streak 1
v6: 15 words (same; u8* vtable no effect); best v4 15; streak 2
v7: 15 words (same); best v4 15; streak 3 -> stop
blocked 001ac5b8 -> branch-layout
claim 6 of 6: 001ac660 token 5cb15e8738a94ec4979524f1be1a26c0 attempts 1
v1: 2 words (lui/ori of 0x1c6ced0: C5); best v1 2
v2: exact. submitted 001ac660 v2
