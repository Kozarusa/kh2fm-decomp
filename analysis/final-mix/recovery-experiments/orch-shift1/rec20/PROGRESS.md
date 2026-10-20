# rec20 progress
start 2026-10-12T20:01:36Z
claim 00154288 token 4d712f56cbe9455d9076e424d64504cd attempts 1
v1: 11 words, first diff at 0: C11/C7 -> next: rewrite with direct returns
v2: 12 words, movn: C8 -> next: switch form
v3: 0 words exact (switch). submitted 00154288 v3
claim 001542c8 token 4a32b68f993a4b5b9e4fc70c19d92af5 attempts 1 (2 of 6)
v1: exact. submitted 001542c8 v1
claim 00154b98 token b7737b0e90194cd8a1544ed052abbb2d attempts 1 (3 of 6)
v1: 14 words, first diff 1: C10/C11 -> next: store order 3ccc before 3cc8 (Ghidra order)
v1 note: source order already matched original (3cc0,3ccc,3cc8); compiler reordered. next: item declared inside if
v2: 17 words worse (item inside if). next: reuse object as cursor like Ghidra (C11b)
v3: 24 words worse. next: v1 with division after stores (C10a)
v4: 14 words (addiu s1 hoisted, t4/t5 swapped). next: declare item early, assign inside if
v5: 8 words (s0/s1 swapped). next: separate loop counter copy inside if (C12b/C11b)
v6: 17 words worse (best remains v5, 8). next: v5 with object reused as cursor inside if
v7: 2 words (mflo/addiu order in blez delay slot). next: swap loop update statement order
v8: 2 words, no change. budget reached (8)
blocked 00154b98 -> branch-layout
claim 00154ee8 token 2e778b0f4b9d40ac85a82d19bc85b9b5 attempts 1 (4 of 6)
v1: 8 words, C7 -> next: Ghidra-literal ifs with early returns
v2: 14 words (collapsed). next: switch with return in case 0 and 2
v3: 8 words same as v1. next: switch with every case assigning result, no initializer
v4: 8 words same. next: switch with return in every case
v5: 8 words same. no improvement 3 versions -> block
blocked 00154ee8 -> branch-layout
claim 00155f40 token aa9dbd6941ac48adb75f06a9bba20129 attempts 1 (5 of 6)
v1: 30 words (no jump table, s0 saved): C1/C12 -> next: explicit case 0/1 + result set after the call
v2: 20 words (jump table ok now; movz instead of branch): C8 -> next: callee returns s64 (C20/Ghidra long)
v3: 20 words same. next: Ghidra literal order, init 0x17, default first with case 0/1 labels, s64 call result then assign
v4: 19 words, registers now match, block order differs (original: case4, epilogue, default, case2, case3). next: source order case4 first
v5: 2 words (only jump table lui/addiu address; compiler emits own table). next: computed goto through extern D_0036b2d8 (C5 / address materialization)
v6: 24 words worse. stopping: best v5 (2 words, jump-table address only)
blocked 00155f40 -> address-materialization
claim 00157990 token 72d45b55114b4a6b8ce215c38abd0c85 attempts 1 (6 of 6)
v1: 11 words, movn vs beqzl: C8 -> next: read +0x34 chain first, then current (load order), plus stores unchanged
v2: 21 words (movn persists). next: C8b flip the comparison
v3: 21 words same. next: store current then conditionally overwrite with target
v4: 9 words (store-then-overwrite helped; still a0 vs s0 and beqz vs beqzl). next: if/else with volatile store at +0x24 (C8c)
v5: 21 words (volatile no help). best v4 (9). next: split pointer: object for loads+0x24 stores, copy self for 0x28 store and calls (C11b)
v6: 9 same. next: empty asm on self copy (C11d)
v7: 27 words worse. 3 versions no improvement -> block
blocked 00157990 -> branch-layout
