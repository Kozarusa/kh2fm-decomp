# rec38 progress
start 2026-10-12T22:10:11Z
claim 00172c38 token 716b6c9e630648f5b5018936c4b74bb0 attempts 1 (claims: 1/6)
v1: 15 words, first diff at 9: C7 -> next: do-while form
v2: 15 words, same: C7 -> next: nested if with continue
v3: 15 words, same: C7 -> next: early returns with duplicated tail
v4: 8 words, first diff at 12: C7/C10 -> next: asm barrier on result
v5: 10 words, worse: asm barrier -> next: do-while with && condition
v6: 15 words: && do-while -> next: s64 result with v4 structure
v7: 9 words: s64 result -> next: asm barrier on null path only
v8: 7 words, size 100 = target; budget reached
blocked 00172c38 -> branch-layout
claim 00173008 token 511cba6943f04d3aac7d5d77ae9865b0 attempts 1 (claims: 2/6)
v1 (00173008): 30 words, first diff 1: C2/C1 lwu vs lw -> next: signed s32 object/s64 params
v2: 30 words: lw fixed, still li t7 and order differ -> next: u16 fill variable, store order f,a,b,c,d,e
v3: 21 words, size ok, store order rotated -> next: C10 source order a,b,c,d,e,f
v4: 20 words -> next: C9 volatile object
v5: 29 words worse (volatile) -> next: move pack.e store after call (dead store test)
v6: 32 words, worse -> next: C10c volatile stores via pointer
v7: 20 words, store order now exact -> next: memory barrier after stores
v8: 21 words; budget reached
blocked 00173008 -> prologue-epilogue
claim 001735b0 token 25490a7f17fd46db8e84f93f52d73769 attempts 1 (claims: 3/6)
v1 (001735b0): compile error (arg type) -> v2 fixes
v2: 23 words, size 100 vs 92, extra s regs -> next: explicit temp with address compare
v3: 11 words, 88 vs 92 bytes, first diff 12 (C11/C7) -> next: if/else with duplicated tail
v4: worse (bnel folds sp) -> next: operator= with self check on Vec4
v5: 23 words Quad-return ABI wrong -> next: operator= self check with temp, pointer after call
v6: 11 words same as v3 -> next: object->target = &(D = temp)
v7: 11 words same -> next: asm pin on pointer
v8: 10 words; budget reached
blocked 001735b0 -> register-allocation
claim 00173ce8 token 7d9c6b0f102748e9b778cfd7b6e13e20 attempts 1 (claims: 4/6)
blocked 00173ce8 -> vu-macro (R3, 0 versions)
claim 00173e38 token e27022d7ad2449589374a62b5efef4f6 attempts 1 (claims: 5/6)
submitted 00173e38 v1
claim 00173f08 token a5ae2a5ba1b2492d97f56a8512652158 attempts 1 (claims: 6/6)
v1 (00173f08): 21 words, pointer computed before call -> next: compute pointer after call
v2: 13 words, s0/s1 swapped, sq folded -> next: asm pin on pointer (C11d)
v3: 7 words, beql operand order, t0, final stores -> next: operator= compare as &other != this
v4: 6 words, only lq/sq reg t7 vs t0 and swc1/sw order -> next: bind quad temp to \
v5: 4 words, store order swc1/sw -> next: C10c volatile object store
v6: 4 words same -> next: volatile y store as well
submitted 00173f08 v7
