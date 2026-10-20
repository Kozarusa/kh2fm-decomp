# Review of rec20
Reviewer: sonnet. Reviewed 2026-10-12. Mechanical check: review-auto-2.json (2 PASS, 0 FAIL, 3 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 00154288 | MERGE | 60 bytes exact. Original packet uses beq/slti/beqzl branches and has no lui/table load, so the switch is a branch form, not a jump table or data-table read. Plain C++, no asm. |
| 001542c8 | MERGE | 104 bytes exact, plain calls and condition, no asm, declarations before the function, report agrees. |

Spot check: 001542c8 diff shows Differing words: 0 (yes).
Blocked reports: 4 checked, 0 incomplete (none). All have the six R9 lines and a non-empty next hypothesis.
FLAG paths (Codex/orchestration/ORCHESTRATION.md, Codex/orchestration/PROGRESS.md, Codex/orchestration/briefs/rec20.md) are orchestrator-written per the orchestrator's note; none is under Public\tools, layout.tsv, functions.tsv, the queue database or root documents.
Mechanical output:
PASS 00154288 60 bytes exact; source orch1_rec20_00154288_v3.cpp
PASS 001542c8 104 bytes exact; source orch1_rec20_001542c8_v1.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec20.md
Blocked reports: 4. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec20\review-auto-2.json
