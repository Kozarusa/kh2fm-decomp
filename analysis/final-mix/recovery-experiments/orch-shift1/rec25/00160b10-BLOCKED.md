# 00160b10 blocked
- Range: 00160b10, 120 bytes. Versions tried: 6. Best: v3 with 23 differing words (120/120 bytes).
- First difference of the best version: !! 00160b28: 56000002  bnezl s0,0x160b34 (compiled: beqz s0,160b34 with the loads in swapped order).
- Changes tried: v1 flat loop with break (offset bug); v2 offset fixed 24 words (112 bytes); v3 ternary + current=node before null test + struct global {head,count} 23 words; v4 early return in loop 33; v5 pre-loop if(current) form 30 (folded); v6 if/else in loop 23 (identical to v3).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: loop is bottom-tested with exit block placed first and body after the epilogue, and node = current ? current->next : head uses branch-likely; try do/while with goto or a volatile read of current->next (C8c/C9) to get bnezl.
