# nm27 progress
start 2026-10-17T17:14:45Z
Read shared/brief and ultracave skill.
claim 1 of 1: 00266678 token 8d5af53124214a82ae9ec6af1de99bdf attempts 2
R4.3: sole exit tail j 002666a8 transports callee v0; u32 return retained. R4.5: all three u32(void) declarations exactly match accepted 00272a00/00272a70/002908f0/0028e710. v1 unchanged copy rec156v2; barrier retained.
00266678 v1: 2 words; best v1 2 words; streak 0. C7 next: negate condition and swap empty/call bodies. Complete baseline source diff reviewed before save; no other changes.
v2 source write failed: Set-Content -NoNewline unsupported; probe file missing. Conservatively counts failed version: best v1 2 words; streak 1. v3 retries same isolated C7 candidate under fresh filename. Full baseline diff reviewed.
00266678 v3: 2 words; best v1 2 words; streak 2. C7 next: change condition to early return of unchanged common call sequence on value != 23. Full baseline diff reviewed; no added binding/temporary/guard, barrier/declarations/types/operand order unchanged.
00266678 v4: 2 words; best v1 2 words; streak 3. Stop strict R7; failed v2 conservatively counted. Three actual compiled probes, four numbered attempts.
blocked 00266678 -> prologue-epilogue; K1 exhausted.
