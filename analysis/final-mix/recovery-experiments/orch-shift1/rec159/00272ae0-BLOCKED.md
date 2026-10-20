# 00272ae0 blocked
- Range: 00272ae0, 128 bytes. Versions tried: 6. Best: v5 with 15 differing words (128/128 bytes).
- First difference of the best version: !! 00272ae8: ffb00000 sd s0,0(sp) | 00272ae8: 0c0a1ef0 jal 287bc0 <func_00287bc0>
- Changes tried: initial result-preserving conditional v1 30 words; C7c outer early return v2 30; C21 sequential early returns v3 24; C11c v0 binding v4 24; C11d guard replacement v5 15; remove unintended second guard v6 16.
- Why it stops here: R12 conservative block after v5 accidentally applied a guard replacement twice, contrary to one-control rule. v5 is evidence only, never submitted. v6 cleanly removed the unintended second guard but prologue scheduling remains unresolved.
- Next hypothesis: isolate first-call save scheduling without changing signature, outgoing result flow or adding emitted instructions.
- ABI audit: first unsigned predicate failure returns explicit computed zero; null table returns null v0; false 00286068 returns its zero; tail 00286280 forwards result. No entry-v0 path.
