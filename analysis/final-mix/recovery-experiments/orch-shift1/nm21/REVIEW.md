# Review of nm21
Reviewer: GPT-6 inherited (replacement for unavailable sonnet). Reviewed 2026-10-15T03:50:04Z. Mechanical check: review-auto-2.json (0 PASS, 0 FAIL, 8 FLAG).
Overall: DO NOT MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 0022f528 | DO NOT MERGE | Blocked; earliest best v1 has 2 differing words, 120/120 bytes. |
| 00232110 | DO NOT MERGE | Blocked; earliest best v1 has 2 differing words, 60/60 bytes. |

Spot check: not applicable; no PASS address or submitted proposal. Both v1 diffs independently show Differing words: 2.
Blocked reports: 2 checked, 0 incomplete (none). Both contain all six R9 lines and non-empty next hypotheses. This is a valid blocked closure, with nothing eligible for integration.

All eight source/proof SHA-256 pairs match. Independent four-byte recounts, v1 through v4: 0022f528 = 2, 10, 5, 5 words (120 bytes each); 00232110 = 2, 16, 14, 2 words (60, 64, 64, 60 bytes). Both named rec136 baseline proofs also hash correctly and recount to 2 words; nm21 v1 sources are byte-identical to rec136 v6 and v5 respectively. Every proof uses the expected target address, size and boundary. Each target stopped at v4 after three consecutive non-improvements; the tied v4 for 00232110 does not displace earliest best v1. K2 and budget12 were respected. All eight expected probes have proofs; the initial directory-creation error preceded probing and does not imply a missing probe.

All eight sources were read. Bodies use ordinary C++, one function each, declarations before the function, no trailing declarations, no forbidden decompiler names or emitted instructions. Bindings are initialized and bindings/empty guards have individual why comments. The two callee declarations match accepted source fm_primary_oneword_recovered_00232510.cpp. Global byte addresses D_0035de14 and D_0035de15 agree with signed-offset packet decoding. The experimental v3 symbolic high-address binding and v4 numeric 0x00360000 base both address 0x0035de14 through -8684; neither is accepted or exact. Labeling v4 as C5 is imprecise: the original symbolic address was already correct; this was an address-expression/scheduling experiment. No arbitrary instruction-emitting asm or uninitialized binding was used.

Outside-WP flags concern Codex/analysis/final-mix/primary-orchdu-checkpoint-2026-10-08.json; Codex/orchestration/ORCHESTRATION.md, PROGRESS.md, ROSTER.md; and Codex/orchestration/briefs/rec140.md, rec141.md, rec142.md. The orchestrator explicitly attributes these to its own bookkeeping; the checkpoint was rewritten by the required post-bookkeeping preflight gate. They are not attributed to this worker and do not invalidate blocked closure.

Mechanical output:
```text
FLAG -        changed outside the WP since it started (check who changed it): Codex/analysis/final-mix/primary-orchdu-checkpoint-2026-10-08.json
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ROSTER.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec140.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec141.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec142.md
FLAG -        no submitted proposals from this WP are awaiting integration
Blocked reports: 2. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\nm21\review-auto-2.json
```
