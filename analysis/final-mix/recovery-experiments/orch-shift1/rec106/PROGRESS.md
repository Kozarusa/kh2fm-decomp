# rec106 progress
start 2026-10-13T05:21:12Z
claim 1 of 6: 001d5068 token c1f60f2a28384752be8435fd5d3affe3 attempts 1
v1: exact
submitted 001d5068 v1
claim 2 of 6: 001d5370 token 566a251c299b491590ef8a53de0b33a9 attempts 1
v1: 4 words, first diff at 18: C10 -> next: drop temp, reorder
v2: worse (9 words). streak 1
v3: 4 words, same as v1. streak 2
v4: 9 words. streak 3 -> block
blocked 001d5370 -> store-order
claim 3 of 6: 001d5868 token 8840c16ae4094679bfbf6f2eef27db16 attempts 1
001d5868 v1: 25 words, first diff 4 (tail calls j used instead of jal): C13 -> next: result variable ghidra form
001d5868 v2: 23 words (best), result var, still tail calls; streak 0 -> next v3 s64 return/s32 callees
001d5868 v3: 25 words; best v2 23; streak 1
001d5868 v4: 25 words; best v2 23; streak 2
001d5868 v5: 21 words (switch), best v5; streak 0
001d5868 v6: 11 words (switch+result var), best v6; streak 0
v7: exact
submitted 001d5868 v7
claim 4 of 6: 001d5d20 token 8cf14b682a7e4b4abb635748faf35a70 attempts 1
001d5d20 v1: 18 words, first diff 6: C11/address base folding -> next: asm base register
001d5d20 v2: 15 words (best), first diff 8; streak 0 -> next: constant-1 register via asm
v3: exact
submitted 001d5d20 v3
claim 5 of 6: 001d69d0 token fd9dfa2d652a4598acfbfd18ad0502ed attempts 1
v1: exact
submitted 001d69d0 v1
claim 6 of 6: 001d6cc8 token b2371fcea7d04368a145ead09af0710c attempts 1
001d6cc8 v1: 15 words, first diff 0: C7 -> next: if/else form
001d6cc8 v2: 19 words; best v1 15; streak 1
001d6cc8 v3: 11 words (best v3); streak 0
001d6cc8 v4: 15 words; best v3 11; streak 1
001d6cc8 v5: 16 words; best v3 11; streak 2
001d6cc8 v6: 15 words; best v3 11; streak 3 -> block
blocked 001d6cc8 -> branch-layout
