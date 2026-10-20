# rec12 progress
start 2026-10-12T19:06:27Z
claim 0013aca0 token 72d86faa995e483ab6379b6d67e6abef attempts 1 (claims: 1/6)
v1: 4 words, first diff at 12: C11 -> next: struct form (v2)
submitted 0013aca0 v2
claim 0013d750 token b9b4426f1ed34c3fb289dd0e0440d94e attempts 1 (claims: 2/6)
submitted 0013d750 v1
claim 0013e3b0 token c847152f6d2947e9ae7b95030dd2fdac attempts 1 (claims: 3/6)
v1: 18 words, first diff at 3: C11/C21 -> next: inline object+0x1c0 (v2)
v2: 18 words, same -> next: kn::FVector (C14) v3
v3: 26 words (self-assign guard added) -> next: asm lq/sq copy v4
submitted 0013e3b0 v4
claim 0013fd10 token 0fba4cc502e744f6b8182a0d2f84dc3a attempts 1 (claims: 4/6)
v1: 19 words, first diff 3: extra s2 save + 2nd copy guard -> v2 asm second copy
v2: 21 words (92 bytes; body matches, s2 save missing) -> v3 clobber s2
v3: 10 words (clobber made sq s2, frame 80) -> v4 register output bind s2
v4: 21 words (dead asm dropped) -> v5 asm volatile output
v5: 23 words (volatile output at start made s2 hold a pointer) -> v6 output asm after last call
v6: 23 words; 3 versions without improvement -> block
blocked 0013fd10 -> prologue-epilogue
claim 00140760 token 5afd6266dbb74c5aad97d88a953ba6b1 attempts 1 (claims: 5/6)
submitted 00140760 v1
claim 001418e8 token d4b1ae489086472aa794ec29b3f485e1 attempts 1 (claims: 6/6)
v1: 15 words, first diff 0: C11 count in t5 vs t7 copy -> v2 separate remaining var
submitted 001418e8 v2
