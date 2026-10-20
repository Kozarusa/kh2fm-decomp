# 002338a8 blocked
- Range: 002338a8, 116 bytes. Versions tried: 6. Best: v3 with 26 differing words (120/116 bytes), source orch1_rec139_002338a8_v3.cpp.
- First difference of the best version: !! 002338b0: 25ef13ac addiu t7,t7,5036 | 002338b0: c5e013ac lwc1 $f0,5036(t7).
- Changes tried: C1 signature and paths checked; v1 37 words. C16 accepted 0016df28 conversion primitive gave v2 29 words. Stack-backed volatile union gave v3 26 words. C11 temporary global address and guard gave v4 31 words; address binding gave v5 31 words; scaled float binding gave v6 31 words.
- Streak sequence: v1 0, v2 0, v3 0, v4 1, v5 2, v6 3.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: Change the coefficient global to an array to force address formation without a guard, starting from earliest best v3.