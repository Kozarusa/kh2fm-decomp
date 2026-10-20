# Review of rec139
Reviewer: GPT-6 inherited (replacement for unavailable sonnet). Reviewed 2026-10-15T03:42:36Z. Mechanical check: review-auto-2.json (0 PASS, 0 FAIL, 5 FLAG).
Overall: DO NOT MERGE

There are no submitted proposals to integrate. This is a valid blocked-work closure, with no worker violation found in the reviewed evidence.

| Address | Verdict | Reason |
| --- | --- | --- |
| 00232db0 | DO NOT MERGE | Blocked; earliest best v5 has 15 differing words, 100/100 bytes. |
| 00233410 | DO NOT MERGE | Correct conservative R3 vu-macro block before source creation; zero versions. |
| 002338a8 | DO NOT MERGE | Blocked; earliest best v3 has 26 differing words, 120/116 bytes. |
| 00234098 | DO NOT MERGE | Blocked; earliest best v6 has 8 differing words, 84/84 bytes. |
| 002341e8 | DO NOT MERGE | Blocked; earliest best v8 has 4 differing words, 84/84 bytes. |
| 00234298 | DO NOT MERGE | Blocked; earliest best v7 has 4 differing words, 88/88 bytes. |

Spot check: No PASS address exists, so the zero-difference spot check is not applicable. Read-only kh2w.py diff on 002341e8 v8 independently reports Differing words: 4, compiled/target 84/84, first difference at instruction 12. It agrees with the saved report.
Blocked reports: 6 checked, 0 incomplete. Every report has the mandatory R9 range/version/best, first difference, changes, stop reason and nonempty next hypothesis. The zero-version report correctly uses no source, no best, no first difference and no streak; its packet records sqc2 vf0,0(sp) at 00233444. None of the packet's named accepted source references contains a supported matching VU sequence. This justifies the conservative R3 block, without claiming that no such sequence exists anywhere in the repository.

I recounted differing four-byte words directly from compiled_hex and target_hex in all 38 verification proofs, including unmatched trailing words, and verified all 38 source SHA-256 values against the corresponding current source files. There were no hash mismatches. The earliest best sources and all count sequences agree with WP-REPORT.md, PROGRESS.md and the blocked reports.

| Address | Word counts in version order | Strict R7 streaks | Stop |
| --- | --- | --- | --- |
| 00232db0 | 21,17,17,17,15,16,21,20 | 0,0,1,2,0,1,2,3 | v8: streak 3 and budget 8 |
| 00233410 | none | none | R3, zero versions |
| 002338a8 | 37,29,26,31,31,31 | 0,0,0,1,2,3 | v6: streak 3 |
| 00234098 | 11,11,10,12,12,8,10,11 | 0,1,0,1,2,0,1,2 | v8: budget 8 |
| 002341e8 | 11,10,10,8,11,11,6,4 | 0,0,1,0,1,2,0,0 | v8: budget 8 |
| 00234298 | 11,11,8,11,11,6,4,24 | 0,1,0,1,2,0,0,1 | v8: budget 8 |

The progress log records exactly six claims in the stated order, including the zero-version VU target, and no seventh claim. No attempt exceeds budget 8 or continues after a three-version non-improvement streak. There are 0 submitted, 6 blocked and 0 released targets.

The reviewed best sources express ordinary C++ operations with declarations before the function and descriptive names. All source assembly and register bindings have their own why comments. Empty read/write guards consume initialized values. The rounded f1 binding in 002338a8 is output-only: cvt.w.s writes it before any C++ read. Its single emitted conversion instruction uses the exact named accepted 0016df28 primitive, confirmed in Public/tools/kh2-reference/src/anon/fm_primary_queunuprime_recovered_0016df28.cpp and the functions.tsv registration. No pasted instruction body or byte-encoding trick was found.

The four outside-WP flags are Codex/orchestration/ORCHESTRATION.md, Codex/orchestration/PROGRESS.md, Codex/orchestration/ROSTER.md and Codex/orchestration/briefs/nm21.md. The orchestrator explicitly identifies these as its own work; they are not attributed to this worker. The fifth flag simply records the expected absence of submitted proposals. No integration or additional worker follow-up is required to close this WP.

Best-source SHA-256 checks:
- orch1_rec139_00232db0_v5.cpp: 431fc04325f0a47cec44d4d08091f448b128892d8e774d6d1b658cfe7dd31dbb
- orch1_rec139_002338a8_v3.cpp: f3edf94b05ee220dfedfed6683b3e905f6ab5bf5473145619a08260e11eeeb14
- orch1_rec139_00234098_v6.cpp: ee041763c9be1b8fbfd4f0b5e6381c79e6a1bfbffd7a2e937e30781b095f008e
- orch1_rec139_002341e8_v8.cpp: 3bb39bd6ace0b302f54cad4ecb46a0ec420c45cf611a0e8f902c1a9d282c5174
- orch1_rec139_00234298_v7.cpp: 645fa1763cbd6660f37ca3c825d3031e9570c7d995b3eb07ec4349798c7eb5de

Mechanical output:
```text
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/nm21.md
FLAG -        no submitted proposals from this WP are awaiting integration
Blocked reports: 6. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec139\review-auto-2.json
```
