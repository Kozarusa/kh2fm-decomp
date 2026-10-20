# rec112 progress
start 2026-10-13T05:56:06Z
claim 1 of 6: 001db198 token 300e7284c386470480e803517f2a5839 attempts 1
v1: 26 words, first diff at 1: C4/C1 -> next: s64 return, early returns
001db198 v1: 26 words; best v1 26 words; streak 0
v2: 21 words, first diff at 1: C7c -> next: early returns
001db198 v2: 21 words; best v2 21 words; streak 0
v3: 21 words, first diff at 0: C12 -> next: nested with result inside
001db198 v3: 21 words; best v2 21 words; streak 1
v4: 21 words, first diff at 0: C12 -> next: separate inner var
001db198 v4: 21 words; best v2 21 words; streak 2
v5: 21 words, first diff at 0: C12
001db198 v5: 21 words; best v2 21 words; streak 3 -> stop
blocked 001db198 -> prologue-epilogue
claim 2 of 6: 001db250 token 0932c724ca1d4c6aa0aae4abc6e13f86 attempts 1
v1: 16 words, first diff at 1: C9 -> next: volatile global read
001db250 v1: 16 words; best v1 16 words; streak 0
v2: 16 words same: C9 no effect -> next: temporary for field
001db250 v2: 16 words; best v1 16 words; streak 1
v3: 16 words same: temporaries no effect -> next: array-typed global
001db250 v3: 16 words; best v1 16 words; streak 2
v4: 16 words same
001db250 v4: 16 words; best v1 16 words; streak 3 -> stop
blocked 001db250 -> store-order
claim 3 of 6: 001db5a8 token ed5c244d159d4ebfb2422817ba921738 attempts 1
v1: 18 words, first diff at 4: C13 -> next: asm barrier after call to block tail call
001db5a8 v1: 18 words; best v1 18 words; streak 0
v1: 18 words; v2 exact
submitted 001db5a8 v2
claim 4 of 6: 001db7d0 token a03a9c51b42e4572a39a15ac78ade1a6 attempts 1
v1: 13 words, first diff at 1: C11/C9 -> next: real virtual call
001db7d0 v1: 13 words; best v1 13 words; streak 0
v2: 9 words, first diff at 1: C11 -> next: temporaries for inner and value
001db7d0 v2: 9 words; best v2 9 words; streak 0
v3: 13 words, worse
001db7d0 v3: 13 words; best v2 9 words; streak 1
v4: 9 words same as v2
001db7d0 v4: 9 words; best v2 9 words; streak 2
v5: 13 words
001db7d0 v5: 13 words; best v2 9 words; streak 3 -> stop
blocked 001db7d0 -> register-allocation
claim 5 of 6: 001db808 token 2f18e1c3b5134a11bd070a344e671c5f attempts 1
v1: 13 words, first diff at 5: C11 -> next: bind inner to t5
001db808 v1: 13 words; best v1 13 words; streak 0
v2: 6 words, first diff at 5: C11c ok -> next: explicit vtable regs
001db808 v2: 6 words; best v2 6 words; streak 0
v3: 6 words same
001db808 v3: 6 words; best v2 6 words; streak 1
v4 exact
submitted 001db808 v4
claim 6 of 6: 001db850 token 6a9369e7935947b6b535ca8425b1520c attempts 1
v1: 5 words, first diff at 3: C11 -> next: array index form
001db850 v1: 5 words; best v1 5 words; streak 0
v2: 14 words worse
001db850 v2: 14 words; best v1 5 words; streak 1
v3 exact
submitted 001db850 v3
