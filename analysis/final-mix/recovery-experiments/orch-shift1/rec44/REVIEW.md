# Review of rec44
Reviewer: sonnet. Reviewed 2026-10-12. Mechanical check: review-auto-2.json (5 PASS, 0 FAIL, 4 FLAG).
Overall: MERGE WITH FOLLOW-UP

| Address | Verdict | Reason |
| --- | --- | --- |
| 0017f488 | MERGE | Plain two-call C++, no asm, report agrees. |
| 0017edf0 | MERGE | Plain C++; one register binding to $15 with a why comment. |
| 0017de70 | MERGE | Plain C++; indirect call through a loaded table slot, no asm. |
| 0017ce10 | MERGE | Plain C++; four empty `asm("" : "+r")` constraints, each with a why comment. |
| 0017fef0 | DO NOT MERGE | VU sequence has no accepted sibling; block to vu-macro. |

0017fef0 detail: the submitted asm emits lqc2, lqc2, vsub.wxyz, sqc2, lqc2, lqc2, vadd.wxyz, sqc2 in one block. 0018a4d8 (fm_primary_queuetheta_recovered_0018a4d8.cpp) has only `lqc2 $vf1,0(%0); lqc2 $vf2,0(%1); vsub.xyzw $vf1,$vf1,$vf2; sqc2 $vf1,0(%2); nop`, then a different vmul/vaddy/vaddz/qmfc2 sequence; no vadd store. 001786e0 has only a vsub/sqc2 zero-fill. A search of all accepted sources under Public\tools\kh2-reference\src\anon found only 00163828, which does vsub then vmul/vaddy/vaddz, not an lqc2/lqc2/vadd/sqc2 accumulate. No accepted source has the difference-and-accumulate sequence. The worker's PROGRESS.md also says 001786e0 and 0018a4d8 were cited as showing "the same" pattern, which they do not.

Spot check: 0017f488 diff shows Differing words: 0 (yes).
Blocked reports: 1 checked, 0 incomplete. 0017f380-BLOCKED.md has range, versions and best, first difference, changes tried, why it stops, and a non-empty next hypothesis.
FLAG paths (Codex/orchestration/ORCHESTRATION.md, PROGRESS.md, briefs/rec44.md, briefs/rec45.md) were written by the orchestrator per its note, not by rec44; not counted against the worker.
Follow-up: 0017fef0 resubmit only if a matching accepted VU pattern exists; otherwise route to vu-macro queue (the PROGRESS.md/report claim of accepted siblings is inaccurate).
Mechanical output:
PASS 0017f488 88 bytes exact; source orch1_rec44_0017f488_v1.cpp
PASS 0017edf0 120 bytes exact; source orch1_rec44_0017edf0_v5.cpp
PASS 0017de70 76 bytes exact; source orch1_rec44_0017de70_v2.cpp
PASS 0017ce10 112 bytes exact; source orch1_rec44_0017ce10_v4.cpp
PASS 0017fef0 120 bytes exact; source orch1_rec44_0017fef0_v6.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec44.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec45.md
Blocked reports: 1. Saved: review-auto-2.json
