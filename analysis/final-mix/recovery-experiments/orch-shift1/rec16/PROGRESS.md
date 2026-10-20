# rec16 progress
start 2026-10-12T19:31:01Z
claim 00146730 token 42a95a7b68ed4efa99c6ea51d4b6e4c7 attempts 1
v1: 7 words, first diff at 10: loop of 5 hidden words missing (C21-ish) -> next: add quad zero loop
v2: 11 words: target loop body is 5 nops (0x00000000), bne sp,t7 with addiu t7,-16 in delay -> next: loop with asm nops
v3: 6 words: compare vs sp wanted (bne sp,t7) -> next: cursor+16 != buffer
v4: 6 words(t6 vs t7, extra addiu) -> next: prev-variable form
v5: 5 words(move t7,t6; operand order) -> next: for loop buffer != cursor
v6: 8 words (preheader test beq) -> next: post-decrement do-while
v7: 8 words -> next: for(;;) with break form
v8: exact. submitted 00146730 v8
claim 00146d68 token 85cd062bfd194935a72b56d82ad2d5c7 attempts 1
v1: 29 words; compiler folded dest!=source compare away -> next: launder pointer with asm
v2: 27 words (size matches); loads must batch 4 lq then 4 sq -> next: struct block copy
v3: 27 words identical to v2 -> next: Block as u32[16] aligned(16) struct
v4: 27 words, same (u32 block copy no change) -> next: explicit Quad temporaries load-all-then-store
v5: 27 words, lq order scrambled; 3 versions no improvement -> block
blocked 00146d68 -> register-allocation
claim 00147240 token f96deaa42d604aa0a343a54840882571 attempts 1
v1: 31 words: result saved across call in s0; extra andi 0xff -> next: zero result after call, no bool-to-int wrapping
v2: 17 words: extra andi 0xff -> next: drop != 0 on flag test
v3: 17 words same -> next: nested ifs
v4: 17 words same -> next: flags as s32
v5: 17 words same -> next: ==1 compare
v6: 7 words: s0/s1 swapped (C11) -> next: && chain form with ==1
v7: 7 words same -> next: register binding s1=subject s0=other
v8: exact; making comment-only v9 for review rule
submitted 00147240 v9
claim 00149c08 token 3c88d9067df641ef99371a5b9baa46c2 attempts 1 (4th claim)
submitted 00149c08 v1
claim 00149c40 token 439fc2436b954d8aba47a3735ffc83b0 attempts 1 (5th claim)
submitted 00149c40 v1
claim 0014a470 token 98faa0d953554ea1a165421b2f57ea97 attempts 1 (6th claim, last)
submitted 0014a470 v1
