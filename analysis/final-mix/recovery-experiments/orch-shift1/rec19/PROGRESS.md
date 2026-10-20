# rec19 progress
start 2026-10-12T19:53:41Z
claim 0014f5d0 token 228a3eb025034bb5a9e30de35dcd0e80 attempts 1
v1: exact
submitted 0014f5d0 v1 (claims so far: 1)
claim 00152ab8 token f7235321c4704c3ab9fdb2849d868e67 attempts 1
v1: 14 words, first diff at 2: C3/ext of a2 (u32 value widened) -> next: value u64
v2: 14 words (value u64 -> dsll32 sext on a2 & t3) -> next: callee decl u32 for 3rd/5th, params u32
v3: 4 words, first diff at 8: C11 (t7 vs a0 for last store) -> next: C11b temp variable
v4: 4 words, same diff: temp var folded -> next: object u64 with s32 casts for stores
v5: 12 words (worse, sext) -> next: v3 + C11c register bind t7 for last store
v6: 7 words, extra move a0,a0 + sched: C11c -> next: bind at top, drop asm
v7: 8 words (bind at top; extra move a0,a0 remains) -> next: unbound alias with asm +r
v8: 7 words, budget reached
blocked 00152ab8 -> register-allocation (claims so far: 2)
claim 00153100 token 552cff5dcb9e472b844dbfe6be08f6cd attempts 1
v1: exact
submitted 00153100 v1 (claims so far: 3)
claim 001535b0 token c8241ece2c494e8a9817ac948b3179b5 attempts 1
v1: 8 words, first diff at 8: C11 (addu operand order) -> next: index*24 + base
v2: exact
submitted 001535b0 v2 (claims so far: 4)
claim 001538d8 token 84f7b72341f144b6b2505e50b8276b3e attempts 1
v1: 12 words, first diff at 5: C11 (t4/t5 swapped) -> next: swap declaration order of index/offset
v2: identical to v1 (replace failed, newline mismatch), 12 words
v3: 12 words same (decl order no effect) -> next: offset init inside the if (Ghidra shape)
v4: 3 words, offset init move t5 ahead of hoisted lui/li: C11 -> next: for loop form
v5: 3 words same -> next: C11d asm +r after offset init
v6: 4 words worse -> next: v4 with 0 < count test
v7: 3 words, no improvement for 3 versions
blocked 001538d8 -> register-allocation (claims so far: 5)
claim 00153948 token 33242611349e4f54b7f6b1ea16ded870 attempts 1
v1: 2 words, move t5 before lui t2: C11 -> next: offset u32
v2: 2 words same -> next: offset declared at function top / loop as for with both inits
v3: 11 words worse -> next: v1 with offset bound to $13
v4: 23 words worse; no improvement for 3 versions
blocked 00153948 -> register-allocation (claims so far: 6)
