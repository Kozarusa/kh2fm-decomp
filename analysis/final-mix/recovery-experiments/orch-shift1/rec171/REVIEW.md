# Review of rec171
Reviewer: GPT-6 inherited, independent. Reviewed 2026-10-17 UTC. Mechanical check: review-auto-2.json (4 PASS, 0 FAIL, 7 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 0028cf28 | MERGE | v1, 112 bytes exact. Both BeginLeave exit results and the SetFlag tail result propagate; packet-named accepted declarations match literally. |
| 0028dd90 | MERGE | v3, 68 bytes exact. Every exit sets v0 to 0, 1 or 2; signed remainder and switch express the original operation. The break trap is compiler-generated. |
| 0028e5e0 | MERGE | v1, 112 bytes exact. Nonpositive count returns the initial callee result; positive count returns the final loop callee result. Both accepted declarations match literally. Pointer arithmetic occurs only inside the positive-count loop; no optional null cursor is incremented on a skipped path. |
| 0028eb88 | MERGE | v3, 104 bytes exact. Preserves the outgoing callee v0 result and f12/f13 argument order; repeated volatile field reads and ordered volatile float stores express the original accesses. Accepted declaration matches literally. |

Spot check: 0028eb88 diff shows Differing words: 0 (yes).
Blocked reports: 2 checked, 0 incomplete. Both contain the heading and all five R9 fields, including nonempty next hypotheses.

The four submissions total 396 bytes. Each is one ordinary C++ function, with declarations before it, no forbidden names, no instruction-emitting assembly or register bindings, and nothing after the function except whitespace. All original exits were traced under literal R4.3; no unspecified entry value was replaced with zero and no outgoing callee result was discarded. R4.5 declarations were checked against fm_primary_capacity_recovered_00303c48.cpp, fm_primary_close_recovered.cpp and fm_primary_threeword_recovered_0028e710.cpp.

All 15 saved proof source hashes match. Independent byte comparisons reproduce every logged word count and size. Full source diffs against the named baselines show one intended compiler-significant control per version. The two equivalent field-access volatility changes in 0028eb88 v2 constitute one access-type control; v3 separately changes the two equivalent float-store access types. No guard, condition or operand-order change is bundled with either.

K6 and budget8 are respected. Version counts are 1, 7, 3, 0, 1, 3. For 0028d068, counts are 5, 4, 10, 2, 2, 14, 25; v4 is the earliest best, 2 words at 96/96 bytes. Versions v5-v7 form strict nonimprovement streak3, after which work stops. Its pure leaf original never writes v0/f0 and has no callee result, so void is permitted. The v4 empty count constraint has its required why comment and preserves the source operation. Baseline orch1_rec171_0028d068_v4.cpp is permitted for the planned isolated outer-condition-layout retry; it remains nonexact and must not be integrated.

0028e350 correctly remains blocked with zero versions: the null branch preserves entry v0/f0, while the nonnull branch exposes the final 00106450 result. The mixed ABI contract is unresolved; the report invents no zero or void exception.

The seven outside-WP flags name Codex/orchestration/DEVIATIONS.md, HANDOFF.md, ORCHESTRATION.md, PROGRESS.md, ROSTER.md, briefs/nm29.md and briefs/rec172.md. The orchestrator identifies these as its own bookkeeping and briefs, not worker edits; they do not reject this WP. No probes, builds or queue mutations were run during review.

Mechanical output:
```text
PASS 0028e5e0 112 bytes exact; source orch1_rec171_0028e5e0_v1.cpp
PASS 0028eb88 104 bytes exact; source orch1_rec171_0028eb88_v3.cpp
PASS 0028dd90 68 bytes exact; source orch1_rec171_0028dd90_v3.cpp
PASS 0028cf28 112 bytes exact; source orch1_rec171_0028cf28_v1.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/DEVIATIONS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/nm29.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec172.md
Blocked reports: 2. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec171\review-auto-2.json
```
