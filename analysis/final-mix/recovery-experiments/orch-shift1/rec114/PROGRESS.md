# rec114 progress
start 2026-10-13T06:06:18Z
claim 1 of 6: 001db9a8 token 05cb0b966b0c4343b08a67eb5badf0e1 attempts 1
v1: 18 words, first diff at 10: C12 -> next: separate vars for check and alloc result
001db9a8 v1: 18 words; best v1 18 words; streak 0
submitted 001db9a8 v2
claim 2 of 6: 001dba98 token 1c875656c64347659171022eb1445f57 attempts 1
submitted 001dba98 v1
claim 3 of 6: 001dbad0 token 5092e121b96a41b18de0f8c1b4b83687 attempts 1
v1: link error (asm label undefined) -> next: plain func_001c2578 declaration
001dbad0 v1: compile error; best none; streak 1
v2: 4 words, first diff 12: C11 -> next: dest pointer variable
001dbad0 v2: 4 words; best v2 4 words; streak 0
v3: 4 words, same diff: C11(b) dest pointer var no effect -> next: u8 array decl for D_00352a60
001dbad0 v3: 4 words; best v2 4 words; streak 1
v4: 4 words, same diff: array decl no effect -> next: C11(d) empty asm guard on destination
001dbad0 v4: 4 words; best v2 4 words; streak 2
v5: 4 words, first diff 13: C11(d) -> t6/t7 swapped
001dbad0 v5: 4 words; best v2 4 words; streak 3
blocked 001dbad0 -> register-allocation
claim 4 of 6: 001dbcd0 token aa183334b295460abde4b26e8c632997 attempts 1
v1 (001dbcd0): 5 words, first diff 10: C11 -> next: register binding \ for destination
001dbcd0 v1: 5 words; best v1 5 words; streak 0
v2 (001dbcd0): 5 words, no effect -> next: add asm guard
001dbcd0 v2: 5 words; best v1 5 words; streak 1
v3 (001dbcd0): 2 words, first diff 14 (quad temp t6 vs t0) -> next: bind temp to \
001dbcd0 v3: 2 words; best v3 2 words; streak 0
submitted 001dbcd0 v4
claim 5 of 6: 001dc018 token 78595f8fbe9343ebb0c33fb70cbbe30b attempts 1
001dc018 v1: 18 words; best v1 18 words; streak 0 (C1: flag var result, return result != 0)
submitted 001dc018 v2
claim 6 of 6: 001dc418 token 6c7083c812e74a419d8bec30afe0d120 attempts 1
001dc418 v1: 6 words; best v1 6 words; streak 0 (C11 t6/t7 swap) -> next: bind vtable address to \ + guard
001dc418 v2: 3 words; best v2 3 words; streak 0 (store moved after move s0)
submitted 001dc418 v3
