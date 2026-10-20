# rec54 progress
start 2026-10-12T23:26:43Z
claim 0018d738 token dbcaf4ebc6a34306bfc0b7df262eb54a attempts 1
v1: 5 words, first diff 8: C10 -> next: separate scalar globals
v2: 4 words, first diff 7: C10/C11 -> next: pointer var
v3: 5 words -> next: all via pointer
v4: 5 words -> next: C11d asm pin
v5: 6 words -> next: volatile
v6: 6 words -> stop (no improvement 4 versions)
blocked 0018d738 -> store-order
claim 0018e108 token a5892ef9dad7466586d9874c0ceccefc attempts 1 (target 2 of 6)
v1: 9 words, C11 -> pointer locals
v2: 9 words same -> C11c bindings
v3: 7 words -> C11d asm pin
submitted 0018e108 v4
claim 0018f070 token 339f2448ca1b446783c16af6b09a12ce attempts 1 (target 3 of 6)
v1: compile error (scope)
v2: 13 words C21 -> rewrite as while(1) with early returns
v3: 13 words C7 -> if/else form
v4: 13 words same -> ternary do/while
v5: 14 words -> stop
blocked 0018f070 -> branch-layout
claim 0018fd40 token dc3121f577f34106aa9cd05d6a26f76f attempts 1 (target 4 of 6)
v1: 8 words C10/C11 -> locals in load order
v2: 9 words -> volatile loads (C9/C10c)
v3: 8 words -> sibling declaration + s32 pointer
v4: 8 words -> stop
blocked 0018fd40 -> register-allocation
claim 00190140 token 8c185bc017134e248580e3e81ecae1c8 attempts 1 (target 5 of 6)
submitted 00190140 v1
claim 00190388 token 1e3636c9d64c4655b5876c94cf2bafee attempts 1 (target 6 of 6)
v1: 18 words, 76 bytes: C1 casts -> pointer args
v2: 16 words -> C11c bindings s1 s0 t0
v3: 18 words 80 bytes -> drop dest/t0 bindings
v4: 6 words -> bind quad temp to t0
v5: 5 words -> C10d barrier
submitted 00190388 v6
