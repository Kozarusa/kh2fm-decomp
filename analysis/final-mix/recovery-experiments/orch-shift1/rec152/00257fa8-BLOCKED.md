# 00257fa8 blocked
- Range: 00257fa8, 80 bytes. Versions tried: 8. Best: v6 with 9 differing words (80/80 bytes).
- First difference of the best version: !! 00257fc8: 51e00006 beqzl t7,0x257fe4 | 51e00004 beqzl t7,257fdc.
- Changes tried: v1 literal loop 17; C11 v2 result temporary 17; C11 v3 result bound v0 10; C7 v4 negate inner condition 10; C11 v5 assign success into result 10; C11 v6 empty guard 9; C7 v7 negate outer flag 9; C7 v8 inner early-return if/else 12.
- Why it stops here: budget reached.
- Next hypothesis: reconcile v8 inline early exit and delay-slot move without successful-result guard; requires fresh budget.
