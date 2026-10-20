# Review of rec38
Reviewer: sonnet. Reviewed 2026-10-12T22:19:32Z. Mechanical check: review-auto-2.json (2 PASS, 0 FAIL, 4 FLAG).
Overall: MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| 00173e38 | MERGE | 44 bytes exact; plain C++ (one call, no asm); report lists it with the same file; declarations before the function; names clean. |
| 00173f08 | MERGE | 96 bytes exact; ordinary C++ with one register binding (register 8), one empty asm pin and two volatile stores, each with a why comment; one function; no trickery. |

Spot check: 00173f08 diff shows Differing words: 0 (yes). 00173e38 also 0 (yes).
Blocked reports: 4 checked, 0 incomplete.
Notes:
- FLAG paths (ORCHESTRATION.md, PROGRESS.md, briefs/rec38.md, briefs/rec39.md under Codex/orchestration) were written by the orchestrator, not by rec38 (per the orchestrator's note); none is a Public\tools, layout.tsv, functions.tsv, queue database or root-document change. They do not affect the verdict.
- 00173f08 inline member: Vec4::operator= is a type's inline operator used by the one exported function, declared in the struct before the function, and fully inlined (the exact 96-byte match shows no extra code). Same kind as the accepted static inline helper precedent (0013a958); not a second exported function. The full build would catch any emitted symbol.
- 00173e38 declares an unused struct Inner; harmless, no symbol.
- 00173ce8 R3 vu-macro block confirmed: the packet has lqc2/vmulax/vmadday/vmaddaz/vmaddw/sqc2 and its only accepted-sibling line is for callee 0016b0e0 (fm_scalar_extra_recovered_12.cpp), not a similar VU sequence. R3 row (_shared.md line 66) applies. The BLOCKED file's cited sibling (002f3cd8) is not in the packet, only a hint for a later attempt.
- Blocked reports 00172c38, 00173008, 001735b0, 00173ce8: all have the R9 lines (range, first difference, changes tried, why it stops, next hypothesis) with non-empty next hypotheses.
Mechanical output:
PASS 00173e38 44 bytes exact; source orch1_rec38_00173e38_v1.cpp
PASS 00173f08 96 bytes exact; source orch1_rec38_00173f08_v7.cpp
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/ORCHESTRATION.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/PROGRESS.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec38.md
FLAG -        changed outside the WP since it started (check who changed it): Codex/orchestration/briefs/rec39.md
Blocked reports: 4. Saved: C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\rec38\review-auto-2.json
