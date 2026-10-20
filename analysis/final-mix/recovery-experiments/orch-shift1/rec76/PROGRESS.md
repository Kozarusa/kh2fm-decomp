# rec76 progress
start 2026-10-13T01:52:48Z
claim 1 of 6: 001a81f0 token 69fed7860fb24ce0bef84e95b6586627 attempts 1
v1: 22 words, first diff at 3: C11 -> next: separate temp copy for count
001a81f0 v1: 22 words; best v1 22 words; streak 0
v2: 22 words same: C11b -> next: s32 count w/ for loop
001a81f0 v2: 22 words; best v1 22 words; streak 1
v3: 26 words, first diff at 1: C21-ish for-loop worse -> next: assign count in the if condition
001a81f0 v3: 26 words; best v1 22 words; streak 2
v4: 24 words: worse -> next: C11d asm barrier on count
001a81f0 v4: 24 words; best v1 22 words; streak 3
blocked 001a81f0 -> register-allocation
claim 2 of 6: 001a8258 token 8f120fb61d884ab4acbfff95476fe839 attempts 1
v1: 15 words, first diff at 1: C11 -> next: separate temp w/ asm barrier
001a8258 v1: 15 words; best v1 15 words; streak 0
v2: exact
submitted 001a8258 v2
claim 3 of 6: 001a82b0 token a5984c40192943708a4c1775739461ff attempts 1
v1: 5 words, first diff at 1: C11 -> next: compute limit before next
001a82b0 v1: 5 words; best v1 5 words; streak 0
v2: 5 words same: -> next: stride variable
001a82b0 v2: 5 words; best v1 5 words; streak 1
v3: 5 words same -> next: C7c invert structure
001a82b0 v3: 5 words; best v1 5 words; streak 2
v4: 15 words
001a82b0 v4: 15 words; best v1 5 words; streak 3
blocked 001a82b0 -> address-materialization
claim 4 of 6: 001a8510 token 5c464bd035fb4d6c8a55b564660a2f52 attempts 1
v1: exact
submitted 001a8510 v1
claim 5 of 6: 001a8c78 token f92fd46bbece4621aeee076d87659604 attempts 1
v1: 19 words, first diff at 2: C12 -> next: keep result var live across call
001a8c78 v1: 19 words; best v1 19 words; streak 0
v2: 19 words (semantics wrong: index==0 returns 1) -> next: Ghidra-shaped return 0/1
001a8c78 v2: 19 words; best v1 19 words; streak 1
v3: 20 words -> next: result var set to 1 via || chain
001a8c78 v3: 20 words; best v1 19 words; streak 2
v4: 17 words, first diff at 4: C7/C9 load hoisted -> next: nest load after index check, kind var
001a8c78 v4: 17 words; best v4 17 words; streak 0
v5: 20 words
001a8c78 v5: 20 words; best v4 17 words; streak 1
v6: 18 words
001a8c78 v6: 18 words; best v4 17 words; streak 2
v7: 16 words, first diff at 4: C3/C11 -> next: u32 byte/kind with (u8) cast at call
001a8c78 v7: 16 words; best v7 16 words; streak 0
v8: 4 words, first diff at 7: C11 register/order swap of andi 0x1f vs 0x80 (budget reached)
001a8c78 v8: 4 words; best v8 4 words; streak 0
blocked 001a8c78 -> register-allocation
claim 6 of 6: 001a8cd0 token f9099c0f57a6431891a748cd5a67513d attempts 1
v1: 20 words, first diff at 1: C7c -> next: result var preset -1 with break
001a8cd0 v1: 20 words; best v1 20 words; streak 0
v2: 29 words, worse -> next: early return -1 for kind==0x12 then loop
001a8cd0 v2: 29 words; best v1 20 words; streak 1
v3: 7 words, first diff at 2: C10/C11 -> next: init index after the early return
001a8cd0 v3: 7 words; best v3 7 words; streak 0
v4: exact
submitted 001a8cd0 v4
