# rec109 progress
start 2026-10-13T05:32:07Z
claim 1 of 6: 001d6e60 token 447a7dc622054e06a204506c5d091e02 attempts 1
v1: 0 words exact
submitted 001d6e60 v1
claim 2 of 6: 001d79b8 token c2cfe347291e47daa06071af1ff0afa0 attempts 1
v1: 18 words, first diff at 1: C8/C11 -> next: separate temp variable for loaded value
v2: 18 words (identical), best v1 18; streak 1
v3: 18 words (identical), best v1 18; streak 2
v4: 14 words, first diff at 1: struct array indexing; best v4 14; streak 0 -> next: pointer walk over struct entries
v5: 18 words; best v4 14; streak 1 -> next: C11d empty asm on entry pointer
v6: compile error (my edit mangled do-line); best v4 14; streak 2
v7: 18 words; best v4 14; streak 3 -> stop
blocked 001d79b8 -> branch-layout
claim 3 of 6: 001d8070 token 5ac4194336c64d7784156b8c71d68c17 attempts 1
v1: 0 words exact
submitted 001d8070 v1
claim 4 of 6: 001d87b8 token 69b6a72968f44e15bc980feaf3a6a280 attempts 1
v1: 27 words, first diff at 0: C12/C2 -> next: early returns, word load then u8 flag
v2: 8 words, first diff at 6: C11 -> next: Ghidra form with result var and operand order; best v2 8 streak 0
v3: 27 words (result var -> s1); best v2 8; streak 1
v4: 8 words (same); best v2 8; streak 2 -> next: ternary result
v5: 27 words; best v2 8; streak 3 -> stop
blocked 001d87b8 -> register-allocation
claim 5 of 6: 001d8f38 token a05af22b35a34ea0967018bd04235f65 attempts 1
v1: 10 words, first diff at 6: C11/C12 (a0 result, sra/andi instead of andi8+sltu); best v1 10 -> next: result var set in nested ifs, u32 temp for bit test
v2: 9 words, first diff at 6: C11 result in a0 not v0; best v2 9 streak 0 -> next: C11c bind result to v2
v3: 12 words (register binding made it worse); best v2 9; streak 1 -> next: u32 result type
v4: 9 words (same); best v2 9; streak 2 -> next: typed struct pointer return
v5: 10 words; best v2 9; streak 3 -> stop
blocked 001d8f38 -> register-allocation
claim 6 of 6: 001d8fa8 token 20ab7ae24ee64a2a9c31ab9179d09787 attempts 1
v1: 7 words, first diff at 17: C7 branch sense -> next: negate select test
v2: see diff (about 7 words); best v1 7 -> next: object pointer computed before vtable load
v3: 4 words, first diff at 20: C11 vtable/method in v0 not t6/t7; best v3 4 streak 0 -> next: per-branch vtable load
v4: 4 words (t6?/t7/v0 mix); best v3 4 streak 1 -> next: C11c bind vtable to t6 method to t7
v5: 0 words exact
submitted 001d8fa8 v5
