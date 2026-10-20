# rec68 progress
start 2026-10-13T00:35:46Z
claim 0019c920 token d9c56627cf2d4366b2390c3800c8577a attempts 1
submitted 0019c920 v1 (targets claimed: 1)
claim 0019d380 token 76852d2294f04e48b64edee068935e23 attempts 1
v1: 8 words, first diff at 3: C7 -> next: flatten result assign into if(!=0) form
v2: 8 words same: C7 -> next: single || condition
v3 exact; submitted 0019d380 v3 (targets claimed: 2)
claim 0019d438 token f90cb04647bc4160bbe7e2d6ffb54e08 attempts 1
submitted 0019d438 v1 (targets claimed: 3)
claim 0019d588 token 7b44517df570437eb0aeac58155f5c31 attempts 1
v1: 19 words, first diff at 10: C7/C1 -> next: single final store of index
v2 exact; submitted 0019d588 v2 (targets claimed: 4)
claim 0019eeb8 token cd797364f7a347f5a7ab6a4c7010e57e attempts 1
v1: 21 words, first diff at 9: C11/C21 -> next: byte-offset addressing
v2: 21 words same; best v1 21; streak 1 -> next: 2D array
v3: 21 words same; best v1 21; streak 2 -> next: hoisted row/word/mask locals
v4: 13 words, first diff at 16: C11 -> best v4 13; next: locals inside if
v5: see diff, locals inside if; best v4 13; streak 1 -> next: result preset before call
0019eeb8 v6: 15 words; best v4 13; streak 2
blocked 0019eeb8 -> register-allocation (targets claimed: 5)
claim 0019f5d8 token 41ee9eaaa79045409187be1fce809942 attempts 1
v1: 1 word (sltu vs slt): C2 -> next: signed pointer compare
submitted 0019f5d8 v2 (targets claimed: 6, K reached)
