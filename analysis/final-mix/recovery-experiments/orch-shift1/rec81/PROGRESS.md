# rec81 progress
start 2026-10-13T02:40:33Z
claim 1 of 6: 001ac858 token 47acd5c54a9c4705ac06fc137212709b attempts 1
submitted 001ac858 v1
claim 2 of 6: 001acf38 token 4023c35f7b1c4fa08ad44a28a3864797 attempts 1
v1: 26 words, first diff at 3: C21/C13 -> next: void with barrier after second call
v2: 0 words
submitted 001acf38 v2
claim 3 of 6: 001ad020 token 519203fad41c4199bf18d1f3ccf98cb8 attempts 1
v1: 17 words, first diff at 1: C21 -> next: pointer includes 0x608, stores at 0x148/0x14c
v2: 10 words, first diff at 1: C10 -> next: swap store source order
001ad020 v2: 10 words; best v2 10 words; streak 0
v3: 6 words, first diff at 1: C11 -> next: temp for offset
001ad020 v3: 6 words; best v3 6 words; streak 0
v4: 6 words, same: C11b -> next: struct array indexing
001ad020 v4: 6 words; best v3 6 words; streak 1
v5: 10 words: C18-ish struct no gain
001ad020 v5: 10 words; best v3 6 words; streak 2
v6: 26 words (register binding s0 worse)
001ad020 v6: 26 words; best v3 6 words; streak 3
blocked 001ad020 -> register-allocation
claim 4 of 6: 001ad0f8 token 2a94a81399c94c07800cca67b104fc1a attempts 1
v1: 10 words, first diff at 12: C9/C11 (address formed with addiu before lwc1) -> next: read through u8 array cast
001ad0f8 v1: 10 words; best v1 10 words; streak 0
v2: 10 words same -> next: volatile read
001ad0f8 v2: 10 words; best v1 10 words; streak 1
v3: 10 words same (volatile no effect) -> next: f32 array decl
001ad0f8 v3: 10 words; best v1 10 words; streak 2
v4: 10 words same
001ad0f8 v4: 10 words; best v1 10 words; streak 3
blocked 001ad0f8 -> address-materialization
claim 5 of 6: 001ad1d0 token 5304a33a3f7a4b5eb272810700b636c3 attempts 1
submitted 001ad1d0 v1
claim 6 of 6: 001ad3e0 token 274238eaa1a3411ab634fcf3dab796b6 attempts 1
submitted 001ad3e0 v1
