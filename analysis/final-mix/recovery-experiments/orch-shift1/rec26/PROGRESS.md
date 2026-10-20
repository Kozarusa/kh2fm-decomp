# rec26 progress
start 2026-10-12T20:53:58Z
claim 00160e50 token 22e34809de3a48559600e74e2862f50f attempts 1
v1: 18 words, first diff 8: C7 -> next: ternary in while cond
v2: 12 words, first diff 8: C9 -> next: volatile load of 0x1a8
v3: 17 words: C9 volatile worse -> next: assign node in condition (move in delay slot)
v4: 4 words, first diff 8: C7/C11 -> next: body uses node
v5: 4 words same as v4 -> next: for(;;) with explicit node=next then return
v6: 17 words worse -> next: swap ternary arms
v7: 4 words same -> next: if/else form
blocked 00160e50 -> branch-layout
claim 00160f10 token d56072b4ac5a4cc4bfc98c8b6c409dd3 attempts 1 (2 of 6)
v1: 18 words, C7 -> next: 4-word form from 00160e50
v2: 4 words -> next: inline helper
v3: 12 words worse -> next: struct typed
v4: 4 words same -> next: C11d asm on next
v5: 13 words worse -> next: C11c bind next to a0
v6: 3 words, first diff 8: C8/C7 -> next: if/else with register binding
v7: 17 words worse -> next: volatile D read
blocked 00160f10 -> branch-layout
claim 00161030 token 9178343ab4b54423b44fb8a097398c5a attempts 1 (3 of 6)
v1: 16 words, C11 -> next: bind next to v0
v2: 18 words, worse -> next: comma-expression form, no binding
v3: 3 words, first diff 3: C8 bnezl form -> next: Ghidra if-form
v4: 16 words worse -> next: volatile node->0x80 read
v5: 3 words same -> next: inline if/else helper
v6: 16 words worse -> next: integer typed node
v7: 3 words same -> next: assign-D-then-override
blocked 00161030 -> branch-layout
claim 001611a8 token 3600bff6945e43a883199f8b5f943f20 attempts 1 (4 of 6)
v1: 3 words, first diff 12: C8 bnezl -> next: Ghidra for(;;) form with call before node=next
v2: 28 words worse -> next: __builtin_expect
v3: 3 words same -> next: expect(node==0,0) swapped arms
v4: 3 words same -> next: goto layout with out-of-line then block
v5: 24 words but produced bnezl form (goto) -> next: goto inside for(;;)
v6: 16 words, head matches (bnezl)! first diff 15 C7 -> next: if(next!=0){call;continue;} return
v7: 16 words same -> next: break instead of return
blocked 001611a8 -> branch-layout
claim 00161248 token ff2c151e75984b108c7031057a6189fe attempts 1 (5 of 6)
v1: 13 words, head OK, first diff 13: C7 layout -> next: explicit goto body
v2: 13 words same -> next: while(1) variant
v3: 13 words same -> next: statement-expression with goto in while cond
v4: EXACT (statement-expression goto); v5 adds why comment
submitted 00161248 v5. KEY: statement-expr goto trick solves bnezl family (00160e50, 00160f10, 00161030, 001611a8 blocked earlier)
claim 001615e8 token 43f1bb093bb1456cad9a15f86f9b3b3f attempts 1 (6 of 6)
v1: 18 words, C1 extra f32 arg to 161770 -> next: drop it
v2: 2 words, first diff 10: C10 -> next: volatile store of scale
v3: 2 words same -> next: asm memory barrier
v4: 5 words worse -> next: volatile store + volatile vtbl load
submitted 001615e8 v6
