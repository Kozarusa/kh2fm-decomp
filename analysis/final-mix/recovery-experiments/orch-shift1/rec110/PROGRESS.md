# rec110 progress
start 2026-10-13T05:42:58Z
claim 1 of 6: 001d9228 token bfeab03b0bb54b3793cea10eb538d48f attempts 1
v1: 25 words, first diff at 0: C12 -> next: no result variable, early returns
v2: 9 words, first diff at 6: C2/C12 lbu vs lw, result in a0 -> next: u32 read then mask, base var in both, result var
v3: 25 words (best v2 9, streak 1): C12 result var costs s1 -> next: early returns with v3 body
v4: 7 words (best v4 7, streak 0): result in a0 not v0 -> next: if/else assigning result
v5: 7 words (best v4 7, streak 1): same -> next: C11c register v0 binding
v6: 17 words (best v4 7, streak 2): C11c worse -> next: C11d asm keep on v4 form
v7: 7 words (best v4 7, streak 3): stop
blocked 001d9228 -> register-allocation
claim 2 of 6: 001d9c68 token 47e60f1bde4542a8b315a6c94bb6d2ba attempts 1
v1 (001d9c68): 13 words, first diff at 1: C11 -> next: indexed loop data[index]
001d9c68 v2: 6 words, first diff at 2: C11 t6/t7 swap -> next: separate value temp, index++ after
001d9c68 v3: 6 words (best v2 6, streak 1) -> next: C11c bind pointer to t6
submitted 001d9c68 v4
claim 3 of 6: 001d9d48 token 673a62305b564d6ab6262e826872b058 attempts 1
001d9d48 v1: 12 words, first diff at 0: C11 -> next: mask computed first
001d9d48 v2: 12 words (best v1 12, streak 1) -> next: single expression like Ghidra
001d9d48 v3: 17 words (best v1 12, streak 2) -> next: C11c bind bit=t3 row=t5
001d9d48 v4: 10 words (best v4 10, streak 0) -> next: bind idx t4 and mask t6
001d9d48 v5: 7 words (best v5 7, streak 0) -> next: swap row/index register numbers
001d9d48 v6: 7 words (best v5 7, streak 1; bindings had no effect) -> next: C11d asm keep on row and index
submitted 001d9d48 v7
claim 4 of 6: 001da420 token 0ab38a70db344045aa1158344b4b771e attempts 1
001da420 v1: 3 words, first diff at 8: C11/C8 -> next: temp for next value, do-while
001da420 v2: compile error (scope), counts as version -> next: declare next outside loop
001da420 v3: 6 words (best v1 3, streak 2) -> next: v1 with temp inside while body
001da420 v4: 3 words (best v1 3, streak 3): stop
blocked 001da420 -> branch-layout
claim 5 of 6: 001da458 token 9503a0dd8538445b9348c6e8cebd8936 attempts 1
001da458 v1: 28 words, first diff at 2: C12/C11 -> next: reuse one variable for both loop counters
001da458 v2: 30 words (best v1 28, streak 1) -> next: pointer object, separate locals, no param mutation
001da458 v3: 30 words (best v1 28, streak 2) -> next: v3 with index reused as count variable
001da458 v4: 24 words (best v4 24, streak 0)
001da458 v4 diff: C10 store/schedule in first loop -> next: precompute next pointer
001da458 v5: compile error (my edit typo), streak 1
001da458 v6: 24 words (best v4 24, streak 2) -> next: u32 index, mutate items (prior v2) but object pointer
001da458 v7: 30 words (best v4 24, streak 3): stop
blocked 001da458 -> store-order
claim 6 of 6: 001da4d8 token ad8f84ff9bb1421fb2c9fe88e6a0dfc6 attempts 1
001da4d8 v1: 26 words, first diff at 5: C1/C7 -> next: switch statement with single return
001da4d8 v2: 27 words (best v1 26, streak 1; switch changed shape) -> next: v1 with single variable for base/result
001da4d8 v3: 26 words (best v1 26, streak 2) -> next: C7a negate kind==1 branch
001da4d8 v4: 19 words (best v4 19, streak 0) -> next: kind<2 block as result=0; if(kind==0) result=object[2]
001da4d8 v5: 19 words (edit did not apply, identical to v4; best v4 19, streak 1)
001da4d8 v6: 19 words (best v4 19, streak 2) -> next: negate kind==2 and kind==0 tests
001da4d8 v7: 10 words (best v7 10, streak 0) -> next: kind as s32 (slti vs sltiu)
001da4d8 v8: 9 words (best v8 9, streak 0) -> next: kind<2 as result=0; if(kind==0) result=object[2]
001da4d8 v9: 9 words (best v8 9, streak 1) -> next: ternary result = kind ? 0 : object[2]
001da4d8 v10: 9 words (best v8 9, streak 2) -> next: position temp for object[1]
001da4d8 v11: 9 words (best v8 9, streak 3): stop
blocked 001da4d8 -> branch-layout
