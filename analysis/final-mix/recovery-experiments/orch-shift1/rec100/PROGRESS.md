# rec100 progress
start 2026-10-13T04:39:53Z
claim 1 of 6: 001c7950 token abff734d19444d5db8f888faab1c72bc attempts 1
v1: 20 words, first diff 1: C3/C11 extra andi 0xff -> next: != 0
v2: 20 words same -> v3 Ghidra-style
v3: 30 words worse (best v1 20; streak 2) -> v4 early return
v4: 18 words best v4 -> v5 memory barrier
v5: 2 words (t0 vs t7) best v5 -> v6 temp quad var
v6: 2 words same; best v5 2; streak 1 -> v7 register bind t0
v7 exact
submitted 001c7950 v7
claim 2 of 6: 001c9958 token 8a7ba66a9e954c3188cc6d8f1a254aa8 attempts 1
001c9958 v1: 22 words, first diff 0: C8 movz/branch -> v2 bool temp
001c9958 v2: 20 words best v2; streak 0 -> v3 separate inRange zeroing
001c9958 v3: 21 words; best v2 20; streak 1 -> v4 ghidra tail from v2
001c9958 v4: 22 words; best v2 20; streak 2 -> v5 duplicated branches from v2
001c9958 v5: 19 words best v5; streak 0 -> v6 C6 xor 0
001c9958 v6: 19 words, no change; best v5 19; streak 1 -> v7 swap operand order
001c9958 v7: 17 words best v7; streak 0 -> v8 u8 inRange
001c9958 v8: 17 words no change; best v7 17; streak 1 -> v9 v2-style tail with swapped order
001c9958 v9: 18 words; best v7 17; streak 2 (note: 9 versions written, one over the 8 budget)
blocked 001c9958 -> branch-layout
claim 3 of 6: 001c9b90 token e6ef974bba92464b83c851957e5436e2 attempts 1
v1 exact
submitted 001c9b90 v1
claim 4 of 6: 001c9c00 token 0d8cb53f4a534af6b4be54f11362e862 attempts 1
v1 exact
submitted 001c9c00 v1
claim 5 of 6: 001c9db0 token 62618121d8244b2c9d352855be25275d attempts 1
001c9db0 v1: 16 words, first diff 1 -> v2 read global directly
v2 exact
submitted 001c9db0 v2
claim 6 of 6: 001ca950 token 0a8246b0f78e4be4bc46ef0732b4f135 attempts 1
v1 exact
submitted 001ca950 v1
