# rec70 progress
start 2026-10-13T00:43:19Z
claim 0019f8c0 token 0bc0536390684d8a8dcf3d5a2162991d attempts 1
v1: 6 words, first diff at 4: C8 -> next: condition other way
0019f8c0 v1: 6 words; best v1 6 words; streak 0
v2: 7 words: C8b worse -> next: C8c volatile
0019f8c0 v2: 7 words; best v1 6 words; streak 1
0019f8c0 v3: 8 words; best v1 6 words; streak 2
0019f8c0 v4: 7 words (48 bytes, early-return form, movz remains); best v1 6 words; streak 3 -> stop per R7
blocked 0019f8c0 -> branch-layout
claim 0019f950 token 9eaec34fa57c42718d47b8839854965c attempts 1
v1: 6 words, first diff at 1: C11/C10 -> next: temp cursor variable
0019f950 v1: 6 words; best v1 6; streak 0
0019f950 v2: 6 words; best v1 6; streak 1
0019f950 v3: 1 word; best v3 1; streak 0 -> next: call arg from object
v4/v5 exact
submitted 0019f950 v5
claim 001a1658 token a24ca6887e13457683b7ed9a06ef3074 attempts 1
v1: 7 words, first diff at 6: C7 -> next: switch
001a1658 v1: 7; best v1 7; streak 0
submitted 001a1658 v2
claim 001a1910 token 1a5cbf32556a4e3cb762e6da70ebf7ca attempts 1
v1: 13 words: C1 -> next: return s32 result
001a1910 v1: 13; best v1 13; streak 0
001a1910 v2: 13; best v1 13; streak 1
001a1910 v3: 13; best v1 13; streak 2
001a1910 v4: 13; best v1 13; streak 3 -> stop
blocked 001a1910 -> store-order
claim 001a1b30 token 5a237f0731ca4500b0b22a381c773a9b attempts 1
v1: 13 words, first diff 1: C3 -> next: separate s32 copy
001a1b30 v1: 13; best v1 13; streak 0
001a1b30 v2: 13; best v1 13; streak 1
001a1b30 v3: 13; best v1 13; streak 2
001a1b30 v4: 13; best v1 13; streak 3 -> stop
blocked 001a1b30 -> branch-layout
claim 001a2578 token 6470e54aaaff4bd4bc05af9d03b06fee attempts 1
v1: 19 words, first diff 0: C1/C21 -> next: Ghidra if/else shape with u16 reload per branch
001a2578 v1: 19; best v1 19; streak 0
001a2578 v2: 19; best v1 19; streak 1
001a2578 v3: 19; best v1 19; streak 2
submitted 001a2578 v4
