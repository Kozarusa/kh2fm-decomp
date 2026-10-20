# rec66 progress
start 2026-10-13T00:24:51Z
claim 0019ac80 token ba2cccfd541948148aa5d916ad38dd15 attempts 1 (claims: 1/6)
v1: 26 words, first diff at 1: C11 -> next: restructure result assignments in loop
v2: 33 words (worse), streak 1; next: v1 + register binding t5
v3: 3 words (best), first diff 13: C7/C11 -> next: result=1/break/result=0 in loop
v4: 4 words; best v3 3; streak 1; next: v4 + result=0 before loop
v5: 4 words; best v3 3; streak 2; next: v3 + result=0 between ad58 call and compare
v6: 1 word (best); streak 0; next: v6 + loop result=1/break/result=0
v7: 2 words; best v6 1; streak 1; next: v6 + result=0 at loop end
v8: 15 words; best v6 1; budget 8 reached
blocked 0019ac80 -> branch-layout
claim 0019b260 token 253cbaf740514ced8a1305fc344199fb attempts 1 (claims: 2/6)
0019b260 v1: 5 words: C11 -> next: temp copy of count
0019b260 v2: 17 words (worse), best v1 5, streak 1; next: use global directly in test and loop
submitted 0019b260 v3
claim 0019b380 token 2beb3b161f344f36b0b3a4755ecdcb56 attempts 1 (claims: 3/6)
0019b380 v1: 17 words, size 76/80 -> next: read header->count directly in test and loop condition
0019b380 v2: 12 words (best), 80/80 -> next: u16 local count
0019b380 v3: 17 words, best v2 12, streak 1 -> next: limit copy inside if
0019b380 v4: 17 words, best v2 12, streak 2 -> next: asm copy of limit (C11d)
submitted 0019b380 v5
claim 0019bad8 token bac09da7d256429bb7c4e5cac709343e attempts 1 (claims: 4/6)
0019bad8 v1: 13 words, extra andi 0xff -> next: drop != 0, use u32 return type
0019bad8 v2: 15 words, best v1 13, streak 1 -> next: s32 fields, bool return
0019bad8 v3: 13 words, best v1 13, streak 2 -> next: bitfield flags
0019bad8 v4: 2 words (best): bitfield offsets -> next: pad bitfield words
submitted 0019bad8 v5
claim 0019bf50 token c30616ad905f43b18f068af849d13d89 attempts 1 (claims: 5/6)
0019bf50 v1: 25 words, wrong offsets (Quad alignment) -> next: u8* offsets
0019bf50 v2: 25 words offsets right, need lq via t0 (C14, pattern from 001906f0) -> next: register Quad t0
0019bf50 v3: 25 words, 100 bytes; compiler folds offsets -> next: asm +r on address pointers
0019bf50 v4: 25 words, best v1 25, streak 3 -> stop (R7); block
blocked 0019bf50 -> abi-layout
claim 0019c590 token 3d9c7cf8412245ca8db522c09bfea4f3 attempts 1 (claims: 6/6)
submitted 0019c590 v1
