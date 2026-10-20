# nm01 progress
start 2026-10-13T01:00:36Z
claim 1 of 6: 0019ac80 token 1c2c1332804c4ce189f3bc612fa1ba7d attempts 2
submitted 0019ac80 v1
claim 2 of 6: 00198aa8 token c32ce3da5f7e4878add65f3ba498fe67 attempts 2
v1: 2 words, first diff at 10: C11 -> next: add +r guard on total
v2: 2 words, same: C11 -> next: volatile asm guards
v3: 4 words: worse; best v1 2 words; streak 2 -> next: bind scaled to 15
v4: authoring error (comment swallowed code, 14 words); retry as v5
blocked 00198aa8 -> register-allocation
claim 3 of 6: 00195468
claim 3 of 6: 00195468 token c517c5e1b7b84303b89164080dcfe726 attempts 2
submitted 00195468 v1
claim 4 of 6: 001904a8 token 827d3e23fc8345c8bab6edc6c7b8e0f7 attempts 2
v1: 5 words, same: C10 volatile store -> next: asm volatile memory barrier after store
submitted 001904a8 v2
claim 5 of 6: 0019ca28 token e17c815be2174820af12bb8f0c216e47 attempts 2
v1: 5 words (different shape, zero sw still first): C10d -> next: local first without barrier
v2: 5 words same as rec69 v2: C10a -> next: barrier between lw and zero store
v3: 11 words worse; best v1 5; streak 2 -> next: zero store placed between copy 1 and 2 with u32 pointer field
v4 25 words; blocked 0019ca28 -> store-order
claim 6 of 6: 00199548 token f91ab2db285342d4b6242532a973f817 attempts 2
v1: 8 words worse than 6 (rec64 v4 baseline); best v? none better; streak 1 -> next: tail as pointer var after store
v2: 8 words; best v1 8; streak 1 -> next: barrier after store plus local tail
v3: 9 words; best v1 8; streak 2 -> next: rec64 v6 (volatile 62138) plus local tail before store
v4: 8 words; blocked 00199548 -> store-order
