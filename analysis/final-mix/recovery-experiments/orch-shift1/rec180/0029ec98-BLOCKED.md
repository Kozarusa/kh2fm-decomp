# 0029ec98 blocked
- Range: 0029ec98, 88 bytes. Versions tried: 2. Best: v1 with 20 differing words (80/88 bytes).
- First difference of the best version: !! 0029ec9c: 0000102d move v0,zero | 0029ec9c: 95cf4aa8 lhu t7,19112(t6); = D_00374aa8.
- Changes tried: C1 audited arguments and every exit; all exits return v0 0 or 1; no callees or float transport. v1 unsigned-index scan: 20 words. C7a negated comparison and swapped bodies in v2: 20 words.
- Why it stops here: orchestrator STOP under R12.
- Next hypothesis: C7c replace early hit return with result assignment and structured exit; preserve defined unsigned indexing and argument transport.