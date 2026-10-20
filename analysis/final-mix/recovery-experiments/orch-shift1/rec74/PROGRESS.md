# rec74 progress
start 2026-10-13T01:35:17Z
claim 1 of 6: 001a60c8 token 8016ebc6810d4269a2f53cc633b55652 attempts 1
v1: 18 words, first diff 1: C5-like address materialization -> next: use extern u8 D_00350800[] base + 40
v2: 17 words, first diff 3; streak 1 -> next: struct array of 44-byte entries (C21-ish rewrite)
submitted 001a60c8 v3
claim 2 of 6: 001a6440 token f0344742f3794a5f863dc8ba4e1cd7cf attempts 1
v1 (001a6440): 16 words, first diff 3: C11 -> next: separate local for inner pointer
v2 (001a6440): 16 words; streak 1 -> next: pass inner as arg to func_00177998 (this pointer in a0)
submitted 001a6440 v3
claim 3 of 6: 001a67e0 token 61af76a8b3d94be6ae2fa21cd73c6ed0 attempts 1
v1 (001a67e0): 16 words, first diff 3, 112/108 bytes: C13/C7 -> next: loop as while(cur && (prev=cur, cur!=node)), keep tail call question
v2 (001a67e0): 16 words, same output; streak 1 -> next: block sibcall with empty asm memory barrier after free
v3 (001a67e0): 16 words, 100/108 bytes; best v3 (tail call fixed); streak 0 -> next: C7 nested if loop shape
v4 (001a67e0): 16 words, same 100 bytes; streak 1 -> next: inline helper for next-node with while loop
v5 (001a67e0): 15 words, 100/108; best v5; streak 0 -> next: do-while with inline step
v6 (001a67e0): 15 words; streak 1 -> next: for(;;) with two breaks and inline step
v7 (001a67e0): 15 words; streak 2 -> next: helper step + nested-if continue form (last)
v8 (001a67e0): 15 words; budget reached
blocked 001a67e0 -> branch-layout
claim 4 of 6: 001a6ae8 token 879b08923c3e4170993453cc8685bfc4 attempts 1
submitted 001a6ae8 v1
claim 5 of 6: 001a6b58 token cc0a8e3fd3434e08b5b897927970a776 attempts 1
v1 (001a6b58): 11 words, first diff 7: C10 -> next: reorder source statements (b, a, c order of loads)
v2 (001a6b58): 15 words; best v1 11; streak 1 -> next: temp for flags_b loaded first, stores c,a,state,b
v3 (001a6b58): 11 words; streak 2 -> next (last): C10d memory barrier between state store and flags_b
v4 (001a6b58): 17 words; best v1 11; streak 3 -> stop
blocked 001a6b58 -> store-order
claim 6 of 6: 001a6bc8 token 6bb7bf440816474ab37cd40bedc351a3 attempts 1
v1 (001a6bc8): 9 words, first diff 7: C10/C11 -> next: split mask and or of flags_b
v2 (001a6bc8): 9 words; best v1; streak 1 -> next: volatile state member (C10c)
v3 (001a6bc8): 9 words; streak 2 -> next (last): load order a,c,b declaration with b mask via later statement
v4 (001a6bc8): 11 words; best v1 9; streak 3 -> stop
blocked 001a6bc8 -> register-allocation
