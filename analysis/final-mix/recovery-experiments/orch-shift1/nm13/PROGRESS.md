# nm13 progress
start 2026-10-13T16:34:11Z
claim 1 of 6: 001dee10 token 3a4abb272ed44572878ba674968914ee attempts 3
001dee10 v1 reasoning: empty counter guard prevents pre-decrement copy allocation; copied best with individual guard comments.
001dee10 v1: 2 words; best v1 2 words; streak 0
v1: first diff 12 C11 -> bind pre-decrement compare to same t7 to eliminate copy.
001dee10 v2: 2 words; best v1 2 words; streak 1
v2: first diff 12 C11 -> C7 for loop compares counter before decrement without pre-copy.
001dee10 v3: compile error; best v1 2 words; streak 2
v3 malformed loop replacement; v4 correct loop shape, one repair.
001dee10 v4: 0 words; best v4 0 words; streak 0
submitted 001dee10 v4
claim 2 of 6: 001ded98 token d2ad47ec62dd4533b9fc2d2232ac94d3 attempts 3
001ded98 v1 reasoning: packet instruction words identical to 001dee10 including callees and offsets; transplant exact loop pattern and bindings, retaining this target symbol.
001ded98 v1: 0 words; best v1 0 words; streak 0
submitted 001ded98 v1
claim 3 of 6: 001e0230 token 8694b4012f6a4b1e845b2c1b046a707b attempts 3
001e0230 v1 reasoning: explicit trailing call label encourages branch around inline epilogue instead of inline call block.
001e0230 v1: 22 words; best v1 22 words; streak 0
v1 C1 goto loses invariant hoisting; v2 use while assignment condition retaining explicit head-selection branches.
001e0230 v2: 0 words; best v2 0 words; streak 0
submitted 001e0230 v2
claim 4 of 6: 001dddd0 token b0e1a34f447b42b281bdf1ad11468db7 attempts 3
001dddd0 v1 reasoning: define bound data copy after first store to preserve end computation and prologue scheduling.
001dddd0 v1: 9 words; best v1 9 words; streak 0
v1 C12 prologue moved by binding; v2 leave end unbound while data copy remains t7.
001dddd0 v2: 9 words; best v1 9 words; streak 1
v2 C11 add separate self guard after object copy to retain store through copied object.
001dddd0 v3: 8 words; best v3 8 words; streak 0
v3 C11 end binding ignored without guard; v4 guard computed end before store.
001dddd0 v4: 3 words; best v4 3 words; streak 0
v4 C11 initial store should use incoming a1 not guarded copy; v5 store data.
001dddd0 v5: 2 words; best v5 2 words; streak 0
v5 C11 original addiu uses original object a0, v6 pass object+2 not guarded self.
001dddd0 v6: 2 words; best v5 2 words; streak 1
v6 C10 guard original object plus memory after store to order address formation.
001dddd0 v7: 2 words; best v5 2 words; streak 2
v7 C11 introduce effect temporary guard plus memory to keep original address-before-load ordering.
001dddd0 v8: 0 words; best v8 0 words; streak 0
submitted 001dddd0 v8
claim 5 of 6: 001d4f40 token eb7c7b326f9a40ffac62c57f8805ccd3 attempts 3
001d4f40 v1 reasoning: correctly formed empty guard evaluates previously untested constant scheduling constraint.
001d4f40 v1: 0 words; best v1 0 words; streak 0
submitted 001d4f40 v1
claim 6 of 6: 001e7470 token 396beafd148146d18cb4e1e54acb63f9 attempts 3
001e7470 v1 reasoning: explicit goto into final epilogue label after store may mark return as branch target; no barrier or extra machine instruction intended.
001e7470 v1: 9 words; best v1 9 words; streak 0
v1 explicit goto changes allocation and fails epilogue; v2 C18 register block type preserves plain store order.
001e7470 v2: 3 words; best v2 3 words; streak 0
v2 C13 explicit void return expression may keep store in exit block before return.
001e7470 v3: 3 words; best v2 3 words; streak 1
R12 conservative block: no permitted source-only change remains for delay-slot constraint; barrier retries forbidden.
blocked 001e7470 -> store-order
end 2026-10-13T16:43:52Z
