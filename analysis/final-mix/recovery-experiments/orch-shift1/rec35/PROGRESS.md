# rec35 progress
start 2026-10-12T21:51:07Z
claim 0016f930 token e23af2540f934ae6bac8479ed6e762cf attempts 1
v1: 11 words, first diff at 1: C11 -> next: reorder declarations
v2: 9 words, first diff at 1: C11 -> next: order pointer,index,result
v3: 11 words, first diff at 1: C11 -> next: for-loop form
v4: 9 words, first diff at 1: C11 -> next: register binding
v5: 15 words, worse (full binding): C11 -> next: order index,result,pointer
v6: 11 words: no improvement for 3 versions -> block
blocked 0016f930 -> register-allocation
claim 0016f9e8 token c17aa34ca5db4fc0b4473a30d0b178ae attempts 1 (claim count 2)
blocked 0016f9e8 -> boundary-review (R3, 0 versions)
claim 001702e0 token 1afffe325de44fd5b601719f0701df42 attempts 1 (claim count 3)
v1: 15 words, first diff at 0: C1 offset wrong (0x40 vs 0x3c) -> next: fix offset
v2: 15 words, first diff 0: C7/C21 -> next: ternary with separate prev/cur
v3: 15 words identical to v2 -> next: C7 while(cond) form
v4: 11 words, first diff 0: C7 -> next: invert ternary
v5: 11 words same: -> next: ghidra if-form with break, return after loop
v6: 14 words worse -> next: ternary + if(node){..continue} else return 0
v7: 15 words: no improvement for 3 versions -> block
blocked 001702e0 -> branch-layout
claim 001703a8 token da38d0116c974c508b2f63c30c735858 attempts 1 (claim count 4)
v1: 8 words, first diff 2: C11 -> next: ghidra while((node=next)!=0) form
v2: 10 words worse -> next: for loop with next declared first
v3: 8 words same: -> next: C11c bind next to s1 and value to s0
v4: 9 words, prologue matches but node in t6 -> next: bind only next (s1) in v1 form
submitted 001703a8 v5
claim 001708f8 token 0dc71263b7844345920b0406878ea6c8 attempts 1 (claim count 5)
v1: 14 words, first diff 5: C6 -> next: size > 9999
v2: 14 words same: C6 -> next: explicit xor
v3: 14 words same (compiler folds xor): C7 -> next: if(a&&b){} else dump form
v4: 14 words same -> next: separate flag variable computed with xor
v5: 18 words but xori+beqzl appeared -> next: assign flag inside the || condition
submitted 001708f8 v6
claim 00170dd0 token db1f10e2a2e54dbe8c05c375600fabb2 attempts 1 (claim count 6, last)
submitted 00170dd0 v1
WP report written
