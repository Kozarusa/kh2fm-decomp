# rec88 progress
start 2026-10-13T03:42:37Z
claim 1 of 6: 001b87b0 token 594d44a64bab4cbbb2eb117f644514b2 attempts 1
v1: 11 words, first diff at 2: C11 -> next: asm +r on base
v2: 0 words exact
submitted 001b87b0 v2
claim 2 of 6: 001b8988 token 95be604d2a034e61a9d0c4f43cd79974 attempts 1
001b8988 v1: 2 words, first diff 2: lui/sd order -> next: volatile store
001b8988 v2: 2 words; best v1 2; streak 1 -> next: reorder statements
001b8988 v3: 2 words; best v1 2; streak 2 -> next: asm +r on value
001b8988 v4: 10 words; best v1 2; streak 3 -> stop
blocked 001b8988 -> store-order
claim 3 of 6: 001b8ce0 token 4f7d6065ff2c4075ac4308bfdbf6b6ba attempts 1
submitted 001b8ce0 v1
claim 4 of 6: 001b8d60 token b84b68626e7f4b5fbcaa59a0daafd625 attempts 1
001b8d60 v1: 14 words, 60/64 bytes: C1 -> next: return count (v0)
001b8d60 v2: 1 word, first diff 7: addu operand order -> next: index + source
001b8d60 v3: 1 word; best v2 1; streak 1 -> next: u32 offset index
v4: 0 words exact
submitted 001b8d60 v4
claim 5 of 6: 001b8e00 token 1ca848d885094fb5b6accb6b9b081f57 attempts 1
001b8e00 v1: 2 words, first diff 7: +2 folded into symbol -> next: struct array entry
001b8e00 v2: 15 words, 100/120; best v1 2; streak 1 -> next: separate pointer in true branch
v3: 0 words exact
submitted 001b8e00 v3
claim 6 of 6: 001b9bc8 token 2a3a5c295e784828af6a46651359f92c attempts 1
001b9bc8 v1: 3 words, first diff 7: C7 -> next: negate condition
v2: 0 words exact
submitted 001b9bc8 v2
WP report written
