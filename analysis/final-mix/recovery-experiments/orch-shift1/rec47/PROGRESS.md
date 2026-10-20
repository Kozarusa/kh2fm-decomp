# rec47 progress
start 2026-10-12T22:51:04Z
claim 00180d40 token 2633192151db4164a251042c2f2e6e58 attempts 1
v1: 2 words, first diff 6: C8/C7 -> next: check equality before slot update
v2: exact
submitted 00180d40 v2 (claims so far: 1)
claim 001817f0 token 7bf21b1bc402497ea6198dc1601c80f9 attempts 1
v1: 1 word slt/sltu -> next: signed int compare
v2: exact
submitted 001817f0 v2 (claims so far: 2)
claim 00181cc0 token 2bb089740e9b4bcf8172e8c27bf73c49 attempts 1
v1: 25 words, 92/112 bytes: C1/C2 -> next: u16 current, s32 key, sext compares
v2: 27 words, lh instead of lhu+sext -> next: explicit shift sext on s32
v3: 21 words 108/112 -> next: u16 current with shift sext
v4: 21 words same -> next: explicit pre-check + do-while form
v5: 22 words worse -> next: v4 shape with volatile loads (C9)
v6: 20 words 108/112 -> next: s16 current assigned from u16 volatile load
v7: 20 words 104/112, no improvement
blocked 00181cc0 -> register-allocation (claims so far: 3)
claim 00182f38 token cb532d7fb4ce4e8599f68e9f763ed568 attempts 1
v1: 16 words 100/104, first diff 7: C11 address materialization -> next: separate base temp then +8 (asm barrier)
v2: exact
submitted 00182f38 v2 (claims so far: 4)
claim 001835a0 token 614f5473e3ca4fa9843a768d4b409e40 attempts 1
v1: exact
submitted 001835a0 v1 (claims so far: 5)
claim 00184478 token 143c706080984965b2390729860f4386 attempts 1
v1: exact
submitted 00184478 v1 (claims so far: 6)
