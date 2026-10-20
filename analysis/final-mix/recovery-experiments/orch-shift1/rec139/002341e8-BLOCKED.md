# 002341e8 blocked
- Range: 002341e8, 84 bytes. Versions tried: 8. Best: v8 with 4 differing words (84/84 bytes), source orch1_rec139_002341e8_v8.cpp.
- First difference of the best version: !! 00234218: 240f0004 li t7,4 | 00234218: ad4de360 sw t5,-7328(t2).
- Changes tried: v1 11 words. C11 serial binding gave v2 10 words; next serial binding gave v3 10 words; next serial guard gave v4 8 words. C10 payload memory barrier gave v5 11 words. C11 next index binding gave v6 11 words; next index guard gave v7 6 words; serial dependency guard gave v8 4 words.
- Streak sequence: v1 0, v2 0, v3 1, v4 0, v5 1, v6 2, v7 0, v8 0.
- Why it stops here: budget reached.
- Next hypothesis: Materialize tag 4 and return serial in guarded temporaries before the global stores, starting from earliest best v8.