# rec39 progress
start 2026-10-12T22:10:11Z
claim 00172a80 token d3012077476b4fa5b1e505e4a0b1dfbb attempts 1
v1: 1 word, first diff at 8: C2/C9 lbu vs lw -> next: u32 temp for flags
submitted 00172a80 v2 (claims so far: 1)
claim 00172fb0 token 19dca4d0c1bd4121bbd2b30bee7e23f8 attempts 1
v1: 11 words, first diff 1: C11/C2 lwu vs lw -> next: s32 a1 param
v2: 7 words, first diff 3: C11 li -1 vs 0xffff -> next: u32 const temp
v3: 6 words, first diff 10: C10 store order -> next: reorder source to 8,1,2,0,4,6
v4: 6 words, identical output -> next: struct local with fields in ghidra order
v5: 7 words, struct worse -> next: volatile stores in order 8,1,2,0,4,6
v6: 15 words, volatile worse
blocked 00172fb0 -> store-order (claims: 2)
claim 00173348 token 89c1fdf7ff264948aba5674c86fe501e attempts 1
submitted 00173348 v1 (claims: 3)
claim 001733f8 token b125256963d043f7abc5526f631fe20e attempts 1
v1: 15 words, first diff 2: C7/C11 -> next: post-decrement on field
v2: 16 words but head matches through bgtz; -> next: struct global, ghidra store order
v3: 9 words, first diff 7: C10 -> next: temps loaded z,x,y then store x,y,z,w
v4: 8 words, first diff 7 -> next: natural order x,y,z,w direct
v5: 10 words -> next: temps x,y,z loaded natural, stores x,y,z,w
v6: 2 words, zero store scheduled early -> next: volatile w store
v7: worse -> next: asm memory barrier before w store on v6
v8: 5 words, budget reached
blocked 001733f8 -> store-order (claims: 4)
claim 00173918 token 42d16dd918944f6da23568f0e1eabce2 attempts 1
submitted 00173918 v1 (claims: 5)
claim 001739b8 token 62b3c6a77e714da290a9498d26c8bbc3 attempts 1
submitted 001739b8 v1 (claims: 6, K reached)
