# rec21 progress
start 2026-10-12T20:11:42Z
claim 00157aa0 token 50ff07c8839847569232f3251a8bda20 attempts 1 (claims 1/6)
v1: 18 words, first diff 0: C8 movn -> next: if/else assigning code
v2: 10 words, first diff 5: C8 still movn, add hoisted -> next: C8(c) volatile / split tail calls
submitted 00157aa0 v3
claim 001585e8 token 51685f3b02d54f2a9adcfb16b8c175fc attempts 1 (claims 2/6)
v1: 2 words, C10 -> next: reorder stores
v2: replace failed, identical to v1 (2 words)
submitted 001585e8 v3
claim 00159130 token d662832ae58c467da0aeb50fb18b6fa0 attempts 1 (claims 3/6)
v1: 25 words, first diff 3: address materialization (addiu then lwc1 0) -> next: declare D_0036b328 as f32 array
v2: same 25 words (array decl no effect) -> next: local pointer to global
v3: same 25 (local pointer) -> next: volatile read
v4: same 25 (volatile) -> next: asm barrier on pointer
submitted 00159130 v5
claim 00159308 token b76995a6b65f4f9e950fd8ac38761d65 attempts 1 (claims 4/6)
v1: 9 words, first diff 9: C11/ordering -> next: load flag first, then pointer, then store
v2: identical 9 words -> next: no barrier
v3: no barrier 15 words (folds, 88 bytes) -> next: asm volatile barrier after store
v4: 9 words (asm volatile) no improvement 3 versions -> block
blocked 00159308 -> address-materialization
claim 00159c20 token eb9dcd029e47424db3e295ffe705b992 attempts 1 (claims 5/6)
v1: 2 words, C5-like constant vs symbol -> next: pass func_00159be0 symbol
submitted 00159c20 v2
claim 00159ef8 token e0672e6685f649e1836791838a9d4797 attempts 1 (claims 6/6)
v1: 19 words, first diff 0: C12/C11 cursor pattern -> next: register cursor t7 and value t0 bindings (queunuprime pattern)
v2: 23 words (96 bytes) but body matches; extra s1 -> next: bind source to s0 with barrier
v3: 5 words, first diff 1: C11 -> next: bind object copy to t7 before computing source
v4: 19 words (bound base moved before call) -> next: unbound temp with barrier, source bound to s0
v5: 5 words no change -> next: asm volatile on source barrier (v3 base)
v6: 21 words, no improvement 3 versions -> block
blocked 00159ef8 -> register-allocation
