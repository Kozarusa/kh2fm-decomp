# rec99 progress
start 2026-10-13T04:39:53Z
claim 1 of 6: 001c73e0 token 25cfe3fc0a334100bc1bf1bf5ae43d34 attempts 1
v1: 12 words, first diff at 2: C13 -> next: void, no return
001c73e0 v1: 12 words; best v1 12 words; streak 0
v2: 12 words, first diff at 2: C13 still sibcall -> next: empty asm after last call
001c73e0 v2: 12 words; best v1 12 words; streak 1
v3: 13 words, first diff at 2: addiu t7 separate -> next: volatile pointer read
001c73e0 v3: 13 words; best v1 12 words; streak 2
v4: 13 words; streak 3 -> stop
blocked 001c73e0 -> address-materialization
claim 2 of 6: 001c8948 token e301cd095703495aa0a03c74b046b2db attempts 1
v1: exact. submitted 001c8948 v1
claim 3 of 6: 001c8b48 token 5313f7682e414cf48c25acc15c7012e1 attempts 1
v1: exact. submitted 001c8b48 v1
claim 4 of 6: 001c9ab8 token bbb39e67aa3545e98c6a91bf6484c529 attempts 1
v1: 18 words, first diff at 6: C7 -> next: single result variable with break (C7c)
001c9ab8 v1: 18 words; best v1 18 words; streak 0
v2: 32 words, first diff at 1: C12/C7c worse -> next: merge two failure ifs into one || (C7b) from v1
001c9ab8 v2: 32 words; best v1 18 words; streak 1
v3: 13 words, first diff at 6: C7 -> next: result assigned after loop, failure sets 0 and jumps to shared return (goto)
001c9ab8 v3: 13 words; best v3 13 words; streak 0
v4: 13 words identical to v3 -> next: early return 1 if bc010 nonzero, loop after
001c9ab8 v4: 13 words; best v3 13 words; streak 1
v5: 14 words, t7 now matches but failure block layout differs: C7 -> next: positive nested ifs with continue
001c9ab8 v5: 14 words; best v3 13 words; streak 2
v6: 14 words identical to v5; streak 3 -> stop
blocked 001c9ab8 -> branch-layout
claim 5 of 6: 001c9b38 token a05037adbf1b4829aff7de409cda212b attempts 1
v1: 15 words, first diff at 4: C7 -> next: !=4 block first, tail call last
001c9b38 v1: 15 words; best v1 15 words; streak 0
v2: 17 words, first diff at 4: C7 -> next: ternary result for the 0x48 block
001c9b38 v2: 17 words; best v1 15 words; streak 1
v3: 20 words, first diff at 1: worse -> next: switch statement on kind
001c9b38 v3: 20 words; best v1 15 words; streak 2
v4: exact. submitted 001c9b38 v4
claim 6 of 6: 001ca448 token 7243e9134ddf4c2791ca20c424d5c07a attempts 1
v1: 4 words, first diff at 16: C3-ish -> next: return !(flags & 0x80) with u32 flags
001ca448 v1: 4 words; best v1 4 words; streak 0
v2: 4 words identical -> next: bool return type
001ca448 v2: 4 words; best v1 4 words; streak 1
v3: 4 words identical -> next: empty asm barrier on masked value
001ca448 v3: 4 words; best v1 4 words; streak 2
v4: exact. submitted 001ca448 v4
