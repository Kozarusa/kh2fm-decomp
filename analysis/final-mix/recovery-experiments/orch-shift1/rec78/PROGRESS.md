# rec78 progress
start 2026-10-13T02:19:43Z
claim 1 of 6: 001aa8a8 token 3048e5f60b344181a2c61493f9a55e08 attempts 1
v1: 14 words, first diff at 1: C13 -> next: callee returns s32, function void (no sibcall)
v2: 14 words, first diff at 1: C13 still sibcall -> next: variadic u64 callee decl, u64 params as in accepted siblings
v3: 16 words (60 bytes) streak1: variadic worse -> next: v1 form + empty asm memory barrier after call to block sibcall
v4: 9 words, best v4 9; first diff at 1: C11 -> next: temporaries in order ptr, f13, f12, first
v5: 16 words; best v4 9; streak 1 -> next: v4 with u64 params/callee args
v6: 9 words; best v4 9; streak 2 -> next: temporaries only for pointer and second float
v7: 10 words; best v4 9; streak 3 -> stop, block
blocked 001aa8a8 -> register-allocation
claim 2 of 6: 001aa8f0 token f175b8a6dce54788ab6685582b7e5501 attempts 1
v1: 17 words, first diff at 1: C11 -> next: u64 params (as 001aa8a8 v6)
v2: 17 words; best v1 17; streak 1 -> next: move barrier before call? no; try 'first' local loaded; use register copy
v3: 12 words; best v3 12; streak 0 -> next: C11(c) bind a,b,c to t6,t5,t4
v4: 12 words; best v3 12; streak 1 -> next: C11(d) asm +r after bindings
v5: 8 words; best v5 8; streak 0 -> next: bind object to t7 and d to t1 in original order
v6: 17 words; best v5 8; streak 1 -> next: v5 plus copy_d bound only (t1) after copy_c
v7: 10 words; best v5 8; streak 2 -> next: v5 with pointer local first
v8: 8 words; best v5 8 (v8 ties); budget reached -> block
blocked 001aa8f0 -> register-allocation
claim 3 of 6: 001aadb0 token 1efdb47eeee646b3a1bf48fa616e2da8 attempts 1
v1: 11 words (44 bytes), first diff at 2: C5/R4.4 constant is a global address -> next: D_01c6cd20 array
v2: 0 words exact
submitted 001aadb0 v2
claim 4 of 6: 001aae28 token c7a9b3e977e343668abd7e3569af0a61 attempts 1
v1: 18 words, first diff at 0: C3 -> next: u32 byte params
v2: 11 words (60 bytes); best v2 11; streak 0; first diff 0: C10 -> next: volatile stores
v3: 2 words; best v3 2; streak 0; first diff 0: load vs first store order -> next: local = j before first store
v4: 2 words; best v3 2; streak 1 -> next: volatile read of j
v5: 0 words exact
submitted 001aae28 v5
claim 5 of 6: 001aaf98 token c16a998d40174d13a36da5d447ce3d6b attempts 1
v1: 15 words (68 bytes), first diff at 2: C7 -> next: result variable with || chain
v2: 0 words exact
submitted 001aaf98 v2
claim 6 of 6: 001abba8 token c9f99b5f1c2e40f29fd195fc9d42aae6 attempts 1
v1: 3 words, first diff at 10: C10 -> next: load both values before stores
v2: 4 words; best v1 3; streak 1 -> next: v1 with volatile reads
v3: 3 words; best v1 3; streak 2 -> next: volatile local for second read before first store
v4: 4 words; best v1 3; streak 3 -> stop, block
blocked 001abba8 -> store-order
