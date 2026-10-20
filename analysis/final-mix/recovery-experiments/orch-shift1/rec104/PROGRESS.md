# rec104 progress
start 2026-10-13T04:57:15Z
claim 1 of 6: 001cf998 token 6d49b092047e420d894de2ed67b3e33c attempts 1
v1: 0 words exact; submitted 001cf998 v1
claim 2 of 6: 001d0068 token f88c4180702a4d2e9fc591494686f999 attempts 1
v1: 13 words, first diff 2: C10/delay slot sd s0 -> next: asm memory barrier before first call
001d0068 v1: 13 words; best v1 13 words; streak 0
v2: 2 words, first diff 1: C10 sd s0/ra order -> next: barrier after first call instead
001d0068 v2: 2 words; best v2 2 words; streak 0
v3: 2 words same as v2; streak 1 (best v2)
001d0068 v3: 2 words; best v2 2 words; streak 1
v4: 13 words (varargs decl no effect); streak 2
001d0068 v4: 13 words; best v2 2 words; streak 2
v5: 2 words; streak 3 -> stop
blocked 001d0068 -> prologue-epilogue
claim 3 of 6: 001d1760 token a8fa1b0019674bac970f68f752c6e94b attempts 1
v1: 11 words, first diff 2: C7 -> next: negate/swap block order
001d1760 v1: 11 words; best v1 11 words; streak 0
v2: 12 words; best v1 11; streak 1
v3: 15 words; streak 2
v4: 8 words; best v4 8; streak 0
v5: 18 words; best v4 8; streak 1
v6: 18 words; best v4 8; streak 2
v7: 12 words; streak 3 -> stop
blocked 001d1760 -> branch-layout
claim 4 of 6: 001d2130 token 2befbf8236f94ca1ba40fe5857f63e3a attempts 1
v1: 0 words exact; submitted 001d2130 v1
claim 5 of 6: 001d2690 token 73f0a4864062450cac735ad05d4b5f3e attempts 1
v1: 29 words, first diff 2: C12 extra s1 needed -> next: slot pointer variable
001d2690 v1: 29 words; best v1 29 words; streak 0
v2: 10 words, first diff 22: C9/address materialization -> next: declare global as f32 array
001d2690 v2: 10 words; best v2 10 words; streak 0
v3: 10 words same; streak 1
v4: 10 words same; streak 2
v5: 0 words exact; submitted 001d2690 v5
claim 6 of 6: 001d2930 token b266553fe2914022ba4a732cd0a54d20 attempts 1
v1: 10 words, first diff 2: C11 -> next: local copy of count inside the if
001d2930 v1: 10 words; best v1 10; streak 0
v2: 2 words, first diff 11: C11 order of move s3/move s0 -> next: pre-decrement in loop condition
001d2930 v2: 2 words; best v2 2; streak 0
v3: 2 words same; streak 1
v4: 2 words same; streak 2
v5: 2 words same; streak 3 -> stop
blocked 001d2930 -> register-allocation
