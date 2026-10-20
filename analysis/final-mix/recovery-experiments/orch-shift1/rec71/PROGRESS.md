# rec71 progress
start 2026-10-13T00:43:19Z
claim 0019f740 token 28ea2a7ced754531a054034e05570f48 attempts 1
v1: 3 words, first diff at 0: C2/C11 -> next: signed pointer compare
v2: 2 words, first diff 0: C11 -> next: -1 temp declared first; best v2 2; streak 0
submitted 0019f740 v3
claim 0019f8f8 token 8cc0882e432943e488e74c7fb0e32a08 attempts 1
v1: 6 words, first diff 1: C11 -> next: separate base var; best v1 6
v2: 6 words, first diff 1; best v1 6; streak 1 -> next: asm s0 bind
v3: 1 words, first diff 5; best v3 1; streak 0 -> next: call uses object+18
submitted 0019f8f8 v5
claim 001a07b0 token 10442cd73bc94179a6ceb486d2845e69 attempts 1
submitted 001a07b0 v1
claim 001a17c8 token 4e907e638cd1443d819d82bf1b2d7242 attempts 1
001a17c8 v1: 24 words (116/120); best v1 24; streak 0 -> next: single base array C21/C5
001a17c8 v2: 25 words (108/120); best v1 24; streak 1 -> next: s32 base with separate offsets
001a17c8 v3: 25 words; best v1 24; streak 2 -> next: struct with table@0x9a00 count@0x9b00
submitted 001a17c8 v4
claim 001a1950 token fde5b00b7b6d4ce1ba1f4d43192e523a attempts 1
001a1950 v1: 16 words (68/60); best v1 16; streak 0 -> next: callee last param u32 (C3)
001a1950 v2: 16 words; best v1 16; streak 1 -> next: u32 param with explicit mask
001a1950 v3: 16 words; best v1 16; streak 2 -> next: if/else, u8 param
001a1950 v4: 16 words; best v1 16; streak 3 -> stop
blocked 001a1950 -> register-allocation
blocked 001a1950 -> register-allocation
claim 001a1d50 token b6a1e35eb8f24e60bc23e26e1d3a8a28 attempts 1 (claim 6 of 6)
001a1d50 v1: 11 words; best v1 11; streak 0 -> next: C7 sum separate, negated test
001a1d50 v2: 7 words; best v2 7; streak 0 -> next: C7 if/else clamp
001a1d50 v3: 11 words; best v2 7; streak 1 -> next: result=limit then !(limit<sum) result=sum
001a1d50 v4: 11 words; best v2 7; streak 2 -> next: result init inside the if
001a1d50 v5: 3 words; best v5 3; streak 0 -> next: clamp as result=limit; if !(limit<sum) result=sum
submitted 001a1d50 v6
