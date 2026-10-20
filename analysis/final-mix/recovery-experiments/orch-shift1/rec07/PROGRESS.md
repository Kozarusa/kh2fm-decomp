# rec07 progress
start 2026-10-12T17:52:30Z
claim 00132068 token e4e4d110cf474508b09411de4f83fa66 attempts 1
v1: 10 words, first diff at 0: C7 -> next: restructure with -1 block last
v2: 12 words (64 bytes), C7 partial -> next: result=base default, zero if tag nonzero
v3: 10 words, same as v1 -> next: v2 structure with result=base
v4: 11 words (64 bytes), null zero-path not shared -> next: goto layout (C7)
v5: 10 words (64 bytes), shared return not formed -> next: nested returns
submitted 00132068 v6 (targets claimed: 1)
claim 00132ec0 token 82e4aaad53b046cdb1b935d5a80f82dd attempts 1
submitted note: v1 of 00132ec0: 4 words, C10/C11 reorder address sum
submitted 00132ec0 v2 (targets claimed: 2)
claim 001340e8 token ed3a1354252c4a1095f2251ae5c82374 attempts 1
v1: 19 words (96 bytes), loop rotated, C7 -> next: for(;;) with break
v2: 19 words identical -> next: swap if/else (C7a)
v3: 17 words, size exact, delay slot fill differs -> next: nonvolatile global D_10003010
v4: 7 words (96 bytes), extern form gives lui+sw off -> next: nonvolatile cast pointer
v5: 17 words same as v3 -> next: volatile D_00347cb4 (C10c)
submitted 001340e8 v6 (targets claimed: 3)
claim 00135bd0 token a3ec0c6ed6584b2fbe67ea639b991030 attempts 1
v1: 25 words, compiler folds s1=32; original compares against first load -> next: second compare against first variable
v2: 2 words, first diff at 25: addiu/sw order (C10) -> next: compute count+1 temp before the first store
v3: 2 words same -> next: temp s32 pointer entry / alt: write via pointer arithmetic
v4: 3 words (worse) -> next: store count first
v5: worse (store order swapped) -> next: count++ then store
v6: 2 words same; no improvement for 4 versions -> block
blocked 00135bd0 -> store-order (targets claimed: 4)
claim 00135c88 token 0c9d4d90b06344d4bea79bb832ba24d1 attempts 1
submitted 00135c88 v1 (targets claimed: 5)
claim 00135cc8 token 37d2b0b3ec194d8185dabc3b09c86b3a attempts 1
submitted 00135cc8 v1 (targets claimed: 6)
