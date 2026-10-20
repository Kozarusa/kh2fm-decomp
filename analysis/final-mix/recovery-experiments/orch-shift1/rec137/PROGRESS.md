# rec137 progress
start 2026-10-14T07:10:52.9523558Z
claim 1 of 6: 0022e6b0 token 82a5169241ec4448ab9006cfa79caea0 attempts 1
0022e6b0 v1: 18 words; best v1 18 words; streak 0
v1: 18 words, first diff at 11: C7 -> next: negate first condition and swap bodies
0022e6b0 v2: 0 words; best v2 0 words; streak 0
submitted 0022e6b0 v2
claim 2 of 6: 0022efb8 token b8104e0bff124f82ad80ec1405ab00e8 attempts 1
0022efb8 v1: 15 words; best v1 15 words; streak 0
v1: 15 words, first diff at 6: C9 -> next: volatile source halfword reads to preserve load placement and reload
0022efb8 v2: 28 words; best v1 15 words; streak 1
v2: 28 words, first diff at 4: C9 failed; next C10 memory guard after first store from best v1
0022efb8 v3: 2 words; best v3 2 words; streak 0
v3: 2 words, first diff at 10: C11 -> next: introduce temporary for initial halfword
0022efb8 v4: 2 words; best v3 2 words; streak 1
v4: 2 words, first diff at 10: C11 -> next: bind initial value to numeric register 14
0022efb8 v5: 2 words; best v3 2 words; streak 2
v5: 2 words, first diff at 10: C11 -> next: empty read-write guard for bound value
0022efb8 v6: 0 words; best v6 0 words; streak 0
submitted 0022efb8 v6
claim 3 of 6: 00230260 token d93a577c4fd24144a6bbd44058eb0f7b attempts 1
00230260 v1: 17 words; best v1 17 words; streak 0
v1: 17 words, first diff at 0: C4 -> next: explicit float callee argument to avoid default promotion
00230260 v2: 12 words; best v2 12 words; streak 0
v2: 12 words, first diff at 11: C11 -> next: bind result to original f12
00230260 v3: 5 words; best v3 5 words; streak 0
v3: 5 words, first diff at 13: C11 -> next: separate outgoing return result from bound transport value
00230260 v4: 5 words; best v3 5 words; streak 1
v4: 5 words, first diff at 13: C5 -> next: preserve explicit global address with empty pointer guard
00230260 v5: 10 words; best v3 5 words; streak 2
v5: 10 words, first diff at 15: C11 -> next: assign subtraction to bound transport value before call
00230260 v6: 10 words; best v3 5 words; streak 3
blocked 00230260 -> address-materialization
claim 4 of 6: 00230d78 token d5129e48caa44789b0f1cf0346a1a4e4 attempts 1
00230d78 v1: 23 words; best v1 23 words; streak 0
v1: 23 words, first diff at 0: C18 -> next: union destination accesses to preserve global reload
00230d78 v2: 22 words; best v2 22 words; streak 0
v2: 22 words, first diff at 0: C9 -> next: volatile global address reads
00230d78 v3: 19 words; best v3 19 words; streak 0
v3: 19 words, first diff at 3: C1 -> next: reuse condition address for first store
00230d78 v4: 17 words; best v4 17 words; streak 0
v4: 17 words, first diff at 0: C10 -> next: nonvolatile global with memory guards after stores from v1
00230d78 v5: 10 words; best v5 10 words; streak 0
v5: 10 words, first diff at 6: C11 -> next: reverse address addition operands
00230d78 v6: 8 words; best v6 8 words; streak 0
v6: 8 words, first diff at 10: C11 -> next: initial value binding and empty guard to t6
00230d78 v7: 19 words; best v6 8 words; streak 1
v7: 19 words, first diff at 0: C11 -> next: remove binding and retain initial temporary only
00230d78 v8: 8 words; best v6 8 words; streak 2
blocked 00230d78 -> register-allocation
claim 5 of 6: 002322b8 token 4e3f4fb9bd6d4ed3b9cb54bb6a48033a attempts 1
002322b8 v1: 0 words; best v1 0 words; streak 0
R8 review: use accepted callee declaration from fm_more_recovered.cpp in fresh v2
002322b8 v2: 0 words; best v1 0 words; streak 1; v2 retains exact accepted declaration
submitted 002322b8 v2
claim 6 of 6: 00232348 token 7fd6791532424e18be79b43865b5a68d attempts 1
00232348 v1: 0 words; best v1 0 words; streak 0
R8 review: copy accepted unsigned Region declaration in v2
00232348 v2: 0 words; best v1 0 words; streak 1; v2 retains accepted declaration
submitted 00232348 v2
Six claims exhausted; no further claims allowed.
Mechanical review passed all four submissions; external shared progress change flagged. Wrote WP-REPORT.md at 2026-10-14T07:21:20.5883449Z.
