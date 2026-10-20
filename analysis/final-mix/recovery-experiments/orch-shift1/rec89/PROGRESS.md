# rec89 progress
start 2026-10-13T03:50:21Z
claim 1 of 6: 001ba028 token 92a9eb2fe2834c7bbd253739b242ffcd attempts 1
v1: 13 words, first diff 0: C21 -> next: single exit u8 result
v2: 12 words, first diff 0 (size ok 56): C7 -> next: ternary form
v3: 12 words; best v2 12; streak 1 -> next: volatile global + if/else (C9)
v4: 14 words; best v2 12; streak 2 -> next: s32 result, u8 return
v5: 13 words; best v2 12; streak 3 -> stop
blocked 001ba028 -> branch-layout
claim 2 of 6: 001bb7f8 token 83021efbfec040d2ae77fa2daf843745 attempts 1
v1 (001bb7f8): 15 words, first diff 1: C12 -> next: bind result to s0
v2 (001bb7f8): 12 words, first diff 6; best v2 -> next: restructure with early return (C7c)
v3 (001bb7f8): exact. submitted 001bb7f8 v3
claim 3 of 6: 001bb958 token a6cb83362af34c6ba6534c2e242c3125 attempts 1
v1 (001bb958): 21 words, 92/88 bytes; zero-extension of callee result -> next: u64 return (C20)
v2 (001bb958): 21 words, 84/88; only prologue sd ra vs delay slot differs -> next: restructure (C7)
v3 (001bb958): 23 words; best v2 21; streak 1 -> next: if/else early return (C7c)
v4 (001bb958): 21 words; best v2 21; streak 2 -> next: u64 param type
v5 (001bb958): 21 words; best v2 21; streak 3 -> stop
blocked 001bb958 -> prologue-epilogue
claim 4 of 6: 001bba88 token 8a8d890ab1334e91be7591e91b0cd3d5 attempts 1
v1 (001bba88): 3 words, 44/52 -> next: if/else with explicit zero (C7c)
v2 (001bba88): 10 words; best v1 3; streak 1 -> next: direct returns
v3 (001bba88): 8 words; best v1 3; streak 2 -> next: ternary
v4 (001bba88): 8 words; best v1 3; streak 3 -> last attempt allowed? no: R7 says stop. 
blocked 001bba88 -> branch-layout (v5 draft unprobed)
claim 5 of 6: 001bbac0 token e8f116b1338e49418d6c4f48e6ab3d25 attempts 1
submitted 001bbac0 v1
claim 6 of 6: 001bbb50 token 3efebafcc22b47c4a2fd2cf3f0fc2ac7 attempts 1
v1 (001bbb50): 13 words, 72/88; sltiu vs slti -> next: s32 kind (C2)
v2 (001bbb50): 12 words; best v2 12 -> next: swap branch (C7a)
v3 (001bbb50): 13 words; best v2 12; streak 1 -> next: switch
submitted 001bbb50 v4
WP report written
