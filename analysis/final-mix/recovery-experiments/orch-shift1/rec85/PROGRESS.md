# rec85 progress
start 2026-10-13T03:24:01Z
claim 1 of 6: 001b2308 token 72955bc865b44a759964810bce259976 attempts 1
v1: 20 words, first diff at 1: C10 -> next: mirror ghidra order + List struct global
v2: 13 words, first diff at 1: C9/C10 -> next: volatile float read
001b2308 v2: 13 words; best v2 13 words; streak 0
001b2308 v3: 13 words; best v2 13 words; streak 1
001b2308 v4: 13 words; best v2 13 words; streak 2
001b2308 v5: 13 words; best v2 13 words; streak 3
blocked 001b2308 -> store-order
claim 2 of 6: 001b24c8 token aac0881857c24dbd923c354ef9881320 attempts 1
submitted 001b24c8 v1
claim 3 of 6: 001b27f0 token 3ed7cf870c9f43cc8bd2eea8597938fc attempts 1
v1: 12 words, first diff 3: C11/C10 -> next: reverse local decl order
001b27f0 v1: 12 words; best v1 12 words; streak 0
001b27f0 v2: 12 words; best v1 12 words; streak 1
v3: 12 words (layout ok, sched differs) C10 -> next: copy through pointer
001b27f0 v3: 12 words; best v1 12 words; streak 2
001b27f0 v4: 12 words; best v1 12 words; streak 3
blocked 001b27f0 -> store-order
claim 4 of 6: 001b3098 token 795de881eb9a47f191dc417997027f42 attempts 1
v1: 2 words, first diff 14: lwu from u64 arg + addu operand order -> next: void* arg, swapped add
001b3098 v1: 2 words; best v1 2 words; streak 0
001b3098 v2: 1 words; best v2 1 words; streak 0
submitted 001b3098 v3
claim 5 of 6: 001b3a90 token 6259bdd61bbc4ab881188daf67e89324 attempts 1
submitted 001b3a90 v1
claim 6 of 6: 001b43e0 token b189bd14d8c5415ea4136fe648f9e8e0 attempts 1
v1: 10 words, 92/80 bytes (tail call j 105110): C13 -> next: block tail-call with asm memory barrier
001b43e0 v1: 10 words; best v1 10 words; streak 0
submitted 001b43e0 v2
