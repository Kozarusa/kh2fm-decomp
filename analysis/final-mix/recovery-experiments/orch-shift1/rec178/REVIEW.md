# Review of rec178
Reviewer: GPT-6 inherited (independent reviewer). Reviewed 2026-10-18T02:39:45Z. Mechanical check: review-auto-2.json (3 PASS, 0 FAIL, 6 FLAG).
Overall: MERGE WITH FOLLOW-UP

| Address | Verdict | Reason |
| --- | --- | --- |
| 0029dd00 | MERGE | Exact 96-byte v1; both optional-build paths return the final func_002931a8 result; accepted func_002ff2e8 declaration copied exactly. |
| 0029dda8 | MERGE | Exact 108-byte v2; both nonzero callee exits and the func_0029dd60 tail-call result are preserved; unsigned shift/address transport avoids signed-shift undefined behavior. |
| 0029e7b0 | MERGE | Exact 88-byte v3; signed halfword match result and default -1 are preserved; initialized $2 binding has its required why comment. |

Spot check: 0029dda8 diff shows Differing words: 0 (yes).
Blocked reports: 3 checked, 0 incomplete (none). Each has the heading, range/version/best information, first difference or explicit no-probe N/A, changes, stopping reason, and non-empty next hypothesis.

Follow-up (only for MERGE WITH FOLLOW-UP):
- Preserve and record the disclosed 0029ec40 v7 one-control violation: comparing complete sources confirms that v7 adds empty guards at both match and default exits relative to v6. Its 2-word result cannot establish an isolated effect and is ineligible for submission or a usable future baseline. Valid v8 derives from v6 and adds only the default-exit guard; it independently reaches 2 words. The report's historical earliest tie at v7 must retain this qualification. This process violation does not affect the three independently exact submitted sources.

All six claims are accounted for: three submissions and three blockers. Version counts are 0, 1, 2, 3, 0, 8; filenames are unique. No target exceeds its budget or continues beyond a strict three-non-improvement stop. The v7 violation remains a violation despite disclosure and the valid v8 comparison; no further experiment is authorized under this WP's exhausted budget. Complete saved source transitions were reviewed, including v4 from v3, v5 from v3, and v8 from v6.

Literal R4.3 review traced every original exit. No submitted function uses void, fabricates an untouched-entry return, or discards an outgoing result. No original submitted exit produces f0. The accepted callee declaration required for 0029dd00 is exactly extern "C" u32 func_002ff2e8(...); the other submitted packets name no accepted caller declarations requiring reuse. The submitted bodies use ordinary C++, with no emitted instructions, executed data, null-cursor arithmetic, or uninitialized register bindings. Declarations precede the single function; names and includes comply.

The six outside-WP flags are Codex/STATUS.md, Codex/orchestration/CHANGELOG.md, Codex/orchestration/GPT6-MEMORY.md, Codex/orchestration/HANDOFF.md, Codex/orchestration/ORCHESTRATION.md, and Codex/orchestration/PROGRESS.md. The orchestrator explicitly attributes them to its own publication/bookkeeping work, not worker edits. No shared-file worker violation is established.

Mechanical output:
```text
PASS 0029e7b0 88 bytes exact; source orch1_rec178_0029e7b0_v3.cpp
PASS 0029dd00 96 bytes exact; source orch1_rec178_0029dd00_v1.cpp
PASS 0029dda8 108 bytes exact; source orch1_rec178_0029dda8_v2.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/STATUS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/CHANGELOG.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/GPT6-MEMORY.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
Blocked reports: 3. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec178\review-auto-2.json
```
