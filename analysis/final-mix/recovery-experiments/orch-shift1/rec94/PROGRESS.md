# rec94 progress
start 2026-10-13T04:09:02Z
claim 1 of 6: 001bcf38 token eb5467dbae6c484eacce9a3df7b642f6 attempts 1
v1: 14 words, first diff at 2: C7 -> next: early returns
v2: 16 words (best v1 14), first diff 1: C7c worse, streak 1 -> next: mix
v3: 15 words; best v1 14; streak 2 -> next: switch
submitted 001bcf38 v4
claim 2 of 6: 001bd8c8 token eeeaefea01a845e9927759b213f2bc71 attempts 1
v1: 13 words, first diff 1: tail call j instead of jal (C13 rev) -> next: barrier after call
v2: 8 words best v2; first diff 1: prologue order/addu -> next: swap addu operands
v3: 8 words, same; best v2 8; streak 1 -> next: sibling varargs decls
v4: 8 words same; streak 2 -> next: object as u32 value, barrier between calls variation
v5: 8 words; best v2 8; streak 3 -> stop
blocked 001bd8c8 -> prologue-epilogue
claim 3 of 6: 001be4e0 token 60f4c463321f4ede8954d17b7337716e attempts 1
v1: 23 words best v1, first diff 1: C10/C11 -> next: reorder store after table load
v2: 23 words; streak 1 -> next: compute entry first
v3: 9 words best v3; first diff 1: C11/C10 -> next: entry expr order
v4: 9 words, no change; streak 1 -> next: field load before entry
v5: 9 words; best v3 9; streak 2 -> next: struct array
v6: 9 words; best v3 9; streak 3 -> stop
blocked 001be4e0 -> register-allocation
claim 4 of 6: 001befd8 token 215247155b3b4a069e9f613b5008df34 attempts 1
submitted 001befd8 v1
claim 5 of 6: 001bf6a8 token fcb19320bcba4c9895d359d3a0e90a02 attempts 1
submitted 001bf6a8 v1
claim 6 of 6: 001bfd60 token ccac3d70a54a4304939b33089b7b697e attempts 1
v1: 13 words best v1; first diff 0: C6/C8 -> next: xor form with local value
v2: 13 words, no change; streak 1 -> next: separate temp ternary
v3: 13 words; streak 2 -> next: xori asm primitive
v4: 7 words best v4; first diff 3 -> next: early-clobber output
v5: 4 words best v5; streak 0 -> next: asm volatile
v6: 10 words; best v5 4; streak 1 -> next: bind loop flag to t7
v7: 10 words; best v5 4; streak 2 -> next: separate found temp from v5
v8: 4 words; best v5 4; streak 3 -> stop
blocked 001bfd60 -> register-allocation
