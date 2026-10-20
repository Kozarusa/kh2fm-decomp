# 002b8984 blocked
- Range: 002b8984, 96 bytes. Versions tried: 4. Best: v1 with 23 differing words (84/96 bytes).
- First difference of the best version: `!! 002b8984: 27bdffe0  addiu\tsp,sp,-32                                  | 002b8984: 00000000  nop`
- Changes tried: C19 explicit frame payload reconstruction, 23 words; C1 remove argument-area constraint, 23 words; C11 remove guarded t7 result transport, 23 words; C10 add memory barrier after argument stores, 24 words.
- Why it stops here: no improvement for 3 versions.
- Next hypothesis: move the frame-transport trigger after the compiler-generated prologue without emitting the leading nop, then bind independent address materialization to t6/t7.
