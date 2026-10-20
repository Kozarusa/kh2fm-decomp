# rec22 progress
start 2026-10-12T20:19:33Z
claim 00159f90 token 840cbf58556e4f5fa726e0af196c915f attempts 1
v1: 11 words, first diff at 3: pointer needed (C1/C21) -> next: pointer variable per Ghidra shape
v2: 13 words, first diff at 0: C7 -> next: zero store first, then pointer selection
v3: 16 words, first diff 0: C11/C7 -> next: if/else-if chain with zero store first
v4: 18 words -> next: dst pointer to keep base live
v5: 15 words; 3 versions without improvement -> block
blocked 00159f90 -> branch-layout
claim 0015a098 token 2b39bb7eb7524a089e7948b430419044 attempts 1
blocked 0015a098 -> vu-macro (R3, 0 versions)
claim 0015a528 token f0f54c8f6b0442c3953f178b0ccd5d63 attempts 1
v1 (0015a528): 13 words, first diff 2: C11 -> next: reorder declarations
v2: 30 words (stack layout swapped) -> next: back to v1, result pointer local
v3: 13 words same -> next: asm lq/sq for initial copy (original lq t0,0(s0) unguarded)
v4: 10 words, only s1/s2 swap -> next: C11c bind result pointer to s1 (17)
v5: 29 words (extra s3) -> next: bind object to s2 (18) instead
v6: 16 words -> next: from v4, resultp declared first (C11a/b)
v7: 13 words; 3 without improvement -> block
blocked 0015a528 -> register-allocation
claim 0015a768 token 6eb42b01b0d94b87aa93f596318c5e92 attempts 1
v1 (0015a768): 18 words, first diff 3: C13/C1 -> next: pointer load for D_0036b3a8
v2: 18 words same (pointer folded) -> next: block sibcall with asm after call
v3: 18->? words, tail call fixed by asm barrier; remaining addiu+lwc1 0 pointer -> next: volatile pointer
v4: 18 words; found sibling 00159c58 with same pattern -> next: copy its register-bound pattern
v5: 11 words (tail call remains) -> next: asm barrier after call
v6: EXACT; adding why comments in v7
submitted 0015a768 v7
claim 0015a810 token 773a9b9fe2824661846f042236e7fdd5 attempts 1 (claim 5 of 6)
submitted 0015a810 v1
claim 0015aa98 token 0b8d47545cd443ba9a82f8e808d6a8e5 attempts 1 (claim 6 of 6)
v1 (0015aa98): 3 words, store order rotated: C10 -> next: reorder source
v2: 5 words (alloc changed) -> next: v1 with volatile stores
v3: 4 words (epilogue loads hoisted) -> next: volatile on first two stores only
v4: 2 words (20,1c,18) -> next: volatile on 0x18 and 0x1c only
v5: 4 words -> next: v1 with memory barrier before float store
v6: 4 words (prologue order changed) -> next: volatile on float store only
v7: 3 words; 3 without improvement -> block
blocked 0015aa98 -> store-order
