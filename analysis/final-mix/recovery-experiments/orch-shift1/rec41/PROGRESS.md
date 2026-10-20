# rec41 progress
start 2026-10-12T22:22:38Z
claim 00174518 token d38ae32aca964ee69b1ee377c6a2d42e attempts 1
v1: 5 words, first diff at 4: C11 -> next: locals loaded in order
v2: 6 words (worse), first diff 4: C11 -> next: register bind a1/t7 on v1 form
v3: 3 words, first diff 6: C11(c) worked partially -> next: hoist f32 x local
v4: 4 words (no better) -> next: v3 with int arg hoisted to local
v5: 1 word, first diff 6 -> next: hoist x local after word
v6: 2 words -> next: x declared after word
v7: 2 words (no improvement) -> next: v6 + asm +r on first
v8: 4 words; budget reached
blocked 00174518 -> store-order
claim 00175370 token ca1022a2fd2f41ff988c3d9629e84966 attempts 1
blocked->next; v1 (00175370): 24 words, first diff 1: source read after alloc (C1/C7 order) -> next: move payload load after alloc
submitted 00175370 v2
claim 001759f0 token be81b1e29b2d47c2bd0a373efb9a653e attempts 1 (claims so far: 3)
001759f0 v1: 20 words, first diff 4: C7/C12 -> next: for loop form
001759f0 v2: 20 words (no better) -> next: Ghidra-shaped while loop with break
001759f0 v3: 28 words (worse) -> next: single-exit flag form
001759f0 v4: 31 words; no improvement 3 versions
blocked 001759f0 -> branch-layout
claim 00176c68 token fcd56baf42c6431dae440cff79cff114 attempts 1 (claims so far: 4)
submitted 00176c68 v1
claim 00177540 token f5c82402ad96418e8ae569f951b31cbd attempts 1 (claims so far: 5)
submitted 00177540 v1
claim 00178280 token ded8130507d64f62928e11ffbd2eef39 attempts 1 (claims so far: 6, last)
submitted 00178280 v1
WP report written
