# rec75 progress
start 2026-10-13T01:44:21Z
claim 1 of 6: 001a6c90 token cd692dd9bac6411bbbea5feeda2b7796 attempts 1
v1 exact; submitted 001a6c90 v1
claim 2 of 6: 001a74f8 token 62640bab0c284a858b61709e4892e4c7 attempts 1
v1: 7 words, first diff 3: C13/C1 (arg a0 and tail call) -> next: no-arg callee, void
v3 exact; submitted 001a74f8 v3
claim 3 of 6: 001a7588 token 6d5574ad7679443883d5b8f984bb0831 attempts 1
v1: 16 words, first diff 1: C11/C9 -> next: return buf.b duplicated per path
v2: 15 words, first diff 1: C7 branch layout; reload semantics -> next: Buf* dest (alias set)
v3: 16 words; best v2 15; streak 1 -> next: typed callee params
v4: 16 words; best v2 15; streak 2 -> next: v2 form with volatile reads (C9)
v5: 13 words; best v5 13; streak 0 -> next: explicit reload after copy
v6: 16 words; best v5 13; streak 1 -> next: nested ifs with returns, no volatile
v7: 15 words; best v5 13; streak 2 -> next: v5 with void* first/second params (C11)
v8: 13 words; best v5 13; streak 3 -> block
blocked 001a7588 -> branch-layout
claim 4 of 6: 001a78c0 token cc4871d1be77400da55c097b30b9de57 attempts 1
v1 exact; submitted 001a78c0 v1
claim 5 of 6: 001a80c8 token 3abfe32f85fa4c32b5667bfc17394dc4 attempts 1
v1: 5 words, first diff 1: C11 reorder -> next: for loop form
v2: 14 words; best v1 5; streak 1 -> next: for loop with local count
v3 exact; submitted 001a80c8 v3
claim 6 of 6: 001a8190 token 84de37c1d5214d82a6906fe7d0326a3f attempts 1
v1: 17 words, first diff 3: C2 sltiu vs slti -> next: s32 type
v2: 15 words; best v2 15; streak 0 -> next: C7 positive-condition nesting
v3: 15 words; best v2 15; streak 1 -> next: id var, positive else-if chain
v4: 15 words; best v2 15; streak 2 -> next: inverted nesting (C7a)
v5 exact; submitted 001a8190 v5
