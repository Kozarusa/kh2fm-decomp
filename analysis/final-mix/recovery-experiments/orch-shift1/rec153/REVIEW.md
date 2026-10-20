# Review of rec153
Reviewer: GPT-6 inherited. Reviewed 2026-10-16 UTC. Mechanical check: review-auto-3.json (4 PASS, 0 FAIL, 8 FLAG).
Overall: MERGE WITH FOLLOW-UP

| Address | Verdict | Reason |
| --- | --- | --- |
| 00253380 | MERGE | Exact 88 bytes; s32 comparison and return preserve both original exits: match sets v0=1, initial/terminating negative sentinel returns initialized v0=0. Narrow register binding and empty constraint both explained. |
| 00257970 | MERGE | Exact 108 bytes; at least one call executes. Nonzero early exit and 24-call exhaustion both return latest 00139d78 v0 through copied accepted u32 declaration. No discarded return or fabricated entry value. |
| 00257ff8 | MERGE | Exact 80 bytes; matching enabled bit returns preceding enabled-bit count; exhausted scan returns initialized -1. No callee. |
| 00258a30 | MERGE | Exact 88 bytes; absent pointers return initialized false, first successful call returns normalized true, otherwise second call result is normalized. No outgoing result discarded. |

Spot check: 00253380 v3 diff shows Differing words: 0 (yes), independently run with kh2w.py diff.
Blocked reports: 2 checked, 0 incomplete. Both contain all six R9 fields and a nonempty next hypothesis.
Follow-up:
- Preserve the disclosed R6 violation in DEVIATIONS #8: 00253380 v1-to-v2 adds BOTH numeric result binding and empty constraint. The measured 20-to-19-word improvement cannot be attributed to either independently. Do not claim isolated v2 effect. The independently inspected v2-to-v3 change replaces early return with assignment/break and reaches exact bytes; source acceptance does not erase the experiment-procedure violation.

## Source and return-contract audit

Read all 14 candidate sources, six packets, four submitted reports, WP-REPORT.md, PROGRESS.md, both blocked reports, and the target brief. Every candidate contains one ordinary C++ function, declarations before it, and no pasted instructions, forbidden names, or code-data trickery. Submitted names agree with the report.

00253380 v2/v3 bind result to numeric $2 to reproduce original early v0 initialization; the following empty read/write constraint keeps that initialization alive before the scan. Each has its own adjacent `why` explanation. Earlier plain v1 failed (20 words). 00257970 v2 binds offset to numeric $16 because original s0 survives the callee; adjacent `why` present, but this version is not submitted. No source emits lq/sq, VU, or other instruction assembly; no exception invoked.

Every original exit was traced independently under literal R4.3. The four submitted targets define integer/Boolean v0 results on every reachable exit. Their originals have no floating-point computation or f0 return definition; untouched f0 is not represented as a fabricated floating result. No submitted target has an untouched entry-v0 return path or tail call. No reliance on the seven earlier void discrepancies.

Blocked 002535d0 returns s0 (-1 or 2) through v0 after the callee condition; all five drafts express that contract but are not exact. Blocked 00256a58 ends in tail j 00263a58, so outgoing v0/f0 flows through. Its existing void declaration cannot resolve that contract. Zero-version ABI block is appropriate; no earlier void exception accepted.

## Saved evidence and budgets

Independently checked all 14 saved verification JSON source SHA-256 bindings against current source bytes and recomputed differing-word counts from saved compiled/target hex; all agree. These are saved-proof checks, not fresh compilations. Exact submitted sizes are 88, 108, 80, and 88 bytes. Layout acceptance ranges, rather than advisory Ghidra body sizes, are used.

- 00253380: v1/v2/v3 = 20/19/0 words; final best v3. R6 attribution violation described above.
- 002535d0: v1/v2/v3/v4/v5 = 29/28/28/29/28 words; earliest best v2, 128/104 bytes. v3-v5 ties/regression produce strict R7 streak 1/2/3; correctly stopped. Its blocker retains all history and next hypothesis.
- 00256a58: no versions, unresolved ABI.
- 00257970: v1/v2/v3/v4 = 8/17/4/0 words; v2 increments streak, v3 resets it; final best v4.
- 00257ff8 and 00258a30: v1 = 0 words each.

Six logged claims, six final dispositions, no seventh claim. Each target stays within eight versions; strict R7 respected. 00257ff8 packet records an earlier 16-word attempt; worker records reading it, then a successful fresh structured translation. No budget overrun found.

The eight outside-WP flags below are explicitly attributed to orchestrator work by the root task and the WP report disclaims worker authorship. No worker-owned shared-file mutation is evidenced; these flags do not reject the four submissions. DEVIATIONS #8 remains root-owned.

Mechanical output:
```text
PASS 00257ff8 80 bytes exact; source orch1_rec153_00257ff8_v1.cpp
PASS 00253380 88 bytes exact; source orch1_rec153_00253380_v3.cpp
PASS 00258a30 88 bytes exact; source orch1_rec153_00258a30_v1.cpp
PASS 00257970 108 bytes exact; source orch1_rec153_00257970_v4.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/STATUS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/DEVIATIONS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/nm25.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec154.md
Blocked reports: 2. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec153\review-auto-3.json
```
