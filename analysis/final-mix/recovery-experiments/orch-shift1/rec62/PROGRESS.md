# rec62 progress
start 2026-10-13T00:03:20Z
claim 001973f0 token cfb492c49afd4a43b858ab5da63ba0c0 attempts 1
v1: 14 words, first diff at 1: sll strength reduction -> next: u8 flag var
v2: 14 words, same sll fold -> next: u64 mode with volatile u16 read
v3: 14 words (movz) best v1 14 streak 2 -> next: u64 non-volatile
v4: 14 words (movz, lbu narrowed) streak 3 -> STOP per R7? v4 is last.
blocked 001973f0 -> branch-layout (targets claimed: 1)
claim 00197ac0 token 50b687095478422ea38fd2b9a5006379 attempts 1 (2/6)
v1: 12 words, first diff 0 (lui ordering, arg temp) -> next: callee u64 param
v2: 14 words worse streak 1 -> next: s32 pointer, s64 callee param
v3: 12 words (same as v1) streak 2 -> next: pointer-typed global/ arg
v4: 12 words streak 3 -> stop
blocked 00197ac0 -> register-allocation (2/6)
claim 00197c28 token d51f2375ebd948a49682084f50cfb5c6 attempts 1 (3/6)
v1: 22 words, first diff 1; slti signed + block order -> next: s32 type var
v2: 21 words best v2 -> next: switch
v3: 3 words best v3 -> next: u8 return type
v4: 2 words best v4 streak 0 -> next: pointer-typed object param
v5: exact. submitted 00197c28 v5 (3/6)
claim 00198700 token e9ed7a2499544eeab3307a5f9eb98d9b attempts 1 (4/6)
v1: 11 words first diff 1 (move v0,a0 extra, lbu) -> next: u32 flag via separate next var
submitted 00198700 v2 (4/6)
claim 00198738 token 665d0c58382c4f2c85ca80057dc69136 attempts 1 (5/6)
v1: 23 words first diff 4 (result var, no early return) -> next: C7c early return + ternary
v2: 23 words identical streak 1 -> next: s32 return
v3: 23 words streak 2 -> next: if/else with nested ternary result
v4: 23 words streak 3 -> stop, block
blocked 00198738 -> branch-layout (5/6)
claim 00198aa8 token f6f5606ef3d048ef8e1303feaea88514 attempts 1 (6/6)
v1: ? words, order of mult (C11) -> next: temp total
v2: 1 word (addu operand order) -> next: swap addend order
v3: 1 word same, streak 1 -> next: u8* object param
v4: 1 word same, streak 2 -> next: separate address temp
v5: 8 words streak 3 -> stop, block
blocked 00198aa8 -> register-allocation (6/6)
