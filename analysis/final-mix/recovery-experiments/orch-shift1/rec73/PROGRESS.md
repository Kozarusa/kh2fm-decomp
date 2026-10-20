# rec73 progress
start 2026-10-13T01:08:04Z
claim 1 of 6: 001a4060 token d4bac3587849482e89e3196d4ca3c396 attempts 1
v1: 14 words, first diff at 9: C21/C7 loop shape -> next: ghidra-style loop (v2)
v2: 5 words, first diff at 11: C11 regs swapped + xor -> next: previous temp (v3)
v3: 5 words (best v2 5, streak 1): C11 -> next: end declared first (v4)
v4: 5 words (best v2 5, streak 2): -> next: register bind (v5)
v5: 2 words (best v5 2, streak 0): -> next: bool form with bindings (v6)
v6: 4 words (best v5 2, streak 1): -> next: only cursor bound (v7)
v7: 3 words (best v5 2, streak 2): -> next: if-break loop (v8)
v8: 0 words EXACT; v9 adds why comments only
submitted 001a4060 v9
claim 2 of 6: 001a4498 token 628cca8147ca4ea297cf375ce54f0662 attempts 1
v1 written
v1: 19 words, first diff 9: C4 float stores -> v2 f32 value
v2: 10 words (best v2): C9 -> v3 volatile read
v3: 10 words (best v2, streak 1): -> v4 volatile zero stores
v4: 8 words (best v4, streak 0): -> v5 volatile store 0x33
v5: 10 words (best v4 8, streak 1): -> v6 v4 with vector stores in index order (C10a)
v6: 5 words (best v6 5, streak 0): -> v7 volatile 0x33 store
v7: 7 words (best v6 5, streak 1): -> v8 volatile vtable store
v8: 8 words (best v6 5): budget reached
blocked 001a4498 -> store-order
claim 3 of 6: 001a49a0 token fad4c70f67604c04bd6a0c2be85bf4f9 attempts 1
v1 written
v1: 14 words; first diff 0: C11 -> v2 separate dest variables
v2: 13 words (best v2 13): -> v3 asm pointer barrier (C11d)
v3: 9 words (best v3 9): -> v4 bind destination t7
v4: 14 words (best v3 9, streak 1): -> v5 v3 with temps
v5: 9 words (best v3 9, streak 2): -> v6 bind temp t0
submitted 001a49a0 v6
claim 4 of 6: 001a5880 token 64c9cfdbc6224af7b3090496de450afd attempts 1
v1 written
v1: 15 words, first diff 1: C11 -> v2 u64 value
v2: 15 words (best v1 15, streak 1): -> v3 separate counter
v3: 3 words (best v3 3): -> v4 offset/table temps before counter
v4: 13 words (best v3 3, streak 1): -> v5 counter declared before if
v5: 15 words (best v3 3, streak 2): -> v6 offset before counter
v6: 2 words (best v6 2): -> v7 table temp first
v7: 13 words (best v6 2, streak 1): -> v8 asm barrier on counter
v8: 3 words (best v6 2): budget reached
blocked 001a5880 -> register-allocation
claim 5 of 6: 001a5928 token b7eab8931a0343368500a3411b85fef0 attempts 1
v1 written
v1: 16 words, first diff 2 (missing nop/ sd order): -> v2 void first callee
v2: 16 words (no change) -> v3 asm memory barrier before first call
v3: 2 words (best v3 2): C10 prologue order -> v4 plain asm volatile
v4: 2 words (best v3 2, streak 1): -> v5 barrier after first call
v5: 2 words (streak 2): -> v6 barriers before and after first call
v6: 2 words (best v3 2, streak 3): stop
blocked 001a5928 -> prologue-epilogue
claim 6 of 6: 001a5a48 token e5be29fef5684df2a17f45a9e17b8468 attempts 1
v1 written
v1: 19 words, first diff 12: C7 layout + andi 0xff -> v2 while-assign form, u32 flag test
v2: 11 words (best v2 11): C11/C3 -> v3 separate cursor + flags local
v3: 17 words (best v2 11, streak 1): -> v4 comma-while with cursor, s32 flags
v4: 8 words (best v4 8): C3 andi -> v5 bit local
v5: 2 words (best v5 2): load order -> v6 value local first
submitted 001a5a48 v6
