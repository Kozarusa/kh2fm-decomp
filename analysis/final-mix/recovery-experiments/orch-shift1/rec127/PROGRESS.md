# rec127 progress
start 2026-10-13T07:57:48Z
claim 1 of 6: 00200638 token c71373e56ea64b208b92c729d5153752 attempts 1
v1: 8 words, first diff at 21: C13 -> next: asm memory barrier after last call
v2: 0 words exact
submitted 00200638 v2
claim 2 of 6: 00201b30 token b9ddf8caa698401f970335e0f277ff66 attempts 1
blocked 00201b30 -> vu-macro
claim 3 of 6: 00202ba0 token 98eb0bbd3cdc462f9e0aca38163bcd4b attempts 1
blocked 00202ba0 -> vu-macro
claim 4 of 6: 00203ae8 token 7a5d270396604e7788eff53e37946947 attempts 1
v1: 8 words, first diff at 1: C8 -> next: if (f58 != 0) return 1; return 0
v2: 8 words, first diff at 1: C8 -> next: result variable per Ghidra structure
best v1 8 words; streak 1
v3: 10 words: C8 -> next: volatile f58 read on v1 base
00203ae8 v3: 10 words; best v1 8 words; streak 2
00203ae8 v4: 8 words; best v1 8 words; streak 3
blocked 00203ae8 -> branch-layout
claim 5 of 6: 00205718 token 6c262d9d586943eab7b5d0f8833bd5cc attempts 1
v1: 0 words exact
submitted 00205718 v1
claim 6 of 6: 00207050 token a4ca599d9e764d0f89187d79f2346f0f attempts 1
v1: 0 words exact
submitted 00207050 v1
