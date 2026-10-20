# rec32 progress
start 2026-10-12T21:40:28Z
claim 0016d230 token 5e6c9d7735a649fb968ef1751851e33e attempts 1 (claims: 1/6)
v1: 4 words, first diff at 13: C11-ish -> next: pointer p=&D_004f6290; D=0; p[1]=0
v2: 4 words, first diff at 13: C11 -> next: pointer as global-level variable-ish: s32* pointer = &D at function top
v3: 4 words (same as v1): C11 -> next: pointer decl at function top
v4: 9 words worse -> next: swap source store order with pointer in block
v5: 2 words, first diff 15: C10 store order -> next: D store volatile
v6: 4 words worse -> next: pointer volatile s32*, D then p[1]
v7: 4 words worse -> next: array decl
v8: 4 words worse; budget reached
blocked 0016d230 -> store-order
claim 0016d920 token 4e6b940d5f6a48fa94f964bd3e621c0b attempts 1 (claims: 2/6)
v1: 10 words, first diff 2: stack slot order -> next: swap local declaration order
v2: 10 words same -> next: Quad buf[2] array
v3: 10 words, slots fixed, schedule differs: C9 -> next: volatile Pair*
v4: 9 words (best): C9 volatile helped slightly -> next: explicit dst pointer var
v5: 9 words no gain -> next: C11c register Quad tmp asm(\) per 0016c508
v6: 10 words but regs t0 match; schedule differs -> next: memory barrier between copies
v7: 4 words (best), first diff 7 -> next: explicit destination pointer assigned before second load
v8: 4 words; budget reached
blocked 0016d920 -> register-allocation
claim 0016e200 token 82e94c5eb5fe431daad1c1da53246e93 attempts 1 (claims: 3/6)
v1: 7 words, first diff 7: C11c -> next: register Quad asm(\)
v2: 7 words, source reg t0 not t7 -> next: bind source to \ too
v3: 5 words (best), only duplicated ld s0 differs -> next: early-return form
v4: 5 words same -> next: both branches return explicitly
v5: 5 words same -> next: memory barrier after store (C10d)
submitted 0016e200 v6
claim 0016e500 token d08211eb86ee44328c5b551f933ce730 attempts 1 (claims: 4/6)
submitted 0016e500 v1
claim 0016f4b8 token 08d2d1426c3a4d45bb32a66e7025e91d attempts 1 (claims: 5/6)
v1: 11 words, first diff 3: C12b/C3 -> next: separate result and pointer vars, u32 flag
v2: 18 words but prefix to insn 7 matches; extra andi 0xff -> next: drop '!= 0', s32 flag
v3: 18 same -> next: object as u32 base with (object+0x48) read via u32 temp / !(x&1)
v4: 18 same (extra andi 0xff persists) -> next: unsigned literals via u32 temp (xor) then and
submitted 0016f4b8 v5
claim 0016f6f8 token 450b560e85644c2d82f38bfa7c04ae97 attempts 1 (claims: 6/6)
v1: 27 words, first diff 0: result live across call (s0) and sltiu: C12/C2 -> next: result set after call, signed kind
v2: 22 words (best), slti ok; early-return form wrong -> next: v1 nested form with s32 kind
v3: 26 words worse -> next: if/else form, result assigned in each branch (not live across call)
v4: 23 words (v2 best 22) -> next: ternary chain
v5: 24 words -> next: u64 id and u64 callee decl (Ghidra: ulong param, long result) in v2 structure
v6: 32 words worse; no improvement for 3 versions (v3-v6)
blocked 0016f6f8 -> branch-layout
