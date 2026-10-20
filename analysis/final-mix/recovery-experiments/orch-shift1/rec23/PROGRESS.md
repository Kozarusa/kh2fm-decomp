# rec23 progress
start 2026-10-12T20:29:24Z
claim 0015aaf8 token 7198e2cb0cb44a6789e913581bf63787 attempts 1 (claims: 1/6)
submitted 0015aaf8 v1
claim 0015ac68 token d12a1f1c4dbd4e9dbbe18e1b0c1c9962 attempts 1 (claims: 2/6)
submitted 0015ac68 v1
claim 0015b268 token e2600b2ea2534b499065a86f242482e1 attempts 1 (claims: 3/6)
v1: 4 words, first diff at 17: reload of D_0034aa9c -> next: volatile pointer global (C9)
v2: 8 words (volatile worse: a1 move displaced) -> next: memory clobber after store (C10d)
v3: 12 words (tail call lost) -> next: global as u32 address with casts
v4: 4 words same as v1 -> next: volatile only on final read
v5: 5 words; remaining schedule/regs -> next: local pointer for store (C11b)
v6: compile error (bad newline escape) -> v7 same idea
v7: 5 words, no improvement for 3+ versions -> block
blocked 0015b268 -> store-order
claim 0015c228 token 9820277896d14826991da01dd2d46278 attempts 1 (claims: 4/6)
v1: 14 words, first diff 1: C10/C11 order of af30 store vs load data[1] -> next: reorder statements
v2: 2 words, last lui t6 vs t7 (C11) -> next: introduce temp pointer
v3: 2 words same -> next: asm +r on count (C11d)
v4: 10 words worse -> next: volatile D_0034af30 (C10c)
v5: 2 words same -> next: temp for base (C11b)
v6: 2 words, no improvement for 4 versions -> block
blocked 0015c228 -> register-allocation
claim 0015c450 token fc6d466e3d2b4975b5fb984194fbf0cd attempts 1 (claims: 5/6)
v1: 20 words, size 88 vs 76, count masked via dsll32/dsra32 (C15) -> next: u32 index param
submitted 0015c450 v2
claim 0015cc18 token 27f7f1d103a348f2b71697055abcfd95 attempts 1 (claims: 6/6)
v1: 3 words, store order (C10) -> next: source order 0,1,2,3
submitted 0015cc18 v2
