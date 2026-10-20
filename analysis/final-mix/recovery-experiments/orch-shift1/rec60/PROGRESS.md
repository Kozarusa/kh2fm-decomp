# rec60 progress
start 2026-10-12T23:54:20Z
claim 00196198 token 19a1f011786541669f6e8c972696410f attempts 1 (claims: 1/6)
v1: exact
submitted 00196198 v1
claim 00196328 token ef74f8a0d98e4c6a92fef943f3d6551d attempts 1 (claims: 2/6)
v1 00196328: 24 words, first diff 0: C11/C21 -> next: u16 fill variable
v2 00196328: 11 words, first diff 1: addr order -> next: index + u32 D
v3 00196328: 7 words, first diff 1: C11 half ptr/lui order -> next: move half decl later
v4 00196328: 7 words (no gain) -> next: C11c bind half to 12
v5 00196328: 20 words (C11c worse) -> next: tail u8* decl first
v6: 7 words
blocked 00196328 -> register-allocation
claim 001966b0 token b9e478ab71294143b6c387601f7107b3 attempts 1 (claims: 3/6)
v1 001966b0: 8 words, first diff 1: const offset folded into symbol (C5/C11) -> next: slot[0x1ef8/2] pointer form
v2 001966b0: 7 words, regs t4/t5 swapped + addu order + arg load order -> next: u32 table add form
v3: exact
submitted 001966b0 v3
claim 00196888 token 31d658e8bfe9482188c96e352d7f95fc attempts 1 (claims: 4/6)
v1: exact
submitted 00196888 v1
claim 00196a40 token 1c9b956b31b34bd795956132de404419 attempts 1 (claims: 5/6)
v1 00196a40: 20 words, first diff 2: base+4 not separate, dsll32 on callback arg -> next: u32 params in callee decl
v2 00196a40: 20 words (shift by 1 insn; only missing separate addiu +4) -> next: entry++ separate statement
v3: exact
submitted 00196a40 v3
claim 00196e98 token acea4b4b409c4a1e881c74505fc2863e attempts 1 (claims: 6/6)
v1 00196e98: 27 words, first diff 1: C8 movn + extra s reg -> next: C8b reverse condition
v2 00196e98: 27 words (movz now) -> next: ternary in call args
v3 00196e98: 20 words, best (movn, obj+64 hoisted) -> next: separate temp + if/else
v4 00196e98: 17 words, best (regs match, movn vs branch) -> next: C8b condition other way
v5 00196e98: 17 words (no gain) -> next: s32 callee return
v6 00196e98: 17 words (no gain) -> next: s64 callee return (C20)
v7: 17 words
blocked 00196e98 -> branch-layout
