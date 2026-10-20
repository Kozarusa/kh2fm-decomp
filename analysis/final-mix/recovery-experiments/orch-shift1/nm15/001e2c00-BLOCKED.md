# 001e2c00 blocked
- Range: 001e2c00, 92 bytes. Versions tried: 1. Best: v1 with 3 differing words (92/92 bytes).
- First difference of the best version: !! 001e2c30: 24a5e9d0 addiu a1,a1,-5680 vs compiled 2484e998 addiu a0,a0,-5736.
- Changes tried: authorized break 0 after independent earlier-proof recount of one trap-only difference; trap now exact, second call argument scheduling changed (3 words).
- Why it stops here: one-version budget reached.
- Next hypothesis: C11 reorder argument materialization while preserving break and guards.
