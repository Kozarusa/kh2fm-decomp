# rec13 progress
start 2026-10-12T19:06:27Z
claim 0013b9e0 token 43bf0ea3fae041be8349de1bd71a4320 attempts 1 (claims: 1)
submitted 0013b9e0 v1
claim 0013d1d0 token bbeef3f67f914fef8e9d30a75740e6b9 attempts 1 (claims: 2)
v1: 5 words, first diff at 3: C1/C7 missing nop (size 52 vs 56) -> next: nested if (C7c)
v2: 5 words same (C7c nested if no effect) -> next: C13 return func()
v3: worse (return u32, extra move v0) -> next: C7b ||
v4: same 5 -> next: loop form
v5: same 5 words (loop form) -> blocking
blocked 0013d1d0 -> branch-layout
claim 0013efe8 token b71eb100808947f68554dcb1e8d00484 attempts 1 (claims: 3)
v1: 12 words 64/56 bytes (u64 args cause lwu/dsll32): C1/C20 -> next: s32 params, s32 global
submitted 0013efe8 v2
claim 0013f050 token 5a2fd3233e4d4116aa629fb1c85a6912 attempts 1 (claims: 4)
v1: 16 words, first diff 16 (branch layout of if chain, 136/128): C7 -> next: switch
v2: switch worse (16+) -> next: else-if chain, order 1,0,2,3
v3: same as v1 16 words -> next: switch with case order 1,0,2,3
v4: 18 words worse -> blocking
blocked 0013f050 -> branch-layout
claim 00140480 token b6e46ed1763a42eb8b92b3cd5fd943a6 attempts 1 (claims: 5)
v1: 31 words 116/128, stack layout differs, lq uses t7 vs t0 (C1/C11) -> next: outs as s32[4] declared last
v2: 32 words (variadic callee reserves outgoing area) -> next: fixed prototype
v3: 31 words -> blocking
blocked 00140480 -> large-control-flow
claim 001407d0 token 4ae7c4401d7149aebdd7e519302dc435 attempts 1 (claims: 6)
v1: 30 words 120/128; original quad moves via t0 (asm lq \ pattern from fm_copy_helpers) -> next: asm quad copy
v2: 2 words, beq operand order -> next: swap comparison operands
submitted 001407d0 v3
