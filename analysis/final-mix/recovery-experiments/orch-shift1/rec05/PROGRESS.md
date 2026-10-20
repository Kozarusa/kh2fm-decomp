# rec05 progress
start 2026-10-12T17:07:23Z
claim 0011b038 token a5630d5af23443a3aa093a8ce6f9a171 attempts 1 (claims: 1/6)
v1: 22 words, first diff 1: u32 truncation of u64 -> next: callee returns u64
v2: 14 words, first diff 12: C9/C10 -> next: load order z first
v3: 14 words, first diff 12: load order swap no effect -> next: array initializer
v4: worse (lq/sq) -> next: C11d asm + zero reg
v5: 7 words, first diff 12: load order -> next: x loaded first
v6: 2 words, first diff 17: C10 -> next: swap vec[1]/vec[3] store order
submitted 0011b038 v7
claim 0011c828 token 137b97ac219f4472b91e488456d739a7 attempts 1 (claims: 2/6)
v1: exact. submitted 0011c828 v1
claim 0011e350 token b7ef32c72ebb4ca686eea397151f8de9 attempts 1 (claims: 3/6)
v1: exact. submitted 0011e350 v1
claim 0011ecc8 token bd1bdaab1f4245989fd1bde6eb6e66cd attempts 1 (claims: 4/6)
v1: 36 words, first diff 1: C7 duplicated call -> next: single call after if/else, handler arg
v2: 32 words, first diff 1: C7 -> next: for loop form
v3: 30 words (size ok), first diff 1: C11 -> next: C11c bind node to a1
v4: 3 words, first diff 10: C7 -> next: negate prev test, swap bodies
v5: exact. submitted 0011ecc8 v5
claim 0011f078 token 250c75b84a6740e3a7a871e10b55147f attempts 1 (claims: 5/6)
v1: 18 words, first diff 12: C7 -> next: positive compare index<count with inner test
v2: 17ish words, first diff 12: C7/C8 -> next: result variable preset 1, break form
v3: ~17 words, same shape -> next: C7b two separate ifs
v4: ~15 words, shared epilogue now, regs differ (C11) -> next: Ghidra form bVar1 with result var
v5: ~14 words, regs match, xori extra (C7) -> next: positive test with bool more
v6: ~16 words, blocks swapped vs original -> next: if (!more) first
v7: 6 words, first diff 12 (sched) + tail branch sense (C7) -> next: v8 final: flag test inverted with continue + compute more before entry
v8: 6 words, no gain; budget 8 reached
blocked 0011f078 -> branch-layout
claim 0011f270 token 44c565453b724f1285b140ad3097473c attempts 1 (claims: 6/6, last)
v1: 23 words 148 bytes, first diff 11: C21/C1 -> next: Ghidra && form with shared mask
v2: worse (unrolled differently) -> next: single loop
v3: 104 bytes (too small) -> next: v1 nested form with shared mask variable
v4: ~140 bytes, first diff 3: loop rotation differs -> next: && conditions indexing entries[parent] with mask var
v5: ~ similar, loop shape (C7) -> next: do-while with parent load inside
v6: ~9 words, layout matches, regs t4/t5/t6 differ (C11) -> next: declare mask inside after entry
v7: worse -> next v8 (last): v6 with register bindings t4/t5/t6
v8: 7 words, budget 8 reached
blocked 0011f270 -> register-allocation
