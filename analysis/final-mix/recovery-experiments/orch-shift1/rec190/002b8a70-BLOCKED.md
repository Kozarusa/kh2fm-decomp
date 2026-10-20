# 002b8a70 blocked
- Range: 002b8a70, 80 bytes. Versions tried: 8. Best: v6 with 2 differing words (80/80 bytes).
- First difference of the best version: `!! 002b8aa4: 01cf7821  addu t7,t6,t7 | 002b8aa4: 01cf7021  addu t6,t6,t7`
- Changes tried: C19 explicit frame transport, 15 words; C11 first t7 binding, 5 words; C11 first t6 binding, 5 words; C11 split t7 constant/add, 4 words; C11 volatile first t6 guard, 2 words; C11 second t7 binding, 8 words; C11 second t6 binding, 2 words.
- Why it stops here: budget reached.
- Next hypothesis: from v8, make only the second t6 reload guard volatile so its load remains before the t7 high-half materialization.
