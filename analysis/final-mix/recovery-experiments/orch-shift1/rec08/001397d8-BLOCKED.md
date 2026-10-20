# 001397d8 blocked
- Range: 001397d8, 124 bytes. Versions tried: 8. Best: v8 with 2 differing words (124/124 bytes).
- First difference of the best version: !! 001397fc: 8e447f80  lw	a0,32640(s2)   (compiled: 8e4f7f80  lw t7,32640(s2)); the next word differs the same way (lw a0,4(a0) vs lw a0,4(t7)).
- Changes tried: v1 if/else loop (22); v2 ternary (22); v3 pass node to the callback so a0 is the this argument (22, registers match); v4 negated if/else (21); v5 volatile read of node->next (20, size matches); v6 body inside if(node) (20); v7 while((node = cond ? volatile next : head) != 0) (4); v8 flipped ternary arms, node == 0 ? head : next (2).
- Why it stops here: budget reached (8 versions).
- Next hypothesis: only the temporary holding D_00347f80 differs (t7 vs a0); try removing the volatile on the next read (C9 may no longer be needed), or C11(c) binding the list pointer to register "$4" with a // why: comment.