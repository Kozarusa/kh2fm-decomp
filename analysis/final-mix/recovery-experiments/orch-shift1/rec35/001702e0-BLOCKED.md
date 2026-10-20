# 001702e0 blocked
- Range: 001702e0, 60 bytes. Versions tried: 7. Best: v4 with 11 differing words (56/60 bytes).
- First difference of the best version: !! 001702e0: 0000702d  move	t6,zero                                     | 001702e0: 0000782d  move	t7,zero
- Changes tried: v1 linked-list search with while(1) 15 words (wrong next offset 0x40); v2 offset fixed to 0x3c, 15; v3 ternary with separate previous/node 15; v4 while((node = previous ? previous->next : head) != 0) form 11 (best, layout close but ternary compiles to beqz+plain loads instead of bnezl, and loop tail differs); v5 inverted ternary 11; v6 if-form with break 14; v7 if(node){...}else return 0 15.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: C8/C9 make the previous->next load volatile or restructure so the ternary yields bnezl with the load in the delay slot and the node kept in v0 (compare and return use v0 directly, previous copied with move t6,v0 in the bnez delay slot).