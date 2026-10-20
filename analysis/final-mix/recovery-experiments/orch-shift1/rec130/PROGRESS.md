# rec130 progress
start 2026-10-13T08:24:58Z
claim 1 of 6: 0020f188 token 8ae1006f718f4e54a4a3ef285a1e7e5b attempts 1
v1: 17 words, first diff at 2: C13 -> next: asm volatile empty at end (sibling pattern)
v2: 9 words, first diff at 2: C10 -> next: memory barrier between stores
0020f188 v2: 9 words; best v2 9 words; streak 0
v3: 10 words, first diff at 2: C10 -> next: drop temporaries, direct stores (from v2)
0020f188 v3: 10 words; best v2 9 words; streak 1
v4: 9 words, first diff at 2: C10 -> next: swap statement order (from v4)
0020f188 v4: 9 words; best v2 9 words; streak 1 (not beaten; counts 2)
v5: 7 words, first diff at 2: C11/C12 -> next: local pointer variable for dest
0020f188 v5: 7 words; best v5 7 words; streak 0
v6: 7 words, first diff at 2: C11 -> next: empty asm guard on dest
0020f188 v6: 7 words; best v5 7 words; streak 1
v7: 11 words, first diff at 1: C11 -> next: volatile dest array (from v5)
0020f188 v7: 11 words; best v5 7 words; streak 2
v8: 9 words; best v5 7 words; streak 3 -> stop
blocked 0020f188 -> register-allocation
claim 2 of 6: 0021cda0 token 37211c859e9c41e895b0850939775fe0 attempts 1
v1 (0021cda0): 5 words, first diff at 2: C8/C11 -> next: ternary
0021cda0 v1: 5 words; best v1 5 words; streak 0
v2 (0021cda0): 5 words: C8 -> next: scalar globals with &, and u32* callee
0021cda0 v2: 5 words; best v1 5 words; streak 1
v3 (0021cda0): 5 words: C11 -> next: register bind \
0021cda0 v3: 5 words; best v1 5 words; streak 2
v4 (0021cda0): EXACT
submitted 0021cda0 v4
claim 3 of 6: 0021e9d0 token 47b042ae47aa458fa33e44a29ed77a8d attempts 1
v1 (0021e9d0): 20 words, first diff at 6: C9 -> next: volatile read of one
0021e9d0 v1: 20 words; best v1 20 words; streak 0
v2 (0021e9d0): 20 words, identical: no effect -> next: C11b declare one first
0021e9d0 v2: 20 words; best v1 20 words; streak 1
v3 (0021e9d0): 20 words: no effect -> next: C10c volatile matrix stores (from v1)
0021e9d0 v3: 20 words; best v1 20 words; streak 2
v4 (0021e9d0): 31 words but stores/f-regs all match; only load order/addr fold differs -> next: C9 volatile table reads (from v4)
0021e9d0 v4: 31 words; best v1 20 words; streak 3 by rule -> but see below
blocked 0021e9d0 -> store-order
claim 4 of 6: 0021ea50 token bdb9d6417d00469c9adb93703a525972 attempts 1
v1 (0021ea50): 24 words, first diff at 6: C11 regs -> next: non-volatile table reads
0021ea50 v1: 24 words; best v1 24 words; streak 0
v2 (0021ea50): 31 words: worse -> next: pointer variable for one (from v1)
0021ea50 v2: 31 words; best v1 24 words; streak 1
v3 (0021ea50): 24 words, no effect -> next: explicit negated temp (from v1)
0021ea50 v3: 24 words; best v1 24 words; streak 2
v4 (0021ea50): 24 words; best v1 24 words; streak 3 -> stop
blocked 0021ea50 -> float-transport
claim 5 of 6: 0021ead0 token 592bdac96313473582aa58b36344acfa attempts 1
v1 (0021ead0): 24 words, first diff at 6 (same family as 0021ea50) -> next: volatile read of constant
0021ead0 v1: 24 words; best v1 24 words; streak 0
v2 (0021ead0): 27 words: worse -> next: cosine declared first, non-volatile table reads (from v1)
0021ead0 v2: 27 words; best v1 24 words; streak 1
v3 (0021ead0): 31 words: worse -> next: separate index temps (from v1)
0021ead0 v3: 31 words; best v1 24 words; streak 2
v4 (0021ead0): 24 words; best v1 24 words; streak 3 -> stop
blocked 0021ead0 -> float-transport
claim 6 of 6: 0021f060 token 539436dc438148a295590c2ab510ba3d attempts 1
v1 (0021f060): 26 words, first diff at 1: C21/C11 -> next: typed struct with fields
0021f060 v1: 26 words; best v1 26 words; streak 0
v2 (0021f060): 26 words identical -> next: C10c volatile object accesses
0021f060 v2: 26 words; best v1 26 words; streak 1
v3 (0021f060): 19 words, first diff at 12: C9 -> next: volatile reload of base after offset read
0021f060 v3: 19 words; best v3 19 words; streak 0
v4 (0021f060): 13 words, first diff at 6: C10 -> next: read flags (18) before the 36 store
0021f060 v4: 13 words; best v4 13 words; streak 0
v5 (0021f060): 21 words: worse -> next: C11c bind base to t3 (from v4)
0021f060 v5: 21 words; best v4 13 words; streak 1
v6 (0021f060): 11 words, first diff at 8: C11/C10 -> next: u32 flags temp read before 36 store (from v6)
0021f060 v6: 11 words; best v6 11 words; streak 0
v7 (0021f060): 20 words: worse (andi on u16 read) -> next: C11c bind table to t4 (from v6)
0021f060 v7: 20 words; best v6 11 words; streak 1
v8 (0021f060): 9 words; best v8 9 words; budget of 8 versions reached
blocked 0021f060 -> store-order
