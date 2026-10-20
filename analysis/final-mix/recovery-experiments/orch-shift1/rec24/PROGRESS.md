# rec24 progress
start 2026-10-12T20:37:03Z
claim 0015cc80 token 4c4f189a88834bf18580d6778b9e268e attempts 1 (claims: 1/6)
v1: 17 words, first diff at 5: C11/operand order -> next: swap compare operands
v2: 17 words, same: swap no effect -> next: C9 volatile global
v3: 17 words, same: volatile no effect -> next: array decl D_[] compare D_[0]
v4: 17 words, same: array decl no effect -> next: u8[] decl with cast to f32*
v5: 17 words, same: u8[] cast ptr no effect -> next: nested ifs
v6: 17 words, same: nested ifs no effect -> next: volatile pointer deref
v7: 17 words, same: volatile deref no effect -> next: inverted != form
v8: 20 words, worse
blocked 0015cc80 -> register-allocation
blocked 0015cc80 -> register-allocation (done)
claim 0015cff0 token 6e7f729d3419458a8de5077ff2efd323 attempts 1 (claims: 2/6)
v1 (0015cff0): 26 words, 92 vs 104 bytes, C14/C18: pointer folding -> next: struct operator= with this!=&o
v2: 26 words, same -> next: asm lq/sq pattern from accepted 001407d0
v3: exact
submitted 0015cff0 v3
claim 0015de98 token 53fce05972d3466b8172937eaec39e6c attempts 1 (claims: 3/6)
v1 (0015de98): 3 words, first diff at 15: C11 regs -> next: void final call
v2: 3 words same -> next: explicit temporaries / struct vtable
v3: 4 words worse (store order) -> next: v2 with explicit temps
v4: 3 words same -> next: C11c register binding
v5: exact; making v6 with per-line why comments
submitted 0015de98 v6
claim 0015def8 token dc9a86d4c88e4442ac8fed7f38d41842 attempts 1 (claims: 4/6)
v1 (0015def8): 4 words, first diff at 15: C10 store order + C11 t5 -> next: memory barrier after store
v2: 2 words -> next: bind final pointer to t5
v3: 3 words (prologue sd order) -> next: declare t5 binding at top
v4: 3 words same -> next: v3 plus asm +r on flagObject
v5: 5 words worse
blocked 0015def8 -> register-allocation
claim 0015eaf8 token 50a97e6a8ec047cfad5f4c1255b2d180 attempts 1 (claims: 5/6)
submitted 0015eaf8 v1
claim 0015edb8 token c8206ede46b44615931f9130e50086d9 attempts 1 (claims: 6/6)
submitted 0015edb8 v1
