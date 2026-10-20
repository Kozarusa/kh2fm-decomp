# rec04 progress
start 2026-10-12T16:58:17Z
claim 001124f8 token 55016e46fb3141dcbc82c8eca074f74b attempts 1 (claim 1/6)
v1: 20 words, first diff at 8: C7 -> next: result=2 default then if(..) result=1
v2: 20 words same: C7(a) -> next: comma form
v3: 20 words same: comma form -> next: ternary direct
v4: 20 words same: ternary -> next: switch (C7)
v5: 20 words same: switch -> next: C11 bind result to \
v6: 20 words same: C11 bind -> stop (no improvement 3 versions)
blocked 001124f8 -> branch-layout
claim 001129d8 token cd1016b0d2c94facb4cd7d38cb548c62 attempts 1 (claim 2/6)
submitted 001129d8 v1
claim 00112d28 token d6ee86196ea540b08e41e848d1e4ee18 attempts 1 (claim 3/6)
v1: 29 words, first diff 0: C12/bool -> next: bool types
v2: 29 words same: bool -> next: C7 single && expression
v3: 28 words, one && expr: result in s1 -> next: C7(c) early returns
v4: 12 words, last expr sra/xori instead of andi/sltiu -> next: s32 return type with early returns
v5: 12 words same -> next: ternary/! on last
v6 exact; submitted 00112d28 v6
claim 001144e8 token 458fadf8564944839f7d250cc8adb61a attempts 1 (claim 4/6)
v1: 25 words, first diff 1: C18/C20 key as u64 -> next: key struct by value
v2: 24 words: loads ok, v0/t7 loop var differs -> next: C11(b) separate cursor
v3: 25 words worse -> next: v2 + result=0 declared at top (C11b)
v4: 24 words same -> next: array-indexed loop over base
v5: 25 words -> stop (3 versions no improvement)
blocked 001144e8 -> abi-layout
claim 001168c0 token 518f951677d4490cad447030cdf37a00 attempts 1 (claim 5/6)
v1: 29 words, structure matches, original keeps zero in s1 -> next: C11 register zero asm
submitted 001168c0 v3
claim 00119f48 token 23c9c75c2fbc4cebb66e2e2f41f29969 attempts 1 (claim 6/6, LAST)
v1: 24 words, first diff 4: C20 u64 param (move s0,a0 then andi) -> next: u64 flags
v2: 24 words same -> next: mask after call, no temp
v3: 15 words, first diff 7: C5/addr materialization -> next: global via f32* pointer local
v4: 15 same -> next: volatile f32* read
v5: 15 same -> next: pointer computed before first call (hoist addr)
v6: 15 same -> stop (3 versions no improvement)
blocked 00119f48 -> address-materialization; K=6 reached
