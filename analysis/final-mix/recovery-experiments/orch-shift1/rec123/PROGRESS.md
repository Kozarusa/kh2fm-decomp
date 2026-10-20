# rec123 progress
start 2026-10-13T07:34:24Z
claim 1 of 6: 001e7810 token 5496075ff6b14b96bcd353c8bc1a453e attempts 1
v1: 9 words, first diff at 4: wrong offset 112 vs 120 (fix pad) + C11 -> next: pad1[16]
v2: 9 words, first diff at 4: C11 -> next: temp copy self used in loop
001e7810 v3: 9 words; best v1 9 words; streak 2
001e7810 v4: 6 words; best v4 6; streak 0. next: count local reloaded after call (C11b)
submitted 001e7810 v5
claim 2 of 6: 001e78e0 token ef58dbde87a8459a9f05806468015cec attempts 1
submitted 001e78e0 v1
claim 3 of 6: 001e8bb8 token 1b6130c24090433ab179a90a7705dde7 attempts 1
001e8bb8 v1: 8 words, first diff 13: trap=teq (unfixable), tail call C13 reverse, arg order -> next: asm memory barrier after last call
001e8bb8 v2: 3 words (trap teq vs break + li/addiu swap); best v2 3; streak 0 -> next: line local before second call
001e8bb8 v3: 3 words; best v2 3; streak 1 -> next: pointer temps
001e8bb8 v4: 3 words; best v2 3; streak 2 -> next: asm guard on line
001e8bb8 v5: 3 words; best v2 3; streak 3 -> block
blocked 001e8bb8 -> privileged-instructions
claim 4 of 6: 001ea458 token d9722555374d43258eb7991fad811852 attempts 1
submitted 001ea458 v1
claim 5 of 6: 001eb0c8 token 5016e18d34bd40ecb05254f0db7c604f attempts 1
001eb0c8 v1: link error (asm label wtarget undefined) -> v2 extern C func_002f3d08(u32,u32,u32)
submitted 001eb0c8 v2
claim 6 of 6: 001eb140 token ef79344db3194b419691c456b4a3345b attempts 1
submitted 001eb140 v1
