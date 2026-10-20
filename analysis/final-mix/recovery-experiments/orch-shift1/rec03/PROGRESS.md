# rec03 progress
start 2026-10-12T16:50:15Z
claim 0010ab08 token 8a130eb59f8b4d2cb5fdb688dd94847d attempts 1
v1: 24 words, first diff 3: C1 -> next: call directly in each branch (no shared pointer)
v2: 24 words, first diff 3: C1 -> next: switch statement
v3: 0 words exact (switch). submitted 0010ab08 v3
claim 0010ce78 token ac67bec5e24542ff9ff1126bc852e6f9 attempts 1
v1: 22 words, first diff 0: C12 -> next: u8 flag, early return form
v2: 22 words, first diff 5: semantics wrong (a==0 -> 1) -> next: fix logic, u32 flag & 0xff
v3: 30 words, first diff 0: C12 -> next: declare result after the call
v4: 15 words, first diff 11: C7 -> next: if equal result=0 else 1
v5: 15 words same: if/else no change -> next: C8c volatile on object field read
v6: 15 words same -> next: Ghidra-literal && chain with comma assignments
v7: 12 words, first diff 15: C7 -> next: result=1 then zero if equal inside single && guard
v8: 12 words same; budget reached
blocked 0010ce78 -> branch-layout
claim 0010f660 token 9bb519e0c17447a792e436ba43f49e0a attempts 1
v1: 10 words, first diff 6: address materialization -> next: array decl
v2: 10 same; array decl no effect -> next: pointer local
v3: 10 same -> next: volatile pointer
v4: 10 same -> next: absolute-address pointer
v5: 2 words (lui 0x36/ori vs lui 0x37/addiu) -> next: u8 array cast to f32*
v6: 10 same -> next: asm barrier on pointer
v7: exact; submitted 0010f660 v7
claim 0010f6b8 token 9e931111b01b495784c010b2e5d5e82c attempts 1
v1: 7 words first diff 1: C8/C7 -> next: Ghidra-form <= condition
v2: 7 same -> next: separate temps / result separate (C8a)
v3: 7 same -> next: early return form
v4: 7 words (52 bytes) -> next: C8c volatile data reads in v2 shape
v5: 12 words worse -> next: bool return with && expression
v6: 7 same; no improvement for 3 versions
blocked 0010f6b8 -> branch-layout
claim 0010f960 token 82448b0ade654dc59d126ab3caa9993e attempts 1
v1: exact; submitted 0010f960 v1
claim 0010f9f0 token c6d91bad7ac84221b3d206068d876e04 attempts 1
v1: 2 words, first diff 3: C11/C14 -> next: temp Quad
v2: 2 same -> next: asm barrier on destination ptr
v3: 4 words regs t6/t7 -> next: C11c bind dest to \ and value to \
v4: exact; submitted 0010f9f0 v4
claim 00112388 token 2aa5d0bc7bd9488e925cae5a7251a4b3 attempts 1
v1: 18 words first diff 7: C5/address materialization -> next: asm barrier on table base
v2: exact; submitted 00112388 v2
