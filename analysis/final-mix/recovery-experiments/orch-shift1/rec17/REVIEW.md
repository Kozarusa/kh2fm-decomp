# Review of rec17
Reviewer: sonnet. Reviewed 2026-10-12. Mechanical check: review-auto-2.json (4 PASS, 0 FAIL, 3 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 0014a868 | MERGE | PASS 112 bytes exact; plain C++ conditions and calls, no asm; report agrees. |
| 0014ad20 | MERGE | PASS 56 bytes exact; two calls, no asm; report agrees. |
| 0014cc40 | MERGE | PASS 116 bytes exact; one empty asm constraint with a `// why:` comment on the same line; diff re-run shows 0 differing words. |
| 0014cde0 | MERGE | PASS 60 bytes exact; two calls, no asm; report agrees. |

Spot check: 0014cc40 diff shows Differing words: 0 (yes).
Blocked reports: 2 checked, 0 incomplete (). Both 0014b9a8 and 0014cf18 have the header plus the five R9 lines and a non-empty next hypothesis. 0014cf18 R3 check: the packet shows `sync` at 0014cf68 and `ei` at 0014cf6c, and its "Earlier attempts" section is "none found" with no accepted source containing `ei`, so the privileged-instructions block is correct.
FLAG paths (written by the orchestrator, not rec17, per the orchestrator note; the WP report lists no edits outside the WP): Codex/orchestration/ORCHESTRATION.md, Codex/orchestration/PROGRESS.md, Codex/orchestration/briefs/rec17.md. None is under Public\tools, layout.tsv, functions.tsv, the queue database or the root documents.
Mechanical output:
PASS 0014cc40 116 bytes exact; source orch1_rec17_0014cc40_v4.cpp
PASS 0014ad20 56 bytes exact; source orch1_rec17_0014ad20_v1.cpp
PASS 0014cde0 60 bytes exact; source orch1_rec17_0014cde0_v1.cpp
PASS 0014a868 112 bytes exact; source orch1_rec17_0014a868_v1.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec17.md
Blocked reports: 2. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec17\review-auto-2.json
