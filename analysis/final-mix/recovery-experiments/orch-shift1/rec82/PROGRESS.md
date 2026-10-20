# rec82 progress
start 2026-10-13T03:14:36Z
claim 1 of 6: 001afa50 token de105b92e3c944668bc2da830f52d41d attempts 1
v1: 1 words, first diff at 8: slt vs sltu -> next: compare as s32
submitted 001afa50 v2
claim 2 of 6: 001aff90 token 2d73e727618d47d1af5272ef2932b56e attempts 1
v1: 16 words, first diff at 3: count in t7 then move t4 -> next: reread count in loop cond
v2: 16 words, same -> next: C9 volatile count read
v3: 16 words, same; best v1 16, streak 2 -> next: struct/for loop
v4: 19 words; best v1 16; streak 3 -> block
blocked 001aff90 -> register-allocation
claim 3 of 6: 001b0498 token e9c1941d7f0d48c9b91bb78bbcf49bac attempts 1
v1: 6 words, first diff at 1: C8 branch-likely vs bnez/sltu -> next: temp variable for flags
001b0498 v2: 6 words; best v1 6 words; streak 1
001b0498 v3: 6 words; best v1 6 words; streak 2 -> next: early returns
001b0498 v4: 3 words, best v4; C7c early returns -> next: result var with first early return
001b0498 v5: 6 words; best v4 3; streak 1 -> next: invert nesting
001b0498 v6: 9 words; best v4 3; streak 2 -> next: v4 plus volatile flag byte
001b0498 v7: 3 words; best v4 3; streak 3 -> block
blocked 001b0498 -> branch-layout
claim 4 of 6: 001b0858 token a2ee2d436d1b4d00a9d32c1db7548c8e attempts 1
001b0858 v1: 13 words, first diff 8 (addr materialization vs folded lwc1 offset) -> next: u8 array cast
001b0858 v2: 13 words; best v1 13; streak 1 -> next: asm pointer barrier
submitted 001b0858 v3
claim 5 of 6: 001b1928 token d1a7c4456a264f25b8b106dfd9723f12 attempts 1
v1: 13 words, first diff at 17: C10 store order/branch layout -> next: explicit tail store before head store in else
v2: 3 words, first diff at 24: C7a blocks swapped -> next: negate condition and swap bodies
submitted 001b1928 v3
claim 6 of 6: 001b1ff0 token c51923edc68543759561d8e92def6997 attempts 1
submitted 001b1ff0 v1
