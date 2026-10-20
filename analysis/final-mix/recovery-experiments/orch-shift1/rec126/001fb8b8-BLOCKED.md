# 001fb8b8 blocked
- Range: 001fb8b8, 108 bytes. Versions tried: 4. Best: v1 with 18 differing words (108/108 bytes).
- First difference of the best version: !! 001fb8c8: 0000282d  move	a1,zero | 001fb8c8: afab0014  sw	t3,20(sp)
- Changes tried: v1 local Args struct (18); v2 C10a source store reorder (18, same output); v3 C10c volatile struct (18, different schedule); v4 conversions in temporaries first (18, same as v1).
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: the same argument-block shape as 001fb508 (also blocked); the scheduler emits sw inner,20(sp) early. Try a different struct member type for inner (s32) or order of declaration so the early t3 store is delayed.
