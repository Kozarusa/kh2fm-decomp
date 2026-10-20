# med01 progress
start 2026-10-12T16:50:15Z
claim 0010cce0 token 8f494c887e8a4ee88e89e2d5d975952f attempts 3
v1: compile error (UTF-8 BOM from Set-Content) -> next: same source without BOM
v2: 13 words, first diff at 7: C7(b) -> next: merge null test and predicate into one || break with shared return
v3: 12 words, first diff at 7: C7(a) -> next: negate first test, place shared return block in loop middle (goto layout)
v4: 12 words (no change), first diff at 7: C7(c) -> next: while loop with call in loop test, break on predicate
v5: exact
submitted 0010cce0 v5
claim 00160488 token a8c7182f83f44e3bbadbf803519d4b46 attempts 3
v1: 19 words, 68/76, first diff at 0: C9/C10 loads after stores -> next: compute three products in locals before stores
v2: 14 words, 68/76, first diff at 1: C12 (frame missing) -> next: add unused local byte array to create the 16-byte frame
v3: 11 words, 76/76, first diff at 1: C11/C10 schedule order -> next: mask params into u8 locals at top in red,green,blue order
v4: 9 words, 76/76, first diff at 2: C11(a) -> next: compute green product before blue
v5: 2 words, 76/76, first diff at 6: C11(a) mult/mult1 bank -> next: product order blue, red, green
v6: 9 words (worse), first diff at 2: C11(a) -> next: product order red, green, blue
v7: exact
submitted 00160488 v7
claim 00161548 token 180d13475dbe4e5ea1c3194ccddec721 attempts 3
v1: 18 words, 72/76, first diff at 1: C12(b) result kept in s0 across call -> next: early returns per test, result local only after call
v2: 14 words, 68/76, first diff at 2: C7(c) block layout -> next: list-null path returns a variable (not constant) so it becomes the fallthrough return
v3: 18 words, 76/76, first diff at 1: C12(b) result in s0 -> next: separate variable for the list-null return value
v4: 14 words (same as v2), first diff at 2: C7 block layout -> next: list as u32 integer (no pointer branch prediction) so call block is laid out after the epilogue
v5: 14 words, first diff at 2: C7 -> stop (3 versions without improvement)
blocked 00161548 -> branch-layout
claim 0016ffc8 token 296c2f3ba88047d9bac5d12fb142e09d attempts 3
v1: 17 words, 72/80, first diff at 0: C8 movz vs beqzl -> next: C8(b) condition written the other way (&& of >= tests)
v2: 17 words (no change), first diff at 0: C8 -> next: C8(a) candidate and result separate via early returns
v3: 10 words, 84/80, first diff at 1: C7/C8 -> next: result=candidate assigned before tests, last range test restores original
v4: 11 words, 80/80, first diff at 7: C8 movn -> next: nested if, return candidate inside, single shared return original
v5: exact
submitted 0016ffc8 v5
claim 00170ee8 token 851bb95b03cc41ebb7c68b04174501c8 attempts 3
v1: 8 words, 76/76, first diff at 5: C11 address register order -> next: C11(b) struct type for the pair
v2: 8 words, first diff at 5: C11 t6/t7 swapped only -> next: C11(b) pointer passed through inline helper (constructor-like)
v3: 8 words, first diff at 5: C11 -> next: C11(c) bind pair pointer to $15
v4: exact
submitted 00170ee8 v4
claim 0018dbd8 token 19325d6a67564b8f962eac72691bfda7 attempts 3
v1: 17 words, 52/80, first diff at 3: C1 fold merged 8|0x10 tests -> next: read flags through memory in each test so tests stay separate
v2: 17 words (same), first diff at 3: C1 -> next: inner selection as separate if statements inside the statement expression
v3: 18 words, 76/80, first diff at 2: C9 reload of flags -> next: flags as local value, selected initialised false then set in if/else-if
v4: 14 words, 68/80, first diff at 3: C8 sltu store-flag instead of shared set block -> next: single || test with statement-expression operands (no fold merge) setting selected
v5: 10 words, 84/80, first diff at 3: extra sltu bool normalisation (C2-like type) -> next: selected as u8 instead of bool
v6: 10 words (same), first diff at 3: C8 extra sltu -> next: outer tests as if statements instead of || value
v7: 13 words, 80/80, first diff at 1: C8 sltu remains -> next: selected assigned directly from the || value (inline-return shape)
v8: 12 words, first diff at 3: C8 -> stop (3 versions without improvement)
blocked 0018dbd8 -> branch-layout
claim 0018f0b0 token 972ee0af40af47e1a2480687d8a64f19 attempts 3
v1: 16 words, 76/80, first diff at 1 (offset; real at 6): C5/C11 lo folded into lwc1 -> next: C11(d) asm barrier on source pointer
v2: 4 words, 80/80, first diff at 6: C10 store address hoisted (lui t6) -> next: C10(d) asm memory barrier between load and store
v3: exact
submitted 0018f0b0 v3
claim 00192818 token 3f7f940b68c74e07936f6432afb5fae0 attempts 3
v1: 8 words, 80/80, first diff at 4: C10 word0 load/store order -> next: C10(a) statements in original store order 2,0,1,3,4,5
v2: 8 words, first diff at 4: C10 -> next: C10(b) rotate word0 copy to the end (1..5,0)
v3: 12 words, first diff at 3: C10 -> next: loads into locals in order 0..5, stores in original order 2,0,1,3,4,5
v4: 10 words, first diff at 4: C10 -> stop (3 versions without improvement)
blocked 00192818 -> store-order
WP report written 2026-10-12T17:07:30Z
