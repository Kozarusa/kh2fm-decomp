# rec49 progress
start 2026-10-12T22:58:41Z
claim 00185050 token 5c0c39e4ae48464b88763fd37f3cd83b attempts 1 (claims: 1/6)
v1: 14 words, first diff at 3: hoisted move a1,a0 -> next: C9 volatile load
v2: 14 words unchanged (C9 no effect) -> next: C7c if/else
v3: 14 words unchanged (C7c) -> next: accepted-style (...) declarations, u32 object
v4: 14 words unchanged (accepted-style decls) -> stop (3 no improvement)
blocked 00185050 -> register-allocation
claim 001852b8 token a4d6ce4df3bc49c28ab53a23ff2b8691 attempts 1 (claims: 2/6)
v1(001852b8): 31 words, 128 bytes: object as u64 wrong -> next: u8* object
v2(001852b8): 20 words, first diff 7: addiu+lwc1 0() expected, folded -> next: array decl
v3: array decl no change, 20 words -> next: volatile global reads
v4: volatile no change, 20 words -> next: constant-address pointer reads
v5: 13 words, 116 bytes
v6: asm+ array ptr 12 words -> next: sequence load of first before second pointer
v7: 12 words, loads reordered -> next: asm volatile
v8: asm volatile 12 words -> budget reached
blocked 001852b8 -> address-materialization
claim 00185a28 token 1e101a4029a84f418acd8deefa1ae4e7 attempts 1 (claims: 3/6)
submitted 00185a28 v1
claim 00185a68 token d5b8bc0223854d5c82baf12efe25d688 attempts 1 (claims: 4/6)
submitted 00185a68 v1
claim 00185c48 token 4da8fd70a94d4f41b38cb703c3626738 attempts 1 (claims: 5/6)
submitted 00185c48 v1
claim 00185da8 token 66c2bf3b737547d4a887e299ebc135d8 attempts 1 (claims: 6/6)
v1: 14 words, 60 bytes (returning u8*)
v2: void, 10 words, 52 bytes: extra move v0,a0 and delay slot layout -> next: separate next var
submitted 00185da8 v3
