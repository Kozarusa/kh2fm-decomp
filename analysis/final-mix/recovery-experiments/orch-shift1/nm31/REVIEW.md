# Review of nm31
Reviewer: GPT-6 inherited. Reviewed 2026-10-17T21:36:41Z. Mechanical check: review-auto-2.json (1 PASS, 0 FAIL, 4 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 0028f690 | MERGE | 92 bytes exact; ordinary C++ preserves the three signed-halfword comparisons and selected-base/fallback pointer return. Both numeric bindings are initialized and individually explained. Literal R4.3 passes; R4.5 has no callees. |

Spot check: 0028f690 diff shows Differing words: 0 (yes).
Blocked reports: 0 checked, 0 incomplete (none).

Independent full source comparisons confirm nm31v1 is unchanged rec172v4. From named baseline v1, v2 introduces only the initialized address temporary, preserving D_0035f480 + index * 884 + 388 operand order and grouping. From v2, v3 changes only base/cursor initialization order. From v2, v4 adds only the initialized base $11 binding and its own why comment. Added trailing whitespace has no semantic effect. The count $14 binding remains initialized to 2 and individually explained. No failed pointer/value bindings or guards were repeated.

The optional result starts null but is never dereferenced or used in arithmetic. The cursor and base start at D_0035f468; three iterations compare sign-extended halfwords with the loaded signed word, retaining the fixed table base on any match. The sole original jr ra returns either that base or D_0035f470 in v0; source returns the same defined selected pointer on every exit. No untouched entry-v0 exit, f0 path, tail call, or callee result exists. Address/index arithmetic retains the baseline operation for its valid indexed-object domain; no null-result arithmetic or signed bit shift was introduced. One function, all declarations before it, no forbidden names, emitted instructions, or instruction-data tricks.

All four source SHA-256 values independently match their proofs; saved compiled/target byte comparisons give 4, 2, 2, 0 differing words. K1, four unique versions within budget8, and strict streak sequence 0, 0, 1, 0 satisfy the brief. Baseline rec172 review and blocker were read; prior evidence remains untouched.

The four outside-WP flags are orchestrator-owned publication/bookkeeping changes, as attributed by the parent orchestrator: Codex/orchestration/DEVIATIONS.md, Codex/orchestration/HANDOFF.md, Codex/orchestration/ORCHESTRATION.md, and Codex/orchestration/PROGRESS.md. None is attributed to the worker. No probe, build, or queue mutation was performed.

Mechanical output:
PASS 0028f690 92 bytes exact; source orch1_nm31_0028f690_v4.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/DEVIATIONS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
Blocked reports: 0. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\nm31\review-auto-2.json
