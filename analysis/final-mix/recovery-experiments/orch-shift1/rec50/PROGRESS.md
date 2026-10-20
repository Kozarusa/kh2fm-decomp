# rec50 progress
start 2026-10-12T23:07:55Z
claim 00186ce8 token c4f59043561b4ddc8e2af2df99e4187f attempts 1
v1: 10 words, first diff 1: C21/structure -> next: inner pointer
v2: 8 words, first diff 2: C8 -> next: separate low/high temps
v3: 8 words: C8 low/high temps no help (movn) -> next: ternary
v4: 8 words: ternary swapped movz regs -> next: low/high order with asm barrier
blocked 00186ce8 -> branch-layout (claims so far: 1)
claim 00187420 token e3a31d703a544b51b9130a43d21d9a2f attempts 1
v1: 31 words first diff 0: C12 -> next: result via if/else
v2: 6 words first diff 12: C11/C12 result reg+dup zero -> next: result declared after call
submitted 00187420 v3 (claims so far: 2)
claim 00187ab8 token 10ad79c30c1540c29ae14ff46abecc29 attempts 1
v1: 25 words first diff 1: result var init zero -> v2
v2: 13 words first diff 1: t6 vs t7 -> v3 goto/reset after loop
v3: 6 words first diff 2: C11 prologue order -> v4 separate cursor
v4: 4 words first diff 1: C11 t6 vs t7 -> v5 bind result to \
submitted 00187ab8 v5 (claims so far: 3)
claim 00188340 token 4d8a07c752f24b5ca72afe1b88ae5fd7 attempts 1
v1: 2 words first diff 12: C10 order of li/move -> v2 swap assignments
submitted 00188340 v2 (claims so far: 4)
claim 001883f8 token b73cf74db8fd4ec580e6bb11ff9c19d0 attempts 1
submitted 001883f8 v1 (claims so far: 5)
claim 00188470 token 87c3aad3c23b413bb7574914b45925de attempts 1
blocked 00188470 -> boundary-review (claims so far: 6)
