# rec08 progress
start 2026-10-12T18:02:04Z
claim 00135d00 token 01ea2d3038234f17938a5c6fb12ee8f8 attempts 1 (claims: 1/6)
v1: 13 words, first diff at 1: C7 -> next: do-while for the subtract loop
v2: exact
submitted 00135d00 v2
claim 00136a18 token a19084f54276430e8006fef4630faf9a attempts 1 (claims: 2/6)
v1: 8 words
blocked 00136a18 -> boundary-review
claim 001373a0 token ffcc36df08814390946e7eae36e56f62 attempts 1 (claims: 3/6)
v1: exact
submitted 001373a0 v1
claim 00138190 token cb9a276493d04f5984b26662d89a4c11 attempts 1 (claims: 4/6)
v1: 18 words, first diff at 4: C10/C11 -> next: swap store order
v2: 16 words, first diff at 4: C11(b) -> next: compute next%8 before loading tail
v3: 24 words, first diff at 1: worse -> next: back to v2 shape, wrapped computed after tail load
v4: 24 words (same as v3): wrapped var is the harm -> next: v2 shape without tail var
v5: 16 words, regs only (C11) -> next: used before next
v6: 16 words (no change)
blocked 00138190 -> register-allocation
claim 001385c0 token 66eb3538ba25445c9df7f4e9d8ec83fb attempts 1 (claims: 5/6)
v1: exact
submitted 001385c0 v1
claim 001397d8 token 62bd56359ec74febaf22b493e5fa2282 attempts 1 (claims: 6/6)
v1: 22 words, first diff at 8: C7 -> next: ternary for next node
v2: 22 words, first diff at 8: C1(a) a0 is this argument of the call -> next: pass node to callback
v3: 22 words, first diff at 8: C7 (regs now match) -> next: negate if/else
v4: 21 words, first diff at 8: C7a no gain -> next: v3 form with volatile node->next read (C9)
v5: 20 words, size now matches, first diff at 8: C7 -> next: invert null test, body inside if(node)
v6: 20 words, no change -> next: while((node = cond ? ... ) != 0) form
v7: 4 words, first diff at 8: C7a -> next: flip ternary arms
v8: 2 words
blocked 001397d8 -> register-allocation
