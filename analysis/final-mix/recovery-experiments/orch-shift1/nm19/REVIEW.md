# Review of nm19
Reviewer: GPT-6 inherited. Reviewed 2026-10-14T01:46:52Z. Mechanical check: review-auto-2.json (1 PASS, 0 FAIL, 2 FLAG).
Overall: MERGE WITH FOLLOW-UP

| Address | Verdict | Reason |
| --- | --- | --- |
| 001b7df0 | MERGE | Complete 120-byte equality; ordinary C++ preserves this target's three calls and two tests. Only the explicitly authorized four-operation VU subtraction emits instructions. |
| 001b27f0 | DO NOT MERGE | No submission or lease; unavailable first claim consumed 1/K. Retry only in a fresh authorized WP using store-order. |

Spot check: 001b7df0 diff shows Differing words: 0 (yes).
Blocked reports: 0 checked, 0 incomplete (none).
Follow-up (only for MERGE WITH FOLLOW-UP): Retry 001b27f0 in a fresh authorized WP; no further nm19 claim.
The two outside-WP flags are Codex/orchestration/PROGRESS.md and Codex/orchestration/briefs/nm19.md. The orchestrator explicitly identifies both as its own changes; they are not worker edits.

Source review: Read the target packet and accepted 001b7998 definition. Calls to 0019bb98, 001b7998 and 0018a7d0 preserve the target's arguments, conditions, stack-vector output and destination at object pointer +4, then +0x870. The destination binding is initialized before its empty read/write guard; both have individual why comments. The stack temporary is supplied by the preceding output-pointer call before the VU read. There are no unassigned register reads, forbidden names, extra functions, trailing declarations or instruction-body substitutions.

Primitive review: Independently read the actual accepted fm_primary_queueeta_recovered_00163210.cpp. Its initial lqc2/lqc2/vsub.xyzw/sqc2 sequence matches the submitted primitive, with operands adapted to this target's destination and stack temporary. Its subsequent vector operations and body were not copied. The submitted primitive has its own why comment; no other emitted assembly appears. Accepted registration/normalized_match/equal_size status was verified by the orchestrator. All 30 original/compiled instruction pairs match, including all three call addresses.

Budget review: 3, 3, 3, 0 differing words across v1-v4 yields streaks 0, 1, 2, 0; strict R7 was respected. Two named claim attempts exhausted K=2; 001b27f0 was never reclaimed.

Mechanical output:
PASS 001b7df0 120 bytes exact; source orch1_nm19_001b7df0_v4.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/nm19.md
Blocked reports: 0. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\nm19\review-auto-2.json

