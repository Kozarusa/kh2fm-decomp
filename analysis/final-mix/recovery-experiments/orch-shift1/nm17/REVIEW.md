# Review of nm17
Reviewer: GPT-6 inherited. Reviewed 2026-10-14T01:12:38.435170+00:00. Mechanical check: review-auto-2.json (0 PASS, 0 FAIL, 5 FLAG).
Overall: DO NOT MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 001bdff0 | DO NOT MERGE | Blocked, not submitted. Independently recounted v1-v4: each 2 differing words, 108/108 bytes; earliest best v1. |

Spot check: not applicable; no PASS address and no submissions. Inspected v1 source and saved diff: only cursor-add/ra-save order differs at instructions 6-7; Differing words: 2. Nothing to integrate.
Blocked reports: 1 checked, 0 incomplete. All six R9 fields present; next hypothesis specifies a separate arithmetic offset temporary consumed by the cursor guard, without binding s0, under a fresh version name.
Accounting: 5 attempts, 4 compiled versions; initial failed write/missing-source probe produced no proof. No evidence of source/proof overwrites. R7 ties v2/v3/v4 yield streak 3 and stop; 5 attempts within budget 12; K=1 exhausted. Both empty-asm guards and v4 initialized register binding have adjacent why comments; ordinary C++ body, declarations before function, no emitted instruction asm.
Outside-WP flags: Codex/orchestration/DEVIATIONS.md, HANDOFF.md, PROGRESS.md, and tools/gpt6_context.py are orchestrator-owned changes, confirmed by orchestrator; not attributed to worker. No-submission FLAG is expected.
Mechanical output:
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/DEVIATIONS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/tools/gpt6_context.py
FLAG -        no submitted proposals from this WP are awaiting integration
Blocked reports: 1. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\nm17\review-auto-2.json
