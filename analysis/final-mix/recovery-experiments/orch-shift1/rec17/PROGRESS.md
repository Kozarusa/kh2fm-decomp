# rec17 progress
start 2026-10-12T19:40:58Z
claim 0014a868 token cee0f8fc0a534881a81184cc2fbeae0f attempts 1
v1: exact
submitted 0014a868 v1
claim 0014ad20 token dfd4bfd2f6924f38811136510859376d attempts 1
v1: exact
submitted 0014ad20 v1
claim 0014b9a8 token 0aea869aa8e34651b3dffaf0216f7400 attempts 1
v1: 10 words, first diff at 10: C11/C9 -> next: declare 80d8 as void*
v2: 17 words (size 112), void* fix kept for size? -> next: inline helper taking Work* (C9/C11)
v3: 10 words (helper no effect; kept u64 decl) -> next: volatile dst + void* decl
v4: 17 words size 112 -> next: volatile Work* w pointer in loop only
v5: 8 words, first diff 11 (reg t3 vs t5, lw order) -> next: volatile Quad store
v6: 7 words, first diff 10 (t4/t5 swap) C11 -> next: declare count before w
v7: 7 words, same swap (C11b no effect) -> next: register binding t4/t5
v8: 3 words, first diff 12 (t6/t7 swap of dst and quad temp)
blocked 0014b9a8 -> register-allocation
claim 0014cc40 token bae43233efd84fe4ba5e0141f9f22735 attempts 1
v1: 11 words, first diff 14: addiu base before addu -> next: base = save+0x2444, offset 8 on element
v2: 11 words, same first diff (folded) -> next: s32* typed base, index element q[2]
v3: 11 words same -> next: asm empty barrier on base (C11d)
v4: exact
submitted 0014cc40 v4
claim 0014cde0 token 1b771c3fec084397be5470fcc1400052 attempts 1
v1: exact
submitted 0014cde0 v1
claim 0014cf18 token 3626395e2fca44b6ba10a622c02420b9 attempts 1 (6th, last)
blocked 0014cf18 -> privileged-instructions (R3, 0 versions)
