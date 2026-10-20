# rec98 progress
start 2026-10-13T04:28:31Z
claim 1 of 6: 001c1748 token 55cbc0ad97c94ae6bcbd864a751c50be attempts 1
v1: 23 words, first diff at 0: C10/C7 -> next: invert tail branch (C7a)
best v1 23; streak 0
v2: 23 words, first diff 0: C7a done; branch ok, t5 list base missing -> next: List* list = &owner->list early
best v1 23 (v2 23); streak 1
v3: 6 words, first diff 0: C10 -> next: asm memory barrier after quad copy
best v3 6; streak 0
v4: 7 words: C10d no help -> next: temp var for quad
best v3 6; streak 1
v5: 6 words, same (temp var no effect) -> next: struct Vec4 aligned(16) copy (C14/C18)
best v3 6; streak 2
v6: 8 words; best v3 6; streak 3 -> stop
blocked 001c1748 -> store-order
claim 2 of 6: 001c2338 token 8380ef256e6444209a5570cc8b1638af attempts 1
submitted 001c2338 v1
claim 3 of 6: 001c2ba8 token da89068cf2394e17bb6870b39f8531d2 attempts 1
submitted 001c2ba8 v1
claim 4 of 6: 001c35a0 token 94d5f4d2d008416fb6a3fb75aa1ac4ec attempts 1
v1: 1 word, first diff 5: addu operand order (C11a) -> next: row + (s32)state
best v1 1; streak 0
submitted 001c35a0 v2
claim 5 of 6: 001c3aa0 token 0e85be052a094ff0920b800c826aeb44 attempts 1
v1: 24 words, first diff 8: C1a dsll32 from u64 decl -> next: declare 0016bd60(u8*,s32)
best v1 24; streak 0
v2: 10 words, first diff 22: address materialization -> next: global as array D_0036de10[] indexed [0]
best v2 10; streak 0
v3: 10 words same -> next: pointer var + empty asm (sibling 0017c108 pattern)
best v2 10; streak 1
submitted 001c3aa0 v4
claim 6 of 6: 001c5f38 token 305afa4c03014689839d43afdd1c7f1f attempts 1
v1: 7 words, first diff 0: C5/addr materialization -> next: pointer var + empty asm
best v1 7; streak 0
v2: 9 words, first diff 0: C9 -> next: volatile index byte read
best v1 7 (v2 9); streak 1
v3: 18 words (volatile worse) -> next: single empty asm tying table and object
best v1 7; streak 2
submitted 001c5f38 v4
