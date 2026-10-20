# rec52 progress
start 2026-10-12T23:16:43Z
claim 00188670 token 53a7e9c3855049ca8fd84b1ba4b871f2 attempts 1 (claims: 1/6)
v1: 30 words, first diff 0: C21 -> next: struct array index loop
v2: 8 words, first diff 13
v3: exact
submitted 00188670 v3
claim 00188758 token fe25b6a629ac4922bbf0a8dd43a0de8a attempts 1 (claims: 2/6)
v1 (00188758): 1 word, lbu vs lw: C2/C9 -> next: u8 flag local
v2: 1 word still
v3: exact
submitted 00188758 v3
claim 00189228 token a8ea8f5008eb4500b2f6038a6b4df2d3 attempts 1 (claims: 3/6)
v1 (00189228): 9 words, first diff 1: C11 -> next: operand order
v2: 6 words, missing andi 0xffff: C3 -> next: cast compare
v3: 6 words same (mask folded) -> next: C11d asm barrier
v4: exact
submitted 00189228 v4
claim 0018a100 token 6972539f6dfb4746b45c5140239cdc12 attempts 1 (claims: 4/6)
v1 (0018a100): 14 words, first diff 9: C7 -> next: restructure with result as loop var, break
v2: 16 words (worse) -> next: C7c if + do-while
v3: 14 words same as v1 -> next: separate iterator copy
v4: 14 words, no gain -> next: ghidra literal (break on 22, return in-loop)
v5: ~14+ words no gain; stopping (3 without improvement)
blocked 0018a100 -> branch-layout
claim 0018b200 token 21de4e986e524cd8bc62dded00c12e1c attempts 1 (claims: 5/6)
v1: exact
submitted 0018b200 v1
claim 0018c528 token dbe4f9fd610c44d7832e9e47c64325db attempts 1 (claims: 6/6)
v1 (0018c528): 14 words, no jump table: C21 -> next: dense switch cases
v2: 15 words, table now emitted but layout differs (52 bytes) -> next: wrap in if (value<14), case 3 break, outer return 0
v3: 15 words same -> next: result variable (C8a-like)
v4: 6 words, 68 bytes (duplicate 287 block) -> next: merge case 2 and 4
v5: 7 words, 60 bytes (case 3 needs own return) -> next: case 3 return 0
v6: 7 words same -> next: grouped 2/4 in separate case 3 break variant with 'return result' sinks reordered
v7: worse; stopping (3 without improvement)
blocked 0018c528 -> branch-layout
