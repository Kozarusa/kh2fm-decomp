# rec44 progress
start 2026-10-12T22:41:32Z
claim 0017ce10 token ded7dc2ce7f947da997b9cb05b0018fa attempts 1 (claims: 1/6)
v1: 23 words, first diff 3: C9 -> next: load global inside each branch via pointer
v2: 22 words, first diff 5: addressing split lui/addiu missing -> next: volatile globals
v3: 22 words, first diff 5: volatile no effect -> next: pointer locals with asm +r to force lui/addiu
v4: exact. submitted 0017ce10 v4
claim 0017de70 token 9d9014fd4b6a476381e56ca5adec875d attempts 1 (claims: 2/6)
v1: 2 words, first diff 11: C11 (v0 vs t6 for fn ptr) -> next: return callee result
v2: exact. submitted 0017de70 v2
claim 0017edf0 token 292aadcc22a74b099f44c4a5a7de9b42 attempts 1 (claims: 3/6)
v1: 20 words (116/120 bytes), first diff 8: C7 result in t7 vs v0 -> next: s64 return/result
v2: 20 words, same -> next: C7 restructure with result=0 init and nested ifs
v3: 27 words worse -> next: v1 shape with one variable reused for object[1] and result
v4: 21 words -> next: C11c bind result to t7 (\) in v1 shape
v5: exact. submitted 0017edf0 v5
claim 0017f380 token c1e6470b943c4c12afb5548c0c0a21d5 attempts 1 (claims: 4/6)
v1: no rows (extern C self-prototype broke extraction) -> v2 drop prototype
v2: 13 words, first diff 9: C11 separate temp for loaded child -> v3
v3: 10 words, first diff 11: C7 branch sense/block order -> v4 early return instead of break
v4: 10 words same -> v5 do-while(next) form
v5: 21 words worse -> v6 back to v3 with if(next){call;continue;} return form (C7c)
v6: 10 words, no improvement for 3 versions -> block
blocked 0017f380 -> branch-layout
claim 0017f488 token 29adc341ac704927b3bd8ca32f7998d6 attempts 1 (claims: 5/6)
v1: exact. submitted 0017f488 v1
claim 0017fef0 token 8d842c0b6c64415bad07934ae8f8e418 attempts 1 (claims: 6/6)
R3 vu-macro but accepted siblings 001786e0 / 0018a4d8 show lqc2/sqc2/vsub asm pattern: attempting
v1: 2 words, first diff 9: C11a swap t7/t6 addiu order -> v2
v2: 6 words worse -> v3 explicit register binds t7/t6 on v2 order
v3: compile error (literal backtick-n in comment) -> v4 fixed
v4: 2 words, same first diff 9 (addiu order) -> v5 bound regs with scratch initialized first
v5: 2 words same -> v6 volatile empty asm pins scratch before accumulator
v6: exact. submitted 0017fef0 v6
