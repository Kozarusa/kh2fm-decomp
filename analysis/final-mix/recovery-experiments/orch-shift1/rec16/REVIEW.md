# Review of rec16
Reviewer: sonnet. Reviewed 2026-10-12. Mechanical check: review-auto-2.json (5 PASS, 0 FAIL, 4 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 00146730 | MERGE | Loop body is five consecutive nop words (0x14675c..0x14676c) ahead of the bne at 0x146770, whose delay slot is the separate addiu at 0x146774; none are delay slots, so no C construct yields them and the asm is a narrow primitive. The rest is ordinary C++, why comment present, exact 88 bytes. |
| 00147240 | MERGE | Ordinary C++ with two register bindings (s0, s1), each with a why comment; v9 differs from the exact v8 only by a why comment (orchestrator note 3), not a budget violation. Exact 120 bytes. |
| 00149c08 | MERGE | Plain C++ calls, exact 56 bytes, report agrees. |
| 00149c40 | MERGE | Plain C++ calls, exact 96 bytes, report agrees. |
| 0014a470 | MERGE | Plain C++ store and calls, exact 60 bytes, report agrees. |

Spot check: 00149c40 diff shows Differing words: 0 (yes).
Blocked reports: 1 checked, 0 incomplete (00146d68 has range, versions/best, first difference, changes tried, why it stops, and a non-empty next hypothesis).
FLAGs "changed outside the WP" (Codex/orchestration/ORCHESTRATION.md, PROGRESS.md, briefs/rec16.md) are under Codex/orchestration and written by the orchestrator per the notes; they are not worker changes and none is a protected shared file.
Mechanical output:
PASS 00149c08 56 bytes exact; source orch1_rec16_00149c08_v1.cpp
PASS 00147240 120 bytes exact; source orch1_rec16_00147240_v9.cpp
PASS 00149c40 96 bytes exact; source orch1_rec16_00149c40_v1.cpp
PASS 0014a470 60 bytes exact; source orch1_rec16_0014a470_v1.cpp
FLAG 00146730 5 emitted non-VU asm instructions; reviewer must confirm these are narrow primitives, not a pasted body
PASS 00146730 88 bytes exact; source orch1_rec16_00146730_v8.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec16.md
Blocked reports: 1. Saved: review-auto-2.json
