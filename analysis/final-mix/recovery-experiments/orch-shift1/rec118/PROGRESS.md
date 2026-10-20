# rec118 progress
start 2026-10-13T06:40:16Z
claim 1 of 6: 001ded98 token bc4338211e4241fea57d2e7700d8ac80 attempts 1
v1: compile error (scope of more) -> declare outside loop
v2: 26 words, first diff at 4: C13 tail call j instead of jal -> next: empty asm memory barrier after calls (accepted-source pattern)
v3: 24 words, first diff at 4: C7 block order -> next: bit4 block first
v4: 5 words, first diff at 10: C11 regs (t6/t7 swap, xor) -> next: explicit fixed compare temp
v5: 7 words; best v4 5; streak 1 -> next: from v4, no bool temp, condition on end+0x10
v6: 21 words; best v4 5; streak 2 -> next: from v4, pre-decrement copy compare
v7: 5 words; best v4 5; streak 3 -> stop, block
blocked 001ded98 -> register-allocation
claim 2 of 6: 001dee10 token 28f95f94d4a540baa8ad84bcc82b155f attempts 1
001dee10 v1: 7 words, first diff at 8: C11 register binding hoisted extra temps -> next: post-decrement struct pointer loop
001dee10 v2: 7 words; best v1 7; streak 1 -> next: pass pointer to func_001e0158 so a0 stays live (C1a arg check)
001dee10 v3: 5 words; best v3 5; streak 0 -> next: v2 struct-pointer loop plus pointer arg
001dee10 v4: 7 words; best v3 5; streak 1 -> next: v3 with prev-copy compare
001dee10 v5: 5 words; best v3 5; streak 2 -> next: v3 with register bindings t7/t6
001dee10 v6: 7 words; best v3 5; streak 3 -> stop, block
blocked 001dee10 -> register-allocation
claim 3 of 6: 001dffd8 token a88e43481ace4002ae0171c4dd99cf07 attempts 1
001dffd8 v1: 26 words, first diff at 3: lwu vs lw (C2) -> next: s32 arg for callee
001dffd8 v2: 26 words, first diff at 3: C12/C7 result merged with flag -> next: separate result and flag variables
001dffd8 v3: exact
submitted 001dffd8 v3
claim 4 of 6: 001e0058 token b0ab935e90804f0ca9c64f178bd826ce attempts 1
001e0058 v1: exact
submitted 001e0058 v1
claim 5 of 6: 001e01e8 token c7e0cd2db9f44ae78b17dff3fb9f6e04 attempts 1
001e01e8 v1: 4 words, first diff at 12: C11 -> next: separate next temp
001e01e8 v2: exact
submitted 001e01e8 v2
claim 6 of 6: 001e0230 token 38d0db667b5143c5ad3e1567ca0a6067 attempts 1
001e0230 v1: 18 words, first diff at 10: C7/C11 -> next: invert exit test, call in taken branch
001e0230 v2: 16 words; best v2 16; streak 0 -> next: if/else for next selection (C7)
001e0230 v3: 16 words; best v2 16; streak 1 -> next: volatile D read (C9)
001e0230 v4: 19 words; best v2 16; streak 2 -> next: ternary in while condition
001e0230 v5: 3 words; best v5 3; streak 0 -> next: ternary sense swapped
001e0230 v6: 3 words; best v5 3; streak 1 -> next: v5 with volatile D
001e0230 v7: 5 words; best v5 3; streak 2 -> next: v5 with volatile node load
001e0230 v8: 3 words; best v5 3; streak 3, budget 8 -> block
blocked 001e0230 -> branch-layout
