# rec91 progress
start 2026-10-13T03:59:48Z
claim 1 of 6: 001bbc30 token 5ffd3595e9ba405987f1e7403c00b05f attempts 1
v1: 20 words, first diff at 10: C7/C21 -> next: switch rewrite
submitted 001bbc30 v2
claim 2 of 6: 001bbf00 token 68f586250a5d478290f267fa8b1886e4 attempts 1
v1: 6 words, first diff at 4: C1/C3 extra andi 0xffff -> next: u32 result
v2: 6 words, streak 1 (same extra andi) -> next: temp u32 for loaded half
submitted 001bbf00 v3
claim 3 of 6: 001bbfd0 token 0320f2b385f84982977d33d7c81dca71 attempts 1
v1: 3 words, first diff at 12: address materialization (C5-ish) -> next: array decl for D_0036dc44
v2: 3 words, streak 1 -> next: asm register-forced pointer (accepted 001675b0 pattern)
submitted 001bbfd0 v3
claim 4 of 6: 001bc130 token db951938d3204fc6af582bb7a1bd1d29 attempts 1
submitted 001bc130 v1
claim 5 of 6: 001bc6a8 token d327b2f572094ae694343ea4e3f4fea7 attempts 1
v1: 21 words, first diff at 1: C3 andi on t0 -> next: u32 flag param
v2: 2 words, first diff at 8: C10 store/move order -> next: volatile byte store
v3: 2 words; best v2 2 words; streak 1 -> next: asm memory barrier after store
v4: 2 words; best v2 2 words; streak 2 -> next: barrier between sh and sb
v5: 1 word, first diff at 8: C11 a0 vs s0 in sb; best v5 -> next: asm +r on object after sh
v6: 4 words; best v5 1 word; streak 1 -> next: barriers on both sides of sb
v7: 1 word; best v5 1 word; streak 2 -> next: v5 plus volatile sb
v8: see diff; best v5 1 word
blocked 001bc6a8 -> register-allocation
blocked-attempt failed (arg quoting); claim 6 of 6: 001bc948 token 214fb42bd5a84c5b9fdb1a2a41823fa7 attempts 1
blocked 001bc6a8 -> register-allocation
v1: 11 words, first diff at 8: missing andi 0xff on compare result -> next: u8 flag variable
v2: compile error (stray backtick, my typo); best v1 11 words; streak 1
v3: 11 words, streak 2 (no andi) -> next: bool flag
v4: 11 words; best v1 11 words; streak 3 -> stop
blocked 001bc948 -> branch-layout
