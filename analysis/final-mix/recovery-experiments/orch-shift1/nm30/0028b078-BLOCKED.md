# 0028b078 blocked
- Range: 0028b078, 100 bytes. Versions tried: 4. Best: v1 with 5 differing words (100/100 bytes).
- First difference of the best version: !! 0028b080: 00a0702d move t6,a1 | 0028b080: 30a5ffff andi a1,a1,0xffff.
- Changes tried: unchanged rec167v1 baseline v1, 5 words; C3 count-only u16 to u32 from v1 in v2, 22 words (96/100 bytes); separate C3 value u16 to u32 from count-wide v2 in v3, 22 words (96/100 bytes); C10(c) volatile store accesses from v3 in v4, 15 words (100/100 bytes). Full source comparisons confirmed one intended control per successor. R4.3 sole exit returns the final tail callee result; all three declarations exactly match accepted 00272a00 under R4.5. No bindings, guards, or emitted assembly.
- Why it stops here: no improvement for 3 versions. Best remains v1; v4's size gain is not a word-count improvement.
- Next hypothesis: from both-wide v3, introduce a separate initialized value temporary before considering numeric t6 binding and a separately probed empty guard; do not repeat the old value-only narrow-count branch. This isolates full-width input register allocation without changing store volatility.
