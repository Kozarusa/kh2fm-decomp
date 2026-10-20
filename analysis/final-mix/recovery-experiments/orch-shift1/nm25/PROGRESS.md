# nm25 progress
start 2026-10-16T07:57:28.4928368Z
claim 1 of 1: 00242908 token 5c6f2f4d6d1844c1852b444f6233d424 attempts 3 blocker nm24/00242908-BLOCKED.md
R2 read full fresh packet, all nm24 and rec148 sources/proofs/blockers and nm24 review. R4.3 every-exit audit: original has one tail j 002b6bc4, no jr; all paths select a0=0 only value0, a0=2 only value2, else1; returns outgoing u64 callee v0 per accepted declaration. Startup branches converge through 00242a68. No unresolved contract. Baseline nm24/orch1_nm24_00242908_v3.cpp copied verbatim to v1; no compliance fixes needed.
00242908 v1: 3 words; best v1 3 words; streak 0. First diff21 C11/C7 lifetime. Baseline orch1_nm25_00242908_v1.cpp -> v2 only add empty result guard at shared done label, preserving all other controls.
00242908 v2: 3 words; best v1 3 words; streak 1. Shared guard unchanged code. C11(c) baseline orch1_nm25_00242908_v2.cpp -> v3 initialized selected result binding a0; every actual path overwrites initializer. Other controls and shared guard preserved.
00242908 v3: 16 words; best v1 3 words; streak 2. C11(d) baseline orch1_nm25_00242908_v2.cpp -> v4 add result guard at one-label assignment only; distinct from earlier before-equality, fallback-only, and shared-done guards. All baseline controls preserved.
00242908 v4: 3 words; best v1 3 words; streak 3. Strict R7 stop at4, no further versions; K1 exhausted.
blocked 00242908 -> branch-layout
R11 WP-REPORT.md written; all evidence preserved; no further work in closed predecessor WPs.
