# rec119 progress
start 2026-10-13T06:58:16Z
claim 1 of 6: 001e03b0 token eea85b311688461abafbf23dc55b9ad4 attempts 1
blocked 001e03b0 -> boundary-review (R3, 0 versions)
claim 2 of 6: 001e0750 token 3bf8e8e45f4a4f6c9d255997eb69e35a attempts 1
submitted 001e0750 v1
claim 3 of 6: 001e0d08 token fd5329fad836482d8739fb0113ea4c39 attempts 1
v1: 20 words, first diff 0: C11 ; v2 (struct members, no volatile): 23 words, worse; best v1 20; streak 1
v3: 21 words, size matches; best v1 20; streak 2
v4: 22 words; best v1 20; streak 3 -> stop
blocked 001e0d08 -> store-order
claim 4 of 6: 001e0d68 token 41b57707645e4947b2b97eef83c4a335 attempts 1
001e0d68 v1: 20 words; best v1 20; streak 0
001e0d68 v2: 21 words; best v1 20; streak 1
001e0d68 v3: 22 words (union, reloads table/index); best v1 20; streak 2
001e0d68 v4: 16 words (union incl D as Word); best v4 16; streak 0
001e0d68 v5: 16 words; best v4 16; streak 1
001e0d68 v6: 20 words; best v4 16; streak 2
001e0d68 v7: 16 words; best v4 16; streak 3 -> stop
blocked 001e0d68 -> register-allocation
claim 5 of 6: 001e0de8 token d50eaf317b5d4d7aa881cea09d7e42d6 attempts 1
001e0de8 v1: 16 words; best v1 16; streak 0
001e0de8 v2: 17 words; best v1 16; streak 1
001e0de8 v3: 15 words; best v3 15; streak 0
001e0de8 v4: 6 words (barrier asm after zero store); best v4 6; streak 0
001e0de8 v5: 2 words (register binding t0 for quads); best v5 2; streak 0
001e0de8 v6: identical to v5 (replace failed, no change); best v5 2; streak 1
submitted 001e0de8 v7
claim 6 of 6: 001e0fe8 token 8f757d5bf4464a71b9bc13c45ca257c8 attempts 1
001e0fe8 v1: 22 words; best v1 22; streak 0
001e0fe8 v2: 14 words (u8 load + s8 casts); best v2 14; streak 0
001e0fe8 v3: 20 words (separate result var); best v2 14; streak 1
001e0fe8 v4: 12 words (volatile first store); best v4 12; streak 0
001e0fe8 v5: 18 words; best v4 12; streak 1
001e0fe8 v6: 19 words; best v4 12; streak 2
001e0fe8 v7: 22 words; best v4 12; streak 3 -> stop
blocked 001e0fe8 -> branch-layout
