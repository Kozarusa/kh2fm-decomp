# 002b81b8 blocked
- Range: 002b81b8, 52 bytes. Versions tried: 5. Best: v2 with 8 differing words (40/52 bytes).
- First difference of the best version: `!! 002b81c0: 03a0f02d  move\ts8,sp                                       | 002b81c0: afc40000  sw\ta0,0(s8)`
- Changes tried: C1 fresh reconstruction with volatile frame argument stores, 10 words; C1 add 16-byte argument-area constraint, 8 words; C19 explicit frame transport, 9 words; C11 bind zero result to t7, 9 words; C11 guard t7 result binding, 9 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: preserve explicit frame transport while delaying the guarded t7 result until after the final volatile store, then explicitly restore sp from s8.
