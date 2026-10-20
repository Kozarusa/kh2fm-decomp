# rec95 progress
start 2026-10-13T04:19:27Z
claim 1 of 6: 001bffd8 token 50103fe50bd74e10807f6a695f93be5c attempts 1
v1: 1 words, first diff at 14: C2 -> next: index u32
submitted 001bffd8 v2
claim 2 of 6: 001c0410 token 7ce4d3e5ddc844b8acbd87a9e27a3634 attempts 1
v1: 17 words, first diff at 0: C7/C21 loop shape -> next: count++ after if
v2: 4 words, first diff at 4: C10 -> next: memory barrier after first store; 001c0410 v2: 4 words; best v2 4; streak 0
v3: 3 words, first diff at 2: C8/C11 bnezl + reg -> next: volatile first store instead of barrier; 001c0410 v3: 3 words; best v3 3; streak 0
v4: 4 words, first diff at 4: C10c no gain -> next: v3 plus temp for halfword; 001c0410 v4: 4 words; best v3 3; streak 1
001c0410 v5: 3 words; best v3 3; streak 2
001c0410 v6: 8 words; best v3 3; streak 3
blocked 001c0410 -> store-order
claim 3 of 6: 001c05b0 token c15e96d49dab491a9f56b194cea445eb attempts 1
v1: 13 words, first diff at 1: C1 missing second id check -> next: two separate if(id) blocks; 001c05b0 v1 13 words best v1
v2: 2 words, first diff at 20: C5/C11 address form -> next: pointer base for second store; 001c05b0 v2: 2 words; best v2 2; streak 0
001c05b0 v3: 2 words (edit failed, identical to v2); best v2 2; streak 1
v4: 2 words, first diff at 20: C10/C11 addiu after sw -> next: asm +r pin on pointer; best v2 2; streak 2
001c05b0 v5: 3 words; best v2 2; streak 3
blocked 001c05b0 -> address-materialization
claim 4 of 6: 001c1060 token ec6f6dbfcf0941b8a56f1da66f20ab97 attempts 1
submitted 001c1060 v1
claim 5 of 6: 001c1130 token d816dae99f8749ad978268b489e36b2c attempts 1
v1: 43 words, first diff at 4: C18/C21 alignment-checked copy -> next: packed u64 struct; 001c1130 v1 43 best v1
v2: 43 words identical to v1; best v1 43; streak 1 -> next: explicit packed 16-byte loop
submitted 001c1130 v3
claim 6 of 6: 001c11e0 token bf999a2923a3456eb1ce899bc81ee115 attempts 1
v1: 12 words, first diff at 2: C5/C11 folded address -> next: empty asm pin on base; 001c11e0 v1 12 best v1
submitted 001c11e0 v2
