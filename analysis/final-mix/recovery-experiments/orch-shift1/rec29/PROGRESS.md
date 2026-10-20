# rec29 progress
start 2026-10-12T21:21:41Z
claim 00166808 token 5136f3ca2ae047bf80c4dd2b652c1c26 attempts 1 (claims: 1/6)
v1: 7 words, first diff at 14: C11/C10 -> next: reorder stores
v2: 10 words (store reorder worse) -> next: C10c volatile stores
v3: 7 words, first diff 21 (regs ok, epilogue interleaved) -> next: barrier at end
v4: 2 words (ld s0/s1 order swapped) -> next: plain stores with barriers between
v5: 12 words worse -> next: v4 with plain byte store
v6: 4 words worse -> next: v4 with barrier after first store only
v7: 7 words, 3 versions without beating best v4 (2)
blocked 00166808 -> prologue-epilogue
claim 00166968 token b68c78545b2f46e7aceebf6fe7438ba7 attempts 1 (claims: 2/6)
v1 00166968: exact (u32 callee decl); trying void decl as v2 to match accepted declaration
submitted 00166968 v2
claim 001676b0 token e62d7628a2f64a45a088c68f8f3950af attempts 1 (claims: 3/6)
v1 001676b0: 8 words, first diff 6: C11 -> next: compute released before pressed
v2: compile error (bad newline escape in my edit) -> v3 same change
v3: 8 words, first diff 5 -> next: v1 with pressed bound to t5 (C11c)
v4: 8 words, binding ignored -> next: load float first then store object[3] (C9/C10 style)
v5: 15 words worse -> next: v1 + asm +r on changed (C11d)
v6: 8 words no change -> next: ~buttons mask temp, and-order swap
v7: 8 words; no improvement over v1 (8) in 6 versions
blocked 001676b0 -> register-allocation
claim 00167c30 token 03b711c6caec44cc9456bbe5fd731bbc attempts 1 (claims: 4/6)
v1 00167c30: 24 words, loop unrolled (72 vs 96 bytes): C1 -> next: asm nop nop in loop body
v2: 20 words, 92/96, first diff 4: address folding D+68 -> next: struct array indexed loop
v3: 19 words, +68 folded into store offset, slot/source regs swapped -> next: pointer-to-member loop
v4: 18 words, regs right, only missing separate addiu 68 -> next: opaque base via asm +r
v5: 5 words, first diff 2 (scheduling of lui/addiu) -> next: declare source before base
v6: 5 words same -> next: asm +r on source too
v7: 5 words same -> v8: asm +r on index
v8: 5 words same. budget reached
blocked 00167c30 -> address-materialization
claim 00168008 token bdff01abbe9d48e5b24f87cc893b9163 attempts 1 (claims: 5/6)
submitted 00168008 v1
claim 001682b8 token 0eb59b7f342147ffae35ddebbbbbf089 attempts 1 (claims: 6/6)
v1 001682b8: 11 words, 48/52: sd s0 filled the jal delay slot, original has nop -> next: memory barrier before call
v2: 2 words, ra/s0 save order swapped -> next: bind result to s0
v3: 2 words same -> next: plain asm volatile with no clobber
v4: 2 words same -> next: barrier after the call instead of before (C10d placement)
v5: 2 words same -> next: barrier clobbering s0
v6: 6 words worse -> v7: u64 types with barrier
v7: 2 words; no improvement over v2 for 5 versions
blocked 001682b8 -> prologue-epilogue
