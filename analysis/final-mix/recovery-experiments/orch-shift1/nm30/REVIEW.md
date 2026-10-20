# Review of nm30
Reviewer: GPT-6 (inherited). Reviewed 2026-10-17T21:06:56Z. Mechanical check: review-auto-2.json (0 PASS, 0 FAIL, 7 FLAG).
Overall: DO NOT MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 0028b078 | DO NOT MERGE | No proposal was submitted. All four saved proofs are non-exact: v1/v2/v3/v4 have 5/22/22/15 differing words and 100/96/96/100 compiled bytes against 100 target bytes. Earliest best remains v1. |

Spot check: not applicable; no PASS address exists, so no exact-address diff was run. Saved source/proof contents and adjacent full-source differences were read without probing or building.
Blocked reports: 1 checked, 0 incomplete. The blocker contains the R9 header and all five required fields, including a non-empty next hypothesis. Its original four-version stop account must be read together with the appended process correction in WP-REPORT.md and PROGRESS.md.

Process findings:
- The mandatory v1 source is text-identical to rec167/orch1_rec167_0028b078_v1.cpp. Its retained narrow value/count parameters are the required baseline experiment, not a signature exception. The original reads a0/a1/a2 without entry masks. Successful v2 changes only count from u16 to u32; v3 changes only value from u16 to u32; v4 adds volatile to the four store accesses as one store-order control. Additional trailing blank lines do not change behavior.
- Every saved source preserves the sole tail return, `return func_0028b1b0(object,0);`. The original has no independent return or untouched entry-v0 exit. The outgoing integer result is preserved; no float-return operation is present. No void-result or fabricated-zero exception is claimed under literal R4.3.
- The three callee declarations match the packet-named accepted source fm_primary_dependencyfamily_recovered_00272a00.cpp exactly, satisfying R4.5. Each candidate contains one ordinary C++ function, declarations before it, no assembly or register bindings, and no prohibited names or encoding tricks.
- Unique-probe/process violation: unsupported `Set-Content -NoNewline` failed before v2 existed. The batch continued through heartbeat, a v2 probe that raised FileNotFoundError before compilation, and a diff that raised FileNotFoundError for the absent proof. A later batch saved v2 and successfully probed the same v2 name. The manual requires a new filename for every probe; absence of an earlier proof does not create an exception. No earlier compilation or proof was overwritten, but the probe name was reused. The worker's appended commands/errors and root confirmation establish this sequence.
- Conservative failure accounting, consistent with the brief's errors-count rule: missing-source invocation is nonimprovement 1 after best v1; successful v2 is nonimprovement 2; successful v3 is nonimprovement 3. Strict R7 therefore stopped at v3. Writing/probing v4 exceeded that limit. The append-only correction acknowledges this; the original four-successful-proof notes remain preserved. No new version, retry exception, or integration eligibility is inferred.
- The six outside-WP path flags are attributed by the orchestrator to its own work: primary-orcheq-checkpoint-2026-10-08.json was updated by its required preflight gate; HANDOFF.md, ORCHESTRATION.md, PROGRESS.md, ROSTER.md and briefs/rec175.md are root-owned changes. Root confirms no worker shared-file edit. The seventh flag correctly reports zero submitted proposals.

Mechanical output:
```text
FLAG -        changed outside the WP since it started (check who changed it): Codex/analysis/final-mix/primary-orcheq-checkpoint-2026-10-08.json
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec175.md
FLAG -        no submitted proposals from this WP are awaiting integration
Blocked reports: 1. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\nm30\review-auto-2.json
```
