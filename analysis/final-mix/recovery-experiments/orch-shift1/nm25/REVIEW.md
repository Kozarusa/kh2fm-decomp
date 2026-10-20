# Review of nm25
Reviewer: GPT-6 inherited. Reviewed 2026-10-16 UTC. Mechanical check: review-auto-2.json (0 PASS, 0 FAIL, 7 FLAG).
Overall: DO NOT MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 00242908 | DO NOT MERGE | Correctly blocked; earliest best v1 remains 3 differing words, 120/120 bytes. No exact submission eligible for integration. |

Spot check: no PASS address exists; not applicable. Independently running kh2w.py diff on best v1 confirms Differing words: 3, first difference instruction 21; no zero-difference claim.
Blocked reports: 1 checked, 0 incomplete. All six R9 fields present, with a nonempty next hypothesis.

The blocked WP passes closure review. DO NOT MERGE means no eligible candidate, not a binary-check failure. Read the target brief, packet, progress, report, blocker, all four sources and saved proofs, predecessor review and baseline, and accepted tail-callee source.

All four saved source SHA-256 bindings match current source bytes. Independently recomputed word counts from compiled/target hex are 3,3,16,3; all sizes 120/120, all exact flags false. v1 is byte-identical to nm24 v3, the required copied baseline. v1, v2 and v4 compiled hex are identical. Earliest best remains v1. Strict R7 streaks are 0,1,2,3, correctly stopping at v4 below budget12. Exactly one named claim and one block; K1 exhausted. No predecessor reopened, additional source version, probe or build performed by this reviewer.

R6 comparisons against each named baseline:
- v1 to v2 adds only the shared-done empty result guard, preserving comparison binding, branches, types, labels and existing controls.
- v2 to v3 replaces plain result storage with initialized numeric $4 result binding. This is one binding-transport control; its required initializer is overwritten along every path before any read and does not add a result guard, branch, or new semantic result. Shared guard and remaining controls are preserved. Result worsens to 16 words; no isolated initializer-effect claim is supported or made.
- v2 to v4 adds only an empty result guard immediately after the one-label assignment. Existing shared guard and other controls remain. Whitespace changes carry no compiler control.

The scoped numeric $15 comparison binding is initialized to 2 on every entry to its block and individually explains original t7 allocation. v3 numeric $4 binding individually explains outgoing a0 allocation. Shared-done guard explains result lifetime before the tail call; v4 one-label guard separately explains preserving that assignment before the shared exit. Each has an adjacent why comment. Plain baseline precedes guard experiments. No emitted instructions, lq/sq, VU, encoding tricks, or fresh-v1 assembly exception; all four bodies remain ordinary C++ with one function and declarations before it.

Literal R4.3 audit: original has one tail exit, j 002b6bc4, and no jr or untouched entry-v0 exit. Startup choice calls 0023d1d0 or 0023d1e0, then converges through 00242a68, so those intermediate returns do not reach the exit. Final selection passes 0 for value0, 2 for value2, 1 otherwise, including negative values. All paths initialize result before the final call or any read/write empty constraint. The scoped comparison initializer cannot be bypassed by a goto. Every draft explicitly returns the outgoing u64 result of func_002b6bc4(u32), matching its accepted source, which returns its callee result through integer registers. No discarded tail result or invented zero return. Original has no floating-result definition; no floating return is fabricated. Earlier accepted void discrepancies provide no exception.

R9 blocker correctly names v1, 3 words, 120/120 bytes, exact first difference, four experiments, strict stop and a distinct future hypothesis. That hypothesis grants no new work in this closed WP or its predecessors. No follow-up required for closure.

Six outside-WP paths below are explicitly root-owned concurrent documentation edits, consistent with the worker's no-shared-file-edit report. The seventh flag is expected for zero submissions.

Mechanical output:
```text
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/DEVIATIONS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec155.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec156.md
FLAG -        no submitted proposals from this WP are awaiting integration
Blocked reports: 1. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\nm25\review-auto-2.json
```
