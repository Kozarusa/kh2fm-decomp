# rec103 progress
start 2026-10-13T04:57:15Z
claim 1 of 6: 001cfac0 token 53370e1ff3294bdd999e6595f26b285e attempts 1
v1: 11 words, first diff 1: addiu folded into lwc1 -> next: volatile read
v2: 11 words, first diff 1: C9 volatile no change; best v1 11; streak 1 -> next: array decl
v3: array, 11 words presumably same; streak 2 -> next: asm empty pointer binding (accepted precedent 0010f660)
v4: 4 words, first diff 5: C10 mul/store order; best v4 4; streak 0 -> next: temps b,c,d computed first (Ghidra order)
v5: exact; submitted 001cfac0 v5
claim 2 of 6: 001d14e0 token 728ee452695d421bbf3660b10f0f6f27 attempts 1
v1 (001d14e0): 10 words, first diff 8: C11/scheduling; best v1 10 streak 0 -> next: ptr loaded to temp before stores
v2: exact; submitted 001d14e0 v2
claim 3 of 6: 001d1540 token cecd513570c748f89874c135b2008db1 attempts 1
v1: exact; submitted 001d1540 v1
claim 4 of 6: 001d1f38 token 261ddd0e8d3a440483d99fda01aa3e71 attempts 1
v1: exact; submitted 001d1f38 v1
claim 5 of 6: 001d1fa8 token 1913c6eea36340f284a5f288fe6d6210 attempts 1
v1 (001d1fa8): 4 words, first diff 2: scheduling of sd s0/move s0; best v1 4 streak 0 -> next: separate self variable (C11b)
v2: 4 words same; best v1 4 streak 1 -> next: empty asm on self (C11d)
v3: 25 words; best v1 4 streak 2 -> next: vtable pointer temp declared before first store
v4: 4 words; best v1 4 streak 3 -> stop
blocked 001d1fa8 -> prologue-epilogue
claim 6 of 6: 001d21c0 token 4b200f1c4f7c4d7ba12a1d88904a15d7 attempts 1
v1 (001d21c0): 7 words, first diff 0: C11 sub result reg -> next: separate variable for new value
v2: 4 words, first diff 0 prologue scheduling; best v2 4 streak 0 -> next: C7b combined || condition
v3: 21 words; best v2 4 streak 1 -> next: C9 volatile load
v4: 4 words; best v2 4 streak 2 -> next: C7c early returns
v5: 19 words; best v2 4 streak 3 -> stop
blocked 001d21c0 -> prologue-epilogue
