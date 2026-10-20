# Review of nm20
Reviewer: GPT-6 (inherited; substitute for unavailable sonnet). Reviewed 2026-10-15T01:01:24.879908+00:00. Mechanical check: review-auto-2.json (0 PASS, 0 FAIL, 7 FLAG).
Overall: DO NOT MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 001b27f0 | DO NOT MERGE | No proposal was submitted. All four versions differ by 12 words; this is a valid blocked closure, with no address to integrate. |

Spot check: Not applicable: there is no PASS address or exact proposal. I independently compared each four-byte word in every nm20 and relevant rec85 proof rather than claiming a zero-word result.
Blocked reports: 1 checked, 0 incomplete. The report contains the R9 heading and every required field, including a concrete non-empty next hypothesis.

Evidence and completeness:
- I read WP-REPORT.md, PROGRESS.md, the blocked report, the target packet, all four nm20 source files and proofs, all four earlier rec85 source files and proofs for this target, the nm20 brief, the shared manual, and the accepted 001b2780 primitive.
- Independent recount: nm20 v1=12, v2=12, v3=12, v4=12. Every compiled and target size is 112 bytes. All four proof source hashes match their source files. The earliest best is v1, as named by the report and blocked record.
- Earlier rec85 evidence also recounts 12,12,12,12, with matching source hashes and 112-byte sizes. Its earliest best is v1. The Frame layout used for nm20 v1 is rec85 v3, with the plain copy replaced by the expressly authorized primitive.
- K1 was consumed by the single named claim, 001b27f0. Four fresh versions remain below the 12-version maximum. Under strict R7, only a lower differing-word count improves the best. Ties in v2, v3, and v4 therefore make three consecutive failures to improve, requiring the stop after v4. No replacement claim or fifth version is recorded.
- The first difference is instruction 3 at 001b27fc: target 03a0202d (move a0,sp), compiled 27a60020 (addiu a2,sp,32). All nm20 machine-code payloads are identical. Neither explicit temporaries, the initialized a0 binding, nor its empty guard lowered the count.
- The original target stores 5 at object+0x104 before 4 at object+0x100. Both rec85 and nm20 already express this source order. The worker correctly avoided the earlier stale suggestion to swap source stores; the compiler still schedules the final stores differently.

Technique review:
The function bodies express calls and stores in ordinary C++. Each file has one function, declarations before it, nothing after it, and meaningful names. The only emitted assembly is the accepted lq/sq pair, copied exactly as a primitive after documented failed plain Quad copies. Its clobbers and memory operand follow the accepted pattern, and it has its own why comment. Versions 3 and 4 initialize the numeric $4 packet binding before reading it; that binding has its own why comment. Version 4 has a separate why comment for the empty read/write guard. There are no uninitialized register reads, arbitrary emitted instructions, pasted bodies, or byte-emission tricks in these sources.

The six outside-WP flags concern Codex/orchestration/HANDOFF.md, Codex/orchestration/ORCHESTRATION.md, Codex/orchestration/PROGRESS.md, Codex/orchestration/ROSTER.md, Codex/orchestration/briefs/rec138.md, and Codex/orchestration/briefs/rec139.md. The orchestrator explicitly identified these as root-owned changes; none is attributed to this worker. The seventh flag correctly says there are no proposals awaiting integration. These flags do not invalidate the blocked closure.

No merge is available. The work package is complete as a documented blocked experiment, with no required review follow-up. This review used no probe, build, or queue mutation.

Mechanical output:
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/HANDOFF.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec138.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec139.md
FLAG -        no submitted proposals from this WP are awaiting integration
Blocked reports: 1. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\nm20\review-auto-2.json
