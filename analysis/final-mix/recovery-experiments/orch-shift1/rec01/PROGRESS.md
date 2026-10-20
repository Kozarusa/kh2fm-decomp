# rec01 progress
start 2026-10-12T16:39:16Z
claim 00105de0 token 0cac063c68584881a1f595f14ed9af3c attempts 1
v1: 8 words, first diff at 12: C11 -> next: swap store order in source
v2: exact
submitted 00105de0 v2
claim 00105fc8 token 39779be3e8194a679694b8ffdc0a9ef9 attempts 1
v1: 7 words, first diff at 1: C11/C10 -> next: store from u32 0xffff variable, order f,a,b,c,d,e
v2: 6 words, first diff at 4: C10 -> next: source order a,b,c,d,e,f
v3: exact
submitted 00105fc8 v3
claim 001064a8 token f24397c0503d433f91306f73b612282b attempts 1
v1: 13 words (compiled 108/120), first diff at 5: C13 -> next: non-tail call; trying callee returning s32 with return value discarded then extra
v2: same 13 (D array form no help) -> next: callee returns f32
v3: same 13 (callee f32 no help) -> next: C9 volatile divisor pointer
v4: same 13 (volatile ptr no help); no improvement for 3 versions -> block
blocked 001064a8 -> address-materialization
claim 00109360 token 8dfe99b3801449529d51f61c22c058c7 attempts 1
v1: exact
submitted 00109360 v1
claim 00109708 token 0e5b0e87309d44b9a62dd9f85c438563 attempts 1
v1: 24 words, first diff at 5: C10 -> next: volatile Quad zero store
v2: 24 words, same (volatile no help; sq scheduled after sd) -> next: C18 union Quad/u64
v3: ? words, first diff at 10, quad part matches: C10 -> next: volatile stores dword[2],[3]
v3: 21 words; v4: 19 words, first diff 8 (D load hoisted): C10c -> next: all four result stores volatile
v5: 19 words (no gain), first diff 9: C11b -> next: single expression for low and high, no temps
v6: 20 words (no gain) -> next: v5 with mask variable declared before the loads
v7: compile error (my stray backtick) -> v8 same change fixed
v8: 19 words (same as v5); budget 8 reached -> block
blocked 00109708 -> store-order
claim 00109cc0 token 911a22175a7d43329f29a8edfb4f5c56 attempts 1
v1: 12 words (68/64), first diff 5: C7a -> next: negate condition, swap bodies
v2: exact
submitted 00109cc0 v2
claim 00109f58 token 1e3df529b04b4650b6b81a7dc317ad0b attempts 1
v1: 7 words (incl 2 reloc words lui/addiu of table), first diff 3: C8 -> next: write condition other way round
v2: 2 words (only table reloc lui/addiu differ; code otherwise exact) -> next: computed goto through extern D_0036a3ac table
v3: exact
submitted 00109f58 v3
claimed 7 targets (miscounted K=6); stopping
