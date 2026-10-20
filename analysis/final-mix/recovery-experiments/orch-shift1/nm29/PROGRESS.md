# nm29 progress
start 2026-10-17T21:00:16Z
claim 1 of 1: 0028d068 token bee30a0d18d94e3a9024b278e59d3260 attempts 2
R4.3 fresh audit: pure leaf no v0/f0 writes or callees; void permitted. R4.5 no callees. v1 unchanged rec171 v4 baseline; review explicitly permits retry.
0028d068 v1: 2 words; best v1 2 words; streak 0. v2 baseline v1; C7(c) outer nonnegative early return only. Full source diff inspected: same negative loop, positive-count condition, initialized count, one guard, volatility, operand order and stores; only outer condition/layout changed.
0028d068 v2: 2 words; best v1 2 words; streak 1. First difference instruction 15 bnezl versus bnez. v3 baseline v2; C7(c) positive-count if changed solely to nonpositive early return; full source diff inspected, body/guard/volatility/operands preserved.
Correction: v2 actual diff is 23 words, 100/96 bytes, first instruction 0; prior 2-word note accidentally described v1 diff. v2 streak 1 unchanged. 0028d068 v3: 23 words; best v1 2 words; streak 2. v4 baseline v1; C7(c) negative-index branch early return replaces outer else only; full source diff inspected, loop/guard/volatility/operand order/stores preserved.
0028d068 v4: 2 words; best v1 2 words; streak 3. Strict R7 stop.
blocked 0028d068 -> branch-layout; K1 reached.
