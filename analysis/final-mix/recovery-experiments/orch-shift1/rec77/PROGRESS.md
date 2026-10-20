# rec77 progress
start 2026-10-13T02:09:06Z
claim 1 of 6: 001a8f10 token 053b6c6647014113ad54a31fd68f0ab6 attempts 1
v1: 18 words, first diff 0: C21 -> next: switch
v2: 13 words, first diff 4: C7 switch; best v2 13; streak 0 -> next: early-return chain
v3: 18 words; best v2 13; streak 1 -> next: merge case 1/14
v4: 0 words exact. submitted 001a8f10 v4
claim 2 of 6: 001a92d8 token 70e865eede9b4c51827a981d954c64b7 attempts 1
001a92d8 v1: 9 words, first diff 6: C11 -> next: temps
001a92d8 v2: 9 words; best v1 9; streak 1 -> next: u64 data
001a92d8 v3: 25 words; best v1 9; streak 2 -> next: register bind
001a92d8 v4: 0 words exact (needs why comments) -> v5
submitted 001a92d8 v5
claim 3 of 6: 001a9a28 token 18358c5ee546403b85dfe232f2b9c304 attempts 1
001a9a28 v1: 16 words (no jump table, 32 bytes): C1 -> next: sparse shared cases
001a9a28 v2: 16 words (range check, 44 bytes); best v1 16; streak 1 -> next: separate bodies per case
001a9a28 v3: 7 words (table ok, extra 5-word body + unresolved table addr); best v3 7; streak 0 -> next: return instead of break
001a9a28 v4: 7 words same; best v3 7; streak 1 -> next: computed goto with extern table
001a9a28 v5: 15 words; best v3 7; streak 2 -> next: label address taken first
001a9a28 v6: 16 words; best v3 7; streak 3 -> block
blocked 001a9a28 -> address-materialization
claim 4 of 6: 001aa310 token 0150b52043a949718ed947cfcce3e324 attempts 1
001aa310 v1: 14 words, first diff 4: C4 -> next: convert to f32 before call
001aa310 v2: 14 words, first diff 16 (addiu position of global): C9 -> next: array decl
001aa310 v3: 14 words same; best v1/v2 14; streak 1 -> next: local pointer
001aa310 v4: 14 words same; best v1 14; streak 2 -> next: volatile read
001aa310 v5: 14 words; best v1 14 (v2 first-diff later); streak 3 -> block
blocked 001aa310 -> address-materialization
claim 5 of 6: 001aa790 token 0fc2b4fc1f2841e1ba61a5cee44546d6 attempts 1
001aa790 v1: 3 words, first diff 15: C10 -> next: asm barrier before last store
001aa790 v2: worse/same 3+ words; best v1 3; streak 1 -> next: volatile inner
001aa790 v3: 3 words same; best v1 3; streak 2 -> next: volatile last store
001aa790 v4: 3 words same; best v1 3; streak 3 -> block
blocked 001aa790 -> store-order
claim 6 of 6: 001aa7f0 token 35136c772d324907b2f66a15d7bc135a attempts 1
001aa7f0 v1: 4 words, first diff 9: C5-ish arg offset typo + ld ra order -> next: fix arg
001aa7f0 v2: 3 words, ld ra late; best v2 3; streak 0 -> next: volatile f0 read
001aa7f0 v3: worse; best v2 3; streak 1 -> next: bind inner to t7
001aa7f0 v4: compile error (script mangled \); best v2 3; streak 2 -> next: bind inner (v5)
001aa7f0 v5: worse; best v2 3; streak 3 -> block
blocked 001aa7f0 -> store-order
