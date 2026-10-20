# rec25 progress
start 2026-10-12T20:45:52Z
claim 0015ee10 token 1b89e1c53dff49609111f323aadd172d attempts 1
submitted 0015ee10 v1 (claims: 1)
claim 00160430 token 7ad86bcd3cdf493f9645efaa22c436b0 attempts 1 (claims: 2)
submitted 00160430 v1
claim 001608c0 token 1f774d6f3c20402e9c9f68455d8c416f attempts 1 (claims: 3)
v1: 23 words, first diff 8: C11 -> next: asm barrier on dest ptr
v2: 24 words (worse): asm barrier -> next: array-based quad copy
v3: ~same as v1 (array quad) -> next: asm lq/sq pattern from 00159ce0
submitted 001608c0 v4
claim 00160b10 token 52f04d89eddf43e09c7ea33d9e4046d2 attempts 1 (claims: 4)
v1: not exact, offset bug in pad2 (flags at 0x184 vs 0x180)
v2: 24 words first diff 6: C7/C8 -> next: ternary + current=node before null test + struct global {head,count}
v3: 23 words, size ok, first diff 6: C7 -> next: early-return with exit stores inside the null test
v4: 33 words worse (early return) -> next: v3 with if(current) next else head, while-loop form
v5: 30 words (folded) -> next: v3 with if/else in loop
v6: 23 words same as v3; 3 versions no improvement
blocked 00160b10 -> branch-layout
claim 00160d70 token f043ca8349e841a587462dadd709177d attempts 1 (claims: 5)
v1: 17 words, 104/108 bytes, first diff 8: C7 -> next: early return in loop
v2: identical 17 words (return vs break) -> next: while-condition form
v3: 12 words, layout right; first diff 8: ternary branch/delay -> next: inline helper for next node
v4: identical 12 (inline helper) -> next: volatile global D_004f3b38
v5: 13 worse (volatile) -> next: assign current in while condition
v6: 12 same; stop
blocked 00160d70 -> branch-layout
claim 00160de0 token b1fdeda4fada4b5aaa80b06707be2568 attempts 1 (claims: 6)
v1: 12 words presumably (same as 00160d70 v3); v2 volatile owner 17 worse
v3: duplicate of v1; v4 asm barrier 18; stop
blocked 00160de0 -> branch-layout
